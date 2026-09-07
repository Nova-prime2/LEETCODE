#include <stack>
using namespace std;

class MyQueue {
    stack<int> inStack, outStack;
    
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
    
public:
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if (outStack.empty()) transfer();
        int x = outStack.top();
        outStack.pop();
        return x;
    }
    
    int peek() {
        if (outStack.empty()) transfer();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
