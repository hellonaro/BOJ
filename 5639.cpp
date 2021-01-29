#include <iostream>
using namespace std;

/*
이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 
이 트리를 후위 순회한 결과를 구하는 프로그램을 작성하시오.
*/

struct node {
	int data;
	node* left;
	node* right;
};

node* makeNode(int n) {
	node* newNode = new node;
	newNode->data = n;
	newNode->left = NULL; newNode->right = NULL;
	return newNode;
}

void insertNode(node* curNode, node* newNode) {
	if (curNode->data > newNode->data) {
		if (curNode->left == NULL) {
			curNode->left = newNode;
			return;
		}
		insertNode(curNode->left, newNode);
	}
	else {
		if (curNode->right == NULL) {
			curNode->right = newNode;
			return;
		}
		insertNode(curNode->right, newNode);
	}
}

void postOrder(node* curNode) {
	if (curNode == NULL) return;
	postOrder(curNode->left);
	postOrder(curNode->right);
	cout << curNode->data << "\n";
	delete(curNode);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num; cin >> num;
	node* root = makeNode(num);
	
	for (; ;) {
		cin >> num; 
		if (cin.eof()) break;
		node* newNode = makeNode(num);
		insertNode(root, newNode);
	}
	postOrder(root);
}