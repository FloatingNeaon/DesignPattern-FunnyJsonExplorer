#ifndef TREE_STYLE_FACTORY_H
#define TREE_STYLE_FACTORY_H

#include "StyleFactory.h"

class TreeStyleFactory : public StyleFactory{
public:
    void print(const json& j, IconFamily& iconFamily, const std::string& prefix = "") const override;
};

#endif