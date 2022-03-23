#ifndef HEADER
#define HEADER

#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void interface(int *n, int *x, int *y, vector<vector<int>> Table, int CX[], int CY[], long unsigned int *numOfTries);
int getN();
int getCoordinate(char coord, int n);
void printStartingData(int n, int x, int y, ostream &outShort, ostream &outFull);
void initTable(int n, vector<vector<int>> &Table, int x, int y);
void printTable(vector<vector<int>> Table, ostream &outShort, ostream &outFull);
void initSet(int CX[], int CY[]);   // initialize production set (possible moves of horse)

void execution(int n, vector<vector<int>> Table, int x, int y, int CX[], int CY[], long unsigned int *numOfTries, ostream &outShort, ostream &outFull);

// iter - iteration, number of current step
int go(int n, vector<vector<int>> &Table, int iter, int x, int y, int CX[], int CY[], long unsigned int *numOfTries, ostream &outFull);

#endif