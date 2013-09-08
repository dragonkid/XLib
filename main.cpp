#include "ToolsDefine.h"
#include "FileTools.h"
#include "LogTools.h"
#include "StringTools.h"
#include "TimeTools.h"
#include <iostream>
#include <gtest/gtest.h>

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
// TimeTools
TEST(TimeTools, GetTZOffsetByZonename)
{
	DFloat8 zoneOffset = 0;
	ASSERT_TRUE(TimeTools::getLocalTZOffset(zoneOffset));
	EXPECT_EQ(28800, zoneOffset);
}

int main(int argc, char * argv[])
{
	// test start
	DFloat8 tmp;
	DTools::TimeTools::getLocalTZOffset(tmp);
	LOG_TO_CONSOLE("Timezone offset is: ", tmp);
	// test end

    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
