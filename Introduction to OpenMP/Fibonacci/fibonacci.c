#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 8

long fib (int n) { return (n < 2 ? 1 : fib (n - 1) + fib (n - 2)); }

int main()
{
    int n = 45;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int t = omp_get_thread_num();
        printf("%d: %ld\n", t, fib(n+t));
    }
    return 0;
}