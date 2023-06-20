#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree tree;
	
	tree.Set(5, "test5");
	tree.Set(7, "test7");
	tree.Set(3, "test3");
	tree.Set(5, "test5");
	tree.Set(2, "test2");
	tree.Set(0, "test0");
	tree.Set(78, "test78");
	tree.Set(55, "test55");
	tree.Set(533, "test533");
	tree.Set(4, "test4");
	tree.Set(99, "test99");
	tree.Set(100, "test100");
	tree.Set(534, "test534");
	tree.Show();

	tree.Remove(3);
	tree.Remove(533);
	tree.Show();
	
	tree.Clear();
	tree.Show();
	
	Tree tree_1;
	int arr[201];
	for (int i = 0; i < 201; i++)
	{
		arr[i] = i;
	}

	srand(time(0));
	for (int i = 0; i < 201; ++i)
	{
		std::swap(arr[i], arr[std::rand() % 201]);
	}


	for (int i = 0; i < 201; i++)
	{
		tree_1.Set(arr[i], "t");
	}
	
	for (int i = 0; i < 201; i++)
	{
		tree_1.Remove(i);
	}

	for (int i = 199; i < 201; i++)
	{
		cout << tree_1.Has(i);
	}
	/*Tree tree;
	tree.Set(30, "a");//
	tree.Set(20, "b");
	tree.Set(50, "c");
	tree.Set(15, "d");
	tree.Set(25, "h");
	tree.Set(47, "k");
	tree.Set(55, "m");
	tree.Set(2, "n");
	tree.Set(16, "o");
	tree.Set(24, "p");
	tree.Set(40, "s");
	tree.Set(53, "w");
	tree.Set(20, "x");
	tree.Show();
	tree.Remove(30);
	tree.Show();*/

    return 0;
}


