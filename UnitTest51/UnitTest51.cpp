#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.1/lab5.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51
{
    TEST_CLASS(UnitTest51)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double t;
            t = g(0.0, 0.0);
            Assert::AreEqual(1.0, t, 0.0001);
        }
    };
}