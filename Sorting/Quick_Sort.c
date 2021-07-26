# include <stdio.h>
# include <conio.h>


void swap( int *m, int *n)
{
    int t;

     t = *m;
    *m = *n;
    *n = t;

}


int partition( int array[], int left, int right )
{
    int pivot = array[ right ];

    int i = left - 1;

    for ( int j = left; j < right; j++ )
    {
        if ( array[ j ] <= pivot )
        {
            i ++ ;
            swap(&array[i], &array[j]);
        }
    } 
    swap(&array[ i + 1 ], &array[ right ]);

    return i + 1;
}


void quickSort(int array[], int left, int right)
{
    if( left < right )
    {
        int pivotIndex = partition( array, left, right );

        quickSort( array, left, pivotIndex - 1  );
        quickSort( array, pivotIndex + 1, right );
    }
}

// Print
void print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver Code
int main()
{
    int array[] = {8, 7, 2, 1, 0, 9, 6};

    int size = sizeof(array) / sizeof(array[0]);

    printf("Unsorting Array : \n");
    print(array, size);

    quickSort(array, 0, size - 1);

    printf("Sorted Array :\n");
    print(array, size);

    return 0;
}