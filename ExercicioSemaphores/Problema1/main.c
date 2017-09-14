// #include <pthread.h>
// #include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_PROCESSES 6

/*
 * Problema 1:  Suponha que sejam criados 5 processos. Utilize
 * semáforos para garantir que o processo 1 escreva números de
 * 1 até 200, o processo 2 os números de 201 até 400, e assim 
 * por diante.
 * Dica: o processo i+1 só deve entrar em funcionamento quando 
 * processo i já tiver terminado a escrita dos seus números.
 */

void print_numbers_in_range(int start, int end, int processNumber) {
    printf("PROCESS NUMBER: %d", processNumber);
    for (int i = start; i <= end; i++) {
        printf("%d\n", i);
    }
}


/*  
 *  interval = 200
 *  1 + 200*0 = 1       200 + 200*0 = 200
 *  1 + 200*1 = 201     200 + 200*1 = 400
 *  1 + 200*2 = 401     200 + 200*2 = 600
 *      ...                 ...
 */

int* create_ranges(int interval) {
    int ranges[NUM_PROCESSES][2];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        ranges[i][0] = 1 + interval*i;
        ranges[i][1] = interval + interval*i;
    }

    return &ranges;
}

void print_arr(int* ranges) {
    printf("[ ");

    int* row;
    for (int i = 0; i < NUM_PROCESSES - 1; i++) {
        // TODO: Not working due pointer issues
        row = ranges[i];
        printf(" [%d, %d]", row[0], row[1]);
    }

    row = ranges[NUM_PROCESSES - 1];
    printf(" [%d, %d] ]\n", row[0], row[1]);
}

int main() {
    int* ranges;
    ranges = create_ranges(200);
    print_arr(ranges);

    return 0; 
}
