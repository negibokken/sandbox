#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SetOfStacks {
  private:
  int th;
  int idx = 0;
  vector<vector<T>> stacks;

  public:
  SetOfStacks(int n)
  {
    th = n;
    vector<T> stack;
    stacks.push_back(stack);
  }
  void push(T x)
  {
    if (idx == -1 || stacks[idx].size() >= th) {
      // Create next stack
      vector<T> stack;
      // Index is next
      ++idx;
      stack.push_back(x);
      stacks.push_back(stack);
    }
    else {
      stacks[idx].push_back(x);
    }
  }
  void pop()
  {
    if (idx == -1) {
      return;
    }
    if (stacks[idx].size() <= 0) {
      // Next Stack
      --idx;
      // Set is empty
      if (idx < 0) {
        return;
      }
      // Next stack is empty
      if (stacks[idx].size() <= 0) {
        return;
      }
    }

    stacks[idx].pop_back();

    if (stacks[idx].size() <= 0) {
      --idx;
    }
  }
  void popAt(int n)
  {
    // Index Error
    if (n > idx || n < 0) {
      return;
    }
    // Target Stack is already empty
    if (stacks[n].size() <= 0) {
      return;
    }

    stacks[n].pop_back();

    // Stack is not empty
    if (stacks[n].size() > 0) {
      return;
    }

    // Stack is empty then
    for (int i = n; i < idx; ++i) {
      stacks[i] = stacks[i + 1];
    }
  }
  T peek()
  {
    if (idx < 0) {
      throw "SETOFSTACK_EMPTY_ERROR";
    }
    if (stacks[idx].size() <= 0) {
      throw "STACK_EMPTY_PEEK_ERROR";
    };
    return stacks[idx].back();
  }
  int num() { return idx + 1; }
  ~SetOfStacks() {}
};

int main(void) try {
  SetOfStacks<int> s(5);
  cout << "#SetOfStack: " << s.num() << endl;
  for (int i = 0; i < 25; ++i) {
    s.push(i);
  }
  cout << "exec popAt" << endl;
  s.popAt(1);
  cout << "#SetOfStack: " << s.num() << endl;
  for (int i = 0; i < 25; ++i) {
    cout << s.peek() << endl;
    s.pop();
  }
  cout << "#SetOfStack: " << s.num() << endl;

  return 0;
}
catch (const char* e) {
  cerr << e << endl;
}
