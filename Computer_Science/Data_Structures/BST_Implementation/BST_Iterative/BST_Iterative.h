#ifndef BINARY_SEARCH_TREE_R
#define BINARY_SEARCH_TREE_R
// Iterative implementation

#include <iostream>
#include <stack>
#include <queue>

template<typename T>
struct node {
	node(T value) : data(value) {};
	T data;
	node<T>* left = nullptr, * right = nullptr;
};

template<typename T>
class BST {
private:
	node<T>* root = nullptr;
public:
	BST() = default;
	~BST();
	node<T>* search(T value);
	node<T>* predecessor(T);
	node<T>* inOrderSucc(T);
	node<T>* minValue();
	node<T>* maxValue();
	void postOrder();
	void preOrder();
	void inOrder();
	void insert(T);
	void remove(T);
	void clean();
	int getHeight();
};

template<typename T>
BST<T>::~BST() {
	clean();
}

template<typename T>
node<T>* BST<T>::search(T value) {
	if (!root) return nullptr;
	node<T>* current = root;
	while (current) {
		if (current->data > value)
			current = current->left;
		else if (current->data < value)
			current = current->right;
		else return current;
	}
	return nullptr;
}

template<typename T>
node<T>* BST<T>::minValue()
{
	node<T>* current = root;
	while (current->left)
		current = current->left;
	return current;
}

template<typename T>
node<T>* BST<T>::maxValue()
{
	node<T>* current = root;
	while (current->right)
		current = current->right;
	return current;
}

template<typename T>
node<T>* BST<T>::inOrderSucc(T value)
{
	auto res = search(value);
	return res ? res->left : nullptr;
}

template<typename T>
node<T>* BST<T>::predecessor(T value)
{
	auto res = search(value);
	return res ? res->right : nullptr;
}

template<typename T>
void BST<T>::insert(T value) {
	if (!root) {
		root = new node<T>(value);
		return;
	}

	node<T>* current = root;

	while (current)
	{
		if (current->data > value)
		{
			if (!current->left) {
				current->left = new node<T>(value);
				return;
			}
			else current = current->left;
		}
		else if (current->data < value)
		{
			if (!current->right) {
				current->right = new node<T>(value);
				return;
			}
			else current = current->right;
		}
		else
			current = current->right;
	}

}

template<typename T>
void BST<T>::remove(T value) {
	if (!root) return;
	node<T>* current = root;
	node<T>* parent = nullptr;

	while (current && current->data != value) {
		parent = current;
		if (current->data > value)
			current = current->left;
		else if (current->data < value)
			current = current->right;
	}

	if (!current) return;

	if (!current->left && !current->right) {
		if (parent) {
			if (parent->left == current)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else {
			root = nullptr;
		}
		delete current;
		return;
	}

	if (current->left && current->right) {
		node<T>* temp = current->right;
		parent = nullptr;

		while (temp->left) {
			parent = temp;
			temp = temp->left;
		}

		current->data = temp->data;

		if (parent) {
			if (parent->left == temp)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else {
			current->right = nullptr;
		}
		delete temp;
	}
	else if (current->left) {
		if (parent) {
			if (parent->left == current)
				parent->left = current->left;
			else
				parent->right = current->left;
		}
		else {
			root = current->left;
		}
		delete current;
	}
	else {
		if (parent) {
			if (parent->left == current)
				parent->left = current->right;
			else
				parent->right = current->right;
		}
		else {
			root = current->right;
		}
		delete current;
	}
}


template<typename T>
void BST<T>::postOrder()
{
	if (!root) return ;
	node<T>* cur = root;
	node<T>* min = minValue();
	std::queue<node<T>*> queue, queue2;
	queue.push(cur);
	queue2.push(cur);
	int num = 1;

	while (!queue2.empty()) {
		int levelSize = num;
		num = 0;
		while (levelSize > 0) {
			cur = queue2.front();
			queue2.pop();
			if (cur->left) {
				queue.push(cur->left);
				queue2.push(cur->left);
				num++;
			}
			if (cur->right) {
				queue.push(cur->right);
				queue2.push(cur->right);
				num++;
			}
			levelSize--;
		}

	}

	while (!queue.empty())
	{
		std::cout << queue.front()->data << ", ";
		queue.pop();
	}


}

template<typename T>
void BST<T>::preOrder()
{
	if (!root) return;

	std::stack<node<T>*> stack;
	node<T>* current = root;

	while (!stack.empty() || current) {
		while (current)
		{
			stack.push(current);
			std::cout << current->data << " ";
			current = current->left;
		}

		current = stack.top();
		stack.pop();
		current = current->right;
	}
}

template<typename T>
void BST<T>::inOrder() {
	if (!root) return;

	std::stack<node<T>*> stack;
	node<T>* current = root;

	while (!stack.empty() || current) {
		while (current)
		{
			stack.push(current);
			current = current->left;
		}

		current = stack.top();
		std::cout << current->data << " ";
		stack.pop();

		current = current->right;
	}

}

template<typename T>
int BST<T>::getHeight() {
	if (!root) return 0;
	int hight = 0;
	node<T>* current = root;
	std::queue<node<T>*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		int levelSize = queue.size();
		while (levelSize > 0) {
			node<T>* Node = queue.front();
			queue.pop();

			if (Node->left)
				queue.push(Node->left);
			if (Node->right)
				queue.push(Node->right);
			levelSize--;
		}
		hight++;
	}

	return hight;
}


template<typename T>
void BST<T>::clean()
{
	
	if (!root) return;

	std::queue<node<T>*> queue;
	queue.push(root);

	while (!queue.empty()) {
		node<T>* current = queue.front();
		queue.pop();

		if (current->left) {
			queue.push(current->left);
		}
		if (current->right) {
			queue.push(current->right);
		}

		delete current;
	}

	root = nullptr;

}




#endif