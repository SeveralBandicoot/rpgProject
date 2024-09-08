#include <iostream>

#include "player.h"

using namespace std;

void prepPhase(player &user);
int main() {
  player user(12, 4, 9);

  cout << "You are getting ready for battle with an unknown enemy, choose how to prep:\n";

  user.displayStats();
  prepPhase(user);

  return 0;
}

void battlePhase() {

}

void prepPhase(player &user) {
  int choice; 

  cin >> choice;

  cout << "\n\nChoose which attributes to add to before battle (you get two attributes to choose from +3)\n"


  (choice == 1) ? void(user.addHealth(3)) :
    (choice == 2) ? void(user.addDurabilityPts(3)) :
      (choice == 3) ? void(user.addHitPts(3)) :
        void(cout << " ");
}