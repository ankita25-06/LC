class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<int> marked(n,0);

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

       for(int i = 0;i<n;i++){
        pq.push({nums[i],i});
       }

       while(!(pq.empty())){
        auto[val,idx] = pq.top();
        pq.pop();
        if(marked[idx]){
            continue;
        }

        score += val;
        marked[idx] = 1;
        if(idx > 0){
            marked[idx-1]=1;
        }
        if(idx +1 < n){
            marked[idx+1] = 1;
        }
       }

       return score;
    }
};