#include <stdio.h>

void fibunacci(short n)
{
    /*initialization*/
    unsigned short x = 0;
    unsigned short y = 1;
    unsigned short i = 0;
    /*check for corner cases*/
    if (n > 0 && 26 >= n)
    {
        switch (n)
        {
        case 1:
            printf("%d", x);
            break;
        case 2:
            printf("%d %d ", x, y);
            break;
        default:
            printf("%d %d ", x, y);
            while (i < n && n > 0)
            {
                /*print next number*/
                printf("%d ", x + y);
                /*swap between previous two numbers*/
                x = x ^ y;
                y = x ^ y;
                x = x ^ y;
                /*store the next number*/
                y += x;
                /*increment*/
                ++i;
            }
            break;
        }
    }
    else
    {
        printf("Invalid input");
    }
}

int main(){
    int num = 5;
    fibunacci(num);
    return 0;
}
