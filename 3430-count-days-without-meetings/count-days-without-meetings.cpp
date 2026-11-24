class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());

        
        long long busyDays = 0;
        long long currStart = meetings[0][0];
        long long currEnd = meetings[0][1];

        for(int i = 1;i<n;i++){
            long long start = meetings[i][0];
            long long end = meetings[i][1];

            if (start <= currEnd) {
                currEnd = max(currEnd, end);
            } else {
                busyDays += (currEnd - currStart + 1);
                currStart = start;
                currEnd = end;
            }
        }

        busyDays += (currEnd - currStart + 1);
        return static_cast<int>(days - busyDays);
    }
};