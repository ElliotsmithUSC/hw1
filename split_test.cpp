#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std ;

int main(){

Node* odds = nullptr;
Node* evens = nullptr;
Node* six = new Node(6,nullptr);
Node* five = new Node(5,six);
Node* four = new Node(4,five);
Node* three = new Node(3,four);
Node* two = new Node(2,three);
Node* one = new Node(1,two);
Node* head = new Node(0,one);



split(head, odds, evens);
while(odds != nullptr){
  cout << odds->value << endl;
  odds = odds->next;
}
while (evens != nullptr){
  cout << evens->value << endl;
  evens = evens->next;
}
delete odds;
delete evens;
delete six;
delete five;
delete four;
delete three;
delete two;
delete one;
delete head;
}
