#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
//   // for getting input from input.txt
//   freopen("input.txt", "r", stdin);
//   // for writing output to output.txt
//   freopen("output.txt", "w", stdout);
// #endif

  // Program starts here
  unsigned long long int count = 0;
  unsigned int array_size;
  cin >> array_size;
  std::vector<int> v;
  for (unsigned int i = 0; i < array_size; ++i)
  {
    unsigned long long int temp;
    cin >> temp;
    v.push_back(temp);
  }

  for (unsigned int i = 1; i < array_size; ++i)
  {
    unsigned long long int temp;
    if (v[i] < v[i - 1]) {
      // temp = prev - current
      temp =  v[i - 1] - v[i];
      // current = prev
      v[i] = v[i - 1];
      // count += temp
      count = count + temp;

    }
  }

  cout << count << endl;



  return 0;
}