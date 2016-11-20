#ifndef LIXPROC_JSONABLE_H
#define LIXPROC_JSONABLE_H

namespace LixProc
{

class Jsonable
{
 public:
    virtual void toJSON() = 0;
};

}

#endif //LIXPROC_JSONABLE_H
