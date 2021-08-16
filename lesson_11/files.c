#include "files.h"

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