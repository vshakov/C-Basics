#include "list_files.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"



void print_type(struct stat *st)
{
    switch (st->st_mode & S_IFMT) {
       case S_IFBLK:  printf("block device ");            break;
       case S_IFCHR:  printf("character device ");        break;
       case S_IFDIR:  printf("directory ");               break;
       case S_IFIFO:  printf("FIFO/pipe ");               break;
       case S_IFLNK:  printf("symlink ");                 break;
       case S_IFREG:  printf("regular file ");            break;
       case S_IFSOCK: printf("socket ");                  break;
       default:       printf("unknown? ");                break;
    }
}

bool print_all = false;

void show_dir_files(const char *strdir, bool all)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char *full_name;

    full_name = (char*)malloc(255);

    dir = opendir(strdir);

    if (dir != NULL)
    {
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_name[0] == '.' && !all)
            {
                continue;
            }

            if(entry->d_type == DT_DIR && strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0 ) // if it is a directory
            {
                printf("%s%s\n",GREEN, entry->d_name); // print its name in green
                char *d_path;
                d_path = (char*)malloc(255);
                printf("%s", BLUE);
                //char d_path[255]; // here I am using sprintf which is safer than strcat
                sprintf(d_path, "%s/%s", strdir, entry->d_name);
                show_dir_files(d_path, print_all); // recall with the new path
                free(d_path);
            }
            
            memset(full_name, 0, 255);
            sprintf(full_name, "%s/%s", strdir, entry->d_name);
            full_name[254] = '\0';
            if (stat(full_name, &file_info) == 0)
            {
                print_type(&file_info);
                printf("sz %10ld ", file_info.st_size);
            }
            printf("%s\n", full_name);
            
        }
        closedir(dir);
    }
    
    free(full_name);
}