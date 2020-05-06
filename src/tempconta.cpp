#include "../include/tempconta.h"

#include <sstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

namespace advcpp
{

advcpp::TempContA::TempContA(const advcpp::Params &a_params )
:ABCControllerAgent(a_params.Name(),a_params.Type(),a_params.Location())
{ 
    std::istringstream buf(a_params.Config());
    buf >> m_units;
    buf >> m_upper;
    buf >> m_lowwer;
    buf >> m_period;
    buf >> m_typedetect;
    buf >> m_start;
    GetDestination() -> AddSubscription(m_typedetect ,Location() ,this);
}

advcpp::TempContA::~TempContA()
{}

void advcpp::TempContA::Run(std::tr1::shared_ptr<advcpp::Event> a_event)
{
   
    if (atoi(a_event->Payload().c_str()) < m_start)
    {
        std::cout << "The date is: "<< a_event->Time().tm_mday<<" "<< a_event->Time().tm_mon<<" " << a_event->Time().tm_year+1900<<std::endl
        << "The time is: "<< a_event->Time().tm_hour<<":"<< a_event->Time().tm_min<<":"<< a_event->Time().tm_sec<<std::endl
        << "Location is: "<< "Floor:"<<a_event->Location().first<<" Room:"<<a_event->Location().second<<std::endl
        << "The tempreture is: " << a_event->Payload() << std::endl
        << "too cold im heating the room" << std::endl << std::endl;
        std::cout.flush();
    }  
    sleep(5); //for testing
}

extern "C"
{

    IAgent* Create(const advcpp::Params &a_params)
    {
        return new TempContA(a_params);
    }

}

}
    