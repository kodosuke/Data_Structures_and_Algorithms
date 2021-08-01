#include <stdio.h>
#include <conio.h>

void bubbleSort(int nums[], int size);
void swap(int *m, int *n);
void print(int nums[], int size);


int main() {

    int nums[] = {10, 9, 7, 101, 23, 44, 12, -4, 78, 34, 23}; 
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Unsorted array :\n\t");
    print(nums, size);

    bubbleSort(nums, size);

    printf("Sorted array :\n\t");
    print(nums, size);

    return 0;

}


void bubbleSort(int nums[], int size) {

    for(int step = 0; step < size; step++) {

        for(int i = 0; i < size - step - 1; i++) {

            if(nums[i] > nums[i + 1]) swap(&nums[ i ], &nums[ i + 1 ]);
        }        
    }
}

void swap(int *m, int *n) {

    int t;

    t  = *m;
    *m = *n;
    *n = t;
}


void print(int nums[], int size) {

    for(int  i = 0; i < size; i++)      printf("%d ", nums[i]);
    printf("\n");
}