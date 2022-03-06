#include "header.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<vector<int>> Table;
    int CX[8];
    int CY[8];

    n = getInput();
    initTable(n, Table);
    printTable(Table);
    initSet(CX, CY);
    
    return 0;
}