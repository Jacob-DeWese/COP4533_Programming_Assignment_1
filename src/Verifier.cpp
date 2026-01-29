//
// Created by thear on 1/28/2026.
//
#include "Verifier.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Verifier::checkIfValid(vector<vector<int>>& matches, int numStudents) {
    vector<bool> hospitals(numStudents, false);
    vector<bool> students(numStudents, false);
    for (int i = 0; i < matches.size(); i++) {
        int hospital = matches[i][0];
        int student = matches[i][1];

        if (hospitals[hospital] || students[student]) {
          return false;
        }

        hospitals[hospital] = true;
        students[student] = true;
    }
    return true;
}

bool Verifier::checkIfStable(vector<vector<int>>& matches, vector<vector<int>>& hospitalPrefs, vector<vector<int>>& studentPrefs, pair<int, int>& blockingPair) {
    int numMatches = matches.size();

    vector<int> studentMatch(numMatches);
    vector<int> hospitalMatch(numMatches);
    for (int i = 0; i < numMatches; i++) {
        int hospitals = matches[i][0];
        int students = matches[i][1];
        hospitalMatch[hospitals] = students;
        studentMatch[students] = hospitals;
    }

    for (int i = 0; i < numMatches; i++) {
        int currentStudent = matches[i][1];
        for (int j = 0; j < numMatches; j++) {
            if (j == currentStudent) {
                continue;
            }

            int currentHospital = studentMatch[j];

            int studentRanking = 0;
            int currentStudentRanking = 0;
            for (int k = 0; k < studentPrefs.size(); k++) {
                if (hospitalPrefs[i][k] == j) {
                    studentRanking = k;
                }
                if (hospitalPrefs[i][k] == currentStudent) {
                    currentStudentRanking = k;
                }
            }

            int hospitalRanking = 0;
            int currentHospitalRanking = 0;
            for (int l = 0; l < numMatches; l++) {
                if (studentPrefs[j][l] == i) {
                    hospitalRanking = l;
                }
                if (studentPrefs[j][l] == currentHospital) {
                    currentHospitalRanking = l;
                }
            }


            if (studentRanking < currentStudentRanking && hospitalRanking < currentHospitalRanking) {
                blockingPair = {i + 1, j + 1};
                return false;
            }
        }
    }
    return true;
}