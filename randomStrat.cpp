#include <bits/stdc++.h>
#define COOP 0
#define CHEAT 1

using namespace std;

int randomStrat() {
  int k = rand() % 2;
  if(k)
    return CHEAT;
  else
    return COOP;
}

bool endGame() {
  int k = rand() % 100000;
  if(k < 346)
    return true;
  return false;
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

int main() {
  return 0;
}
