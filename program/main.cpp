#include "ItemType.h"
#include "Heap.h"
#include "Sorting.h"
#include <exception>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{

    cout << "How is world" << endl;

    // {
    //     cout << "Hello, World" << endl;

    if (argc <= 1)
    {
        cout << "Usage: ./main [list_file] " << endl;
        return 1;
    }

    ItemType *rawData;
    ItemType item;
    int input;
    int length = 0;
    std::fstream file;
    file.open(argv[1], fstream::in);

    if (file.is_open())
    {
        //    cout << "opened file" << endl;
        file >> input;
        while (!file.eof())
        {
            // cout << length << endl;
            cout << input << endl;
            length += 1;
            item.initialize(input);
            //cin.get(); // error handling
            file >> input;
        }
    }
    else
    {
        cout << "Failed to open the input file1" << endl;
        return 1;
    }

    rawData = new ItemType[length];
    cout << "Length: " << length << endl;

    //     // Read in item input
    std::fstream file2;
    file2.open(argv[1], fstream::in);
    int count = 0;

    if (file2.is_open())
    {
        //    cout << "opened file" << endl;
        while (!file2.eof())
        {
            file2 >> input;

            item.initialize(input);
            rawData[count] = item;
            count += 1;
            //cin.get(); // error handling
            // file >> input;
        }
    }
    else
    {
        cout << "Failed to open the input file2" << endl;
        return 1;
    }

    cout << rawData[0].getValue() << endl;

    // Menu
    cout << "selection-sort (s)merge-sort (m)heap-sort (h)quick-sort-fp(q)quick-sort-rp (r)" << endl;

    string choice;
    bool running = true;
    Sorting sorter;

    // Begin user choice menu
    while (running)
    {
        cout << "Enter the algorithm: ";
        cin >> choice;

        if (choice.compare("s") == 0)
        {
            sorter.SelectionSort(rawData);
        }
        else if (choice.compare("m") == 0)
        {
            sorter.MergeSort(rawData);
        }
        else if (choice.compare("h") == 0)
        {
            sorter.HeapSort(rawData);
        }
        else if (choice.compare("r") == 0)
        {
            sorter.QuickSort_R(rawData);
        }
        else if (choice.compare("q") == 0)
        {
            sorter.QuickSort_FP(rawData);
        }
    }

    // at end of main
    delete[] rawData;
    // get length of input
}