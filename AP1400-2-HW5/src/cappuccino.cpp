#include "cappuccino.h"

// Cappuccino::Cappuccino(){
    
// }
// Cappuccino::Cappuccino(const Cappuccino& cap):ingredients(cap.ingredients), name(cap.name), side_items(cap.side_items){

// }

Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

Cappuccino::Cappuccino(const Cappuccino& cap) : EspressoBased(cap) {
    for (auto x : cap.side_items) {
        Cinnamon* ptr_1 = dynamic_cast<Cinnamon*>(x);
        Chocolate* ptr_2 = dynamic_cast<Chocolate*>(x);
        Sugar* ptr_3 = dynamic_cast<Sugar*>(x);
        Cookie* ptr_4 = dynamic_cast<Cookie*>(x);
        Espresso* ptr_5 = dynamic_cast<Espresso*>(x);
        Milk* ptr_6 = dynamic_cast<Milk*>(x);
        MilkFoam* ptr_7 = dynamic_cast<MilkFoam*>(x);
        Water* ptr_8 = dynamic_cast<Water*>(x);

        if (ptr_1 != nullptr) {
            Cinnamon* y = new Cinnamon(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_2 != nullptr) {
            Chocolate* y = new Chocolate(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_3 != nullptr) {
            Sugar* y = new Sugar(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_4 != nullptr) {
            Cookie* y = new Cookie(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_5 != nullptr) {
            Espresso* y = new Espresso(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_6 != nullptr) {
            Milk* y = new Milk(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_7 != nullptr) {
            MilkFoam* y = new MilkFoam(x->get_units());
            (this->side_items).push_back(y);
        } else if (ptr_8 != nullptr) {
            Water* y = new Water(x->get_units());
            (this->side_items).push_back(y);
        }
    }
}

// Cappuccino& Cappuccino::operator=(const Cappuccino& cap){
void Cappuccino::operator=(const Cappuccino& cap){
    // this->side_items = cap.side_items;
    // return *this;
    if (this != &cap) {
        this->name = cap.name;
        for (auto& i : this->side_items) {
            delete i;
        }
        (this->side_items).clear();
        for (auto x : cap.side_items) {
            Cinnamon* ptr_1 = dynamic_cast<Cinnamon*>(x);
            Chocolate* ptr_2 = dynamic_cast<Chocolate*>(x);
            Sugar* ptr_3 = dynamic_cast<Sugar*>(x);
            Cookie* ptr_4 = dynamic_cast<Cookie*>(x);
            Espresso* ptr_5 = dynamic_cast<Espresso*>(x);
            Milk* ptr_6 = dynamic_cast<Milk*>(x);
            MilkFoam* ptr_7 = dynamic_cast<MilkFoam*>(x);
            Water* ptr_8 = dynamic_cast<Water*>(x);

            if (ptr_1 != nullptr) {
                Cinnamon* y = new Cinnamon(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_2 != nullptr) {
                Chocolate* y = new Chocolate(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_3 != nullptr) {
                Sugar* y = new Sugar(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_4 != nullptr) {
                Cookie* y = new Cookie(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_5 != nullptr) {
                Espresso* y = new Espresso(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_6 != nullptr) {
                Milk* y = new Milk(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_7 != nullptr) {
                MilkFoam* y = new MilkFoam(x->get_units());
                (this->side_items).push_back(y);
            } else if (ptr_8 != nullptr) {
                Water* y = new Water(x->get_units());
                (this->side_items).push_back(y);
            }
        }
    }
}

std::string Cappuccino::get_name(){
    return this->name;
}

double Cappuccino::price(){
    double price_count = 0;
    for(auto igd : this->get_ingredients()){
        price_count += igd->price();
        // cout << price_count<< endl;
    }
    for(auto side_igd : this->get_side_items()){
        price_count += side_igd->price();
        // cout << price_count<< endl;
    }
    return price_count;
}

std::vector<Ingredient*>& Cappuccino::get_side_items(){
    return this->side_items;
}
void Cappuccino::add_side_item(Ingredient* side){
    this->get_side_items().push_back(side);
}