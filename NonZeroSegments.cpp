    #include <bits/stdc++.h>
    using namespace std;
    int main() {
        int n;
        cin>>n;
        long long int a[n], sum = 0LL;
        int last_corrected = -1, ans = 0;
        unordered_map<long long int, int> um;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            sum+=a[i];
            if (i>0) {
                if (sum == 0 && last_corrected < 0) {
                    last_corrected = i;
                    ans++;
                } else if (um.find(sum) != um.end()) {
                    int f = um[sum];
                    if (f >= last_corrected-1) {
                        last_corrected = i;
                        ans++;
                    }
                }
            }
            um[sum] = max((um.find(sum) == um.end() ? INT_MIN : um[sum]), i);
        }
        cout<<ans<<endl;
    }
