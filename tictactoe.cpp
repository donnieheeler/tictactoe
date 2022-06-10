#include <iostream>

#include <random>

#include <fstream>

 

using namespace std;

 

//Variables

 

string t3Table[9] = {"E","E","E","E","E","E","E","E","E"}; //Tic Tac Toe Table

 

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

 

// Chooses a random number 0 - 8

void choice() {

                std::random_device rd;

                std::mt19937 gen (rd());

                uniform_int_distribution<> distr(0,8);

                computerChoice = distr(gen);
                
                cout << "\n" << " ( "<< (computerChoice + 1) << xoro <<" ) "<<"\n\n";

                validate();

}

 

// Switches from X to O or, O to X

void xoroSwitch() {

                if(xoro == "X"){

                xoro = "O";

                }else{

                xoro = "X";

                }                             

}

 

// Sets the validated move as X or O then preps for the next move by calling xoroSwitch

void set() {
                saveFirstMove();
                t3Table[computerChoice] = xoro;
                xoroSwitch();

               
                winCheck();

                

}

 

 

// Validates the computers choice

void validate() {
                if(t3Table[computerChoice] != "O"){

                if(t3Table[computerChoice] != "X"){
                

                set();

                }else{

                choice();

                }

                }

}

 

// Checks to see if any wins have happened, out of 8 possibilities

void winCheck() {

// 012,036,048

                if(t3Table[0] == xoro){

                                if((t3Table[1, 2]) == xoro){

                                winState = true;

                                }

                                if((t3Table[3, 6]) == xoro){

                                winState = true;

                                }

                                if((t3Table[4, 8]) == xoro){

                                winState = true;

                                }

                }

 

//147

                if(t3Table[1,4,7] == xoro){

                winState = true;

                }

//258

                if(t3Table[2,5,8] == xoro){

                winState = true;

                }

//345

                if(t3Table[3,4,5] == xoro){

                winState = true;

                }

 

//642,678

                if(t3Table[6] == xoro){

                                if((t3Table[4, 2]) == xoro){

                                winState = true;

                                }

                                if((t3Table[7, 8]) == xoro){

                                winState = true;

                                }

 

                }             

 

}

// Checks to see if a draw has occured. Adds +1 to drawThreshold for ever X or O. Sets draw to true once 9 has been reached.

void drawCheck() {

                for (int i=0; i < 9; i++){

                                if((t3Table[i] == "X") || (t3Table[i] == "0")){

                                                if(drawThreshold == 9){

                                                                draw = true;

                                                                break;                  

                }             

                                                drawThreshold == drawThreshold + 1;

                }

                }             

}

 

//"Resets" the t3Table array by setting all array elements to E(mpty)

void resetT3(){

                for(int i=0; i < 9; i++){

                                t3Table[i] = "E";

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
                cout << "Your number is: " << winAmount << "\n"; // Display the input value
                
                while(winAmount > 0){
                if (winState == false){
                choice();
                display();
                }
                if (winState == true){
                cout << "WIN!" << "\n"; 
                resetT3();
                firstMoveTF = false;
                winAmount = winAmount - 1;
                }
                
                //display();              
                
                
                record();
                }
return 0;

}
