#include <stdio.h>
int gcd(int a, int b)
{
	//This function assumes a is bigger than b
	if(a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int main()
{
	int a,b;
	printf("Enter 2 numbers: ");
	scanf("%d%d", &a, &b);
	if(a>b)
		printf("The GCD is: %d\n", gcd(a,b));
	else if(a<b)
		printf("The GCD is: %d\n", gcd(b,a));
	else
		printf("The GCD is: %d\n", a);
}