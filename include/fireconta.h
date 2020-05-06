#ifndef FIRECONTA_H__
#define FIRECONTA_H__

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

    class FireContA : public ABCControllerAgent, public IAgent
    {
    public:
        FireContA(Params const& a_params );  //all 3d party get params
        ~FireContA();
        // FUNCTIONS
        virtual void Run(std::tr1::shared_ptr<advcpp::Event> a_event) ;  // 3d party 2 use 
    private:
        // 3d party decides  witch memmbers to add
        std::string        m_typedetect; 
        int                m_value;
    };
    
}


#endif //end FIRECONTA_H