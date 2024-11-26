// ADS_2024_CA2_Anastasia_McCormac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinaryTree.h"
#include "Entity.h"
#include "TreeMap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void Q1();
void Q2();
void Q3();
void Q4();

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

/// <summary>
/// Contains basic tests to see if the tree works with the given entity.
/// </summary>
void Q1() {

    BinaryTree<Entity<int, std::vector<std::string>>> testTree {};

    Entity<int, std::vector<std::string>> newEnt { 2, std::vector<std::string>{"World"}};
    testTree.add(newEnt);

    newEnt = Entity<int, std::vector<std::string>> { 1, std::vector<std::string>{"Hello"}};
    testTree.add(newEnt);

    newEnt = Entity<int, std::vector<std::string>>{3, std::vector<std::string>{"!"}};
    testTree.add(newEnt);

    testTree.printInOrder();
};

void Q2() {
    
    // Ref: Rath, R. (2020). The Infinite and the Divine. 1st ed, Black Library.
    std::fstream fin { "InfiniteAndDivineExtract.txt"};

    BinaryTree<Entity<char, std::vector<std::string>>> uniqueWordTree {};

    if (fin) {
        
        std::cout << "File open";

        Entity<char, std::vector<std::string>> wordEnt {};
        std::string line;

        while (std::getline(fin, line, ' ')) {

            //std::cout << "Line: " << line << std::endl;

            /*std::string word;

            while (line.at(' ') != 0) {

                word = line.substr(line.at(' '));
                std::cout << word << std::endl;

                line = line.substr(line.at(' '));

                word = line.at(line.find_first_of(' '));
                std::cout << word;*/

            wordEnt = Entity<char, std::vector<std::string>> { line.at(0), std::vector<std::string>{line} };
                //cout << wordEnt << endl;;

                uniqueWordTree.add(wordEnt);
            //}
        }
    }
    std::cout << "\n\n\n" << std::endl;
    
    uniqueWordTree.printInOrder();
};

void Q3() {

};

void Q4() {

};
