/**************************************************************************
 *	Title	: Order of Binary Tree
 *	Author	: Edlin
 *	Date	: April 20, 2014
 **************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Node{
public:
	string value;
	Node* left;
	Node* right;

	Node(){
		left = NULL;
		right = NULL;
	}
};


int* Index;
bool pre, in, post;
string preorder, inorder, postorder;


void LoadData(){
	pre = false;
	in = false;
	post = false;
	
	string command;

	cout <<"[Preorder]:\t";
	getline(cin,preorder);

	cout <<"[Inorder]:\t";
	getline(cin,inorder);

	cout <<"[Postorder]:\t";
	getline(cin,postorder);
}


int FindMinPosition(int start, int end){
	int pos = start;
	int min = Index[start];
	for(int i=start+1; i<=end; i++){
		if(min>Index[i]){
			min = Index[i];
			pos = i;
		}
	}
	return pos;
}

int FindMaxPosition(int start, int end){
	int pos = start;
	int max = Index[start];
	for(int i=start+1; i<=end; i++){
		if(max<Index[i]){
			max = Index[i];
			pos = i;
		}
	}
	return pos;
}


Node* BuildTree(Node* node, int start, int end, string tag){
	if(start>end)
		return NULL;

	int pos;
	if(tag=="POST")
		pos = FindMinPosition(start, end);
	else if(tag=="PRE")
		pos = FindMaxPosition(start, end);
	node->value = inorder[pos];

	Node* Left = new Node;
	Node* Right = new Node;	
	node->left = BuildTree(Left, start, pos-1, tag);
	node->right = BuildTree(Right, pos+1, end, tag);

	if(node->left!=NULL)
		cerr<<node->value<<":sw->"<<node->left->value<<";"<<endl;
	if(node->right!=NULL)
		cerr<<node->value<<":se->"<<node->right->value<<";"<<endl;

	return node;
}

void PrintPost(Node* node){
	if(node->left!=NULL)
		PrintPost(node->left);
	if(node->right!=NULL)
		PrintPost(node->right);
	cout<<node->value;
}

void PrintPre(Node* node){
	cout<<node->value;
	if(node->left!=NULL)
		PrintPre(node->left);
	if(node->right!=NULL)
		PrintPre(node->right);
}

void PrepareGraph(){
	cerr<<"digraph G{ node[shape=box];";
}


int main(){

	LoadData();
	PrepareGraph();

	Node* root = new Node();



	if(preorder!="" && inorder!="" && postorder==""){
		int count = inorder.length();
		Index = new int[count];		//index of the char in inoder appear in preorder;
		for(int i=0; i<count; i++ ){
			Index[i] = preorder.find(inorder[i]);
		}
	
		BuildTree(root, 0, count-1, "POST");
	
		cout<<"Postorder: ";
		PrintPost(root);
		cout<<endl;
	}
	else if(preorder=="" && inorder!="" && postorder!=""){
		int count = inorder.length();
		Index = new int[count];		//index of the char in inoder appear in preorder;
		for(int i=0; i<count; i++ ){
			Index[i] = postorder.find(inorder[i]);
		}
	
		BuildTree(root, 0, count-1, "PRE");
	
		cout<<"Preorder: ";
		PrintPre(root);
		cout<<endl;
	}


	cerr<<"}";

	return 0;
}
