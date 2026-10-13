#include "address/Address.hpp"
#include "UniqueCode.hpp"

Address::Type Address::getType() const {return ad_type;}
const CubicCm& Address::getCapacity() const {return capacity;}

const std::unordered_map<UniC::UniqueCode, CubicCm>& Address::getVolumes() const
{return volumes_in;}


CubicCm Address::getCubic() const {
    CubicCm acc = 0;
    for(auto& a: volumes_in) {
        acc += a.second;
    }
    return acc;
}

bool Address::isOverCapacity() const {return capacity <= getCubic();}

bool Address::appendVolume(IdObj<Volume>& v) {
    UniC::UniqueCode code = UniC::pairToStr({v.getGroup(), v.getID()});
    if(volumes_in.find(code) != volumes_in.end()) {return false;}

    volumes_in.insert({code, v.cgetObj().getCubic()});
    return true;
}

bool Address::removeVolume(UniC::UniqueCode& v) {
    auto target = volumes_in.find(v);
    if(target == volumes_in.end()) {return false;}

    volumes_in.erase(target);
    return true;
}
