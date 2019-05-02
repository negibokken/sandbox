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

Node *apendNode(Node *head, Node *n)
{
  if (head == NULL) {
    head = n;
    return head;
  }

  int j = 0;
  Node *p;
  for (p = head; p->next != NULL; p = p->next) {
    j++;
  }
  p->next = n;
  return head;
}

void showNode(Node *head, bool flag = false)
{
  for (Node *p = head; p != NULL; p = p->next) {
    if (flag) {
      cout << "addr: " << p << ", data:" << p->data << ", p->next: " << p->next
           << endl;
    }
    else {
      cout << p->data;
      if (p->next != NULL) {
        cout << " ";
      }
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

// Delete target Node
void deleteNode(Node *delNode)
{
  if (delNode == NULL) {
    return;
  }
  delNode->data = delNode->next->data;
  delNode->next = delNode->next->next;
  return;
}

Node *searchNode(Node *head, char c)
{
  Node *p = head;
  while (p != NULL) {
    if (p->data == c) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

Node *divideNode(Node *node, int e)
{
  Node *head = node;
  Node *tail = node;

  while (node != NULL) {
    Node *next = node->next;
    if (node->data < e) {
      node->next = head;
      head = node;
    }
    else {
      tail->next = node;
      tail = node;
    }
    node = next;
  }
  tail->next = NULL;
  return head;
}

Node *sumNodes(Node *term1, Node *term2)
{
  Node *ans = NULL;
  Node *t1 = term1;
  Node *t2 = term2;
  int curry = 0;
  Node *prev = NULL;
  while (t1 != NULL) {
    int x = t1->data + t2->data + curry;

    curry = x / 10;
    ans = apendNode(ans, x % 10);

    t1 = t1->next;
    t2 = t2->next;
  }
  if (curry > 0) {
    ans = apendNode(ans, 1);
  }
  return ans;
}

bool rotateCheck(Node *head)
{
  Node *cur = head;
  vector<char> c;
  while (cur != NULL) {
    c.push_back(cur->data);
    cur = cur->next;
  }
  cur = head;
  while (cur != NULL) {
    char ele = c.back();
    c.pop_back();
    if (ele != cur->data) {
      return false;
    }
    cur = cur->next;
  }
  return true;
}
Node *hasSameNode(Node *head1, Node *head2)
{
  Node *p = head1;
  map<long, int> refs;
  while (p != NULL) {
    refs[(long long)p]++;
    p = p->next;
  }

  p = head2;
  while (p != NULL) {
    if (refs.count((long long)p) > 0) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

int main(void)
{
  int n, k;
  cin >> n >> k;

  if (n < 1) {
    return 1;
  }
  Node *head = NULL;
  Node *head2 = NULL;

  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    head = apendNode(head, x);
    head2 = apendNode(head2, x);
  }

  Node t;
  t.data = k;
  t.next = NULL;

  // Save same Node into two lists
  head = apendNode(head, &t);
  head2 = apendNode(head2, &t);

  // check then
  Node *node = hasSameNode(head, head2);
  cout << node->data << endl;

  return 0;
}
