#include "pch.h"
#include "CppUnitTest.h"
#include "../lab05.2/lab05.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
    TEST_CLASS(UnitTest52)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double a = -0.5;
            A(0.5, 1, a);
            Assert::AreEqual(-0.125, a, 0.0001);
        }
    };
}