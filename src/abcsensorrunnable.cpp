#include "../include/abcsensorrunnable.h"

namespace advcpp
{
    
advcpp::ABCSensorRunnable::ABCSensorRunnable(advcpp::ABCSensorAgent  &a_sensoragent)
:m_sensoragent(a_sensoragent)
{}

advcpp::ABCSensorRunnable::~ABCSensorRunnable()
{}

void advcpp::ABCSensorRunnable::Run()
{
   while(m_sensoragent.m_run)
   {
      m_sensoragent.Run();
   }
}

} // namespace advcpp
