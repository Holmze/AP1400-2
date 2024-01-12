#ifndef MOCHA_H
#define MOCHA_H
#include <vector>
#include <string>
#include <iostream>
// #include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
using std::cout;
using std::endl;

class Mocha : public EspressoBased{
public:
    Mocha(){
        this->name = "Mocha";
        // size_t  units = 2;
        // Espresso espressoObj = Espresso{units};
        this->get_ingredients().push_back(new Espresso{2});
        this->get_ingredients().push_back(new Milk{2});
        this->get_ingredients().push_back(new MilkFoam{1});
        this->get_ingredients().push_back(new Chocolate{1});
        this->side_items = std::vector<Ingredient*>{};
    };
    Mocha(const Mocha& cap);
    // Mocha(const Mocha& cap):side_items(cap.side_items){};

	~Mocha();
    void operator=(const Mocha& cap);
    // Mocha& operator=(const Mocha& cap);

    virtual std::string get_name();
    virtual double price();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();

private:
    std::vector<Ingredient*> side_items;

};
#endif // MOCHA_H