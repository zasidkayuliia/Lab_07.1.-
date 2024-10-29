#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1.rec/Lab_07.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int testMatrix[rowCount][colCount] = {
				{ -5, 2, 7 },
				{ -8, 6, 3 },
				{ 9, -4, 12 }
			};

			int** q = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				q[i] = new int[colCount];
				for (int j = 0; j < colCount; j++) {
					q[i][j] = testMatrix[i][j];
				}
			}

			int expectedS = 2;
			int expectedK = 6;

			int S = 0;
			int k = 0;


			Calc(q, rowCount, colCount, S, k);

			Assert::AreEqual(expectedS, S);
			Assert::AreEqual(expectedK, k);

			for (int i = 0; i < rowCount; i++) {
				delete[] q[i];
			}
			delete[] q;
		}
	};
}

	