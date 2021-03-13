#ifndef MAP
# define MAP

# include <cstddef>
# include <limits>
# include <iostream>
# include <functional>
# include "../utils/nodeMap.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
	class map
	{
		public:
            typedef	T											value_type;
			// typedef MapIterator<T>					            iterator;
			// typedef ConstMapIterator<T>			                const_iterator;
			// typedef ReverseMapIterator<T>			            reverse_iterator;
			// typedef ConstReverseMapIterator<T>		            const_reverse_iterator;
            typedef Alloc										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference  	const_reference;
			typedef NodeMap<T, Compare>					NodeMap;
		private:
			map				*m_root;
			Alloc			_allocator;
			Compare			m_comp;
			size_t			m_lenght;
		public:
			explicit MapBase(const Compare& m_comp = key_compare(), const Alloc& _allocator = Alloc())
				: _allocator(alloc), m_comp(comp), m_lenght(0){
				this->_first = new mapnode();
				this->_last = new mapnode();
				this->_first->parent = this->_last;
				this->_last->parent = this->_first;
				this->_size = 0;
			}
			///////// ITERATORS /////////
			

			///////// CAPACITY /////////
			

			///////// ELEMENTS ACCESS /////////
			

			///////// MODIFIERS /////////
			
			

			///////// LIST OPERATIONS /////////
			

			// const int MaxEle=256,CarParLin=121;                                  //WV
			// int nbE,lev,Lev[MaxEle],Prn[MaxEle];                                 //WV
			// Node *Arr[MaxEle];                                                   //WV
			// 																	//WV
			// int RecurDisplay(Node *nod) { // nod != 0                            //WV
			// if (nbE>=MaxEle) return 0;                                         //WV
			// if (nod->left) {++lev; Prn[RecurDisplay(nod->left)]=nbE; --lev;}   //WV
			// int num=nbE++;                                                     //WV
			// Arr[num]=nod; Lev[num]=lev;                                        //WV
			// if (nod->right) {++lev; Prn[RecurDisplay(nod->right)]=num; --lev;} //WV
			// return num;                                                        //WV
			// }                                                                    //WV
			// void RBTree::display() {                                             //WV
			// if (root) {nbE=0; lev=0;} else return;                             //WV
			// RecurDisplay(root);                                                //WV
			// char lin[MaxEle*CarParLin],*ln=lin,*l,*ll;                         //WV
			// memset(lin,' ',nbE*CarParLin);                                     //WV
			// for (int i=0; i<nbE; ++i,ln+=CarParLin) {                          //WV
			// 	l=ln+6*Lev[i];                                                   //WV
			// 	if (Lev[i]) {                                                    //WV
			// 	int n=Prn[i]-i,m=CarParLin;                                    //WV
			// 	ll=l;                                                          //WV
			// 	if (n>0) *l=218; else {n=-n; m=-m; *l=192;} // '┌' ou '└'      //WV
			// 	for (int k=1; k<n; ++k) {ll+=m; *ll=179;} // '│'               //WV
			// 	}                                                                //WV
			// 	*++l=196; *++l=196; *++l=196; *++l='>'; *++l=0; // "───>"        //WV
			// }                                                                  //WV
			// ln=lin;                                                            //WV
			// for (int i=0; i<nbE; ++i,ln+=CarParLin) {                          //WV
			// 	SetConsoleTextAttribute(console,Fnd); printf("%s",ln);           //WV
			// 	if (Arr[i]->color==RED) {                                        //WV
			// 	SetConsoleTextAttribute(console,Red);                          //WV
			// 	printf(" %i n",Arr[i]->data);                                 //WV
			// 	} else {                                                         //WV
			// 	SetConsoleTextAttribute(console,Black);                        //WV
			// 	printf(" *%i n",Arr[i]->data);                                //WV
			// 	}                                                                //WV
			// }                                                                  //WV
			// SetConsoleTextAttribute(console,Fnd);                              //WV
			// }  
	};	
}

#endif