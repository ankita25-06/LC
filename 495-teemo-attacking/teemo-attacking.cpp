class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = duration;
        int currTime;
        for(int i = 1;i<timeSeries.size();i++){
            currTime = timeSeries[i-1];
            int temp = duration;
            while(temp != 0 && currTime != timeSeries[i]){
                currTime++;
                time++;
                temp--;
            }
        }

        return time;
    }
};