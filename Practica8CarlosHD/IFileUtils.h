#pragma once

#include "IFile.h"

namespace IFileUtils
{
	unsigned int CountStringAppearances(const char * strToSearch, const IFile::FileIdentifier * fileId);
	int SumCommaSeparatedIntegers(const IFile::FileIdentifier * fileId);
}