#include <iostream>

using namespace std;

int main(int argc, const char * argv[]){
    cout << "Command line length: " << argc << endl; 
    cout << "Filename: " << argv[1] << endl;
    cout << "Seed: " << argv[2] << endl;

    return 0;
}