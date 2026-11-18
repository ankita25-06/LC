class Solution {
public:
    int getLucky(string s, int k) {
       
        string n = "";
        for(char c : s){
            n += to_string(c-'a'+1);
        }

        int sum = 0;
        for (char c : n) {
            sum += c - '0';
        }
        k--; 
        while (k > 0 && sum >= 10) {
            int nextSum = 0;
            while (sum > 0) {
                nextSum += sum % 10;
                sum /= 10;
            }
            sum = nextSum;
            k--;
        }
        
       
        while (k > 0) {
            int nextSum = 0;
            while (sum > 0) {
                nextSum += sum % 10;
                sum /= 10;
            }
            sum = nextSum;
            k--;
        }
        
        return sum;
    }
};