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
