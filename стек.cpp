struct Node {
    int value;
    Node* next;
};

void Push(Node*& root, int new_value) { // == PushFront
  Node* new_node = new Node;
  new_node->value = new_value;
  new_node->next = root;
  root = new_node;
}

void Pop(Node*& root) { // == PopFront
  if (root == nullptr) {
    std::cout << "Empty" << "\n";
    return;
  }
  Node* new_node = root->next;
  delete root;
  root = new_node;
}

int Top(Node*& root) { // Берёт верхний корень и дает value
  if (root == nullptr) {
    return -1;
  }
  return root->value;
}

// + доп функции с АТД списка