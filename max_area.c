#include <stdio.h>

#define Size 5
/*
    Inputs: array size, and array reference
    Output: the maximum area
    Description: calculats the maximum area between 
    two numbers that represent a wall height.  
*/
int maxArea(int *arr, int N)
{
    int max = 0, test, i = 0, j = N - 1;
    while (j > i)
    {
        test = arr[i];
        if (test > arr[j])
            test = arr[j];
        test = (j - i) * test;
        if (max < test)
            max = test;
        if (arr[i] < arr[j])
            i++;
        else
            j--;
    }
    return max;
}

int main(){
    int arr[Size] = {4,3,6,8,2};

    prinf("The maximum area is: %d", maxArea(arr, Size));
}