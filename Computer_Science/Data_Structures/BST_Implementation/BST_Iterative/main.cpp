#include<iostream>
#include"BST_Iterative"

int values[255] = { 50, 30, 70, 20, 40, 60, 80 };

//			50                                     
//		    / \        
//		 30     70     
//		 / \    / \                               
//      20  40 60  80
//		   Height: 3




int main(int argv, char* argc[]) {
	BST<int> a;
	
	for (int i = 0; i < 7; i++)
		a.insert(values[i]);
	a.inOrder();

	auto b = a.search(50);
	auto c = a.search(20);
	auto d = a.search(80);
	auto z = a.search(100);
	auto min = a.minValue();
	auto max = a.maxValue();
	auto inorder = a.inOrderSucc(50);
	auto inorder2 = a.inOrderSucc(20);
	auto inorder3B = a.inOrderSucc(100);
	auto pre = a.predecessor(50);
	auto pre2= a.predecessor(80);
	auto pre3B = a.predecessor(100);
	std::cout << "\n\n\n";
	a.preOrder();

	std::cout << a.getHeight();

	std::cin.get();

	return 0;
}



