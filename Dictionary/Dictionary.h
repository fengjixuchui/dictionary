/*++

Copyright (c) 2018 Trent Nelson <trent@trent.me>

Module Name:

    Dictionary.h

Abstract:

    This is the main header file for the Dictionary component.

--*/

#ifdef _DICTIONARY_INTERNAL_BUILD

//
// This is an internal build of the TracerHeap component.
//

#ifdef _DICTIONARY_DLL_BUILD

//
// This is the DLL build.
//

#define DICTIONARY_API __declspec(dllexport)
#define DICTIONARY_DATA extern __declspec(dllexport)

#else

//
// This is the static library build.
//

#define DICTIONARY_API
#define DICTIONARY_DATA

#endif

#include "stdafx.h"

#else

#ifdef _DICTIONARY_STATIC_LIB

//
// We're being included by another project as a static library.
//

#define DICTIONARY_API
#define DICTIONARY_DATA extern

#else

//
// We're being included by an external component that wants to use us as a DLL.
//

#define DICTIONARY_API __declspec(dllimport)
#define DICTIONARY_DATA extern __declspec(dllimport)

#endif

#include "../Rtl/Rtl.h"

#endif

//
// Define an opaque DICTIONARY structure.
//

typedef struct _DICTIONARY DICTIONARY;
typedef DICTIONARY *PDICTIONARY;
typedef const DICTIONARY *PCDICTIONARY;

//
// We can't use STRING structures here as the words might be up to 1MB and we can't
// represent that size via the USHORT Length parameters.  So, use a custom structure
// named LONG_STRING with appropriate ULONG sizes.
//

typedef struct _LONG_STRING {

    //
    // Length of the string, in bytes.
    //

    ULONG Length;

    //
    // Maximum length of the string, in bytes.
    //

    ULONG MaximumLength;

    //
    // Pointer to the string.
    //

    PBYTE Buffer;

} LONG_STRING;
typedef LONG_STRING *PLONG_STRING;
typedef const LONG_STRING *PCLONG_STRING;

//
// Define a macro to help initialize static C variables to long strings.
// (This is equivalent to RTL_CONSTANT_STRING.)
//

#define CONSTANT_LONG_STRING(s) { \
    sizeof(s) - sizeof((s)[0]),   \
    sizeof(s),                    \
    s                             \
}

//
// Define the WORD_ENTRY structure used to capture words.
//

typedef struct _WORD_ENTRY {

    //
    // The string representation of this word entry.
    //

    LONG_STRING String;

    //
    // Linked-list entry used for chaining anagrams together.
    //

    LIST_ENTRY AnagramListEntry;

} WORD_ENTRY;
typedef WORD_ENTRY *PWORD_ENTRY;
typedef const WORD_ENTRY *PCWORD_ENTRY;

//
// Define the DICTIONARY interface function pointers.
//

typedef
_Check_return_
_Success_(return != 0)
BOOLEAN
(NTAPI CREATE_AND_INITIALIZE_DICTIONARY)(
    _In_ PRTL Rtl,
    _In_ PALLOCATOR Allocator,
    _Outptr_result_nullonfailure_ PDICTIONARY *Dictionary
    );

typedef CREATE_AND_INITIALIZE_DICTIONARY *PCREATE_AND_INITIALIZE_DICTIONARY;

typedef
_Success_(return != 0)
BOOLEAN
(NTAPI ADD_WORD)(
    _Inout_ PDICTIONARY Dictionary,
    _In_ _Const_ PCLONG_STRING Word,
    _Outptr_result_nullonfailure_ PCWORD_ENTRY WordEntry,
    _Outptr_opt_ PULONGLONG EntryCount
    );
typedef ADD_WORD *PADD_WORD;

//
// Inline helper functions.
//

//
// Define character bitmap structure and supporting functions.
//

#define NUMBER_OF_CHARACTER_BITS 256
#define NUMBER_OF_CHARACTER_BITS_IN_BYTES (256 / 8)
#define NUMBER_OF_CHARACTER_BITS_IN_DOUBLEWORDS (256 / (4 << 3))
#define NUMBER_OF_CHARACTER_BITS_IN_QUADWORDS (256 / (8 << 3))

typedef struct _CHARACTER_BITMAP {
    union {
        RTL_BITMAP Bitmap;

        //
        // Leverage the fact that we get a free ULONG slot between SizeOfBitMap
        // and Buffer on x64 (due to the latter needing to be 8-byte aligned)
        // and stash a 32-bit hash for the underlying bitmap value.  This is 
        // useful during debugging.  (Currently, CRC-32 is used.)
        //

        struct {
            ULONG SizeOfBitMap;
            ULONG Hash;
            PULONG Buffer;
        };
    };

    ULONG BitmapBuffer[NUMBER_OF_CHARACTER_BITS_IN_DOUBLEWORDS];
} CHARACTER_BITMAP;
typedef CHARACTER_BITMAP *PCHARACTER_BITMAP;

