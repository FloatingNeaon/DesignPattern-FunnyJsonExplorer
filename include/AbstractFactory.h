/**
 * @file AbstractFactory.h
 * @author CaoYonghao
 * @brief 提供接口，用于创建与特定样式相关的对象
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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