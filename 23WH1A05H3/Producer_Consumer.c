#define NUM_ITEMS 10
int *buffer;
int in = 0, out = 0;
sem_t *empty, *full, *mutex;
void *producer(void *arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(empty);
        sem_wait(mutex);
        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % BUFFER_SIZE;
        sem_post(mutex);
        sem_post(full);
        sleep(rand() % 2);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(full);
        sem_wait(mutex);
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        sem_post(mutex);
        sem_post(empty);
        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

int main() {
    int shm_fd = shm_open("/buffer", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int) * BUFFER_SIZE);

    buffer = mmap(NULL, sizeof(int) * BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    empty = sem_open("/empty", O_CREAT, 0666, BUFFER_SIZE);
    full = sem_open("/full", O_CREAT, 0666, 0);
    mutex = sem_open("/mutex", O_CREAT, 0666, 1);
    pthread_t prod_thread, cons_thread;
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
    sem_close(empty);
    sem_close(full);
    sem_close(mutex);
    shm_unlink("/buffer");
    sem_unlink("/empty");
    sem_unlink("/full");
    sem_unlink("/mutex");
    return 0;
}
