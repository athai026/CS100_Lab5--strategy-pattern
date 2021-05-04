#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"
#include <cstring>

class Select_Not : public Select
{
protected:
Select* select1;
public:
     Select_Not(Select* _select)
     {
        delete select1;  

        select1 = _select;
     }

     virtual bool select() const
     {
          return !(select1->select());
     }
};

#endif //__SELECT_NOT_HPP__
