#include "IDed_map.hpp"
#include "base_converter.hpp"
#include "include/interface.hpp"
#include "item.hpp"
#include "status.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string.h>
#include <string_view>
#include <vector>

static WMRobert syst;


int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "RobertWMS\n Version 0.0.1\n All Copyright reserved\n";
        return 0;
    }

    //item new <name> <weight> <cubic> <value>
    //item info <id>
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

}
