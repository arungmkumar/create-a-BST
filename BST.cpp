#include "Bst.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void Bst::print(){
	//printInorderRecursive(rootPtr);
	//printInorderIterative(rootPtr);
	//printPreorderIterative(rootPtr);
	//printLevelOrder(rootPtr);
	int max = 0;
	//printRightView(rootPtr,0,&max);
	//printLeftView(rootPtr, 1, &max);
	//printLeftViewUsingQ(rootPtr);
	printRightViewUsingQ(rootPtr);
}

void Bst::printRightViewUsingQ(Bstnode* rptr){
	if (!rptr) return;

	queue<Bstnode*> Q;
	Q.push(rptr);

	while (!Q.empty()){
		int size = Q.size();
		for (int i = 0; i < size; i++){

			Bstnode* tmp = Q.front();
			if (i == size-1) cout << tmp->data << " ";
			if (tmp->left) Q.push(tmp->left);
			if (tmp->right) Q.push(tmp->right);
			Q.pop();
		}
	}
}

void Bst::printLeftViewUsingQ(Bstnode* rptr){
	if (!rptr) return;

	queue<Bstnode*> Q;
	Q.push(rptr);

	while (!Q.empty()){
		int size = Q.size();
		for (int i = 0; i < size; i++){
			
			Bstnode* tmp = Q.front();
			if (i==0) cout << tmp->data << " ";
			if (tmp->left) Q.push(tmp->left);
			if (tmp->right) Q.push(tmp->right);
			Q.pop();
		}
	}
}
void Bst::printLeftView(Bstnode * node, int currLevel, int *maxLevel){

	if (node == NULL) return;

	if (currLevel >  *maxLevel){
		cout << node->data << " ";
		*maxLevel = currLevel;
	}
	printRightView(node->left, currLevel + 1, maxLevel);
	printRightView(node->right, currLevel + 1, maxLevel);
	
}

void Bst::printRightView(Bstnode * node, int currLevel, int *maxLevel){

	if (node == NULL) return;

	if (currLevel >  *maxLevel){
		cout<<node->data<<" ";
		*maxLevel = currLevel;
	}
	printRightView(node->right, currLevel + 1, maxLevel);
	printRightView(node->left, currLevel + 1, maxLevel);
}
void Bst::printLevelOrder(Bstnode* rptr){
	/*       10
	2                 20
	    5       18          30
	4      6        19
	*/

	if (!rptr) return;
	queue<Bstnode*> Q;

	Q.push(rptr);
	Bstnode* tmp = nullptr;
	while (!Q.empty()){
		tmp = Q.front();
		cout << tmp->data << endl;
		if (tmp->left) Q.push(tmp->left);
		if (tmp->right) Q.push(tmp->right);
		Q.pop();
	}
 

}
void Bst::printInorderRecursive(Bstnode* rptr){
	
	if (rptr == nullptr){
		return;
	}
	printInorderRecursive(rptr->left);
	cout << rptr->data << " ";
	
	printInorderRecursive(rptr->right);
}
void Bst::printInorderIterative(Bstnode* rptr){
	stack<Bstnode*> st;
	if (rptr == nullptr) return;

	while (true){
		if (rptr){
			st.push(rptr);
			rptr = rptr->left;
		}
		else{
			if (st.empty()) break;

			rptr = st.top();
			st.pop();
			cout << rptr->data << " ";
			rptr = rptr->right;
		}

	}
}

void Bst::printPreorderIterative(Bstnode* rptr){
	stack<Bstnode*> st;
	if (rptr == nullptr) return;

	st.push(rptr);
	while (!st.empty()){
		cout << st.top()->data << " ";
		rptr = st.top();
		st.pop();
		if (rptr->right) st.push(rptr->right);
		if (rptr->left) st.push(rptr->left);

	}
	
}
void Bst::insert(int data){

	rootPtr = insertPrivate(rootPtr, data);
}

Bst::Bstnode* Bst::insertPrivate(Bstnode* rootp, int data){
	Bstnode* newNode = new Bstnode();
	newNode->data = data; newNode->left = nullptr; newNode->right = nullptr;
	if (rootp == nullptr){
		rootp = newNode;
		}
	else if (data <= rootp->data)
		rootp->left=insertPrivate(rootp->left, data);
	else
		rootp->right=insertPrivate(rootp->right, data);

	return rootp;
}

bool Bst::isNumExistsPrivate(Bstnode* rootPtr, int data){
	if (rootPtr == nullptr){
		return false;
	}
	else if (data == rootPtr->data)
		return true;
	else if (data < rootPtr->data)
		return isNumExistsPrivate(rootPtr->left, data);
	else
		return isNumExistsPrivate(rootPtr->right, data);
}
bool Bst::isNumExists(int data){
	return isNumExistsPrivate(rootPtr, data);
}

void Bst::DeleteNode(int data){
	rootPtr=DeleteNodePrivate(rootPtr, data);
}
Bst::Bstnode* Bst::DeleteNodePrivate(Bstnode* rootptr, int data){
	if (rootptr == nullptr)
		return rootptr;
	else if (data < rootptr->data){
		rootptr->left= DeleteNodePrivate(rootptr->left, data);
		return rootptr;
	}
	else if (data > rootptr->data){
		rootptr->right= DeleteNodePrivate(rootptr->right, data);
		return rootptr;
	}
	else{

		if (rootptr->left == nullptr && rootptr->right == nullptr){
			delete rootptr;
			rootptr = nullptr; return rootptr;

		}
		else if (rootptr->left == nullptr){
			Bstnode* tmp = rootptr->right;
			//rootptr->data = tmp->data;
			rootptr = tmp;
			delete tmp; return rootptr;
		}
		else if(rootptr->right == nullptr){
			Bstnode* tmp = rootptr->left;
			//rootptr->data = tmp->data;
			rootptr = tmp;
			delete tmp; return rootptr;
		}
		else{
			Bstnode* tmp = FindMinInTree(rootptr->right);
			rootptr->data = tmp->data;
			cout << "****"<<tmp->data << endl;
			rootptr->right = DeleteNodePrivate(rootptr->right, tmp->data);
			return rootptr;
		}

	}
}

Bst::Bstnode* Bst::FindMinInTree(Bstnode* rootPtr){
	if (rootPtr->left == nullptr){
		return rootPtr;
	}
	else
		return FindMinInTree(rootPtr->left);

}
