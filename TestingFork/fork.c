#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	if (fork()) {
		printf("Parent1\n");
	}
	else {
		printf("Child1\n");
	}
	if (fork()) {
		printf("Parent2\n");
	}
	else {
		printf("Child2\n");
	}
	if (fork()) {
		printf("Parent3\n");
	}
	else {
		printf("Child3\n");
	}
}
