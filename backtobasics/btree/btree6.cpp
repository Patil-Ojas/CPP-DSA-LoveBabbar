#include <iostream>
#include <stack>
using namespace std;
/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Input:
		   1
		 /   \
		/	  \
	   2	   3
	  /		  / \
	 /	  	 /	 \
	4		5	  6
		   / \
		  /   \
		 7	   8

Output: [4, 2, 1, 7, 5, 8, 3, 6]

*/

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/
	void getInorder(Node* root, vector<int> &ans)
	{
		if (root==NULL)	
			return ;
		
		getInorder(root->left, ans);
		ans.push_back(root->data);
		getInorder(root->right, ans);
	}
	
	vector<int> findInorderTraversal(Node* root)
	{
		vector<int> ans;
		getInorder(root, ans);
		
		return ans;
	}
};
