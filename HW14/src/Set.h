/*
 * Set.h
 *
 *  Created on: Nov 15, 2015
 *      Author: murph141
 */

#ifndef SET_H_
#define SET_H_

#include <climits>
#include <iostream>
#include <cmath>
using namespace std;

class Set
{

	public:
		Set(int);
		~Set();
		int getCopyCount();
		int * members;
		int copied;
		int size;
};

Set::Set(int x)
{
	int a = x / 32;

	members = new int[a + 1];
	size = a + 1;
	copied = 0;
}

Set operator+(Set X, int x)
{
	int a = x / 32;
	int b = x % 32;

	X.members[a] |= (1 << b);
	return(X);
}

Set operator-(Set X, int x)
{
	int a = x / 32;
	int b = x % 32;

	int c = (-1 << (b + 1));
	int d = pow(2, b) - 1;

	X.members[a] &= (c | d);
	return(X);
}

Set operator&(Set X, Set Y)
{
	Set Z = Set(0);

	for(int a = 0; a < 2048; a++)
	{
		Z.members[a] = X.members[a] & Y.members[a];
	}

	return(Z);
}

Set operator/(Set X, Set Y)
{
	Set Z = Set((X.size - 1) * 32);

	for(int a = 0; a < X.size; a++)
	{
		Z.members[a] = X.members[a] & ~Y.members[a];
	}

	return(Z);
}

Set operator~(Set X)
{
	for(int a = 0; a < 2048; a++)
	{
		X.members[a] ^= -1;
	}

	return(X);
}

int Set::getCopyCount()
{
	(*this).copied++;
	return((*this).copied - 1);
}

ostream& operator<<(ostream& os, const Set& X)
{
	for(int a = 0; a < X.size; a++)
	{
		for(int b = 0; b < 32; b++)
		{
			if(X.members[a] & (1 << b))
			{
				os << (b + 32 * a) << " ";
			}
		}
	}

	return(os);
}

Set::~Set(){}

#endif /* SET_H_ */
