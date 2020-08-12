#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubiomes/finders.h"
#include "cubiomes/generator.h"

#define SEED_LEN 21
#define NUM_SEEDS 123830

char** getSeedList()
{
  char line[NUM_SEEDS][SEED_LEN];
  char ** seedList = malloc(NUM_SEEDS * sizeof(char*));
  char fname[25] = "seeds-filtered.txt";
  FILE *fptr = NULL;

  fptr = fopen(fname, "r");
  printf("Opened the file...\n");

  int i = 0;
  while (fgets(line[i], SEED_LEN, fptr))
  {
    seedList[i] = malloc(SEED_LEN * sizeof(char) + 1);
    seedList[i] = line[i];
    printf(line[i]);
    i++;
  }
  seedList[i] = NULL;
  return seedList;
}

int main()
{
  initBiomes();
  LayerStack g = setupGenerator(MC_1_16);
  char ** str = getSeedList();

  // Pos pos = getSpawn(const int mcversion, const LayerStack *g, int *cache, int64_t worldSeed)
  for (int i = 0; i < NUM_SEEDS - 100; i++)
  {1
    if(str[i] != NULL)
    {
      int64_t seedNum = atoi(str[i]);
      Pos pos = getSpawn(MC_1_16, &g, NULL, seedNum);
      applySeed(&g, seedNum);
      int biomeID = getBiomeAtPos(g, pos);
      if (biomeID == jungle_edge)
      {
        break;
      }
    }
  }
  // Clean up.
  freeGenerator(g);

  return 0;
}
