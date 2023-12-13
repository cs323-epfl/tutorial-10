#include<stdio.h>
#include<assert.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>

void *fn(void *arg) {
	int fd = *((int*)arg);
	int temp = lseek(fd, 10, SEEK_CUR);
	printf("child: offset %d\n", temp);
}

int main(int argc, char* argv[]) {
	int fd = open("file.txt", O_RDONLY);
	assert(fd >= 0);
	pthread_t t1;
	pthread_create(&t1, NULL, fn, &fd);
	pthread_join(t1, NULL);
	int temp = lseek(fd, 10, SEEK_CUR);
	printf("parent: offset %d\n", temp);
	return 0;
}
