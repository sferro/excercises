#include <setjmp.h>
#include <stdio.h>

static jmp_buf buf;

int main(int argc, char **argv)
{
	volatile int b;
	b=3;
	
	if(setjmp(buf) != 0)
	{
		printf("%d ", b);
		exit(0);
	}
	b=5;
	longjmp(buf, 1);
}



