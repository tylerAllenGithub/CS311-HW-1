//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Tyler Allen
//Compiler: g++  
//File type: .cpp
//===========================================================

#ifndef QUEUE_CPP
#define QUEUE_CPP//include guards


using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  count=0;
  front=0;
  rear=-1;
}

//destructor 
queue::~queue()
{
  //nothing to do
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count==0)
    return true;
  return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count>=MAX_SIZE)
    return true;
  return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(isFull())
    throw queue::Overflow();
  else
    {
      rear = (rear+1) % MAX_SIZE; //increment rear and mod by max size to wrap around to start
	el[rear] = newElem; //set the rear element in el array to newElem parameter     
      count++; //increment count variable
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(isEmpty())
    throw queue::Underflow();
  else
    {
      removedElem = el[front];
      front = (front+1) % MAX_SIZE;
      count--;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(isEmpty())
    {
      throw queue::Underflow();
    }
  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
  //Displays current values of variables
  cout<<"Front: "<<front<<" "<<"Count: "<<count<<" "<<"Rear: "<<rear<<endl;
  cout<<"[ ";//beginning brace
  if(isEmpty())//if queue is empty 
    cout<<"empty";//display empty
  else//if the queue is not empty
       {
//If the front is greater than the rear, front needs to loop around to reach rear
	 if(front>rear)
	   {
	     for(int i = front; i<MAX_SIZE;i++)//proceeds until front reaches end of array
	       {
		 cout<<el[i];//displays element at position i
		 if(count>1)//if count is only 1 then no comma is necessary
		   cout<<", ";//print comma if necessary
	       }
	     for(int i = 0; i<=rear;i++)//continue looping through queue from position 0 to rear
	       {
		 cout<<el[i];//displays element at position i
		 if(count>1&&i<rear)//if the count is 1 and if i is the last element's position then no comma is necessary
		   cout<<", ";//print comma if necessary
	       }
	   }//end if(front<rear)
	 else//if front <= rear
	   {
	     for(int i = front; i<=rear;i++)//loop until element i reaches rear
	       {
		 cout<<el[i];//displays element at position i
		 if(count>1&&i<rear)//if the count is 1 and if i is the last element's position then no comma is necessary
		   cout<<", ";//print comma if necessary
	       }
	   }
       }
  cout<<" ]"<<endl;//ending brace
    
}
// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{//local variable to store result of remove function passed by reference
  el_t var;
  if(isEmpty())//if queue is empty
    throw queue::Underflow();
  else if(count>1)//if queue has more than one element
    {
      remove(var);//remove top element and store in var
      add(var);//add var to rear of queue
    }

}

#endif//end include guard



