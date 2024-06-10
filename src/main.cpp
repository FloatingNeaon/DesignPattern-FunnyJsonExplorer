#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "JsonParser.h"
#include "IconFamily.h"
#include "StyleFactory.h"
#include "TreeStyleFactory.h"
#include "RectangleStyleFactory.h"

using json = nlohmann::json;

int optind = 1;
char *optarg = nullptr;

int getopt(int argc, char *const argv[], const char *optstring) {
    if (optind >= argc || argv[optind][0] != '-' || argv[optind][1] == '\0') {
        return -1;
    }
    
    char opt = argv[optind][1];
    const char *p = strchr(optstring, opt);
    if (p == nullptr) {
        return '?';
    }
    
    if (p[1] == ':') {
        if (optind + 1 >= argc) {
            return '?';
        }
        optarg = argv[++optind];
    }
    ++optind;
    return opt;
}

std::unique_ptr<StyleFactory> createStyleFactory(const std::string& style) {
    if (style == "tree") {
        return std::make_unique<TreeStyleFactory>();
    } 
    else if (style == "rectangle") {
        return std::make_unique<RectangleStyleFactory>();
    }
    else {
        throw std::invalid_argument("Unknown style: " + style);
    }
}

int main(int argc, char *argv[]){

    if (argc != 7) {
        std::cerr << "Usage: "<< argv[0] <<"-f <json file> -s <style> -i <icon family>" << std::endl;
        return 1;
    }
    std::string iconConfigPath = "../icons/icon_config.json";
    std::string jsonFilePath, style, iconFamily;

    //命令行参数解析
    int opt;
    while ((opt = getopt(argc, argv, "f:s:i:")) != -1) {
        switch (opt) {
            case 'f':
                jsonFilePath = optarg;
                break;
            case 's':
                style = optarg;
                break;
            case 'i':
                iconFamily = optarg;
                break;
            default: /* '?' */
                std::cerr << "Usage: " << argv[0] << " -f <json file> -s <style> -i <icon family>\n";
                return 1;
        }
    }

    JsonParser jsonParser;
    jsonParser.set_jsonFilePath(jsonFilePath);
    json JsonObj = jsonParser.parse();
    jsonParser.set_jsonFilePath(iconConfigPath);
    json IconObj = jsonParser.parse();

    IconFamily iconFamilyObj(IconObj, iconFamily);

    std::unique_ptr<StyleFactory> styleFactory;
    try {
        styleFactory = createStyleFactory(style);
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    styleFactory->print(JsonObj, iconFamilyObj);

}