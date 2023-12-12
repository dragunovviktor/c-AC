#include <iostream>
#include <string>

// Связный список
struct node {
    int value;
    node* next;
};

// Вставка элемента в начало списка
void push_front(int new_value, node*& root) {
  node* new_node = new node;
  new_node->value = new_value;
  new_node->next= root;
  root = new_node;
}

// Удаление первого элемента списка
void pop_front(node*& root) {
  if (root == nullptr) {
    return;
  }
  node* new_root = root->next;
  delete root;
  root = new_root;
}

// Получение размера списка
int size(node*& root) {
  int count = 0;
  node* runner = root;
  while (runner != nullptr) {
    count++;
    runner = runner->next;
  }
  return count;
}

// Вставка элемента в конец списка
void back(int new_value, node*& root) {
  if (root == nullptr) {
    push_front(new_value,root);
    return;
  }
  node* runner = root;
  while (runner -> next != nullptr) {
    runner = runner -> next;
  }
  node* new_node = new node;
  new_node -> value = new_value;
  new_node->next= nullptr;
  runner->next=new_node;
}

// Удаление последнего элемента списка
void popback (node*& root) {
  if (root == nullptr) {
    return;
  }
  if (root -> next == nullptr) {
    pop_front(root);
  }
  node* runner = root -> next;
  while (runner -> next -> next != nullptr) {
    runner = runner -> next;
  }
  delete runner -> next;
  runner -> next = nullptr;
}