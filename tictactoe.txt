#include <iostream>
#include <random>

using namespace std;

int main() {
	string tick[9] = {"1","2","3","4","5","6","7","8","9"}; //ttt array
	int x; //declare user input pocket
	bool win = false;
	int y;
	while(win == false){

cout << string(100, '\n');
cout << tick[0] << " | " << tick[1] << " | " << tick[2] << "\n";
cout << "_________\n";
cout << tick[3] << " | " << tick[4] << " | " << tick[5] << "\n";
cout << "_________\n";
cout << tick[6] << " | " << tick[7] << " | " << tick[8] << "\n";

	cout << "choose 1-9:";
	cin >> x; //user input
	x = x - 1;
		if(tick[x] != "O"){
		if(tick[x] != "X"){
		tick[x] = "X";
		}else{
		cout << "not valid \n";
			}
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
			
			bool retry;
			do{
			    retry = false;
				std::random_device rd;
				std::mt19937 gen(rd());
				uniform_int_distribution<> distr(1,9);
				int y = distr(gen);
				//cout << y;
				y=y-1;
				
					if(tick[y] != "O"){
					if(tick[y] != "X"){
					tick[y] = "O";
					retry = true;
					}}else{
                    //nothing
					}
			}
					while(retry == false);
					y=y-1;
					
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
			}
		cout << string(100, '\n');
		}
	cout << string(100, '\n');
	cout << "Game Over\n";
	cout << tick[0] << " | " << tick[1] << " | " << tick[2] << "\n";
	cout << "_________\n";
	cout << tick[3] << " | " << tick[4] << " | " << tick[5] << "\n";
	cout << "_________\n";
	cout << tick[6] << " | " << tick[7] << " | " << tick[8] << "\n";

	/*for (int i = 0; i < 4; i++) 
	{
  	cout << tick[i] << "\n";
	}*/

  return 0;
}
