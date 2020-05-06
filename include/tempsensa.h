#ifndef TEMPSENSA_H__
#define TEMPSENSA_H__

#include <string>

#include "abcsensoragent.h"
#include "params.h"
#include "publisher.h"
#include "iagent.h"

namespace advcpp
{
    extern "C"
    {
        IAgent* Create(Params const& a_params) ;   
    }

    class TempSensA :public ABCSensorAgent , public IAgent
    {
    public:
        TempSensA(Params const& a_params ); //all 3d party get params
        ~TempSensA();

        // FUNCTIONS
        virtual void Run() ; // 3d party 2 use 

    private:
        // 3d party decides  witch memmbers to add
        std::string        m_units;
        int                m_lowwer;
        int                m_upper;
        unsigned int       m_period;
        std::string        m_typedetect;
    }; 
}

#endif //end TEMPSENS_H