#include "lefunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void print(string printertext, bool endline = true){
    //screw you i wrote a sensible print function
    cout << printertext;
    if(endline){
        cout << "\n";
    }
}

//Very poggers file reading code by Thomas Mathews on StackOverflow
string readFile(string filePath){
    ifstream input_file(filePath);
    string str;
    string text_read;
    while (getline(input_file, text_read))
    {
        cout << "reading" << endl;
        const string::size_type position = text_read.find('\r');
        if (position != string::npos)
        {
            text_read.erase(position);
        }
        str += text_read;
    }
    return str;
}

int occurances(string s, char key) {
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == key) count++;

  return count;
}

int idOperator(string oper){
    //holy yandev this code is ICK...... so tell me if theres a better
    //way to do it bc no string switches means i dont see one.
    if(oper == "Equ"){
        return 0;
    }
    else if(oper == "Nqu"){
        return 1;
    }
    else if(oper == "Grt"){
        return 2;
    }
    else if(oper == "Lst"){
        return 3;
    }
    else if(oper == "Gre"){
        return 4;
    }
    else if(oper == "Lse"){
        return 5;
    }
    else {
        return 6;
    }
}
