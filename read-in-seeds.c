#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubiomes/finders.h"
#include "cubiomes/generator.h"

#define LSIZ 25
#define RSIZ 123835

int main(void)
{

  #define LSIZ 25
  #define RSIZ 123835

  char line[RSIZ][LSIZ];
  char fname[25] = "seeds-filtered.txt";
  FILE *fptr = NULL;
  int i = 0;

  fptr = fopen(fname, "r");
  printf("Opened the file...\n");
  while(fgets(line[i], LSIZ, fptr))
	{
    printf("%s", line[i]);
    i++;
  }
  return 0;
}
