#include <iostream>
#include <random>

using namespace std;

// Definitions

string t3Table[9] = {"1","2","3","4","5","6","7","8","9"}; //Tic Tac Toe Table

bool winState = false; // Declare win state.

int playerChoice; //Declare user input.

int computerChoice; //Declare computer choice.

bool retry;

// Display Function: Displays T3 Table

void display() {

	cout << t3Table[0] << " | " << t3Table[1] << " | " << t3Table[2] << "\n";
	cout << "_________\n";
	cout << t3Table[3] << " | " << t3Table[4] << " | " << t3Table[5] << "\n";
	cout << "_________\n";
	cout << t3Table[6] << " | " << t3Table[7] << " | " << t3Table[8] << "\n";
}

void choice() {

	cout << "Choose 1 - 9, or press 0" << "\n";

	cin >> playerChoice;

	if(playerChoice == 0){
		do{
			retry = false;
			std::random_device rd;
			std::mt19937 gen (rd());
			uniform_int_distribution<> distr(1,9);
			int computerChoice = distr(gen);
			computerChoice = computerChoice - 1;

			if(t3Table[computerChoice] != "O"){
			if(t3Table[computerChoice] != "X"){
			t3Table[computerChoice] = "O";
			retry = true;
			    }
			    }
	        }
			while(retry == false);
	       computerChoice = computerChoice - 1;
    }else{
			playerChoice = playerChoice - 1; //Preps user input to work with  t3Table
			
			if(t3Table[playerChoice] != "O"){
			if(t3Table[playerChoice] != "X"){
			t3Table[playerChoice] = "X";
				}else{
				cout << "not valid \n";
				}
				
            }
    	}
}



/*
//Needs major overhaul. Feels like there is a better way to write this.
//Check to see if there is a win

void winCheck() {

if(tick[0]==tick[1] && tick[1]==tick[2]){
win = true;
tick[0] = tick[1] = tick [2] = "W";		
}

if(tick[3]==tick[4] && tick[4]==tick[5]){
win = true;
tick[3] = tick[4] = tick [5] = "W";				
}

if(tick[6]==tick[7] && tick[7]==tick[8]){
win = true;	
tick[6] = tick[7] = tick [8] = "W";			
}	

if(tick[0]==tick[3] && tick[3]==tick[6]){
win = true;		
tick[0] = tick[3] = tick [6] = "W";		
}

if(tick[1]==tick[4] && tick[4]==tick[7]){
win = true;	
tick[1] = tick[4] = tick [7] = "W";	
}

if(tick[2]==tick[5] && tick[5]==tick[8]){
win = true;
tick[2] = tick[5] = tick [8] = "W";			
}

if(tick[0]==tick[4] && tick[4]==tick[8]){
win = true;	
tick[0] = tick[4] = tick [8] = "W";		
}	

if(tick[6]==tick[4] && tick[4]==tick[2]){
win = true;	
tick[6] = tick[4] = tick [2] = "W";
		
}
*/

int main() {

display();

choice();

return 0;

}
