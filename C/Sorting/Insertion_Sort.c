#include <stdio.h>
#include <conio.h>

void insertionSort(int nums[], int size);
void print(int nums[], int size);

int main()
{

    int nums[] = {10, 9, 7, 101, 23, 44, 12, -4, 78, 34, 23}; 
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Unsorted array :\n\t");
    print(nums, size);

    insertionSort(nums, size);

    printf("Sorted array :\n\t");
    print(nums, size);

    return 0;

}

void insertionSort(int nums[], int size) {

    for( int step = 0; step < size; step++ ) {

        int key = nums[ step ];
        int i   = step - 1;

        while( nums[i] > key && i >= 0 ) {
            nums[i + 1] = nums[i];
            --i; 
        } 

        nums[i + 1] = key;
    }

}


// Print
void print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
