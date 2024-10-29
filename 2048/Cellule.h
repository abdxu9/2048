#pragma once
#ifndef _CELLULE_HPP_
#define _CELLULE_HPP_
#include<iostream>
using namespace std;

class Cellule
{
private:
	int m_val;
public:
	Cellule();
	Cellule(int val);
	int getVal();
	void setVal(int val);
	bool empty() const;
	Cellule& merge(Cellule& other);
	Cellule& operator=(const Cellule& other);
	friend ostream& operator<<(ostream& o, const Cellule& c);
};

#endif // !_CELLULE_HPP_
