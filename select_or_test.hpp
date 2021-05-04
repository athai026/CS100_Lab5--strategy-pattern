fndef __SELECT_OR_TEST_HPP__
#define __SELECT_OR_TEST_HPP__

#include "gtest/gtest.h"
#include "selectContains.hpp"
#include "selectOr.hpp"
#include "spreadsheet.hpp"
#include "spreadsheet.cpp"

TEST(SelectOr, First_Angel_Amy) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});

    std::ostringstream out;
    test_sheet.set_selection(new Select_Or(new Select_Contains(&test_sheet, "First", "Angel"), new Select_Contains(&test_sheet, "First", "Amy")));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nAmy Adams 19 English");
}

TEST(SelectOr, Last_Cornell_Dang) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});

    std::ostringstream out;
    test_sheet.set_selection(new Select_Or(new Select_Contains(&test_sheet, "Last", "Cornell"), new Select_Contains(&test_sheet, "Last", "Dang")));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Charles Cornell 21 Music \nLauren Dang 20 Film");
}

TEST(SelectOr, Age_1_2) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "18", "English"});

    std::ostringstream out;
    test_sheet.set_selection(new Select_Or(new Select_Contains(&test_sheet, "Age", "1"), new Select_Contains(&test_sheet, "Age", "2")));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nCharles Cornell 21 Music \nLauren Dang 20 Film \nAmy Adams 18 English");
}

TEST(SelectOr, Major_E_u) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});

    std::ostringstream out;
    test_sheet.set_selection(new Select_Or(new Select_Contains(&test_sheet, "Major", "E"), new Select_Contains(&test_sheet, "Major", "u")));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nAmy Adams 19 English \n");
}

TEST(SelectOr, Major_E_z) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "19", "English"});

    std::ostringstream out;
    test_sheet.set_selection(new Select_Or(new Select_Contains(&test_sheet, "Major", "E"), new Select_Contains(&test_sheet, "Major", "z")));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Angel Adams 19 English \nAmy Adams 19 English \n");
}

TEST(SelectOr, First___y) {
    Spreadsheet test_sheet;
    test_sheet.set_column_names({"First", "Last", "Age", "Major"});
    test_sheet.add_row({"Angel", "Adams", "19", "English"});
    test_sheet.add_row({"Charles", "Cornell", "21", "Music"});
    test_sheet.add_row({"Lauren", "Dang", "20", "Film"});
    test_sheet.add_row({"Amy", "Adams", "18", "English"});

    std::ostringstream out;
    test_sheet.set_selection(new Select_Or(new Select_Contains(&test_sheet, "First", ""), new Select_Contains(&test_sheet, "First", "y")));
    test_sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Amy Adams 18 English \n");
}

#endif //__SELECT_OR_TEST_HPP__

