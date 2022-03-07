#ifndef HEADER
#define HEADER

#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

int getInput();
void initTable(int n, vector<vector<int>> &Table);
void printTable(vector<vector<int>> Table);
void initSet(int CX[], int CY[]);   // initialize production set (possible moves of horse)
int go(int n, vector<vector<int>> &Table, int iter, int x, int y, int CX[], int CY[], int nn);

#endif