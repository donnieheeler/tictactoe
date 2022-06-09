#include <iostream>
#include <random>

using namespace std;

//Variables

string t3Table[9] = {"1","2","3","4","5","6","7","8","9"}; //Tic Tac Toe Table

bool winState = false; // Declare win state.

int playerChoice; //Declare user input.

int computerChoice; //Declare computer choice.

string xoro = "X";

bool retry;

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

// Chooses a random number 0 - 8
void choice() {
	std::random_device rd;
	std::mt19937 gen (rd());
	uniform_int_distribution<> distr(0,8);
	int computerChoice = distr(gen);
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


int main() {
	//choice();	
return 0;
}
