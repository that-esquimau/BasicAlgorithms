#include <assert.h>

void insertion_sort(
    int A[] /* The sorted array. */,
    int n /* Length of A */)
{
    for (int k = 1; k < n; ++k)
    {
        int x = A[k]; /* "Hey you, come here." */
        int z = k;
        while (z > 0 && A[z - 1] > x)
        {
             /* z is the empty position before each iteration. */
            A[z] = A[z - 1]; /* "Sweetie, move to the next position, please." */
            --z;
        }
        A[z] = x; /* "Please get back to your array." */
    }
}

int test_case_0()
{
    int A[] = { 1 };
    int B[] = { 1 };
    insertion_sort(A, 1);
    return A[0] == B[0];
}

int test_case_1()
{
    int A[] = { 3, 2, 1 };
    int B[] = { 1, 2, 3 };
    insertion_sort(A, 3);
    for (int i = 0; i < 3; ++i)
    {
        if (A[i] != B[i])
            return 0;
    }
    return 1;
}

int square(int x)
{
    return x * x;
}

int test_case_2()
{
    int A[1000];
    for (int i = 0; i < 1000; ++i)
    {
        A[i] = square(999 - i);
    }
    insertion_sort(A, 1000);
    for (int i = 0; i < 1000; ++i)
    {
        if (A[i] != square(i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    assert(test_case_0());
    assert(test_case_1());
    assert(test_case_2());
    return 0;
}