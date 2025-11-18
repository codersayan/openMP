#include <stdio.h>
#include <omp.h>
#include <unistd.h>   // for sleep()

#define BUFFER_SIZE 5
#define PRODUCE_COUNT 10

int buffer[BUFFER_SIZE];
int count = 0;        // items in buffer
int in = 0, out = 0;  // circular queue indices

omp_lock_t lock;

// ------------------------ PRODUCER ------------------------
void producer() {
    for (int i = 1; i <= PRODUCE_COUNT; i++) {

        // wait until buffer has space
        while (count == BUFFER_SIZE);

        omp_set_lock(&lock);

        buffer[in] = i;
        printf("Producer produced: %d\n", i);

        in = (in + 1) % BUFFER_SIZE;
        count++;

        omp_unset_lock(&lock);

        sleep(1);
    }
}

// ------------------------ CONSUMER ------------------------
void consumer() {
    for (int i = 1; i <= PRODUCE_COUNT; i++) {

        // wait until buffer has data
        while (count == 0);

        omp_set_lock(&lock);

        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);

        out = (out + 1) % BUFFER_SIZE;
        count--;

        omp_unset_lock(&lock);

        sleep(2);
    }
}

// -------------------------- MAIN ---------------------------
int main() {
    omp_init_lock(&lock);

    #pragma omp parallel sections
    {
        #pragma omp section
        producer();

        #pragma omp section
        consumer();
    }

    omp_destroy_lock(&lock);

    return 0;
}
