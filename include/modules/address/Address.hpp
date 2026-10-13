#include <cstdint>
#include <unordered_map>
#include <utility>
#include <vector>
#include "IdObj.hpp"
#include "UniqueCode.hpp"
#include "volume/Volume.hpp"
typedef uint32_t CubicCm;

class Address {
    enum Type {
        UNKNOW,
        PALLET,
        HACK,
        WIRE_CAGE
    };


    CubicCm capacity;
    Address::Type ad_type;

    std::unordered_map<UniC::UniqueCode, CubicCm> volumes_in;

    public:
        Address(CubicCm capacity_, Address::Type type): capacity(capacity_), ad_type(type)
        {}

        const CubicCm& getCapacity() const;
        const std::unordered_map<UniC::UniqueCode, CubicCm>& getVolumes() const;

        Address::Type getType() const;
        CubicCm getCubic() const;
        bool isOverCapacity() const;

        bool appendVolume(IdObj<Volume>& v);
        bool removeVolume(UniC::UniqueCode& v);
};
