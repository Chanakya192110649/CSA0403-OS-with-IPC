#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
pthread_mutex_t mutex; 
void *thread_func(void *arg) 
{ 
	pthread_mutex_lock(&mutex); 
	printf("Entered thread_func\n"); 
	sleep(5); 
	printf("Exiting thread_func\n"); 
	pthread_mutex_unlock(&mutex); 
	return NULL; 
} 
int main() 
{ 
	pthread_t tid; 
	pthread_mutex_init(&mutex, NULL); 
	pthread_create(&tid, NULL, thread_func, NULL); 
	pthread_mutex_lock(&mutex); 
	printf("Entered main\n"); 
	sleep(5); 
	printf("Exiting main\n"); 
	pthread_mutex_unlock(&mutex); 
	pthread_join(tid, NULL); 
	pthread_mutex_destroy(&mutex); 
	return 0; 
}
