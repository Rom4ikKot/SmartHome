#include "../include/eventcontainer.h"

namespace advcpp
{

advcpp::EventContainer::EventContainer()
{}

advcpp::EventContainer::~EventContainer()
{
    while (!m_events.IsEmpty())
    {
        std::tr1::shared_ptr<advcpp::Event> temp;
        m_events.Dequeue(temp);
    } 
}

void advcpp::EventContainer::Enqueue(std::tr1::shared_ptr<advcpp::Event> const& a_obj)
{
    m_events.Enqueue(a_obj);
}

void advcpp::EventContainer::Dequeue(std::tr1::shared_ptr<advcpp::Event> &a_obj)
{
    m_events.Dequeue(a_obj);
}

} // namespace advcpp
