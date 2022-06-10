#include <iostream>

#include <random>

#include <fstream>

 

using namespace std;

 

//Variables

 

string t3Table[9] = {"_","_","_","_","_","_","_","_","_"}; //Tic Tac Toe Table

 

bool winState = false; // Declare win state.

 

int playerChoice; //Declare user input.

 

int computerChoice; //Declare computer choice.

 

string xoro = "X";

 

bool retry;

 

bool draw = false;

 

int drawThreshold = 0;

 

int firstMove;

 

bool firstMoveTF;

 

int t3Results[9];

 

 

// Display Function: Displays T3 Table

 

void display() {

 

                cout << t3Table[0] << " | " << t3Table[1] << " | " << t3Table[2] << "\n";

                cout << "_________\n";

                cout << t3Table[3] << " | " << t3Table[4] << " | " << t3Table[5] << "\n";

                cout << "_________\n";

                cout << t3Table[6] << " | " << t3Table[7] << " | " << t3Table[8] << "\n";

}

 

void validate();

void winCheck();

void saveFirstMove();

void drawCheck();

 

// Chooses a random number 0 - 8

void choice() {

                std::random_device rd;

                std::mt19937 gen (rd());

                uniform_int_distribution<> distr(0,8);

                computerChoice = distr(gen);
                
                cout << "\n" << "Choice: "<< computerChoice << xoro <<" ? "<<"\n";

                validate();

}

 

// Switches from X to O or, O to X

void xoroSwitch() {

                if(xoro == "X"){
                xoro = "O";
                }
                
                else if(xoro == "O"){
                xoro = "X";
                }                             

}

 

// Sets the validated move as X or O then preps for the next move by calling xoroSwitch

void set() {
                saveFirstMove();
                cout << "Set:  "<< computerChoice << xoro <<" ! "<<"\n";
                t3Table[computerChoice] = xoro;
                drawCheck();
                winCheck();
                xoroSwitch();
                

}

 

 

// Validates the computers choice

void validate() {
                cout << "Chosen Position Status: " << t3Table[computerChoice] <<"\n";
                if(t3Table[computerChoice] != "O"){

                if(t3Table[computerChoice] != "X"){
                

                set();

                }else{
                cout << "#########Retry############";
                choice();

                }

                }

}

 

// Checks to see if any wins have happened, out of 8 possibilities

void winCheck() {

// 012,036,048

                if(t3Table[0] == xoro){

                                if((t3Table[1] == xoro) && (t3Table[1] == t3Table[2])){

                                winState = true;
                                cout << "012" << "\n";

                                }

                                if((t3Table[3] == xoro) && (t3Table[3] == t3Table[6])){

                                winState = true;
                                cout << "036" << "\n";
                                }

                                if((t3Table[4] == xoro) && (t3Table[4] == t3Table[8])){

                                winState = true;
                                cout << "048" << "\n";
                                }

                }

 

//147

                if((t3Table[1] == xoro) && (t3Table[4] == t3Table[7]) && (t3Table[4] == t3Table[1])){

                winState = true;
                cout << "147" << "\n";
                }


//528,543
                if(t3Table[5] == xoro){

                                if((t3Table[2] == xoro) && (t3Table[2] == t3Table[8])){

                                winState = true;
                                cout << "528" << "\n";
                                }

                                if((t3Table[4] == xoro) && (t3Table[4] == t3Table[3])){

                                winState = true;
                                cout << "543" << "\n";
                                }

                }

//642,678

                if(t3Table[6] == xoro){

                                if((t3Table[4] == xoro) && (t3Table[4] == t3Table[2])){

                                winState = true;
                                cout << "642" << "\n";
                                }

                                if((t3Table[7] == xoro) && (t3Table[7] == t3Table[8])){

                                winState = true;
                                cout << "678" << "\n";
                                }

 

                }             

 

}

// Checks to see if a draw has occured. Adds +1 to drawThreshold for ever X or O. Sets draw to true once 9 has been reached.

void drawCheck() {

                for (int i=0; i < 8; i++){

                                if((t3Table[i] == "X") || (t3Table[i] == "0")){

                                                if(drawThreshold == 8){

                                                                draw = true;
                                                                break;                  

                }             

                                                drawThreshold = drawThreshold + 1;

                }

                }             

}

 

//"Resets" the t3Table array by setting all array elements to E(mpty)

void resetT3(){

                for(int i=0; i < 9; i++){

                                t3Table[i] = "_";

                }

}

 

void record(){

                ofstream results("results");        

                results << firstMove;

                results.close();

}

 

void saveFirstMove(){
                if(firstMoveTF == false){
                                firstMove = computerChoice;

                                firstMoveTF = true;

                }

}

 

int main() {
                int winAmount;
                cout << "Type a number of games to record: "; // Type a number and press enter
                cin >> winAmount; // Get user input from the keyboard
                //cout << "Your number is: " << winAmount << "\n"; // Display the input value
                
                while(winAmount > 0){
                if (winState == false){
                choice();
                display();
                }
                if (winState == true){
                cout << "WIN!" << "\n";
                //display();
                resetT3();
                firstMoveTF = false;
                winAmount = winAmount - 1;
                winState = false;
                }
                
                //display();              
                
                
                record();
                }
return 0;

}
