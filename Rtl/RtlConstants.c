/*++

Copyright (c) 2017 Trent Nelson <trent@trent.me>

Module Name:

    RtlConstants.c

Abstract:

    This module defines constants used by the Rtl component.

--*/

#include "stdafx.h"

CONST PCSTR RtlFunctionNames[] = {
    "RtlCharToInteger",
    "RtlSubtreeSuccessor",
    "RtlSubtreePredecessor",
    "RtlRealSuccessor",
    "RtlRealPredecessor",
    "RtlInitializeGenericTable",
    "RtlInsertElementGenericTable",
    "RtlInsertElementGenericTableFull",
    "RtlDeleteElementGenericTable",
    "RtlLookupElementGenericTable",
    "RtlLookupElementGenericTableFull",
    "RtlEnumerateGenericTable",
    "RtlEnumerateGenericTableWithoutSplaying",
    "RtlGetElementGenericTable",
    "RtlNumberGenericTableElements",
    "RtlIsGenericTableEmpty",
    "RtlInitializeGenericTableAvl",
    "RtlInsertElementGenericTableAvl",
    "RtlInsertElementGenericTableFullAvl",
    "RtlDeleteElementGenericTableAvl",
    "RtlLookupElementGenericTableAvl",
    "RtlLookupElementGenericTableFullAvl",
    "RtlEnumerateGenericTableAvl",
    "RtlEnumerateGenericTableWithoutSplayingAvl",
    "RtlLookupFirstMatchingElementGenericTableAvl",
    "RtlEnumerateGenericTableLikeADirectory",
    "RtlGetElementGenericTableAvl",
    "RtlNumberGenericTableElementsAvl",
    "RtlIsGenericTableEmptyAvl",
    "PfxInitialize",
    "PfxInsertPrefix",
    "PfxRemovePrefix",
    "PfxFindPrefix",
    "RtlPrefixString",
    "RtlPrefixUnicodeString",
    "RtlCreateHashTable",
    "RtlDeleteHashTable",
    "RtlInsertEntryHashTable",
    "RtlRemoveEntryHashTable",
    "RtlLookupEntryHashTable",
    "RtlGetNextEntryHashTable",
    "RtlEnumerateEntryHashTable",
    "RtlEndEnumerationHashTable",
    "RtlInitWeakEnumerationHashTable",
    "RtlWeaklyEnumerateEntryHashTable",
    "RtlEndWeakEnumerationHashTable",
    "RtlExpandHashTable",
    "RtlContractHashTable",
    "RtlInitializeBitMap",
    "RtlClearBit",
    "RtlSetBit",
    "RtlTestBit",
    "RtlClearAllBits",
    "RtlSetAllBits",
    "RtlFindClearBits",
    "RtlFindSetBits",
    "RtlFindClearBitsAndSet",
    "RtlFindSetBitsAndClear",
    "RtlClearBits",
    "RtlSetBits",
    "RtlFindClearRuns",
    "RtlFindLongestRunClear",
    "RtlNumberOfClearBits",
    "RtlNumberOfSetBits",
    "RtlAreBitsClear",
    "RtlAreBitsSet",
    "RtlFindFirstRunClear",
    "RtlFindNextForwardRunClear",
    "RtlFindLastBackwardRunClear",
    "RtlInitializeUnicodePrefix",
    "RtlInsertUnicodePrefix",
    "RtlRemoveUnicodePrefix",
    "RtlFindUnicodePrefix",
    "RtlNextUnicodePrefix",
    "RtlCopyUnicodeString",
    "RtlInitString",
    "RtlCopyString",
    "RtlAppendUnicodeToString",
    "RtlAppendUnicodeStringToString",
    "RtlUnicodeStringToAnsiSize",
    "RtlUnicodeStringToAnsiString",
    "RtlEqualString",
    "RtlEqualUnicodeString",
    "RtlCompareString",
    "RtlCompareMemory",
    "RtlPrefetchMemoryNonTemporal",
    "RtlMoveMemory",
    "RtlCopyMemory",
    "RtlCopyMappedMemory",
    "RtlFillMemory",
    "RtlLocalTimeToSystemTime",
    "RtlTimeToSecondsSince1970",
    "bsearch",
    "qsort",
    "memset",
    "MmGetMaximumFileSectionSize",
    "K32GetProcessMemoryInfo",
    "K32GetPerformanceInfo",
    "GetProcessIoCounters",
    "GetProcessHandleCount",
    "K32InitializeProcessForWsWatch",
    "K32GetWsChanges",
    "K32GetWsChangesEx",
    "K32QueryWorkingSet",
    "K32QueryWorkingSetEx",
    "ZwQueryInformationProcess",
    "LdrRegisterDllNotification",
    "LdrUnregisterDllNotification",
    "LdrLockLoaderLock",
    "LdrUnlockLoaderLock",
    "ZwAllocateVirtualMemory",
    "ZwFreeVirtualMemory",
    "AllocateUserPhysicalPages",
    "AllocateUserPhysicalPagesNuma",
    "MapUserPhysicalPages",
    "MapUserPhysicalPagesScatter",
    "FreeUserPhysicalPages",
    "RtlCreateHeap",
    "RtlDestroyHeap",
    "RtlAllocateHeap",
    "RtlFreeHeap",
    "RtlCaptureStackBackTrace",
    "RtlPcToFileHeader",
    "RtlLookupFunctionEntry",
    "RtlAddFunctionTable",
    "RtlDeleteFunctionTable",
    "RtlInstallFunctionTableCallback",
    "RtlAddGrowableFunctionTable",
    "RtlGrowFunctionTable",
    "RtlDeleteGrowableFunctionTable",
    "ZwCreateSection",
    "ZwMapViewOfSection",
    "ZwUnmapViewOfSection",
    "ZwCreateProcess",
    "ZwCreateProcessEx",
    "ZwCreateThread",
    "ZwOpenThread",
    "ZwTerminateThread",
    "NtQueueApcThread",
    "NtTestAlert",
    "SearchPathW",
    "CreateToolhelp32Snapshot",
    "LoadLibraryA",
    "LoadLibraryW",
    "LoadLibraryExW",
    "GetProcAddress",
    "CloseHandle",
    "OpenEventA",
    "OpenEventW",
    "GetLastError",
    "SetLastError",
    "SetEvent",
    "ResetEvent",
    "SuspendThread",
    "ResumeThread",
    "GetThreadContext",
    "SetThreadContext",
    "WaitForSingleObject",
    "WaitForSingleObjectEx",
    "SignalObjectAndWait",
    "SleepEx",
    "ExitThread",
    "GetExitCodeThread",
    "TerminateThread",
    "QueueUserAPC",
    "DeviceIoControl",
    "GetModuleHandleA",
    "GetModuleHandleW",
    "CreateFileW",
    "CreateFileMappingW",
    "OpenFileMappingW",
    "MapViewOfFileEx",
    "FlushViewOfFile",
    "UnmapViewOfFileEx",
    "VirtualAllocEx",
    "VirtualFreeEx",
    "VirtualProtectEx",
    "VirtualQueryEx",
    "DebugActiveProcessStop",
    "DebugSetProcessKillOnExit",
    "Thread32First",
    "Thread32Next",
};

