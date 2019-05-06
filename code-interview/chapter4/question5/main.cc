#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

typedef struct Node {
  int data;
  Node *left;
  Node *right;
  Node *parent;
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
  if (n->left != NULL) {
    n->left->parent = n;
  }
  n->right = buildBST(arr, mid + 1, end);
  if (n->right != NULL) {
    n->right->parent = n;
  }
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

bool isBST(Node *head)
{
  queue<Node *> q;
  q.push(head);
  while (!q.empty()) {
    Node *n = q.front();
    q.pop();
    if (n->left != NULL) {
      // 左の子ノードの方が親ノードより大きい場合は BST ではないので return
      // false
      if (n->left->data > n->data) {
        return false;
      }
      q.push(n->left);
    }
    if (n->right != NULL) {
      // 右の子ノードの方が親ノードより小さい場合は BST ではないので return
      // false
      if (n->right->data < n->data) {
        return false;
      }
      q.push(n->right);
    }
  }
  return true;
}

Node *proceedLeft(Node *node)
{
  Node *next = NULL;
  queue<Node *> q;
  q.push(node);
  while (!q.empty()) {
    Node *n = q.front();
    q.pop();
    if (n->left == NULL) {
      next = n;
      return next;
    }
    q.push(n->left);
  }
  return next;
}

Node *findNextNode(Node *node)
{
  Node *next;

  // 左の子 \ 右の子| あり | なし
  //  あり          |   1  |  2
  //  なし          |   3  |  4
  //  1
  if (node->left != NULL && node->right != NULL) {
    // Find Node that doesn't have left child (NULL) from **right node (start is
    // node->right)**
    next = proceedLeft(node->right);
    return next;
  }
  // 2
  if (node->left != NULL && node->right == NULL) {
    // Find Node that doesn't have left child (NULL) from **left node (start is
    // node->left)**
    next = proceedLeft(node->left);
    return next;
  }
  // 3
  if (node->left == NULL && node->right != NULL) {
    // Find Node that doesn't have left child (NULL) from **right node (start is
    // node->right)**
    next = proceedLeft(node->right);
    return next;
  }
  // 4
  if (node->left == NULL && node->right == NULL) {
    // Only root tree
    if (node->parent == NULL) {
      return NULL;
    }
    // If the node is left child for parent node then parent is next
    if (node->parent->left == node) {
      return node->parent;
    }
    // In the other hand, the node is right child for parent node then find
    // parent node that has another right node
    queue<Node *> q;
    Node *prev;
    q.push(node->parent);
    while (!q.empty()) {
      Node *n = q.front();
      q.pop();
      // parent が NULL ならそれを返す
      if (n->parent == NULL) {
        return n;
      }
      // 親が自分じゃない右のノードを持っていたらそのノード
      if (n->parent->right != n) {
        return n->parent;
      }
      q.push(n);
    }
  }
  // 実際にはここにはこない
  return NULL;
}

Node *findNode(Node *root, int target)
{
  Node *cur = root;
  vector<Node *> s;
  s.push_back(root);
  while (!s.empty()) {
    Node *n = s.back();
    s.pop_back();
    if (n->data == target) {
      return n;
    }
    if (n->right != NULL) {
      s.push_back(n->right);
    }
    if (n->left != NULL) {
      s.push_back(n->left);
    }
  }
  return NULL;
}

int main(void)
{
  int n, target;
  cin >> n;
  cin >> target;

  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  Node *root = NULL;

  int start = 0;
  int end = arr.size() - 1;
  root = buildBST(arr, start, end);

  Node *node = findNode(root, target);
  Node *next = findNextNode(node);
  if (next == NULL) {
    cout << "NULL" << endl;
  }
  else {
    cout << next->data << endl;
  }
  return 0;
}
