#include <stdio.h>
#include <time.h>
  
int isPrime(long int n)
{
    // Corner cases
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 0;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
  
    return 1;
} 


int main()
{
    // Calculate the time taken by fun()
    clock_t t;
    t = clock();
    isPrime(94846548797);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("isPrime() took %f seconds to execute \n", time_taken);
    return 0;
}
