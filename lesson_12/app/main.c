/* Show list of files in entered direcrtory*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#include <list_files.h>

extern char *optarg;
extern int optind, opterr, optopt;

void help(const char* appname);

int main(int argc, char **argv)
{
    /*char path[255] = {0};*/
    char* path;
    path = (char*)malloc(255);
    /*scanf("%s", path);*/
    /*getcwd(path, 255);*/
    
    
    
    int rez=0;
    
    const char* opts = "hf:a";
    int a;

    bool print_all = false;

    if(argc == 1)
    {
        help(argv[0]);
        return 0;
    }

    while((a = getopt(argc, argv, opts)) != -1)
    {
        switch(a)
        {
            case 'h':
            {
                help(argv[0]);
                return 0;
            }
            case 'f':
            {
                //printf("folder is \"f = %s\".\n",optarg);
                strcpy(path, optarg);
                break;
            }
            case '?':
            {
                printf("Unknown argument: %s Try -h for help\n", argv[optind-1]);
                return 1;
            }
            case 'a':
            {
                print_all = true;
            }
        }
    }
    printf("path = %s\n", path);
    show_dir_files(path, print_all);
    
    return 0;
    free(path);
}

void help(const char* appname)
{
    printf("This is example of list directory\n");
    printf("Usage: clear [options]\n\
                 -h This help text\n\
                 -f Specify folder.\n");
    printf("Example: %s -f /tmp\n", appname);
}