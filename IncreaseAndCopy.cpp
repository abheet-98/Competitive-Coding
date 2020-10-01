#include <bits/stdc++.h>
using namespace std;
long long int getAns(long long int n, long long int x) {
    long long int x_ans;
    double x_div = (double)n/x;
    x_ans = (x-1) + ((long long int)x_div);
    if ((long long int)x_div * x == n) {
        x_ans -= 1;
    }
    return x_ans;
}
int main() {
    int test;
    cin>>test;
    while(test--) {
        long long int n;
        cin>>n;
        long long int x = ceil(sqrt((double)n));
        long long int y = x-1;
        long long int x_ans = getAns(n, x), y_ans = getAns(n, y);
        cout<<min(x_ans, y_ans)<<endl;
    }
}
