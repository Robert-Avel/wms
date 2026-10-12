#include "item/Item.hpp"
#include "WMRobert.hpp"
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <getopt.h>
#include <string>
#include <vector>


#define ITEM "item"
#define VOLUME "volume"
#define BATCH "batch"
#define CARGO "cargo"
#define WAREHOUSE "warehouse"
#define GROUP "group"
#define CONFIG "config"

#define CNEW "new"
#define CINFO "info"
#define CLIST "list"
#define CSEARCH "search"


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
            if(ch != '"') {
                buffer.append(1, ch);
            }
            if(ch == '"') {in_quotes = !in_quotes;}
        }
    }
    output.push_back(buffer);
    return output;
}


static WMRobert syst("SSS.db");


inline void groupContext(size_t argc, std::vector<std::string>& argv)
{
    //group new <name>
    if(argv[1] == CNEW && argc == 3) {
        uint64_t r = syst.group_module.newGroup(argv[2]);
        if(r == 0) {std::cout << "A group was already created with this name (" << argv[3] << ")\n";}
        else {
            std::cout << "A new group was created with ID " << r << "\n";
        }
    }

    //group list
    else if(argv[1] == CLIST && argc == 2) {
        auto& r = syst.group_module.getMap();
        if(r.empty()) {std::cout << "No groups\n";}
        else {
            for(auto& it: r)
            {
                std::cout << it.second << " | " << it.first << "\n";
            }
        }
    }
}



inline void itemContext(size_t argc, std::vector<std::string>& argv)
{
    //item new <group> <name> <weight> <cubic> <value>
    if(argv[1] == CNEW && argc == 7) {
        uint64_t r = syst.item_module.creteItem(
            argv[2],
            argv[3],
            std::atoi(argv[4].c_str()),
            std::atoi(argv[5].c_str()),
            std::atoi(argv[6].c_str())
        );
        if(r != 0) {
            std::cout << "A new item was created with ID " << r << "\n";
        } else std::cout << "Invalid Group or something went wrong!\n";
    }

    //item info <group> <id>
    else if(argv[1] == CINFO && argc == 4) {
        const auto* r = syst.item_module.getItem(
            argv[2],
            std::atol(argv[3].c_str())
        );
        if(r == nullptr) {std::cout << "No item found\n";}
        else {std::cout << r->cgetObj().formatData();}
    }

    //item list <group> <page>
    else if(argv[1] == CLIST && argc == 4) {
        auto r = syst.item_module.list(argv[2], atoi(argv[3].c_str()));
        if(r.empty()) {std::cout << "No Itens Found\n"; return;}
        for(auto& it: r) {
            std::cout << it->getID() << " | " << it->cgetObj().getGlobalName() << "\n";
        }

    }

}

inline void volumeContext(size_t argc, std::vector<std::string>& argv) {
    //volume new <group> <item_id>
    if(argv[1] == CNEW && argc == 4) {
        auto r = syst.volume_module.createVolume(
            std::atol(argv[2].c_str()),
            std::atol(argv[3].c_str())
        );
        if(r != 0) {
            std::cout << "A new volume was created with ID " << r << "\n";
        } else std::cout << "Invalid Group or something went wrong!\n";
    }

    //volume info <group> <id>
    if(argv[1] == CINFO && argc == 4) {
        auto* r = syst.volume_module.getVolume(
            std::atol(argv[2].c_str()),
            std::atol(argv[3].c_str())
        );
        if(r == nullptr) {std::cout << "No Volume found\n";}
        else {std::cout << r->cgetObj().formatData();}
    }

    //volume list <group> <page>
    if(argv[1] == CLIST && argc == 4) {
        auto r = syst.volume_module.list(
            std::atol(argv[2].c_str()),
            std::atol(argv[3].c_str())
        );
        if(r.empty()) {std::cout << "No Volume Found\n";}
        for(auto& it: r) {
            std::cout << it->getID() << " | " << it->cgetObj().getBatchID() << "\n";
        }
    }
}



int main() {
    std::cout << "RobertWMS\nVersion 0.0.2\nAll Copyright reserved\n";

    while (true) {
        std::cout << "(robert-wms) ";
        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> argv_ = slipStr(input, ' ');

        if(argv_[0] == "quit") {break;}
        if(argv_[0] == ITEM) {itemContext(argv_.size(), argv_);}
        if(argv_[0] == GROUP) {groupContext(argv_.size(), argv_);}
        if(argv_[0] == VOLUME) {volumeContext(argv_.size(), argv_);}
    }


    //item search <name>

    //volume search batch <batch>
    //volume search item <item_id>

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
