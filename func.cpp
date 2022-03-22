#include "header.h"

using namespace std;

int getN(){
    int n;
    printf("Enter table size N\n");

    while(1){
        if((scanf("%d", &n) == 1) && (n > 2)){
            break;
        }
        else{
            printf("Error: Enter a correct integer greater than 2\n");
            while(getchar() != '\n');
        }
    }
    return n;
}
int getCoordinate(char coord, int n){
    int x;
    printf("Enter starting %c coordinate\n", coord);

    while(1){
        if((scanf("%d", &x) == 1) && (x >= 1) && (x <= n)){
            break;
        }
        else{
            printf("Error: Enter a correct possitive integer\n");
            while(getchar() != '\n');
        }
    }
    return x;
}
void printStartingData(int n, int x, int y){
    printf("PART 1. Starting data\n");
    printf("1) Table %dx%d.\n", n, n);
    printf("2) Starting possition X=%d, Y=%d. Iteration=1\n", x, y);
}
void initTable(int n, vector<vector<int>> &Table, int x, int y){
    vector<int> TableY;
    //  TableY is a vertical component of the Table
    for(int i = 0; i < n; i++){
        TableY.push_back(0);
    }
    for(int i = 0; i < n; i++){
        Table.push_back(TableY);
    }
    Table[x-1][y-1] = 1;
}
void printTable(vector<vector<int>> Table){
    printf("Y, v^\n");
    for(int i = Table.size()-1; i >= 0; i--){
        printf("  %d | ", i+1);
        for(unsigned int j = 0; j < Table[i].size(); j++){
            printf("%3d ", Table[j][i]);
        }
        printf("\n");
    }
    printf("    ----------------------------> X, U\n     ");
    for(unsigned int i = 1; i <= Table.size(); i++){
        printf("   %d", i);
    }
    printf("\n");
}
void printStep(long unsigned int numOfTries, int iter, int retry, int x, int y, string state){
    char Char[20];
    for(long unsigned int i = 0; i < sizeof(state); i++)
    {
        Char[i] = state[i];
    }

    printf("%ld) ", numOfTries);
    for(int i = 0; i < iter-2; i++){
        printf("-");
    }
    printf("R%d. U=%d, V=%d. Iteration=%d. %s", retry, x, y, iter, Char);

}
void initSet(int CX[], int CY[]){
    CX[0] = 2;  CY[0] = 1;
    CX[1] = 1;  CY[1] = 2;
    CX[2] = -1; CY[2] = 2;
    CX[3] = -2; CY[3] = 1;
    CX[4] = -2; CY[4] = -1;
    CX[5] = -1; CY[5] = -2;
    CX[6] = 1;  CY[6] = -2;
    CX[7] = 2;  CY[7] = -1;
}
int go(int n, vector<vector<int>> &Table, int iter, int x, int y, int CX[], int CY[], int nn, long unsigned int *numOfTries){
    int newX, newY, out=0, retry=1;
    for(int i = 0; i < 8; i++){
        ++*numOfTries;
        newX = x + CX[i];
        newY = y + CY[i];
        //printf("iteration = %d\n", iter);
        //printf("coordinates = %d %d\n", newX, newY);
        
        printf("\n");
        if((newX >= 1) && (newX <= n) && (newY >= 1) && (newY <= n)){
            if(Table[newX-1][newY-1] == 0){
                printStep(*numOfTries, iter, retry, newX, newY, "Empty");
                printf(". TABLE[%d,%d]=%d", newX, newY, iter);
                Table[newX-1][newY-1] = iter;

                if(iter < nn){
                    
                    out = go(n, Table, iter+1, newX, newY, CX, CY, nn, numOfTries);
                    if(out != 1){
                        Table[newX-1][newY-1] = 0;
                    }
                    if(out == 1){
                        return 1;
                    }
                    
                }
                else{
                    return 1;
                }
            }
            else{
                printStep(*numOfTries, iter, retry, newX, newY, "Taken");

            }
        }
        else{
            printStep(*numOfTries, iter, retry, newX, newY, "Out of bounds");
        }
        retry++;
    }
    return 0;
}