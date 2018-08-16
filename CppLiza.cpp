/*
Jenny Bloom
10.25.2015
Homework 6
With help/brainstorming from: Collin Duncan, Darwin, and Jeff (in class)
Transforming string to lower case:
http://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case

DESCRIPTION:
This program loops through a file and responds based on specific user-inputted
keywords to find descriptions. The keywords act like a dictionary of terms and
definitions regarding C++.
*/

//include libraries
#include <iostream>
#include <string>
#include <fstream>
#include <locale> //where transform comes from.
using namespace std;

/*
SHODDY PSEUDOCODE AND OUTLINE:
1. Read in Command Line Arguments
  - get in the name of file
2. Read in data from files (response.txt)
3. Read in user input
  - user reads in keyword
  - look for keyword in the list of keyword/response pairs (array)
  - Determine response to give from this
4. Create and loop through a 2D array.
 -
PSEUDOCODE:
read in CLA .txt file
declare Main()
  declare var
  read in keyword from user in loop
  for each
  somefunction(that does this)*/

int main(int argc, char*argv[])
{
  string keyword;
  string line;
  int position;
  string foo[100][2]; //first [] = rows, second [] = columns: 2-D array
  //n = some bullshit the user puts into the array1.

  ifstream responseFile; //create variable to store file in
  responseFile.open(argv[1]); //use .open method to read .txt file into responseFile stream
  for (int i = 0; getline(responseFile, line); i++) //creating own counter, reading .txt into line variable
  {
     position = line.find('@'); /* split each line by @ delimiter */
     int post = position+1; /* declare second position to discard @, and read
     second part of line.*/
     string key = line.substr(0, position); /*substring takes portion of string,
     takes up to position, and places into it's own string.*/
     string value = line.substr(post); /*subtring takes portion of string to
     right of former @ symbol, and places it into it's own string.*/
     foo[i][0] = key; //populating first column with key
     foo[i][1] = value; // populating second column with value
  }
  responseFile.close();

  // Make user case unified.
  cout << "What question do you have about C++?\n";
  cin >> keyword;
  transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower); //convert all user input to lower case

  /* loopy-roo for keywords in 2D array, checking if keyword
  matches user input*/
  for (int x = 0; x < 100; x++) //coordinate of for loop within multidimensional array.
  {
    for (int y = 0; y < 2; y++)
    {
      transform(foo[x][0].begin(), foo[x][0].end(), foo[x][0].begin(), ::tolower);
      if (keyword == foo[x][0])
      {
      cout << foo[x][1] << "\n";
      return 0;
      }
      else if (keyword == "quit")
      return 0;
    }
  }
  cout << "Sorry, I don't know. What else can we talk about?\n";

  return 0;
}
