#ifndef LOCKER_H__
#define LOCKER_H__

namespace advcpp
{

template <typename T>
class Locker
{
public:
    Locker(T& a_t);
    ~Locker();

private:
    void* operator new(size_t size);

private:
    T&    m_t;

};

template<class T>
advcpp::Locker<T>::Locker(T& a_t)
:m_t(a_t)
{
    m_t.Lock();
}

template<class T> 
advcpp::Locker<T>::~Locker()
{
    m_t.Unlock();
}

} // namespace advcpp


#endif // LOCKER_H