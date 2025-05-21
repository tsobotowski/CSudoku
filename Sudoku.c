#include <stdio.h>
#include <stdlib.h>

#define size 9

int board[size][size] = {0};

int checkX(int y, int value){
    printf("Checking x\n");
    for(int x = 0; x < 9; x++){
        printf("%d, %d\n", board[x][y], value);
        if(board[x][y] == value){
            printf("Duplicate found in current row");
            return 1;
        }
    }
    return 0;
}

int checkY(int x, int value){
    printf("Checking y\n");
    for(int y = 0; y < 9; y++){
        printf("%d, %d\n", board[x][y], value);
        if(board[x][y] == value){
            printf("Duplicate found in current column");
            return 1;
        }
    }
    return 0;
}

int checkSquare(int x, int y, int value){
    printf("Checking square\n");

    int xGrid;
    int yGrid;

    /*Calculate the coordinates of the top left item in the grid*/
    xGrid = 3 * ((x - 1) / 3);
    yGrid = 3 * ((y - 1) / 3);

    printf("X: %d Y: %d\n", xGrid, yGrid);

   for(int i = xGrid - 1; i < xGrid + 3; i++){
       for(int j = yGrid - 1; j < yGrid + 3; j++){
        printf("%d, %d\n", board[i][j], value);
        if(board[i][j] == value){
            printf("Duplicate found in current square");
            return 1;
        }
   }
}
return 0;
}

/*Check if a value is duplicated, return 0 if duplicated*/
int checkValue(int x, int y, int value){

    if((checkX(x, value) || checkY(y, value) || checkSquare(x, y, value))){
        return 0;
    }
    return 1;
}

/*Prints the game board to the terminal*/
void printBoard() {
    printf("\n"); // Start with a newline for cleaner display
    for (int i = 0; i < size; i++) {
        if (i % 3 == 0) {
            printf("+-------+-------+-------+\n");
        }
        
        for (int j = 0; j < size; j++) {
            if (j % 3 == 0) {
                printf("| ");
            }
            
            // Display the value (or space if 0)
            if (board[j][i] == 0) {
                printf("  ");
            } else {
                printf("%d ", board[j][i]);
            }
        }
        printf("|\n"); // End the line with a border
    }
    printf("+-------+-------+-------+\n"); // Bottom border
}


int main()
{
    printBoard();
    while(1){
        printf("Enter a value to add to the board:\n");
        fflush(stdout);
        char selection[256];
        fgets(selection, 256, stdin);
        int val = atoi(selection);

        printf("Enter an x value:\n");
        fflush(stdout);
        char xChar[3];
        fgets(xChar, 3, stdin);
        int x = atoi(xChar);

        printf("Enter a y value:\n");
        fflush(stdout);
        char yChar[3];
        fgets(yChar, 3, stdin);
        int y = atoi(yChar);

        if(checkValue(x-1, y-1, val)){
            printf("Write value: %d:", val);
            board[x-1][y-1] = val;
        }
        printBoard();
    }

}