CONST PCSTR RtlExFunctionNames[] = {
    "DestroyRtl",
    "ArgvWToArgvA",
    "CopyPagesMovsq",
    "CopyPagesAvx2",
    "CopyPagesMovsq_C",
    "CopyPagesAvx2_C",
    "CopyToMemoryMappedMemory",
    "CreateBitmapIndexForString",
    "CreateBitmapIndexForUnicodeString",
    "CurrentDirectoryToRtlPath",
    "CurrentDirectoryToUnicodeString",
    "DestroyPathEnvironmentVariable",
    "DestroyRtlPath",
    "DisableCreateSymbolicLinkPrivilege",
    "DisableDebugPrivilege",
    "DisableIncreaseWorkingSetPrivilege",
    "DisableLockMemoryPrivilege",
    "DisableManageVolumePrivilege",
    "DisablePrivilege",
    "DisableProfileSingleProcessPrivilege",
    "DisableSystemProfilePrivilege",
    "EnableCreateSymbolicLinkPrivilege",
    "EnableDebugPrivilege",
    "EnableIncreaseWorkingSetPrivilege",
    "EnableLockMemoryPrivilege",
    "EnableManageVolumePrivilege",
    "EnablePrivilege",
    "EnableProfileSingleProcessPrivilege",
    "EnableSystemProfilePrivilege",
    "FilesExistA",
    "FilesExistW",
    "FindCharsInString",
    "FindCharsInUnicodeString",
    "GetModuleRtlPath",
    "InitializeRtlFile",
    "LoadFile",
    "LoadDbgEng",
    "LoadDbgHelp",
    "LoadPathEnvironmentVariable",
    "LoadShlwapi",
    "PrefaultPages",
    "RegisterDllNotification",
    "RtlCheckBit",
    "SetPrivilege",
    "StringToExistingRtlPath",
    "StringToRtlPath",
    "TestExceptionHandler",
    "UnicodeStringToExistingRtlPath",
    "UnicodeStringToRtlPath",
    "UnregisterDllNotification",
    "WriteEnvVarToRegistry",
    "WriteRegistryString",
};

