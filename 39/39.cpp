#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() {}
};

TreeNode* newTree()
{
	TreeNode* node = new TreeNode;
	int x;
	cin >> x;
	if (!x)node = NULL;
	else
	{
		node->val = x;
		node->left = newTree();
		node->right = newTree();
	}
	return node;
}

int getDepth(TreeNode* root)
{
	if (!root)return 0;
	int left = getDepth(root->left);
	if (left == -1)return -1;
	int right = getDepth(root->right);
	if (right == -1)return -1;
	return abs(left - right) > 1 ? -1 : 1 + max(left, right);
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
	return getDepth(pRoot) != -1;
}

int main()
{
	ios::sync_with_stdio(false);
	TreeNode* root = NULL;
	root = newTree();
	cout << IsBalanced_Solution(root) << endl;
	return 0;
}