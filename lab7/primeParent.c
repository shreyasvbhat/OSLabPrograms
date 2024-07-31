#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define SHM_NAME "try"
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <M> <N>\n", argv[0]);
        exit(1);
    }

    int M = atoi(argv[1]);
    int N = atoi(argv[2]);

    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        perror("shm_open");
        exit(1);
    }
    ftruncate(fd, SHM_SIZE);

    char *shm_ptr = (char *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        char m_str[10], n_str[10];
        snprintf(m_str, sizeof(m_str), "%d", M);
        snprintf(n_str, sizeof(n_str), "%d", N);
        execlp("./child", "./child", m_str, n_str, NULL);
        perror("execl");
        exit(1);
    } else {
        wait(NULL);
        printf("Prime Numbers: %s\n", shm_ptr);

        munmap(shm_ptr, SHM_SIZE);
        shm_unlink(SHM_NAME);
    }

    return 0;
}