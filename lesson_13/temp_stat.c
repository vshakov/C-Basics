#include <stdio.h>

struct measures {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
  };

  int main(int argc, char **argv)
  {
    if(argc<2)
    {
        return -1;
    }
    char *file=argv[1];

    FILE *f=fopen("temp.csv", "r");
    if(!f)
    {
        printf("Error opening file\n");
        return -2;
    }

    while (!feof(f))
    {
        struct measures m;
        int scanfret=fscanf(f, "%d;%d;%d;%d;%d;%d",
            &m.year,
            &m.month,
            &m.day,
            &m.hour,
            &m.minute,
            &m.temperature);
        printf("scanfret %d\n", scanfret);
    }

    fclose(f);

    return 0;
  }