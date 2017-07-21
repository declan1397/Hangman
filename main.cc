#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <locale>
#include <string>

using namespace std;

int main(int argc, const char * argv[]){
    
    if (argc <= 1){
        cout << "ERROR: No input file specified.\n";
    }

    string chosen_word;
    string temp;
    vector<string> word_bank;
    ifstream word_file;
    word_file.open(argv[1]);
    while (getline(word_file, temp)){
        // Check for >6 characters
        bool isValid = true;
        if (temp.size() < 6){
           isValid = false;
        }

        else { // Check for valid ASCII values
            for (int i=0; i < temp.size(); i++){
                if (temp[i] < 'A' || temp[i] > 'z'){
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid){
            word_bank.push_back(temp);
        }

        isValid = true;
    }
    word_file.close();

    /******************/
    // Play
    /******************/

    mt19937 generator (stoi(argv[2]));
    chosen_word = word_bank[generator() % word_bank.size()];
    string guessed_word = "";
    vector<char> letters_used;
    int lives_left = 5;
    string guess;

    // Make guessed word same length as chosen word
    for (int i=0; i<chosen_word.size(); i++){
        guessed_word += "-";
    }

    // Play game loop
    while (true){
        cout << "Word: " << guessed_word << "\n";
        cout << "Letters used: ";
        for (int i=0; i < letters_used.size(); i++){
            cout << letters_used[i] << " ";
        }
        cout << "\n";
        cout << "You have " << lives_left << " lives left.\n";
        cout << "Next guess: ";

        cin >> guess;

        // If character guess
        if (guess.size() == 1){

            // If guess is upper case
            if (guess[0] >= 'A' || guess[0] < 'a'){
                cout << "Changed " << guess;
                guess = tolower(guess);
                cout << " to " << guess << endl;
            }
            
            // If guess is out of range
            if (guess[0] < 'a' || guess[0] > 'z') {
                lives_left--;
                letters_used.push_back(guess);
                continue;
            }

            // Guess is valid guess
            else {
                // Check if guess has already been made
                vector<char>::iterator i = find(letters_used.begin(), letters_used.end(), guess);

                if (i != vw.end()) {
                    cout << "You already guessed letter \"" << guess << "\".\n";
                }

                else {
                    for (int j=0; j < chosen_word.size(); j++){
                        if (chosen_word[j] == guess){
                            guessed_word[j] = guess;
                            break;
                        }
                    }
                }

            }
        }

        // If word guess
        else if (guess.size() > 1){

        }

        // Check if game is won
        if (guessed_word == chosen_word){
            "You WIN!  The word was \"" << chosen_word << "\".\n";
            break;
        }

    }




    return 0;
}
