#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"
#include <cstring>

class Select_Or : public Select
{
protected:
     Select* select1;
     Select* select2;
public:
     Select_Or(Select* _select1, Select* _select2)
     {
          delete select1;
          delete select2;

          select1 = _select1;
          select2 = _select2;
     }

     virtual bool select(const Spreadsheet* sheet, int row) const
     {
          if(select1->select(sheet, row) == true || select2->select(sheet, row) == true)
          {
               return true;
          } else { return false;}
     }
};

#endif //__SELECT_OR_HPP__
