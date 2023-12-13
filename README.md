
* fork-lseek.c : Creates two processes which does lseek on the file descriptor and prints the offset at the end.
* thread-lseek.c : Creates two threads which does lseek on the file descriptor and prints the offset at the end.
* thread-unlink.c : Create two threads. The first thread unlinks the file meanwhile the second write writes some data to the file.
* rename.c : A process does two write system calls. If the process exits before the second write, then only first write is visible.
* rename-atomic.c : A process does two write system calls to a temporary file and at the end does a rename. If the process exits before the second write, then no write is done on the original file.

Execute the following command to compile:

```{.sh}
make
```
