/* Show list of files in current direcrtory*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include "files.h"

void show_dir_files(const char *strdir);

int main(int argc, char **argv)
{
    char path[255] = {0};
    getcwd(path, 255);
    printf("patch = %s\n", path);
    
    show_dir_files(path);
    
    return 0;

}