#include "include/interface.hpp"
#include "item.hpp"
#include "item_data.hpp"
#include "status.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string.h>


static ItemData* main_i_data = nullptr;
static std::ifstream inf;
static std::ofstream outf;

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "RobertWMS\n Version 0.0.1\n All Copyright reserved\n";
        return 0;
    }

    if(argc < 4) {
        std::cout << "No Enough Args to a Safe Run!\n";
        return 1;
    }


    inf.open("data.bin", std::ios::binary | std::ios::in);
    main_i_data = new ItemData(inf);
    inf.close();

    char* option = argv[1];
    char* sub_cmd = argv[2];


    //./wms item get <id> -> item
    if (strcmp(option, "item") == 0) {

        if(strcmp(sub_cmd, "get") == 0) {
            const Item* i =  wmr::item::get(*main_i_data, argv[3]);
            if(i == nullptr) {
                std::cout << "Item Not Found!\n";
            } else std::cout << i->formatData() << "\n";
        }

        //./wms item create <name> <m3> <weight> <cents>
        if(strcmp(sub_cmd, "create") == 0 && argc == 7) {
            Status s = wmr::item::create(*main_i_data, argv[3], std::atoi(argv[4]), std::atoi(argv[5]), std::atoi(argv[6]));
            if (s == SUCCESS) {
                std::cout << "New Item (apparently) was created\n";
            } else std::cout << "Something going wrong\n";
        }

        if(strcmp(sub_cmd, "mode") == 0) {
            std::cout << "Command Here";
            return 0;
        }

        outf.open("data.bin", std::ios::binary | std::ios::out | std::ios::trunc);
        main_i_data->saveData(outf);
        delete main_i_data;
        outf.close();
    }
}
