#ifndef UNCOPYABLE_H__
#define UNCOPYABLE_H__

namespace advcpp
{


class Uncopyable
{
    public:
        Uncopyable();
        virtual ~Uncopyable() = 0;
    private:
        Uncopyable& operator=(Uncopyable const &);
        Uncopyable(Uncopyable const &);
};

} //namespace advcpp

#endif // UNCOPYABLE_H__

