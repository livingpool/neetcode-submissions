class Twitter {
private:
    int time;
    map<int, vector<vector<int>>> tweetMap; // userId, {time, tweetId}
    map<int, set<int>> followMap; // userId, followee(s)

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            return p1[2] < p2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        followMap[userId].insert(userId);

        for (auto& followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                // followeeId, index, time, tweetId
                int index = tweetMap[followeeId].size() - 1;
                minHeap.push({followeeId, index, tweetMap[followeeId][index][0], tweetMap[followeeId][index][1]});
            }
        }

        while (!minHeap.empty() && res.size() < 10) {
            vector<int> t = minHeap.top();
            minHeap.pop();
            res.push_back(t[3]);

            if (t[1] - 1 >= 0) {
                minHeap.push({t[0], t[1] - 1, tweetMap[t[0]][t[1] - 1][0], tweetMap[t[0]][t[1] - 1][1]});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
