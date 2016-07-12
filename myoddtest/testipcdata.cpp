#include <gtest/gtest.h>
#include "myoddinclude.h"
#include "os\ipcdata.h"
#include <string>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

std::wstring Uuid()
{
  return boost::lexical_cast<std::wstring>(boost::uuids::random_generator()());
}

TEST(MyoddOs, CheckThatTheGuiIsSavedProperly) {
  // create the ipc
  auto uuid = Uuid();
  auto ipc = myodd::os::IpcData( uuid );
  ASSERT_EQ(uuid, ipc.GetGuid());
}

TEST(MyoddOs, FromGuidToPtrAndBack) {
  // create the ipc
  auto uuid = Uuid();
  auto ipc = myodd::os::IpcData(uuid);

  auto pData = ipc.GetPtr();
  auto dataSize = (unsigned int)ipc.GetSize();

  auto copyIpc = myodd::os::IpcData(pData, dataSize);
  ASSERT_EQ(uuid, copyIpc.GetGuid());
}

TEST(MyoddOs, GetStringOnly) {
  // create the ipc
  auto uuid = Uuid();
  auto ipc = myodd::os::IpcData(uuid);

  ipc.Add(L"Hello");
  ipc.Add(L"World");

  ASSERT_EQ(L"Hello", ipc.Get<std::wstring>(0));
  ASSERT_EQ(L"World", ipc.Get<std::wstring>(1));
}

TEST(MyoddOs, GetMixtedDataTypes) {
  // create the ipc
  auto uuid = Uuid();
  auto ipc = myodd::os::IpcData(uuid);

  ipc.Add(L"Hello");
  ipc.Add(L"World");
  ipc.Add(42);
  ipc.Add("Something" );

  ASSERT_EQ(L"Hello", ipc.Get<std::wstring>(0));
  ASSERT_EQ(L"World", ipc.Get<std::wstring>(1));
  ASSERT_EQ(42, ipc.Get<int>(2));
  ASSERT_EQ(L"Something", ipc.Get<std::wstring>(3));
}

TEST(MyoddOs, MakeSureThatArgumentCountIsValid) {
  // create the ipc
  auto uuid = Uuid();
  auto ipc = myodd::os::IpcData(uuid);
  ASSERT_EQ(0, ipc.GetNumArguments());

  ipc.Add(L"Hello");
  ASSERT_EQ(1, ipc.GetNumArguments());

  ipc.Add(L"World");
  ASSERT_EQ(2, ipc.GetNumArguments());

  ipc.Add(42);
  ASSERT_EQ(3, ipc.GetNumArguments());

  ipc.Add("Something");
  ASSERT_EQ(4, ipc.GetNumArguments());
}

TEST(MyoddOs, TryingToGetAnOutofRangeItemInEmptyIpc) {
  // create the ipc
  auto ipc = myodd::os::IpcData(Uuid());

  EXPECT_THROW( ipc.Get<std::wstring>(0), std::exception );
}

TEST(MyoddOs, TryingToGetAnOutofRangeItemInNonEmptyIpc) {
  // create the ipc
  auto ipc = myodd::os::IpcData(Uuid());
  ipc.Add(42);

  // we have item 0, but not 1
  EXPECT_THROW(ipc.Get<std::wstring>(1), std::exception);
}
