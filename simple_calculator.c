#include <stdio.h>
#define maxFloat 0xFFFF

char insert_str[] = "Please insert two numbers space separated\n";

/*
    inputs: none
    ouputs: none
    description: gets two values from the user and prints
                 back the sum.
    time complexity: O(1);
    space complexity: O(1);
*/
void sum()
{
    /*initializations*/
    float result = 0, a = 0, b = 0;
    /*get user data*/
    printf(insert_str);
    scanf(" %f %f", &a, &b);
    /*calculate*/
    result = a + b;
    /*check for overflow*/
    if (result < maxFloat)
    {
        printf("The sum of %0.3f and %0.3f is %0.3f\n", a, b, result);
    }
    else
    {
        printf("Overflow!\n");
    }
}

/*
    inputs: none
    ouputs: none
    description: gets two values from the user and prints
                 back the difference.
    time complexity: O(1);
    space complexity: O(1);
*/
void diff()
{
    /*initializations*/
    float result = 0, a = 0, b = 0;
    /*get user data*/
    printf(insert_str);
    scanf(" %f %f", &a, &b);
    /*calculate*/
    result = a - b;
    /*check for overflow*/
    if (result < maxFloat)
    {
        printf("The difference of %0.3f and %0.3f is %0.3f\n", a, b, result);
    }
    else
    {
        printf("Overflow!\n");
    }
}

/*
    inputs: none
    ouputs: none
    description: gets two values from the user and prints
                 back the product.
    time complexity: O(1);
    space complexity: O(1);
*/
void prod()
{
    /*initializations*/
    float result = 0, a = 0, b = 0;
    /*get user data*/
    printf(insert_str);
    scanf(" %f %f", &a, &b);
    /*calculate*/
    result = a * b;
    /*check for overflow*/
    if (result < maxFloat)
    {
        printf("The product of %0.3f and %0.3f is %0.3f\n", a, b, result);
    }
    else
    {
        printf("Overflow!\n");
    }
}

/*
    inputs: none
    ouputs: none
    description: gets two values from the user and prints
                 back the quotient.
    time complexity: O(1);
    space complexity: O(1);
*/
void quotient()
{
    /*initializations*/
    float result = 0, a = 0, b = 0;
    /*get user data*/
    printf(insert_str);
    scanf(" %f %f", &a, &b);
    /*check for zero division*/
    if (b != 0)
    {
        /*calculate*/
        result = a / b;
        /*check for overflow*/
        if (result < maxFloat)
        {
            printf("The sum of %0.3f and %0.3f is %0.3f\n", a, b, result);
        }
        else
        {
            printf("Overflow!\n");
        }
    }
    else
    {
        printf("Ivalid division by zero!\n");
    }
}

/*
    inputs: none
    ouputs: none
    description: gets two values from the user and prints
                 back the power.
    time complexity: O(n);
    space complexity: O(1);
*/
void power()
{
    /*initializations*/
    float result = 1, a = 0, b = 0;
    /*get user data*/
    printf(insert_str);
    scanf(" %f %f", &a, &b);
    /*check for negative powers*/
    if (0 > b)
    {
        b = b * -1;
        /*calculate the power normally*/
        for (int i = b; 0 < i; --i)
        {
            result *= a;
        }
        /*apply the negative sign*/
        result = 1 / result;
    }
    else
    {
        for (float i = b; 0 < i; --i)
        {
            result *= a;
        }
    }
    /*check for overflow*/
    if (result < maxFloat)
    {
        printf("%0.3f power of %0.3f is %0.3f\n", a, b, result);
    }
    else
    {
        printf("Overflow!\n");
    }
}

/*
    inputs: none
    ouputs: none
    description: gets one value from the user and prints
                 back its factorial.
    time complexity: O(n);
    space complexity: O(1);
*/
void factorial()
{
    /*initializations*/
    float result = 1, a = 0;
    /*get user data*/
    printf(insert_str);
    scanf(" %f", &a);
    /*calculate the factorial*/
    while (0 < a)
    {
        result *= a;
        --a;
    }
    /*check for overflow*/
    if (result < maxFloat)
    {
        printf("The factorial is %0.3f\n", a, result);
    }
    else
    {
        printf("Overflow!\n");
    }
}

int main()
{
    void (*funcPtr[6])() = {sum, diff, prod, quotient, power, factorial};
    char usr_input = 'a';
    float result = 0;
    float a = 0, b = 0;
    char str[] = "Choose an operation: a -> addition\n\
                     s -> subtraction\n\
                     m -> multiplication\n\
                     d -> division\n\
                     p -> power\n\
                     f -> factorial\n\
                     e -> to exit\n";

    while (usr_input != 'e')
    {
        usr_input = 'a';
        printf(str);
        scanf(" %c", &usr_input);
        switch (usr_input)
        {
        case 'a':
            funcPtr[0]();
            break;
        case 's':
            funcPtr[1]();
            break;
        case 'm':
            funcPtr[2]();
            break;
        case 'd':
            funcPtr[3]();
            break;
        case 'p':
            funcPtr[4]();
            break;
        case 'f':
            funcPtr[5]();
            break;
        case 'e':
            break;
        default:
            printf("Please insert a valid character from the list!\n");
        }
    }
    printf("Thanks :)\n");
    return 0;
}