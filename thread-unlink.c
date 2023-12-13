#include<stdio.h>
#include<assert.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *fn(void *arg) {
	unlink("test.txt");
}

int main(int argc, char* argv[]) {
	int fd = open("test.txt", O_CREAT | O_RDWR, 0600);
	assert(fd >= 0);

	pthread_t t1;
	pthread_create(&t1, NULL, fn, NULL);
	pthread_join(t1, NULL);

	char *data = "test";
	char rdata[64];
	write(fd, data, strlen(data));
	sleep(2);
	lseek(fd, 0, SEEK_SET);
	int rval = read(fd, &rdata, 64);
	rdata[rval] = 0;
	printf("Read value: %s\n", rdata);
	return 0;
}
