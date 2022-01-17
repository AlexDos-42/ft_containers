#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "../stack/stack.hpp"                  

void next();

void stack_Construct() {
  std::cout << "\e[95mConstruct: \e[0m" << std::endl;
  std::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack

  ft::stack<int,std::vector<int> > second;  // empty stack using vector
  ft::stack<int,std::vector<int> > third (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << second.size() << '\n';
  std::cout << "size of fourth: " << third.size() << '\n';
}

void stack_empty() {
  std::cout << "\e[95mempty: \e[0m" << std::endl;
  ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';   
}

void stack_size() {
  std::cout << "\e[95msize: \e[0m" << std::endl;
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}

void stack_top() {
  std::cout << "\e[95mmax_size: \e[0m" << std::endl;
  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void stack_push() {
  std::cout << "\e[95mpush: \e[0m" << std::endl;
  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}
void stack_pop() {
  std::cout << "\e[95mpop: \e[0m" << std::endl;
  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void stackTest() {
    
stack_Construct();
next();
stack_empty();
stack_size();
next();
stack_top();
stack_push();
stack_pop();
next();
}