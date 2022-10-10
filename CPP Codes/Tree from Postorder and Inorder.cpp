void mapping(int in[],map<int,int>&mp,int n){
   for(int i=0;i<n;i++){
       mp[in[i]]=i;
   }
}
Node* solve(int in[],int post[],int &postindx,int instart,int inend,int n,map<int,int> &mp){
   if(postindx<0)return NULL;
   if(instart>inend)return NULL;
   int start=post[postindx--];
   //int pos=find(in,start,n);
   int pos=mp[start];
   Node* root=new Node(start);
   root->right=solve(in,post,postindx,pos+1,inend,n,mp);
   root->left=solve(in,post,postindx,instart,pos-1,n,mp);
   return root;
}
Node *buildTree(int in[], int post[], int n) {
   // Your code here
   int postindx=n-1;
   map<int,int>mp;
   mapping(in,mp,n);
   Node* root=solve(in,post,postindx,0,n-1,n,mp);
   return root;
}
