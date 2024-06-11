#ifndef TREE_FACTORY_H
#define TREE_FACTORY_H

#include "AbstractFactory.h"
#include "TreeStyle.h"

class TreeFactory : public AbstractFactory {
public:
    std::unique_ptr<Style> createStyle() const override {
        return std::make_unique<TreeStyle>();
    }
    
    std::unique_ptr<IconFamily> createIconFamily(const json& iconJson, const std::string& icon_family) const override {
        return std::make_unique<IconFamily>(iconJson, icon_family);
    }
};

#endif
