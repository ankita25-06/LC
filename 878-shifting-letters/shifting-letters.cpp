class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long currentShift = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            currentShift = (currentShift + shifts[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + currentShift) % 26;
        }
        return s;
    }
};