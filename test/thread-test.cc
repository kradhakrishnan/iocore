#include <list>

#include "unit-test.h"
#include "thread.h"

using namespace std;
using namespace bblocks;

class ThreadTest : public UnitTest
{
public:

	ThreadTest() {}

protected:

	struct MyThread : Thread
	{
		MyThread() : Thread("/threadtest"), run_(false) {}

		void * ThreadMain() override
		{
			while (run_) {
				sleep(1);
			}

			return nullptr;
		}

		bool run_;
	};

	void SetUp() override
	{
		UnitTest::SetUp();

		INVARIANT(threads_.empty());

		for (size_t i = 0; i < SysConf::NumCores(); ++i) {
			auto th = new MyThread();
			th->Start();
			threads_.push_back(th);
		}
	}

	void TearDown() override
	{
		for (auto th : threads_) {
			delete th;
		}
		threads_.clear();

		UnitTest::TearDown();
	}

	void StopMain()
	{
		for (auto th : threads_)
		{
			th->run_ = false;
			th->Join();
		}
	}

	void CancelMain()
	{
		for (auto th : threads_) {
			th->Cancel();
			th->Join();
		}
	}

	std::list<MyThread *> threads_;
};

TEST_F(ThreadTest, testStop)
{
	StopMain();
}

TEST_F(ThreadTest, testCancel)
{
	CancelMain();
}

int
main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