CONST PCSTR DbgHelpFunctionNames[] = {
    "EnumDirTree",
    "EnumDirTreeW",
    "EnumerateLoadedModules64",
    "EnumerateLoadedModules",
    "EnumerateLoadedModulesEx",
    "EnumerateLoadedModulesExW",
    "EnumerateLoadedModulesW64",
    "FindFileInPath",
    "FindFileInSearchPath",
    "GetSymLoadError",
    "GetTimestampForLoadedLibrary",
    "MakeSureDirectoryPathExists",
    "RangeMapAddPeImageSections",
    "RangeMapRead",
    "RangeMapRemove",
    "RangeMapWrite",
    "ReportSymbolLoadSummary",
    "SearchTreeForFile",
    "SearchTreeForFileW",
    "StackWalk64",
    "StackWalkEx",
    "StackWalk",
    "SymAddrIncludeInlineTrace",
    "SymAddSourceStreamA",
    "SymAddSourceStream",
    "SymAddSourceStreamW",
    "SymAddSymbol",
    "SymAddSymbolW",
    "SymCleanup",
    "SymCompareInlineTrace",
    "SymDeleteSymbol",
    "SymDeleteSymbolW",
    "SymEnumerateModules64",
    "SymEnumerateModules",
    "SymEnumerateModulesW64",
    "SymEnumerateSymbols64",
    "SymEnumerateSymbols",
    "SymEnumerateSymbolsW64",
    "SymEnumerateSymbolsW",
    "SymEnumLines",
    "SymEnumLinesW",
    "SymEnumProcesses",
    "SymEnumSourceFiles",
    "SymEnumSourceFilesW",
    "SymEnumSourceFileTokens",
    "SymEnumSourceLines",
    "SymEnumSourceLinesW",
    "SymEnumSymbolsEx",
    "SymEnumSymbolsExW",
    "SymEnumSymbolsForAddr",
    "SymEnumSymbolsForAddrW",
    "SymEnumSymbols",
    "SymEnumSymbolsW",
    "SymEnumSym",
    "SymEnumTypesByName",
    "SymEnumTypesByNameW",
    "SymEnumTypes",
    "SymEnumTypesW",
    "SymFindFileInPath",
    "SymFindFileInPathW",
    "SymFromAddr",
    "SymFromAddrW",
    "SymFromIndex",
    "SymFromIndexW",
    "SymFromInlineContext",
    "SymFromInlineContextW",
    "SymFromName",
    "SymFromNameW",
    "SymFromToken",
    "SymFromTokenW",
    "SymGetFileLineOffsets64",
    "SymGetLineFromAddr64",
    "SymGetLineFromAddr",
    "SymGetLineFromAddrW64",
    "SymGetLineFromInlineContext",
    "SymGetLineFromInlineContextW",
    "SymGetLineFromName64",
    "SymGetLineFromName",
    "SymGetLineFromNameW64",
    "SymGetLineNext64",
    "SymGetLineNext",
    "SymGetLineNextW64",
    "SymGetLinePrev64",
    "SymGetLinePrev",
    "SymGetLinePrevW64",
    "SymGetModuleBase",
    "SymGetModuleInfo64",
    "SymGetModuleInfo",
    "SymGetModuleInfoW64",
    "SymGetModuleInfoW",
    "SymGetOmaps",
    "SymGetOptions",
    "SymGetScope",
    "SymGetScopeW",
    "SymGetSearchPath",
    "SymGetSearchPathW",
    "SymGetSourceFileFromToken",
    "SymGetSourceFileFromTokenW",
    "SymGetSourceFile",
    "SymGetSourceFileToken",
    "SymGetSourceFileTokenW",
    "SymGetSourceFileW",
    "SymGetSourceVarFromToken",
    "SymGetSourceVarFromTokenW",
    "SymGetSymbolFile",
    "SymGetSymbolFileW",
    "SymGetSymFromAddr64",
    "SymGetSymFromAddr",
    "SymGetSymFromName64",
    "SymGetSymFromName",
    "SymGetSymNext64",
    "SymGetSymNext",
    "SymGetSymPrev64",
    "SymGetSymPrev",
    "SymGetTypeFromName",
    "SymGetTypeFromNameW",
    "SymGetTypeInfoEx",
    "SymGetTypeInfo",
    "SymGetUnwindInfo",
    "SymInitialize",
    "SymInitializeW",
    "SymLoadModule",
    "SymLoadModuleEx",
    "SymLoadModuleExW",
    "SymMatchFileName",
    "SymMatchFileNameW",
    "SymMatchStringA",
    "SymMatchString",
    "SymMatchStringW",
    "SymNext",
    "SymNextW",
    "SymPrev",
    "SymPrevW",
    "SymQueryInlineTrace",
    "SymRefreshModuleList",
    "SymRegisterCallback64",
    "SymRegisterCallback",
    "SymRegisterCallbackW64",
    "SymRegisterFunctionEntryCallback64",
    "SymRegisterFunctionEntryCallback",
    "SymSearch",
    "SymSearchW",
    "SymSetContext",
    "SymSetOptions",
    "SymSetParentWindow",
    "SymSetScopeFromAddr",
    "SymSetScopeFromIndex",
    "SymSetScopeFromInlineContext",
    "SymSetSearchPath",
    "SymSetSearchPathW",
    "SymSrvGetFileIndexes",
    "SymSrvGetFileIndexesW",
    "SymSrvGetFileIndexInfo",
    "SymSrvGetFileIndexInfoW",
    "SymSrvGetFileIndexString",
    "SymSrvGetFileIndexStringW",
    "SymSrvIsStore",
    "SymSrvIsStoreW",
    "SymUnDName64",
    "SymUnDName",
    "SymUnloadModule64",
    "SymUnloadModule",
    "UnDecorateSymbolName",
    "UnDecorateSymbolNameW",
    "ImageNtHeader",
    "ImageDirectoryEntryToData",
    "ImageDirectoryEntryToDataEx",
    "ImageRvaToSection",
    "ImageRvaToVa"
};

