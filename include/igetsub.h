#ifndef IGETSUB_H__
#define IGETSUB_H__

#include <vector>
#include "abccontrolleragent.h"
#include "event.h"

namespace advcpp
{

class ABCControllerAgent;
class IGetSub
{

public:
    // 
        typedef std::vector<ABCControllerAgent*>  ControllerContainer;
    // 

    virtual ~IGetSub();

    virtual std::vector<ABCControllerAgent*> const& GetSubscriptors(Event& a_event) = 0; 
    
};

inline
advcpp::IGetSub::~IGetSub()
{}

} // namespace advcpp

#endif // IGETSUB_H