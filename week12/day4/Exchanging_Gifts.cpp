#include <iostream>
#include <vector>
using namespace std;

void find_youngest_member(int n, int m, vector<pair<int, int>> &gifts) {
    vector<bool> vis(n, false);
    vector<int> rec(n, 0);

    for (int i = 0; i < m; i++) {
        int a = gifts[i].first;
        int b = gifts[i].second;
        vis[a - 1] = true;
        rec[b - 1]++;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && rec[i] == n - 1) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> gifts(m);

    for (int i = 0; i < m; ++i) {
        cin >> gifts[i].first >> gifts[i].second;
    }

    find_youngest_member(n, m, gifts);
    return 0;
}

//approach
// first, I observed that every gift is given from a → b, which means b is receiving the gift.

// The youngest member will be the one:

// who receives gifts from everyone
// and does not give any gift

// So if there are n members, the youngest person should receive n-1 gifts.

// Now the problem is: how to find how many gifts each person received?

// For that, I used one array:

// rec[i] → tells how many gifts person i received

// Example:

// 3 2
// 1 3
// 2 3

// So:

// rec = [0, 0, 2]
//        1  2  3

// This shows that person 3 received 2 gifts, which is n-1 = 2, so 3 can be the youngest.

// Now we also need to check who did not give any gift
// because youngest person never gives gifts.

// For that, I used another array:

// vis[i] = true → means person i gave at least one gift

// Example:

// vis = [true, true, false]
//        1     2     3

// This means:

// person 1 gave gift
// person 2 gave gift
// person 3 did NOT give any gift