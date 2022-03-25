#include "header.h"

using namespace std;

void interface(int *n, int *x, int *y, vector<vector<int>> Table, int CX[], int CY[], long unsigned int *numOfTries){
    printf("press a specified number to select a menu entry\n");
    printf("1. Enter custom size of board and starting position\n");
    printf("2. Run 7 test cases\n");

    int ch;
    while(1){
        if((scanf("%d", &ch) == 1) && (ch >= 1) && (ch <= 2)){
            if(ch == 1){
                *n = getN();
                *x = getCoordinate('X', *n);
                *y = getCoordinate('Y', *n);
                initTable(*n, Table, *x, *y);
                
                ofstream outShort;
                outShort.open("out-short.txt");
                ofstream outFull;
                outFull.open("out-full.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);
                
                outShort.close();
                outFull.close();
            }
            else if(ch == 2){
                //1:
                *n = 5; *x = 1; *y = 1;
                initTable(*n, Table, *x, *y);
                ofstream outShort;
                outShort.open("out-short_1test.txt");
                ofstream outFull;
                outFull.open("out-full_1test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();
                
                //2:
                Table.clear();
                *n = 5; *x = 5; *y = 1;
                initTable(*n, Table, *x, *y);
                outShort.open("out-short_2test.txt");
                outFull.open("out-full_2test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();

                //3:
                Table.clear();
                *n = 5; *x = 1; *y = 5;
                initTable(*n, Table, *x, *y);
                outShort.open("out-short_3test.txt");
                outFull.open("out-full_3test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();

                //4:
                Table.clear();
                *n = 5; *x = 2; *y = 1;
                initTable(*n, Table, *x, *y);
                outShort.open("out-short_4test.txt");
                outFull.open("out-full_4test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();
/*
                //5:
                Table.clear();
                *n = 6; *x = 1; *y = 1;
                initTable(*n, Table, *x, *y);
                outShort.open("out-short_5test.txt");
                outFull.open("out-full_5test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();

                //6:
                Table.clear();
                *n = 7; *x = 1; *y = 1;
                initTable(*n, Table, *x, *y);
                outShort.open("out-short_6test.txt");
                outFull.open("out-full_6test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();

                //7:
                Table.clear();
                *n = 4; *x = 1; *y = 1;
                initTable(*n, Table, *x, *y);
                outShort.open("out-short_7test.txt");
                outFull.open("out-full_7test.txt");
                printStartingData(*n, *x, *y, outShort, outFull);
                execution(*n, Table, *x, *y, CX, CY, numOfTries, outShort, outFull);

                *numOfTries = 0;
                outShort.close();
                outFull.close();*/
            }
            break;
        }
        else{
            printf("Error: Enter a correct integer value\n");
            while(getchar() != '\n');
        }
    }
}
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
void printStartingData(int n, int x, int y, ostream &outShort, ostream &outFull){
    printf("PART 1. Starting data\n");
    printf("1) Table %dx%d.\n", n, n);
    printf("2) Starting possition X=%d, Y=%d. Iteration=1\n", x, y);

    outShort << "PART 1. Starting data" << endl;
    outShort << "1) Table " << n << "x" << n << "." << endl;
    outShort << "2) Starting possition X=" << x << ", Y=" << y << ". Iteration = 1" << endl;

    outFull << "PART 1. Starting data" << endl;
    outFull << "1) Table " << n << "x" << n << "." << endl;
    outFull << "2) Starting possition X=" << x << ", Y=" << y << ". Iteration = 1" << endl;
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
void printTable(vector<vector<int>> Table, ostream &outShort, ostream &outFull){
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


    outShort << "Y, v^" << endl;
    for(int i = Table.size()-1; i >= 0; i--){
        outShort << "  " << i+1 << " | ";
        for(unsigned int j = 0; j < Table[i].size(); j++){
            outShort << setw(3) << Table[j][i] << " ";
        }
        outShort << endl;
    }
    outShort << "    ----------------------------> X, U " << endl << "     ";
    for(unsigned int i = 1; i <= Table.size(); i++){
        outShort << "   " << i;
    }
    outShort << endl;


    outFull << "Y, v^" << endl;
    for(int i = Table.size()-1; i >= 0; i--){
        outFull << "  " << i+1 << " | ";
        for(unsigned int j = 0; j < Table[i].size(); j++){
            outFull << setw(3) << Table[j][i] << " ";
        }
        outFull << endl;
    }
    outFull << "    ----------------------------> X, U " << endl << "     ";
    for(unsigned int i = 1; i <= Table.size(); i++){
        outFull << "   " << i;
    }
    outFull << endl;
}
void printStep(long unsigned int numOfTries, int iter, int retry, int x, int y, string state, ostream &outFull){
    char Char[20];
    for(long unsigned int i = 0; i < sizeof(state); i++)
    {
        Char[i] = state[i];
    }

    outFull << numOfTries << ") ";
    for(int i = 0; i < iter-2; i++){
        outFull << "-";
    }
    outFull << "R" << retry << ". U=" << x << ", V=" << y << ". Iteration=" << iter << ". " << Char;

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
void execution(int n, vector<vector<int>> Table, int x, int y, int CX[], int CY[], long unsigned int *numOfTries, ostream &outShort, ostream &outFull){
    outFull << "PART 2. Execution" << endl;

    if(go(n, Table, 2, x, y, CX, CY, numOfTries, outFull) == 1){
        printf("\nPART 3. Results\n");
        printf("1) Solution found. Number of tries = %ld\n", *numOfTries);
        printf("2) graphical solution:\n");

        outShort << endl << "PART 3. Results" << endl;
        outShort << "1) Solution found. Number of tries = " << *numOfTries << endl;
        outShort << "2) graphical solution:" << endl;

        outFull << endl << "PART 3. Results" << endl;
        outFull << "1) Solution found. Number of tries = " << *numOfTries << endl;
        outFull << "2) graphical solution:" << endl;

        printTable(Table, outShort, outFull);
    }
    else{
        printf("\nPART 3. Results\n");
        printf("Solution does not exist\n");
        printf("Number of tries = %ld\n", *numOfTries);

        outShort << endl << "PART 3. Results" << endl;
        outShort << "Solution does not exist" << endl;
        outShort << "Number of tries = " << *numOfTries << endl;

        outFull << endl << "PART 3. Results" << endl;
        outFull << "Solution does not exist" << endl;
        outFull << "Number of tries = " << *numOfTries << endl;
    }
}
int go(int n, vector<vector<int>> &Table, int iter, int x, int y, int CX[], int CY[], long unsigned int *numOfTries, ostream &outFull){
    int newX, newY, out=0, retry=1;
    for(int i = 0; i < 8; i++){
        ++*numOfTries;
        newX = x + CX[i];
        newY = y + CY[i];
        
        outFull << endl;
        if((newX >= 1) && (newX <= n) && (newY >= 1) && (newY <= n)){
            if(Table[newX-1][newY-1] == 0){
                printStep(*numOfTries, iter, retry, newX, newY, "Empty", outFull);
                outFull << ". TABLE[" << newX << "," << newY << "]=" << iter;

                Table[newX-1][newY-1] = iter;

                if(iter < n*n){
                    
                    out = go(n, Table, iter+1, newX, newY, CX, CY, numOfTries, outFull);
                    if(out != 1){
                        Table[newX-1][newY-1] = 0;
                        outFull << ". Backtrack";
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
                printStep(*numOfTries, iter, retry, newX, newY, "Taken", outFull);

            }
        }
        else{
            printStep(*numOfTries, iter, retry, newX, newY, "Out of bounds", outFull);
        }
        retry++;
    }
    return 0;
}