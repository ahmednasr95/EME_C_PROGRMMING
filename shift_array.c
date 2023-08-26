#include <stdio.h>

#define Size 6

/*
    Inputs: array size and array reference
    Output: None
    Description: Prints the given array to the
    terminal.
*/
void printArray(int arrSize, int *arr)
{
    for (int i = 0; i < arrSize; ++i)
    {
        printf("%d, ", arr[i]);
    }
}

/*
    Inputs: array size, array reference, number of shifts
    Output: None
    Description: If k is positive, shift the array to the right 
    k times. If k is negative, shift the array to the left
    k times. Follows the classical approach of nested loops.
*/
void classic_shiftArray(int arrSize, int *arr, int k)
{
    int i = 0;
    int j = 0;
    /*to prevent too many unnecessary shifts*/
    k = k % arrSize;
    /*shift to the right*/
    if (0 < k)
    {
        j = arrSize - 1;
        i = j - 1;
        while (0 < k)
        {
            /*swap each two adjacent numbers*/
            while (0 <= i)
            {
                arr[i] ^= arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
                --i;
                --j;
            }
            j = arrSize - 1;
            i = j - 1;
            /*repeat the above k times*/
            --k;
        }
        printArray(arrSize, arr);
    }
    /*shift to the left*/
    else if (0 > k)
    {
        i = 0;
        j = i + 1;
        k *= -1;
        while (0 < k)
        {
            /*swap each two adjacent numbers*/
            while (arrSize > j)
            {
                arr[i] ^= arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
                ++i;
                ++j;
            }
            i = 0;
            j = i + 1;
            /*repeat the above k times*/
            --k;
        }
        printArray(arrSize, arr);
    }
    /*if k is zero*/
    else
    {
        printArray(arrSize, arr);
    }
}

/*
    Inputs: array size, array reference, number of shifts
    Output: None
    Description: If k is positive, shift the array to the right
    k times. If k is negative, shift the array to the left
    k times. Follows an optimized approach using three loops.
*/
void optimized_shiftArray(int arrSize, int *arr, int k)
{
    /*to prevent too many unnecessary shifts*/
    if (0 > k)
    {
        k = (k % arrSize) + arrSize;
    }
    else
    {
        k = (k % arrSize);
    }
    int l = 0;
    int r = arrSize - k - 1;
    /*swap between the leftmost numbers*/
    while (l < r)
    {
        arr[l] ^= arr[r];
        arr[r] = arr[l] ^ arr[r];
        arr[l] = arr[l] ^ arr[r];
        ++l;
        --r;
    }
    l = (arrSize - k) + 1;
    r = arrSize - 1;
    /*swap between the inner most numbers*/
    while (l < r)
    {
        arr[l] ^= arr[r];
        arr[r] = arr[l] ^ arr[r];
        arr[l] = arr[l] ^ arr[r];
        ++l;
        --r;
    }
    l = 0;
    r = arrSize - 1;
    /*swap between the outer most numbers*/
    while (l < r)
    {
        arr[l] ^= arr[r];
        arr[r] = arr[l] ^ arr[r];
        arr[l] = arr[l] ^ arr[r];
        ++l;
        --r;
    }
    printArray(arrSize, arr);
}

int main(){
    int arr[Size] = {1, 2, 3, 4, 5, 6};
    int k1 = 3, k2 = -300;
    
    classic_shiftArray(Size, arr, k1);
    optimized_shiftArray(Size, arr, k2);
}