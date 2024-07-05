// Leo Guermonprez

#include "includes.h" // This includes the long list of includes 
                        //as well as namespace std

// All of this is all the universal variables this code needs.
string userInput = "";
string userName = "User";
string line = "";
vector<string> favGames;
ifstream findFile;
ofstream writeFile;


// This is for making the program feel more personalized.
    // Does not majorly alter the code.
    // setUserName() is used in beginProgram()
void setUserName() {
    cout << "Can you give us a name to refer to you by?\n";
    getline(cin, userInput);
    userName = userInput;
    cout << "Thank you, " << userInput << "!\n";
}


// This is for welcoming the user to the program, and explaining what it does.
void beginProgram() {
    cout << "Welcome, User! You are now using FavGames.exe!\n";
    cout << "This program allows you to store your games in a text file.\n";
    cout << "This can be done by making a new file, or loading an old one!\n";
    setUserName();
}


// This is to check if there is a file in this folder/
    // If yes, read off what is inside
    // If no, create a new file
void loadFile() {
    cout << "Searching for file named \"favorite_games.txt\"...\n";
    ifstream findFile("favorite_games.txt");
    if(findFile.is_open()) {
        cout << "We found that file, displaying contents now:\n\n";
        while(getline(findFile, line)) {
            cout << line << "\n";
            favGames.push_back(line);
        }
        cout << "\n";
    } else {
        cout << "Could not find file, creating \"favorite_games.txt\"...\n";
        ofstream createFile("favorite_games.txt");
        createFile.close();
        cout << "Successfully created file!\n";
    }
}


// This is to ask the user what they would like to do, 
    //marking the start of a new loop
string promptUser() {
    cout << "What would you like to do, " << userName << "?\n";
    cout << "Please use the corresponding numbers to answer.\n";
    cout << "1) Add a Game to the List\n";
    cout << "2) Edit a Game in the List\n";
    cout << "3) Remove a Game from the List\n";
    cout << "4) Show the Current List of Favorite Games\n";
    cout << "5) Quit the Program\n";
    getline(cin, userInput);
    return userInput;
}


// This is for adding a new game.
void addGame() {
    cout << "\nYou chose: Add a Game to the List.\n\n";
    cout << "What game would you like to add, " << userName << "?\n";
    getline(cin,userInput);
    cout << "Okay, adding \"" << userInput << "\" to the list.\n\n";
    favGames.push_back(userInput);
}


// This is for editing the name of a game in the vector.
void editGame() {
    cout << "\nYou chose: Edit a Game in the List.\n\n";
    vector<string>::iterator iter = favGames.begin();
    while(true) {
        cout << "What would you like to edit, " << userName << "?\n";
        getline(cin,userInput);
        iter = find(favGames.begin(), favGames.end(), userInput);
        //if the game is found
        if(iter != favGames.end()) {
            cout << "We found \"" << *iter << ".\"\n";
            cout << "What would you like to change it to?\n";
            getline(cin,userInput);
            cout << "Okay, changing \"" << *iter << "\" to \"" << userInput << ".\"\n";
            *iter = userInput;
            break;
            // if the game is NOT found
        } else {
            cout << "We could not find \"" << userInput << ".\"";
            cout << "Would you like to search again? (Y/N)\n";
            getline(cin,userInput);
            if(userInput == "Y") {
                continue;
            } else {
                cout << "Selected N or an unspecified input, cancelling request.\n";
                break;
            }
            
        }
    }


}


// This is for removing a game from the vector.
void removeGame() {
    vector<string>::iterator iter = favGames.begin();
    cout << "\nYou chose: Remove a Game from the List.\n\n";
    while(true) {
        cout << "What game would you like to delete from the list, " << userName << "?\n";
        getline(cin,userInput);
        iter = find(favGames.begin(), favGames.end(), userInput);
        if(iter != favGames.end()) {
            cout << "We found \"" << *iter << ".\"\n";
            cout << "Are you sure you want to delete this? (Y/N)\n";
            getline(cin,userInput);
            if(userInput == "Y") {
                cout << "Okay, removing \"" << *iter << "\" from the list.\n";
                favGames.erase(iter);
                break;
            } else {
                cout << "Selected n or an unspecified input, cancelling request.\n";
                break;
                }
            // if the game is NOT found
        } else {
            cout << "We could not find \"" << userInput << ".\"";
            cout << "Would you like to search again? (Y/N)\n";
            getline(cin,userInput);
            if(userInput == "Y") {
                continue;
            } else {
                cout << "Selected n or an unspecified input, cancelling request.\n";
                break;
            }
        }
    }
}


// This is to show the current list in the vector.
void showGames() {
    cout << "You chose: Show the Current List of Favorite Games.\n\n";
    cout << "Your current list of favorite games:\n";
    for(int i = 0; i < favGames.size(); i++) {
        cout << favGames[i] << "\n";
    }
    cout << "\n";
}


// This is to end the program. It will ask if the user wants to really quit.
    // If yes, then ask if they would like to save their games in a txt file
        // If yes, acknowledge then do so.
        // If no, acknowledge and do nothing.
        // Regardless, thank the user.
    // If no, acknowledge an unspecified input and cancel action. 
int quitProgram() {
    cout << "You chose: Quit the Program.\n";
    cout << "Are you sure you want to quit, " << userName << "? Type \"YES\" to quit.\n";
    getline(cin, userInput);
    if(userInput == "YES") {
        cout << "Thank you for using this program, " << userName << ".\n";
        cout << "Would you like to save your games to favorite_games.txt? (Y/N)\n";
        getline(cin,userInput);
        while(true) {
            if(userInput == "Y") {
                cout << "Okay, saving your favorite games to favorite_games.txt...\n";
                ofstream writeFile ("favorite_games.txt");
                if(writeFile.is_open()) {
                    for(int i = 0; i < favGames.size(); i++) {
                        writeFile << favGames[i] << "\n";
                    }
                }
                writeFile.close();
                cout << "Successfully saved, " << userName << ". Thank you!\n";
                return 2;
            } else if (userInput == "N") {
                cout << "Okay, ending program without saving. Thank you!";
                return 2;
            } else cout << "Selected an unspecified input, please try again.\n\n";
        }
    } else  {
        cout << "Selected an unspecified input, cancelling request.\n\n";
        return 0;
        }
}


// This is the bulk of the code down here, where programs from 'string promptUser()
    // are used
void userPromptLoop() {
    while(true) {
        promptUser();
        if(userInput == "1") {
            addGame();
        } else if (userInput == "2") {
            editGame();
        } else if (userInput == "3") {
            removeGame();
        } else if (userInput == "4") {
            showGames();
        } else if (userInput == "5") {
            if(quitProgram() == 2) break;
        } else {
            cout << "User input failed.\n";
        }
    }
}