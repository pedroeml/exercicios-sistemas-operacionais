#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_THREADS 3
#define ARR_LENGTH 10

/*
 * Escreva um programa com  tres threads, onde a tread A coloca um
 * novo elemento em um vetor de 50 numeros a cada segundo, a thread B
 * reordena este vetor a cada 5s e a thread C imprime o vetor a cada
 * 2s. o programa deve parar quando o vetor estiver cheio
 */

int arr[ARR_LENGTH];
int index = 0;

void* add_elem_to_arr(void *threadid) {
    int tid;

    tid = (int)(long int)threadid;

    srand(time(NULL));
    int random_number = rand();

    for (index = 0; index < ARR_LENGTH; index++) {
        arr[index] = random_number;
        printf("Thread A added %d at arr's index %d\n", random_number, index);
        random_number = rand();
        sleep(1);
    }

    printf("Thread A finished\n");
    pthread_exit(NULL);

    return NULL;
}

int comp(const void* elem1, const void* elem2) {
    int f = *((int*) elem1);
    int s = *((int*) elem2);

    if (f > s)
        return 1;
    else if (f < s)
        return -1;
    return 0;
}

void* sort_arr(void *threadid) {
    while (index != ARR_LENGTH) {
        qsort(arr, ARR_LENGTH, sizeof(int), comp);
        printf("Thread B sorted arr\n");
        sleep(5);
    }

    printf("Thread B finished\n");
    pthread_exit(NULL);

    return NULL;
}

void* print_arr(void *threadid) {
    while (index != ARR_LENGTH) {
        printf("[ ");
        for (int i = 0; i < ARR_LENGTH - 1; i++) {
            printf(" %d,", arr[i]);
        }
        printf(" %d ]\n", arr[ARR_LENGTH - 1]);
        printf("Thread C printed arr\n");
        sleep(2);
    }

    printf("Thread C finished\n");
    pthread_exit(NULL);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int err_code, i = 0;

    while(index != ARR_LENGTH) {
        if (i == 0)
            err_code = pthread_create(&threads[i], NULL, add_elem_to_arr, (void *)i++);
        else if (i == 1)
            err_code = pthread_create(&threads[i], NULL, sort_arr, (void *)i++);
        else if (i == 2)
            err_code = pthread_create(&threads[i], NULL, print_arr, (void *)i++);

        if (err_code){
            printf("ERROR code is %d\n", err_code);
            return -1;
        }
    }

    printf("Thread main finished\n");
    pthread_exit(NULL);

    return 0;
}
