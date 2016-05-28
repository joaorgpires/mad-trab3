#include <bits/stdc++.h>

using namespace std;

#define COOP 0
#define CHEAT 1

int genTit4Tat(int antP2);
int conTit4Tat(int ant2P1, int ant1P2);
int pavlov(int antP1, int antP2);

int main() {
  srand(time(NULL));
  return 0;
}

int genTit4Tat(int antP2) {
  //P2 -> jogador adversario
  int prob = rand() % 100;
  
  if(antP2 == CHEAT)
    if(prob < 5)
      return COOP;
  
  return antP2;
}

int conTit4Tat(int ant2P1, int ant1P2) {
  //ant2P1 -> Duas jogadas anteriores a actual
  if(ant2P1 == CHEAT && ant1P2 == CHEAT)
    return COOP;
  
  return ant1P2;
}

int pavlov(int antP1, int antP2) {
  //P1 -> jogador utilizando a estrategia Pavlov
  if(antP1 == COOP && antP2 == COOP)
    return COOP;
  if(antP1 == CHEAT && antP2 == CHEAT)
    return COOP;
  if(antP1 == CHEAT && antP2 == COOP)
    return CHEAT;
  return COOP;
}
