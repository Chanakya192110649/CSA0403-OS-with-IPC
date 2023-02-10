#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_MEMORY 1000

int memory[MAX_MEMORY]; 
int block_size[MAX_BLOCKS]; 


void allocate_memory(int process_size) {
  int i, worst_fit_block = -1, worst_fit_size = -1;
  

  for (i = 0; i < MAX_BLOCKS; i++) {
    if (memory[i] == 0 && block_size[i] >= process_size && block_size[i] > worst_fit_size) {
      worst_fit_block = i;
      worst_fit_size = block_size[i];
    }
  }
  
  
  if (worst_fit_block != -1) {
    memory[worst_fit_block] = 1;
    printf("Memory allocated to process of size %d in block %d\n", process_size, worst_fit_block + 1);
  } else {
    printf("Error: Not enough memory to allocate process of size %d\n", process_size);
  }
}

int main() {
  int i, process_size;
  
  
  for (i = 0; i < MAX_BLOCKS; i++) {
    block_size[i] = MAX_MEMORY / (i + 1);
  }
  
  
  process_size = 200;
  allocate_memory(process_size);
  
  return 0;
}

