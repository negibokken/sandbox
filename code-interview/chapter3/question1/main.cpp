#include <iostream>
using namespace std;

#define MAX_SIZE 10 * 3

template <typename T>
class Stack3 {
  private:
  T arr[MAX_SIZE];
  int idx[3] = {-1, -1, -1};

  public:
  Stack3()
  {
    for (int i = 0; i < MAX_SIZE; ++i) {
      arr[i] = 0;
    }
  }
  void push(T x, int n)
  {
    if (idx[n] >= (MAX_SIZE / 3) - 1) {
      throw "MAX_SIZE_OVER_ERROR";
    }
    ++idx[n];
    arr[(3 * idx[n] + n)] = x;
    return;
  }
  void pop(int n)
  {
    if (idx[n] < 0) {
      throw "NO_ELEMENT_ERROR";
    }
    --idx[n];
  }
  T peek(int n)
  {
    if (idx[n] < 0) {
      throw "NO_ELEMENT_ERROR";
    }
    return arr[((3 * idx[n]) + n)];
  }
  bool isEmpty(int n) { return idx[n] == -1; }
  ~Stack3() {}
};

int main(void)
{
  Stack3<int> s;
  for (int i = 0; i < MAX_SIZE / 3; ++i) {
    s.push(i, 0);
    s.push(i * 2, 1);
    s.push(i * 3, 2);
  }

  for (int i = 0; i < 3; ++i) {
    cout << i << " isEmpty: " << s.isEmpty(i) << endl;
  }

  for (int i = 0; i < MAX_SIZE / 3; ++i) {
    cout << i << ": 0 "
         << " peek: " << s.peek(0) << endl;
    s.pop(0);

    cout << i << ": 1 "
         << " peek: " << s.peek(1) << endl;
    s.pop(1);

    cout << i << ": 2 "
         << " peek: " << s.peek(2) << endl;
    s.pop(2);
  }

  for (int i = 0; i < 3; ++i) {
    cout << i << " isEmpty: " << s.isEmpty(i) << endl;
  }
  return 0;
}
