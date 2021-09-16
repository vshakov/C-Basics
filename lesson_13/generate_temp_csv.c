#include <stdio.h>
#include <stdlib.h> /*for exit*/
#include <stdint.h>
#include <string.h>
#include <time.h>

struct measures {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
  };

typedef struct measures m_t;

void init_measures(m_t *m);
void print_measures(m_t m);
static int comparer(const void *a, const void *b);
void sort_measures(m_t m[], int N);
void fprintf_measures(m_t m);


int main(int argc, char** argv)
{
    
    int N = 10;
    srand(time(0));

    m_t m[N];

    for(int i=0;i<N;i++)
    {
        init_measures(&m[i]);
    }

    for(int i=0;i<N;i++)
    {
        print_measures(m[i]);
    }
    printf("###############################\n");

    sort_measures(m, N);

    for(int i=0;i<N;i++)
    {   
        print_measures(m[i]);
    }

FILE *fp;
fp = fopen("temp.csv", "w");
fprintf(fp,"%s,%s,%s,%s,%s,%s\n","YEAR","MONTH","DAY","HOUR","MINUTE","TEMPERATURE");
fclose(fp);

   for(int i=0;i<N;i++)
    {
        fprintf_measures(m[i]);
    }
    return 0;
}

void init_measures(m_t *m)
{
    m->year = 2020;
    //init month
    m->month = rand()%12 + 1;
    //init day
    m->day = rand()%31 + 1;
    //init hour
    m->hour = rand()%12;
    //init minute
    m->minute = rand()%60;
    //init temperature
    m->temperature = (rand() % (99-(-99)+1) + (-99));

}

void print_measures(m_t m)
{
    printf("%d %d %d %d %d %d\n", m.year, m.month, m.day, m.hour, m.minute, m.temperature);
}

void fprintf_measures(m_t m)
{
    FILE *fp;
    fp = fopen("temp.csv", "a");

    if(fp == NULL)
    {
        printf("File error");
        exit(0);
    }
    
    fprintf(fp,"%d,%d,%d,%d,%d,%d\n", m.year, m.month, m.day, m.hour, m.minute, m.temperature);

    fclose(fp);
}

static int comparer(const void *a, const void *b)
{
    m_t *m1 = (m_t *)a;
    m_t *m2 = (m_t *)b;

    if(m1->year - m2->year == 0)
    {
        if(m1->month > m2->month)
        {
            return 1;
        }
        else if(m1->month < m2->month)
        {
            return -1;
        }
        else if(m1->month = m2->month)
        {
            if(m1->day > m2->day)
            return 1;
            else if(m1->day < m2->day)
            return -1;
            else if(m1->day = m2->day)
            {
                if(m1->hour > m2->hour)
                return 1;
                else if(m1->hour < m2->hour)
                return -1;
                else if (m1->hour = m2->hour)
                {
                    if(m1->minute > m2->minute)
                    return 1;
                    else if(m1->minute < m2->minute)
                    return -1;
                    else
                    return 0;
                }
            }
        }
    }
}


void sort_measures(m_t m[], int N)
{
    qsort(m, N, sizeof(m_t), comparer);
  
}
