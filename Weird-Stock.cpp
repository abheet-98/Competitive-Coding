#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int n,m;
	
	//n - initial price of stock
	//m - Desired price of stock
    
	cin>>n>>m;
	
	//Stock reduces by 1$ or doubles itself

    double days = 0;
    
    if(n == m){
        days = 0;
    }
    else if(n > m){                          // we have to reduce stock price
        days = n-m;
    }
    else{                                    // we have to increase stock price
    
        double p = ceil((log10(m) - log10(n))/(log10(2)));
        
        if(pow(2, p) * n == m){
            days = p;
        }
        else{
            days = p + (pow(2, p) * n) - m - 1;
        }
        
    }
    
    cout<<days;

	return 0;
}

