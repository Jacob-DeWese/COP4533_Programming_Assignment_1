//
// Created by thear on 1/28/2026.
//

#pragma once
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Verifier {
public:
  bool checkIfValid(vector<vector<int>>& matches, int numStudents);
  bool checkIfStable(vector<vector<int>>& matches, vector<vector<int>>& hospitalPrefs, vector<vector<int>>& studentPrefs, pair<int, int>& blockingPair);
};
