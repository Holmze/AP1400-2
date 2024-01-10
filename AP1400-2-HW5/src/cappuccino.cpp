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
// Cappuccino& Cappuccino::operator=(const Cappuccino& cap){
void Cappuccino::operator=(const Cappuccino& cap){
    // this->side_items = cap.side_items;
    // return *this;
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