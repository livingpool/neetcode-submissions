class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int s : stones) maxHeap.push(s);

        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if (x - y > 0) maxHeap.push(x - y);
        }

        if (!maxHeap.empty()) return maxHeap.top();
        return 0;
    }
};
