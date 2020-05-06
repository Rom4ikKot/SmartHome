#ifndef __ANALYZER_T_H__
#define __ANALYZER_T_H__

#include <list>
#include <string>
#include <map>
#include <queue>
#include <tr1/memory>

#include "params.h"

using namespace std;

namespace advcpp
{
    
class analyzer_t
{
public:
    // CTOR
    analyzer_t();
    // DTOR
    virtual ~analyzer_t();
    //FUNCTIONS
    void AnalyzeLine(list < string >&  _list );

    //enum
    typedef enum
    {
        NAME = 1,
        TYPE,
        ROOM,
        FLOOR,
        LOG,
        CONFIG
    }types; 

    queue<tr1::shared_ptr<Params> >*  GetParams() ;


private:
    analyzer_t(const analyzer_t& _obj); //disable copy constructor 
    analyzer_t& operator=(const analyzer_t& _obj);//disable operator =
   
private:
    // predefined container
    map<  string , types >                         m_preDefined;
    // created container
    std::queue<std::tr1::shared_ptr<Params> >*     m_params;
    // 
    types                                          m_prev;

private:
    // Helper functions
    bool FindIterPre(string& _string , map<string , types>::iterator& _it);
    void PreDefinedFoundAction(map<string , types>::iterator& _iterMap);
    void UnDefinedFoundAction(string& _string );
    void KeyWordDelimitersOperators(map<string , types>::iterator& _iterMap);
    void TypeDefinedAction(map<string , types>::iterator& _iterMap);
    void Name();
    void Floor(std::string& a_string);
    void Room(std::string& a_string);
    void Config(std::string & a_string);
};

} // namespace advcpp

#endif /* __ANALYZER_T_H */