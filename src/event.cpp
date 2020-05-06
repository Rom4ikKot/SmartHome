#include "../include/event.h"

namespace advcpp
{

advcpp::Event::Event(const std::string &a_payload, const std::string &a_type, const std::pair<int,int> &a_location)
:m_payload(a_payload)
,m_type(a_type)
,m_location(a_location.first ,a_location.second)
{
    time_t temp  = time(0);
    m_time = *localtime( &temp );
}

advcpp::Event::Event(const advcpp::Event &a_event)
{
    m_location = a_event.m_location;
    m_payload = a_event.m_payload;
    m_time = a_event.m_time;
    m_type = a_event.m_type;
}

}