#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_MEMORY 1000

int memory[MAX_MEMORY]; // 1 means block is allocated, 0 means block is free
int block_size[MAX_BLOCKS]; // size of each block

// function to allocate memory using the best fit algorithm
void allocate_memory(int process_size) {
  int i, best_fit_block = -1, best_fit_size = MAX_MEMORY;
  
  
  for (i = 0; i < MAX_BLOCKS; i++) {
    if (memory[i] == 0 && block_size[i] >= process_size && block_size[i] < best_fit_size) {
      best_fit_block = i;
      best_fit_size = block_size[i];
    }
  }
  
  
  if (best_fit_block != -1) {
    memory[best_fit_block] = 1;
    printf("Memory allocated to process of size %d in block %d\n", process_size, best_fit_block + 1);
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

