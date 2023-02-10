#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_message_function( void *ptr );

main()
{
     pthread_t thread1;
     char *message = "Thread 1";
     int  iret;

     

     iret = pthread_create( &thread1, NULL, print_message_function, (void*) message);
     if(iret)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret);
         exit(EXIT_FAILURE);
     }

     

     pthread_join( thread1, NULL); 

     exit(EXIT_SUCCESS);
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);+

     pthread_exit(NULL);
}

