#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "temp_functions.h"

extern char *optarg;
extern int optind, opterr, optopt;

#ifdef DEBUG
#define D if(1)
#else
#define D if (0)
#endif

  int main(int argc, char **argv)
  {
    struct measures *m;
    m = (struct measures *)malloc(N*sizeof(struct measures));
    m = (struct measures *)realloc(m, 2*N*sizeof(struct measures));

    if(argc<2)
    {
        printf ("Error. Enter the name of file\n");
        return -1;
    }
    char *file=argv[1];

    int rez=0;
    const char* opts = "hf:m:";

    if(argc == 1)
    {
        help(argv[0]);
        return 0;
    }

    while((rez = getopt(argc, argv, opts)) != -1)
    {
        switch(rez)
        {
            case 'h':
            {
                help(argv[0]);
                return 0;
            }
            case 'f':
            {
                //printf("folder is \"f = %s\".\n",optarg);
                strcpy(file, optarg);
                break;
            }
            case '?':
            {
                printf("Unknown argument: %s Try -h for help\n", argv[optind-1]);
                return 1;
            }
            case 'm':
            {
                printf ("statistics for the specified month are displayed");
            }
        }
    }
    


    FILE *f=fopen(file, "r");
    if(!f)
    {
        printf("Error opening file\n");
        return -2;
    }

    printf("YEAR MONTH DAY HOUR MINUTE TEMPERATURE\n");

    float average_annual_temperature=0;
    float summ_annual=0;
    int min,max;
    while (!feof(f))
    {
      int scanfret=fscanf(f, "%d;%d;%d;%d;%d;%d",
          &m->year,
          &m->month,
          &m->day,
          &m->hour,
          &m->minute,
          &m->temperature);
        D printf("scanfret %d\n", scanfret);

      if(scanfret == 6)
      {
        printf("%d%4d%6d%5d%7d%12d\n", 
        m->year,
        m->month,
        m->day,
        m->hour,
        m->minute,
        m->temperature);

      summ_annual+=m->temperature;
      average_annual_temperature = summ_annual/N;
      min = m->temperature;
      }
    }
    printf("Average annual temperature = %+.1f °C\n", average_annual_temperature);
    printf("Minimal annual temperature = %+d °C\n", min);

    free(m);

    fclose(f);

    return 0;
  }