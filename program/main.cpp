#include "ItemType.h"
#include "Heap.h"
#include <exception>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

int main(int argc, char **argv) {

    cout << "How is world" << endl;

// {
//     cout << "Hello, World" << endl;

//     if (argc <= 1)
//     {
//         cout << "Usage: ./main [list_file] " << endl;
//         return 1;
//     }

//     Heap * bossTree = new Heap();

//     // Read in item input
//     ItemType item;
//     int input;
//     std::fstream file;
//     file.open(argv[1], fstream::in);

//     if (file.is_open())
//     {
//         //    cout << "opened file" << endl;
//         while (!file.eof())
//         {
//             file >> input;

//             item.initialize(input);
//             bossTree->insert(item);
//             //cin.get(); // error handling
//             // file >> input;
//         }
//     }
//     else
//     {
//         cout << "Failed to open the input file" << endl;
//         return 1;
//     }

}