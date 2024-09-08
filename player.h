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

    }

    void getDurabilityPts() {

    }

    void getMaxHitPts() {

    }

    int addHealth(int currentHealth) {
      maxHealth += currentHealth;
    }

    int addDurabilityPts(int currentDurabilty) {
      maxDurabilityPts += currentDurabilty;      
    }

    int addMaxHitPts(int currentHitPts) {
      maxHitPts += currentHitPts;
    }

    void displayStats() {
      cout << "HEALTHPTS: " << maxHealth << "\nARMORPTS: " << maxDurabilityPts << "\nDMGPTS: " << maxHitPts;
    }


  private: 
    int maxHealth; 
    int maxDurabilityPts;
    int maxHitPts;
};