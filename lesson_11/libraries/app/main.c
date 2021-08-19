/* Show list of files in current direcrtory*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include <list_files.h>

int main(int argc, char **argv)
{
    char* path;
    path = (char*)malloc(255);
    /*scanf("%s", path);*/
    getcwd(path, 255);
    printf("path = %s\n", path);
    
    show_dir_files(path);
    
    
    free(path);
    return 0;
}