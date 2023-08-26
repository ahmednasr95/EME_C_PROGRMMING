#include <stdio.h>

#define numDays 5

void get_maxProfit(int arrSize, int* arr){
    unsigned short dayIndex = 0;
    unsigned short minimumPrice = arr[0];
    unsigned short minimumPriceIndex = 0;
    unsigned short maximumPrice = arr[numDays - 1];
    unsigned short maximumPriceIndex = numDays - 1;
    unsigned short profit = 0;

    for (; dayIndex < numDays; ++dayIndex)
    {
        if (arr[dayIndex] < minimumPrice && (dayIndex < maximumPriceIndex))
        {
            minimumPrice = arr[dayIndex];
            minimumPriceIndex = dayIndex;
        }
        if ((arr[dayIndex] > maximumPrice) && (dayIndex > minimumPriceIndex))
        {
            maximumPrice = arr[dayIndex];
            maximumPriceIndex = dayIndex;
        }
    }

    if ((maximumPriceIndex > minimumPriceIndex) && (numDays > 1))
    {
        profit = maximumPrice - minimumPrice;
        if (0 < profit)
        {
            printf("Maximum Profit is %d\n", profit);
        }
        else
        {
            printf("%d\n", 0);
        }
    }
    else
    {
        printf("%d\n", 0);
    }
}
void main()
{
    unsigned short arr[numDays] = {2, 6, 1, 4, 3};
    get_maxProfit(numDays, arr);
}