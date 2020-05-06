#ifndef ABCSENSORAGENT_H__
#define ABCSENSORAGENT_H__

#include "ienq.h"
#include "event.h"
#include "thread.h"

namespace advcpp
{
    
    class ABCSensorAgent
    {
    public:
    
        ABCSensorAgent(std::string const& a_name ,std::string const& a_type , std::pair<int,int> const& a_location);
        virtual ~ABCSensorAgent() ;

        std::tr1::shared_ptr<advcpp::Event>  CreateEvent(const std::string &a_payload, const std::string &a_type) ; 
        virtual void Run() = 0; 
        IenQ*  GetDestination(){return s_destination;} 
        static void SetEventDestination(IenQ* a_destination) {s_destination = a_destination;}  // maybe interface
        virtual void RunThread();   
        virtual void Stop();                 
        //seters

        void Name(std::string const& a_name){m_name = a_name;}
        void Type(std::string const& a_type){m_type = a_type;}
        void Location(std::pair<int,int> const& a_location) {m_location = a_location;}

        //getters
        std::string const& Name() const {return m_name;}
        std::string const& Type() const {return m_type;}
        std::pair<int,int> const& Location() const {return m_location;}
        //friends
        friend class ABCSensorRunnable;
      
    private:
        std::string                                  m_name;
        std::string                                  m_type;
        std::pair<int,int>                           m_location;

        static IenQ*                                 s_destination;
        bool                                         m_run;
        std::tr1::shared_ptr<advcpp::Thread>         m_thread;

    };
}

#endif //end ABCSENSORAGENT_H