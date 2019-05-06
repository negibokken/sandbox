#include <iostream>
#include <list>
#include <queue>
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

void enqueueNodes(Node *node, queue<Node> &q)
{
  if (node == NULL) {
    return;
  }
  q.push(*node);
  if (node->left) {
    enqueueNodes(node->left, q);
  }
  if (node->right) {
    enqueueNodes(node->right, q);
  }
}

// calculate child depth of child nodes
int balance(Node *node)
{
  if (node == NULL) {
    return 0;
  }
  int left = balance(node->left) + 1;
  int right = balance(node->right) + 1;
  cout << left << right;
  return max(left, right);
}

bool isBalanced(Node *node)
{
  queue<Node> q;
  enqueueNodes(node, q);
  int left, right;

  while (!q.empty()) {
    Node n = q.front();
    q.pop();
    left = balance(n.left);
    right = balance(n.right);
    if (abs(left - right) > 1) {
      return false;
    }
  }
  return true;
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

  // createSameDepthList(root, l, 0);

  bool result = isBalanced(root);
  cout << (result ? "true" : "false") << endl;
  return 0;
}
