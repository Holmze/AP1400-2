#include <iostream>
#include <gtest/gtest.h>
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
#include "cappuccino.h"
#include "mocha.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        // debug section
        
        // cout << "1" <<endl;
        EspressoBased* esp{new Cappuccino{}};
        reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Cookie{1});
        std::vector<Ingredient*>& sides = reinterpret_cast<Cappuccino*>(esp)->get_side_items();
        cout << sides[0] <<endl;
        cout << sides.size() <<endl;
        delete esp;
        cout << sides[0] <<endl;
        cout << sides.size() <<endl;


        // Cappuccino cappuccino;
        // cappuccino.add_side_item(new Chocolate{2});
        // Cappuccino copy{cappuccino};
        // cout << copy.get_name() <<endl;
        // cout << copy.price()<<endl;
        // cout << cappuccino.get_side_items()[0] <<endl;
        // cout << copy.get_side_items()[0] <<endl;


        // cout << "2" <<endl;
        // Cappuccino cappuccino;
        // cappuccino.add_side_item(new Chocolate{2});
        // Cappuccino copy{cappuccino};
        // cout << "3" <<endl;
        // EspressoBased* esp{new Cappuccino{}};
        // reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Cookie{1});
        // std::vector<Ingredient*>& sides = reinterpret_cast<Cappuccino*>(esp)->get_side_items();
        // cout << sides.size() <<endl;
        // delete esp;
        // cout <<sides.size() <<endl;


        // EspressoBased* eb{};
        // eb->brew();

        // Cappuccino cap{};
        // cout << cap.get_name() <<endl;
        // cout << cap.price() <<endl;
        // Mocha moc{};
        // cout << moc.get_name() <<endl;
        // cout << moc.price() <<endl;
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}