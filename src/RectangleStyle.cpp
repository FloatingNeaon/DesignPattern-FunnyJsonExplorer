#include "RectangleStyle.h"

void RectangleStyle::print(const json& j, IconFamily& iconFamily, const std::string& prefix) const {

    size_t line_length = 0;
    for (auto it = j.begin(); it != j.end(); ++it) {
        std::string key = it.key();
        line_length = std::max(line_length, key.length() + prefix.length() + 50); // Adjust 50 as needed for icons and padding
    }
    
    std::cout << "┌─" << prefix;
    for (int i=0;i<line_length;i++){
        std::cout<< "─";
    }
    std::cout <<"——┐" << std::endl;

    printBox(j, iconFamily, "|  ", line_length, true);
    
    std::cout << "|__" << generatePadding(0, line_length) << "_|" << std::endl;
    
    
}

void RectangleStyle::printBox(const json& j, IconFamily& iconFamily, const std::string& prefix, size_t line_length, bool is_top) const{
    
    for (auto it = j.begin(); it != j.end(); ++it) {
        bool is_last = (std::next(it) == j.end());
        std::string key = it.key();
        size_t current_length = prefix.length() + key.length() + 3; // Adjust 3 as needed for icons and spacing

        std::cout << prefix;
        if (is_top && it == j.begin()) {
            std::cout << "┌─ ";
        } 
        else {
            std::cout << "├─ ";
        }

        if (it->is_structured()) {
            std::cout << iconFamily.get_containerIcon() << " " << key << " ";
            std::cout << generatePadding(current_length + iconFamily.get_containerIcon().length(), line_length) << "__|" << std::endl;
            printBox(*it, iconFamily, prefix + "|  ", line_length, false);
        } else {
            std::cout << iconFamily.get_leafIcon() << " " << key;
            if (!it->is_null()) {
                std::cout << ": " << *it;
                current_length += it->dump().length() + 2;
            }
            std::cout << " " << generatePadding(current_length + iconFamily.get_leafIcon().length(), line_length) << "__|" << std::endl;
        }
    }
}

std::string RectangleStyle::generatePadding(size_t current_length, size_t total_length) const{
    if (current_length>=total_length){
        return "";
    }
    return std::string(total_length - current_length, '_');
}