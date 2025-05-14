

///https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, mxlen = 0;
        unordered_map<char, int> mp;

        while (r < s.size()) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {  // the element is in the map
                l = mp[s[r]] + 1;
            }
            mxlen = max(mxlen, r - l + 1);
            mp[s[r]] = r;
            r += 1;
        }

        return mxlen;
    }
};

// Main function for testing
int main() {
    Solution solution;
    string s;

    cout << "Enter a string: ";///abcabcbb
    cin >> s;

    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}

/*

Time Complexity: O(n)-where nn is the length of the input string s.
*The operations inside the loop, such as finding and updating elements
in the unordered_map, are average O(1) operations due to the hash table
implementation of the unordered_map.

Space Complexity: O(min(m, n))
where m is the size of the character set(map) and n is the length of the string.


When to use unordered set and map
1. Use unordered_set when you only need to check the presence of elements.
2. Use unordered_map when you need to associate additional data
(like the last occurrence index) with each key.

*/
