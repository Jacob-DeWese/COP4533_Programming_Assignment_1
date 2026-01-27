#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "GaleShapely.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << "<Matcher|Verifier> <input_file> <output_file>" << endl;
        return 1;
    }

    string instructionSelect = argv[1];

    if (instructionSelect == "Matcher" || instructionSelect == "matcher" || instructionSelect == "Match" || instructionSelect == "match") {
        ifstream inputFile;
        inputFile.open(argv[2]);
        if (!inputFile.is_open()) {
            cerr << "Error opening file " << argv[2] << endl;
            return 1;
        }
        int numPeople;
        inputFile >> numPeople;
        vector<vector<int>> hospitalPreferenceList(numPeople, vector<int>(numPeople));
        vector<vector<int>> studentPreferenceList(numPeople, vector<int>(numPeople));
        for(int i = 0; i < numPeople; i++){
           string preference;
           inputFile >> preference;
           for(int j = 0; j < numPeople; j++){
               hospitalPreferenceList[i][j] = preference[j] - '1';
           }
        }
        for(int h = 0; h < numPeople; h++){
            string preference;
            inputFile >> preference;
            for(int g = 0; g < numPeople; g++){
                studentPreferenceList[h][g] = preference[g] - '1';
            }
        }
        vector<vector<int>> studentRankingList(numPeople, vector<int>(numPeople));
        for(int g = 0; g < numPeople; g++){
           for(int h = 0; h < numPeople; h++){
               int studentRanking = studentPreferenceList[g][h];
               studentRankingList[g][studentRanking] = h;
           }
        }
        inputFile.close();
        GaleShapely galeShapely;
        vector<vector<int>> matchings = galeShapely.GaleShapelyAlgorithm(hospitalPreferenceList, studentRankingList);
        for(const auto& hospital : matchings){
            cout << hospital[0] + 1 << " " << hospital[1] + 1<< endl;
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