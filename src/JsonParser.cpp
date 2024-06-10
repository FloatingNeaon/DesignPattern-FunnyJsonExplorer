#include "JsonParser.h"

void JsonParser::set_jsonFilePath(std::string path){
    jsonFilePath = path;
}

json JsonParser::parse(){
    std::ifstream json_file(jsonFilePath);

    if (!json_file.is_open()) {
        std::cerr << "Failed to open the target file." << std::endl;
        return 1;
    }

    json JsonObj;
    try {
        json_file >> JsonObj;
    } catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }

    json_file.close();

    return JsonObj;
}