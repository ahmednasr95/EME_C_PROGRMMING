#include <stdio.h>

#define Size 5

/*
    Inputs: array and array size
    Output: None
    Description: Prints the second biggest value in an array.
    The function uses bubble sort to sort the array in ascending order.
*/
void classic_second_biggest(short arr_len, short *arr)
{
    short temp = arr[0];
    if (arr_len == 1)
    {
        printf("Array has only one value %d\n\n", arr[0]);
        return;
    }
    /*sort the array*/
    for (short i = 0; i < arr_len; ++i)
    {
        for (short j = i + 1; j < arr_len; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    short second_biggest = arr[0];
    /*search for the second biggest value*/
    for (short i = 0; i < arr_len; ++i)
    {
        if (second_biggest < arr[i] && arr[i] < arr[arr_len - 1])
        {
            second_biggest = arr[i];
        }
    }
    if (arr[arr_len - 1] == second_biggest)
    {
        printf("Array consists of one repeated value %d\n\n", second_biggest);
    }
    else
    {
        printf("%d\n\n", second_biggest);
    }

}

/*
    Inputs: array and array size
    Output: None
    Description: Prints the second biggest value in an array.
    The function uses a single loop to determine the second biggest number.
*/
void optimized_second_biggest(short arr_len, short *arr){
    short biggest = arr[0];
    short second_biggest = arr[1];
    for(short i = 0; i < arr_len; ++i){
            if(arr[i] > biggest){
                second_biggest = biggest;
                biggest = arr[i];
            }
            if(arr[i] > second_biggest && arr[i] < biggest){
                second_biggest = arr[i];
            }
    }
    printf("%d\n", second_biggest);
}

int main(){
   int arr[Size] = {43,66,50,10,30};

   classic_second_biggest(Size, arr);
   optimized_second_biggest(Size, arr);
}