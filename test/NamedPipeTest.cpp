#include "gtest/gtest.h"

#include "NamedPipe.h"
#include "TestHelper.h"
#include <string>

namespace {
  class NamedPipeTest : public ::testing::Test {
//   protected:
//     Foo foo;
  };

  TEST_F(NamedPipeTest, NamedPipeInitSelf) {
    NamedPipe namedPipe;
    namedPipe.filePath = "Fugus";
    namedPipe.pipeHandle = 0xDEADBEEF;
    NamedPipeInitSelf(&namedPipe);
    ASSERT_NE(namedPipe.filePath, "Fugus");
    ASSERT_NE(namedPipe.pipeHandle, 0xDEADBEEF);
  }

  TEST_F(NamedPipeTest, NamedPipeCreate) {
    NamedPipe namedPipe;
    std::string filePath("/tmp/testfifo");

    unlink(filePath.c_str()); // delete fifo if existing
    NamedPipeInitSelf(&namedPipe);
    ASSERT_NE(-1, NamedPipeCreate(&namedPipe, filePath.c_str()));
    ASSERT_TRUE(TestHelper::FileExists(filePath));
    NamedPipeDestroy(&namedPipe);
  }

  TEST_F(NamedPipeTest, NamedPipeDestroy) {
    NamedPipe namedPipe;
    std::string filePath("/tmp/testfifo");

    NamedPipeInitSelf(&namedPipe);
    NamedPipeCreate(&namedPipe, filePath.c_str());
    ASSERT_NE(-1, NamedPipeDestroy(&namedPipe));
    ASSERT_FALSE(TestHelper::FileExists(filePath));
  }

//  TEST_F(NamedPipeTest, NamedPipeOpenRead) {
//    NamedPipe namedPipe;
//    std::string filePath("/tmp/testfifo");
//
//    NamedPipeInitSelf(&namedPipe);
//    NamedPipeCreate(&namedPipe, filePath.c_str());
//    ASSERT_NE(-1, NamedPipeOpen(&namedPipe, NAMED_PIPE_READ));
//    NamedPipeClose(&namedPipe);
//    NamedPipeDestroy(&namedPipe);
//  }
//
//  TEST_F(NamedPipeTest, NamedPipeOpenWrite) {
//    NamedPipe namedPipe;
//    std::string filePath("/tmp/testfifo");
//
//    NamedPipeInitSelf(&namedPipe);
//    NamedPipeCreate(&namedPipe, filePath.c_str());
//    ASSERT_NE(-1, NamedPipeOpen(&namedPipe, NAMED_PIPE_WRITE));
//    NamedPipeClose(&namedPipe);
//    NamedPipeDestroy(&namedPipe);
//  }
//
//  TEST_F(NamedPipeTest, NamedPipeClose) {
//    NamedPipe namedPipe;
//    std::string filePath("/tmp/testfifo");
//
//    NamedPipeInitSelf(&namedPipe);
//    NamedPipeCreate(&namedPipe, filePath.c_str());
//    NamedPipeOpen(&namedPipe, NAMED_PIPE_READ);
//    ASSERT_NE(-1, NamedPipeClose(&namedPipe));
//    NamedPipeDestroy(&namedPipe);
//  }

}
