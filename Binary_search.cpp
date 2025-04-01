#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(Log2(N))
// Space complexity : O(1)

// Binary search is applicable to find the maximum or minimum value of a function in a sorted search space
int Binary_search(int a[], int n, int key)
{
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi)
  {
    int mid = hi - (hi - lo) / 2;
    if (a[mid] == key)
    {
      return mid;
    }
    else if (a[mid] < key)
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }

  return -1;
}
int main()
{

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  // Incase of binary search, search space should be in sorted order
  // If search space is in sored order then we can use binary search
  sort(a, a + n);
  cout << "The sorted alignment of data set is\n";
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  cout << "Enter key value ";
  int key;
  cin >> key;
  int ind = Binary_search(a, n, key);
  if (ind == -1)
  {
    cout << "The element " << key << " " << "does not exist in the data set\n";
  }
  else
  {
    cout << "The element " << key << " " << "is present at index " << ind << endl;
  }
  return 0;
}