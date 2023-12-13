#include<stdio.h>
#include<assert.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	int fd = open("foo.txt", O_WRONLY | O_APPEND);
	assert(fd >= 0);

	int fd1 = open("foo.txt.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0664); 

	char *data = "ABCDE";
	write(fd1, data, strlen(data));
	printf("Data written %s\n", data);
	//exit(1);
	char *data1 = "FGHIJ";
	write(fd1, data1, strlen(data1));
	printf("Data written %s\n", data1);
	fsync(fd1);
	close(fd1);
	rename("foo.txt.tmp", "foo.txt");
	return 0;
}
