#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <memory>
#include "Style.h"
#include "IconFamily.h"

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<Style> createStyle() const = 0;
    virtual std::unique_ptr<IconFamily> createIconFamily(const json& iconJson, const std::string& iconStyle) const = 0;
};

#endif