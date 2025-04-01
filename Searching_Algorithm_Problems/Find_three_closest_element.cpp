#include <bits/stdc++.h>
using namespace std;
int BS(int arr[], int n, int key)
{
  int lo = 0;
  int hi = n - 1;
  int val = INT_MAX;
  int ans;
  while (lo <= hi)
  {
    int mid = hi - (hi - lo) / 2;
    if (val >= abs(arr[mid] - key))
    {
      val = abs(arr[mid] - key);
      ans = arr[mid];
      hi = mid - 1;
    }
    else
    {
      lo = mid + 1;
    }
  }
  return ans;
}
int main()
{

  int p, q, r;
  cin >> p >> q >> r;
  int a[p], b[q], c[r];

  for (int i = 0; i < p; i++)
    cin >> a[i];

  for (int j = 0; j < q; j++)
    cin >> b[j];

  for (int k = 0; k < r; k++)
    cin >> c[k];

  sort(a, a + p);
  sort(b, b + q);
  sort(c, c + r);
  vector<int> ans;
  int dif = INT_MAX;
  for (int i = 0; i < p; i++)
  {
    int key = a[i];
    int val1 = BS(b, q, key);
    int val2 = BS(c, r, key);

    if (max({abs(key - val1), abs(key - val2), abs(val1 - val2)}) < dif)
    {
      dif = max({abs(key - val1), abs(key - val2), abs(val1 - val2)});
      if (ans.size() != 0)
      {
        ans.clear();
      }
      ans.push_back(key);
      ans.push_back(val1);
      ans.push_back(val2);
    }
  }

  for (int i = 0; i < 3; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}