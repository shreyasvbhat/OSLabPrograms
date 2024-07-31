#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* add(void *arg){
        int n = *(int*)arg;
        int sum=0;
        for(int i=1; i<=n; i++)
                sum+=i;
        printf("Sum of first %d natural numbers is: %d\n",n,sum);
        printf("Add Thread completed...\n");
        pthread_exit(NULL);
}

void* factorial(void* arg){
        int n = *(int*)arg;
        int factorial = 1;
        for(int i=1; i<=n; i++)
                factorial *= i;
        printf("Factorial of %d is: %d\n",n,factorial);
        printf("Product Thread completed...\n");
        pthread_exit(NULL);
}

int main(int argc, char *argv[]){
        if(argc != 2){
                fprintf(stderr, "Usage: %s <number>\n",argv[0]);
                return 1;
        }
        int n = atoi(argv[1]);
        pthread_t thread1, thread2;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&thread1, &attr, add, &n);
        pthread_create(&thread2, &attr, factorial, &n);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        printf("Inside the main thread\n");
        return 0;
}