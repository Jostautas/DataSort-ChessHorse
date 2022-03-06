#include "header.h"
#include <stdio.h>
#include <vector>

using namespace std;

int getInput(){
    int n;
    printf("Enter table size N\n");

    while(1){
        if((scanf("%d", &n) == 1) && (n > 2)){
            printf("Great success, %d\n", n);
            break;
        }
        else{
            printf("Error: Enter a correct integer greater than 2\n");
            while(getchar() != '\n');
        }
    }
    return n;
}
void initTable(int n, vector<vector<int>> &Table){
    vector<int> TableY;
    for(int i = 0; i < n; i++){
        TableY.push_back(0);
    }
    for(int i = 0; i < n; i++){
        Table.push_back(TableY);
    }
}
void printTable(vector<vector<int>> Table){
    for(unsigned int i = 0; i < Table.size(); i++){
        for(unsigned int j = 0; j < Table[i].size(); j++){
            printf("%d ", Table[i][j]);
        }
        printf("\n");
    }
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
// l - number of current step
void go(int n, vector<vector<int>> &Table, int l){

}