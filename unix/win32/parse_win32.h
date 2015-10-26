#ifndef PARSE_WIN32_H
#define PARSE_WIN32_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Shlobj.h>
#include <io.h>
#include <direct.h>

#pragma comment(lib, "Ws2_32")

#define PATH_MAX 260
#define mkdir(path, permissions) _mkdir(path)
#define rmdir(path) _rmdir(path)

#define lstat(path, buffer) _stat(path, buffer)
#define stat _stat
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)

#define chmod(path, permissions) 0
#define S_ISUID 0

//#define open(path, flags, pmode) _open(path, flags, pmode)
#define open _open
#define read(handle, buf, length) _read(handle, buf, length)
#define write(handle, buf, length) _write(handle, buf, length)
#define close(handle) _close(handle)
#define strdup(string) _strdup(string)
#define S_IRWXU (_S_IREAD | _S_IWRITE)

struct passwd {
	char pw_dir[MAX_PATH];
};

static struct passwd * getpwuid(int unused) {
	static struct passwd pw;
	SHGetFolderPathA(0, CSIDL_PROFILE, 0, 0, pw.pw_dir);
	return &pw;
}

static int getuid() {
	return 1;
}

struct utsname {
	char sysname[16];    /* Operating system name (e.g., "Linux") */
	char release[16];    /* Operating system release (e.g., "2.6.28") */
	char machine[16];    /* Hardware identifier */
};

#if _MSC_VER > 1800
#include <VersionHelpers.h>
#else
static BOOL IsWindowsVersionOrGreater(WORD wMajorVersion, WORD wMinorVersion, WORD wServicePackMajor)
{
	OSVERSIONINFOEXW osvi = { sizeof(osvi), 0, 0, 0, 0,{ 0 }, 0, 0 };
	DWORDLONG        const dwlConditionMask = VerSetConditionMask(
		VerSetConditionMask(
			VerSetConditionMask(
				0, VER_MAJORVERSION, VER_GREATER_EQUAL),
			VER_MINORVERSION, VER_GREATER_EQUAL),
		VER_SERVICEPACKMAJOR, VER_GREATER_EQUAL);

	osvi.dwMajorVersion = wMajorVersion;
	osvi.dwMinorVersion = wMinorVersion;
	osvi.wServicePackMajor = wServicePackMajor;

	return VerifyVersionInfoW(&osvi, VER_MAJORVERSION | VER_MINORVERSION | VER_SERVICEPACKMAJOR, dwlConditionMask) != FALSE;
}
#endif

static int uname(struct utsname *buf) {
	int major = -1;
	int minor = -1;
	strcpy_s(buf->sysname, sizeof(buf->sysname), "Windows");

	do {
		major++;
	} while (IsWindowsVersionOrGreater(major + 1, 0, 0));

	do {
		minor++;
	} while (IsWindowsVersionOrGreater(major, minor + 1, 0));

	sprintf_s(buf->release, sizeof(buf->release), "%i.%i", major, minor);
	
#if defined(_AMD64_)
	strcpy_s(buf->machine, sizeof(buf->machine), "x86_64");
#elif defined(_X86_)
	strcpy_s(buf->machine, sizeof(buf->machine), "x86");
#elif defined(_ARM_)
	strcpy_s(buf->machine, sizeof(buf->machine), "arm");
#else
	strcpy_s(buf->machine, sizeof(buf->machine), "unknown");
#endif
	
	return 0;
}

static long strtoumax(const char *nptr, char **endptr, int base) {
	return strtoul(nptr, endptr, base);
}

#endif