#ifndef EVENT_H__
#define EVENT_H__

#include <string>
#include <utility>
#include <ctime>

namespace advcpp
{
    class Event
    {
    public:
        Event(std::string const& a_payload,std::string const& a_type, std::pair<int,int> const& a_location);
        Event(Event const& a_event);
        ~Event(){}

        // Functions //seters
        std::string const& Payload() const {return m_payload;}
        std::string const& Type() const {return m_type;}
        std::pair<int,int> const& Location() const {return m_location;}
        struct tm const& Time() const {return m_time;}
        
    private:
        std::string m_payload; //maybe struct?
        std::string m_type;
        std::pair<int,int> m_location;
        struct tm m_time; 
    };
}

#endif //end EVENT_H