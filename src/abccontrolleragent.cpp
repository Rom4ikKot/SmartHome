#include "../include/abccontrolleragent.h"
#include "../include/abccontrollerrunnable.h"
#include <iostream>

namespace advcpp
{

ISetSub* advcpp::ABCControllerAgent::s_subscriptor = 0;

advcpp::ABCControllerAgent::ABCControllerAgent(const std::string &a_name, const std::string &a_type, const std::pair<int,int> &a_location)
:m_name(a_name)
,m_type(a_type)
,m_location(a_location)
{}

advcpp::ABCControllerAgent::~ABCControllerAgent()
{
   m_run = false;
   while (!m_waitable.IsEmpty())
   {
      std::tr1::shared_ptr<advcpp::Event> temp;
      m_waitable.Dequeue(temp) ;
   } 
}

void advcpp::ABCControllerAgent::AddEvent2Controller(std::tr1::shared_ptr<advcpp::Event> const a_event )
{
   m_waitable.Enqueue(a_event);
}

void advcpp::ABCControllerAgent::Stop()
{
   std::string payload = "a";
   std::string type = "STOP";
   std::pair<int,int> location;
   location.first = 0;
   location.second = 0;
   std::tr1::shared_ptr<Event> stopEvent(new Event (payload, type,  location));
   m_waitable.Enqueue(stopEvent);
   m_thread->ThreadJoin();
}

void advcpp::ABCControllerAgent::RunThread()
{
    try
   {
      std::tr1::shared_ptr<Runnable> RunController(new ABCControllerRunnable(*this) );
      m_thread = std::tr1::shared_ptr<Thread>(new Thread(RunController)) ;   
   }
   catch(...)
   {
      //log
      throw; // TODO -do i keep throwing or return my own error ??
   }
}

}  //namespace advcpp