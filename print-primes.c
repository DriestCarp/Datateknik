/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

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

void print_numbers(int n, int *count)
{
  if (*count % COLUMNS == 0)
    printf("\n");
  printf("%10d ", n);
  *count = *count + 1;
}

void print_primes(int n)
{
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  int count = 0;
  for (int i = 2; i < n; i++)
  {
    if (is_prime(i))
    {
      print_numbers(i, &count);
    }
  }
  printf("\n");
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[])
{
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
  {
    printf("Please state an interger number.\n");
  }
  return 0;
}

 
