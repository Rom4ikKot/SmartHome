#ifndef TEMPCONTA_H__
#define TEMPCONTA_H__

#include "abccontrolleragent.h"
#include "params.h"
#include "iagent.h"
#include "subscriptor.h"

namespace advcpp
{
    extern "C"
    {
        IAgent* Create(Params const& a_params) ;   
    }


    class TempContA : public ABCControllerAgent, public IAgent
    {
    public:
        TempContA(Params const& a_params ); //all 3d party get params
        ~TempContA();

        // FUNCTIONS
        virtual void Run(std::tr1::shared_ptr<advcpp::Event> a_event) ;   // 3d party 2 use 
        
    private: 
        // 3d party decides  witch memmbers to add
        std::string  m_units;//
        int          m_lowwer;//
        int          m_upper;//
        unsigned int m_period;//
        std::string  m_typedetect;
        int m_start;

    };
}

#endif //end TEMPCONTA_H