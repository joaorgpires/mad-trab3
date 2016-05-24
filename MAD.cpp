#include <bits/stdc++.h>
using namespace std;
#define COOP 0
#define CHEAT 1

int choice, turns=0, points=0, enemy=0;
double probC=0, probT=0;
bool over=false;

int main(){
	cout << "Choose the strategy you want to test:" << endl;
	cout << "1- Cooperar sempre" << endl;
	cout << "2- Trair sempre" << endl;
	cout << "3- Random 50-50" << endl;
	cout << "4- Começar por cooperar e depois jogar sempre o que o outro jogou" << endl;
	cin >> choice;
	start();

return 0;
}
// CC - 3,3
// CT - 0,5
// TC - 5,0
// TT - 1,1
void start(){
	while(over==false){
		if(rand<min)
			over=true;
		else{
			if(choice==1){

			}
		}
	}
}

bool endGame() {
  int k = rand() % 100000;
  if(k < 346)
    return true;
  return false;
}