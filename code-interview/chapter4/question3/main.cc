#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef struct Node {
  int data;
  Node *left;
  Node *right;
} Node;

Node *buildBST(vector<int> arr, int start, int end)
{
  if (end < start) {
    return NULL;
  }

  int mid = (end + start) / 2;
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = arr[mid];
  n->left = buildBST(arr, start, mid - 1);
  n->right = buildBST(arr, mid + 1, end);
  return n;
}

void visit(Node *node)
{
  if (node == NULL) {
    return;
  }
  visit(node->left);
  cout << node->data << " ";
  visit(node->right);
}

void createSameDepthList(Node *node, vector<list<Node>> &l, int depth)
{
  if (node == NULL) {
    return;
  }
  if (l.empty() || (l.size() - 1) < depth) {
    list<Node> ll;
    l.push_back(ll);
  }
  l[depth].push_back(*node);
  ++depth;
  if (node->left != NULL) {
    createSameDepthList(node->left, l, depth);
  }
  if (node->right != NULL) {
    createSameDepthList(node->right, l, depth);
  }
}

int main(void)
{
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  Node *root = NULL;

  int start = 0;
  int end = arr.size() - 1;
  root = buildBST(arr, start, end);

  vector<list<Node>> l;
  // visit(root);
  createSameDepthList(root, l, 0);
  for (int i = 0; i < l.size(); ++i) {
    cout << "depth:" << i << ",";
    ;
    list<Node> lst = l[i];
    for (auto j = lst.begin(); j != lst.end(); ++j) {
      cout << j->data << ",";
    }
  }
  return 0;
}
