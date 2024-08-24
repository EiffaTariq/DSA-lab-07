#include<iostream>
#include"TreeNode.h"
using namespace std;
void inOrder(Treenode* root)
{
	if (root == nullptr)
	{
		return;
	}
	inOrder(root->left);
	cout << root->data << ", ";
	inOrder(root->right);
}
void preOrder(Treenode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << ", ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Treenode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << ", ";
	postOrder(root->left);
	postOrder(root->right);
}
Treenode* convertToBinaryTree(int arr[], int start, int end)
{
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	Treenode* root = new Treenode(arr[mid]);

	root->left = convertToBinaryTree(arr, start, mid - 1);
	root->right = convertToBinaryTree(arr, mid + 1, end);

	return root;
}

int main()
{
	int arr[7] = { 1,2,3,4,5,6,7};
	Treenode*root = convertToBinaryTree(arr,0,6);
	postOrder(root);
	cout << endl;
	int arr1[1] = { 1};
	Treenode* root1 = convertToBinaryTree(arr1, 0, 0);
	postOrder(root1);
	cout << endl;
	return 0;
}