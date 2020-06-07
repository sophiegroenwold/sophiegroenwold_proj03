// main.cpp
// runs functions given in intlist.cpp

#include "intlist.h"

#include <cstdlib> // provides atoi
#include <iostream>
#include <cassert>

using namespace std;

void test_1()
{
    IntList list;
    int arr [] = {5, 2, 15, 30, 4};
    for (int i = 0; i < 5; i++)
        list.append(arr[i]);
    cout << "list: ";
    list.print();
    cout << " max: " << list.max() << endl;

    IntList list2;
    int arr2 [] = {-4, -3, -1, -11};
    for (int i = 0; i < 4; i++)
        list2.append(arr2[i]);
    cout << "list2: ";
    list2.print();
    cout << " max: " << list2.max() << endl;
}

void test_2()
{
    
}

void test_3()
{
    
}

void test_4()
{
    
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Error: need at least one int arg on command line" << endl;
        cout << "Usage: " << argv[0] << " testid " << endl;
        return 0;
    }

    else if (atoi(argv[1]) == 1)
    {
        test_1();
    }

    else if (atoi(argv[1]) == 2)
    {
        test_2();
    }

    else if (atoi(argv[1]) == 3)
    {
        test_3();
    }

    else if (atoi(argv[1]) == 4)
    {
        test_4();
    }

    else
    {
        cout << "Please enter a number [1, 4]" << endl; 
    }
    
    return 0;
}