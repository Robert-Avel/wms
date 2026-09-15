#include "IDed_map.hpp"
#include "base_converter.hpp"
#include "command.hpp"
#include "item.hpp"
#include "interface.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>


static WMRobert syst("WmsDataBase.db");


inline void groupContext(int argc, char** argv) 
{
    syst.data_module.loadGroup();
    //group new <name>
    if(strcmp(argv[2], CNEW) == 0 && argc == 4) {
        uint64_t r = syst.group_module.newGroup(argv[3]);
        if(r == 0) {std::cout << "A group was already created with this name (" << argv[3] << ")\n";}
        else {std::cout << "A new group was created with ID " << r << "\n";}
    }

    //group list
    else if(strcmp(argv[2], CLIST) == 0 && argc == 3) {
        GroupPrefixMap& r = syst.group_module.getGroups();
        if(r.empty()) {std::cout << "No groups\n";}
        else {
            auto it = r.begin();
            while (it != r.end())
            {
                std::cout << it->second << " | " << it->first << "\n";
                it++;
            }   
        }
    }
    syst.data_module.saveGroup();
}



inline void itemContext(int& argc, char**& argv) 
{
    syst.data_module.loadItem();
    syst.data_module.loadGroup();
    //item new <group> <name> <weight> <cubic> <value>
    if(strcmp(argv[2], CNEW) == 0 && argc == 8) {
        uint64_t r = syst.item_module.createItem(
            argv[3],
            argv[4],
            std::atof(argv[5]),
            std::atof(argv[6]),
            std::atoi(argv[7])
        );
        std::cout << "A new item was created with ID" << r << "\n";
    }

    //item info <group> <id>
    else if(strcmp(argv[2], CINFO) == 0 && argc == 5) {
        Item* r = syst.item_module.infoItem(
            argv[3],
            std::atol(argv[4])
        );
        if(r == nullptr) {std::cout << "No item found";}
        else {std::cout << r->formatData();}
    }

    //item list <group> <page>
    else if(strcmp(argv[2], CLIST) == 0 && argc == 5) {

    }

    //item search <name>
    else if(strcmp(argv[2], CSEARCH) == 0 && argc == 5) {
    }
    syst.data_module.saveItem();
}


int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "RobertWMS\nVersion 0.0.1\nAll Copyright reserved\n";
        return 0;
    }


    if(strcmp(argv[1], GROUP) == 0) {groupContext(argc, argv);}
    if(strcmp(argv[1], ITEM) == 0) {itemContext(argc, argv);}


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
