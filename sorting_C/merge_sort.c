#include<stdlib.h>
#include<stdio.h>

  /* Function to print an array */
 void printArray(int A[], int size)
 {
     int i;
     for (i=0; i < size; i++)
         printf("%d ", A[i]);
     printf("\n");
 }

/* this function merge two sorted arrays into a single sorted
** array. */
void MergeArray(int left[], int n1, int right[], int n2)
{
    int i=0, j=0;

    int* merge_result = (int *) malloc((n1+n2)*sizeof(int));
    
    // Merge the temp arrays back into arr[l..r]
    while (i < n1 || j < n2)
    {
        if (i < n1 && (j >= n2 || left[i] <= right[j]))
        {
            merge_result[i+j] = left[i];
            i++;
        }
        else
        {
            merge_result[i+j] = right[j];
            j++;
        }
    }
    
    // copy the data back to original array
    for (int i = 0; i < n1; i++)
    {
        left[i] = merge_result[i];
    }
    // copy the data back to original array
    for (int i = n1, j = 0; i < (n1+n2); i++, j++)
    {
        right[j] = merge_result[i];
    }
    
    // free heap memory
    free(merge_result);
}

/* this sorting method is a O(nlogn) time complexity sorting
** algorithm. the main array is divided into two equal (unequal)
** halves and those are sorted first and then merged to get a
** new sorted array. the main function calls itself recursively
** to sort the divided arrays and then merge to get a single
** sorted array. */
void MergeSortArray(int arr[], int size)
{
    if (size <= 1)
      return;

    int mid = size/2;

    // calling mergeSort() function recursively to sort
    // the new smaller arrays.
    MergeSortArray(arr, mid);
    MergeSortArray(arr+mid, size-mid);
    
    // after two halves are sorted, merge them to get a
    // single merged sorted array
    MergeArray(arr, mid, arr+mid, size-mid);
}

/* Driver program to test above functions */
int main(int argc, const char * argv[])
{
    int arr[] = {12, 11, 13, 6, 5, 7, -3, 14, -32, 25, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    MergeSortArray(arr, arr_size);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
