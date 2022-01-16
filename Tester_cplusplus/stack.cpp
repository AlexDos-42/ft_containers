#include <iostream>
#include <stack>
#include "../stack/stack.hpp"                  

void next();

///Constructor:
void Construct() {
  std::cout << "\e[95mConstruct: \e[0m" << std::endl;

}
void operatorEgale() {
  std::cout << "\e[95moperator=: \e[0m" << std::endl;
}

///Iterators:
void begin() {
  std::cout << "\e[95mbegin: \e[0m" << std::endl;
}
void end() {
  std::cout << "\e[95mend: \e[0m" << std::endl;
}
void rbegin() {
  std::cout << "\e[95mrbegin: \e[0m" << std::endl;
    
}
void rend() {
  std::cout << "\e[95mrend: \e[0m" << std::endl;
    
}

///Capacity:
void empty() {
  std::cout << "\e[95mempty: \e[0m" << std::endl;
    
}
void size() {
  std::cout << "\e[95msize: \e[0m" << std::endl;
}
void max_size() {
  std::cout << "\e[95mmax_size: \e[0m" << std::endl;
}

///Element access:
void operatorC() {
}

///Modifiers:
void insert() {
  std::cout << "\e[95minsert: \e[0m" << std::endl;
}
void erase() {
  std::cout << "\e[95merase: \e[0m" << std::endl;
}
void swap() {
  std::cout << "\e[95mswap: \e[0m" << std::endl;
    
}
void clear() {
  std::cout << "\e[95mclear: \e[0m" << std::endl;
}

///Observers:
void key_comp() {
  std::cout << "\e[95mkey_comp: \e[0m" << std::endl;
}
void value_comp() {
  std::cout << "\e[95mvalue_comp: \e[0m" << std::endl;
}

///Operations:
void find() {
  std::cout << "\e[95mfind: \e[0m" << std::endl;
}
void count() {
  std::cout << "\e[95mcount: \e[0m" << std::endl;
}
void lower_bound() {
  std::cout << "\e[95mlower_bound: \e[0m" << std::endl;
    
}
void upper_bound() {
  std::cout << "\e[95mupper_bound: \e[0m" << std::endl;
    
}
void  equal_range() {
  std::cout << "\e[95mequal_range: \e[0m" << std::endl;
    
}

///Allocator:
void get_allocator() {
  std::cout << "\e[95mget_allocator: \e[0m" << std::endl;
}

void vectorTest() {
    
///Constructor:
Construct();

///Destructor:
destructor();

///Copy:
operator=();
Copy();

///Iterators:
begin();
end();
rbegin();
rend();

///Capacity:
empty();
size();
max_size();

///Element access:
operator[]();

///Modifiers:
insert();
erase();
swap();
clear();

///Observers:
key_comp();
value_comp();

///Operations:
find();
count();
lower_bound();
upper_bound();
equal_range();

///Allocator:
get_allocator();

}