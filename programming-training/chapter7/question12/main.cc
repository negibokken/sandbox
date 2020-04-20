#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Node {
  T value;
  Node *next;
  Node() {}
};

template <typename K, typename V>
class Map {
 private:
  vector<vector<Node<V> *>> values;
  int size;
  int getHash() {}

 public:
  Map(int size = 100) : size(size) { values.resize(size, NULL); }
  bool hasKey(K key) const {}
  V getValue(K key) const {
    int hash = getHash();
    values[hash];
  }
  vector<Node<V> *> &operator[](K key) { return values[getHash(key)]; }
};

class Array {
  int *p;
  int size;

 public:
  Array(int size) { p = (int *)malloc(sizeof(int) * size); }
  int &operator[](int i) { return p[i]; };
};

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Array a = Array(10);

  a[0] = 1;
  std::cout << a[0] << std::endl;

  return 0;
}
