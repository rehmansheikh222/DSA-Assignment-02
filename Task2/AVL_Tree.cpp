#include "AVL_Tree.h"
template <typename T>
AVL_Tree<T>::AVL_Tree()
{
	root = nullptr;
}
template <typename T>
AVL_Tree<T>::AVL_Tree(const AVL_Tree<T>& obj) :root(nullptr)
{
	if (obj.root)
	{
		root = new AVLNode<T>(obj.root->data);
		queue<AVLNode<T>*> q;
		queue<AVLNode<T>*> q2;
		q.push(obj.root);
		q2.push(root);
		while (!q.empty())
		{
			AVLNode<T>* p1 = q.front();
			AVLNode<T>* p2 = q2.front();
			if (p1->left)
			{
				p2->left = new AVLNode<T>(p1->left->data);
				q.push(p1->left);
				q2.push(p2->left);
			}
			if (p1->right)
			{
				p2->right = new AVLNode<T>(p1->right->data);
				q.push(p1->right);
				q2.push(p2->right);
			}
			q.pop();
			q2.pop();
		}
	}
}
template <typename T>
AVLNode<T>* AVL_Tree<T>::search(T key)
{
	AVLNode<T>* p = root;
	while (p)
	{
		if (key == p->data)
		{
			return p;
		}
		else if (key < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return p;
}
template <typename T>
int AVL_Tree<T>::getBalanceFactor(AVLNode<T>* node)
{
	if (node == nullptr)
		return 0;
	int bf = newHeight(node->left) - newHeight(node->right);
	return bf;
}
template <typename T>
string AVL_Tree<T>::getRotationType(AVLNode<T>* node)
{
	string s = "";
	if (getBalanceFactor(node) == 2 && (getBalanceFactor(node->left) == 1 || getBalanceFactor(node->left) == 0))
		s = "ll";
	else if (getBalanceFactor(node) == -2 && (getBalanceFactor(node->right) == -1 || getBalanceFactor(node->right) == 0))
		s = "rr";
	else if (getBalanceFactor(node) == 2 && getBalanceFactor(node->left) == -1)
		s = "lr";
	else if (getBalanceFactor(node) == -2 && getBalanceFactor(node->right) == 1)
		s = "rl";
	return s;
}
template <typename T>
AVLNode<T>* AVL_Tree<T>::LLRotation(AVLNode<T>* node)
{
	AVLNode<T>* nLeft = node->left;
	AVLNode<T>* nLRight = node->left->right;
	nLeft->right = node;
	node->left = nLRight;
	node->height = newHeight(node);
	nLeft->height = newHeight(nLeft);
	if (node == root)
		root = nLeft;
	return nLeft;
}
template <typename T>
AVLNode<T>* AVL_Tree<T>::RRRotation(AVLNode<T>* node)
{
	AVLNode<T>* nRight = node->right;
	AVLNode<T>* nRLeft = node->right->left;
	nRight->left = node;
	node->right = nRLeft;
	node->height = newHeight(node);
	nRight->height = newHeight(nRight);
	if (node == root)
		root = nRight;
	return nRight;
}
template <typename T>
AVLNode<T>* AVL_Tree<T>::LRRotation(AVLNode<T>* node)
{
	AVLNode<T>* nLeft = node->left;
	AVLNode<T>* nLRight = nLeft->right;
	AVLNode<T>* nLRLeft = nLRight->left;
	AVLNode<T>* nLRRight = nLRight->right;
	nLRight->left = node->left;
	nLRight->right = node;
	nLeft->right = nLRLeft;
	node->left = nLRRight;
	nLeft->height = newHeight(nLeft);
	node->height = newHeight(node);
	nLRight->height = newHeight(nLRight);
	if (node == root)
	{
		root = nLRight;
	}
	return nLRight;
}
template <typename T>
AVLNode<T>* AVL_Tree<T>::RLRotation(AVLNode<T>* node)
{
	AVLNode<T>* nRight = node->right;
	AVLNode<T>* nRLeft = nRight->left;
	AVLNode<T>* nRLLeft = nRLeft->left;
	AVLNode<T>* nRLRight = nRLeft->right;
	nRLeft->right = node->right;
	nRLeft->left = node;
	node->right = nRLLeft;
	nRight->left = nRLRight;
	nRight->height = newHeight(nRight);
	node->height = newHeight(node);
	nRLeft->height = newHeight(nRLeft);
	if (node == root)
	{
		root = nRLeft;
	}
	return nRLeft;
}
template <typename T>
int AVL_Tree<T>::newHeight(AVLNode<T>* node)
{
	if (node == nullptr)
		return 0;
	int h = 1;
	int hLeft = 0, hRight = 0;
	if (node->left)
	{
		hLeft = node->left->height;
	}
	if (node->right)
	{
		hRight = node->right->height;
	}
	if (hLeft > hRight)
		h += hLeft;
	else
		h += hRight;
	return h;
}
template <typename T>
void AVL_Tree<T>::insert(T val)
{
	AVLNode<T>* newNode = new AVLNode<T>(val);
	if (!root)
	{
		root = newNode;
		return;
	}
	stack<AVLNode<T>*> s;
	AVLNode<T>* p = root, *q = nullptr;
	while (p)
	{
		s.push(p);
		q = p;
		if (val < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (q->data>val)
	{
		q->left = newNode;
	}
	else
	{
		q->right = newNode;
	}
	AVLNode<T>* n;
	while (!s.empty())
	{
		n = s.top();
		s.pop();
		n->height = newHeight(n);
		int bF = getBalanceFactor(n);
		if (!(bF >= -1 && bF <= 1))
		{
			string str = getRotationType(n);
			if (str == "ll")
				n = LLRotation(n);
			else if (str == "rr")
				n = RRRotation(n);
			else if (str == "lr")
				n = LRRotation(n);
			else if (str == "rl")
				n = RLRotation(n);
		}
		if (!s.empty())
		{
			AVLNode<T>* temp = s.top();
			if (temp->data > n->data)
			{
				temp->left = n;
			}
			else
			{
				temp->right = n;
			}
			s.pop();
			s.push(temp);
		}
	}
}
template <typename T>
void AVL_Tree<T>::deleteNode(AVLNode<T>* node)
{
	if (!node)
	{
		cout << "The node is null" << endl;
		return;
	}
	T key = node->data;
	if (!root)
	{
		cout << "There is no node present in the tree" << endl;
		return;
	}
	stack<AVLNode<T>*> s;
	AVLNode<T>* p = root;
	AVLNode<T>* q = nullptr;
	while (p && p != node)
	{
		q = p;
		s.push(q);
		if (key < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (!p)
	{
		cout << "The node to be deleted does not exist" << endl;
		return;
	}
	if (p->left && p->right)
	{
		AVLNode<T>* min = p->left;
		AVLNode<T>* par = nullptr;
		while (min && min->right)
		{
			par = min;
			s.push(par);
			min = min->right;
		}
		T temp = min->data;
		min->data = p->data;
		p->data = temp;
		if (par)
		{
			q = par;
			p = min;
		}
		else
		{
			q = p;
			s.push(q);
			p = min;
		}
	}
	if (p->left || p->right)
	{
		if (p->left)
		{
			if (p == root)
			{
				root = root->left;
				delete p;
				return;
			}
			AVLNode<T>* t = p->left;
			if (q->left == p)
			{
				q->left = t;
			}
			else if (q->right == p)
			{
				q->right = t;
			}
			delete p;
		}
		else if (p->right)
		{
			if (p == root)
			{
				root = root->right;
				delete p;
				return;
			}
			AVLNode<T>* t = p->right;
			if (q->left == p)
			{
				q->left = t;
			}
			else if (q->right == p)
			{
				q->right = t;
			}
			delete p;
		}
	}
	else if (!p->left && !p->right)
	{
		if (p == root)
		{
			root = nullptr;
			delete p;
			return;
		}
		if (q->left == p)
		{
			delete q->left;
			q->left = nullptr;
		}
		else if (q->right == p)
		{
			delete q->right;
			q->right = nullptr;
		}
	}
	AVLNode<T>* n;
	while (!s.empty())
	{
		n = s.top();
		s.pop();
		n->height = newHeight(n);
		int bF = getBalanceFactor(n);
		if (!(bF >= -1 && bF <= 1))
		{
			string str = getRotationType(n);
			if (str == "ll")
				n = LLRotation(n);
			else if (str == "rr")
				n = RRRotation(n);
			else if (str == "lr")
				n = LRRotation(n);
			else if (str == "rl")
				n = RLRotation(n);
		}
		if (!s.empty())
		{
			AVLNode<T>* temp = s.top();
			if (temp->data > n->data)
			{
				temp->left = n;
			}
			else
			{
				temp->right = n;
			}
			s.pop();
			s.push(temp);
		}
	}
}
template <typename T>
void AVL_Tree<T>::printNodes(AVLNode<T>* root)
{
	if (!root)
	{
		cout << "The tree has no node" << endl;
		return;
	}
	cout << "Level Order Traversal is" << endl;
	queue<AVLNode<T>*> q;
	AVLNode<T>* p = root;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		cout << p->data << " ";
		if (p->left)
		{
			q.push(p->left);
		}
		if (p->right)
		{
			q.push(p->right);
		}
	}
	cout << endl;
}
template <typename T>
void AVL_Tree<T>::printTree()
{
	if (!root)
	{
		cout << "The tree has no node" << endl;
		return;
	}
	queue<AVLNode<T>*> q;
	AVLNode<T>* p = root;
	q.push(p);
	while (!q.empty())
	{
		int nodesInLevel = q.size();
		while (nodesInLevel != 0)
		{
			p = q.front();
			q.pop();
			cout << p->data << " ";
			if (p->left)
			{
				q.push(p->left);
			}
			if (p->right)
			{
				q.push(p->right);
			}
			nodesInLevel--;
		}
		cout << endl;
	}
}
template <typename T>
bool AVL_Tree<T>::helperIsBST(AVLNode<T>* root)
{
	if (!root)
	{
		return true;
	}
	if (!root->left && !root->right)
	{
		return true;
	}
	bool b1 = true, b2 = true;
	if (root->left)
	{
		if (root->data > root->left->data)
			b1 = helperIsBST(root->left);
		else
			return false;
	}
	if (root->right)
	{
		if (root->data <= root->right->data)
			b2 = helperIsBST(root->right);
		else
			return false;
	}
	if (b1&&b2)
		return true;
	return false;
}
template <typename T>
bool AVL_Tree<T>::isBST(AVL_Tree<T> obj)
{
	AVLNode<T>* r = obj.root;
	return helperIsBST(r);
}
template <typename T>
AVLNode<T>* AVL_Tree<T>::getParent(AVLNode<T>* node)
{
	////Code for simple binary tree
	//if (node == root)
	//{
	//	cout << "No parent of the node as it is the root node" << endl;
	//	return nullptr;
	//}
	//queue<AVLNode<T>*> q;
	//AVLNode<T>* p = root;
	//q.push(root);
	//while (!q.empty())
	//{
	//	p = q.front();
	//	q.pop();
	//	if (p->left && node == p->left)
	//		return p;
	//	if (p->right && node == p->right)
	//		return p;
	//	if (p->left)
	//		q.push(p->left);
	//	if (p->right)
	//		q.push(p->right);
	//}
	//cout << "The node is not present in the tree" << endl;
	//return nullptr;
	AVLNode<T>* p = root;
	if (!p)
	{
		cout << "Tree is empty" << endl;
		return p;
	}
	if (node == root)
	{
		cout << "No parent of the node as it is the root node" << endl;
		return nullptr;
	}
	AVLNode<T>* q = nullptr;
	while (p && p != node)
	{
		q = p;
		if (p->data > node->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (p)
	{
		return q;
	}
	cout << "The node is not present in the tree" << endl;
	return nullptr;
}
template <typename T>
AVL_Tree<T>::~AVL_Tree()
{
	if (root)
	{
		while (root&&root->left)
		{
			deleteNode(root->left);
		}
		while (root&&root->right)
		{
			deleteNode(root->right);
		}
		if (root)
		{
			delete root;
			root = nullptr;
		}
	}
}
