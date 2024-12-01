#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_Anastasia_McCormac/Entity.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EntityTests
{
	TEST_CLASS(EntityTests) {

	public:

		TEST_METHOD(TestConstruction) {

			Entity<char, int> entity {'a', 3};
			
			Assert::IsTrue(entity.key == 'a');
			Assert::IsTrue(entity.value == 3); 
		}

		TEST_METHOD(TestLessThanValid) {

			Entity<char, int> entity { 'a', 3 };
			Entity<char, int> entity2 { 'c', 5 };

			Assert::IsTrue(entity < entity2);
		}

		TEST_METHOD(TestLessThanInvalid) {

			Entity<char, int> entity { 'b', 3 };
			Entity<char, int> entity2 { 'a', 5 };

			Assert::IsFalse(entity < entity2);

		}

		TEST_METHOD(TestGreaterThanValid) {

			Entity<char, int> entity { 'b', 3 };
			Entity<char, int> entity2 { 'a', 5 };

			Assert::IsTrue(entity > entity2);
		}

		TEST_METHOD(TestGreaterThanInvalid) {

			Entity<char, int> entity { 'a', 3 };
			Entity<char, int> entity2 { 'c', 5 };

			Assert::IsFalse(entity > entity2);
		}

		TEST_METHOD(TestEqualsValid) {

			Entity<char, int> entity { 'c', 3 };
			Entity<char, int> entity2 { 'c', 5 };

			Assert::IsTrue(entity == entity2);
		}

		TEST_METHOD(TestEqualsInvalid) {

			Entity<char, int> entity { 'a', 3 };
			Entity<char, int> entity2 { 'c', 5 };

			Assert::IsFalse(entity == entity2);
		}
	};
}