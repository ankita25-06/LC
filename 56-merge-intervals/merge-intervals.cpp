class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        int n = intervals.size();
        vector<vector<int>> A;
        A.push_back(intervals[0]);

        
        for(size_t j = 1;j < n;j++){
            int start = intervals[j][0];
            int end = intervals[j][1];
            if (start <= A.back()[1]) {
                A.back()[1] = max(A.back()[1], end);
            } else {
                A.push_back({start, end});
            }
        }

        return A;
    }
};