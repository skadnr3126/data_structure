#include <iostream>
#include <vector>
//typical tree
class Node {
    std::string key;
    Node* next_sibling;
    Node* firstchild;

public:

    Node(std::string key) {
        Node::key = key;
        next_sibling = nullptr;
        firstchild = nullptr;
    }

    static void add_child(Node* parent, Node* child) {
        //temp에 무엇을 저장해야 되는가? temp의 용도를 이애하고 무엇을 저장해야되는지 이해하자
        //Node* temp = parent->firstchild; // 이렇게 하면 temp 라는 새로운 변수에 null값이 들어갈 뿐이다.
        //temp = parent 이렇게 해야 null일때 오류가 안난다?
        Node *temp = parent;
        if (temp->firstchild == nullptr) {
            temp->firstchild = child;
            return;
        }
        temp = temp->firstchild; // 무조건 널이 아님
        while (temp->next_sibling != nullptr) {
            temp = temp->next_sibling;//무조건 널이 아님
        }
        temp->next_sibling = child; //널일때
    }
    static void PrintTree(Node* first_child, int depth) {
        //std::cout << "enter print tree";
        Node* temp = first_child;
        while (temp != nullptr) {
            for (int i = 0; i < depth; ++i) {
                std::cout << " ";
            }
            std::cout << temp->key << std::endl;

            if(temp->firstchild !=nullptr)
                PrintTree(temp->firstchild, depth + 1);
            temp = temp->next_sibling;
        }
    }
};

int main() {
    Node* head = new Node("head");

    std::vector<Node*> middle;
    middle.push_back(new Node("middle1"));
    middle.push_back(new Node("middle2"));
    middle.push_back(new Node("middle3"));

    std::vector<Node*> bottom;
    bottom.push_back(new Node("botton1"));
    bottom.push_back(new Node("botton2"));
    bottom.push_back(new Node("botton3"));
    bottom.push_back(new Node("botton4"));
    bottom.push_back(new Node("botton5"));
    bottom.push_back(new Node("botton6"));

    for (int i = 0; i < 3; ++i) {
        Node::add_child(head, middle[i]);
        for (int j = i * 2; j < i * 2 + 2; ++j) {
            Node::add_child(middle[i], bottom[j]);
        }
    }

    Node::PrintTree(head, 0);
}