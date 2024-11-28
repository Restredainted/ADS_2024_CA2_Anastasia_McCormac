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

void Q1();
void Q2();
void Q3();
void Q4();
int tryStoi(const std::string &input);



int main()
{
    std::cout << " ADS_2024_CA2_Anastasia_McCormac\n";

    Q1();
    Q2(); 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

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
    std::fstream fin { "InfiniteAndDivineExtract.txt"};

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

};

#pragma endregion

#pragma region Stage 4

void Q4() {

};

#pragma endregion


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