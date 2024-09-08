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
void gameEnd(player &user, player &enemy);
void randomCase(int &randomNum);
int main() {
  player user(12, 4, 9);

  cout << "You are getting ready for battle with an unknown enemy, choose how to prep:\n";

  for (int i = 0; i < 2; i++) {
    user.displayStats();
    prepPhase(user);
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
    cout << enemy.getHealth();

    cout << "\n\nYou approached an enemy! Choose your action:\n1.) ATTACK\n2.) DEFEND\n";
    cin >> playerChoice;
    if (playerChoice == 1) {
      cout << "\nYou choose to attack!\n";
      for (int i = 0; i < 3; i++) {
        sleep(1);
        cout << i << "...";
      }
      randomCase(randomNum);
      if (randomNum == 0) {
        cout << "\nThe attack hit the enemy!\n";
        enemy.decreaseHealth(user.getMaxHitPts());
        cout << "\nENEMY STATS:\nHEALTH: ";
        cout << enemy.getHealth();
      } else {
        cout << "\nIt missed!\n";
      }
    } else if (playerChoice == 2) {
      cout << "\nYou choose to defend!\n";
      cout << "Your defense is up " << user.getDurabilityPts() << " points!";
      user.addHealth(user.getDurabilityPts());
    }

     if (enemy.getHealth() <= 0) {
      winCase = true;
    }

    cout << "\n====================\n";

    cout << "\nIt's the enemy's turn!\n";
    sleep(2);
    cout << "\nThe enemy attacks!\n";
    randomCase(randomNum);

    if (randomNum == 0) {
      cout << "\nThe attack hit you!\n";
      user.decreaseHealth(enemy.getMaxHitPts());
    } else {
      cout << "\nThe creature misses!\n";
    }

    cout << "\n====================\n";

    if (user.getHealth() <= 0) {
      winCase = true;
    }

  }
  gameEnd(user, enemy);
}

void prepPhase(player &user) {
  int choice; 

  cout << "\n\nChoose which attributes to add to before battle (you get two attributes to choose from +3)\n";

  cin >> choice;

  (choice == 1) ? void(user.addHealth(3)) :
    (choice == 2) ? void(user.addDurabilityPts(3)) :
      (choice == 3) ? void(user.addMaxHitPts(3)) :
        void(cout << "Input Invalid, please try again:\n");
}

void gameEnd(player &user, player &enemy) {
  (user.getHealth() <= 0) ? void(cout << "\nGAME OVER enemy wins\n") :
    (enemy.getHealth() <= 0) ? void(cout << "\nCONGRATS you won!\n") :
      void("\nIt's a tie!\n");
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