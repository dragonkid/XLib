#include "ToolsDefine.h"
#include "FileTools.h"
#include "LogTools.h"
#include "StringTools.h"
#include "TimeTools.h"
#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace DTools;

// FileTools
TEST(FileTools, ExtractDirectory)
{
    EXPECT_EQ("/foo/bar/", FileTools::extractDirectory("/foo/bar/baz.txt"));
}
TEST(FileTools, ExtractFilename)
{
    EXPECT_EQ("baz.txt", FileTools::extractFilename("/foo/bar/baz.txt"));
}
TEST(FileTools, ExtractFileExtension)
{
    EXPECT_EQ(".txt", FileTools::extractFileExtension("/foo/bar/baz.txt"));
    EXPECT_EQ("", FileTools::extractFileExtension("/foo/bar/baz"));
}
TEST(FileTools, ChangeFileExtension)
{
    EXPECT_EQ("/foo/bar/baz.dat", FileTools::changeFileExtension("/foo/bar/baz.txt", ".dat"));
    EXPECT_EQ("/foo/bar/baz", FileTools::changeFileExtension("/foo/bar/baz.txt", ""));
    EXPECT_EQ("/foo/bar/baz.txt", FileTools::changeFileExtension("/foo/bar/baz", ".txt"));
}

//TEST(FileTools, MakeDirectory)
//{
//#ifdef WIN32
//	EXPECT_EQ(true, FileTools::makeDirectory("C:\\logs\\"));
//	EXPECT_EQ(true, FileTools::makeDirectory("C:\\logs\\"));
//	EXPECT_EQ(false, FileTools::makeDirectory(""));
//	EXPECT_EQ(false, FileTools::makeDirectory("C:\\logs/a"));
//	EXPECT_EQ(false, FileTools::makeDirectory("/home/logs\a"));
//	EXPECT_EQ(false, FileTools::makeDirectory("/home/logs"));
//#else
//	EXPECT_EQ(false, FileTools::makeDirectory("C:\\logs\\"));
//	EXPECT_EQ(false, FileTools::makeDirectory(""));	
//	EXPECT_EQ(false, FileTools::makeDirectory("C:\\logs/a"));
//	EXPECT_EQ(false, FileTools::makeDirectory("/home/logs\a"));
//	EXPECT_EQ(true, FileTools::makeDirectory("/home/logs"));
//	EXPECT_EQ(true, FileTools::makeDirectory("/home/logs"));
//#endif
//}

// TimeTools
TEST(TimeTools, GetTZOffsetByZonename)
{
	DFloat8 zoneOffset = 0;
	ASSERT_TRUE(TimeTools::getLocalTZOffset(zoneOffset));
	EXPECT_EQ(28800, zoneOffset);
}

// StringTools
TEST(StringTools, ValueToString)
{
	EXPECT_EQ("123.456", StringTools::valueToString(123.456));
	EXPECT_EQ("123", StringTools::valueToString(123));
}

int main(int argc, char * argv[])
{
	// log test start
	DLOGGER_INIT;
	// base write log function test.
	//DLOGGER << 12312412 << "asdfasdfa" << std::endl;
	//DLOGGER << "asdfas" << std::endl;
	//std::vector<std::string> tmp_vecTest;
	//tmp_vecTest.push_back("Show me the money.");
	//tmp_vecTest.push_back("Black sheep wall.");
	//DLOGGER << "tmp_vecTest:\n";
	//for (std::vector<std::string>::size_type i = 0; i < tmp_vecTest.size(); ++i)
	//{
	//	DLOGGER << "\t" + DTools::StringTools::valueToString(i + 1) + ". " << tmp_vecTest.at(i) << "\n";
	//}
	//DLOGGER << std::endl;
	//DLOGGER << "test" << std::endl;
	// file partition function test.
	//for (;;)
	//{
	//	DLOGGER << "asdfasasdfasdfasdafddddddddddddddddddddddddddddddddd" << std::endl;
	//}
	// flow id function test.

	DLOGGER_END;
	// log test end

    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
