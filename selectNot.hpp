#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"
#include <cstring>

class Select_Not : public Select
{
protected:
Select* select;
public:
     Select_Not(Select* _select)
     {
          delete select;

          select = _select;
     }

     virtual bool select() const
     {
          return !select.select();
     }
};

#endif //__SELECT_NOT_HPP__
