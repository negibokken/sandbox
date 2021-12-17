#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

// Self settings
// clang-format off
// #define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

const int MAX_N = 1 << 17;

int n, dat[2 * MAX_N - 1];

void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    // base nodes and other parent nodes
    for (int i = 0; i < 2 * n - 1; i++) dat[i] = INT_MAX;
}

void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INT_MAX;
    if (a <= l && r <= b)
        return dat[k];
    else {
        int vl = query(a, b, k * 2 + 1, 1, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    }
    return min(vl, vr);
}

int main(void) { return 0; }
