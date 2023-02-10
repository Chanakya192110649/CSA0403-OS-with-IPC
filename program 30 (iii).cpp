#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
     pthread_t thread1, thread2;

     if (pthread_equal(thread1, thread2) != 0) {
         printf("Threads are equal\n");
     } else {
         printf("Threads are not equal\n");
     }

     exit(EXIT_SUCCESS);
}

