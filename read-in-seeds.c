#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubiomes/finders.h"
#include "cubiomes/generator.h"

#define SEED_LEN 25
#define NUM_SEEDS 123835

int main()
{
  initBiomes();

  LayerStack g = setupGenerator(MC_1_14);

  char line[NUM_SEEDS][SEED_LEN];
  char fname[25] = "seeds-filtered.txt";
  FILE *fptr = NULL;
  int i = 0;

  fptr = fopen(fname, "r");
  printf("Opened the file...\n");
  while(fgets(line[i], SEED_LEN, fptr))
	{
    printf("%s", line[i]);
    i++;
  }
  return 0;
}

char** getSeedList()
{
  char line[NUM_SEEDS][SEED_LEN];
  char ** seedList = malloc(NUM_SEEDS * sizeof(char*));
  char fname[25] = "seeds-filtered.txt";
  FILE *fptr = NULL;

  fptr = fopen(fname, "r");
  printf("Opened the file...\n");

  int = 0;
  while (fgets(line[i], SEED_LEN, fptr)
  {
    seedList[i] = malloc(SEED_LEN * sizeof(char) + 1);
    i++;
  }

  return seedList;

}
