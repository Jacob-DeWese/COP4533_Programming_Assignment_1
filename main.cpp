#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    string instructionSelect = argv[1];

    if (instructionSelect == "Matcher" || instructionSelect == "matcher" || instructionSelect == "Match" | instructionSelect == "match") {
        ifstream inputFile;
        inputFile.open(argv[2]);
        if (!inputFile.is_open()) {
            cerr << "Error opening file " << argv[2] << endl;
            return 1;
        }
    }
    else if (instructionSelect == "Verifer" || instructionSelect == "verifier" || instructionSelect == "Verify" || instructionSelect == "verify") {
        if (argc < 4) {
            cerr << "Error: Matcher not run or matching file not found" << endl;
            return 1;
        }
        ifstream inputFile;
        inputFile.open(argv[2]);
        ifstream matchFile;
        matchFile.open(argv[3]);
        if (!inputFile.is_open()) {
            cerr << "Error opening input file " << argv[2] << endl;
            return 1;
        }
        if (!matchFile.is_open()) {
            cerr << "Error opening matching file " << argv[3] << endl;
            return 1;
        }
    }
    else {
        cerr << "Error: Select either matcher or verifier" << endl;
        return 1;
    }

    return 0;
}