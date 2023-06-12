#include "Tree.h"

void Tree::showR(node* head)
{
	if (head != nullptr)
	{
		showR(head->left);
		cout << head->data;
		cout << " ";
		showR(head->right);
	}
}

void Tree::clearR(node* head)
{
	if (head != nullptr)
	{
		clearR(head->left);
		clearR(head->right);
		delete head;
	}
}

Tree::node* Tree::getHeir(node* removable)
{
	node* heirParent = removable;
	node* heir = removable;
	node* current = removable->right;
	while (current != nullptr)
	{
		heirParent = heir;
		heir = current;
		current = current->left;
	}

	if (heir != removable->right)
	{
		heirParent->left = heir->right;
		heir->right = removable->right;
	}
	return heir;
}

Tree::Tree()
{
	head = nullptr;
}

Tree::~Tree()
{
	Clear();
	//delete head;//
}

bool Tree::Has(int key)
{
	node* current = head;
	if (current == nullptr) return false;

	while (current->key != key)
	{
		if (key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
		if (current == nullptr)
		{
			return false;
		}
	}
	return true;
}

char* Tree::Get(int key)
{
	node* current = head;

	while (current->key != key)
	{
		if (key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	
	return current->data;
}

bool Tree::Remove(int key)
{
	node* current = head;
	node* parent = head;
	bool isLeft = true;

 	while (current->key != key)
	{
		parent = current;
		if (key < current->key)
		{
			isLeft = true;
			current = current->left;
		}
		else
		{
			isLeft = false;
			current = current->right;
		}
		if (current == nullptr)
			return false;
	}

	if (current->left == nullptr && current->right == nullptr)
	{
		if (current == head)
		{
			//head = nullptr;
			delete head;
			head = nullptr;
		}
		else if (isLeft)
		{
			//parent->left = nullptr;
			delete parent->left;
			parent->left = nullptr;
		}
			
		else
		{
			//parent->right = nullptr;
			delete parent->right;
			parent->right = nullptr;
		}
			
	}
	else if (current->right == nullptr)
	{
		if (current == head)
		{
			head = current->left;
			delete current;
		}
		else if (isLeft)
		{
			parent->left = current->left;
			delete current;
		}
		else
		{
			parent->right = current->left;
			delete current;
		}
					
	}
	else if (current->left == nullptr)
		if (current == head)
		{
			head = current->right;
			delete current;
		}
		else if (isLeft)
		{
			parent->left = current->right;
			delete current;
		}
		else
		{
			parent->right = current->right;
			delete current;
		}
	else
	{
		node* heir = getHeir(current);

		if (current == head)
		{
			heir->left = current->left;
			delete head;
			head = heir;
			
		}
		else if (isLeft)
		{
			parent->left = heir;
			parent->left->left = current ->left;
			delete current;
		}
		else
		{
			parent->right = heir;
			heir->left = current->left;//
			parent->right->left = current->left;
			delete current;
		}
	}
	return true;
}

void Tree::Clear()
{
	clearR(head);
	head = nullptr;
}

void Tree::Show()
{
	showR(head);
	cout << endl;
}

void Tree::Set(int key, char const data[])
{
	if (head == nullptr)
	{
		head = new node(key, data);
	}
	else
	{
		node* current = head;
		node* parent;
		while (true)
		{
			parent = current;
			if (key < current->key)
			{
				current = current->left;
				if (current == nullptr)
				{
					parent->left = new node(key, data);
					return;
				}
			}
			else if (key > current->key)
			{
				current = current->right;
				if (current == nullptr)
				{
					parent->right = new node(key, data);
					return;
				}
			}
			else
			{
				strcpy_s(current->data, data);
				return;
			}
		}
	}
}

