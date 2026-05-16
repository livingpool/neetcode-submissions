class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> m;
        for (char t : tasks) m[t]++;

        priority_queue<int> maxHeap;
        for (auto& it : m) maxHeap.push(it.second);

        int time = 0;
        queue<pair<int, int>> q; // count, idleTime
        while (!maxHeap.empty() || !q.empty()) {
            if (!q.empty() && time >= q.front().second) {
                maxHeap.push(q.front().first);
                q.pop();
            }
            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if (count > 0) q.push({count, time + n + 1});
            }
            time++;
        }

        return time;
    }
};
