#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__
#include "select.hpp"
#include <cstring>

class Select_And : public Select
{
protected:
Select* select1;
Select* select2;
public:
    Select_And(Select* _select1, Select* _select2)
    {
   
         select1 = _select1;
         select2 = _select2;
    }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
         if(select1->select(sheet, row) == select2->select(sheet, row)) {
            return select1->select(sheet, row);
        } else {return false;}
    }
};

#endif //__SELECT_AND_HPP__
