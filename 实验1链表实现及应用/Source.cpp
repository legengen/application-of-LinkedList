#include <iostream>
typedef int ElemType;
struct Node {
	ElemType data=0;
	Node* next=nullptr;
};
typedef Node* LinkList;
void insertLinkList(LinkList p, ElemType data, int order);
void prinfLinkList(LinkList head);
void deleteNode(LinkList p,int order);
int main() {
	LinkList head = new Node;
	ElemType data;
	int length = 0;
	while (std::cin >> data && data != 0) {
		insertLinkList(head, data, 1);
		length++;
	}
	for (int i = 0;i <= length;i++) {
		prinfLinkList(head);
		deleteNode(head, 1);
	}	
}
void insertLinkList(LinkList p,ElemType data,int order) {
	while (--order) {		
		p=p->next;
	}
	LinkList newnode = new Node;
	newnode->data = data;
	newnode->next = p->next;
	p->next = newnode;
}
void prinfLinkList(LinkList head) {
	head = head->next;
	if (!head) {
		std::cout << "empty list!" << std::endl;
		return;
	}
	while (head) {
		std::cout << head->data<<" ";
		head = head->next;
	}
	std::cout << std::endl;
	return;
}
void deleteNode(LinkList p, int order) {
	LinkList deletedNode;
	while (--order) {
		p = p->next;
	}
	if (p->next==nullptr) return;
	deletedNode = p->next;
	p->next = deletedNode->next;
	delete deletedNode;
}