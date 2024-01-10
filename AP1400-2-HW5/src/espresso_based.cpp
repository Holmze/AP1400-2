#include "espresso_based.h"

EspressoBased::EspressoBased():ingredients(), name(""){

}
EspressoBased::EspressoBased(const EspressoBased& esp):ingredients(esp.ingredients), name(esp.name){

}
// EspressoBased& EspressoBased::operator=(const EspressoBased& esp){
void EspressoBased::operator=(const EspressoBased& esp){
    // if(this != &esp){
    //     ingredients = esp.ingredients;
    //     name = esp.name;
    // }
    // return *this;
    this->name = esp.name;
    this->ingredients = esp.ingredients;
}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

void showProgressBar(int progress, int total) {
    constexpr int barWidth = 70;

    float percent = static_cast<float>(progress) / total;
    int filledWidth = static_cast<int>(barWidth * percent);

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < filledWidth) {
            std::cout << "=";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << static_cast<int>(percent * 100.0) << "%\r";
    std::cout.flush();
}

void EspressoBased::brew(){
    constexpr int total = 100;

    for (int i = 0; i <= total; ++i) {
        showProgressBar(i, total);
        usleep(50000);
    }

    std::cout << std::endl;
}

std::vector<Ingredient*>& EspressoBased::get_ingredients(){
    return this->ingredients;
}