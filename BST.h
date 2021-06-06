#ifndef BST_H
#define BST_H

class Bst{
private:
	struct Bstnode{
		int data;
		Bstnode* left;
		Bstnode* right;
	};
	Bstnode* rootPtr;

	Bstnode* insertPrivate(Bstnode* nodeptr, int data);
	bool isNumExistsPrivate(Bstnode* nodeptr, int data);
	Bstnode* DeleteNodePrivate(Bstnode* rootptr, int data);
	Bstnode* FindMinInTree(Bstnode* rootPtr);
public:
	Bst() :rootPtr(0){}
	void print();
	void printInorderRecursive(Bstnode* rptr);
	void printInorderIterative(Bstnode* rptr);
	void printPreorderIterative(Bstnode* rptr);
	void printLevelOrder(Bstnode* rptr);
	void printRightView(Bstnode* rptr, int currLevel, int *maxLevel);
	void printLeftView(Bstnode* rptr, int currLevel, int *maxLevel);
	void printLeftViewUsingQ(Bstnode* rptr);
	void printRightViewUsingQ(Bstnode* rptr);
	void insert(int data);
	bool isNumExists(int data);
	void DeleteNode(int data);
	
};



#endif
