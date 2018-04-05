/*
Problem Name:   ZigZag
Used In:        TCCC '03 Semifinals 3
Used As:        Division I Level One
Categories:     Dynamic Programming

https://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259
*/

#include <vector>

using namespace std;

class ZigZag {
public:
    int longestZigZag(vector<int> sequence);
};

int ZigZag::longestZigZag(vector<int> sequence) {
    if (sequence.size() == 1) return 1;

    vector<int> dp(sequence.size());

    int lastDiference = 0;

    dp[0] = 1;

    for (size_t i = 1; i < sequence.size(); i++) {
        int currentDiference = sequence[i] - sequence[i - 1];

        dp[i] = dp[i - 1];

        if (currentDiference == 0) continue;

        if ((currentDiference > 0 && lastDiference <= 0) || (currentDiference < 0 && lastDiference >= 0)) {
            dp[i] += 1;
        }

        lastDiference = currentDiference;
    }

    return dp.back();
}
