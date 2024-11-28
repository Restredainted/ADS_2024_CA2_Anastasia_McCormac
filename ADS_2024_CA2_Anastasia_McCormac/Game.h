#pragma once
#include <string>

enum Rating {

	OverwhelminglyPositive = 8,
	VeryPositive = 7,
	Positive = 6,
	MostlyPositive = 5, 
	Mixed = 4,
	MostlyNegative = 3,
	Negative = 2, 
	VeryNegative = 1,
	OverwhelminglyNegative = 0
};

// Struct for game objects.
struct Game {

	int appId;
	std::string title;
	std::string relDate;
	bool windows;
	bool macOS;
	bool linux;
	bool steamDeck;
	Rating rating;
	int posRatio;
	int userReviews;
	float priceFinal;
	float priceOriginal;

	// Operator Overload Functions. 
	bool operator < (Game &other) {

		return title < other.title;
	}

	bool operator > (Game &other) {

		return title > other.title;
	}
		
	bool operator== (Game &other) {

		return title == other.title;
	}
};

std::string RatingToStr(Game &game);


// Output stream opereator overload for Game struct. 
std::ostream &operator<<(std::ostream &out, Game &game) {

	 printf("| %-8d | %-25s | %-12s | %-8s | %-8s | %-8s | %-10s | %-24s | %-12d | %-15d | %10.2f | %10.2f |",
		game.appId,
		(game.title.length() <= 25) ? game.title.c_str() : game.title.substr(0, 25).c_str(),
		game.relDate.c_str(),
		((game.windows) ? "Yes" : "No"),
		((game.macOS) ? "Yes" : "No"),
		((game.linux) ? "Yes" : "No"),
		((game.steamDeck) ? "Yes" : "No"),
		RatingToStr(game).c_str(),
		game.posRatio,
		game.userReviews,
		game.priceFinal,
		game.priceOriginal 
	 );
	
	 
	return out;
};

std::string RatingToStr(Game &game) {

	std::string value {};

	switch (game.rating) {

		case 8:
			value = "Overwhelmingly Positive";
			break;

		case 7:
			value = "Very Positive";
			break;

		case 6:
			value = "Positive";
			break;

		case 5:
			value = "Mostly Positive";
			break;

		case 4:
			value = "Mixed";
			break;

		case 3:
			value = "Mostly Negative";
			break;

		case 2:
			value = "Negative";
			break;

		case 1:
			value = "Very Negative";
			break;

		case 0:
			value = "Overwhelmingly Negative";
			break;
	}

	return value;
}