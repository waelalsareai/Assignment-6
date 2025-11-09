//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Functions to write.
// You do NOT need to write doxygen comments for these. You may add extra helper
// functions if you want. Work on them one at a time.

// Helper: extract value of an attribute name="VALUE"
string getAttributeValue(const string& tag, const string& name) {
    string key = name + "=\"";
  size_t pos = tag.find(key);
  if (pos == string::npos) return "";
  pos += key.length();
    size_t endPos = tag.find("\"", pos);
  return tag.substr(pos, endPos - pos);}

// Helper: extract the tag name (e.g., img from <img src="...">)
string getTagName(const string& tag) {
  size_t start = tag.find("<") + 1;
size_t end = tag.find(" ");
if (end == string::npos)
    end = tag.find(">");
return tag.substr(start, end - start);
}

// Helper: check if a tag is self-closing (like <br/> or <img/>)
bool isSelfClosing(const string& tag) {
    return tag[tag.size() - 2] == '/';
}

// Extract the value inside source="..."
// Extract: returns "cat_pounce.gif"
string getImageSource(string tag) {
  string value = getAttributeValue(tag, "source");
  return value;
}

// Replace underscores with spaces
string underscoresToSpaces(string str) {
    for (size_t i = 0; i < str.size(); i++) {
      if (str[i] == '_')
      str[i] = ' ';
    }
    return str;
  }

// Extract width="100px" -> returns 100
int getImageWidth(string tag) {
  string value = getAttributeValue(tag, "width");
  int num = stoi(value.substr(0, value.size() - 2));
return num;
}

// Extra height="200px" -> rerturns 200
int getImageHeight(string tag) {
  string value = getAttributeValue(tag, "height");
  int num = stoi(value.substr(0, value. size () - 2));
return num;
{
  
// string getImageSource(string tag)

// string underscoresToSpaces(string str)

// int getImageWidth(string tag)

// int getImageHeight(string tag)

// int getVerticalPadding(string tag)

// int getHorizontalPadding(string tag)

//-----------------------------------------------------------------------------------
// Testing code

// The line "// clang-format off" below turns off auto-formatting
// That will keep the example strings from being reformatted to multiple lines
// clang-format off
const string EXAMPLE_1 = "<image source=\"puppy.jpg\" width=\"100px\" height=\"200px\">";
const string EXAMPLE_2 = "<image source=\"cat_pounce.gif\" height=\"400px\" width=\"300px\" padding=\"10px\">";
const string EXAMPLE_3 = "<image width=\"400px\" height=\"250px\" padding=\"10px 5px\" source=\"little_red_snake.mpeg\">";
// clang-format on
// "// clang-format on" turns auto-formatting back on

// TEST_CASE("Testing getImageSource")
// {
//   cout << "1: getImageSource" << endl;
//   CHECK(getImageSource(EXAMPLE_1) == "puppy.jpg");
//   CHECK(getImageSource(EXAMPLE_2) == "cat_pounce.gif");
//   CHECK(getImageSource(EXAMPLE_3) == "little_red_snake.mpeg");
// }

// TEST_CASE("Testing underscoresToSpaces")
// {
//   cout << "2: underscoresToSpaces" << endl;
//   CHECK(underscoresToSpaces("puppy.jpg") == "puppy.jpg");
//   CHECK(underscoresToSpaces("cat_pounce.gif") == "cat pounce.gif");
//   CHECK(underscoresToSpaces("little_red_snake.mpeg")
//         == "little red snake.mpeg");
// }

// TEST_CASE("Testing getImageWidth")
// {
//   cout << "3: getImageWidth" << endl;
//   CHECK(getImageWidth(EXAMPLE_1) == 100);
//   CHECK(getImageWidth(EXAMPLE_2) == 300);
//   CHECK(getImageWidth(EXAMPLE_3) == 400);
// }

// TEST_CASE("Testing getImageHeight")
// {
//   cout << "4: getImageHeight" << endl;
//   CHECK(getImageHeight(EXAMPLE_1) == 200);
//   CHECK(getImageHeight(EXAMPLE_2) == 400);
//   CHECK(getImageHeight(EXAMPLE_3) == 250);
// }

// TEST_CASE("Testing getVerticalPadding")
// {
//   cout << "5: getVerticalPadding" << endl;
//   CHECK(getVerticalPadding(EXAMPLE_1) == 0);
//   CHECK(getVerticalPadding(EXAMPLE_2) == 10);
//   CHECK(getVerticalPadding(EXAMPLE_3) == 10);
// }

// TEST_CASE("Testing getHorizontalPadding")
// {
//   cout << "6: getHorizontalPadding" << endl;
//   CHECK(getHorizontalPadding(EXAMPLE_1) == 0);
//   CHECK(getHorizontalPadding(EXAMPLE_2) == 10);
//   CHECK(getHorizontalPadding(EXAMPLE_3) == 5);
// }
