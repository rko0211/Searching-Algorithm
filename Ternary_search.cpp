#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(2*Log3(N))
// Space complexity : O(1)

// Ternary search is applicable to find the maximum or minimum value of a function in a sorted search space
int Ternary_search(int a[], int n, int key)
{
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi)
  {
    int mid1 = lo + (hi - lo) / 3;
    int mid2 = hi - (hi - lo) / 3;
    if (a[mid1] == key)
    {
      return mid1;
    }
    if (a[mid2] == key)
    {
      return mid2;
    }
    else if (a[mid1] > key)
    {
      hi = mid1 - 1;
    }
    else if (a[mid2] < key)
    {
      lo = mid2 + 1;
    }
    else
    {
      lo = mid1 + 1;
      hi = mid2 - 1;
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
  // Incase of Ternary search, search space should be in sorted order
  // If search space is in sored order then we can use Ternary search
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
  int ind = Ternary_search(a, n, key);
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