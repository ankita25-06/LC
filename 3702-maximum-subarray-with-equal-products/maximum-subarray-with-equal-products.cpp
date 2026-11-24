class Solution {
    long long gcd(long long a , long long b){
        while(b != 0){
            long long rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
    long long lcm(long long a, long long b){
        return (a / gcd(a,b))*b;
    }
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        const long long MAX_RHS = 25200;

        for(int i = 0;i<n;i++){
            long long prod = 1;
            long long curGCD = 0;
            long long curLCM = 0;

            for(int j = i;j<n;j++){
                long long val = nums[j];
                prod *= val;
                curGCD = (curGCD == 0)?val : gcd(curGCD,val);

                curLCM = (curLCM == 0)?val:lcm(curLCM,val);

                long long rhs = curGCD * curLCM;
                if (prod == rhs) {
                    maxLength = max(maxLength, j - i + 1);
                }

                if (prod > MAX_RHS) {
                    break;
                }
            }
        }

        return maxLength;
    }
};