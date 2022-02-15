/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>

int is_prime(int n)
{
	double ctrl = (double) n;
	for (int i= 2; i < n; i++)
	{
		if ((ctrl / i) == (n / i) && n != 2)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	printf("%d\n", is_prime(19));  // 11 is a prime.      Should print 1.
	printf("%d\n", is_prime(20)); // 383 is a prime.     Should print 1.
	printf("%d\n", is_prime(21)); // 987 is not a prime. Should print 0.
}
