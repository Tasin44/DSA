

//This question is very hard, will understand it later, but it's not much important
//https://youtu.be/KCEPvdLqlYI?feature=shared

//https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2, vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();

        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    void backtrack(int i, int j, string& s, string& t, vector<vector<int>>& dp, string& current, set<string>& result) {
        if (i == 0 || j == 0) {
            result.insert(current);
            return;
        }

        if (s[i - 1] == t[j - 1]) {
            current += s[i - 1];
            backtrack(i - 1, j - 1, s, t, dp, current, result);
            current.erase(0, 1); // Remove the last added character for other branches
        } else {
            if (dp[i - 1][j] == dp[i][j]) backtrack(i - 1, j, s, t, dp, current, result);
            if (dp[i][j - 1] == dp[i][j]) backtrack(i, j - 1, s, t, dp, current, result);
        }
    }

    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        longestCommonSubsequence(s, t, dp);

        set<string> result;
        string current;
        backtrack(n, m, s, t, dp, current, result);

        return vector<string>(result.begin(), result.end());
    }
};

int main() {
    string s = "abaaa";
    string t = "baabaca";

    Solution obj;
    vector<string> lcs = obj.all_longest_common_subsequences(s, t);

    for (const string& str : lcs) {
        cout << str << endl;
    }

    return 0;
}
