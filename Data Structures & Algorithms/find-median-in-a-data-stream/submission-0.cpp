class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if (!large.empty() && small.top() > large.top()) {
            int val = small.top();
            small.pop();
            large.push(val);
        }

        int s = int(small.size());
        int l = int(large.size());

        if (s - l > 1) {
            int val = small.top();
            small.pop();
            large.push(val);
        } else if (l - s > 1) {
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return double(small.top());
        } else if (small.size() < large.size()) {
            return double(large.top());
        } else {
            return (small.top() + large.top()) / 2.0;
        }
    }
};
