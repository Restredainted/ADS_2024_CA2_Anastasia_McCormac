// Author: Anastasia McCormac - GD3a
// Created on: 
// ADS_2024_CA2_Anastasia_McCormac.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TreeMap.h"
#include "Entity.h"
#include "BinaryTree.h"
#include "Game.h"

void Q1();
void Q2();
void Q3();
void Q4();
int tryStoi(const std::string &input);
Rating getRating(std::string &input);
enum question { A = 1, B = 2, C = 3, D = 4 };

int main()
{
    std::cout << " ADS_2024_CA2_Anastasia_McCormac\n";

    // Change this value to change which question is accessed. 
    question showQ { C };

    switch (showQ) {
    
    case A:
        Q1();
        break;

    case B:
        Q2();
        break;

    case C:
        Q3();
        break;

    case D:
        Q4();
        break;

    default:
        break;
    }
}

#pragma region Stage 1

/// <summary>
/// Contains basic tests to see if the tree works with the given entity.
/// </summary>
void Q1() {

    BinaryTree<Entity<int, std::string>> testTree {};

    //Entity<int, std::string> newEnt {2, "World"};
    //testTree.add(newEnt);

    //newEnt = Entity<int, std::string>(1, "Hello");
    //testTree.add(newEnt);

    //newEnt = Entity<int, std::string>(3, "!");
    //testTree.add(newEnt);

    testTree.printInOrder();
};

#pragma endregion

#pragma region Stage 2

void Q2() {
    
    // Ref: Rath, R. (2020). The Infinite and the Divine. 1st ed, Black Library.
    std::fstream fin { "InfiniteAndDivineExtract.txt" };

    TreeMap<char, BinaryTree<std::string>> uniqueWordTree {};

    if (fin) {
        
        std::cout << "File Opened Successfully";

        std::string line;

        while (!fin.eof()) {

            std::getline(fin, line);
            std::stringstream ss(line);
            std::string word;
            char delim {' '};

            while (std::getline(ss, word, delim)) {

                if (uniqueWordTree.ContainsKey(word.at(0))) {

                    uniqueWordTree.Get(word.at(0)).add(word);
                }

                else {

                    BinaryTree<std::string> wordEnt {};
                    wordEnt.add(word);
                    uniqueWordTree.Put(word.at(0), wordEnt);
                }
                
                ss.flush();
            }
        }
    }

    else {

        std::cout << "File read failed." << std::endl;
    }
    

    fin.close();

    std::string input;
    int selection = 0;
    
    do {

        std::cout << "\n What would you like to view?" << std::endl;
        std::cout << "1. View unique letters." << std::endl;
        std::cout << "2. View words by letter." << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::getline(std::cin, input);

        selection = tryStoi(input);

        switch (selection) {

            case 1:
                //uniqueWordTree.KeySet().printInOrder();
                break;

            case 2:
                uniqueWordTree.PrintInOrder();
                break;
        }
    }
    while (selection != 0);

    std::cout << "Goodbye" << std::endl;
};

#pragma endregion

#pragma region Stage 3

void Q3() {


    // Ref: Kozyriev, A. (2024). Game Recommendations on Steam (Online) Available at: 
    // https://www.kaggle.com/datasets/antonkozyriev/game-recommendations-on-steam [Last Accessed 28/11/2024]
    std::fstream fin { "games.csv" };

    TreeMap<char, BinaryTree<Game>> steamGames {};

    steamGames.PrintInOrder();
    if (fin) {

        std::cout << "File Opened Successfully\n";

        std::string line;

        std::getline(fin, line); // Clear headers row.

        std::cout << line << std::endl;
        while (std::getline(fin, line)) {
            
            std::stringstream ss(line);
            std::string item;
            char delim { ',' };

            std::cout << line << std::endl;
            Game newGame {};

            std::getline(ss, item, delim);
            //std::cout << item;
            newGame.appId = tryStoi(item);

            std::getline(ss, item, delim);
            //std::cout << item;
            newGame.title = item;

            std::getline(ss, item, delim);
            //std::cout << item;
            newGame.relDate = item;

            std::getline(ss, item, delim);
            //std::cout << item;
            newGame.windows = (item == "TRUE") ? true : false;

            std::getline(ss, item, delim);
            //std::cout << item;
            newGame.macOS = (item == "TRUE") ? true : false;

            std::getline(ss, item, delim);
            newGame.linux = (item == "TRUE") ? true : false;

            std::getline(ss, item, delim);
            newGame.rating = getRating(item);

            std::getline(ss, item, delim);
            newGame.posRatio = tryStoi(item);

            std::getline(ss, item, delim);
            newGame.userReviews = tryStoi(item);

            std::getline(ss, item, delim);
            newGame.priceFinal;

            std::getline(ss, item, delim);
            newGame.priceOriginal;

            std::getline(ss, item, delim);
            newGame.steamDeck = (item == "TRUE") ? true : false;

            std::cout << newGame;


            if (steamGames.ContainsKey(newGame.title.at(0))) {

                steamGames.Get(newGame.title.at(0)).add(newGame);
            }

            else {

                BinaryTree<Game> gameList {};
                gameList.add(newGame);
                steamGames.Put(newGame.title.at(0), gameList);
            }

            ss.flush();
        }
    }

    else {

        std::cout << "File read failed." << std::endl;
    }

    steamGames.PrintInOrder();
};



#pragma endregion

#pragma region Stage 4

void Q4() {

};

#pragma endregion


/// <summary>
/// Function to try conversion of a string into an int.
/// </summary>
/// <param name="input">String attempt conversion.</param>
/// <returns> If successful returns integer, otherwise returns -1</returns>
int tryStoi(const std::string &input) {

    int output;

    try {

        output = stoi(input);
    }

    catch (...) {

        std::cout << "Conversion failure of Value: " << input << std::endl;
        output = -1;
    }

    return output;
}

/// <summary>
/// Discerns the string value as it's appropriate enum state. 
/// </summary>
/// <param name="input">String to evaluate.</param>
/// <returns>Rating Enum value.</returns>
Rating getRating(std::string &input) {
    
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
