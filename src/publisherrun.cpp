#include "publisherrun.h"
#include "igetsub.h"
#include <tr1/memory>
#include <iostream>


namespace advcpp
{

advcpp::PublisherRun::PublisherRun(advcpp::Publisher &a_obj)
:m_publisher(a_obj)
{}

advcpp::PublisherRun::~PublisherRun()
{}

void advcpp::PublisherRun::Run()
{
    while (1)
    {
        std::tr1::shared_ptr<advcpp::Event> spEvent;
        m_publisher.m_dequeu.Dequeue(spEvent); 

        if (spEvent->Type() == "STOP")
        {
            break;
        }
        
        advcpp::IGetSub::ControllerContainer controllerContainer = m_publisher.m_getsub.GetSubscriptors(*spEvent.get());

        for (size_t i = 0; i < controllerContainer.size(); ++i)
        {
            controllerContainer[i] -> AddEvent2Controller(spEvent); 
        }   
    }
    
}
    
} // namespace advcpp


