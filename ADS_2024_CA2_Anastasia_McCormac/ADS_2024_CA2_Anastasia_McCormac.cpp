// ADS_2024_CA2_Anastasia_McCormac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TreeMap.h"
#include "Entity.h"
#include "BinaryTree.h"

void Q1();
void Q2();
void Q3();
void Q4();

int main()
{
    std::cout << " ADS_2024_CA2_Anastasia_McCormac\n";

    Q1();
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

    BinaryTree<Entity<int, std::string>> testTree {};

    Entity<int, std::string> newEnt { 2, "World" };
    testTree.add(newEnt);

    newEnt = Entity<int, std::string>(1, "Hello");
    testTree.add(newEnt);

    newEnt = Entity<int, std::string>(3, "!");
    testTree.add(newEnt);

    testTree.printInOrder();
};

void Q2() {

};

void Q3() {

};

void Q4() {

};
