class StockPrice {
    unordered_map<int, int> record;
    multiset<int> prices;
    int latestTime = 0;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);

        if (record.find(timestamp) != record.end()) {
            int prevPrice = record[timestamp];
            auto it = prices.find(prevPrice);
            if (it != prices.end()) {
                prices.erase(it);
            }
        }

        record[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return record[latestTime];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */