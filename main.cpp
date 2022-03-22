#include "header.h"

using namespace std;

int main(){
    int n;
    long unsigned int numOfTries=0;
    n = getN();
    int nn = n*n;   // n - size of n*n board. nn = n*n

    int x = getCoordinate('X', n);
    int y = getCoordinate('Y', n);

    printStartingData(n, x, y);

    vector<vector<int>> Table;
    int CX[8];
    int CY[8];
    
    initTable(n, Table, x, y);
    printTable(Table);
    initSet(CX, CY);
    
    printf("PART 2. Execution\n");
    if(go(n, Table, 2, x, y, CX, CY, nn, &numOfTries) == 1){
        printf("\nPART 3. Results\n");
        printf("1) Solution found. Number of tries = %ld\n", numOfTries);
        printf("2) graphical solution:\n");
        printTable(Table);
    }
    else{
        printf("THIRD PART. Results\n");
        printf("Solution does not exist\n");
        printf("Number of tries = %ld\n", numOfTries);

    }
    
    return 0;
}