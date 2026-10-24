class ATM {
    vector<long long>notes;
       const vector<int> values = {20,50,100,200,500}; 
public:
    ATM() {
       notes.assign(5,0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0;i<5;i++){
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> temp(5,0);
        long long rem = amount;
        for(int i = 4;i>=0;i--){
            if(rem > 0 && notes[i] > 0){
                long long count = min(rem/values[i],notes[i]);
                temp[i] = count;
                rem -= count*values[i];
            }
        }
        if (rem > 0) {
            return {-1};
        }
        for (int i = 0; i < 5; ++i) {
            notes[i] -= temp[i];
        }
        
        return temp;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */