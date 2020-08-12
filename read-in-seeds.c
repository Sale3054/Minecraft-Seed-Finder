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
  int biomeList[3] = {warmOcean, ice_spikes, mushroom_fields};
  BiomeFilter myBiomeFilter = setupBiomeFilter(biomeList, 3);
  int * map = NULL;
  printf("Finished getting seeds from cleaned seedList/File/W.e\n");
  printf("%d", warmOcean);

  // Pos pos = getSpawn(const int mcversion, const LayerStack *g, int *cache, int64_t worldSeed)
  for (int i = 0; i < NUM_SEEDS - 100; i++)
  {
    long long winningSeed = 0;
    if(str[i] != NULL)
    {
      int64_t seedNum = atoi(str[i]);
      printf("%lld", seedNum);
      Pos pos = getSpawn(MC_1_16, &g, NULL, seedNum);
      applySeed(&g, seedNum);
      winningSeed = checkForBiomes(&g, map, seedNum, pos.x, pos.z, 1000, 1000, myBiomeFilter, 27);
      if(winningSeed == 0)
      {
        printf("Seed #: %"PRId64" did not have all we were looking for...\n", seedNum);
      }
      else
      {
        printf("Success!\n Seed #: %"PRId64" has all we are looking for!!\n", seedNum);
      }
    }
  }
  // Clean up.
  freeGenerator(g);

  return 0;
}
