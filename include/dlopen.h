#ifndef DLOPEN_H__
#define DLOPEN_H__

#include "iagent.h"
#include "params.h"

#include <vector>

namespace advcpp
{
    
class DLOpen
{

public:
    typedef IAgent* (*Func)(Params const& a_params) ;

    DLOpen();
    ~DLOpen();

    // Functions
    Func GetFunc(std::string const& a_string);
              

private:
    std::vector<void*>  m_handles;
};


} // namespace advcpp


#endif //DLOPEN_H