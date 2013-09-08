#include "ToolsDefine.h"
#include "FileTools.h"
#include "LogTools.h"
#include "StringTools.h"
#include "TimeTools.h"
#include <iostream>
#include <gtest/gtest.h>

using namespace DTools;

TEST(FileTools, ExtractDirectory)
{
    ASSERT_EQ("/foo/bar/", FileTools::extractDirectory("/foo/bar/baz.txt"));
}

TEST(FileTools, ExtractFilename)
{
    ASSERT_EQ("baz.txt", FileTools::extractFilename("/foo/bar/baz.txt"));
}

TEST(FileTools, ExtractFileExtension)
{
    ASSERT_EQ(".txt", FileTools::extractFileExtension("/foo/bar/baz.txt"));
    ASSERT_EQ("", FileTools::extractFileExtension("/foo/bar/baz"));
}

TEST(FileTools, ChangeFileExtension)
{
    ASSERT_EQ("/foo/bar/baz.dat", FileTools::changeFileExtension("/foo/bar/baz.txt", ".dat"));
    ASSERT_EQ("/foo/bar/baz", FileTools::changeFileExtension("/foo/bar/baz.txt", ""));
    ASSERT_EQ("/foo/bar/baz.txt", FileTools::changeFileExtension("/foo/bar/baz", ".txt"));
}

int main(int argc, char * argv[])
{
	// test start

	// test end

    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
