/**
 * @file IconFamily.h
 * @author CaoYonghao
 * @brief 管理图标相关信息，包括中间节点图标和叶子节点图标
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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