FORCEINLINE
_Success_(return != 0)
BOOLEAN
CreateCharacterBitmapForStringInline(
    _In_ PCLONG_STRING String,
    _Outptr_result_nullonfailure_ PCHARACTER_BITMAP Bitmap
    )
{
    BYTE Byte;
    ULONG Hash;
    ULONG Index;
    ULONG Length;
    PBYTE Buffer;
    PLONG BitmapBuffer;
    PULONG Doublewords;

    //
    // Verify arguments.
    //

    if (!ARGUMENT_PRESENT(Bitmap)) {
        return FALSE;
    }

    //
    // Wire up the underlying RTL_BITMAP structure, clear all bits, and
    // set the hash to 0.
    //

    Bitmap->SizeOfBitMap = NUMBER_OF_CHARACTER_BITS;
    Bitmap->Buffer = (PULONG)&Bitmap->BitmapBuffer;
    ZeroStruct(Bitmap->BitmapBuffer);
    Bitmap->Hash = 0;

    //
    // Initialize variables.
    //

    Length = String->Length;
    Buffer = (PBYTE)String->Buffer;
    BitmapBuffer = (PLONG)&Bitmap->BitmapBuffer;

    //
    // Iterate over each byte in the string, set the corresponding bit
    // in the bitmap.
    //

    for (Index = 0; Index < Length; Index++) {
        Byte = *Buffer++;
        BitTestAndSet(BitmapBuffer, Byte);
    }

    //
    // Calculate the CRC32 hash.
    //

    Hash = Length;
    Doublewords = (PULONG)&Bitmap->BitmapBuffer;
    Hash = _mm_crc32_u32(Hash, Doublewords[0]);
    Hash = _mm_crc32_u32(Hash, Doublewords[1]);
    Hash = _mm_crc32_u32(Hash, Doublewords[2]);
    Hash = _mm_crc32_u32(Hash, Doublewords[3]);

    Bitmap->Hash = Hash;

    //
    // Return success.
    //

    return TRUE;
};

//
// Define character histogram structure and supporting functions.
//

typedef struct _CHARACTER_FREQUENCY_HISTOGRAM {
    DECLSPEC_ALIGN(256) ULONG CharacterCounts[NUMBER_OF_CHARACTER_BITS];
} CHARACTER_FREQUENCY_HISTOGRAM;
typedef CHARACTER_FREQUENCY_HISTOGRAM *PCHARACTER_FREQUENCY_HISTOGRAM;

FORCEINLINE
_Success_(return != 0)
BOOLEAN
CreateCharacterFrequencyHistogramForStringInline(
    _In_ PCLONG_STRING String,
    _Inout_updates_bytes_(sizeof(*Histogram)) PCHARACTER_FREQUENCY_HISTOGRAM Histogram,
    _Outptr_opt_result_nullonfailure_ PULONG HashPointer
    )
{
    BYTE Byte;
    ULONG Hash;
    ULONG Index;
    ULONG Length;
    PBYTE Buffer;
    PULONG Counts;

    //
    // Verify arguments.
    //

    if (!ARGUMENT_PRESENT(String)) {
        return FALSE;
    }

    if (!ARGUMENT_PRESENT(Histogram)) {
        return FALSE;
    }

    if (!IsAligned(Histogram, 256)) {

        //
        // Once we start using AVX2 instrinsics, change this NOTHING
        // into a trap.
        //

        NOTHING;
    }

    //
    // Zero all of the counts.
    //

    ZeroStructPointer(Histogram);

    //
    // Initialize variables.
    //

    Length = String->Length;
    Buffer = (PBYTE)String->Buffer;
    Counts = (PULONG)&Histogram->CharacterCounts;

    //
    // Iterate over each byte in the string and increment its corresponding
    // count in the histogram.
    //

    for (Index = 0; Index < Length; Index++) {
        Byte = Buffer[Index];
        Counts[Byte]++;
    }

    //
    // Calculate the CRC32 hash if the user has provided a valid HashPointer.
    //

    if (ARGUMENT_PRESENT(HashPointer)) {

        Hash = Length;
        for (Index = 0; Index < NUMBER_OF_CHARACTER_BITS; Index += 4) {
            Hash = _mm_crc32_u32(Hash, Counts[Index+0]);
            Hash = _mm_crc32_u32(Hash, Counts[Index+1]);
            Hash = _mm_crc32_u32(Hash, Counts[Index+2]);
            Hash = _mm_crc32_u32(Hash, Counts[Index+3]);
        }

        //
        // Update the caller's pointer.
        //

        *HashPointer = Hash;

    }

    //
    // Return success.
    //

    return TRUE;
};


//
// API exports.
//

DICTIONARY_API CREATE_AND_INITIALIZE_DICTIONARY CreateAndInitializeDictionary;

// vim:set ts=8 sw=4 sts=4 tw=80 expandtab                                     :