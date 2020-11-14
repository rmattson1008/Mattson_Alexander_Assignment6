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
    int MAX_LENGTH = 0;
    std::fstream file;
    file.open(argv[1], fstream::in);

    if (file.is_open())
    {
        //    cout << "opened file" << endl;
        file >> input;
        while (!file.eof())
        {
            // cout << MAX_LENGTH << endl;
            // cout << input << endl;
            MAX_LENGTH += 1;
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

    rawData = new ItemType[MAX_LENGTH];
    cout << "MAX_LENGTH: " << MAX_LENGTH << endl;

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

    // cout << rawData[0].getValue() << endl;

    // Menu
    cout << "selection-sort (s)merge-sort (m)heap-sort (h)quick-sort-fp(q)quick-sort-rp (r)" << endl;

    string choice;
    bool running = true;
    Sorting sorter;
    int comps = 0;

    // Begin user choice menu
    while (running)
    {
        cout << "Enter the algorithm: ";
        cin >> choice;

        if (choice.compare("s") == 0)
        {
            // comps = sorter.SelectionSort(rawData);
            cout << "Comparisons: " << comps<< endl;
        }
        else if (choice.compare("m") == 0)
        {
            int first = 0;
            int last = MAX_LENGTH - 1;
            comps = sorter.MergeSort(rawData, first, last, MAX_LENGTH);
            cout << "Comparisons: " << comps << endl;
        }
        else if (choice.compare("h") == 0)
        {
            // comps = sorter.HeapSort(rawData);
            cout << "Comparisons: " << comps<< endl;
        }
        else if (choice.compare("r") == 0)
        {
            // comps = sorter.QuickSort_R(rawData);
            cout << "Comparisons: " << comps<< endl;
        }
        else if (choice.compare("q") == 0)
        {
            // comps = sorter.QuickSort_FP(rawData);
            cout << "Comparisons: " << comps<< endl;
        } else if (choice.compare("e") == 0)
        {
            
            cout << "Exiting..." << endl;
            return 0;
        }else { 
            cout << "Command not recognized. Try again" << endl;
        }
    }

    // at end of main
    delete[] rawData;
    // get MAX_LENGTH of input
}