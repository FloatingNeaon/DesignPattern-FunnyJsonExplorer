#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "AbstractFactory.h"
#include "RectangleStyle.h"

class RectangleFactory : public AbstractFactory {
public:
    std::unique_ptr<Style> createStyle() const override {
        return std::make_unique<RectangleStyle>();
    }
    
    std::unique_ptr<IconFamily> createIconFamily(const json& iconJson, const std::string& iconStyle) const override {
        return std::make_unique<IconFamily>(iconJson, iconStyle);
    }
};

#endif
