#include "../include/fireconta.h"

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

namespace advcpp
{

advcpp::FireContA::FireContA(const advcpp::Params &a_params )
:ABCControllerAgent(a_params.Name(),a_params.Type() ,a_params.Location() )
{
    std::istringstream buf(a_params.Config());
    buf >> m_typedetect;
    buf >> m_value;
    GetDestination() -> AddSubscription(m_typedetect ,Location() ,this);
}

advcpp::FireContA::~FireContA()
{}

void advcpp::FireContA::Run(std::tr1::shared_ptr<advcpp::Event> a_event)
{
    if(atoi(a_event->Payload().c_str()) > m_value )
    {
        std::cout << "The date is: "<< a_event->Time().tm_mday<<" "<< a_event->Time().tm_mon<<" " << a_event->Time().tm_year+1900<<std::endl
         << "The time is: "<< a_event->Time().tm_hour<<":"<< a_event->Time().tm_min<<":"<< a_event->Time().tm_sec<<std::endl
         <<"Location is: "<< "Floor:"<<a_event->Location().first<<" Room:"<<a_event->Location().second<<std::endl
         << "There is fire: " << a_event->Payload() << std::endl
         << "Activating sprinklers" << std::endl << std::endl;
        std::cout.flush();
    }
    sleep(5);  ///for testing
}

extern "C"
    {
        IAgent* Create(const advcpp::Params &a_params)
        {
            return new FireContA(a_params);
        }
    }

}