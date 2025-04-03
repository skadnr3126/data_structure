#include <iostream>
#define MAX 10001


typedef struct Node {
	int data;
	Node* link;

}Node;

class linked_list { //class로 구현 
private:
	Node* head;

public:

	linked_list() {
		head = nullptr;
	}

	void insert_last(int data) {
		if (head == nullptr) {
			head = new Node();
			head->data = data;
			head->link = head;
		}
		else {
			Node* temp = new Node();
			temp->link = head->link;
			temp->data = data;
			head->link = temp;
			head = temp;
		}
	}
	void insert_first(int data) {
		if (head == nullptr) {
			head = new Node();
			head->data = data;
			head->link = head;
		}
		else {
			Node* temp = new Node();
			temp->data = data;
			temp->link = head->link;
			head->link = temp;
		}
	}
	void print_node() {
		
		if (head == nullptr) {
			return;
		}
		else {
			Node* p = head;
			do {
				p = p->link;
				std::cout << p->data << std::endl;

			} while (p != head);
		}
	}
};


void insert_first(Node *&head, int data){
	if (head == nullptr) {
		head = new Node();
		head->data = data;
		head->link = head;
	}
	else {
		Node* temp = new Node();
		temp->data = data;
		temp->link = head->link;
		head->link = temp;
	}

}

void insert_last(Node*& head, int data) {
	if (head == nullptr) {
		head = new Node();
		head->data = data;
		head->link = head;
	}
	else {
		Node* temp = new Node();
		temp->data = data;
		temp->link = head->link;
		head->link = temp;
		head = temp;
	}

}
void print_node(Node*& head) {
	if (head == nullptr) {
		return;
	}
	else {
		Node* p = head;
		do {
			p = p->link;
			std::cout << p->data << std::endl;
		} while (p != head);
	}
}

int main() {
	linked_list num_1 = linked_list();
	num_1.insert_first(5);
	num_1.insert_first(4);
	num_1.insert_first(3);
	num_1.insert_first(2);
	num_1.insert_first(1);
	num_1.insert_last(6);
	num_1.print_node();

	std::cout << "struct" << std::endl;
	Node* head = nullptr; // node()로 해도 상관없기는 한데, nunllptr로 하는게 비어있다는 상태를 더 잘나태내준다
	insert_last(head, 1);
	insert_last(head, 2);
	insert_last(head, 3);
	insert_last(head, 4);
	insert_last(head, 5);
	insert_first(head, 0);
	print_node(head);

}