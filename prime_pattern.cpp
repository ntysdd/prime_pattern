#include <stdio.h>
#include <vector>

#define N      ( 100LL * 1000 * 1000 )

#if __linux
    #define _putchar_nolock    putchar_unlocked
#endif

int main()
{
    std::vector<bool> vec;
    for (long long i = 0; i <= N; i++)
    {
        vec.push_back(true);
    }

    vec[0] = false;
    vec[1] = false;

    for (long long i = 2; i * i <= N; i++)
    {
        for (long long j = i * i; j <= N; j += i)
        {
            vec[j] = false;
        }
    }

    long long prev = 0;
    long long total = 0;
    for (long long i = 1; i <= N; i++)
    {
        if (vec[i])
        {
            long long n = i - prev;
            for (long long k = 0; k < n - 1; k++)
            {
                _putchar_nolock('0');
                total++;
            }
            _putchar_nolock('1');
            total++;
            prev = i;
        }
    }

    for (long long i = 0; i < N - total; i++)
    {
        _putchar_nolock('0');
    }
    _putchar_nolock('\n');
}
