#include "Cellule.h"

Cellule::Cellule(): m_val(0) {}

Cellule::Cellule(int val) : m_val(val) {}

int Cellule::getVal(){
	return m_val;
}

void Cellule::setVal(int val) {
	this->m_val = val;
}

bool Cellule::empty() const{
	return (m_val == 0);
}

Cellule& Cellule::merge(Cellule& other) {
	this->m_val = other.m_val + this->m_val;
	other.m_val = 0;
	return *this;
}
Cellule& Cellule::operator=(const Cellule& other) {
	this->m_val = other.m_val;
	return *this;
}

ostream& operator<<(ostream& o, const Cellule& c) {
	o << "val : " << c.m_val;
	return o;
}