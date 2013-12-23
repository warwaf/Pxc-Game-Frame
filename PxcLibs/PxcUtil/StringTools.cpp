#include "StringTools.h"
#include <windows.h>

namespace PxcUtil
{


namespace StringTools
{

std::wstring StrToWstr(const std::string& str)
{
	std::wstring wstrRet;
	if (str.empty())
		return wstrRet;
	int iSize = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	if (iSize != 0)
	{
		LPWSTR wszBuf = new WCHAR[iSize];
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wszBuf, iSize);
		wstrRet = wszBuf;
		delete []wszBuf;
	}
	return wstrRet;
}

std::string WstrToStr(const std::wstring& wstr)
{
	std::string strRet;
	if (wstr.empty())
		return strRet;
	int iSize = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
	if (iSize != 0)
	{
		LPSTR szBuf = new CHAR[iSize];
		WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, szBuf, iSize, NULL, NULL);
		strRet = szBuf;
		delete []szBuf;
	}
	return strRet;
}

std::string Trim(const std::string& str)
{
	if (str.empty())
		return str;

	int i = 0, iSize = str.size();
	while (i < iSize && (str[i] == ' ' || str[i] == '\t' ||
		str[i] == '\n' || str[i] == '\r')) i++;
	if (i >= iSize)
		return "";

	int iMax = iSize - 1;
	while (iMax >= i && (str[iMax] == ' ' || str[iMax] == '\t' ||
		str[iMax] == '\n' || str[iMax] == '\r')) iMax--;

	std::string strRet;
	for (; i <= iMax; ++i)
		strRet.push_back(str[i]);
	return strRet;
}

std::wstring Trim(const std::wstring& wstr)
{
	if (wstr.empty())
		return wstr;

	int i = 0, iSize = wstr.size();
	while (i < iSize && (wstr[i] == L' ' || wstr[i] == L'\t' ||
		wstr[i] == L'\n' || wstr[i] == L'\r')) i++;
	if (i >= iSize)
		return L"";

	int iMax = iSize - 1;
	while (iMax >= i && (wstr[iMax] == L' ' || wstr[iMax] == L'\t' ||
		wstr[iMax] == L'\n' || wstr[iMax] == L'\r')) iMax--;

	std::wstring wstrRet;
	for (; i <= iMax; ++i)
		wstrRet.push_back(wstr[i]);
	return wstrRet;
}

}


}