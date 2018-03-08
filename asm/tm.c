#include "asm.h"
int main ()
{
	char *a = malloc(1024 * 1024 * 16);
	*a = 1;
}
