#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyQueue {
  private:
  vector<T> s1, s2;

  public:
  void add(T x) { s1.push_back(x); }
  void remove()
  {
    if (s1.size() == 0) {
      throw "QUEUE_EMPTY_ERROR";
    }
    while (!s1.empty()) {
      // Remove Last one
      if (s1.size() != 1) {
        s2.push_back(s1.back());
      }
      s1.pop_back();
    }
    while (!s2.empty()) {
      s1.push_back(s2.back());
      s2.pop_back();
    }
  }
  T peek()
  {
    if (s1.size() == 0) {
      throw "QUEUE_EMPTY_ERROR";
    }
    while (!s1.empty()) {
      s2.push_back(s1.back());
      s1.pop_back();
    }
    T result = s2.back();
    while (!s2.empty()) {
      s1.push_back(s2.back());
      s2.pop_back();
    }
    return result;
  }
  bool isEmpty() { return s1.size() == 0; }
};

int main(void) try {
  MyQueue<int> q;
  for (int i = 0; i < 10; ++i) {
    q.add(i);
  }
  for (int i = 0; i < 10; ++i) {
    cout << q.peek() << endl;
    q.remove();
  }
  cout << "Empty: " << (q.isEmpty() ? "true" : "false") << endl;
  return 0;
}
catch (char *s) {
  cerr << s << endl;
}
