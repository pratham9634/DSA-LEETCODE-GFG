class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue< 
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>> 
        > pq; // Min-heap
        
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0) return ans;

        // Step 1: Push first k pairs (nums1[i], nums2[0])
        for (int i = 0; i < min(n1, k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        // Step 2: Extract k smallest pairs
        while (k-- > 0 && !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int i = p.second.first, j = p.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // If there's a next pair (i, j+1), push it into the heap
            if (j + 1 < n2) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
