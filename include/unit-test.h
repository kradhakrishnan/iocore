#pragma once

#include <gtest/gtest.h>

#include "logger.h"
#include "sysconf.h"

namespace bblocks {

class UnitTest : public ::testing::Test
{
public:
protected:

	void SetUp() override
	{
		LogHelper::InitConsoleLogger();
		RRCpuId::Init();
	}

	void TearDown() override
	{
		RRCpuId::Destroy();
		LogHelper::DestroyLogger();
	}
};

}

