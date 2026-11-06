class Foo {
private:
    promise<void> firstFinished;
    promise<void> secondFinished;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstFinished.set_value();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        firstFinished.get_future().wait();
        printSecond();
        secondFinished.set_value();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        secondFinished.get_future().wait();
        printThird();
    }
};