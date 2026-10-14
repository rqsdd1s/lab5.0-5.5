#include "pch.h"
#include "CppUnitTest.h"
#include "../lab05.3/lab05.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
    TEST_CLASS(UnitTest53)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double t;
            t = f(0.5);
            Assert::AreEqual(0.40021, t, 0.0001);
        }
    };
}