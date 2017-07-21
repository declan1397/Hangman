#include <iostream>
#include <vector>
#include <fstream>
#include <random>

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
            cout << temp << "\n";
        }

        isValid = true;
    }
    word_file.close();

    /******************/
    // Play
    /******************/

    mt19937 generator (stoi(argv[2]));
    chosen_word = word_bank[generator() % word_bank.size()];

    cout << "Chosen_word: " << chosen_word << endl;


    return 0;
}
