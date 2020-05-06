#ifndef IENQ_H__
#define IENQ_H__

#include "event.h"
#include <tr1/memory>

namespace advcpp
{
    
class IenQ
{

public:

    virtual void Enqueue(std::tr1::shared_ptr<Event> const& a_obj) = 0;
    virtual ~IenQ();

};

inline
advcpp::IenQ::~IenQ()
{}


} // namespace advcpp


#endif //IENQ_H