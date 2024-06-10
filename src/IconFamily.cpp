#include "IconFamily.h"

IconFamily::IconFamily(json IconJson, std::string iconStyle){
    try
    {
        containerIcon = IconJson.at(iconStyle).at("Container").get<std::string>();
        leafIcon = IconJson.at(iconStyle).at("Leaf").get<std::string>();
    }
    catch(json::out_of_range& e)
    {
        throw std::runtime_error("Invalid style or missing icons in the config");
    }
    
}

std::string IconFamily::get_containerIcon(){
    return containerIcon;
}

std::string IconFamily::get_leafIcon(){
    return leafIcon;
}

void IconFamily::set_containerIcon(std::string cIon){
    containerIcon = cIon;
}

void IconFamily::set_leafIcon(std::string lIcon){
    leafIcon = leafIcon;
}