#include "TreeStyle.h"

void TreeStyle::print(const json& j, IconFamily& iconFamily, const std::string& prefix) const {
    for (auto it = j.begin(); it != j.end(); ++it) {
        bool is_last = (std::next(it) == j.end());

        std::cout << prefix;
        if (is_last) {
            std::cout << "└─";
        } else {
            std::cout << "├─";

        }

        //中间节点
        if (it->is_structured()) {
            std::cout << iconFamily.get_containerIcon();
            std::cout << it.key();
            std::cout << std::endl;
            print(*it, iconFamily, prefix + (is_last ? "   " : "|  "));
        } 
        //叶节点
        else {
            std::cout << iconFamily.get_leafIcon();
            std::cout << it.key();
            if (it->is_null()) {
                std::cout << std::endl;
            } else {
                std::cout << ": " << *it << std::endl;
            }
        }
    }
}