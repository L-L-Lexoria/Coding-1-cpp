// Coding Week 2

//First, set up the code.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//begin the program

int main() {
    // make the string input for cin
    string input = "";
    string userName = "User";
    vector<string> favoriteGames = {"example_game_1", "example_game_2"};
    //welcome the user
    cout << "Welcome, " << userName << "!\n";
    cout << "This is your personalized list of favorite games.\n";
    for(int i = 0; i < favoriteGames.size(); i++) {
        cout << favoriteGames[i] <<"\n";
    }
    cout << "\n";
    // begin the while loop.
    while(true) {
        //ask them what they would like to do. And offer options.
        cout << "\nWhat would you like to do, " << userName << "? (Options are case sensetive!)\n";
        cout << "Show\nAdd\nEdit\nDelete\nChange Name\nQuit\n";
        //grab the input
        getline(cin,input);
        //the if for "Show"
        if (input == "Show") {
            cout << "\nYou chose: Show.\n\n";
            cout << "Here is your personalized list of favorite games.\n";
            for(int i = 0; i < favoriteGames.size(); i++) {
            cout << favoriteGames[i] <<"\n";
            }
        // the else if for "Add"
        } else if (input == "Add") {
            cout << "\nYou chose: Add.\n\n";
            cout << "What game would you like to add, " << userName << "?\n";
            getline(cin,input);
            cout << "Okay, adding \"" << input << "\" to the list.";
            favoriteGames.push_back(input);
        // the else if for "Edit"
        } else if (input == "Edit") {
            //create the iterator for just this if
            vector<string>::iterator iter = favoriteGames.begin();
            cout << "\nYou chose: Edit.\n\n";
            
            //a small while loop in case player input found nothing, and can try again.
            while(true) {
                cout << "What would you like to edit, " << userName << "?\n";
                getline(cin,input);
                iter = find(favoriteGames.begin(), favoriteGames.end(), input);
                //if the game is found
                if(iter != favoriteGames.end()) {
                    cout << "We found \"" << *iter << ".\"\n";
                    cout << "What would you like to change it to?\n";
                    getline(cin,input);
                    cout << "Okay, changing \"" << *iter << "\" to \"" << input << ".\"\n";
                    *iter = input;
                    break;
                    // if the game is NOT found
                } else {
                    cout << "We could not find \"" << input << ".\"";
                    cout << "Would you like to search again? (y/n)\n";
                    getline(cin,input);
                    if(input == "y") {
                        continue;
                    } else {
                        cout << "Selected n or an unspecified input, cancelling request.\n";
                        break;
                    }
            
                }
            } // end of the Edit loop, beginning Delete
        } else if (input == "Delete") {
            //create the iterator for just this if
            vector<string>::iterator iter = favoriteGames.begin();
            cout << "\nYou chose: Delete.\n\n";
            while(true) {
                cout << "What game would you like to delete from the list, " << userName << "?\n";
                getline(cin,input);
                iter = find(favoriteGames.begin(), favoriteGames.end(), input);
                if(iter != favoriteGames.end()) {
                    cout << "We found \"" << *iter << ".\"\n";
                    cout << "Are you sure you want to delete this? (y/n)\n";
                    getline(cin,input);
                    if(input == "y") {
                        cout << "Okay, removing \"" << *iter << "\" from the list.\n";
                        favoriteGames.erase(iter);
                        break;
                    } else {
                        cout << "Selected n or an unspecified input, cancelling request.\n";
                        break;
                    }
                    // if the game is NOT found
                } else {
                    cout << "We could not find \"" << input << ".\"";
                    cout << "Would you like to search again? (y/n)\n";
                    getline(cin,input);
                    if(input == "y") {
                        continue;
                    } else {
                        cout << "Selected n or an unspecified input, cancelling request.\n";
                        break;
                    }
                }
            } // end of Delete loop, beginning Quit
        } else if (input == "Change Name") {
            cout << "Okay, what would you like to change your name to?\n";
            getline(cin, input);
            cout << "Okay, changing name from \"" << userName << "\" to \"" << input << ".\"";
            userName = input;
            // end of Change Name
        } else if (input == "Quit") {
            cout << "You chose: Quit\n";
            cout << "Are you sure you want to quit? Type \"YES\" to quit.\n";
            getline(cin, input);
            if(input == "YES") {
                cout << "Thank you for using this program. Goodbye, " << userName << ".\n" ;
                return 0;
            } else cout << "Selected an unspecified input, cancelling request.\n";
            // end of Quit
        } else cout << "Selected an unspecified input, please try again, " << userName << ".\n" ;
    }
}
