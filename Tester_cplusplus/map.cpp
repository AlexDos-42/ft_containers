#include <iostream>
#include <map>
#include "../map/map.hpp"                  

void next();

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

///Constructor:
void Construct() {
  std::cout << "\e[95mConstruct: \e[0m" << std::endl;
  std::cout << "default constructor: " << std::endl;
  ft::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;
  for (ft::map<char,int>::iterator it = first.begin(); it != first.end(); it++)
  	std::cout << it->second << " ";
  std::cout << std::endl << "range constructor: " << std::endl;
  ft::map<char,int> second (first.begin(),first.end());
  for (ft::map<char,int>::iterator it = second.begin(); it != second.end(); it++)
  	std::cout << it->second << " ";
  std::cout << std::endl << "copy constructor: " << std::endl;
  ft::map<char,int> third (second);
  for (ft::map<char,int>::iterator it = third.begin(); it != third.end(); it++)
  	std::cout << it->second << " ";
  std::cout << std::endl;

}
void operatorEgale() {
  std::cout << "\e[95moperator=: \e[0m" << std::endl;	
  ft::map<char,int> first;
  ft::map<char,int> second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  second=first;
  std::cout << "first: " << std::endl;
  for (ft::map<char,int>::iterator it = first.begin(); it != first.end(); it++)
  	std::cout << it->second << " ";
  std::cout << std::endl << "second: " << std::endl;
  for (ft::map<char,int>::iterator it = second.begin(); it != second.end(); it++)
  	std::cout << it->second << " ";
  std::cout << std::endl;
}

///Iterators:
void begin() {
  std::cout << "\e[95mbegin: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
void end() {
  std::cout << "\e[95mend: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;
  for (ft::map<char,int>::iterator it =mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
void rbegin() {
  std::cout << "\e[95mrbegin: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;
  ft::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
    
}
void rend() {
  std::cout << "\e[95mrend: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;
  ft::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
    
}

///Capacity:
void empty() {
  std::cout << "\e[95mempty: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  std::cout << "while not empty display begin()" << '\n';
  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
    
}
void size() {
  std::cout << "\e[95msize: \e[0m" << std::endl;
  ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
}
void max_size() {
  std::cout << "\e[95mmax_size: \e[0m" << std::endl;
  int i;
  ft::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";
}

///Element access:
void operatorC() {
  std::cout << "\e[95moperator[]: \e[0m" << std::endl;
  ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

///Modifiers:
void insert() {
  std::cout << "\e[95minsert: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  ft::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));
  mymap.insert (it, ft::pair<char,int>('c',400));

  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
void erase() {
  std::cout << "\e[95merase: \e[0m" << std::endl;
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
void swap() {
  std::cout << "\e[95mswap: \e[0m" << std::endl;
  ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it =bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    
}
void clear() {
  std::cout << "\e[95mclear: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it =mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it =mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

///Observers:
void key_comp() {
  std::cout << "\e[95mkey_comp: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
}
void value_comp() {
  std::cout << "\e[95mvalue_comp: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );
}

///Operations:
void find() {
  std::cout << "\e[95mfind: \e[0m" << std::endl;
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';
}
void count() {
  std::cout << "\e[95mcount: \e[0m" << std::endl;
  ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
}
void lower_bound() {
  std::cout << "\e[95mlower_bound: \e[0m" << std::endl;
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    
}
void upper_bound() {
  std::cout << "\e[95mupper_bound: \e[0m" << std::endl;
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    
}
void  equal_range() {
  std::cout << "\e[95mequal_range: \e[0m" << std::endl;
  ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator > ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';
    
}

///Allocator:
void get_allocator() {
  std::cout << "\e[95mget_allocator: \e[0m" << std::endl;
  int psize;
  ft::map<char,int> mymap;
  ft::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);
}

void mapTest() {
    
///Constructor:
Construct();
operatorEgale();
next();

///Iterators:
begin();
end();
rbegin();
rend();
next();

///Capacity:
empty();
size();
max_size();
next();

///Element access:
operatorC();
next();

///Modifiers:
insert();
erase();
swap();
clear();
next();

///Observers:
key_comp();
value_comp();
next();

///Operations:
find();
count();
lower_bound();
upper_bound();
equal_range();
next();

///Allocator:
get_allocator();
next();
}