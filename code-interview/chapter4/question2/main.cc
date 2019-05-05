#include <iostream>
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

  visit(root);
  return 0;
}
