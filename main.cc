#include <iostream>
#include <vector>
#include <fstream>

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
    while (geline(word_file, temp)){
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
            cout << "temp\n";
        }

        isValid = true;
    }
    word_file.close();

     
    cout << "Filename: " << argv[1] << endl;
    cout << "Seed: " << argv[2] << endl;

    return 0;
}
