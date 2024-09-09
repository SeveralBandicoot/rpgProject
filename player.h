#include <iostream>

using namespace std; 

class player {
  public: 
    player() { // default constructor

    }

    player(int currentHealth, int currentDurability, int currentHitPts) { // paramatized constructor
        maxHealth = currentHealth; // assigns privatized maxHealth variable to currentHealth 
        maxDurabilityPts = currentDurability; // assigns privatized maxDurabilityPts variable to currentDurability
        maxHitPts = currentHitPts; // assigns privatized maxHitPts variable to currentHitPts 
    }
    int getHealth() { // get health function, returns maxHealth value 
      return maxHealth;
    }

    int getDurabilityPts() { // get durability function, returns maxDurabilityPts value
      return maxDurabilityPts;
    }

    int getMaxHitPts() { // gets max hit points function, returns getMaxHitPts value
      return maxHitPts;
    }

    int addHealth(int currentHealth) { // add health function, adds health points depending on value of currentHealth value
      maxHealth += currentHealth;
      return currentHealth;
    }

    int addDurabilityPts(int currentDurabilty) { // addDurabilityPts function depending on value of currentDurability value 
      maxDurabilityPts += currentDurabilty;     
      return currentDurabilty; 
    }

    int addMaxHitPts(int currentHitPts) { // addMaxhitPts function, adds points to maxHitPts depending on value of currentHitPts
      maxHitPts += currentHitPts;
      return currentHitPts;
    }

    void decreaseHealth(int maxHitPts) { // decreaseHealth function, decreases health depending on maxHitPts value
      maxHealth -= maxHitPts;
    }

    void displayStats() { // displayStats function, displays stats including health, durability, and damage
      cout << "PLAYER STATS:\nHEALTHPTS: " << maxHealth << "\nARMORPTS: " << maxDurabilityPts << "\nDMGPTS: " << maxHitPts << endl;
    }


  private: 
    int maxHealth; // private health variable
    int maxDurabilityPts; // private durabilitypts variable
    int maxHitPts; // private hitpts variable
};