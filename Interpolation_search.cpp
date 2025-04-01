#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(Log2(Log2(n)))
// Space complexity : O(1)

// Interpolation search is applicable when data sets are uniform

// It is similar like Binary search but the difference is that here we do not take any mid value
int Interpolation_search(int a[], int n, int key)
{
  int lo = 0;
  int hi = n - 1;
  int pos;
  while (lo <= hi && a[lo] <= key && key <= a[hi])
  {
    pos = lo + (((double)(hi - lo) / (a[hi] - a[lo]))) * (key - a[lo]);

    if (a[pos] == key)
    {
      return pos;
    }
    else if (a[pos] < key)
    {
      lo = pos + 1;
    }
    else
    {
      hi = pos - 1;
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
  int ind = Interpolation_search(a, n, key);
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