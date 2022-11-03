#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// This function generates random number
int * GenerateRandomNumbers( int N ) ;

// Sequential Quick Sort Algorithm
void Sort( int * A, int l, int h ) ;


// Partition function, called by the sequential quick sort algorithm function SeqQuickSort()
int Partition( int * A, int l, int h ) ;

// This function swaps two entries in the array. This will be used in the partitioning step
void Swap( int * A, int * B ) ;

// This function checks if the array is sorted or not
bool IsSorted( int * A, int N ) ;
void Display( bool IsSorted, double t, int N ) ;

int main (int argc, char *argv[])
{
    int N, * A ;
    double t ;
    
    // The input size of the array must be entered
    if( argc < 2 )
        printf("\033[1;31m \nERROR: MISSING COMMAND LINE ARGUMENTS \nFORMAT: ./Par <N> \n\n \033[0m") ;
    else {
        // Record the input size
        N = atoi(argv[1]) ;
        // Generate N random numbers
        A = GenerateRandomNumbers(N) ;
        // Start the clock
        t = clock() ;
        // Sort the array using quick sort
        Sort(A,0,N-1) ;
        // End the clock and record the execution time
        t = ((double) (clock() - t)) / CLOCKS_PER_SEC ;
        // Display the results
        Display(IsSorted(A,N),t,N) ;
    }
    
    return 0 ;
}

// This function generates random number
int * GenerateRandomNumbers( int N )
{
    int i ;
    int * A = (int *) malloc(sizeof(int)*N) ;
    for( i = 0 ; i < N ; i++ )
        A[i] = rand()%N ;
    return A ;
}

void Sort( int * A, int l, int h )
{
    if( l < h ){
        int P = Partition(A,l,h) ;
        Sort(A,l,P-1) ;
        Sort(A,P+1,h) ;
    }
}

// Partition function, called by the sequential quick sort algorithm function SeqQuickSort()
int Partition( int * A, int l, int h )
{
    int j, i = l-1, P = A[h] ;
    for ( j = l; j <= h-1; j++ ) {
        if (A[j] < P){
            i++ ;
            Swap(&A[i], &A[j]) ;
        }
    }
    Swap(&A[i+1], &A[h]) ;
    return i+1 ;
}

// This function swaps two entries in the array. This will be used in the partitioning step
void Swap( int * A, int * B )
{
    int T = *A ;
    *A = *B ;
    *B = T ;
}

// This function checks if the array is sorted or not
bool IsSorted( int * A, int N )
{
    int i ;
    for( i = 0 ; i < N-1 ; i++ ){
        if( A[i] > A[i+1] )
            return false ;
    }
    return true ;
}

// This function is responsible for displaying final results: Execution Time - Was the array sorted or not ?
void Display( bool IsSorted, double t, int N )
{
    printf("\n------------------------------------\n") ;
    printf("\033[1;36mInput Size = %d \n\033[0m", N) ;
    if( IsSorted )
        printf("\033[1;32mArray Is Sorted ✓\n\033[0m") ;
    else
        printf("\033[1;31mArray Is Not Sorted X\n\033[0m") ;
    printf("\033[1;31mExecution Time = %lf seconds \n\033[0m", t ) ;
    printf("------------------------------------\n\n") ;
}
