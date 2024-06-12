/**
 * @file IconFamilyBuilder.h
 * @author CaoYonghao
 * @brief 采用建造者模式，构建IconFamily对象
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ICON_FAMILY_BUILDER_H
#define ICON_FAMILY_BUILDER_H

#include "IconFamily.h"

class IconFamilyBuilder {
public:
    IconFamilyBuilder() : iconJson(), iconStyle("") {}
    
    IconFamilyBuilder& withIconJson(const json& iconJson) {
        this->iconJson = iconJson;
        return *this;
    }
    
    IconFamilyBuilder& withIconStyle(const std::string& iconStyle) {
        this->iconStyle = iconStyle;
        return *this;
    }
    
    std::unique_ptr<IconFamily> build() const {
        return std::make_unique<IconFamily>(iconJson, iconStyle);
    }
    
private:
    json iconJson;
    std::string iconStyle;
};

#endif
