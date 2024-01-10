#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient
{
public:
    double get_price_unit(){return price_unit;};
    size_t get_units(){return units;};
    virtual std::string get_name() = 0;
    //虚函数：希望子类重写
    //pure虚函数：必须在子类中进行重写，且此class为抽象类，只能作为基类使用

    double price(){return price_unit*units;};
    

protected:
    //可以在类的内部和派生类中访问，但对于类的外部是不可见的。这意味着受保护成员对于类的外部代码是不可直接访问的。
    Ingredient(double price_unit, size_t units):price_unit(price_unit),units(units){};

    double price_unit;
    size_t units;
    std::string name; //Espresso, Milk, Chocolate, or ...
};

#endif // INGREDIENT_H