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

        Mocha mocha{};
        cout << mocha.get_name() << endl;
        // EXPECT_EQ(mocha.get_name(), "Mocha");
        auto ingredients = mocha.get_ingredients();
        cout << ingredients.size() <<endl;
        // EXPECT_EQ(ingredients.size(), 4);
        for(const auto& i : ingredients)
            cout << i->get_name() <<endl;
            // EXPECT_TRUE(i->get_name() == "Espresso" || i->get_name() == "Milk" || i->get_name() == "MilkFoam" || i->get_name() == "Chocolate");
        cout << mocha.price() <<endl;
        // EXPECT_DOUBLE_EQ(mocha.price(), 60);

        EspressoBased* esp{new Mocha{}};
        reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Cookie{1});
        reinterpret_cast<Cappuccino*>(esp)->add_side_item(new Sugar{2});
        std::vector<Ingredient*>& sides = reinterpret_cast<Cappuccino*>(esp)->get_side_items();
        cout << sides.size() <<endl;
        // EXPECT_EQ(sides.size(), 2);
        delete esp;
        cout << sides.size() <<endl;
        // EXPECT_EQ(sides.size(), 0);
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