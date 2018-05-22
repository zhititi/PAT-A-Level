#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
//用这种方法建立成的二叉查找树，无论“原先序序列”是否为镜像树的先序序列，建成的树都一样。
//把建成的树用不同的方法遍历，以确定原序列是“二叉查找树”的先序序列or“镜像二叉查找树”的先序序列or都不是。
//无论“原二叉查找树”，或是“镜像二叉查找树”需给出的后序遍历序列都应该是“其本身”的后序序列。
struct node {
	int data;
	node *left, *right;       //注意*的位置
};

void insert(node *&root, int data) {   //二叉查找树的建树方法
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}

void preorder(node *root, vector<int>& vi) {   //先序遍历，结果储存在vi里
	if (root == NULL) return;
	vi.push_back(root->data);
	preorder(root->left, vi);
	preorder(root->right, vi);
}
void preordermirror(node *root, vector<int>& vi) {  //先序镜像遍历
	if (root == NULL) return;
	vi.push_back(root->data);
	preordermirror(root->right, vi);
	preordermirror(root->left, vi);
}
void postorder(node *root, vector<int>& vi) {  //后序遍历
	if (root == NULL) return;
	postorder(root->left, vi);
	postorder(root->right, vi);
	vi.push_back(root->data);
}
void postordermirror(node*root, vector<int>& vi) {   //后序镜像遍历
	if (root == NULL) return;
	postordermirror(root->right, vi);
	postordermirror(root->left, vi);
	vi.push_back(root->data);
}

//origin为初始序列，pre为先序，post为后序，preM为镜像树先序，postM为镜像树后序
vector<int> origin, pre, preM, post, postM;

int main() {
	int n, data;
	node *root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	//把建成的树用不同的方法遍历，以确定原序列是“二叉查找树”的先序序列or“镜像二叉查找树”的先序序列or都不是。
	preorder(root, pre);
	preordermirror(root, preM);
	postorder(root, post);
	postordermirror(root, postM);

	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1) printf(" ");
		}
	}
	else if (origin == preM) {
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if (i < postM.size() - 1) printf(" ");
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}