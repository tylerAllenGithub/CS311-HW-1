//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Tyler Allen
// Compiler:  g++ 
// File type: header file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------
#ifndef STACK_H
#define STACK_H//include guards


const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is int for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  el_t     el[MAX];       // el is  an array of el_t's
  int      top;           // top is index to the top of stack
  
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: Receives el_t to be passed by reference; receiving the value of el_t 
  void topElem(el_t&);

  //PURPOSE: To determine if the stack is empty or not.
  //         Returns true if empty and false if not empty.
  //PARAMETER: Receives no parameters
  bool isEmpty();
  //PURPOSE:  To determine if the stack is empty  if (top == -1)
  //         Returns true if empty and false if not empty.
  //PARAMETER: Receives no parameters
  bool isFull();
  //PURPOSE: To print a list of the contents of the stack
  //PARAMETER: Takes no parameters
  void displayAll();
  //PURPOSE: Removes all the contents of the stack
  //PARAMETER:Takes no parameters
  void clearIt();
  
};  

// Note: semicolon is needed at the end of the header file

#endif
