#include<stdio.h>
#include<assert.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
	int fd = open("file.txt", O_RDONLY);
	assert(fd >= 0);
	int pid = fork();
	if (pid == 0) {
		int temp = lseek(fd, 10, SEEK_CUR);
		printf("child: offset %d\n", temp);
	} else if (pid > 0) {
		wait(NULL);
		int temp = lseek(fd, 10, SEEK_CUR);
		printf("parent: offset %d\n", temp);
	}
	return 0;
}
