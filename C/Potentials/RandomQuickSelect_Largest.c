# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

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


int randomizedPartition( int array[], int left, int right)
{
    int randIndex = (rand() % ( right - left + 1))+ left ;

    swap( &array[randIndex], &array[ right ] );

    return partition(array, left, right );

}


int findkthLargest( int array[], int size, int k)
{
    int left = 0;
    int right = size - 1;

    while ( left < right )
    {
        int pivotIndex = randomizedPartition( array, left, right);

        if ( pivotIndex == size - k)    return array[ pivotIndex ];
        else {

            if ( pivotIndex < size - k )    left = pivotIndex + 1;
            else    right = pivotIndex - 1;
        }
    }
    return __INT_MAX__;
}


void print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main()
{
    int array[] = { 3,2,1,5,6,4 };

    int size = sizeof(array) / sizeof(array[0]);

    int k = rand() % size;

    printf("The elements of array are, \n");
    print(array, size);

    printf("kth ( %d th ) largest element is %d ",k, findkthLargest(array, size, k));
    
    return 0;
}