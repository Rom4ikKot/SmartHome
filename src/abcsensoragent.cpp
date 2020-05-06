#include "../include/abcsensoragent.h"
#include "../include/abcsensorrunnable.h"

namespace advcpp
{

IenQ* advcpp::ABCSensorAgent::s_destination = 0;

advcpp::ABCSensorAgent::ABCSensorAgent(const std::string &a_name, const std::string &a_type, const std::pair<int,int> &a_location)
:m_name(a_name)
,m_type(a_type)
,m_location(a_location)
,m_run(false)
{}

advcpp::ABCSensorAgent::~ABCSensorAgent()
{
   
}

void advcpp::ABCSensorAgent::Stop()
{
   m_run = false;
   m_thread->ThreadJoin();
}

std::tr1::shared_ptr<Event> advcpp::ABCSensorAgent::CreateEvent(const std::string &a_payload, const std::string &a_type)
{
   std::tr1::shared_ptr<Event>  spEvent( new Event(a_payload, a_type,m_location));
   return spEvent;
}

void advcpp::ABCSensorAgent::RunThread()
{
   try
   {
      m_run = true;
      std::tr1::shared_ptr<Runnable> RunSensor(new ABCSensorRunnable(*this) );
      m_thread = std::tr1::shared_ptr<Thread>(new Thread(RunSensor)) ;   
   }
   catch(...)
   {
      //log
      throw; // TODO -do i keep throwing or return my own error ??
   }
}

}
