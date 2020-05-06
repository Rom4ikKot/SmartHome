#include "../include/tempsensa.h"

#include <stdlib.h>     /* srand, rand */
#include <unistd.h>
#include <sstream>

namespace advcpp
{

advcpp::TempSensA::TempSensA(const advcpp::Params &a_params)
:ABCSensorAgent(a_params.Name(),a_params.Type(),a_params.Location())
{
    std::istringstream buf(a_params.Config());
    buf >> m_units;
    buf >> m_upper;
    buf >> m_lowwer;
    buf >> m_period;
    buf >> m_typedetect;
}

advcpp::TempSensA::~TempSensA() 
{}

void advcpp::TempSensA::Run()
{
    std::string payload;
    std::stringstream ss;
    srand(time(NULL));
    ss << rand()%50;
    payload = ss.str();
    try
    {
        GetDestination() -> Enqueue(CreateEvent(payload,m_typedetect));
    }
    catch(const std::exception& e)
    {
        // write to log failed event create and send
    }
    sleep(m_period);
}

extern "C"
    {
        IAgent* Create(const advcpp::Params &a_params)
        {
            return new TempSensA(a_params);
        }
    }

}