#include <iostream>
#include <unistd.h>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

#include "player.h"

using namespace std;

void prepPhase(player &user);
void battlePhase(player &user);
void gameEnd();
void randomCase(int &randomNum);
int main() {
  player user(12, 4, 9);

  cout << "You are getting ready for battle with an unknown enemy, choose how to prep:\n";

  for (int i = 0; i < 2; i++) {
    user.displayStats();
    prepPhase(user);
    user.displayStats();
    cout << "====================\n";
  }

  battlePhase(user);

  return 0;
}

void battlePhase(player &user) {
  bool winCase = false; 
  int randomNum;
  int playerChoice; 

  player enemy(16, 12, 9);

  while (winCase == false) {
    user.displayStats();
    cout << "\nENEMY STATS:\nHEALTH: ";
    enemy.getHealth();

    cout << "\n\nYou approached an enemy! Choose your action:\n1.) ATTACK\n2.) DEFEND\n3.) HEAL\n\n";
    cin >> playerChoice;
    if (playerChoice == 1) {
      cout << "\nYou choose to attack!\n";
      for (int i = 0; i < 3; i++) {
        sleep(1);
        cout << i << "...";
      }
      randomCase(randomNum);
      if (randomNum == 0) {
        cout << "\nIt hit!\n";
        enemy.decreaseHealth(user.getMaxHitPts());
        enemy.getHealth();
      } else {
        cout << "\nIt missed!\n";
      }
    } 
  }
}

void prepPhase(player &user) {
  int choice; 

  cout << "\n\nChoose which attributes to add to before battle (you get two attributes to choose from +3)\n";


  cin >> choice;

    if (choice == 1) {
      user.addHealth(3);
    } else if (choice == 2) {
      user.addDurabilityPts(3);
    } else if (choice == 3) {
      user.addMaxHitPts(3);
    } else {
      cout << "Input Invalid, please try again:\n";
    }
}

void gameEnd() {

}

void randomCase(int &randomNum) {
    //const int randomRange = 2;

    std::vector<int> randomNumber = {0, 1};  // Vector initialized with values 0 and 1

    // Seed the random number generator with the current time
    unsigned seed = static_cast<unsigned>(time(0));
    std::mt19937 rng(seed); // Mersenne Twister random number generator

    // Shuffle the vector
    std::shuffle(randomNumber.begin(), randomNumber.end(), rng);

    // Output the shuffled result
    /*for (int num : randomNumber) {
        std::cout << num << " ";
    }*/
    randomNum = randomNumber[0];
    std::cout << std::endl;
}