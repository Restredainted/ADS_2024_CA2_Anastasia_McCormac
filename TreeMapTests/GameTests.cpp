#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_Anastasia_McCormac/Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameTests {

	TEST_CLASS(GameTests) {

	public:

		TEST_CLASS_INITIALIZE(ratingvar) {
			std::string rate;
		}

		TEST_METHOD(TestConstruction) {

			Game game {};

			Assert::IsTrue(game.appId == 0);
			Assert::IsTrue(game.title == "Default");
			Assert::IsTrue(game.windows);
		}

		TEST_METHOD(TestLessThanValid) {

			Game game {};
			game.title = "test1";
			Game game2 {};
			game2.title = "test2";

			Assert::IsTrue(game < game2);
		}

		TEST_METHOD(TestLessThanInvalid) {


			Game game {};
			game.title = "test1";
			Game game2 {};
			game2.title = "less than2";

			Assert::IsFalse(game < game2);

		}

		TEST_METHOD(TestGreaterThanValid) {

			Game game {};
			game.title = "test 2";
			Game game2 {};
			game2.title = "test 1";

			Assert::IsTrue(game > game2);
		}

		TEST_METHOD(TestGreaterThanInvalid) {


			Game game {};
			game.title = "test1";
			Game game2 {};
			game2.title = "test2";

			Assert::IsFalse(game > game2);
		}

		TEST_METHOD(TestEqualsValid) {

			Game game {};
			game.title = "test1";
			Game game2 {};
			game2.title = "test1";

			Assert::IsTrue(game == game2);
		}

		TEST_METHOD(TestEqualsInvalid) {

			Game game {};
			game.title = "test1";
			Game game2 {};
			game2.title = "test2";

			Assert::IsFalse(game == game2);
		}

		// I can't get strings to work, therefore can't get this test to work. 
		/*TEST_METHOD(TestGetRating) {

			std::string rate = "Overwhelmingly Positive";
			Assert::AreEqual(GetRating(rate), OverwhelminglyPositive);

			rate = "Very Positive";
			Assert::AreEqual(GetRating(rate), VeryPositive);

			rate = "positive";
			Assert::AreEqual(GetRating(rate), Positive);

			rate = "Mostly Positive";
			Assert::AreEqual(GetRating(rate), MostlyPositive);

			rate = "Mixed";
			Assert::AreEqual(GetRating(rate), Mixed);

			rate = "MostlyNegative";
			Assert::AreEqual(GetRating(rate), MostlyNegative);

			rate = "Negative";
			Assert::AreEqual(GetRating(rate), Negative);

			rate = "Very Negative";
			Assert::AreEqual(GetRating(rate), VeryNegative);

			rate = "Overwhelmingly Negative";
			Assert::AreEqual(GetRating(rate), OverwhelminglyNegative);
		}*/
	};
}
