#ifndef SUBSCRIPTOR_H__
#define SUBSCRIPTOR_H__

#include <map>
#include <vector>

#include "isetsub.h"
#include "igetsub.h"

namespace advcpp
{
    
    class SubScriptor : public IGetSub , public ISetSub 
    {
    public:
        
        SubScriptor();
        ~SubScriptor();
        // Functions
        virtual void AddSubscription(std::string const& a_type , std::pair<int,int> const& a_location,ABCControllerAgent* a_controller ); //for smarthome control
        virtual ControllerContainer const& GetSubscriptors(Event& a_event); 

    private:
        typedef std::string KeyEvent;
        KeyEvent GetKey(std::string const& a_type , std::pair<int,int> const& a_location) const ;
    private:
        std::map<KeyEvent,ControllerContainer> m_controllers;
    };
    
}

#endif //end SUBSCRIPTOR_H
