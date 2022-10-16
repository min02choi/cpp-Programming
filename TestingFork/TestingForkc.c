#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <unistd.h>

int main() {
	int pid;
	pid = fork();
	printf("%d \n", pid);
}