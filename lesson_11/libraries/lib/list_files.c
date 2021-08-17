#include "list_files.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void show_dir_files(const char *strdir)
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(strdir);
    if(dir)
    {
        while((entry = readdir(dir)) != NULL)
        {
            printf("file %s\n", entry->d_name);
        }
    }
}