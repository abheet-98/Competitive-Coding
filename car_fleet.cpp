class Solution {
public:
    bool order(pair<int, int> a, pair<int, int> b) {
        return a.first <= b.first;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> dv;
        for(int i=0;i<position.size();i++) {
            dv.push_back(position[i], speed[i]);
        }
        sort(dv.begin(), dv.end(), order);
        stack<pair<int, int>> stk;
        for(auto i:dv) {
            stk.push(i);
        }
        int ans = position.size();
        while(stk.size()>1) {
            pair<int, int> x = stk.top();
            stk.pop();
            pair<int, int> y = stk.top();
            stk.pop();
            int s1 = x.first, s2 = y.first, v1 = x.second, v2 = y.second;
            if (v1 != v2) {
                double d = ((double)(s1-s2)/(v2-v1))*v1 + s1;
                if (d >= 0.00 && d <= target) {
                    ans--;
                    stk.push(x);
                } else {
                    stk.push(y);
                }   
            } else if (s1 == s2) {
                ans--;
                stk.push(x);
            } else {
                stk.push(y);
            }
        }
        return ans;
    }
};
