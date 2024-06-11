#ifndef STYLE_H
#define STYLE_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "IconFamily.h"

using json = nlohmann::json;

class Style{
public:
    virtual ~Style() = default;
    virtual void print(const json& j,  IconFamily& iconFamily, const std::string& prefix = "") const = 0;
};

#endif