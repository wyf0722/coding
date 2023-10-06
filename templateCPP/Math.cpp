#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 MOD = 1e9 + 7;
/**
 * 埃氏筛
 */
const int MX = 1e5 + 10;
vector<int> prime;
bool is_prime[MX + 1];
int init = []() -> int {
    for (int i = 0; i <= MX; i++) {
        is_prime[i] = 1;
    }
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i <= MX; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i; j <= MX / i; j++) {
                is_prime[i * j] = 0;
            }
        }
    }
    return 0;
}();

/**
 * 组合数（数量较小）
 */

i64 C(i64 a, int b) {
    i64 ans = 1LL;
    for (int i = 1; i <= b; i++) {
        ans = (ans * (a + 1 - i) / i) % MOD;
    }
    return ans;
}

/**
 * 快速幂
*/
i64 power(i64 a, int b) {
    i64 ans = 1LL;
    for (; b; b /= 2) {
        if (b & 1) ans = (ans * a) % MOD;
        a = a * a % MOD;
    }
    return ans;
}
