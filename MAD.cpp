#include <bits/stdc++.h>
using namespace std;
#define COOP 0
#define CHEAT 1

int choice, turn=0, points=0, enemy=0, combo1=0, combo2=0, combo3=0, combo4=0;

int main(){
	cout << "Choose the strategy you want to test:" << endl;
	cout << "1- Cooperar sempre" << endl;
	cout << "2- Trair sempre" << endl;
	cout << "3- Random 50-50" << endl;
	cout << "4- Começar por cooperar e depois jogar sempre o que o outro jogou" << endl;
	cin >> choice;
	if(choice!=1 || choice!=2 || choice!=3 || choice!=4)
		cout << "Input errado." << endl;
	else
		start();

return 0;
}
// CC - 3,3
// CT - 0,5
// TC - 5,0
// TT - 1,1
void start(){
	string strategy;
	int player1, player2;
	bool over = false;
	while(!over){
		over=endGame();
		turn++;
		if(choice == 1){
			player1=strategy();
			player2=cooperar();
			sums(player1, player2);
		}
		else if(choice == 2){
			player1=strategy();
			player2=trair();
			sums(player1, player2);
		}
	}
	if(over){
		if(choice==1)
			strategy = "cooperar sempre";
		else if(choice==2)
			strategy = "trair sempre";
		else if(choice==3)
			strategy = "random";
		else
			strategy = "começar por cooperar e depois jogar sempre o que o outro jogou";
		cout << "Pontos da nova estratégia: " << points << endl;
		cout << "Pontos da estratégia " << strategy << ": " << enemy << endl;
	}
}

int strategy(){
	int c;
	if(turn <= 7)
		c=COOP;
	else if(turn > 7 && turn <= 10)
		c=CHEAT;
	else{
		if(combo1>combo3 && combo2>combo4)
			c=COOP;
		else if(combo3>combo1 && combo3>combo4)
			c=CHEAT;
		else
			c=CHEAT;
	}
	return c;
}

void sums(int player1, int player2){
	if(player1==COOP && player2==COOP){
		points+=3;
		enemy+=3;
		combo1+=3;
	}
	else if(player1==COOP && player2==CHEAT){
		enemy+=5;
		combo2=0;
	}
	else if(player1==CHEAT && player2==COOP){
		points+=5;
		combo3+=5;
	}
	else if(player1==CHEAT && player2==CHEAT){
		points+=1;
		enemy+=1;
		combo4+=1;
	}
}

int cooperar(){
	playC++;
	probC=playC/turns;
	return COOP;
}

int trair(){
	probT++;
	probT=playT/turns;
	return CHEAT;
}

bool endGame() {
  int k = rand() % 100000;
  if(k < 346)
    return true;
  return false;
}