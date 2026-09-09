#include "IDed_map.hpp"
#include "item.hpp"
#include "volume.hpp"
#include "data/IDed_map.cpp"
#include "data/group.cpp"

template class GroupMap<Item>;
template class GroupMap<Volume>;
template class IDedMap<Volume>;
template class IDedMap<Item>;
