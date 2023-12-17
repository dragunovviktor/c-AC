#include <iostream>
struct Node {

    int value;

    Node* left = nullptr;

    Node* right = nullptr;

};

void FindMax(Node* node) {

  if (node == nullptr) {

    std::cout << "Empty";

    return;

  }

  if (node->right != nullptr) {

    return FindMax(node->right);

  }

  if (node->right == nullptr) {

    std::cout << node->value << "\n";

    return;

  }

}

void FindMin(Node* node) {

  if (node == nullptr) {

    std::cout << "Empty";

    return;

  }

  if (node->left != nullptr) {

    return FindMin(node->left);

  }

  if (node->left == nullptr) {

    std::cout << node->value << "\n";

    return;

  }

}

void Search(Node* node, int key) { // Ищет элемент в дереве. Можно написать для приватного использования (тогда 33 - Node* и + return node)

  if (node == nullptr) {

    std::cout << "Not find";

    return;

  }

  if (key == node->value) {

    std::cout << "Find" << "\n";

    return;

  }

  if (key > node->value) {

    return Search(node->right, key);

  }

  if (key < node->value) {

    return Search(node->left, key);

  }

}

void Push(Node*& node, int key) {

  if (node == nullptr) {

    Node* new_node = new Node;

    new_node->value = key;

    node = new_node;

  } else if (key == node->value) {

    std::cout << "The element already exists";

  } else if (key > node->value) {

    if (node->right == nullptr) {

      Node* new_node = new Node;

      new_node->value = key;

      node->right = new_node;

    } else {

      Push(node->right, key);

    }

  } else if (key < node->value) {

    if (node->left == nullptr) {

      Node *new_node = new Node;

      new_node->value = key;

      node->left = new_node;

    } else {

      Push(node->left, key);

    }

  }

}

void PreOrder(Node* root) {

  if (root != nullptr) {

    std::cout << root->value << " ";

    PreOrder(root->left);

    PreOrder(root->right);

  }

}

void InOrder(Node* root) { // ВЫВОДИТ ОТСОРТИРОВАННЫЕ ДАННЫЕ!!!!

  if (root != nullptr) {

    InOrder(root->left);

    std::cout << root->value << " ";

    InOrder(root->right);

  }

}

void PostOrder(Node* root) {

  if (root != nullptr) {

    PostOrder(root -> left);

    PostOrder(root -> right);

    std::cout << root->value << " ";

  }

}

Node* DeleteNode(Node* node, int key) { // РАЗОБРАТЬСЯ

  if (node == nullptr) { // если пусто

    return node;

  }

  if (node->value > key) { // отвечает за передвижение

    node->left = DeleteNode(node->left, key);

    return node;

  } else if (node->value < key) {

    node->right = DeleteNode(node->right, key);

    return node;

  }

  if (node->left == nullptr) { // удаление

    Node* tmp = node->right;

    delete node;

    return tmp;

  } else if (node->right == nullptr) {

    Node* tmp = node->left;

    delete node;

    return tmp;

  } else {

    Node* parent = node;

    Node* runner = node->right;

    while (runner->left != nullptr) {

      parent = runner;

      runner= runner->left;

    }

    if (parent != node) {

      parent->left = runner->right;

    } else {

      parent->right = runner->right;

    }

    node->value = runner->value;

    delete runner;

    return node;

  }

}

void RemoveTee(Node* root) {

  if (root != nullptr) {

    RemoveTee(root->left);

    RemoveTee(root->right);

    delete root;

  }

}