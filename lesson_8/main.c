/******************************************************************************

The standard input stream contains text consisting of Latin letters and numbers and ending with '.'.
Print the most frequently occurring digit in the text to the standard output stream (if there are several such digits, print any of them).

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int counter[256] = {0}; // initialize all elements to 0
    char str;
    int i;
    printf("Enter text with '.' in the end.\n");
    while((str = getchar()) != '.')
    {
        ++counter[str];
    }
    printf("\nNumber   Frequency\n");
    for(i=48;i<58;i++)
    {
        if(counter[i]!=0)
        {
            printf("%3c%11d\n", i, counter[i]); 
        }
    }
    int max = counter[48];
    for(i=49;i<58;i++)
    {
        if(counter[i]>max)
        {
            max=counter[i];
        }
    }
    int most_frequent_digit=0;
    for(i=48;i<58;i++)
    {
        if(counter[i]==max)
        {
            most_frequent_digit=i;
        }
    }
    printf("The most frequent digit in the text is '%c'. It was repeated %d times.\n", most_frequent_digit, max);
    
    return 0;
}
