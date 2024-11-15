#include <iostream>
#include <string>
#include <sstream>

struct Node {
	int value;
	Node* next;
	Node(int value, Node* next = nullptr) : value(value), next(next) {}
};

class SinglyLinkedList {
	Node* head = nullptr;
	Node* middle = nullptr;
	Node* tail = nullptr;
	int length = 0;

public:

	SinglyLinkedList() = default;
	SinglyLinkedList(const SinglyLinkedList& other) = delete;
	SinglyLinkedList& operator= (const SinglyLinkedList& other) = delete;
	~SinglyLinkedList() {
		while (head) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void push_back(int value) {
		if (head == nullptr) {
			head = new Node(value);
			middle = tail = head;
			length++;
			return;
		}

		tail->next = new Node(value);
		tail = tail->next;
		length++;
		if (length % 2 == 1) {
			middle = middle->next;
		}
	}

	void middleSwap() {
		tail->next = head;
		Node* tmp = middle;
		middle = head;
		head = tmp->next;
		tail = tmp;
		tail->next = nullptr;
	}

	void printList() const {
		Node* tmp = head;
		while (tmp) {
			std::cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}
};


static std::pair<std::string, int> parseCommand(const std::string& cmd) {
	std::stringstream ss(cmd);
	std::string command;
	int x;
	ss >> command;
	if (!ss.eof()) {
		ss >> x;
	}

	return {command, x};
}

void printList(Node* head) {
	Node* tmp = head;
	while (tmp) {
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
}
int main() {

	Node* head, *middle, *tail;
	head = middle = tail = nullptr;
	int n;
	std::cin >> n;
	std::cin.ignore();
	SinglyLinkedList list;
	for (int i = 0; i < n; i++) {
		
		std::string cmd;
		getline(std::cin, cmd);
		auto action = parseCommand(cmd);
		if (action.first == "add") {
			list.push_back(action.second);
		}
		else if(action.first == "swap") {
			list.middleSwap();
		}
	}
	list.printList();

	return 0;
}