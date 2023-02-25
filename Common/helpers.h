#pragma once

#include <Windows.h>

class OperatingSystemChecker
{
private:
    typedef NTSTATUS(CALLBACK* RtlGetVersion)(RTL_OSVERSIONINFOEXW* versionInfo);
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

        RtlGetVersion rtlGetVersion = (RtlGetVersion)GetProcAddress(ntdll, "RtlGetVersion");

        // Could not find RtlGetVersion (shouldn't happen), assume default
        if (!rtlGetVersion)
            return defaultHasLightingBug;

        RTL_OSVERSIONINFOEXW osInfo;
        rtlGetVersion(&osInfo);

        // Code below has been shamelessly yoinked from https://github.com/oliverpechey/Freelancer-hd-edition-install-script/blob/main/utilities.iss

        // No issues on Windows 8.1 and older.
        if (osInfo.dwMajorVersion < 10)
            return false;
        // Because the issue was introduced in Windows 10 Minor 0, newer versions definitely have it too.
        else if (osInfo.dwMajorVersion > 10 || osInfo.dwMinorVersion > 0)
            return true;

        // Windows 10 version 2004 (20H1), or build 19041 is the first known Windows version where the lighting bug appears.
        // Returns true if the current version is equal to or newer than this build.
        return osInfo.dwBuildNumber >= 19041;
	};
};
