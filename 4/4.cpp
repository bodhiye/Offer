#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() {}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	int pre_len = pre.size();
	int vin_len = vin.size();
	if (pre_len == 0 || vin_len == 0 || pre_len != vin_len)
		return NULL;
	TreeNode *head = new TreeNode(pre[0]);//�������ڵ�
	int root_ind = 0;//��¼root�������е��±�
	for (int i = 0; i < vin_len; i++) {
		if (vin[i] == pre[0]) {
			root_ind = i;
			break;
		}
	}
	vector<int> vin_left, vin_right, pre_left, pre_right;
	for (int j = 0; j < root_ind; j++) {
		vin_left.push_back(vin[j]);
		pre_left.push_back(pre[j + 1]);//��һ��Ϊ�����ڵ㣬����
	}
	for (int j = root_ind + 1; j < pre_len; j++) {
		vin_right.push_back(vin[j]);
		pre_right.push_back(pre[j]);
	}
	//�ݹ�
	head->left = reConstructBinaryTree(pre_left, vin_left);
	head->right = reConstructBinaryTree(pre_right, vin_right);
	return head;
}

void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int pre[] = { 1,2,4,7,3,5,6,8 };
	int vin[] = { 4,7,2,1,5,3,8,6 };
	vector<int> pre_vec(pre, pre + 8);
	vector<int> vin_vec(vin, vin + 8);
	TreeNode *head;
	head = reConstructBinaryTree(pre_vec, vin_vec);
	inorder(head);
	return 0;
}