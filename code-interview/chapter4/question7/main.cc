#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct Node {
  char data;
} Node;

typedef struct Edge {
  char src;
  char dst;
} Edge;

void dependencyParser(char *buf, vector<Edge> &arr)
{
  int i = 0;
  while (buf[i] != '\0') {
    if (buf[i] == '(') {
      ++i;
      while (buf[i] != ')') {
        Edge e;
        e.src = buf[i];  // 'a'
        i += 3;          // ' ,'
        e.dst = buf[i];  // 'b'
        arr.push_back(e);
        ++i;
      }
    };
    ++i;
  }
}

void addDependent(vector<Node> &arr, char src, char dst)
{
  for (vector<Node>::iterator i = arr.begin(); i != arr.end(); ++i) {
    if (i->data == src) {
    }
  }
}

Node *findNode(vector<Node> arr, char c)
{
  Node *node;
  for (vector<Node>::iterator i = arr.begin(); i != arr.end(); ++i) {
    if (i->data == c) {
      node = &(*i);
      return node;
    }
  }
  return node;
}

void delDependent(vector<Edge> &dep, char c) {}

map<char, bool> updateNodeps(vector<Node> nodes, vector<char> updates,
                             vector<Edge> dep, char c)
{
  map<char, bool> depmap;
  for (auto i : nodes) depmap[i.data] = true;
  for (vector<Edge>::iterator i = dep.begin(); i != dep.end(); ++i) {
    if (i->src == c) {
      dep.erase(i);
    }
  }
  for (auto i : dep) {
    depmap[i.src] = false;
  }
}

bool buildOrder(vector<Node> nodes, vector<Edge> dep, vector<Node> &orderl)
{
  map<char, bool> depmap, orderedmap;
  for (auto n : nodes) {
    depmap[n.data] = true;
    orderedmap[n.data] = false;
  }
  for (vector<Edge>::iterator i = dep.begin(); i != dep.end(); ++i) {
    depmap[i->dst] = false;
  }
  vector<char> nodeps;
  for (map<char, bool>::iterator i = depmap.begin(); i != depmap.end(); ++i) {
    if (i->second) {
      nodeps.push_back(i->first);
    }
  }

  while (1) {
    if (nodes.size() == orderl.size()) break;  // Add all nodes
    if (!nodeps.size()) break;                 // No update
    while (!nodeps.empty()) {
      char c = nodeps.back();
      nodeps.pop_back();
      orderl.push_back(*findNode(nodes, c));
      depmap = updateNodeps(nodeps, dep, c);
    }
  }
  // add no dependent node
  // update dependent
  // add no dependent node

  // 依存関係が解決されたことで追加できるノードを見る
  // を繰り返すのが理想

  for (auto i : orderl) cout << i.data << endl;

  // サイズが一致していれば true: 正常終了
  // そうでなければ false
  return orderl.size() == nodes.size();
}

int main(void)
{
  int n, d;
  scanf("%d %d%*c", &n, &d);

  vector<Node> orderl;

  char c;
  vector<Node> arr(n);
  map<char, bool> visited;
  for (int i = 0; i < n; ++i) {
    scanf("%c ", &c);
    Node n;
    n.data = c;
    arr[i] = n;
    visited[c] = false;
  }

  vector<Edge> dep;
  char *buf = (char *)malloc(sizeof(char) * 256);
  char *cc = fgets(buf, 255, stdin);
  dependencyParser(buf, dep);
  buildOrder(arr, dep, orderl);

  return 0;
}
