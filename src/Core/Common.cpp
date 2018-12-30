#include "Common.hpp"

#include <windows.h>
#include <string>

#include <d3d.h>

#include "Client.hpp"

const char* GetFilePath(const char* path)
{
	char moduleFilePath[MAX_PATH] = { 0 };

	GetModuleFileName(Client::getInstance(), moduleFilePath, MAX_PATH);

	char result[MAX_PATH] = { 0 };

	// remove dll name from path
	auto len = strlen(moduleFilePath);
	for (size_t i = len - 1; i > 0; --i)
	{
		if (moduleFilePath[i] == '\\')
		{
			moduleFilePath[i] = 0;
			break;
		}
	}

	char fixedPath[MAX_PATH] = { 0 };
	strcpy_s(fixedPath, path);

	// change '/' to '\\'
	len = strlen(result);
	for (size_t i = 0; i < strlen(result); ++i)
	{
		if (result[i] == '/')
		{
			result[i] = '\\';
		}
	}

	// merge module path with given path
	sprintf_s(result, "%s\\%s", moduleFilePath, fixedPath);

	return result;
}

const char* GetDXErrorMsg(long hResult)
{
	char* desc;
	size_t count = 1024;

	DWORD result = FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, hResult,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), desc, count, nullptr);

	if (result > 0)
		return "";

	return desc;
}
