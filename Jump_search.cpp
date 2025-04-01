#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(sqrt(N))
// Space complexity : O(1)

// Jump search is applicable when data sets are sorted

// Jump search = Jump + linear search
//  O(N/M + (M-1))
// Optimal jump size, M = sqrt(N);

int jump_search(int a[], int N, int key)
{
  int M = sqrt(N);
  int i = 0;
  // Jump segment
  // while (a[min(N, M) - 1] < key)
  // {
  //   i = M;
  //   M += sqrt(N);
  //   if (i >= N)
  //   {
  //     return -1;
  //   }
  // }
  int lo = 0;
  int hi = sqrt(N);

  while (a[min(N, hi) - 1] < key)
  {
    lo = hi;
    hi += sqrt(N);
    if (lo >= N)
    {
      return -1;
    }
  }

  // Linear search part
  // while (a[i] < key)
  // {
  //   i++;
  //   if (i == min(M, N))
  //   {
  //     return -1;
  //   }
  // }
  for (int k = lo; k < min(N, hi); k++)
  {
    if (a[k] == key)
    {
      return k;
    }
  }
  // if (a[i] == key)
  // {
  //   return i;
  // }
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
  int ind = jump_search(a, n, key);
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