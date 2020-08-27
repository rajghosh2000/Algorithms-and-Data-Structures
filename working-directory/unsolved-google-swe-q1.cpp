#include <bits/stdc++.h>
using namespace std;

int alpabetify(string S)
{
  int count = 0;
  char item, prev, next;
  for (unsigned int i = 1; i < S.size(); ++i)
  {
    item = S[i];
    next = S[i+1];
    if(item == next and i > 1 and prev != item){
      prev = 
    }
    if(item == next){ continue; }
    if(
      (S[i] > S[i+1] && S[i] < S[i-1]) || 
      (S[i] < S[i+1] && S[i] < S[i-1]) || 
      (S[i] == S[i-1] && S[i] > S[i+1] && S[i] > prev) ||
      (S[i] == S[i-1] && S[i] < S[i+1] && S[i] < prev)
      )
    {
      i++;
      count++;
    }
  }
  return count;
}
int main(int argc, char const *argv[])
{
  #ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
  #endif

  // Program starts here
  string S;
  cin >> S;
  int x = alpabetify(S);
  cout << x << endl;

  return 0;
}