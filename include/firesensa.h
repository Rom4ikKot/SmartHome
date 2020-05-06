#ifndef FIRESENSA_H__
#define FIRESENSA_H__

#include <string>

#include "abcsensoragent.h"
#include "iagent.h"
#include "params.h"

namespace advcpp
{ 
    extern "C"
    {
        IAgent* Create(Params const& a_params) ;   
    }

    class FireSensA :public ABCSensorAgent , public IAgent
    {
    public:
        FireSensA(Params const& a_params ); //all 3d party get params 
        ~FireSensA();

        // FUNCTIONS
        virtual void Run() ; // 3d party 2 use 

    private:
        // 3d party decides  witch memmbers to add
        std::string        m_typedetect; 
        int                m_period;
    };
}

#endif //end FIRESENSA_H