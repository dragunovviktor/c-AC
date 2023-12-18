#include <iostream>
struct Node {
    int value;
    Node* next;
};

void PushFront(Node*& root, int new_value) { // Добавляет узел с value в начало списка
  Node* new_node = new Node;
  new_node->value = new_value;
  new_node->next = root;
  root = new_node;
}

void PopFront(Node*& root) { // Удаляет первый корень в начале списка
  if (root == nullptr) {
    std::cout << "Empty" << "\n";
    return;
  }

  Node* new_node = root->next;
  delete root;
  root = new_node;

}

void Size(Node*& root) { // Дает длинну списка
  if (root == nullptr) {
    std::cout << "0 - Empty" << "\n";
    return;
  }

  int count = 0;
  Node* runner = root;
  while (runner != nullptr) {
    count += 1;
    runner = runner->next;
  }
  std::cout << count << "\n";
}

void PushBack(Node*& root, int new_value) { // Добавляет корень с value в конец списка
  if (root == nullptr) {
    PushFront(root, new_value);
    return;
  }

  Node* runner = root;
  while (runner->next != nullptr) {
    runner = runner->next;

  }

  Node* new_node = new Node;
  new_node->value = new_value;
  new_node->next = nullptr;
  runner->next = new_node;

}

void PopBack(Node*& root) { // Удаляет корень в конце списка
  if (root == nullptr) {
    std::cout << "Empty" << "\n";
    return;
  }

  if (root->next == nullptr) {
    PopFront(root);
    return;
  }

  Node* runner = root;
  while (runner->next->next != nullptr) {
    runner = runner->next;
  }
  delete runner->next;
  runner->next = nullptr;
}

void Add(Node*& previous, int new_value) { // Добавляет корень с value в после корня previous
  Node* new_node = new Node;
  new_node->value = new_value;
  new_node->next = previous->next;
  previous->next = new_node;
}

void Remove(Node*& previous) { // Удаляет корень после корня previous
  Node* next_previous = previous->next;
  previous->next = next_previous->next;
  delete next_previous;
}

void Delete(Node*& root) { // Удаляет список --- ОБЯЗАТЕЛЬНО ДЕЛАТЬ ВСЕГДА!!!
  while (root != nullptr) {
    Node* next = root->next;
    delete root;
    root = next;
  }
  root = nullptr;
}

void Display(Node*& root) { // Выводит список на экран
  if (root == nullptr) {
    std::cout << "Empty" << "\n";
    return;
  }

  Node* runner = root;
  while (runner != nullptr) {
    std::cout << runner->value << " ";
    runner = runner->next;

  }

  std::cout << "\n";

}
