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

// Output stream opereator overload for Game struct. 
std::ostream &operator<<(std::ostream &out, Game &game) {

	out << " | " << printf("%d", game.appId);
	out << " | " << printf("%s", game.title);
	out << " | " << printf("%s", game.relDate);
	out << " | " << printf("%s", ((game.windows) ? "Yes" : "No"));
	out << " | " << printf("%s", ((game.macOS) ? "Yes" : "No" ))
		<< " | " << printf("%s", ((game.linux) ? "Yes" : "No" ))
		<< " | " << printf("%15d", game.rating)
		<< " | " << printf("%5d", game.posRatio)
		<< " | " << printf("%8d", game.userReviews)
		<< " | " << printf("%6f", game.priceFinal)
		<< " | " << printf("%9f", game.priceOriginal)
		<< " | " << printf("%8s", ((game.steamDeck) ? "Yes" : "No" ))
		<< " | " << std::endl;

	return out;
};
