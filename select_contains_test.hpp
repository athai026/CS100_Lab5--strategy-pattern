#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"
#include "selectContains.hpp"
#include "spreadsheet.hpp"
#include "spreadsheet.cpp"


TEST(SelectContains, First_Angel) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "First", "Angel"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \n");
}


#endif //__SELECT_CONTAINS_TEST_HPP__
