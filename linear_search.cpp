#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(N)
// Space complexity : O(1)

int linear_search(int a[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] == key)
    {
      return i;
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
  cout << "Enter key value ";
  int key;
  cin >> key;
  int ind = linear_search(a, n, key);
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