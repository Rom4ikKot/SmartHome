#ifndef __TOKENYZER_T_H__
#define __TOKENYZER_T_H__

#include <list>
#include <string>

using namespace std;

namespace advcpp
{
    
class tokenyzer_t
{

public:
    // CTOR DEFAULT
    tokenyzer_t();
    //DTOR
    ~tokenyzer_t(){}
    // FUNCTIONS
    list<string>& Tokenize(const string& _string );

private:
    const string m_rules;
    list<string> m_list;
    tokenyzer_t(const tokenyzer_t& _obj); //disable copy
    tokenyzer_t& operator=(const tokenyzer_t& _obj);  //disable operator =
    // TOKENIEZER HELPER FUNCTIONS
    void IsThereSpace(unsigned long& _position , unsigned long& _prev , const string& _string);
    bool FindFirstDel(unsigned long& position,const string&_string);
    void CopySubString2List(unsigned long& _from ,unsigned long _amount ,const string& _string );
    bool DidPositionChange(unsigned long& _current ,unsigned long _prevoius);
};

} // namespace advcpp

#endif /* __TOKENYZER_T_H */