#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node*parent;
  node*left;
  node*right;
  node(){parent=NULL;right=NULL;left=NULL;}
};
int n=1,p=0;
class bst
{
  public:
  node*root=NULL;


  void insert(int x){
    node*temp#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node*parent;
  node*left;
  node*right;
  node(){parent=NULL;right=NULL;left=NULL;}
};
int n=1;
class bst
{
  public:
  node*root=NULL;


  void insert(int x){
    node*temp=new node;
    temp->data=x;
   temp->left=NULL;temp->right=NULL;
    if(root==NULL){root=temp;}
   else{
    node*curr;
    curr=root;
    while(true){
     if(temp->data<curr->data)
     {
        if(curr->left==NULL){curr->left=temp;temp->parent=curr;break;}
        else{curr=curr->left;}
     }
     else if(temp->data>curr->data){
      if(curr->right==NULL){curr->right=temp;temp->parent=curr;break;}
      else{
      curr=curr->right;}
    }
   }
}
}
void display(node*temp)
 {
   if(temp==NULL){return ;}
   else{
   display(temp->left);
   cout<<temp->data<<"    ";
   display(temp->right);}
 }
node* search(node*temp,int s)
{
  if(temp==NULL){return NULL;}
  else if(s==temp->data) return temp;
  else if(s<temp->data) 
    search(temp->left,s);
   else
    search(temp->right,s);
 }
void Delete(node*temp,int s)
{
 
  if(search(temp,s)!=NULL)
  { 
    node*curr=search(temp,s);
    cout<<curr->data;
 
    if(curr->left==NULL && curr->right==NULL)
    {
      if(curr->parent->left==curr)
        curr->parent->left=NULL;
      else
         curr->parent->right=NULL;
    }
 
    else if(curr->left==NULL || curr->right==NULL)
    {
      if(curr!=root)
      {
        node* p;
        node* c;
        p=curr->parent;
        if(curr->left==NULL)
        c=curr->right;
        else
        c=curr->left;
        if(p->data>=curr->data)
        {
          p->left=c;
          c->parent=p;
        }
        else
        {
         p->right=c;
         c->parent=p;
        }
       }
       else
       {
         if(curr->left==NULL)
          root=curr->right;
         else
          root=curr->left;
       }
    }
  
    else
    {
      node*l;
      l=curr->left;
      while(l->right!=NULL)
      {
        l=l->right;
      }
      if(l->left==NULL)
      {
       curr->data=l->data;
       node* p=l->parent;
       if(p->left==l)
        p->left=NULL;
       else
        p->right=NULL;
      }
      else
      {
        curr->data=l->data;
        node* p=l->parent;
        if(p->left==l)
        p->left=l->left;
        else
        p->right=l->left;
      }
    }
  }
}

int count(node*temp)
{
   if(temp==NULL)return 0;
   if(temp->left!=NULL)
   {
     ++n;
     n=count(temp->left);
   }
   if(temp->right!=NULL)
   {
    ++n; 
    n=count(temp->right);
   }
   return n; 
}
int countleaf(node*temp)
{
  if(temp==NULL) return 0;
    if(temp->right!=NULL && temp->right==NULL)
    return 1;    
    return countleaf(temp->left)+countleaf(temp->right);
}
int countinternal()
{
  int total,leaf;
  total=count(root);
  leaf=countleaf(root);
  return total-leaf;
 }
void range_search(node*temp,int max,int min)
{
  if(temp==NULL) return;
  range_search(temp->right,max,min);
  if(temp->data>=min && temp->data<=max)
  {cout<<temp->data<<"   ";
    ++P;}
  range_search(temp->left,max,min);
  }
  cout<<endl<<"number of nodes : "<<p<<endl;
 
};

int main()
{


  bst b;
 int x,ch;
 do{
 cout<<" \n 1.insert \n 2.display \n 3.search \n 4.delete \n5.count\n 6.range search \n;
 cout<<"7.count leaf node \n 8.count internal node \n 9.exit \n";
 cout<<" \n -------------------------------\n";
 cout<<" \n Enter your choice : ";cin>>ch;
 switch(ch)
 {
   case 1:cout<<" \n Enter the data : ";cin>>x;b.insert(x);break;
   case 2:b.display(b.root);break;
   case 3:cout<<" \n Enter the search : ";
          cin>>x;
          node*temp;temp=b.search(b.root,x);
          if(temp!=NULL) cout<<" \n Found ";
          else cout<<" \n Not found";
          break;
   case 4 :cout<<" \n Enter the delete element : ";
          cin>>x;
          b.Delete(b.root,x);
          cout<<" \n After delete \n ";
          b.display(b.root);break;
   case 5 : int y;y=b.count(b.root);
            cout<<"Number of nodes : "<<y;break;
   case 6 :int max,min;cout<<"Enter the maximum and minmum number ";
           cin>>max>>min;b.range_search(b.root,max,min);break;
   case 7: int z;z=b.countleaf(b.root);cout<<z<<endl;break; 
   case 8 : int m;m=countinternal();cout<<m<<endl;break;
   default : return 0;
 }
 }while(ch!=9);
 return0;
 }
