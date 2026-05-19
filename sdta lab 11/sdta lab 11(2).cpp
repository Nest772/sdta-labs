#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

struct Node{
	int height;
	char name[50];
	Node* left;
	Node* right;
};

Node* createNode(int h,const char*n)
{
	Node* newNode = new Node;
	newNode->height = h;
	strcpy(newNode->name,n);
	newNode->left=newNode->right=NULL;
	
	return newNode;
}

Node*insert(Node* root,int h,const char*n)
{
	if(root==NULL)
	return createNode(h,n);
	
	if(h<root->height)
	 root->left=insert(root->left,h,n);
	 root->right=insert(root->right,h,n);
	 
	 return root;
}

int countNodes(Node* root)
{
	if(!root) return 0;
	return 1+
  countNodes(root->left)+countNodes(root->right);
}

int countName(Node* root,const char* target)
{
	if(!root)return 0;
	
	int count = 0;
	if (strcmp(root->name,target)==0)
	 count = 1;
	  
	  return count +
	  countName(root->left,target)+countName(root->right,target);
	  
}

int depth(Node* root)
{
	if (!root) return 0;
	int leftDepth=depth(root->left);
	int rightDepth=depth(root->right);
	
	return 1+(leftDepth>rightDepth ? leftDepth:rightDepth);
};

Node*copyLeftSubTree(Node*root)
{
	if(!root||!root->left)
	return NULL;
	
	Node* newRoot = createNode(root->left->height,"");
	
	newRoot->left=copyLeftSubTree(root->left);
	newRoot->right=NULL;
	
	return newRoot;
}

void deleteTree(Node*root)
{
	if(!root)return;
	
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

const char* names[]=
{"Ivan","Oleg","Maria","Anna","Petro"};

int main()
{
	srand(time(0));
	
	Node* root=NULL;
	int n;
	
	cout<<"Enter number of nodes: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int h = rand()%200+100;
		const char* name = names[rand()%5];
		root = insert(root,h,name);
	}
	
	char searchName[50];
	cout<<"Enter name t search: ";
	cin>>searchName;
	
	int occurrences = countName(root,searchName);
	
	  if(occurrences>0)
	  cout<<"Name found "<<occurrences<<"times\n";
	   else 
	    cout<<"Name is not found\n";
	    
	Node* newTree=copyLeftSubTree(root);
	
	cout<<"\nOriginal tree\n";
	cout<<"Nodes: "<<countNodes(root)<<endl;
	  cout<<"Depth"<<depth(root)<<endl;
	  
	  cout<<"\nNew tree(left subtree heights):\n";
	  cout<<"Nodes: "<<countNodes(newTree)<<endl;
	  cout<<"Depth: "<<depth(newTree)<<endl;
	  
	  deleteTree(root);
	  deleteTree(newTree);
	  
	  return 0;
}






























































