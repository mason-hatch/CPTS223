#include <stdio.h>
#include <random>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "AVLNode.h"
#include "AVLTree.h"

int main()
{
    int data[50] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99};

    AVLTree<int> ascending, descending, random;

    for(int i = 0; i < 50; i++)
    {
        ascending.insert(data[i]);
        descending.insert(data[49 - i]);
    }

    //std::random_device rd;
    //std::mt19937 g(rd());
    //std::shuffle(data[0],data[49], g);

    //for(int i = 0; i < 50; i++)
    //{
    //    random.insert(data[i]);
    //}

    std::cout << "ascending height: " << ascending.height() << "\n";
    std::cout << "descending height: " << descending.height() << "\n";
    //std::cout << "random height: " << random.height() << "\n";



    return 0;
}