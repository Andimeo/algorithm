#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100000 + 4;
const int n_alpha = 26;

int post[maxn][n_alpha];
int dp[254][254][254];
vector<int> r[3];

void update(int i, int j, int k) {
    int ans = -1;
    if (i > 0 && dp[i-1][j][k] != -1) {
        int ret = post[dp[i-1][j][k]][r[0][i-1]];
        if (ret != -1 && (ans == -1  || ret < ans))
            ans = ret;
    }
    if (j > 0 && dp[i][j-1][k] != -1) {
        int ret = post[dp[i][j-1][k]][r[1][j-1]];
        if (ret != -1 && (ans == -1 || ret < ans))
            ans = ret;
    }
    if (k > 0 && dp[i][j][k-1] != -1) {
        int ret = post[dp[i][j][k-1]][r[2][k-1]];
        if (ret != -1 && (ans == -1 || ret < ans))
            ans = ret;
    }
    dp[i][j][k] = ans;
}

int main(void) {
    int n, q;
    while (cin >> n >> q) {
        memset(post, -1, sizeof(post));
        r[0].clear();
        r[1].clear();
        r[2].clear();
        string word;
        cin >> word;
        for (int i = n - 1 ; i >= 0 ; i--) {
            for (int j = 0 ; j < n_alpha; j++) {
                post[i][j] = post[i + 1][j];
            }
            post[i][word[i] - 'a'] = i + 1;
        }
        
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        for (int o = 0 ; o < q; o++) {
            string op;
            int pos;
            cin >> op >> pos;
            pos--;
            string letter;
            int n1[3];
            n1[0] = r[0].size();
            n1[1] = r[1].size();
            n1[2] = r[2].size();
            if (op == "+") {
                cin >> letter;
                r[pos].push_back(letter[0] - 'a');
            } else {
                r[pos].pop_back();
            }
            int n2[3];
            n2[0] = r[0].size();
            n2[1] = r[1].size();
            n2[2] = r[2].size();
            if (op == "+") {
                int v = letter[0] - 'a';
                int p = n2[pos] - 1;
                if (pos == 0) {
                    for (int j = 0; j <= n2[1]; j++) {
                        for (int k = 0 ; k <= n2[2]; k++) {
                            update(p+1, j, k);
                        }
                    }
                }
                if (pos == 1) {
                    for (int i = 0; i <= n2[0]; i++) {
                        for (int k = 0 ; k <= n2[2]; k++) {
                            update(i,p+1,k);
                        }
                    }
                }
                if (pos == 2) {
                    for (int i = 0; i <= n2[0]; i++) {
                        for (int j = 0 ; j <= n2[1]; j++) {
                            update(i,j,p+1);
                        }
                    }
                }
                if (dp[n2[0]][n2[1]][n2[2]] == -1) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            } else {
                if (dp[n2[0]][n2[1]][n2[2]] == -1) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}
