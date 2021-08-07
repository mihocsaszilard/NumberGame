#include <iostream>
#include <conio.h>

using namespace std;

int random(int[], int);
int write(int[], int, int);
int evenorodd(int[], int);

int main()
{
  int n, t[100], winner, right, left;
  cout << " How many turns do you want? Type here:  ";
  cin >> n;

  random(t, 2 * n);
  write(t, 0, (2 * n) - 1);
  winner = evenorodd(t, 2 * n);
  right = (2 * n) - 1;
  left = 0;

  int pc = 0, user = 0;
  char c;

  for (int i = 0; i <= n; ++i)
  {
    if (right % 2 == winner)
    {
      pc += t[right];
      --right;
    }
    else
    {
      pc += t[left];
      ++left;
    }
    write(t, left, right);
    cout << " Choose, (l)eft or (r)ight!";
    c = getch();

    if (c == 'j')
    {
      user += t[right];
      --right;
    }
    else
    {
      user += t[left];
      ++left;
    }
  }
  cout << " PC's result = " << pc << endl;
  cout << " User's result = " << user << endl;
}
int evenorodd(int t[], int n)
{
  int even = 0, odd = 0;

  for (int i = 0; i <= n; i += 2)
  {
    odd += t[i];
    even += t[i + 1];
  }
  return odd > even;
}
