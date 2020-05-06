#ifndef __PARSER_T_H__
#define __PARSER_T_H__

#include <string>
#include <fstream>

#include "params.h"

using namespace std;

namespace advcpp
{
    
class tokenyzer_t;
class analyzer_t;

class parser_t
{
public:
    // CTOR FROM
    parser_t() ;
    //DTOR
    ~parser_t();
    //FUNCTIONS
    std::queue<std::tr1::shared_ptr<Params> >* Parse(const string _fileName);

private:
    tokenyzer_t* m_tokenyzer;
    analyzer_t*  m_analyzer;
    parser_t(const parser_t& _obj); //disable copy
    parser_t& operator=(const parser_t& _obj);  //disable operator =
};

} // namespace advcpp

#endif /* __PARSER_T_H */