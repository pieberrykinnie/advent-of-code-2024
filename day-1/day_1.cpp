#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vi left;
    vi right;

    int l, r;
    while (cin >> l >> r) {
        left.push_back(l);
        right.push_back(r);
    }
    int n = left.size();

    ll sim = 0;

    map<int, int> table;

    REP(i,0,n) {
        if (table.find(right[i]) == table.end()) {
            table[right[i]] = 1;
        } else {
            table[right[i]] += 1;
        }
    }

    REP(i,0,n) {
        if (table.find(left[i]) != table.end()) {
            sim += left[i] * table.at(left[i]);
        }
    }

    cout << sim;

    return 0;
}
