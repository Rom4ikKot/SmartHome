#include "../include/subscriptor.h"

#include <sstream>

namespace advcpp
{
    advcpp::SubScriptor::SubScriptor()
    {}

    advcpp::SubScriptor::~SubScriptor()
    {}

    std::string advcpp::SubScriptor::GetKey(const std::string &a_type, std::pair<int,int> const&a_location) const
    { 
        std::ostringstream temp;
        std::string ret;
        temp << a_type;
        temp << a_location.first;
        temp << a_location.second;
        ret = temp.str();
        return ret;
    }

    void advcpp::SubScriptor::AddSubscription(const std::string &a_type, std::pair<int,int> const& a_location, advcpp::ABCControllerAgent *a_controller)
    {
        m_controllers[GetKey(a_type,a_location)].push_back(a_controller);
    }

    std::vector<ABCControllerAgent*> const& advcpp::SubScriptor::GetSubscriptors(advcpp::Event &a_event)
    {
        return m_controllers[GetKey(a_event.Type(), a_event.Location())];
    } 
}