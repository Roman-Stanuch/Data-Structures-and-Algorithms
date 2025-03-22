#include <stdio.h>

const static int NEW_LINE = '\n';

int gcd(int a, int b)
{
	if (b % a == 0)
		return a;
	else
		return gcd(b % a, a);
}

int main()
{
	int num1, num2;

	printf("Number 1: ");
	scanf_s("%d", &num1);
	putchar(NEW_LINE);

	printf("Number 2: ");
	scanf_s("%d", &num2);
	putchar(NEW_LINE);

	printf("GCD: %d", gcd(num1, num2));
	putchar(NEW_LINE);
}
