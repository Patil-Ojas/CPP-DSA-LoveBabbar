#include <bits/stdc++.h> 
void swap(int &a, int &b)
{
   int temp = b;
   b = a;
   a = temp;
}

void sort012(int *arr, int n)
{
   int size = sizeof(arr)/sizeof(arr[0]);
   std::cout<<n<<"hatemylife\n";
   std::cout<<size<<"hatemylife\n";

   int i=0;
   int j=0;
   int k=n-1;

   while (j<=k)
   {
      if (arr[j]==0)
      {
         swap(arr[i], arr[j]);
         i++;
         j++;
      }
      else if (arr[j]==1)
      {
         j++;
      }
      else
      {
         swap(arr[j], arr[k]);
         k--;
      }
   }
}

int main() {
    int n;

    // Input the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];

    // Input the elements of the array
    std::cout << "Enter " << n << " elements of the array (0, 1, or 2): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Sorting the array using the sort012 function
    sort012(arr, n);

    // Displaying the sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}