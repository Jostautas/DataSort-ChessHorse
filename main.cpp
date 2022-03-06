#include "header.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, nn; // n - size of n*n board. nn = n*n
    vector<vector<int>> Table;
    int CX[8];
    int CY[8];

    n = getInput();
    nn = n*n;
    initTable(n, Table);
    printTable(Table);
    initSet(CX, CY);

    if(go(n, Table, 2, 1, 1, CX, CY, nn) == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", Table[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("ERROR - does not exist\n");
    }
    
    return 0;
}