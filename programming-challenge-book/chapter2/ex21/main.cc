#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int heap[MAX_N], sz = 0;

void push(int x)
{
  int i = sz++;
  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap[p] <= x) break;
    heap[i] = heap[p];
    i = p;
  }
  heap[i] = x;
}

int pop()
{
  int ret = heap[0];
  int x = heap[--sz];
  int i = 0;
  while (i * 2 + 1 < sz) {
    int a = i * 2 + 1, b = i * 2 + 2;
    if (b < sz && heap[b] < heap[a]) a = b;

    if (heap[a] >= x) break;

    heap[i] = heap[a];
    i = a;
  }
  heap[i] = x;
  return ret;
}

int n;
int x[MAX_N];

int main(void)
{
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d ", &x[i]);
    push(x[i]);
  }
  for (int i = 0; i < n; ++i) {
    int y = pop();
    printf("%d", y);
  }
  return 0;
}
