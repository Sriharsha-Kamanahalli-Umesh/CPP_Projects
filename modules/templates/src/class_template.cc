#include <iostream>
using namespace std;

template <class T>
class myPair
{
  T x, y;

public:
  myPair(T first, T second)
  {
    x = first;
    y = second;
  }

public:
  T add()
  {
    T result;
    result = x + y;
    return result;
  }
};

int main()
{
  myPair<int> intPair(3, 7);
  myPair<double> doublePair(3.5, 7.2);
  myPair<string> stringPair("Hello", " World!");

  cout << intPair.add() << endl;
  cout << doublePair.add() << endl;
  cout << stringPair.add() << endl;

  return 0;
}