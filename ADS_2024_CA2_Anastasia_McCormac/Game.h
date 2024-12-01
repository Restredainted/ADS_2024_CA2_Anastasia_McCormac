// Author: Anastasia McCormac - GD3a
// Created on: 28/11/2024
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

	int appId = 0;
	std::string title = "Default";
	std::string relDate = "DD/MM/YYYY"; // Simply using a string to avoid using Date/Times. May Update if I have time. 
	bool windows = true;
	bool macOS = true;
	bool linux = true;
	bool steamDeck = true;
	Rating rating = Mixed;
	float posRatio = 0.0;
	int userReviews = 0;
	float price = 0.0;

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
std::ostream &operator<<(std::ostream &out, Rating &rating);

// Output stream operator overload for Game struct. 
std::ostream &operator<<(std::ostream &out, Game &game) {

	 printf("| %-8d | %-25s | %-12s | %-8s | %-8s | %-8s | %-10s | %-24s | %-6f | %-7d | %6.2f |",
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
		game.price
	 );
	 
	 return out;
};

/// <summary>
/// Discerns the string value as it's appropriate enum state. 
/// </summary>
/// <param name="input">String to evaluate.</param>
/// <returns>Rating Enum value.</returns>
Rating GetRating(std::string &input) {

	if (input == "Overwhelmingly Positive")
		return OverwhelminglyPositive;

	if (input == "Very Positive")
		return VeryPositive;

	if (input == "Positive")
		return Positive;

	if (input == "Mostly Positive")
		return MostlyPositive;

	if (input == "Mixed")
		return Mixed;

	if (input == "Mostly Negative")
		return MostlyNegative;

	if (input == "Negative")
		return Negative;

	if (input == "Very Negative")
		return VeryNegative;

	if (input == "Overwhelmingly Negative")
		return OverwhelminglyNegative;

	return Mixed;
}

/// <summary>
/// Evaluate the rating of a game to a string value.
/// </summary>
/// <param name="game">Game object of which to evaluate its rating. </param>
/// <returns>Game's rating as a string.</returns>
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

/// <summary>
/// Rating stream output overload
/// </summary>
/// <param name="game">Rating to send upstream.</param>
/// <returns>ostream operator.</returns>
std::ostream &operator<<(std::ostream &out, Rating &rating) {

	switch (rating) {

	case 8:
		out << "Overwhelmingly Positive";
		break;

	case 7:
		out << "Very Positive";
		break;

	case 6:
		out << "Positive";
		break;

	case 5:
		out << "Mostly Positive";
		break;

	case 4:
		out << "Mixed";
		break;

	case 3:
		out << "Mostly Negative";
		break;

	case 2:
		out << "Negative";
		break;

	case 1:
		out << "Very Negative";
		break;

	case 0:
		out << "Overwhelmingly Negative";
		break;
	}

	return out;
}