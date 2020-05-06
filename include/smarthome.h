#ifndef SMARTHOME_H__
#define SMARTHOME_H__

#include <string>

#include "iagent.h"
#include "uncopyable.h"
#include "factory.h"
#include "eventcontainer.h"
#include "subscriptor.h"

namespace advcpp
{

class SmartHome :private Uncopyable
{

public:
    SmartHome(std::string const& a_config);
    ~SmartHome();

    void Stop();

private:
    std::string            m_config;
    Factory*               m_factory;
    EventContainer*        m_eventContainer;
    SubScriptor*           m_subscriptor;
    Publisher*             m_publisher;
    std::vector<IAgent*>*  m_deviseContainer;
};

} // namespace advcpp

#endif //SMARTHOME_H