#include "base_converter.hpp"
#include "command.hpp"
#include "include/interface.hpp"
#include "item.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <utility>

static ItemSys syst("WMR.bin", basec::NUMERIC);


int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "RobertWMS\n Version 0.0.1\n All Copyright reserved\n";
        return 0;
    }

    syst.load();

    #ifdef DEBUG
    for(int i = 0; i < argc; i++) {std::cout << argv[i] << " ";}
    std::cout << "\n";
    #endif

    if(strcmp(argv[1], ITEM) == 0)
    {
        //item new <name> <weight> <cubic> <value>
        if(strcmp(argv[2], CNEW) == 0 && argc == 7) {
            cID i = syst.create(argv[3], std::atoi(argv[4]), std::atoi(argv[5]), std::atoi(argv[6]));
            std::cout << "A new item was created with the ID " << i << '\n';
        }
    }
        //item info <id>
        if(strcmp(argv[2], CINFO) == 0 && argc == 4) {
            Item* it = syst.info(argv[3]);
            if(it == nullptr) {
                std::cout << "No iten Found with this ID\n";
            } else {
                std::cout << it->formatData();
            }
        }

        //item list <page>
        if(strcmp(argv[2], CLIST) == 0 && argc == 4) {
            auto it = syst.list(std::atoi(argv[3]));

            if(it.empty()) {std::cout << "No itens\n";}

            for(std::pair<cID, const Item *> pp: it) {
                std::cout << pp.first << " | " << pp.second->getGlobalName() << "\n";
            }
        }

        //item search <name>
        if(strcmp(argv[2], CSEARCH) == 0 && argc == 4) {
            auto it = syst.search(argv[3]);

            if(it.empty()) {std::cout << "No itens\n";}

            for(std::pair<cID, const Item *> pp: it) {
                std::cout << pp.first << " | " << pp.second->getGlobalName() << "\n";
            }
        }

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

    syst.save();
}
