#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

class Evaluator {
    public:
        Evaluator(int varCount, vector<string> expression);
        void truthValuesGenerator(int r, int s,  vector<vector <bool>> &vals);
    private:
     int rows, cols;
     vector<vector<bool>> truthVals;
     vector<string> exp;
};