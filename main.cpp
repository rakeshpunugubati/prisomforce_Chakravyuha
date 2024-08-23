#include <bits/stdc++.h>

using namespace std;

class ChakravyuhaGame {
private:
    int maxEnemies;              // Total number of enemies in the Chakravyuha
    vector<int> enemyPowers;    // Powers of each enemy
    int initialPower;           // Initial power of Abhimanyu
    int totalSkips;             // Total number of skips Abhimanyu has
    int totalRecharges;         // Number of times Abhimanyu can recharge

public:
    // Constructor to initialize the game with given parameters
    ChakravyuhaGame(int maxEnemies, vector<int> powers, int power, int skips, int recharges) {
        this->maxEnemies = maxEnemies;
        this->enemyPowers = powers;
        this->initialPower = power;
        this->totalSkips = skips;
        this->totalRecharges = recharges;
    }

    // Recursive function to check if Abhimanyu can cross the Chakravyuha
    bool canCrossChakravyuha(int enemy, int currentPower, int behindAttackPower, int remainingSkips, int remainingRecharges) {
        // Base case: If all enemies are crossed
        if (enemy == maxEnemies) return true;

        bool canCross = false;

        // Option 1: Recharge if possible and if current power is less than initial power
        if (remainingRecharges > 0 && currentPower < initialPower) {
            canCross |= canCrossChakravyuha(enemy, initialPower, behindAttackPower, remainingSkips, remainingRecharges - 1);
        }

        // Check if Abhimanyu can withstand the behind attack
        if (currentPower >= behindAttackPower) {
            currentPower -= behindAttackPower;  // Deduct the power for the attack from behind
            behindAttackPower = 0;              // Reset the behind attack power
        } else {
            return false;  // Cannot withstand the attack from behind, so return false
        }

        // Option 2: Skip the current enemy if skips are remaining
        if (remainingSkips > 0) {
            canCross |= canCrossChakravyuha(enemy + 1, currentPower, behindAttackPower, remainingSkips - 1, remainingRecharges);
        }

        // Option 3: Fight with the current enemy if current power is sufficient
        if (currentPower >= enemyPowers[enemy]) {
            // If the enemy regenerates (enemies at index 2 and 6)
            if (enemy == 2 || enemy == 6) {
                behindAttackPower = enemyPowers[enemy] / 2;  // Set the behind attack power
            }
            // Recursively check if Abhimanyu can cross the next enemy
            canCross |= canCrossChakravyuha(enemy + 1, currentPower - enemyPowers[enemy], behindAttackPower, remainingSkips, remainingRecharges);
        }

        return canCross;  // Return whether Abhimanyu can cross the Chakravyuha
    }

    // Function to start the game and check if Abhimanyu can cross the Chakravyuha
    void startGame() {
        if (canCrossChakravyuha(0, initialPower, 0, totalSkips, totalRecharges)) {
            cout << "Abhimanyu can cross the Chakravyuha" << endl;
        } else {
            cout << "Abhimanyu cannot cross the Chakravyuha" << endl;
        }
    }
};

int main() {
    int maxEnemies = 11;  // Number of enemies in the Chakravyuha
    
    // For Custom Test Cases
    /* 
    
    vector<int> enemyPowers(maxEnemies);  // Vector to store the powers of each enemy
    // Read the power of each enemy
    for (int i = 0; i < maxEnemies; i++) {
        cin >> enemyPowers[i];
    }

    int initialPower, totalSkips, totalRecharges;

    // Read Abhimanyu's initial power, total skips, and total recharges
    cin >> initialPower >> totalSkips >> totalRecharges;
     
    */
    vector<int> enemyPowers1 = {1, 8, 3, 5, 7, 5, 5, 3, 9, 2, 4};
    
    // Create a game instance and start the game
    ChakravyuhaGame game1(maxEnemies, enemyPowers1, 6, 3, 3);
    game1.startGame();
    
    vector<int> enemyPowers2 = {1, 8, 11, 3, 5, 7, 9, 8, 4, 5, 2};
    
    // Create a game instance and start the game
    ChakravyuhaGame game2(maxEnemies, enemyPowers2, 9, 4, 3);
    game2.startGame();
    
    return 0;
}


//Test case 1
/*  enemyPowers = {1, 8, 3, 5, 7, 5, 5, 3, 9, 2, 4}
    Power = 6;
    skips = 3;
    recharges = 3;
    Answer: Abhimanyu cannot cross the Chakravyuha;
    
//Test case 1
/*  
    enemyPowers = {1, 8, 11, 3, 5, 7, 9, 8, 4, 5, 2}
    Power = 9;
    skips = 4;
    recharges = 3;
    Answer: Abhimanyu can cross the Chakravyuha;
*/