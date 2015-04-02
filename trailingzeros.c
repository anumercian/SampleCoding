/*  Question: How many trailing zeros are in 5!
 *  Author: Anu Mercian
 */

/* A trailing zero is produced by prime factors 2 and 5 */
/* Complexity is O(log n) or O(n)*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to return trailing 0s in factorial of n
int findTrailingZeros(int  n)
{
    // Initialize result
    int count = 0, i;
 
    // Keep dividing n by powers of 5 and update count
    for (i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}

int factorial (int n)
{
   int f=1, i;
   for(i=2; i<=n; i++)
   {
      f = f*i;
   }
   printf("%d\n", f);
}
int trailingZeros(int a)
{
   int f, m, count;
   count = 0;
   // Finding the factorial of a
   f = factorial(a);
   // Divide the number of 10 until its 0 and see if remainder is 0 and count

   while(f>0)
   {
      m = f % 10;
      printf("%d\n", (f%10));
      if ( (f%10) == 0)
	count++;
      f = f/10;
   }
   printf("%d\n", count);
   return count;
}

int main()
{
  int n, z;

  scanf("%d", &n);
  
  z = findTrailingZeros(n);

  printf("Number of trailing zeros of %d is %d \n", n, z);
  return 0;
}

