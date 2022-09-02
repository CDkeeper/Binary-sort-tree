#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=1e8;
int n,o,t;
struct node{
    int val;
    node *left,*right;
    node(int _val):val(_val),left(NULL),right(NULL){};
}*root;
void insert(node* &root,int t){
    if(!root) root=new node(t);
    else if(root->val<t) insert(root->right,t);
    else insert(root->left,t);
}
void remove(node* &root,int t){
    if(!root) return;
    else if(root->val<t) remove(root->right,t);
    else if(root->val>t) remove(root->left,t);
    else{
        if(!root->left&&!root->right) root=NULL;
        else if(!root->left) root=root->right;
        else if(!root->right) root=root->left;
        else {
            auto p=root->left;
            while(p->right) p=p->right;
            root->val=p->val;
            remove(root->left,p->val);
        }
    }
}
int get_pre(node* root,int t){
    if(!root) return -INF;
    else if(root->val>=t) return get_pre(root->left,t);
    else return max(root->val,get_pre(root->right,t));
}
int get_suc(node* root,int t){
    if(!root) return INF;
    else if(root->val<=t) return get_suc(root->right,t);
    else return min(root->val,get_suc(root->left,t));
}
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &o, &t);
        if(o==1) insert(root,t);
        else if(o==2) remove(root,t);
        else if(o==3) printf("%d\n",get_pre(root,t));
        else printf("%d\n",get_suc(root,t));
    }
}
