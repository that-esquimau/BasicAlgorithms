void swap(int A[], int x, int y)
{
    int tmp = A[x];
    A[x] = A[y];
    A[y] = tmp;
}

int partition(int A[], int p, int q)
{
    int x = A[q];
    int j = p;
    for (int i = p; i < q; ++i)
    {
        if (A[i] < x)
        {
            swap(A, i, j++);
        }
    }
    swap(A, j, q);
    return j;
}

void quick_sort(int A[], int p, int q)
{
    if (p < q)
    {
        int k = partition(A, p, q);
        quick_sort(A, p, k - 1);
        quick_sort(A, k + 1, q);
    }
}

void sort(int A[], int n)
{
    quick_sort(A, 0, n - 1);
}

#include <stdio.h>

int main()
{
    int A[] = {5, 4, 3, 2, 1};
    sort(A, 5);
    for (int i = 0; i < 5; ++i)
    {
        if (A[i] != i + 1)
        {
            printf("error.\n");
        }
    }
    return 0;
}