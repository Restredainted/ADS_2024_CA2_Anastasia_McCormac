#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_Anastasia_McCormac/TreeMap.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeMapTests
{
	TEST_CLASS(TreeMapTests)
	{
	public:
		
		TEST_METHOD(TestConstructerNoParam)
		{
			TreeMap<int, char> tree;
			
			Assert::AreEqual(tree.Size(), 0);
		}

		TEST_METHOD(TestConstructorWithParam) {

			TreeMap<int, float> tree (3, 0.5f);

			Assert::AreEqual(tree.Size(), 1);
			Assert::AreEqual(tree.Get(3), 0.5f);
		}

		TEST_METHOD(TestClear) {

			TreeMap<int, char> tree { 1,  'a' };

			Assert::AreEqual(tree.Size(), 1);
			tree.Clear();

			Assert::AreEqual(tree.Size(), 0);
		}

		TEST_METHOD(TestPut) {

			TreeMap<int, char> tree { 1,  'b' };

			Assert::AreEqual(tree.Size(), 1);
			char itemA = 'a';
			tree.Put(2, itemA);

			Assert::AreEqual(tree.Size(), 2);

		}

		TEST_METHOD(TestGetValid) {

			TreeMap<char, int> tree { 'b',  3};

			int item = 5;
			tree.Put('a', item);

			Assert::IsTrue(tree.Get('a'));
			Assert::AreEqual(tree.Get('a'), item);
		}

		TEST_METHOD(TestGetInvalid) {

			auto func = [] { TreeMap<char, int>().Get('a'); };

			Assert::ExpectException<std::logic_error>(func);
		}
		TEST_METHOD(TestSize) {

			TreeMap<int, int> tree { 3,  3 };

			Assert::AreEqual(tree.Size(), 1);
			int item = 5;
			tree.Put(8, item);

			Assert::AreEqual(tree.Size(), 2);

			int item1 = 3;
			tree.Put(5, item1);
			Assert::AreEqual(tree.Size(), 3);

		}

		TEST_METHOD(TestContainsKey) {

			TreeMap<char, int> tree { 'b',  3 };

			Assert::IsFalse(tree.ContainsKey('a'));
			int item = 5;
			tree.Put('a', item);

			Assert::IsTrue(tree.ContainsKey('a'));
		}

		TEST_METHOD(TestRemoveKeyValid) {
			TreeMap<char, int> tree { 'b',  3 };

			Assert::IsFalse(tree.ContainsKey('a'));
			int item = 5;
			tree.Put('a', item);

			Assert::IsTrue(tree.ContainsKey('a'));

			Assert::IsTrue(tree.RemoveKey('a'));
			Assert::IsFalse(tree.ContainsKey('a'));
		}

		TEST_METHOD(TestRemoveKeyInvalid) {
			TreeMap<char, int> tree { 'b',  3 };

			Assert::IsFalse(tree.RemoveKey('a'));
			Assert::IsFalse(tree.ContainsKey('a'));
		}

		TEST_METHOD(TestSQBracketValid) {

			TreeMap<char, int> tree { 'b',  3 };

			int item = 5;
			tree.Put('a', item);

			Assert::IsTrue(tree.ContainsKey('a'));
			Assert::AreEqual(tree['a'], item);
		}

		TEST_METHOD(TestSQBracketInvalid) {

			auto func = [] { TreeMap<char, int>()['a']; };

			Assert::ExpectException<std::logic_error>(func);
		}
	};
}