CONST PCSTR CuFunctionNames[] = {
    "cuInit",
    "cuGetErrorName",
    "cuGetErrorString",
    "cuDeviceGet",
    "cuDeviceGetCount",
    "cuDeviceGetName",
    "cuDeviceTotalMem_v2",
    "cuDeviceComputeCapability",
    "cuDeviceGetAttribute",
    "cuCtxCreate_v2",
    "cuCtxDestroy_v2",
    "cuCtxPushCurrent_v2",
    "cuCtxPopCurrent_v2",
    "cuCtxSetCurrent",
    "cuCtxGetCurrent",
    "cuCtxGetDevice",
    "cuCtxSynchronize",
    "cuCtxGetStreamPriorityRange",
    "cuModuleLoad",
    "cuModuleUnload",
    "cuModuleLoadDataEx",
    "cuModuleGetFunction",
    "cuModuleGetGlobal_v2",
    "cuStreamCreate",
    "cuStreamCreateWithPriority",
    "cuStreamDestroy_v2",
    "cuStreamQuery_ptsz",
    "cuStreamSynchronize_ptsz",
    "cuStreamAddCallback_ptsz",
    "cuStreamAttachMemAsync_ptsz",
    "cuStreamWaitEvent_ptsz",
    "cuStreamWaitValue32_ptsz",
    "cuStreamWriteValue32_ptsz",
    "cuStreamBatchMemOp_ptsz",
    "cuEventCreate",
    "cuEventDestroy_v2",
    "cuEventElapsedTime",
    "cuEventQuery",
    "cuEventRecord_ptsz",
    "cuEventSynchronize",
    "cuMemAlloc_v2",
    "cuMemFree_v2",
    "cuMemHostAlloc",
    "cuMemPrefetchAsync_ptsz",
    "cuMemHostGetDevicePointer_v2",
    "cuMemHostRegister_v2",
    "cuMemHostUnregister",
    "cuMemFreeHost",
    "cuMemcpyHtoD_v2_ptds",
    "cuMemcpyDtoH_v2_ptds",
    "cuMemcpyHtoDAsync_v2_ptsz",
    "cuMemcpyDtoHAsync_v2_ptsz",
    "cuLaunchKernel_ptsz",
};

// vim:set ts=8 sw=4 sts=4 tw=80 expandtab nowrap                              :
