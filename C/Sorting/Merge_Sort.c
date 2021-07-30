# include <stdio.h>
# include <conio.h>

void mergeSort(int nums[], int leftStart, int rightEnd);
void print(int array[], int size);
void mergeHalves(int nums[], int leftStart, int mid, int rightEnd);

int main() {

    int nums[] = {10, 9, 7, 101, 23, 44, 12, 78, 34, 23}; 
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Unsorted Array : ");
    print(nums, size);

    mergeSort(nums, 0, size - 1);

    printf("Sorted Array : ");
    print(nums, size);

    return 0;

}

 
void mergeSort(int nums[], int leftStart, int rightEnd) {

    int mid;

    if(leftStart < rightEnd) {

        mid = leftStart + (rightEnd - leftStart) / 2;

        mergeSort(nums, leftStart, mid);
        mergeSort(nums, mid + 1, rightEnd);

        mergeHalves(nums, leftStart, mid, rightEnd);
    }

} 


void mergeHalves(int nums[], int leftStart, int mid, int rightEnd) {

    int leftEnd    = mid;
    int rightStart = mid + 1;

    int m = leftEnd - leftStart + 1;
    int n = rightEnd - rightStart + 1;

    int left[ m ];
    int right[ n ];

    int index = rightStart;

    for(int i = 0; i < m; i++ ) {
        left[i] = nums[ leftStart + i];
    }

    for(int j = 0; j < n; j++ ) {
        right[j] = nums[ rightStart + j];
    }

    int i = 0;
    int j = 0;
    int k = leftStart;

    while (i < m && j < n) {
        if (left[i] <= right[j])    nums[k++] = left[i++];
        else                        nums[k++] = right[j++];
    }

    while(i < m)    nums[k++] = left[i++];
    while(j < n)    nums[k++] = right[j++];    
    
}    


void print(int array[], int size) {

  for (int i = 0; i < size; ++i) {

    printf("%d  ", array[i]);
  }
  printf("\n");
}
