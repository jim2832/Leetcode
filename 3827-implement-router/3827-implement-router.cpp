#include <bits/stdc++.h>
using namespace std;

struct TupleHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto [a, b, c] = t;
        size_t h1 = hash<int>()(a);
        size_t h2 = hash<int>()(b);
        size_t h3 = hash<int>()(c);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
public:
    int max_size;
    queue<tuple<int,int,int>> q;
    unordered_set<tuple<int,int,int>, TupleHash> us;  // ✅ 指定 TupleHash
    unordered_map<int, deque<int>> destMap;           // destination -> timestamps

    Router(int memoryLimit): max_size(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> packet = {source, destination, timestamp};
        if(us.count(packet)) return false;

        if(q.size() == max_size) {
            auto old = q.front();
            q.pop();
            us.erase(old);
            auto [os, od, ot] = old;
            destMap[od].pop_front();
        }

        q.push(packet);
        us.insert(packet);
        destMap[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [s,d,t] = q.front();
        q.pop();
        us.erase({s,d,t});
        destMap[d].pop_front();
        return {s,d,t};
    }

    int getCount(int destination, int startTime, int endTime) {
        if(!destMap.count(destination)) return 0;
        auto &dq = destMap[destination];
        auto it1 = lower_bound(dq.begin(), dq.end(), startTime);
        auto it2 = upper_bound(dq.begin(), dq.end(), endTime);
        return distance(it1, it2);
    }
};
