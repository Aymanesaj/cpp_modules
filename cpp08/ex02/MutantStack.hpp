#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iterator>
#include <cstdlib>
#include <ctime>

template <typename T, typename type = std::deque<T> >
class MutantStack : public std::stack<T, type>
{
private:
public:
	MutantStack(){}
	~MutantStack(){}
	typedef typename type::iterator iterator;
	iterator	begin(){
		return (this->c.begin());
	}
	iterator	end(){
		return (this->c.end());
	}
};


#endif