class EventManager {
public:
    // eventId -> current priority
    unordered_map<int, int> mp;

    // max heap: {priority, -eventId}
    priority_queue<pair<int, int>> pq;

    EventManager(vector<vector<int>>& events) {
        for (auto &e : events) {
            int id = e[0];
            int pr = e[1];
            mp[id] = pr;
            pq.push({pr, -id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId}); // push new entry
    }
    
    int pollHighest() {
        while (!pq.empty()) {
            auto [pr, negId] = pq.top();
            int id = -negId;

            // valid entry check
            if (mp.count(id) && mp[id] == pr) {
                pq.pop();
                mp.erase(id); // mark as removed
                return id;
            }

            pq.pop(); // discard wrong entry
        }

        return -1;
    }
};
