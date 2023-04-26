#include<iostream>
#include"BST.h"


int values[255] = { 50, 30, 70, 20, 40, 60, 80 };

//			50                                     
//		    / \        
//		 30     70     
//		 / \    / \                               
//      20  40 60  80
//		   Height: 3

int main(int argv, char* argc[]) {

	BST<int> a;
	for (size_t i = 0; i < 7; i++) 
		a.insert(values[i]);

	// <---------------Traversals test cases ---------------->

	std::cout << "\nPostorder Traversal:\t\t";
	a.postOrder();

	std::cout << "\nPreorder Traversal:\t\t";
	a.preOrder();

	std::cout << "\nInorder Traversal:\t\t";
	a.inOrder();
	// <---------------		     END         ---------------->


	// <---------------		     HEIGHT         ---------------->

	std::cout << "\n\n\nHeight of the tree: " << a.getHeight() << "\n\n";


	// <---------------                        LEFT-RIGHT                      ---------------->

	std::cout << "In-order successor of the Node(70): \t" << a.inOrderSucc(70)->data << "\n\n";
	std::cout << "Predecessor of the Node(70): \t" << a.predecessor(70)->data << "\n\n";
	// <---------------                         END                            ---------------->


	// <---------------           MIN-MAX              ---------------->

	std::cout << "Max value of BST: \t" << a.maxValue() << "\n\n";
	std::cout << "Min value of BST: \t" << a.minValue() << "\n\n\n\n";
	// <---------------              END                 ---------------->


	// <---------------           Searching              ---------------->
	std::cout << "Search value of 70: \t" << a.search(70)->data << "\n\n";
	std::cout << "Search value of 20: \t" << a.search(20)->data << "\n\n";
	// <---------------              END                 ---------------->



	// <---------------        Remove test cases           ---------------->
	std::cout << "\n\n\nRemoving value of 20 \t";
	a.remove(20);
	std::cout << "\nInorder Traversal:\t\t";
	a.inOrder(); 
	std::cout << "\n\n";
	// ---
	std::cout << "Removing value of 80 \t";
	std::cout << "\nInorder Traversal:\t\t";
	a.remove(80);
	a.inOrder();
	std::cout << "\n\n";
	// ---
	std::cout << "Removing value of 100(test) \t";
	std::cout << "\nInorder Traversal:\t\t";
	a.remove(100);
	a.inOrder();
	std::cout << "\n\n";
	// <---------------                END                 ---------------->


	return 0;
}



//node<T>* serach(T);
//node<T>* remove(T);
//node<T>* minValue();
//node<T>* maxValue();
//node<T>* inOrderSucc(T);
//node<T>* predecessor();
//void insert(T);
//void inOrder();
//void preOrder();
//void postOrder();
//int getHeight();