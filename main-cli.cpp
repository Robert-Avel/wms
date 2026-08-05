#include "include/interface.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

static WMRobert syst("WMR.bin");


int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "RobertWMS\n Version 0.0.1\n All Copyright reserved\n";
        return 0;
    }

    syst.itemLoad();

    #ifdef DEBUG
    for(int i = 0; i < argc; i++) {std::cout << argv[i] << " ";}
    std::cout << "\n";
    #endif

    if(strcmp(argv[1], "item") == 0)
    {
        //item new <name> <weight> <cubic> <value>
        if(strcmp(argv[2], "new") == 0 && argc == 7) {
            cID i = syst.itemNew(argv[3], std::atoi(argv[4]), std::atoi(argv[5]), std::atoi(argv[6]));
            std::cout << "A new item was created with the ID " << i << '\n';
        }
    }
        //item info <id>
        if(strcmp(argv[2], "info") == 0 && argc == 4) {
            Item* it = syst.itemInfo(argv[3]);
            if(it == nullptr) {
                std::cout << "No iten Found with this ID\n";
            } else {
                std::cout << it->formatData();
            }
        }
    //item list <page>
    //item search <name>

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

    syst.itemSave();
}
