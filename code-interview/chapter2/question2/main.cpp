#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *newNode(int x)
{
  Node *node;
  if ((node = (Node *)malloc(sizeof(Node))) == NULL) {
    cerr << "malloc Error" << endl;
    return NULL;
  }
  node->data = x;
  node->next = NULL;
  return node;
}

Node *apendNode(Node *head, int x)
{
  if (head == NULL) {
    head = newNode(x);
    return head;
  }

  int j = 0;
  Node *p;
  for (p = head; p->next != NULL; p = p->next) {
    j++;
  }
  p->next = newNode(x);
  return head;
}

void showNode(Node *head)
{
  for (Node *p = head; p != NULL; p = p->next) {
    cout << p->data;
    if (p->next != NULL) {
      cout << " ";
    }
  }
}

void deleteRedundant(Node *head)
{
  map<int, int> m;
  Node *prev;
  for (Node *p = head; p != NULL; p = p->next) {
    m[p->data]++;
    if (m[p->data] > 1) {
      prev->next = p->next;
    }
    else {
      prev = p;
    }
  }
}

Node *backAt(Node *head, int k)
{
  Node *cur;
  if (head == NULL) {
    return NULL;
  }
  int n = 0;
  cur = head;
  while (cur != NULL) {
    cur = cur->next;
    ++n;
  }

  // return NULL if invalid input k
  if (k > n) {
    return NULL;
  }

  cur = head;
  int frk = n - k;
  while (cur->next != NULL) {
    if (frk <= 0) {
      break;
    }
    cur = cur->next;
    --frk;
  }
  return cur;
}

int main(void)
{
  int n, k;
  cin >> n >> k;

  if (n < 1) {
    return 1;
  }
  Node *head = NULL;

  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    head = apendNode(head, x);
  }

  Node *at = backAt(head, k);
  cout << at->data << endl;
  // showNode(head);
  return 0;
}
