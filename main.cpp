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
    int max = list2.max();
    cout << " max: " << max << endl;
}

void test_2()
{
    IntList list1;
    int arr1 [] = {4, -1, 8, 4, 2, 9};
    for (int i = 0; i < 6; i++)
        list1.append(arr1[i]);
    
    IntList list2;
    int arr2 [] = {3, -10, -3, 0, 2, 6};
    for (int i = 0; i < 6; i++)
        list2.insertFirst(arr2[i]);

    list2 = list1;
}

void test_3()
{
    IntList list;
    int arr1 [] = {2, 0, 3, 3, 0, 4};
    for (int i = 0; i < 6; i++)
        list.append(arr1[i]);

    cout << "list: ";
    list.print();
    cout << " average: " << list.average() << ", sum: " 
        << list.sum() << ", count: " << list.count() << endl;

    int arr2 [] = {7, 2, 5, 1};
    for (int i = 0; i < 4; i++)
        list.append(arr2[i]);

    cout << "list: ";
    list.print();
    cout << " average: " << list.average() << ", sum: " 
        << list.sum() << ", count: " << list.count() << endl;
}

void test_4()
{
    IntList list1;
    int arr1 [] = {2, 0, 3, 3, 0, 4};
    for (int i = 0; i < 6; i++)
        list1.append(arr1[i]);
    
    IntList list2(list1);
    cout << "list1: ";
    list1.print();
    cout << endl;
    cout << "list2: ";
    list2.print();
    cout << endl;

    IntList list3;
    list3.append(0);
    IntList list4(list3);

    cout << "list3: ";
    list3.print();
    cout << endl;
    cout << "list4: ";
    list4.print();
    cout << endl;
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
        test_1();

    else if (atoi(argv[1]) == 2)
        test_2();

    else if (atoi(argv[1]) == 3)
        test_3();

    else if (atoi(argv[1]) == 4)
        test_4();

    else
        cout << "Please enter a number [1, 4]" << endl; 
    
    return 0;
}