#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int fd, i, count = 0, nloop = 10, zero = 0, *ptr;
    sem_t mutex;
    //open a file and map it into memory
    fd = open("log.txt", O_RDWR | O_CREAT, S_IRWXU);
    write(fd, &zero, sizeof(int));
    ptr = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    /* create, initialize semaphore */
    if (sem_init(&mutex, 1, 1) < 0) //
    {
        perror("semaphore initilization");
        exit(0);
    }
    if (fork() == 0) { /* child process*/

        printf("child's sem %p\n",&mutex);
        for (i = 0; i < nloop; i++) {
            if(sem_wait(&mutex) != 0){
                exit(-1);
            }
            printf("child: %d\n", ++(*ptr));
            fflush(stdout);
            if(sem_post(&mutex) != 0){
                exit(-1);
            }
        }
        exit(0);
    }
    /* back to parent process */
    printf("parent's sem %p\n",&mutex);
    for (i = 0; i < nloop; i++) {
        if(sem_wait(&mutex) != 0){
                exit(-1);
            }
        printf("parent: %d\n", ++(*ptr));
        fflush(stdout);
        if(sem_post(&mutex) != 0){
                exit(-1);
            }
        
    }

    wait(NULL);


    printf("last value: %d\n", (*ptr));
    printf("parent exit\n");
    
    exit(0);
}