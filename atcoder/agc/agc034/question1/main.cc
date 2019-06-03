#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_S 200001
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, A, B, C, D;
char s[MAX_S];

bool canOvertake()
{
  // 最初に C > D のときの難しいケースを考えないようにする
  // ... が３つないと A が B を抜かせないのでチェックする
  // 岩が２つつながってないかもチェックする
  if (C > D) {
    s[A] = 'A';
    s[B] = 'B';
  }
  int i = A, cnt = 0;
  int maxDot = 0;
  while (s[i] != '\0') {
    if (i >= D + 1) break;
    if (s[i] == '.') {
      ++cnt;
    }
    else {
      maxDot = max(cnt, maxDot);
      cnt = 0;
    }
    ++i;
  }
  maxDot = max(cnt, maxDot);

  s[A] = '.';
  s[B] = '.';
  if (C > D && maxDot < 3) {
    int cnt = 0, maxDot = 0;
    int i = A;
    while (i <= B + 1) {
      if (s[i] == '.') {
        ++cnt;
      }
      else {
        maxDot = max(cnt, maxDot);
        cnt = 0;
      }
      ++i;
    }
    maxDot = max(cnt, maxDot);
    if (maxDot >= 3 && B - A == 1) {
      return true;
    }
    cout << "No" << endl;
    return false;
  }
  return true;
}

void solve()
{
  if (!canOvertake()) return;

  bool ansa = false, ansb = false;
  int i = A, j = B;
  while (s[i] != '\0') {
    int nexta = 0, nextb = 0;
    if (i != C) {
      if (i + 1 == C)
        nexta = 1;
      else if (i + 2 == C)
        nexta = 2;
      else if (s[i + 2] != '\0' && (s[i + 2] == '.'))
        nexta = 2;
      else if (s[i + 1] != '\0' && (s[i + 1] == '.'))
        nexta = 1;
      else
        nexta = 0;
    }

    if (j != D) {
      if (j + 1 == D)
        nextb = 1;
      else if (j + 2 == D)
        nextb = 2;
      else if (s[j + 2] != '\0' && (s[j + 2] == '.'))
        nextb = 2;
      else if (s[j + 1] != '\0' && (s[j + 1] == '.'))
        nextb = 1;
      else
        nextb = 0;
    }

    if (nexta == 0 && nextb == 0) {
      break;
    }
    i += nexta;
    j += nextb;
    if (i == C) {
      ansa = true;
    }
    if (j == D) {
      ansb = true;
    }
  }

  if (ansa && ansb)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> A >> B >> C >> D;
  --A, --B, --C, --D;
  cin >> s;
  solve();
  return 0;
}
