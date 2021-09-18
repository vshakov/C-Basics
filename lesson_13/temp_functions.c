#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#include "temp_functions.h"

void help(const char* appname)
  {
    printf("Temperature statistics application\n\
    The program displays statistics for each month, taking into account the initial data:\n\
    - average monthly temperature\n\
    - minimum temperature in the current month\n\
    - maximum temperature in the current month\n\
    The program also displays statistics for the year:\n\
    - average annual temperature\n\
    - minimum temperature\n\
    - Maximum temperature\n");
    printf("Usage: clear [options]\n\
                 -h This help text\n\
                 -f Specify filename.<filename.csv> input csv file to process\n\
                 -m <month number> if this key is specified, then only statistics for the specified month are displayed\n");
  }
