#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define SHM_NAME "try"
#define SHM_SIZE 1024

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void generate_primes(int m, int n, char *buffer) {
    char temp[50];
    for (int i = m; i <= n; i++) {
        if (is_prime(i)) {
            snprintf(temp, sizeof(temp), "%d ", i);
            strcat(buffer, temp);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <M> <N>\n", argv[0]);
        exit(1);
    }

    int M = atoi(argv[1]);
    int N = atoi(argv[2]);

    int fd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (fd < 0) {
        perror("shm_open");
        exit(1);
    }

    char *shm_ptr = (char *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    generate_primes(M, N, shm_ptr);

    munmap(shm_ptr, SHM_SIZE);
    close(fd);

    return 0;
}