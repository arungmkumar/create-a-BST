#include "Bst.h"

#include <iostream>
using namespace std;
int main(){

	Bst bst1;
	bst1.print();
	bst1.insert(10);
	bst1.insert(2);
	bst1.insert(20);
	bst1.insert(5);
	bst1.insert(4);
	bst1.insert(18);
	bst1.insert(19);
	bst1.insert(6);
	bst1.insert(30);
	/*       10
	2                 20
	    5       18          30
     4     6        19
	*/

	
	//bst1.print();
	//int num;
	cout << endl;
	/*cout << "Enter number to be searched" << endl;
	cin >> num;
	
	(bst1.isNumExists(num)) ? (cout << num << " exists") : (cout << num << " doesnt exist");*/

	//bst1.DeleteNode(10);
	bst1.print();
	return 0;
}
