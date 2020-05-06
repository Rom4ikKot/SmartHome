#include <string>
#include "tokenyzer_t.h"

#include <stdio.h>
#include <ctype.h>

using namespace std;

namespace advcpp
{

//CTOR FROM
tokenyzer_t::tokenyzer_t():m_rules("{}[]();<>=+*&, \n\t\v\f\r")
{}


void tokenyzer_t::IsThereSpace(unsigned long& _position , unsigned long& _prev ,const string& _string)
{
   while(isspace(_string[_position]))
    {
        ++_position;
        ++_prev;
    }  
}

bool  tokenyzer_t::FindFirstDel(unsigned long& position,const string&_string)
{
    position = _string.find_first_of(m_rules , position );
    return (position==string::npos)? false:true;
}

void tokenyzer_t::CopySubString2List(unsigned long& _from ,unsigned long _amount ,const string& _string )
{
    string str;
    str = _string.substr (_from,_amount );
    m_list.insert(m_list.end(),str);
}

bool tokenyzer_t::DidPositionChange(unsigned long& _current ,unsigned long _prevoius)
{
    return (_current == _prevoius)? false : true ;
}

list<string>& tokenyzer_t::Tokenize(const string& _string )
{
    unsigned long prev = 0;
    unsigned long position = 0;
    
    while (position!=string::npos) 
    { 
        IsThereSpace(position,prev,_string);
        if(FindFirstDel(position,_string))
        {
            if(DidPositionChange( position, prev) )
            {
                CopySubString2List(prev , position - prev ,_string);
                prev = position;
            }
            else //position did not change
            {
                CopySubString2List(position , 1 ,_string);
                prev = ++position;
            }   
        }
    }
    return m_list;
}

} // namespace advcpp