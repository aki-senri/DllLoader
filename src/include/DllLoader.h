#pragma once
#include <windows.h>
#include <string>

#define DLL_TYPEDEF(ret, method, args) typedef ret(*pf##method)args;
#define DLL_METHOD(method) pf##method method;
#define DLL_FUNCTIONDEF(ret, method, args)	DLL_TYPEDEF(ret, method, args);\
											DLL_METHOD(method);

#define GET_METHOD_ADDRESS(method) method = (pf##method)GetProcAddress(hModule, #method);

class DllLoader
{
public:
	DllLoader() {};
	~DllLoader() {};

	bool Load(std::wstring dll_path)
	{
		hModule = LoadLibrary(dll_path.c_str());
		if (hModule != NULL)
		{
		}
	}

private:
	HMODULE hModule = NULL;
};


