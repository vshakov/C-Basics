/******************************************************************************

Implement a function that returns the sum of the digits in the string passed to it. str_sum_digits (const char * cs)

*******************************************************************************/
#include <stdio.h>

void str_sum_digits(void);

int main(int argc, char **argv)
{
    str_sum_digits();
    return 0;
}

void str_sum_digits(void)
{
    int counter=0, i=0;
    char cs[100] = {0};
    while((*cs = getchar()) != '\n')
    {
        if((cs[i] >= '0') && (cs[i] <= '9'))
        {
            counter+=(cs[i] - '0'); /* counter = counter + (ASCII(cs[i]) - '0') for example: counter = 0 + (1(ASCII='49') - 0(ASCII='48') = 1 */
        }
    }
    printf("Sum of digits = %d\n", counter);
}