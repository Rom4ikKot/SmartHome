#ifndef ABCCONTROLLERAGENT_H__
#define ABCCONTROLLERAGENT_H__

#include <string>
#include <utility>

#include "publisherrun.h"
#include "thread.h"
#include "event.h"
#include "waitablequeue.h"
#include "isetsub.h"

namespace advcpp
{
    void* RunControllerThread(void* context); //thread function

    class ISetSub;
    class ABCControllerAgent 
    {
    public:

        ABCControllerAgent(std::string const& a_name ,std::string const& a_type , std::pair<int,int> const& a_location );
        virtual ~ABCControllerAgent() ;

        virtual void Run(std::tr1::shared_ptr<advcpp::Event> const a_event) = 0;  //for 3d party to implement
        ISetSub*  GetDestination(){return s_subscriptor;} 
        static void SubScribe(ISetSub* a_subscriptor) {s_subscriptor = a_subscriptor;}   //maybe interface
        virtual void RunThread();
        void Stop() ;
        // SETERS
        void Name(std::string const& a_name){m_name = a_name;}
        void Type(std::string const& a_type){m_type = a_type;}
        void Location(std::pair<int,int> const& a_location) {m_location = a_location;}
        // GETERS
        std::string const& Name() const {return m_name;}
        std::string const& Type() const {return m_type;}
        std::pair<int,int> const& Location() const {return m_location;}



        friend class ABCControllerRunnable;
        friend class PublisherRun;
    private:
                 
        virtual void AddEvent2Controller(std::tr1::shared_ptr<advcpp::Event> const a_event); //for smart home control
        //subscriber 

    private:
        std::string                                             m_name;
        std::string                                             m_type;
        std::pair<int,int>                                      m_location;
        bool                                                    m_run;

        static ISetSub*                                         s_subscriptor;
        WaitableQueue<std::tr1::shared_ptr<advcpp::Event> >     m_waitable;
        std::tr1::shared_ptr<advcpp::Thread>                    m_thread;
    };
}

#endif //end ABCCONTROLLERAGENT_H