/**
 * @file RectangleStyle.h
 * @author CaoYonghao
 * @brief 实现Style接口，提供具体的矩形打印方式
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef RECT_STYLE_H
#define RECT_STYLE_H

#include "Style.h"

class RectangleStyle : public Style{
public:
    void print(const json& j, IconFamily& iconFamily, const std::string& prefix = "") const override;
    void printBox(const json& j, IconFamily& iconFamily, const std::string& prefix, size_t line_length, bool is_top) const;
    std::string generatePadding(size_t current_length, size_t total_length) const;
};

#endif