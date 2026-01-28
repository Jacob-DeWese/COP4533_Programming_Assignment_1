//
// Created by brook on 1/27/2026.
//

#include "GaleShapely.h"
vector<vector<int>> GaleShapely::GaleShapelyAlgorithm(vector<vector<int>> hospitalInput, vector<vector<int>> studentRankings){
    bool hospitalsUnassigned=true;
    int numberOfHospitals = hospitalInput.size();
    vector<int> hospitalMatchings(numberOfHospitals,-1);
    vector<int> studentMatchings(numberOfHospitals,-1);
    vector<int> nextToMatch(numberOfHospitals, 0);
    while(hospitalsUnassigned){
        hospitalsUnassigned=false;
        for(int i=0;i<numberOfHospitals;i++){
            if(hospitalMatchings[i]==-1&&nextToMatch[i]<numberOfHospitals){
                hospitalsUnassigned=true;
                int student = hospitalInput[i][nextToMatch[i]];
                nextToMatch[i]++;
                if(studentMatchings[student]==-1) {
                    hospitalMatchings[i] = student;
                    studentMatchings[student] = i;
                }else{
                    int current = studentMatchings[student];
                    if(studentRankings[student][i]<studentRankings[student][current]){
                        hospitalMatchings[current] = -1;
                        hospitalMatchings[i] = student;
                        studentMatchings[student] = i;
                    }
                }
            }
        }
    }
    outputList.clear();
    for(int i=0;i<numberOfHospitals;i++){
        outputList.push_back({i,hospitalMatchings[i]});
    }
    return outputList;
}
