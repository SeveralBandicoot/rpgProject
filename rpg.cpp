/*
Lab 3 Class RPG

@ AJ Enrique Arguello

9/8/24

Objectives: 
- Create a Game that has at least 2 private Attributes that are displayed, changed and displayed again within main( ).

- Main( ) should also have several decisions to be made that adjust the Attributes
*/

#include <iostream>
#include <unistd.h>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

#include "player.h" // reference of .h file 

using namespace std;

void prepPhase(player &user);
void battlePhase(player &user);
void gameEnd(player &user, player &enemy);
void randomCase(int &randomNum);
int main() {
  player user(12, 4, 9); // default conditions for user

  cout << "You are getting ready for battle with an unknown enemy, choose how to prep:\n";

  for (int i = 0; i < 2; i++) { // loop so that user can choose attributes to add to
    user.displayStats();
    prepPhase(user);
    cout << "====================\n";
  }

  battlePhase(user);

  return 0;
}

void battlePhase(player &user) { // simulates a battle with an enemy
  bool winCase = false; // wincase set to false
  int randomNum; // random number integer to store random int
  int playerChoice; // player choice integer to store input from user

  player enemy(16, 12, 9); // default conditions for enemy 

  while (winCase == false) { // while the winCase bool value is set to false

    user.displayStats(); // displays stats of user
    cout << "\nENEMY STATS:\nHEALTH: ";
    cout << enemy.getHealth(); // displays enemy health

    cout << "\n\nYou approached an enemy! Choose your action:\n1.) ATTACK\n2.) DEFEND\n";
    cin >> playerChoice;
    if (playerChoice == 1) { // if the user input is 1, they will be sent to a randomCase function which determines if the user misses the attack or not
      cout << "\nYou choose to attack!\n";
      for (int i = 0; i < 3; i++) { // countdown
        sleep(1); // waits 1 second
        cout << i << "...";
      }
      randomCase(randomNum); // randomNum integer is sent by reference into the randomCase function
      if (randomNum == 0) { // if the randomNum is equal to 0, the attack hits the enemy
        cout << "\nThe attack hit the enemy!\n";
        enemy.decreaseHealth(user.getMaxHitPts()); // decreases the enemy health by the value of the users maxHitPts
        cout << "\nENEMY STATS:\nHEALTH: ";
        cout << enemy.getHealth(); // displays enemy health after attack
      } else { // if randomNum is not equal to 1, the attack misses
        cout << "\nIt missed!\n";
      }
    } else if (playerChoice == 2) { // if the user input is 2, they're health will be increased by the value of durabilityPts (AMORPTS)
      cout << "\nYou choose to defend!\n";
      cout << "Your defense is up " << user.getDurabilityPts() << " points!";
      user.addHealth(user.getDurabilityPts()); // adds health to user
    }

     if (enemy.getHealth() <= 0) { // checks if the enemy's health is lower or equal to zero, if so, the loop will end
      winCase = true;
    }

    cout << "\n====================\n";

    cout << "\nIt's the enemy's turn!\n";
    sleep(2); // waits 2 seconds
    cout << "\nThe enemy attacks!\n";
    randomCase(randomNum); // generates a random number

    if (randomNum == 0) { // if the random number is equal to 0, the attack hits user
      cout << "\nThe attack hit you!\n";
      user.decreaseHealth(enemy.getMaxHitPts()); // decreases the health for user by the balue of the enemy's max hit points
    } else { // if the random number is not 0, the attack misses
      cout << "\nThe creature misses!\n";
    }

    cout << "\n====================\n";

    if (user.getHealth() <= 0) { // checks if the user health is lower or equal to 0, if so, the loop ends
      winCase = true;
    }

  }
  gameEnd(user, enemy); // when loop ends, the gameEnd function is called. This will determine the winCase (user or enemy win)
}

void prepPhase(player &user) { 
  int choice; 

  cout << "\n\nChoose which attributes to add to before battle (you get two attributes to choose from +3)\n";

  cin >> choice;

  (choice == 1) ? void(user.addHealth(3)) : // if choice is equal to 1, 3 pts of health will be added
    (choice == 2) ? void(user.addDurabilityPts(3)) : // if choice is equal to 1, 3 pts of armor will be added
      (choice == 3) ? void(user.addMaxHitPts(3)) : // if choice is equal to 1, 3 pts of damage will be added
        void(cout << "Input Invalid, please try again:\n");
}

void gameEnd(player &user, player &enemy) {
  (user.getHealth() <= 0) ? void(cout << "\nGAME OVER enemy wins\n") : // if user health is less than or equal to 0, enemy win case is output
    (enemy.getHealth() <= 0) ? void(cout << "\nCONGRATS you won!\n") : // if enemy health is less than or equal to 0, user win case is output
      void("\nIt's a tie!\n");
}

void randomCase(int &randomNum) {
    std::vector<int> randomNumber = {0, 1};  // vector initialized with values 0 and 1

    unsigned seed = static_cast<unsigned>(time(0)); // seeds the random number generator with the current time
    std::mt19937 rng(seed); // Mersenne Twister random number generator

    std::shuffle(randomNumber.begin(), randomNumber.end(), rng); // shuffles the randomNumber vector

    randomNum = randomNumber[0]; // sets the randomNum integer value equal to the first element of randomNumber vector
    std::cout << std::endl;
}