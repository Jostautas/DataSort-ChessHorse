#ifndef HEADER
#define HEADER

#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

int getN();
int getCoordinate(char coord, int n);
void printStartingData(int n, int x, int y);
void initTable(int n, vector<vector<int>> &Table, int x, int y);
void printTable(vector<vector<int>> Table);
void initSet(int CX[], int CY[]);   // initialize production set (possible moves of horse)

// iter - iteration, number of current step
int go(int n, vector<vector<int>> &Table, int iter, int x, int y, int CX[], int CY[], int nn, long unsigned int *numOfTries);

#endif