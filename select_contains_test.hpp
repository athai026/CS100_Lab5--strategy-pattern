#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"
#include "selectContains.hpp"
#include "header.hpp"


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

TEST(SelectContains, First_A) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "First", "A"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nAmy Adams 19 English \n");
}

TEST(SelectContains, First_allnames) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "First", ""));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nCharles Cornell 21 Music \nLauren Dang 20 Film \nAmy Adams 19 English \n");
}

TEST(SelectContains, Last_o) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "Last", "o"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Charles Cornell 21 Music \n");
}

TEST(SelectContains, Age_19) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "Age", "19"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nAmy Adams 19 English \n");
}

TEST(SelectContains, Major_Film) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "Major", "Film"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Lauren Dang 20 Film \n");
}

TEST(SelectContains, First_z) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "First", "z"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "");
}

TEST(SelectContains, First_angel) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "First", "angel"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "");
}

TEST(SelectContains, First_ANGEL) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});
 
    std::ostringstream out;
    test_sheet.set_selection(new Select_Contains(&test_sheet, "First", "ANGEL"));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "");
}

#endif //__SELECT_CONTAINS_TEST_HPP__
