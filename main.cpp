#include "header.h"

using namespace std;

int main(){
    int n;
    n = getInput();
    int nn = n*n;   // n - size of n*n board. nn = n*n

    vector<vector<int>> Table;
    int CX[8];
    int CY[8];
    
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