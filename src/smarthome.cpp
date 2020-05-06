#include "../include/smarthome.h"
#include "../include/abccontrolleragent.h"
#include "../include/abcsensoragent.h"
#include "../include/parser_t.h"

#include <exception>

namespace advcpp
{

advcpp::SmartHome::SmartHome(const std::string &a_config)
:m_config(a_config)
,m_factory(new Factory)
,m_eventContainer(new EventContainer)
,m_subscriptor(new SubScriptor)
,m_publisher(new Publisher(*m_eventContainer,*m_subscriptor))
{
    advcpp::ABCControllerAgent::SubScribe(m_subscriptor);
    advcpp::ABCSensorAgent::SetEventDestination(m_eventContainer);
    try
    {
        m_publisher->Run();
        ////get params from parser //////
        parser_t       parse;
        std::queue<std::tr1::shared_ptr<Params> >*  temp;
        temp = parse.Parse(a_config);
        ////////////////////////////
        m_deviseContainer = m_factory -> GetAgents(*temp);
        delete temp;//temp points to a location on heap must delete // better use shared pointer
        for (size_t i = 0; i < m_deviseContainer->size() ; i++)
        {
            m_deviseContainer->operator[](i)->Activate();
        }
    }
    catch(...)                                                /// add more catches according to action for easier debugging
    {
        throw std::runtime_error("smarthome initializer failed");
    }
}

void advcpp::SmartHome::Stop()
{
    ////stop publisher run ///
    std::string payload = "a";
    std::string type = "STOP";
    std::pair<int,int> location;
    location.first = 0;
    location.second = 0;
    std::tr1::shared_ptr<Event> stopEvent(new Event (payload, type,  location));
    m_eventContainer->Enqueue(stopEvent);
    /////////////stop  all devises /////////////
    for (size_t i = 0; i < m_deviseContainer->size(); i++)
    {
      m_deviseContainer->operator[](i)->Stop();
    }
}

advcpp::SmartHome::~SmartHome()
{ 
    delete m_eventContainer;
    delete m_subscriptor;
    delete m_publisher;
    for (size_t i = 0; i < m_deviseContainer->size(); i++)
    {
        delete m_deviseContainer->operator[](i);
    }
    delete m_factory;
    delete m_deviseContainer;
}

} // namespace advcpp
