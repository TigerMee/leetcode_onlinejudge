
#include "common.h"

class Solution {
//the clue is that if we traverse the tree in inorder, then it must be sorted, so:
//1. the first error element must be the first element of the pair who breaks the order
//2. the second error element must be the second element of the pair who breaks the order
//note: there is a special case that the two element exist in one single error pair
public:
	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeNode* prev = NULL;
		TreeNode* e1 = NULL;
		TreeNode* e2 = NULL;
		GetErrorElement(root, e1, e2, prev);
		if(e1 && e2)
			swap(e1->val, e2->val);
	}

	void GetErrorElement( TreeNode * root, TreeNode*& e1, TreeNode*& e2, TreeNode*& prev )
	{
		//throw std::exception("The method or operation is not implemented.");
		if(root == NULL)
			return;
		GetErrorElement(root->left, e1, e2, prev);
		if (prev && prev->val > root->val)
		{
			e2 = root;//second error element
			if(!e1)//first error element
				e1 = prev;
		}
		prev = root;
		GetErrorElement(root->right, e1, e2, prev);
	}
};
