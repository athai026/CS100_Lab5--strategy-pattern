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

        select1 = _select;
     }

    ~Select_Not() 
    {
            delete select1;
    }

     virtual bool select(const Spreadsheet* sheet, int row) const
     {
          return !(select1->select(sheet, row));
     }
};

#endif //__SELECT_NOT_HPP__
