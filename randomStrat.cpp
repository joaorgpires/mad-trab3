#include <bits/stdc++.h>
#define COOP 0
#define CHEAT 1

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

int main() {
  return 0;
}
