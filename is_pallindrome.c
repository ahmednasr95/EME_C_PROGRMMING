#include <stdio.h>
enum state
{
    false = 0,
    true = 1
};
enum testState
{
    fail = 0,
    pass = 1
};

/*
    Inputs: integer number
    Output: state (fail or success)
    Dscription: Checks if a number is a pallindrome i.e. the number when read from 
    left to right is the same when read from right to left.    
*/
enum state isPallindrome(int num)
{
    int x = num;
    int rev = 0;
    enum state state;
    /*reverse the number*/
    while (0 < x)
    {
        rev = (rev + (x % 10)) * 10;
        x /= 10;
    }
    /*check if the reverse is the same as the original*/
    if (num == (rev / 10))
    {
        /*for debugging*/
        // printf("The number %d is a pallindromic number.", num);
        state = true;
        return state;
    }
    else
    {
        /*for debugging*/
        // printf("The number %d is not a pallindromic number.", num);
        state = false;
        return state;
    }
}

/*
    Inputs: call-by-reference to an integer
    Output: state (fail or success)
    Description: Runs the isPallindrome function against 5 test cases
    and returns success if all cases are passed otherwise returns the
    number of failed test cases.
*/
enum testState testFunc(int *ptr)
{
    int test_cases[5] = {121, 12321, 1994, 2000, 1};
    enum state expected[5] = {true, true, false, false, true};
    enum testState status = pass;
    for (int i = 0; i < 5; ++i)
    {
        if (expected[i] != isPallindrome(test_cases[i]))
        {
            (*ptr) += 1;
        }
    }
    if (0 < *ptr)
    {
        status = fail;
        return status;
    }
    return status;
}

int main()
{
    int failedCases = 0;
    int *failedCasesPtr = &failedCases;
    if (testFunc(failedCasesPtr))
    {
        printf("All cases have passed!");
    }
    else
    {
        printf("%d test cases failed!", *failedCasesPtr);
    }

    return 0;
}