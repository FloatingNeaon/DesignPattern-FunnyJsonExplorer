/**
 * @file JsonParser.h
 * @author CaoYonghao
 * @brief 解析JSON文件，返回JSON对象
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JsonParser{
public:
    std::string jsonFilePath;

    JsonParser(){jsonFilePath = "";}
    JsonParser(std::string path):jsonFilePath(path){}
    void set_jsonFilePath(std::string path);
    json parse();
};

#endif