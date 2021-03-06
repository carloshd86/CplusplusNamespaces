// Practica8CarlosHD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IFileUtils.h"



void testIFile();
void testIFileUtils();

/********************/




void testIFile()
{
	char * buffer = nullptr;
	unsigned int bytesRead = 0;
	unsigned int bytesWritten = 0;

	printf("IFile tests:\n*********\n\n");

	IFile::FileIdentifier * fId = IFile::OpenFile("test.txt", IFile::FileOpenMode::ReadOnly);

	if (fId)
	{
		buffer = new char[14];
		bytesRead = IFile::ReadFile(buffer, fId, 13);
		buffer[13] = '\0';

		printf("\n%d bytes read from file", bytesRead);
		printf("\nBytes read: %s", buffer);
		bytesRead = IFile::ReadFile(buffer, fId, 13);
		buffer[13] = '\0';

		printf("\n%d bytes read from file", bytesRead);
		printf("\nBytes read: %s", buffer);
		bytesRead = IFile::ReadFile(buffer, fId, 13);
		buffer[13] = '\0';

		printf("\n%d bytes read from file", bytesRead);
		printf("\nBytes read: %s", buffer);
		int file1Closed = IFile::CloseFile(fId);
		printf("\nResult of CloseFile 1: %d", file1Closed);

		fId = IFile::OpenFile("newFile.txt", IFile::FileOpenMode::ReadWrite);
		if (fId)
		{
			bytesWritten = IFile::WriteFile(buffer, fId, 13);
			printf("\n\n%d bytes written in new file", bytesWritten);
			int file2Closed = IFile::CloseFile(fId);
			printf("\nResult of CloseFile 2: %d", file2Closed);
		}
		else
			printf("\n\nFile couldn't be opened");

		delete[]buffer;
		buffer = nullptr;

		fId = IFile::OpenFile("newFile.txt", IFile::FileOpenMode::ReadOnly);
		if (fId)
		{
			buffer = new char[14];

			printf("\n\nNew file opened");
			bytesRead = IFile::ReadFile(buffer, fId, 13);
			buffer[13] = '\0';
			printf("\n%d bytes read from new file", bytesRead);
			printf("\nBytes read: %s", buffer);
			int file3Closed = IFile::CloseFile(fId);
			printf("\nResult of CloseFile 3: %d", file3Closed);

			delete[]buffer;
			buffer = nullptr;
		}
		else
			printf("\n\nFile couldn't be opened");

	}
	else
		printf("\n\nFile couldn't be opened");
}
/********************/


void testIFileUtils()
{
	printf("\n\nIFileUtils tests:\n*********\n\n");

	char str[3] = "it";

	IFile::FileIdentifier * fileText = IFile::OpenFile("text.txt", IFile::FileOpenMode::ReadOnly);

	if (fileText)
	{
		unsigned int iAppearances = IFileUtils::CountStringAppearances(str, fileText);

		printf("\n Number of appearances of the string '%s': %d", str, iAppearances);

		int fileClosed = IFile::CloseFile(fileText);
		printf("\n\n Result of CloseFile: %d", fileClosed);
	}
	else
		printf("\n\nFile couldn't be opened");

	IFile::FileIdentifier * fileIntegers = IFile::OpenFile("integers.txt", IFile::FileOpenMode::ReadOnly);

	if (fileIntegers)
	{
		int iSumIntegers = IFileUtils::SumCommaSeparatedIntegers(fileIntegers);

		printf("\n Sum of the integers: %d", iSumIntegers);

		int fileClosed = IFile::CloseFile(fileIntegers);
		printf("\n\n Result of CloseFile: %d", fileClosed);
	}
	else
		printf("\n\nFile couldn't be opened");

}
/********************/


int main()
{
	testIFile();

	printf("\n\nPress Enter to start IFileUtils tests...");
	getchar();

	testIFileUtils();

	printf("\n\n Press Enter to quit...");
	getchar();

	return 0;
}
/********************/


