#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int i;
    int fd = open("temp.txt", O_CREAT | O_RDWR, 0644);

    for (i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            printf("child %d created ,pid = %d\n", i+1, getpid());

            // Demonstrate close()
            close(fd);

            printf("processes with pid %d is finished\n", getpid());
            return 0;
        }
    }

    // Parent also closes file
    close(fd);

    return 0;
}
