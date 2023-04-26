#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
// Recursive implementation
#include <iostream>
#include <algorithm>

// <---------------------------------------------------------->
template<typename T>
struct node {
	node(T value) : data(value) {};
	T data;
	node<T>* left = nullptr, *right = nullptr;
};

template<typename T>
node<T>* insertNode(node<T>* root, const T &value) {
	if (!root) 
		return new node<T>(value);

	if (root->data > value)
		root->left = insertNode(root->left, value);
	if (root->data < value)
		root->right = insertNode(root->right, value);
	return root;
}

template<typename T>
node<T>* searchNode(node<T>* root, const T &value) {
	
	if (!root || root->data == value) 
		return root;

	if (root->data > value)
		return searchNode(root->left, value);
	return searchNode(root->right, value);

}

template<typename T>
void inOrderNode(node<T>* root) {
	if (!root) return;
	inOrderNode(root->left);
	std::cout << root->data << " ";
	inOrderNode(root->right);
}

template<typename T>
void preOrderNode(node<T>* root) {
	if (!root) return;
	std::cout << root->data << " ";
	preOrderNode(root->left);
	preOrderNode(root->right);
}

template<typename T>
void postOrderNode(node<T>* root) {
	if (!root) return;
	postOrderNode(root->left);
	postOrderNode(root->right);
	std::cout << root->data << " ";
}

template<typename T>
node<T>* removeNode(node<T>* root, T value) {
	if (!root) return root;

	if (root->data > value)
		root->left = removeNode(root->left, value);
	else if (root->data < value)
		root->right = removeNode(root->right, value);
	else {
		if (!root->left && !root->right) {
			delete root;
			return nullptr;
		}
		node<T>* helper;
		if (!root->left) {
			helper = root->right;
			delete root;
			return helper;
		}
		if (!root->right) {
			helper = root->left;
			delete root;
			return helper;
		}
		helper = findMin(root->right);
		root->data = helper->data;
		delete helper;
		return root;

	}
	return root;

}

template<typename T>
node<T>* findMin(node<T>* root) {
	if (!root) return nullptr;
	if (!root->left) return root;
	findMin(root->left);
}

template<typename T>
node<T>* findMax(node<T>* root) {
	if (!root) return nullptr;
	if (!root->right) return root;
	findMax(root->right);
}

template<typename T>
int calculateHeight(node<T>* root){
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	int lVal = calculateHeight(root->left);
	int rVal = calculateHeight(root->right);
	return std::max(lVal, rVal) + 1;
}

// <---------------------------------------------------------->


template<typename T>
class BST{
public:
	BST() : root(nullptr) {};
	node<T>* search(T);
	node<T>* remove(T);
	T minValue();
	T maxValue();
	node<T>* inOrderSucc(T);
	node<T>* predecessor(T);
	void insert(T);
	void inOrder();
	void preOrder();
	void postOrder();	
	int getHeight();

private:
	node<T>* root;
};


template<typename T>
inline node<T>* BST<T>::search(T value)
{
	return searchNode(this->root, value);
}

template<typename T>
inline node<T>* BST<T>::remove(T value)
{
	return removeNode(root, value);
}

template<typename T>
inline T BST<T>::minValue()
{
	return findMin(root)->data;
}

template<typename T>
inline T BST<T>::maxValue()
{
	return findMax(root)->data;
}

template<typename T>
inline node<T>* BST<T>::inOrderSucc(T value)
{
	node<T>* node = searchNode(this->root, value);
	return node->left;
}

template<typename T>
inline node<T>* BST<T>::predecessor(T value)
{
	node<T>* node = searchNode(this->root, value);
	return node->right;
}

template<typename T>
inline void BST<T>::insert(T value)
{
	this->root = insertNode(root, value);
}

template<typename T>
inline void BST<T>::inOrder()
{
	inOrderNode(this->root);
}

template<typename T>
inline void BST<T>::preOrder()
{
	preOrderNode(root);
}

template<typename T>
inline void BST<T>::postOrder()
{
	postOrderNode(root);
}

template<typename T>
inline int BST<T>::getHeight()
{
	return calculateHeight(this->root);
}

#endif // !BINARY_SEARCH_TREE

