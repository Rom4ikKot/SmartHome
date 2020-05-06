#ifndef RUNNABLE_H__
#define RUNNABLE_H__

namespace advcpp
{

class Runnable //maybe private uncoppyable
{

public:
    virtual void Run() = 0;
    virtual  ~Runnable();
};

inline 
advcpp::Runnable::~Runnable()
{}

} // namespace advcpp


#endif //RUNNABLE_H