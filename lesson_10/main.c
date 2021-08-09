#include <stdio.h>
#include <stdlib.h> /*for exit*/
#include <stdint.h>

void print_file_size(void);

int main (int argc, char **argv)
{
    FILE *file1, *file2;
    char filename1[100], filename2[100], c;
    size_t size;
    printf("Enter source and destination files:\n");
    scanf("%s %s", filename1, filename2);
    /* Open source file for reading and destination file for writing*/
    file1 = fopen(filename1, "r");
    if(file1 == NULL)
    {
        printf("Error. file1 not exists");
        exit(0);
    }

    file2 = fopen(filename2, "w");
    if(file2 == NULL)
    {
        printf("Error. file2 not exists");
        fclose(file1);
        exit(0);
    }

    /* Read content of file1*/
    while((c=fgetc(file1))!=EOF)
    {
        fputc(c, file2);
    }

    fseek(file2, 0, SEEK_END);
    size = ftell(file2);

    fclose(file1);
    fclose(file2);

    printf("Сopy done. Transfered %lu bytes\n", size);
    return 0;
}