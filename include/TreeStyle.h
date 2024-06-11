#ifndef TREE_STYLE_H
#define TREE_STYLE_H

#include "Style.h"

class TreeStyle : public Style{
public:
    void print(const json& j, IconFamily& iconFamily, const std::string& prefix = "") const override;
};

#endif