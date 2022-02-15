/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define COLUMNS 6

int countIf8 = 0;

void print_numbers(int n, int *count)
{
  if (*count % COLUMNS == 0)
    printf("\n");
  printf("%10d ", n);
  *count = *count + 1;
}

void print_seives(int n) // check primes under n
{   
  int x[n];
  int count = 0;
  for (int i = 0; i  < n-1; i++)
  {
    x[i] = i+2;
  }
  for (int i = 0; x[i]*x[i] <= n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (x[i] != 0 && x[j] != 0 && x[j] % x[i] == 0  && i !=j )
      {
         x[j] = 0; 
      }   
    }    
  }
  for(int i = 0; i < n; i++)
  {
    if(x[i] != 0)
    {
      bool temp = 0;
      print_numbers(x[i], &count);

      for(int j = 0; j < i; j++)
      {
        if(x[i] - x[j] == 8 )
        {
          temp = 1;
        }
        else if(temp == 1 && x[j] != 0)
        {
          temp = 0;
        }
      }
      if(temp)
        countIf8++;
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
    print_seives(atoi(argv[1]));
  else
  {
    printf("Please state an interger number.\n");
  }
  

  printf("%d", countIf8);
  printf("\n");
  return 0;
}
