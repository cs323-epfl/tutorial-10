
all: fork-lseek thread-lseek thread-unlink rename rename-atomic

fork-lseek: fork-lseek.c
	gcc fork-lseek.c -O0 -o fork-lseek
	touch file.txt

thread-lseek: thread-lseek.c
	gcc thread-lseek.c -O0 -o thread-lseek
	touch file.txt

thread-unlink: thread-unlink.c
	gcc thread-unlink.c -O0 -o thread-unlink

rename: rename.c
	gcc rename.c -O0 -o rename
	touch foo.txt

rename-atomic: rename-atomic.c
	gcc rename-atomic.c -O0 -o rename-atomic
	touch foo.txt

clean:
	rm -f fork-lseek file.txt thread-lseek thread-unlink test.txt rename foo.txt rename-atomic foo.txt.tmp
