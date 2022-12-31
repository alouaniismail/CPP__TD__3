#include<cstdlib>
#include <iostream>

#include "SmartPointer.hpp"

//#define DEBUG

#ifdef DEBUG
#define TRACE(s) std::cerr << s
#else
#define TRACE(s) 
#endif

//#undef DEBUG
#ifdef DEBUG
#define R_TRACE(s) std::cerr << s
#else
#define R_TRACE(s) 
#endif



namespace enseirb {
  void SmartPointer::releasePointer() {
    *_counter = *_counter-1;
    R_TRACE(':' << __func__ << ':' << _data << '(' << *_counter << ')');
    if (*_counter == 0)
      {
	R_TRACE(":DELETE"); 
	delete _counter;
	delete[] _data;
      }
    _counter = NULL;
    R_TRACE(std::endl);
  }
  
  SmartPointer::SmartPointer(char *data): _data(data), _counter(new int(1)) {
    TRACE(__func__ << "(char*) " << _data << std::endl);
  }
  
  SmartPointer::SmartPointer(const SmartPointer &p) : 
    _data(p._data), _counter(p._counter) {
    *_counter = *_counter + 1;
    TRACE("SmartPointer recopie " << _data 
	  << '(' << *_counter << ")\n");
  }
  
  SmartPointer::~SmartPointer() {releasePointer();}

  char *SmartPointer::operator->() {return _data;}
  
  const char *SmartPointer::operator->() const {return _data;}

  char &SmartPointer::operator*() {return *_data;}
  const char &SmartPointer::operator*() const {return *_data;}
 
  const SmartPointer &SmartPointer::operator=(const SmartPointer &p) {
    TRACE(__func__ << ':' << p._data);
    //std::cerr << __func__ << ':' << p._data;     
    if ((this==&p)||(this->_data==p._data)) return *this;
    releasePointer();
    _counter = p._counter;
    *_counter = *_counter + 1;
    _data = p._data;
    TRACE("\t" << __func__ << '(' << *_counter << ")\n"); 
    return *this;
  }
  
  SmartPointer::operator char *(){
    TRACE(':' << __func__ << ':' << _data << std::endl);
    return _data;}

  SmartPointer::operator const char *() const {
    TRACE(':' << __func__ << ':' << _data << std::endl);
    return _data;}

  char * SmartPointer::get() { return _data;}
  const char * SmartPointer::get() const { return _data;}
}
