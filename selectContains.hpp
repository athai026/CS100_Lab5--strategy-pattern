#ifndef __SELECTCONTAINS_HPP__
#define __SELECTCONTAINS_HPP__

#include "select.hpp"

class Select_Contains : public Select {
    protected:
        std::string match;
        Spreadsheet* spread;
        int column_num;
    public:
        Select_Contains(Spreadsheet &sheet, const std::string column_name, const std::string s) {
            match = s;
            *spread = sheet;
            column_num = spread->get_column_by_name(column_name);
        }

        virtual bool select(const Spreadsheet* spread, int row) const {
            std::string cell = spread->cell_data(row, column_num);
            int found = cell.find(match);
            if (found != std::string::npos) {
                return true;
            }
            return false;
        }
};

#endif //__SELECTCONTAINS_HPP__
