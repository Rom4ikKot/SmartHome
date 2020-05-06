#include "../include/dlopen.h"

#include <iostream>
#include <dlfcn.h>

namespace advcpp
{

DLOpen::DLOpen()
{}

DLOpen::~DLOpen()
{
    for (size_t i = 0; i < m_handles.size() ; ++i)
    {
        dlclose(m_handles[i]);
    }
}

advcpp::DLOpen::Func  advcpp::DLOpen::GetFunc(const std::string &a_string)
{
    void* handle = dlopen(a_string.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return NULL ;
    }
   
    dlerror();
    Func obj = (Func) dlsym(handle, "Create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol Create: " << dlsym_error << '\n';
        dlclose(handle);
        return NULL ;
    }
    
    m_handles.push_back(handle);
    return obj;
}


} // namespace advcpp
