//In C++ just to spite you, you know who you are.
//I havent used C++ in so long im basically relearning it, so this is going to be awful code.

////////VERSION//1.0////////
// COMPILER FOR  THE BEST //
// LANGAUGE EVER CONCIVED //
//                        //
// STARTED  ON   11.23.21 //
////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

#include "lefunctions.h"

//Macros
//ngl im not entirely sure how versions of LANGUAGES work so im hoping this is right lmao
#define CVERSION "1.0.0" //Compiler version
#define LVERSION "1.0.0" //Langauge version



using namespace std;

int main(int argc, char *argv[]){
    //Error out if no file provided
    if(argc == 1){
        cout << "Provide an input file, idiot." << endl;
        getchar();
        return 0;
    }


    //enum of the primary and secondary cring3 variables, for ease of use
    enum CVar {
        pcvar,
        scvar
    };
    //array of vars for effiencey ig
    char cvars[2] = { 'p', 's' };


    string file = argv[argc-1];
    if(file == "-v"){
        cout << "You are suffering with Cringepiler version "<< CVERSION << endl;
        cout << "You are suffering with Cring3 version      " << LVERSION << endl;
        return 0;
    }
    //ENFORCE the .pog extension
    if(file.find(".pog", file.size()-4) == std::string::npos){
        cout << "Use a valid Cring3 file (.pog) n00b" << endl;
        getchar();
        return 0;
    }

    //array of operators
    string oprs[6] = {"==", "!=", ">", "<", ">=", "<="};

    bool activeVar = pcvar;

    string cringcode = readFile(argv[argc-1]);
    //Removes spaces
    cringcode.erase(remove(cringcode.begin(), cringcode.end(), ' '), cringcode.end());

    vector<string> ops;
    //Make second string to be chopped
    string str = cringcode;
    //Go thru once for every
    for(int i = 0; i < occurances(cringcode,';'); i++){
        //add instrution to end of vector (list) of opst
        ops.emplace_back(str.substr(0,str.find(';')));
        //cout << str << endl;
        //cuts down str so its easier to get next op
        str = str.substr(str.find(';')+1);
    }

    //Delete out.c if exists
    if( remove( "out.c" ) != 0 ){
        cout << "Out file not found, creating." << endl;
    }
    else {
        cout << "Out file deleted, creating." << endl;
    }


    ofstream outfile;
    //Open file to append
    outfile.open("out.c", ios_base::app);

    //Setup file for transcription
    outfile << "\
    #include <stdio.h>\n\
    int main(){\n\
    int p = 0;\n\
    int s = 0;\n\
    int a = 0;\n\
    " << endl;


    //Translate instructions into C, write them into file
    for(int i = 0; i < ops.size(); i++){
        //no switch statements with strings in C++ so im yandevin' it

        //Need to do this cringe for comments >:(
        string opButString = ops[i];
        //Handle comments
        if(opButString.at(0) == '#'){
            //uhhhh do nothing its a comment
        }
        //Hello World
        else if(ops[i] == "Hlw"){
            outfile << "printf(\"Sup Nerd\\n\");" << endl;
            cout    << "printf(\"Sup Nerd\\n\");" << endl;
        }
        //Print
        else if(ops[i] == "Dsp"){
            string toPrint = ops[i+1];
            //Check each character for quotes, to escape the user input bc security
            //
            //it hanging here if you use a " was not actually intentional, if anyone
            //can pls fix it so i can insult the user at runtime instead of just
            //in the manual
            for (int x = 0; x < toPrint.size(); x++){
                if (toPrint[x] == '"' && x > 0){
                    //If quotes and not first character, check if previous character is slash
                    if(toPrint[x-1] !='\\'){
                        //if it is a not a slash
                        toPrint.insert(x-1,'\\',1);
                        //move foward an extra char so it doesnt repeat the same one

                    }
                }
                else if (toPrint[x] == '"'){
                    //if character is quotes and first character,
                    //insert escape character
                    toPrint.insert(0,'\\',1);
                    //move foward an extra char so it doesnt repeat the same one

                }
            }
            //Once escaped
            outfile << "printf(\"" << toPrint << "\");" << endl;
            cout    << "printf(\"" << toPrint << "\");" << endl;
            //Skip next instruction as it is an argument
            i++;
        }
        //Pause for input
        else if(ops[i] == "Stp"){
            outfile << "getchar();" << endl;
            cout    << "getchar();" << endl;
        }
        //Set Variable
        else if(ops[i] == "Set"){
            //Use try to make sure argument (next instruction) is an integer, only proceed if so
            //other error out.
            try{
                //just to check if int
                int bruh = stoi(ops[i+1]);
                //Set variable to next instruction
                outfile << cvars[activeVar] <<" = " << ops[i+1] << ";" << endl;
                cout    << cvars[activeVar] <<" = " << ops[i+1] << ";" << endl;
                //Skip next op, since its a number not an instruction
                i ++;
            }
            catch (std::invalid_argument const &e){
                cout << "Syntax Error on instruction " << i+2 << ", \"" << ops[i+1] << "\" should be an int," << " gitgud" << endl;
                return 0;
            }
            catch (std::out_of_range const &e){
                cout << "Syntax Error on instruction " << i+2 << ", " << ops[i+1] << " is too BIG," << " gitgud" << endl;
                return 0;
            }
        }
        //Set unactive variable to active variable
        else if(ops[i] == "Equ"){
            outfile << cvars[!activeVar] << " = " << cvars[activeVar] << ";" << endl;
            cout    << cvars[!activeVar] << " = " << cvars[activeVar] << ";" << endl;
        }
        //For loop
        else if(ops[i] == "For"){
            //Use try to make sure argument (next instruction) is an integer, only proceed if so
            //other error out.
            try{
                //just to check if int
                int bruh = stoi(ops[i+1]);
                //Start for look for number of next instruction
                outfile << "for(int i = 0; i < " << ops[i+1] << "; i++){" << endl;
                cout    << "for(int i = 0; i < " << ops[i+1] << "; i++){" << endl;
                //Skip next op, since its a number not an instruction
                i ++;
            }
            catch (std::invalid_argument const &e){
                cout << "Syntax Error on instruction " << i+2 << ", \"" << ops[i+1] << "\" should be an int," << " gitgud" << endl;
                return 0;
            }
            catch (std::out_of_range const &e){
                cout << "Syntax Error on instruction " << i+2 << ", " << ops[i+1] << " is too BIG," << " gitgud" << endl;
                return 0;
            }
        }
        //Add Ending Curly
        else if(ops[i] == "Brk"){
            outfile << "}" << endl;
            cout    << "}" << endl;
        }
        //Swap Active Variable
        else if(ops[i] == "Swp"){
            //toggle the bool to toggle the variable used
            activeVar = !activeVar;
        }
        //Print active variable
        else if(ops[i] == "Prt"){
            //Use array to determine if printing primary or secondary without if statement
            outfile << "printf(\"%d\"," << cvars[activeVar] << ");" << endl;
            outfile << "printf(\"\\n\");" << endl;
            cout    << "printf(\"%d\"," << cvars[activeVar] << ");" << endl;
            cout    << "printf(\"\\n\");" << endl;
        }
        //Print accumulator
        else if(ops[i] == "Pra"){
            outfile << "printf(\"%d\", a);" << endl;
            outfile << "printf(\"\\n\");" << endl;
            cout    << "printf(\"%d\", a);" << endl;
            cout    << "printf(\"\\n\");" << endl;
        }
        //Store active variable to accumulator
        else if(ops[i] == "Sta"){
            outfile << "a = " << cvars[activeVar] << ";" << endl;
            cout    << "a = " << cvars[activeVar] << ";" << endl;
        }
        //Load accumulator into active variable
        else if(ops[i] == "Lda"){
            outfile << cvars[activeVar] << " = " << "a;" << endl;
            cout    << cvars[activeVar] << " = " << "a;" << endl;
        }
        //Clears accumulator (sets to 0)
        else if(ops[i] == "Cla"){
            outfile << "a = 0;" << endl;
            cout    << "a = 0;" << endl;
        }
        //Add active variable to acccumulator
        else if(ops[i] == "Add"){
            outfile << "a += " << cvars[activeVar] << ";" << endl;
            cout    << "a += " << cvars[activeVar] << ";" << endl;
        }
        //Subtract active variable from acccumulator
        else if(ops[i] == "Sub"){
            outfile << "a -= " << cvars[activeVar] << ";" << endl;
            cout    << "a -= " << cvars[activeVar] << ";" << endl;
        }
        //Subtract active variable from acccumulator
        else if(ops[i] == "Div"){
            outfile << "a = a/" << cvars[activeVar] << ";" << endl;
            cout    << "a = a/" << cvars[activeVar] << ";" << endl;
        }
        else if(ops[i] == "Mlt"){
            outfile << "a *= " << cvars[activeVar] << ";" << endl;
            cout    << "a *= " << cvars[activeVar] << ";" << endl;
        }
        //Checks active variable against accumulator based on operator
        else if(ops[i] == "Chk"){
            //Make sure operator is valid
            //If operator is not valid
            if(idOperator(ops[i+1]) == 6) {
                cout << "Invalid Operator on instruction " << i+2 << ", " << ops[i+1] << "," << " gitgud" << endl;
            } //If it is a valid operator
            else {
                outfile << "if(" << cvars[activeVar] << oprs[idOperator(ops[i+1])] << "a){" << endl;
                cout    << "if(" << cvars[activeVar] << oprs[idOperator(ops[i+1])] << "a){" << endl;
            }
            //Skip next op, since not an instruction
            i++;
        }
        //Else
        else if(ops[i] == "Els"){
            outfile << "else{" << endl;
            cout    << "else{" << endl;
        }
        //Gets user input
        else if(ops[i] == "Inp"){
            outfile << "scanf(\"%d\", &" << cvars[activeVar] << ");" << endl;
            cout    << "scanf(\"%d\", &" << cvars[activeVar] << ");" << endl;
        }
        //Exits the program by returning 0
        else if(ops[i] == "Ext"){
            outfile << "return 0;" << endl;
            cout    << "return 0;" << endl;
        }
        //Handle syntax error
        else {
            cout << "Syntax Error on instruction " << i+1 << ", " << ops[i] << "," << " gitgud" << endl;
            return 0;
        }
    }
    outfile << "\
    return 0;\n\
    }";
    return 0;
}


