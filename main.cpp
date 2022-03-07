#include "header.h"

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
        printTable(Table);
    }
    else{
        printf("ERROR - solution does not exist\n");
    }
    
    return 0;
}