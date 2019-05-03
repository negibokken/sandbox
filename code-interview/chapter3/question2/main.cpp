#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct Element {
  int data;
  int min;
} Element;

class MinStack {
  private:
  vector<Element> a;

  public:
  MinStack() {}
  void push(int x)
  {
    int m;
    if (a.size() == 0) {
      m = x;
    }
    else {
      m = std::min(a.back().min, x);
    }
    Element e = {x, m};
    a.push_back(e);
  }
  void pop() { a.pop_back(); }
  int min()
  {
    if (a.size() == 0) {
      throw "NO_ELEMENT_ERROR";
    }
    return a.back().min;
  }
  ~MinStack() {}
};

int main(void)
{
  MinStack ms;

  ms.push(2);
  cout << ms.min() << endl;
  ms.push(1);
  cout << ms.min() << endl;
  ms.push(0);
  cout << ms.min() << endl;
  ms.pop();
  cout << ms.min() << endl;
  ms.push(99);
  cout << ms.min() << endl;
  ms.push(98);
  cout << ms.min() << endl;
  ms.push(-1);
  cout << ms.min() << endl;
  return 0;
}
