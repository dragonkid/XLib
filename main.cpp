#include "XLib.h"
#include <iostream>
#include <gtest/gtest.h>

using namespace XLib;

TEST(InterfaceTest, ExtractDirectory)
{
    ASSERT_EQ("/foo/bar/", FileOperate::extractDirectory("/foo/bar/baz.txt"));
}

TEST(InterfaceTest, ExtractFilename)
{
    ASSERT_EQ("baz.txt", FileOperate::extractFilename("/foo/bar/baz.txt"));
}

TEST(InterfaceTest, ExtractFileExtension)
{
    ASSERT_EQ(".txt", FileOperate::extractFileExtension("/foo/bar/baz.txt"));
    ASSERT_EQ("", FileOperate::extractFileExtension("/foo/bar/baz"));
}

TEST(InterfaceTest, ChangeFileExtension)
{
    ASSERT_EQ("/foo/bar/baz.dat", FileOperate::changeFileExtension("/foo/bar/baz.txt", ".dat"));
    ASSERT_EQ("/foo/bar/baz", FileOperate::changeFileExtension("/foo/bar/baz.txt", ""));
    ASSERT_EQ("/foo/bar/baz.txt", FileOperate::changeFileExtension("/foo/bar/baz", ".txt"));
}

int main(int argc, char * argv[])
{
	// test start
    //XLib::XLogger::instance();
	// test end

    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
