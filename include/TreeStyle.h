/**
 * @file TreeStyle.h
 * @author CaoYonghao
 * @brief 实现Style接口，提供具体的树形打印方式
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef TREE_STYLE_H
#define TREE_STYLE_H

#include "Style.h"

class TreeStyle : public Style{
public:
    void print(const json& j, IconFamily& iconFamily, const std::string& prefix = "") const override;
};

#endif