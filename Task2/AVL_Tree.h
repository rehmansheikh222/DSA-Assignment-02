#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
template <typename T>
class AVL_Tree;
template <typename T>
class AVLNode
{
	T data;
	int height;
	AVLNode<T>* left;
	AVLNode<T>* right;
	friend class AVL_Tree<T>;
public:
	AVLNode(T val)
	{
		data = val;
		height = 1;
		left = right = nullptr;
	}
	T getData(){ return data; }
};
template <typename T>
class AVL_Tree
{
	AVLNode<T>* root;
	bool helperIsBST(AVLNode<T>* root);
	string getRotationType(AVLNode<T>* node);
	AVLNode<T>* LLRotation(AVLNode<T>* node);
	AVLNode<T>* RRRotation(AVLNode<T>* node);
	AVLNode<T>* LRRotation(AVLNode<T>* node);
	AVLNode<T>* RLRotation(AVLNode<T>* node);
public:
	AVL_Tree();
	AVL_Tree(const AVL_Tree& obj);
	~AVL_Tree();
	void insert(T val);
	AVLNode<T>* search(T key);
	void deleteNode(AVLNode<T>* node);
	bool isBST(AVL_Tree<T> obj);
	int getBalanceFactor(AVLNode<T>* node);
	void printNodes(AVLNode<T>* root);
	AVLNode<T>* getParent(AVLNode<T>* root);
	void printTree();
	AVLNode<T>* getRoot(){ return root; }
	int newHeight(AVLNode<T>* node);
	bool isEmpty(){ return root == nullptr; }
};