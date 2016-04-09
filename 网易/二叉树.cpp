#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
using namespace std;
/*
有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离。
给定二叉树的根节点root，请返回所求距离。
*/
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Tree {
public:
	int getDis(TreeNode* root) {
		// write code here
		inorder(root);

		int comm = 0;
		for (int i = 0; i != min(maxpath.size(), minpath.size()); i++){
			if (maxpath[i] == minpath[i])
				comm++;
			else
				break;
		}

		return maxpath.size() + minpath.size() - 2 * comm;
	}

private:
	int maxdata = INT_MIN, mindata = INT_MAX;
	vector<TreeNode *> maxpath;
	vector<TreeNode *> minpath;
	vector<TreeNode *> path;
	void inorder(TreeNode * root){
		if (!root) return;

		path.push_back(root);
		if (!root->left && !root->right){
			if (root->val > maxdata){
				maxdata = root->val;
				maxpath = path;
			}
			else if (root->val < mindata){
				mindata = root->val;
				minpath = path;
			}
		}
		inorder(root->left);
		inorder(root->right);
		path.pop_back();//回溯
	}

	
};