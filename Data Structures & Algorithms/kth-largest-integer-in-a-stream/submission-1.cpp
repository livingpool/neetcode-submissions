class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int capacity;

public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop(); 
        }
        capacity = k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > capacity) minHeap.pop();
        return minHeap.top();
    }
};
