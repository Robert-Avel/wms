#include "base_converter.hpp"
#include "command.hpp"
#include "item/item.hpp"
#include "interface.hpp"
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <getopt.h>
#include <string>
#include <vector>



static std::vector<std::string> slipStr(std::string input, char delimiter) {
    std::vector<std::string> output;
    std::string buffer;
    bool in_quotes = false;
    for(auto& ch: input) {
        if(ch == delimiter && !in_quotes) {
            output.push_back(buffer);
            buffer.clear();
        }
        else {
            buffer.append(1, ch);
            if(ch == '"') {in_quotes = !in_quotes;}
        }
    }
    output.push_back(buffer);
    return output;
}


static WMRobert syst("SSS.db");

/*
inline void groupContext(int& argc, char**& argv)
{
    //group new <name>
    if(strcmp(argv[2], CNEW) == 0 && argc == 4) {
        uint64_t r = syst.group_module.newGroup(argv[3]);
        if(r == 0) {std::cout << "A group was already created with this name (" << argv[3] << ")\n";}
        else {
            std::cout << "A new group was created with ID " << r << "\n";
            syst.data_module.saveGroupMap(r, argv[3]);
        }
    }

    //group list
    else if(strcmp(argv[2], CLIST) == 0 && argc == 3) {
        GroupPrefixMap& r = syst.group_module.getGroups();
        if(r.empty()) {std::cout << "No groups\n";}
        else {
            for(auto& it: r)
            {
                std::cout << it.second << " | " << it.first << "\n";
            }
        }
    }
}

 */

inline void itemContext(size_t argc, std::vector<std::string>& argv)
{
    //item new <group> <name> <weight> <cubic> <value>
    if(argv[1] == CNEW && argc == 7) {
        uint64_t r = syst.item_module.creteItem(
            atol(argv[2].c_str()),
            argv[3],
            std::atoi(argv[4].c_str()),
            std::atoi(argv[5].c_str()),
            std::atoi(argv[6].c_str())
        );
        std::cout << "A new item was created with ID " << r << "\n";
    }

    //item info <group> <id>
    else if(argv[1] == CINFO && argc == 4) {
        const auto* r = syst.item_module.getItem(
            std::atol(argv[2].c_str()),
            std::atol(argv[3].c_str())
        );
        if(r == nullptr) {std::cout << "No item found\n";}
        else {std::cout << r->cgetObj().formatData();}
    }

    //item list <group> <page>
    else if(argv[1] == CLIST && argc == 4) {
        auto r = syst.item_module.list(atol(argv[2].c_str()), atoi(argv[3].c_str()));
        if(r.empty()) {std::cout << "No Itens Found\n"; return;}
        for(auto& it: r) {
            std::cout << it->getID() << " | " << it->cgetObj().getGlobalName() << "\n";
        }

    }

    //item search <name>

}


int main() {
    std::cout << "RobertWMS\nVersion 0.0.1\nAll Copyright reserved\n";

    while (true) {
        std::cout << "(robert-wms) ";
        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> argv_ = slipStr(input, ' ');

        if(argv_[0] == "quit") {break;}
        if(argv_[0] == ITEM) {itemContext(argv_.size(), argv_);}
    }

    //if(strcmp(argv[1], GROUP) == 0) {groupContext(argc, argv);}


    //volume new <item_id>
    //volume get <id>
    //volume search batch <batch>
    //volume search item <item_id>
    //volume list <page>

    //batch list <page>
    //batch new <item_id>...

    //cargo new volume <volume_id>...
    //cargo new batch <batch_id>...
    //cargo list <page>


    //warehouse new <name> <cubic>
    //warehouse list <page>


    //./wms item get <id> -> item

    //syst.save(ITEM_D);
}
