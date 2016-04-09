#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
using namespace std;
/*
��һ�ö�����������ÿ�������Ȩֵ��Ȩֵ������ͬ�������һ���㷨���Ȩֵ����Ҷ�ڵ㵽Ȩֵ��С��Ҷ�ڵ�ľ��롣������ÿ���ߵľ���Ϊ1��һ���ڵ㾭���������ߵ�����һ���ڵ�Ϊ�������ڵ�֮��ľ��롣
�����������ĸ��ڵ�root���뷵��������롣
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
		path.pop_back();//����
	}

	
};