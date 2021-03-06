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

int main(void)
{
  int n;
  cin >> n;

  if (n < 1) {
    return 1;
  }
  Node *head = NULL;

  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    head = apendNode(head, x);
  }

  deleteRedundant(head);
  showNode(head);

  return 0;
}
