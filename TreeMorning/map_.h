#pragma once
#include <iostream>
using namespace std;

template<class T1, class T2>
struct node {
	T1 key;
	T2 value;
	node<T1, T2> *parent = nullptr;
	node<T1, T2> *left = nullptr;
	node<T1, T2> *right = nullptr;
};


template<class T1, class T2>
class map_
{
	node<T1, T2> *root;
	int size;
public:
	map_();
	void insert(const T1& key, const T2& value);

	node<T1, T2>*getNode() { return root; }
	node<T1, T2>* min(node<T1, T2>* nd);
	node<T1, T2>*delNode(node<T1, T2> *nd, const T1 key);

	T2& find(const T1& key);
	void print()const;

	void printNode(node<T1, T2>*nd) const;

	void copyNode(node<T1, T2>*nd);
	map_(const map_<T1, T2>&obj);

	map_(map_<T1, T2>&&obj);
	map_<T1, T2>& operator=(const map_<T1, T2>&obj);
	map_<T1, T2>& operator=(map_<T1, T2>&&obj);
	~map_();
	void deleteNodes(node<T1, T2>*nd);
};

template<class T1, class T2>
inline map_<T1, T2>::map_()
{
	root = nullptr;
	size = 0;
}

template<class T1, class T2>
void map_<T1, T2>::insert(const T1 & key, const T2 & value)
{
	node<T1, T2> *newNode = new node<T1, T2>;
	newNode->key = key;
	newNode->value = value;
	if (root == nullptr) {
		root = newNode;
		size = 1;
		return;
	}
	node<T1, T2>*tmp = root;
	node<T1, T2>*y = nullptr;
	while (tmp != nullptr) {
		y = tmp;
		if (key < tmp->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	if (key < y->key)
		y->left = newNode;
	else
		y->right = newNode;
	newNode->parent = y;
	size++;
}

template<class T1, class T2>
inline node<T1, T2>* map_<T1, T2>::min(node<T1, T2>* nd)
{
	node<T1, T2>*current = nd;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

template<class T1, class T2>
inline node<T1, T2>* map_<T1, T2>::delNode(node<T1, T2> *root, const T1 key)
{
	if (root == nullptr)
		return root;
	if (key < root->key)
		root->left = delNode(root->left, key);
	else if (key > root->key)
		root->right = delNode(root->right, key);
	else
	{
		if (root->left == nullptr)
		{
			node<T1, T2>* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == nullptr)
		{
			node<T1, T2>* tmp = root->left;
			delete root;
			return tmp;
		}
		node<T1, T2>* tmp = min(root->right);
		root->key = tmp->key;
		root->value = tmp->value;

		root->right = delNode(root->right, tmp->key);
	}
	return root;
}

template<class T1, class T2>
inline T2 & map_<T1, T2>::find(const T1 & key)
{
	node<T1, T2>*tmp = root;
	while (tmp != nullptr) {
		if (key == tmp->key)
			return tmp->value;
		else if (key < tmp->key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	//return (T2)"0";
}

template<class T1, class T2>
inline void map_<T1, T2>::print() const
{
	printNode(root);
}

template<class T1, class T2>
inline void map_<T1, T2>::printNode(node<T1, T2>* nd) const
{
	if (nd != nullptr) {
		printNode(nd->left);
		cout << nd->key << " " << nd->value << endl;
		printNode(nd->right);
	}
}

template<class T1, class T2>
inline void map_<T1, T2>::copyNode(node<T1, T2>* nd)
{
	if (nd != nullptr)
	{
		insert(nd->key, nd->value);
		copyNode(nd->left);
		copyNode(nd->right);
	}

}

template<class T1, class T2>
inline map_<T1, T2>::map_(const map_<T1, T2>& obj)
{
	copyNode(obj.root);
}

template<class T1, class T2>
inline map_<T1, T2>::map_(map_<T1, T2>&& obj)
{
	this->root = obj.root;
	this->size = obj.size;
	obj.root = nullptr;
	obj.size = 0;
}

template<class T1, class T2>
inline map_<T1, T2>& map_<T1, T2>::operator=(const map_<T1, T2>& obj)
{
	if (this == &obj) return *this;
	this->~map_();
	copyNode(obj.root);
	return *this;
}

template<class T1, class T2>
inline map_<T1, T2>& map_<T1, T2>::operator=(map_<T1, T2>&& obj)
{
	swap(obj.root, this->root);
	swap(obj.size, this->size);
	return *this;
}

template<class T1, class T2>
inline map_<T1, T2>::~map_()
{
	deleteNodes(root);
	root = nullptr;
	size = 0;
}

template<class T1, class T2>
inline void map_<T1, T2>::deleteNodes(node<T1, T2>* nd)
{
	if (nd != nullptr) {
		deleteNodes(nd->left);
		deleteNodes(nd->right);
		delete nd;
		size--;
	}
}

