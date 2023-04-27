#ifndef BINARY_SEARCH_TREE_R
#define BINARY_SEARCH_TREE_R
// Iterative implementation

#include <iostream>
#include <stack>

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
	node<T>* search(T value);
	node<T>* predecessor(T);
	node<T>* inOrderSucc(T);
	node<T>* minValue();
	node<T>* maxValue();
	void postOrder();
	void preOrder();
	void inOrder();
	void insert(T);
	int getHeight();
};


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
inline node<T>* BST<T>::maxValue()
{
	node<T>* current = root;
	while (current->right)
		current = current->right;
	return current;
}

template<typename T>
inline node<T>* BST<T>::inOrderSucc(T value)
{
	auto res = search(value);
	return res ? res->left : nullptr;
}

template<typename T>
inline node<T>* BST<T>::predecessor(T value)
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
// not finished
template<typename T>
void BST<T>::postOrder()
{

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
//not finished
template<typename T>
int BST<T>::getHeight() {
	if (!root) return 0;
	int highest = 0;
	int currCount = 0;

	node<T>* current = root;
	std::stack<node<T>*> stack;

	while (current || !stack.empty())
	{
		while (current)
		{
			stack.push(current);
			current = current->left;
			currCount++;
		}

		if (currCount > highest)
			highest = currCount;
		current = stack.top();

		stack.pop();
		current = current->right;

	}
	return highest;
}


// finish those 3 and destructor
//node<T>* remove(T);
//void postOrder();
//int getHeight();


#endif