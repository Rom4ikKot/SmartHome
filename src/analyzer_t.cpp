#include <map>
#include <iostream>
#include <sstream>

#include <stdlib.h>

#include "analyzer_t.h"

using namespace std;

namespace advcpp
{
    
// CTOR
analyzer_t::analyzer_t()
:m_params(new std::queue<std::tr1::shared_ptr<Params> >)
{   
    // initializing predefined types
    m_preDefined.insert(pair<string,types>("NAME",NAME));
    m_preDefined.insert(pair<string,types>("TYPE",TYPE));
    m_preDefined.insert(pair<string,types>("ROOM",ROOM));
    m_preDefined.insert(pair<string,types>("FLOOR",FLOOR));
    m_preDefined.insert(pair<string,types>("LOG",LOG));
    m_preDefined.insert(pair<string,types>("CONFIG",CONFIG));

}

// DTOR
analyzer_t::~analyzer_t()
{}

// Helper Function Find Iter Pre
bool analyzer_t::FindIterPre(string& _string ,map<string , types>::iterator& _it)
{
    return ((_it = m_preDefined.find(_string)) == m_preDefined.end()) ? false : true ;
}

void analyzer_t::Name()
{
    std::tr1::shared_ptr<Params> param(new Params);
    m_params->push(param);
}

// PreDefinedFoundAction
void analyzer_t::PreDefinedFoundAction( map<string , types>::iterator& _iterMap)
{
    switch (_iterMap->second)
    {
    case NAME: Name();
        break;    
    default:
        break;
    }
    m_prev = _iterMap->second;
}

void analyzer_t::Floor(string& _string)
{
    int stam;
    m_params->back()->Location(atoi(_string.c_str()),stam);
}

void analyzer_t::Room(string & _string)
{
    std::pair<int,int> pair ;
    pair = m_params->back()->Location();
    pair.second = atoi(_string.c_str());
    m_params->back()->Location(pair.first,pair.second);
}

void analyzer_t::Config(string & _string)
{
    std::string temp;
    temp = m_params->back()->Config();
    temp+=" ";
    temp+=_string;
    m_params->back()->Config(temp);
}

// Undefined
void analyzer_t::UnDefinedFoundAction(string& _string )
{
    switch (m_prev)
    {
    case NAME:   m_params->back()->Name(_string);
        break;
    case TYPE:   m_params->back()->Type(_string);
        break;
    case ROOM:  Room(_string);
        break;
    case FLOOR: Floor(_string); 
        break;
    case LOG:    m_params->back()->Log(_string);
        break;
    case CONFIG: Config(_string);
        break;
    default:
        break;
    }
}

// Analyze Line
void    analyzer_t::AnalyzeLine(list <string>& _list )
{
    size_t index = 0;
    map<string , types>::iterator iterMap;
    list<string>::iterator iterList = _list.begin();
    for (; index < _list.size(); ++index ,++iterList)
    {
        if(FindIterPre(*iterList  ,iterMap ))
        {
            PreDefinedFoundAction(iterMap);
        }
        else
        {
            UnDefinedFoundAction(*iterList  );
        }  
    }
}

std::queue<std::tr1::shared_ptr<advcpp::Params> >*  advcpp::analyzer_t::GetParams() 
{
    return m_params;
}

} // namespace advcpp