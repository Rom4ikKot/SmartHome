#include "../include/firesensa.h"

#include <stdlib.h>     /* srand, rand */
#include <sstream>
#include <unistd.h>

namespace advcpp
{
    advcpp::FireSensA::FireSensA(const advcpp::Params& a_params)
    :ABCSensorAgent(a_params.Name(),a_params.Type(),a_params.Location())
    {
        std::istringstream buf(a_params.Config());
        buf >> m_typedetect;
        buf >> m_period;
    }

    advcpp::FireSensA::~FireSensA()
    {}

    void advcpp::FireSensA::Run()
    {
        std::string payload;
        std::stringstream ss;
        srand(time(NULL));
        ss << rand()%10;
        payload = ss.str();
        try
        {
           GetDestination()->Enqueue(CreateEvent(payload,m_typedetect));
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
            return new FireSensA(a_params);
        }
    }
    
}


