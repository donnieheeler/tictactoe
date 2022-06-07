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
