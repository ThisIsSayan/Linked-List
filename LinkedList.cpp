#include<iostream>
using namespace std;
struct Node
{
  int data;
  Node* next;
};
Node* head;
Node* create(int data)
{
  Node* newNode = new Node();
  (*newNode).data = data;
  //newNode -> data = data;
  (*newNode).next = nullptr;
}
void append(int data)
{
  Node* temp = create(data);
	if(head == NULL)
  {
    head = temp;
    return;
  }
  Node* current = head;
  while(current->next != NULL)
  {
    current = current->next;
  }
  current->next = temp;
  return;
  
}
void show()
{
  Node* current = head;
  while(current != NULL)
  {
    cout << current->data << " --> ";
    current = current->next;
  }
  cout << endl;
}
void prepend(int data)
{
  Node* temp = create(data);
  temp->next = head;
  head = temp;
}
void insert(int pos, int data)
{
  Node* temp = create(data);
  Node* current = head;
  for(int i=0; i<pos-1; i++)
  {
    current = current->next;
  }
  temp->next = current->next;
  current->next = temp;
}
void del(int data)
{
  Node* current = head;
  while(current != NULL)
  {
    if(current->next->data == data)
    {
      break;
    }
    current = current->next;
  }
  current->next = current->next->next;
}
void rev()
{
  Node* current = head, *next = NULL, *prev = NULL;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
int main()
{
  append(5);
  append(9);
  append(3);
  show();
  prepend(11);
  show();
  insert(2, 13);
  show();
  rev();
  show();
}