#ifndef ICON_FAMILY_H
#define ICON_FAMILY_H

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class IconFamily{
public:
    IconFamily(){}
    IconFamily(json IconJson, std::string iconStyle);
    std::string get_containerIcon();
    std::string get_leafIcon();
    void set_containerIcon(std::string cIon);
    void set_leafIcon(std::string lIcon);
private:
    std::string containerIcon, leafIcon;
    
};

#endif