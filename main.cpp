#include "header.h"

using namespace std;

int main(){
    int n, x, y;    // n - size of n*n array. x, y = starting position coordinates
    long unsigned int numOfTries=0;

    vector<vector<int>> Table;
    int CX[8];
    int CY[8];
    initSet(CX, CY);
    
    interface(&n, &x, &y, Table, CX, CY, &numOfTries);
    
    return 0;
}