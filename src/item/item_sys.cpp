#include "item_sys.hpp"
#include "base_converter.hpp"
#include "byte_serializator.hpp"
#include <cstddef>


ByteS ItemSys::getByte() {
    ByteS buffer{};

    size_t size = itens.size();
    bID next_ID = itens.showNexID();

    buffer.append((char*) &next_ID, sizeof(bID));
    buffer.append((char*) &size, sizeof(size));

    auto iter = itens.begin();
    while(iter != itens.end()) {
        buffer.append((char*) &iter->first, sizeof(bID));
        buffer << iter->second.getBytes();
        iter++;
    }
    return buffer;
}


ItemSys::ItemSys(ByteS& __bs) {
    size_t item_n;
    bID next_ID;
    this->itens.setNexID(next_ID);

    __bs.pop((char*) &item_n, sizeof(size_t));
    __bs.pop((char*) &next_ID, sizeof(bID));

    bID id;
    for(size_t i = 0; i < item_n; i++) {
        __bs.pop((char*) &id, sizeof(bID));
        this->itens.insert(id, {__bs});
    }
}


cID ItemSys::create(std::string name, double weight, double cubic, cents value) {
    Item i{name, cubic, weight, value};
    return basec::intToBase(itens.append(i), code_mode);
}

Item* ItemSys::info(cID id_) {
    return itens.getItem(basec::baseToInt(id_, code_mode));
}


std::list<std::pair<cID, const Item*>> ItemSys::list(uint32_t page) {
    std::list<std::pair<cID, const Item*>> output;

    if(itens.isEmpty()) {return output;}

    unsigned int i_page = 1;
    for (uint64_t it_id = 1; it_id <= itens.size(); it_id++) {
        if(page == i_page) {
            Item* i = this->itens.getItem(it_id);
            output.push_back({basec::intToBase(it_id, code_mode), i});
        }
        if(page % 10 == 0) {i_page++;}
    }
    return output;
}


std::list<std::pair<cID, const Item*>> ItemSys::search(std::string name) {
    std::list<std::pair<cID, const Item*>> output;
    if(itens.isEmpty()) {return output;}

    auto it = itens.begin();
    while (it != itens.end()) {
        if(it->second.getGlobalName().find_first_of(name) != it->second.getGlobalName().npos) {
            output.push_back({basec::intToBase(it->first, code_mode), &it->second});
        }
        it++;
    }
    return output;
}
