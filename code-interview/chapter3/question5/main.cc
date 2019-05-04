#include <iostream>
#include <random>
#include <vector>
using namespace std;

template <typename T>
class SortedStack {
  private:
  vector<T> s1, tmp;

  public:
  SortedStack() {}
  void push(T x)
  {
    while (!s1.empty()) {
      if (x <= s1.back()) {
        break;
      }
      tmp.push_back(s1.back());
      s1.pop_back();
    }
    s1.push_back(x);
    while (!tmp.empty()) {
      s1.push_back(tmp.back());
      tmp.pop_back();
    }
  }
  void pop()
  {
    if (s1.empty()) {
      return;
    }
    s1.pop_back();
  }
  T peek() { return s1.back(); }
  ~SortedStack() {}
};

int main(void)
{
  random_device rnd;
  SortedStack<int> s;
  for (int i = 0; i < 10; ++i) {
    int rnum = rnd() * 100 % 100;
    cout << "push: " << rnum << endl;
    s.push(rnum);
  }
  for (int i = 0; i < 10; ++i) {
    cout << s.peek() << endl;
    s.pop();
  }
  return 0;
}
