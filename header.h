#ifndef HEADER
#define HEADER

#include <vector>

using namespace std;

int getInput();
void initTable(int n, vector<vector<int>> &Table);
void printTable(vector<vector<int>> Table);
void initSet(int CX[], int CY[]);   // initialize production set (possible moves of horse)

#endif