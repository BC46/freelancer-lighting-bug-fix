#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class OperatingSystemChecker
{
private:
    const static bool defaultHasLightingBug = true;

public:
    /// <summary>
    ///	Determines whether or not the current operating system suffers from the major lighting bug in Freelancer.
    /// </summary>
    /// <returns>bool</returns>
    static bool HasLightingBug()
    {
        HMODULE ntdll = GetModuleHandle(L"ntdll.dll");

        // Could not find ntdll (shouldn't happen), assume default
        if (!ntdll)
            return defaultHasLightingBug;

        // Assume the lighting bug isn't present on Wine
        if (GetProcAddress(ntdll, "wine_get_version"))
            return false;

        TCHAR dirBuffer[MAX_PATH];

        const WCHAR* d3d8Location = (GetSystemWow64DirectoryW(dirBuffer, MAX_PATH) != 0
            ? L"C:\\Windows\\SysWOW64\\d3d8.dll"
            : L"C:\\Windows\\system32\\d3d8.dll");

        DWORD  verHandle = 0;
        UINT   size = 0;
        LPBYTE lpBuffer = NULL;
        DWORD  verSize = GetFileVersionInfoSize(d3d8Location, &verHandle);

        long double d3d8BuildNumber = 0;

        // Attempt to get the d3d8 version
        if (verSize != NULL)
        {
            LPSTR verData = new char[verSize];

            if (GetFileVersionInfo(d3d8Location, verHandle, verSize, verData))
            {
                if (VerQueryValue(verData, L"\\", (VOID FAR * FAR*) & lpBuffer, &size))
                {
                    if (size)
                    {
                        VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
                        if (verInfo->dwSignature == 0xfeef04bd)
                        {
                            d3d8BuildNumber = verInfo->dwFileVersionLS >> 16 & 0xffff;
                        }
                    }
                }
            }

            delete[] verData;
        }

        // Test if the check succeeded, return the default value if it didn't
        if (d3d8BuildNumber == 0)
            return defaultHasLightingBug;

        // Windows 10 version 2004 (20H1), or build 19041 is the first known Windows version where the lighting bug appears.
        // Returns true if the current version is equal to or newer than this build.
        return d3d8BuildNumber >= 19041.0L;
    };
};
