#include<bits/stdc++.h>

using namespace std;

int precedence(char ch){
    
    if(ch == '+'){
        return 1;
    }else if(ch == '-'){
        return 1;
    }else if(ch == '*'){
        return 2;
    }else if(ch == '/'){
        return 2;
    }
    
}

int operation(int v1,int v2,char ch){
    
    if(ch == '+'){
        return v1 + v2;
    }else if(ch == '-'){
        return v1 - v2;
    }else if(ch == '*'){
        return v1 * v2;
    }else if(ch == '/'){
        return v1 / v2;
    }
    
}

int main(){
    
    string s = "2*4+(5-3*8)";
    
    stack<int> opnds;
    stack<char> opts;
    
    for(int i = 0 ; i < s.length() ; i++){
        
        char ch = s[i];
        
        if(ch == '('){
            opts.push(ch);
        }else if(isdigit(ch)){
            opnds.push(ch - '0');
        }else if(ch == ')'){
            while(opts.top()!='('){
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                char cch = opts.top();
                opts.pop();
                
                int v = operation(v1,v2,cch);
                opnds.push(v);
            }
            opts.pop();
            
        }else if(ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            while(opts.size() > 0 && opts.top() != '(' && precedence(ch) <= precedence(opts.top()) ){
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                char cch = opts.top();
                opts.pop();
                
                int v = operation(v1,v2,cch);
                opnds.push(v);
            }
            opts.push(ch);
            
        }
    }
    
    while(opts.size() != 0){
        int v2 = opnds.top();
        opnds.pop();
        int v1 = opnds.top();
        opnds.pop();
        char cch = opts.top();
        opts.pop();
        
        int v = operation(v1,v2,cch);
        opnds.push(v);
    }
    
    cout<<opnds.top(); //ans would be -11 for this specific input

    return 0;
}
