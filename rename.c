#include<stdio.h>
#include<assert.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	int fd = open("foo.txt", O_WRONLY | O_APPEND);
	assert(fd >= 0);

	char *data = "ABCDE";
	write(fd, data, strlen(data));
	printf("Data written %s\n", data);
	//exit(1);
	char *data1 = "FGHIJ";
	write(fd, data1, strlen(data1));
	printf("Data written %s\n", data1);
	close(fd);
	return 0;
}
