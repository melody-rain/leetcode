#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int medianPos;
        bool doIncrease;

        if (!n && !m)
            return 0.;

        if (!m)
        {
            medianPos = (n >> 1);
            doIncrease = (n % 2) ? false : true;
            return (doIncrease ? ((B[medianPos - 1] + B[medianPos]) / 2.0) : B[medianPos]);
        }
        else if (!n)
        {
            medianPos = (m >> 1);
            doIncrease = (m % 2) ? false : true;
            return (doIncrease ? ((A[medianPos - 1] + A[medianPos]) / 2.0) : A[medianPos]);
        }

        medianPos = ((m + n) >> 1);
        doIncrease = ((m + n) % 2) ? false : true;
        int *C = new int[m + n];

        int i, j, k;
        for (i = 0, j = 0, k = 0; i < m && j < n; k++)
        {
            if (A[i] <= B[j])
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = B[j];
                j++;
            }
        }

        if (i >= m)
        {
            for (int t = j; t < n; t++, k++)
            {
                C[k] = B[t];
            }
        }

        if (j >= n)
        {
            for (int t = i; t < m; t++, k++)
            {
                C[k] = A[t];
            }
        }

        return (doIncrease ? ((C[medianPos - 1] + C[medianPos]) / 2.0): C[medianPos]);
    }
};

int main()
{
    Solution mySolution;
    int A[] = { 1, 3, 4, 5, 8 };
    int B[] = { 2, 5, 7, 9, 10 };
    double median = mySolution.findMedianSortedArrays(A, sizeof(A) / sizeof(int), B, sizeof(B) / sizeof(int));
    printf("median is %f\n", median);
}