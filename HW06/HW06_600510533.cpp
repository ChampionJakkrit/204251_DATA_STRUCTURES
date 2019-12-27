#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[10000];
int temp[10000];
int max_input, num_input, func_input, func_input2;

void Binary_search(int max_input);
void sequential_search(int z);
void Sort_by_asc(int arr[], int lift, int right);
void Sort_by_desc();
void Binary_search_max(int z);


int main()
{
    int state = 0; // set ค่า

    scanf("%d", &max_input);
    for (int i = 0; i < max_input; i++) {
        scanf("%d", &num_input);
        ary[i] = num_input;
        }
    while (func_input != 4) {
        scanf("%d", &func_input);
        if (func_input == 1) {
            scanf("%d", &func_input2);
            if (state == 0) {
                sequential_search(func_input2); // ค้นหาไม่เรียง
            }
            else if (state == -1) {
                Binary_search(func_input2); // ค้นหาเรียงน้อยไปมาก
            }
            else {
                Binary_search_max(func_input2); // ค้นหาเรียงมากไปน้อย
            }
        }
        else if (func_input == 2) {
            state = -1;
            Sort_by_asc(ary, 0, max_input - 1);
            for (int i = 0; i < max_input; i++) {
                printf("%d ", ary[i]);
            }
            printf("\n");
        }
        else if (func_input == 3) {
            state = 1;
            Sort_by_asc(ary, 0, max_input - 1);
            Sort_by_desc();
        }
    }
    return 0;
}

void Binary_search(int z)
{
    int low = 0;
    int high = max_input - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (z == ary[mid]) {
            printf("%d\n", (mid + 1));
            return;
        }
        else {
            if (z < ary[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    printf("no\n");
    return;
}

void Binary_search_max(int z)
{
    int low = 0;
    int high = max_input - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (z == ary[mid]) {
            printf("%d\n", (mid + 1));
            return;
        }
        else {
            if (ary[mid] < z)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    printf("no\n");
    return;
}

void sequential_search(int z)
{
    for (int i = 0; i < max_input; i++) {
        if (z == ary[i]) {
            printf("%d\n", i + 1);
            return;
        }
    }
    printf("no\n");
}

void merge(int arr[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void Sort_by_asc(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = left+(right-left) / 2; 
  
        // Sort first and second halves 
        Sort_by_asc(arr, left, mid); 
        Sort_by_asc(arr, mid + 1, right); 
  
        merge(arr, left, mid, right); 
    } 
} 

void Sort_by_desc()
{
    int ary_reverse[10000];
    for (int i = 0; i < max_input; i++) {
        ary_reverse[i] = ary[max_input - i - 1];
    }
    for (int i = 0; i < max_input; i++) {
        ary[i] = ary_reverse[i];
    }

    for (int i = 0 ; i <= max_input - 1; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");
    return;
}
