#include <bits/stdc++.h>

using namespace std;

#define COOP 0
#define CHEAT 1

void start();
int strat();
void sums(int player1, int player2);
int cooperar();
int trair();
bool endGame();
int randomStrat();
int tit4tat(int last);

int choice, turn=0, points=0, enemy=0, combo1=0, combo2=0, combo3=0, combo4=0;

int main(){
  srand(time(NULL));
  cout << "Choose the strategy you want to test:" << endl;
  cout << "1- Cooperar sempre" << endl;
  cout << "2- Trair sempre" << endl;
  cout << "3- Random 50-50" << endl;
  cout << "4- Tit-for-tat" << endl;
  cin >> choice;
  if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
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
  int player1 = COOP, player2;
  bool over = false;
  while(!over){
    over=endGame();
    turn++;
    //cout << "Turn: " << turn << endl;
    if(choice == 1){
      player1=strat();
      player2=cooperar();
      sums(player1, player2);
    }
    else if(choice == 2){
      player1=strat();
      player2=trair();
      sums(player1, player2);
    }
    else if(choice == 3) {
      player1 = strat();
      player2 = randomStrat();
      sums(player1, player2);
    }
    else {
      player2 = tit4tat(player1);
      player1 = strat();
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
      strategy = "tit-for-tat";
    cout << "Pontos da nova estratégia: " << points << endl;
    cout << "Pontos da estratégia " << strategy << ": " << enemy << endl;
  }
}

int strat(){
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
  return COOP;
}

int trair(){
  return CHEAT;
}

bool endGame() {
  int k = rand() % 100000;
  //cout << "Random value: " << k << endl;
  if(k < 346)
    return true;
  return false;
}

int randomStrat() {
  int k = rand() % 2;
  if(k)
    return CHEAT;
  else
    return COOP;
}

int tit4tat(int last) {
  if(!turn)
    return COOP;
  else {
    if(last == COOP)
      return COOP;
    else return CHEAT;
  }
}
