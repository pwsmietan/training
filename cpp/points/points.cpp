#include <iostream>

using namespace std;

// Is given point inside a given rectangle or not.
bool FindPoint(int x1, int y1, int x2, int y2, int x, int y)
{
  return (x > x1 && x < x2 && y > y1 && y < y2);
}

int main()
{
  // Define the bottom-left and top-right corners of rectangle:
  int x1 = 0, y1 = 0, x2 = 20, y2 = 10;
  int xVal, yVal;

  cout << "Type in your X location:" << endl;
  cin >> xVal;

  cout << "Type in your Y location:" << endl;
  cin >> yVal;

  // Test a given point:
  int x = xVal, y = yVal;

  if (FindPoint(x1, y1, x2, y2, x, y))
    cout << "You are completely surrounded. Don't move!";
  else
    cout << "You're out of reach!";

  return 0;
}