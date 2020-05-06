#include "../include/iagent.h"
#include "../include/abccontrolleragent.h"
#include "../include/abcsensoragent.h"

#include <typeinfo>

#include <iostream>

namespace advcpp
{
    
advcpp::IAgent::~IAgent()
{}

void advcpp::IAgent::Activate()
{
    if (dynamic_cast<ABCControllerAgent*> (this) )
    {
        dynamic_cast<ABCControllerAgent*> (this) -> RunThread();
    }
    else
    {
        dynamic_cast<ABCSensorAgent*> (this) -> RunThread();
    }
}

void advcpp::IAgent::Stop()
{
    if (dynamic_cast<ABCControllerAgent*> (this) )
    {
        dynamic_cast<ABCControllerAgent*> (this) -> Stop();
    }
    else
    {
        dynamic_cast<ABCSensorAgent*> (this) -> Stop();
    }
}


} // namespace advcpp


