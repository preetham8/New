#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node *left;
    node *right;
};

node *newnode(int data){
   node *temp = new node;
   temp->data=data;
   temp->left=NULL; 
   temp->right=NULL;
   return temp;
}

node* insert(node* node, int data){
   if(node==NULL) return newnode(data);
   
   if(data < node->data)
   node->left = insert(node->left, data);

   else if(data > node->data)
   node->right = insert(node->right, data); 

   return node;
}

void inorder(node* root){
   if(root!=NULL)
   {
       inorder(root->left);
       cout<<" ";
       cout<<root->data; 
       cout<<" ";
       inorder(root->right);
       cout<<" ";
   }
} 

void preorder(node* root){
   if(root!=NULL)
   {
       cout<<root->data<<" ";
       preorder(root->left);
       cout<<" ";
       preorder(root->right);
       cout<<" ";
   }
}

void postorder(node* root){
   if(root!=NULL){
       postorder(root->left);
       cout<<" ";
       postorder(root->right);
       cout<<" ";
       cout<<root->data;
       cout<<" ";
   }
}

node *search(node* root, int data){
   if(root==NULL||root->data==data){
   return root;}
  
   if(root->data < data){
   return search(root->right,data);}
   
   return search(root->left,data);
}

int getlevelutil(node *node, int data, int level){
   if(node==NULL)
   return 0;
   
   if(node->data==data)
   return level;

   int downlevel=getlevelutil(node->left,data,level+1);
   
   if(downlevel!=0)
   return downlevel;

   downlevel = getlevelutil(node->right,data,level+1);

   return downlevel;

}

int getlevel(node *node, int data){
   return getlevelutil(node,data,1);
}

int main(){
  int choice;
  int a[20];
  node* root = NULL;
  srand(time(0));
  for(int i=0;i<20;i++){
      root = insert(root,rand()%20);
      a[i] = rand()%20;
  }
  
  cout<<"enter the choice: 1. inorder traversal 2. preorder traversal 3. postorder traversal 4. searching 5. average comparisons -1. exit";
  while(choice!=-1){
  if(choice==1){
     cout<<"inorder traversal:";
     inorder(root);}
   
  else if(choice==2){
     cout<<"preorder traversal:";
     preorder(root);}

  else if(choice==3){
     cout<<"postorder traversal:";
     postorder(root);}
  
  else if(choice==4){
     int k;
     cout<<"enter the number to be searched:";
     cin>>k;
     node* temp = search(root,k);
     if(temp->data==k)
       cout<<"element present";
  
     else
       cout<<"element not found";}

  else if(choice==5){
      int sum=0;
      for(int i=0;i<20;i++){
         int level = getlevel(root,a[i]);
         sum+=level;
      }        
      cout<<"total average number of comparisons are:";
      float avg = float(sum)/20.0;
      cout<<avg;
  }
  else
  cout<<"wrong choice!!"<<endl;

  cout<<"enter next choice:";
  cin>>choice;
  cout<<endl;
}
  return 0;
}



