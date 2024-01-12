#ifndef CAPPUCCINO
#define CAPPUCCINO
#include <vector>
#include <string>
#include <iostream>
// #include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
using std::cout;
using std::endl;

class Cappuccino : public EspressoBased{
public:
    Cappuccino(){
        this->name = "Cappuccino";
        // size_t  units = 2;
        // Espresso espressoObj = Espresso{units};
        this->get_ingredients().push_back(new Espresso{2});
        this->get_ingredients().push_back(new Milk{2});
        this->get_ingredients().push_back(new MilkFoam{1});
        this->side_items = std::vector<Ingredient*>{};
    };
    Cappuccino(const Cappuccino& cap);
    // Cappuccino(const Cappuccino& cap):side_items(cap.side_items){};

	~Cappuccino();
    void operator=(const Cappuccino& cap);
    // Cappuccino& operator=(const Cappuccino& cap);

    virtual std::string get_name();
    virtual double price();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();

private:
    std::vector<Ingredient*> side_items;

};

#endif // CAPPUCCINO