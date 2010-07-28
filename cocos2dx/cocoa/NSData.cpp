/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/


#include "NSData.h"

#include <stdio.h>

using namespace std;

NSData::NSData(void)
{
	m_pData = NULL;
}

NSData::~NSData(void)
{
	if (m_pData)
	{
		delete[] m_pData;
	}
}

NSData* NSData::dataWithContentsOfFile(const string &strPath)
{
	NSData *pRet = new NSData();

	FILE *pFile;
	pFile = fopen(strPath.c_str(), "rb");

	if (! pFile)
	{
		return false;
	}

	fseek(pFile, 0, SEEK_END);

	int nSize = ftell(pFile);

	fseek(pFile, 0, SEEK_SET);

	pRet->m_pData = new char[nSize];

	fread(pRet->m_pData, sizeof(char), nSize, pFile);

	fclose(pFile);

	return pRet;
}

void* NSData::bytes(void)
{
	return m_pData;
}

///@todo implement
NSData* NSData::dataWithBytes(UINT8 *pBytes, int size)
{
	return NULL;
}
