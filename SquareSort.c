#include <stdio.h>
#include <stdlib.h>

// [PARAM] Single digits input only

#define inputSizeMax 64

int * ArrayInput( char inputString[], int * inputSize );
int SquareInputs( int inputNumber );
void SortSquares( int inputArray[], int inputSize );
void PrintArray( int inputArray[], int inputSize, char infoLine[] );

int main () {
    
    FILE * filePointer;
    char inputString[inputSizeMax];
    char outgoingLine[] = "[INFO ] Sorted Sqaures -> [";
    int * incomingArray;
    int inputSize = 0;

    // Allows for print/scan to function in order
    setbuf(stdout, NULL);
    
    // String Clean
    for ( int i = 0; i < inputSizeMax; i++ ) {
        inputString[i] = 0;
    } int i = 0;

    // Data Input
    filePointer = fopen( "../input.txt", "r" );
    fscanf( filePointer, "%[^\n]", inputString );

    // Main Operation
    incomingArray = ArrayInput( inputString, &inputSize );
    SortSquares( incomingArray, inputSize );
    PrintArray( incomingArray, inputSize, outgoingLine );

    return 0;
}

/*
    Array Input
    Params: inputString : Raw string pulled from input file
            inputSize   : Pointer to variable to track amount of inputs
    Output: Pointer     : Points to start of int array containing inputs
*/
int * ArrayInput( char inputString[], int * inputSize ) {
    int * inputArray;
    int i = 0;
    while ( inputString[i] != 0 ) {
        switch ( inputString[i] ) {
            case 48 ... 57:
                inputArray[*inputSize] = SquareInputs( inputString[i] - 48 );
                (*inputSize)++;
                break;
            default:
                break;
        }
        i++;
    }

    return inputArray;
}

/*
    Square Inputs
    Params: inputNumber : Int of number desired to square
    Output: Integer     : Square of the given number
*/
int SquareInputs ( int inputNumber ) {
    return (inputNumber * inputNumber);
}

/*
    Sort Squares
    Params: inputArray  : Int Array of given values to sort through
            inputSize   : Variable amount used to track amount of inputs
    Output: NONE
    Notes : Utilizes Bubble Sort, which is not the most effecient. Could move to Merge Sort in future.
*/
void SortSquares( int inputArray[], int inputSize ) {
    int tempSwap;
    for(int i = inputSize-1; i >= 0; i-- ) {
        for( int j = 0; j < i; j++ ) {
            if( inputArray[j] > inputArray[j+1] ) {
                tempSwap = inputArray[j];
                inputArray[j] = inputArray[j+1];
                inputArray[j+1] = tempSwap;
            }
        }
    }
}

/*
    Print Array
    Params: inputArray  : Int Array of given values to print through
            inputSize   : Variable amount used to track amount of inputs
            infoLine    : String used to setup which type of output this would be for
    Output: NONE        : Not entirely true. Prints to screen the given array
    Notes : infoLine is redundent as the current flow of program prevents output of initial array with this function.
*/
void PrintArray( int inputArray[], int inputSize, char infoLine[] ) {
    printf( "%s%d", infoLine, inputArray[0] );
    for( int i = 1; i < inputSize; i++ ) {
        printf( ", %d", inputArray[i] );
    } printf( "]\n" );
}