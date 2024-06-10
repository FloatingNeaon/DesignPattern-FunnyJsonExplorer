#ifndef STYLE_FACTORY_H
#define STYLE_FACTORY_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "IconFamily.h"

using json = nlohmann::json;

class StyleFactory{
public:
    virtual ~StyleFactory() = default;
    virtual void print(const json& j,  IconFamily& iconFamily, const std::string& prefix = "") const = 0;
};

#endif