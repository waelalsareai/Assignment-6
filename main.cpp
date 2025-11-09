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

// Extract height="200px" -> rerturns 200
int getImageHeight(string tag) {
  string value = getAttributeValue(tag, "height");
  int num = stoi(value.substr(0, value. size () - 2));
return num;
}

// Get vertical padding (first number in padding="10px 5px")
int getVerticalPadding(string tag) {
  string value = getAttributeValue(tag, "padding");
  if (value == "") return 0; // no padding attribute
  
  size_t space = value.find(" ");
string first = (space == string::npos) ? value : value.substr(0, space);
return stoi(first.substr(0, first.size() - 2));
}

// Get horizontal padding (second number in padding="10px 5px")
int getHorizontalPadding(string tag) {
    string value = getAttributeValue(tag, "padding");
    if (value == "") return 0;  // no padding attribute

    size_t space = value.find(' ');
    if (space == string::npos) {
        // only one value -> applies to both directions
        return stoi(value.substr(0, value.size() - 2));
    } else {
      // take second token, remove "px"
        string second = value.substr(space + 1);
        return stoi(second.substr(0, second.size() - 2));
    }
}

int main()
{
    cout << "Enter a tag: ";
    string tag;
    getline(cin, tag);  // read a full line of input including spaces
    string filename = getImageSource(tag);
string filenamePretty = underscoresToSpaces(filename);

    // Some sample inputs you can copy-paste to test your main
    // <image source="puppy.jpg" width="100px" height="200px">
    // <image source="cat_pounce.gif" height="400px" width="300px" padding="10px">
    // <image width="400px" height="250px" padding="10px 5px" source="little_red_snake.mpeg">

    cout << "Tag:" << tag << endl;
    // Add your code here to print out information about the tag

}
