#include <iostream>

using namespace std; 

class player {
  public: 
    player() {

    }

    player(int currentHealth, int currentDurability, int currentHitPts) {
        maxHealth = currentHealth;
        maxDurabilityPts = currentDurability;
        maxHitPts = currentHitPts;
    }
    void getHealth() {
      cout << maxHealth;
    }

    void getDurabilityPts() {

    }

    int getMaxHitPts() {
      return maxHitPts;
    }

    int addHealth(int currentHealth) {
      maxHealth += currentHealth;
      return currentHealth;
    }

    int addDurabilityPts(int currentDurabilty) {
      maxDurabilityPts += currentDurabilty;     
      return currentDurabilty; 
    }

    int addMaxHitPts(int currentHitPts) {
      maxHitPts += currentHitPts;
      return currentHitPts;
    }

    int decreaseHealth(int maxHitPts) {
      maxHealth -= maxHitPts;
    }

    void displayStats() {
      cout << "PLAYER STATS:\nHEALTHPTS: " << maxHealth << "\nARMORPTS: " << maxDurabilityPts << "\nDMGPTS: " << maxHitPts << endl;
    }


  private: 
    int maxHealth; 
    int maxDurabilityPts;
    int maxHitPts;
};