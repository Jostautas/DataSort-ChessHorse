#include "header.h"

using namespace std;

int main(){
    int n, x, y;
    long unsigned int numOfTries=0;
    //n = getN();
    

    //printStartingData(n, x, y);

    vector<vector<int>> Table;
    int CX[8];
    int CY[8];
    
    
    //printTable(Table);
    

    interface(&n, &x, &y, Table, CX, CY, &numOfTries);
    
    /*
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

    }*/
    
    return 0;
}