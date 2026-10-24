class Solution {
public:
    int HtoM(string time){
        int hour = stoi(time.substr(0,2));
        int min = stoi(time.substr(3,2));

        return (hour*60)+min;
    }
    int convertTime(string current, string correct) {
        int count = 0;
        int curr = HtoM(current);
        int corr = HtoM(correct);

        int diff = corr-curr;
        int ops[] = {60, 15, 5, 1};
        
        for (int op : ops) {
            count += diff / op;
            diff %= op;
        }
        
        return count;
    }
};