#pragma once
#include<iostream>

using namespace std;

class Tree
{
private:
	int static const SIZE = 20;
	struct node
	{
		int key;
		char data[SIZE];
		//bool isPrevios;
		//node* ancestor;
		node* left;
		node* right;
		node(int k, char const d[])
		{
			key = k;
			strcpy_s(data, d);
			//isPrevios = false;
			//ancestor = nullptr;
			left = nullptr;
			right = nullptr;
		}
	};

	node* head;
	void showR(node* removable);
	void clearR(node* head);
	node* getHeir(node* node);
	
public:
	Tree();
	~Tree();
	bool Has(int key);
	char* Get(int key);
	void Set(int key, char const data[]);
	bool Remove(int key);
	void Clear();
	void Show();

};

