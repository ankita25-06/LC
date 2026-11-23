class ProductOfNumbers {
public:
    vector<int> prefixProducts;
    ProductOfNumbers() {
        prefixProducts = {1};
    }
    
    void add(int num) {
        if(num == 0){
            prefixProducts = {1};
        }else{
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProducts.size();

        if(k>=n){
            return 0;
        }

        return prefixProducts.back() / prefixProducts[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */