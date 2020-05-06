#ifndef PARAMS_H__
#define PARAMS_H__

#include <string>

namespace advcpp
{
    class Params
    {
    public:
        Params(){}
       
        ~Params(){}
        // FUNCTIONS
        void Name(std::string const&  a_name){m_name = a_name;}
        void Type(std::string const& a_type) {m_type = a_type;}
        void Location(int const& a_floor ,int const& a_room){m_location.first = a_floor; m_location.second = a_room;}
        void Log(std::string const& a_log){m_log = a_log;}
        void Config(std::string const& a_config) {m_config = a_config;}

        std::string       const&  Name() const {return m_name;}
        std::string       const&  Type() const {return m_type;}
        std::pair<int,int>const&  Location()const  {return m_location;}
        std::string       const&  Log() const {return m_log;}
        std::string       const&  Config() const{return m_config;}

    private:
        std::string        m_name;
        std::string        m_type;
        std::pair<int,int> m_location;
        std::string        m_log;
        std::string        m_config;
    };
     
}

#endif //end PARAMS_H
