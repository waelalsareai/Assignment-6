//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;


// Paste your function implementations here


int main()
{
    cout << "Enter a tag: ";
    string tag;
    getline(cin, tag);  // read a full line of input including spaces

    // Some sample inputs you can copy-paste to test your main
    // <image source="puppy.jpg" width="100px" height="200px">
    // <image source="cat_pounce.gif" height="400px" width="300px" padding="10px">
    // <image width="400px" height="250px" padding="10px 5px" source="little_red_snake.mpeg">

    cout << "Tag:" << tag << endl;
    // Add your code here to print out information about the tag

}
