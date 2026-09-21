#include "group.hpp"
#include <sqlite3.h>


template<class T>
class DataMngr {
    virtual std::string formatInsertion(T& i) = 0;

    public:
    GroupMap<T> data;
    sqlite3*& opened_db;

    virtual bool save(uint64_t group, uint64_t id) = 0;
    virtual bool saveAll();
    virtual bool load(uint64_t group, uint64_t id) = 0;
    virtual bool loadAll();
};