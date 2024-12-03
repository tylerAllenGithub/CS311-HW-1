//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Tyler Allen
//Compiler: g++  
//File type: client program
//===========================================================

#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

//Purpose of the program: To create a client program that utilizes the Queue class and its functions 
//Algorithm: **
int main()
{
  queue q;//create queue object
  //add beginning elements
  q.add("A");
  q.add("B");
  q.add("C");
  
  el_t temp;

  try//watch for errors
  {
    while(true)//continue looping until Overflow
    {
      q.remove(temp);//remove the top element from the queue
      q.add(temp+"A");//add the removed element concatenated with A
      q.add(temp+"B");//add the removed element concatenated with B
      q.add(temp+"C");//add the removed element concatenated with C

      cout<<temp<<endl;//display the removed element
      //if entire queue needs to be displayed call displayAll()
      //ex: 
      //queue q;
      //q.displayAll();
    }
  }

  catch(queue::Underflow)//if elements are attempting to be removed from an empty queue
   {
     cerr<<"There are no elements that can be removed from the queue."<<endl;//display error
     return 0;
   }
  catch(queue::Overflow)//if elements are attempting to be added to a full queue
   {
     cerr<<"No more elements can be added to the queue."<<endl;//display error
     return 0;
   }
 catch (char const* errorcode) // for invalid item
   {
     cerr<<"There was an invalid entry."<<endl;//display error
     return 0;
   }

}//end of program


  /*
*************************************************************************************************************************************************************************************
The following is a potential alternative program if the client wishes to do something else
I did it by accident and felt bad if I just deleted it all

   int choice;
  el_t input;
  el_t hold;
  
  cout<<endl;
  cout<<"Please select one of the following options: "<<endl;
  cout<<"Press 1 to add an element to the queue: "<<endl;
  cout<<"Press 2 to display the entire queue: "<<endl;
  cout<<"Press 3 to remove an element from the queue: "<<endl;
  cout<<"Press 4 to display the front element of the queue: "<<endl;
  cout<<"Press 5 to check to see if the queue is empty: "<<endl;
  cout<<"Press 6 to check to see if the queue is full: "<<endl;
  cout<<"Press 7 to quit: "<<endl;
  cout<<endl;
  cout<<"Your Choice: ";
  cin>>choice;
  cout<<endl;
  
  while(choice!=7)
    {
      try
	{
	  switch(choice)
	    {
	    case 1: cout<<"Please enter an element to be added to the Queue: ";
	      cin>>input;
	      q.add(input);
	      break;
	    case 2:
	      q.displayAll();
	      break;
	    case 3:
	      q.remove(hold);
	      cout<<hold<<" was removed from the Queue.";
	      break;
	    case 4:
	      q.frontElem(hold);
	      cout<<"The front element is: "<<hold;
	      break;
	    case 5:
	      cout<<"The Queue is ";
	      if(!q.isEmpty())
		cout<<"not ";
	      cout<<"empty.";
	      break;
	    case 6:
	      cout<<"The Queue is ";
              if(!q.isFull())
                cout<<"not ";
              cout<<"full.";
	      break;

	    default:
	      cout<<"Invalid input please try again."<<endl<<endl;
	    }
 
	}
      catch(queue::Underflow)
	{
	  cerr<<"There are no elements that can be removed from the queue."<<endl;
	  return 0;
	}
      catch(queue::Overflow)
	{
	  cerr<<"No more elements can be added to the queue."<<endl;
	  return 0;
	}
      catch (char const* errorcode) // for invalid item
        {
          cerr<<"There was an invalid entry."<<endl;
          return 0;
        }
      cout<<endl;
      cout<<"Please select one of the following options: "<<endl;
      cout<<"Press 1 to add an element to the queue: "<<endl;
      cout<<"Press 2 to display the entire queue: "<<endl;
      cout<<"Press 3 to remove an element from the queue: "<<endl;
      cout<<"Press 4 to display the front element of the queue: "<<endl;
      cout<<"Press 5 to check to see if the queue is empty: "<<endl;
      cout<<"Press 6 to check to see if the queue is full: "<<endl;
      cout<<"Press 7 to quit: "<<endl;
      cout<<"Your Choice: ";
      cin>>choice;//ask for input again
      cout<<endl;
    }
  cout<<"Now removing all elements..."<<endl;
  while(!q.isEmpty())  
    {
      q.remove(hold);
	cout<<"Deleted "<<hold<<endl;
    }
  */


