#ifndef ISETSUB_H__
#define ISETSUB_H__

#include <string>

#include "abccontrolleragent.h"

namespace advcpp
{

class ABCControllerAgent;  
class ISetSub
{

public:
    virtual ~ISetSub();

    virtual void AddSubscription(std::string const& a_type , std::pair<int,int> const& a_location,ABCControllerAgent* a_controller ) = 0; 
};

inline
advcpp::ISetSub::~ISetSub()
{}

} // namespace advcpp


#endif //ISETSUB_H