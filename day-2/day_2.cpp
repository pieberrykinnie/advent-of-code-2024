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

    string line;
    int curr, prev;
    int count = 0;

    while (getline(cin, line) && !line.empty()) {
        stringstream s(line);
        bool safe = true;
        bool first = true;
        bool ascending;

        s >> prev;

        while (safe && s >> curr) {
            int diff = curr - prev;

            if (first) {
                safe = abs(diff) >= 1 && abs(diff) <= 3;

                if (safe) {
                    ascending = diff > 0;
                }

                first = false;
            } else {
                safe = !ascending && diff >= -3 && diff <= -1 || ascending && diff >= 1 && diff <= 3;
            }

            prev = curr;
        }

        if (safe) count++;
    }

    cout << count;

    return 0;
}
