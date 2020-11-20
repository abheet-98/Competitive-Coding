#include <bits/stdc++.h> 
using namespace std; 


struct Node{
    int data;
    Node* left;
    Node* right;
};


Node *newNode(int data,Node* left,Node* right){
  Node *temp = new Node; 
	temp->data = data; 
	temp->left = left;
	temp->right = right;
	return temp; 
}

bool find(Node *node, int data,vector<Node*>& vec){
    if(node==NULL){
        return false;
    }
    if(node->data == data){
        vec.push_back(node);
        return true;
    }
    bool fnl = find(node->left,data,vec);
    if(fnl){
        vec.push_back(node);
        return true;
    }
    bool fnr = find(node->right,data,vec);
    if(fnr){
        vec.push_back(node);
        return true;
    }
    return false;
}

void pre(Node* node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    pre(node->left);
    pre(node->right);
}

void pkd(Node *node, int k,Node* blocker){
    if(node == NULL || k < 0 || node == blocker){
        return;
    }
    if(k == 0){
        cout<<node->data<<" ";
    }
    pkd(node->left,k-1,blocker);
    pkd(node->right,k-1,blocker);
}

void klevelsfar(Node* node,int data,int k,vector<Node*> &vec){
    bool found = find(node,data,vec);
    
    if(!found){
        cout<<"Element Not Found !";
        return;
    }
    for(int i = 0 ; i < vec.size() ; i++){
        pkd(vec[i],k-i,i==0?NULL:vec[i-1]);
    }
}

int main() 
{ 
    
    vector<Node*> vec;

    Node *root = newNode(10,NULL,NULL);
    root->left = newNode(20,NULL,NULL);
    root->right = newNode(30,NULL,NULL);
    root->left->left = newNode(40,NULL,NULL);
    root->left->right = newNode(50,NULL,NULL);
    root->left->left->right = newNode(60,NULL,NULL);
    root->right->left = newNode(90,NULL,NULL);
    root->right->right = newNode(48,NULL,NULL);
    root->right->right->right = newNode(65,NULL,NULL);
    root->right->right->right->left = newNode(99,NULL,NULL);
    root->right->left->right = newNode(88,NULL,NULL);
    root->right->left->left = newNode(26,NULL,NULL);
    root->right->right->right->left->right = newNode(47,NULL,NULL);
    
    klevelsfar(root,30,2,vec);
    
	return 0;
	
} 
