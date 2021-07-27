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


int findkthSmallest( int array[], int left, int right, int k)
{
    if ( k > 0 && k <= right - left + 1)
    {
        int pivotIndex = partition( array, left, right );

        if ( pivotIndex - left == k - 1)    return array[ pivotIndex ];
        if ( pivotIndex - left > k - 1 )    return findkthSmallest( array, left, pivotIndex - 1, k);
        else
            return findkthSmallest( array, pivotIndex + 1, right, k - pivotIndex + left - 1);
    }
    return __INT_MAX__;
}


// Print
void print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };

    int size = sizeof(arr) / sizeof(arr[0]);

    int k = rand() % size;

    printf("The elements of array are, \n");
    print(arr, size);

    printf("kth ( %d th ) smallest element is %d ",k, findkthSmallest(arr, 0, size - 1, k));
    
    return 0;
}