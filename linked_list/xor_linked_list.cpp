#include <iostream>
#include <cstdint>

class Node {
public:
  Node() : m_val(0), m_npx(nullptr) {}
  Node(int v) : m_val(v), m_npx(nullptr) {}
  static Node *XOR(Node *a, Node *b) {
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    Node *result = (Node *)(uintptr_t(a) ^ uintptr_t(b));
    return result;
  }

  void InsertAtHead(Node* &head, int val) {
    Node *newNode = new Node(val);
    newNode->m_npx = head;
    if (head != nullptr) {
      head->m_npx = XOR(head->m_npx, newNode);
    }
    head = newNode;
    std::cout<<"Insert at head done\n";
  }

  void IterateForward(Node* head) {
    Node *prev = nullptr;
    while (head) {
      std::cout << head->m_val << " ";
      Node* temp = XOR(head->m_npx, prev);
      prev = head;
      head = temp;
    }
    std::cout<<"\n";
  }

  void IterateBackward(Node* end) { 
    Node* next = nullptr;
    while(end) {
        std::cout<< end->m_val << " ";
        Node* temp = XOR(end->m_npx, next);
        next = end;
        end = temp;
    }
    std::cout<<"\n";
  }


public:
  int m_val;
  Node *m_npx;
};

int main() { 
    Node *head = nullptr; 
    head->InsertAtHead(head,20);
    Node* end = head; 
    head->InsertAtHead(head,30);
    head->InsertAtHead(head,40);
    
    head->IterateForward(head);
    head->IterateBackward(end);
}
