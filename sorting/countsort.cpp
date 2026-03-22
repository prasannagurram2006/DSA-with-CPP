#include <iostream>
using namespace std;

void countSort(int a[], int n, int k)
{
    int count[k + 1], b[n];

    // Step 1: Initialize count array with 0
    for (int i = 0; i <= k; i++)
        count[i] = 0;

    // Step 2: Store frequency of each element
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    // Step 3: Prefix sum (cumulative count)
    for (int i = 1; i <= k; i++)
        count[i] = count[i] + count[i - 1];

    // Step 4: Build output array (RIGHT to LEFT → stable)
    for (int i = n - 1; i >= 0; i--)
        b[--count[a[i]]] = a[i];

    // Step 5: Copy sorted elements back to original array
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter maximum key value (k): ";
    cin >> k;

    countSort(a, n, k);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
