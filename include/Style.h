/**
 * @file Style.h
 * @author CaoYonghao
 * @brief 定义接口，具体样式类需要实现这个接口，用于打印特定格式的JSON数据
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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