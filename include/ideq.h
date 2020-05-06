#ifndef IDEQ_H__
#define IDEQ_H__

#include <tr1/memory>
#include "event.h"

namespace advcpp
{
    
class IdeQ
{

public:

    virtual void Dequeue(std::tr1::shared_ptr<Event> & a_obj) = 0;
    virtual ~IdeQ();

};

inline
advcpp::IdeQ::~IdeQ()
{}

} // namespace advcpp


#endif //IDEQ_H