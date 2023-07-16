#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
   for(int i=0;i<=n-2;i++)
   {
    int mini=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[mini])
        {
            mini=j;
        }
    }
    swap(arr[i],arr[mini]);
   }

    cout << "After Using selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using selection Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selection_sort(arr, n);
    return 0;
}