// Last Updated June 7th 2024

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

//Adventure Assignment
//set up the game
    //int health = 10, attack block, turns = 0
    //seed the RNG
//start the loop
    //add 1 to turns
    //start the encounter
        //randomly generate numbers for attack (0-4) and block (0-4)
        //if block is greator or equal to attack, successful block
        //otherwise, subtracked attack value from health
        //ask the player if they would like to keep adventuring. if no, break loop
//keep looping while health is greater than zero and fewer than 4 turns have passed

//if health is greater than 0, congragulate player
//otherwise, tell the player they are dead

int main() {
    int playerHealth = 10;
    int enemyAttack = 0;
    int playerBlock = 0;
    int turnNumber = 0;
    int playerGold = 0;
    int foundGold = 0;
    srand(time(NULL));
    int totalEncounters = rand() % 5 + 6; //All this sets the playing field of the game.

    cout << "Welcome, Adventurer, what is your name?\n"; // Welcome the player and begin
    string playerName = "";
    cin >> playerName;
    cout << "\nWelcome, " << playerName << "!\n";
    cout << "Let us begin your adventure! We have up to " << totalEncounters << " encounters to go through!\n";
    
    Sleep(1000);
    // We then begin the loop.
    while(playerHealth > 0 && turnNumber++ < totalEncounters) {
        cout << "Encounter " << turnNumber << " begins!\n";
        //randomly generate attack and defense
        enemyAttack = rand() % 5;
        playerBlock = rand() % 5;

        Sleep(1000);
        // Explain the sequence to the player. Data is useless if not told!
        cout << "You fight an enemy!\n";
        Sleep(1000);
        cout << "They attack with a power of " << enemyAttack << "!\n";
        Sleep(1000);
        cout << "You block with a power of " << playerBlock << "!\n";
        Sleep(1000);
        // Check if the player blocks or gets hit.
        if(playerBlock >= enemyAttack) {
            cout << "You successfully blocked the enemy's attack!\n";
            foundGold = rand() % 10 + 1 + turnNumber;
            playerGold += foundGold;
        } else {
            cout << "You fail to block the attack!\n";
            playerHealth -= enemyAttack*2;
            cout << "You take " << enemyAttack*2 << " points of damage.\n";
        }

        Sleep(1000);
        // This checks if the player is dead first.
        if(playerHealth <= 0) {
            break;
        }
        // Randomly scaling gold found if the player remains alive.
        cout << "You find " << foundGold << " gold!\n";
        Sleep(1000);
        cout << "You now have " << playerGold << " gold!\n";
        Sleep(1000);
        //check if the total encounters has ended. if not, ask the player to continue
        if(turnNumber == totalEncounters) {
            cout << "Alright, let's head home now.\n";
            Sleep(1000);
            break;
        }
        cout << "Would you like to keep adventuring?\n";
        cout << "Type Y or N\n";
        char playerInput = '0';
        cin >> playerInput;
        if(playerInput == 'Y' || playerInput == 'y') {
            cout << "Great! Let's keep going.\n";
            Sleep(1000);
        } else if(playerInput == 'N' || playerInput == 'n') {
            cout << "Alright, let's head home.\n";
            Sleep(1000);
            break;
        } else {
            cout << "The input specified was not Y or N. The Adventure shall now end.\n";
            Sleep(1000); //Safeguard to assume no if not explicity Y or y.
            break;
        }
    }
    //First check if the player is dead, since it is the first way the loop can break.
    if(playerHealth <= 0) {
        cout << "Unfortunately you have fallen. Your adventure ends here.\n";
        Sleep(1000);
        cout << "Better luck next time!\n";
        Sleep(1000);
        // If alive, then tell the player their stats.
    } else {
        cout << playerName << ", you end your adventure, alive.\n";
        Sleep(1000);
        cout << "You earned " << playerGold << " gold and took " << 10 - playerHealth << " total points of damage.\n";
        Sleep(1000);
        // And some flavor for how healthy the player is.
        if(playerHealth >= 6) {
            cout << "You're looking healthy still.\n";
            cout << "Good, always pull out while you're still winning!\n";
        } else if(playerHealth < 6 && playerHealth >= 3) {
            cout << "You look a little beat, good on you for knowing when to quit!\n";
        } else {
            cout << "You're barely standing as we speak!\n";
            cout << "You might have to spend all that hard-earned gold on a medic!\n";
        }
        Sleep(1000);
        // Thank them then end the program.
        cout << "Thank you for playing, " << playerName << "!\n";
    }
} 