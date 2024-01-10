#include "mocha.h"


// Mocha::Mocha(){
    
// }
// Mocha::Mocha(const Mocha& cap):ingredients(cap.ingredients), name(cap.name), side_items(cap.side_items){

// }

Mocha::~Mocha()
{
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

// Mocha& Mocha::operator=(const Mocha& cap){
void Mocha::operator=(const Mocha& cap){
    // this->side_items = cap.side_items;
    // return *this;
    
}

std::string Mocha::get_name(){
    return this->name;
}

double Mocha::price(){
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

std::vector<Ingredient*>& Mocha::get_side_items(){
    return this->side_items;
}

void Mocha::add_side_item(Ingredient* side){
    this->get_side_items().push_back(side);
}