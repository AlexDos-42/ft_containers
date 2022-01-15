#include <iostream>
#include <map>
                       
void AffMAP(std::map<char, int>){
    for(std::map<>::iterator<> it)
    std::cout << std::map[it]
    
}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

///Constructor:
void Construct() {
  std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  std::map<char,int,classcomp> fourth;
std::cout << "Size of first: " << first.size() << '\n';

}
void operatorEgale() {
  std::map<char,int> first;
  std::map<char,int> second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  second=first;
  first=std::map<char,int>();

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
}

///Iterators:
void begin() {

}
void end() {

}
void rbegin() {
    
}
void rend() {
    
}

///Capacity:
void empty() {
    
}
void size() {
    
}
void max_size() {
    
}

///Element access:
void operatorC() {
    
}

///Modifiers:
void insert() {
    
}
void erase() {
    
}
void swap() {
    
}
void clear() {
    
}

///Observers:
void key_comp() {
    
}
void value_comp() {
    
}

///Operations:
void find() {
    
}
void count() {
    
}
void lower_bound() {
    
}
void upper_bound() {
    
}
void  equal_range() {
    
}

///Allocator:
void get_allocator() {
    
}

void mapTest() {
    
///Constructor:
Construct();
operatorEgale();

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
operatorC();

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