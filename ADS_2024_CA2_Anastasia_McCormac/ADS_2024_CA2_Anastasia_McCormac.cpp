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
void Q3(TreeMap<char, BinaryTree<Game>> &tree); // Now takes i tree to assign info to. 
void Q4();
int tryStoi(const std::string &input);
float tryStof(const std::string &input);
Rating GetRating(std::string &input);
void printHeaders();
enum question { A = 1, B = 2, C = 3, D = 4 };

int main()
{
    std::cout << " ADS_2024_CA2_Anastasia_McCormac\n";

    // Change this value to change which question is accessed. 
    question showQ { D };

    switch (showQ) {
    
    case A:
        Q1();
        break;

    case B:
        Q2();
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

void Q3(TreeMap<char, BinaryTree<Game>> &tree) {

    // Ref: Kozyriev, A. (2024). Game Recommendations on Steam (Online) Available at: 
    // https://www.kaggle.com/datasets/antonkozyriev/game-recommendations-on-steam [Last Accessed 28/11/2024]
    std::fstream fin { "games.csv" };

    if (fin) {

        std::cout << "File Opened Successfully, Reading Data.\n";

        std::string line;

        std::getline(fin, line); // Clear headers row.

        while (std::getline(fin, line)) {

            std::stringstream ss(line);
            std::string item;
            char delim { ',' };

            Game newGame {};

            std::getline(ss, item, delim);
            newGame.appId = tryStoi(item);

            std::getline(ss, item, delim);
            newGame.title = item;

            std::getline(ss, item, delim);
            newGame.relDate = item;

            std::getline(ss, item, delim);
            newGame.windows = (item == "true" || "TRUE") ? true : false;

            std::getline(ss, item, delim);
            newGame.macOS = (item == "true" || "TRUE") ? true : false;

            std::getline(ss, item, delim);
            newGame.linux = (item == "true" || "TRUE") ? true : false;

            std::getline(ss, item, delim);
            newGame.rating = GetRating(item);

            std::getline(ss, item, delim);
            newGame.posRatio = tryStof(item) / 100;

            std::getline(ss, item, delim);
            newGame.userReviews = tryStoi(item);

            std::getline(ss, item, delim);
            newGame.price = tryStof(item);

            std::getline(ss, item, delim);
            newGame.steamDeck = (item == "true" || "TRUE") ? true : false;

            if (tree.ContainsKey(newGame.title.at(0))) {
                
                tree.Get(newGame.title.at(0)).add(newGame);
            }

            else {

                BinaryTree<Game> gameList {};
                gameList.add(newGame);
                tree.Put(newGame.title.at(0), gameList);
            }

            ss.flush();
        }

        fin.close();
        std::cout << "File Reading Complete." << std::endl;
    }

    else {
        // Will leave empty tree if file fails to load. 
        std::cout << "File read failed, no data loaded." << std::endl;

    }

    std::cout.flush();
};

#pragma endregion

#pragma region Stage 4

void Q4() {

    TreeMap<char, BinaryTree<Game>> steamGames {};
    Q3(steamGames);

    printHeaders();
    steamGames.PrintInOrder();
};

#pragma endregion

#pragma region Utility


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
/// Function to try conversion of a string into an int.
/// </summary>
/// <param name="input">String attempt conversion.</param>
/// <returns> If successful returns integer, otherwise returns -1</returns>
float tryStof(const std::string &input) {

    float output;

    try {

        output = stof(input);
    }

    catch (...) {

        std::cout << "Conversion failure of Value: " << input << std::endl;
        output = -1;
    }

    return output;
}

/// <summary>
/// Simple hard code to print headers for tree Table. 
/// </summary>
void printHeaders() {
    printf("\n| %-8s | %-25s | %-12s | %-8s | %-8s | %-8s | %-10s | %-24s | %-6.3s | %-7s | %-6s |",
        "App ID", "Title", "Release Date", "Windows", "Mac OS", "Linux", "Steam Deck", "Rating", "Ratio", "Reviews", "Price"
    );
}

#pragma endregion

