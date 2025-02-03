/*
Author: Grant Hughes
Created: January 31, 2025

Main.cpp:
    - Process command line arguments, set up file to process regardless of source, check if file is readable, set the basename for the output file, etc.
    - Build the tree
    - Traverse the tree using three different ways
*/
#include <iostream>
#include <cstdlib> // exit()
#include <fstream> // file handling
#include <string>
#include <sstream> // istringstream
#include <ctype.h> // isalnum

using namespace std;

// checking if file is empty
// https://solvepro.co/check-if-a-file-is-empty-in-c/
bool isFileEmpty(const std::string& filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}

// checking if character in string is valid
//! “ # $ % & ‘ ( ) * + // these characters correspond to ascii numbers 33 to 43
bool stringCharacterCheck(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (isalnum(c))
            continue;
        if (c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&' 
            || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+')
            continue;
        if (isspace(c))
            continue;
        
        return false; //invalid
    }
    return true; // valid
}

int main(int argc, char* argv[])
{
    // checking if there is more than 1 filename present
    // And printing erro message if so (must be only 1 file)
    if (argc >= 3)
    {
        cout << "Fatal: Imroper Usuage" << endl;
        cout << "Usuage: P0 [filename]" << endl;
        
        // Terminate program if this is encountered
        exit(1);
    }
    // if 1 file then ooen and read contents
    // And build tree (if possible)
    if (argc == 2)
    {
        // variables
        string file = argv[1];
        string line;
        string word;

        // checking if there is contentents in file
        if (isFileEmpty(file))
        {
            cout << "Error: Missing data" << endl;
            return 1;
        }

        // checking file is readable
        // Check that input data are all character strings with letters, numbers,
        // And/or any of the following special characters:
        //Assume the strings are separated with any number of standard
        //white-space separators (space, tab, newline).
        ifstream myFile(file);

        if (myFile.is_open())
        {
            while (getline(myFile, line))
            {
                // accessing each string that is seperated by white-space separators
                istringstream strDiv(line);

                while (strDiv >> word)
                {
                    if (stringCharacterCheck(word))
                    {
                        cout << word << endl;
                    }
                    else 
                    {
                        cout << "Error: Invalid character or word" << word << endl;
                        exit(1);
                    }
                }
            }
            myFile.close();
        }
        else
        {
            cout << file << " couldn't open" << endl;
            exit(1);
        }
    }
    if (argc == 1)
    {
        // variables for user input
        string inputLine;
        string word;
        ofstream writeFile("output.txt", ios::app);

        if (!writeFile.is_open())
        {
            cout << "Error: Could not open file for writing" << endl;
            exit(1);
        }

        while (getline(cin, inputLine))
        {
            if (inputLine.empty())
                continue;
            
            istringstream strDiv(inputLine);
            
            while (strDiv >> word)
            {
                if (!stringCharacterCheck(word))
                {
                    cout << "Error: Invalid character or word " << endl;
                    exit(1);
                }
                else 
                {
                    writeFile << word << endl;
                    // then send to binary tree class
                }
            }
        }
        writeFile.close();
        
        // erasing contents of file so the next tree dosn't have it
        ofstream fileToClear("output.txt", ios::out | ios::trunc);
        fileToClear.close();
    }
    return 0;
}