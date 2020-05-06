#ifndef WAITABLEQUEUE_H__
#define WAITABLEQUEUE_H__

#include <queue>
#include <stdexcept>

#include "mutex.h"
#include "condvar.h"
#include "uncopyable.h"
#include "locker.h"

namespace advcpp
{

template<class T>
class WaitableQueue : private Uncopyable
{
	public:

		WaitableQueue();

		void Enqueue(T const& a_val);

		void Dequeue(T& a_t);

		bool IsEmpty() const;

		T& Front() const;
		T& Last() const;
				 
	private:
		mutable Mutex	m_mutex;
		CondVar	        m_condv;
		std::queue<T> 	m_queue;
        int             m_waiters;  
};

template <typename T>
class QueueEmpty
{
public:
	QueueEmpty(WaitableQueue<T>* a_obj)
	:m_q(a_obj)
	{}
	bool operator()()
	{
        return m_q->IsEmpty();
	}
private:
	WaitableQueue<T>* m_q;
};



template<class T>
WaitableQueue<T>::WaitableQueue()
:m_mutex("Roman",advcpp::Mutex::RECURSIVE)
,m_condv(m_mutex)
,m_waiters(0)
{}

template<class T>
void WaitableQueue<T>::Enqueue(T const& _val)
{
	int res;
    {
    Locker<Mutex>  locker(m_mutex);
    m_queue.push(_val);
    res = m_waiters;
    }
    if (res)
    {
        m_condv.Signal();
    }   
}

template<class T>
void WaitableQueue<T>::Dequeue(T& a_t) 
{
    Locker<Mutex>  locker(m_mutex);
    ++m_waiters;   ///think
    m_condv.Wait(QueueEmpty<T>(this));
    --m_waiters;  //think 
    a_t = m_queue.front();
    m_queue.pop();
}

template<class T>
bool WaitableQueue<T>::IsEmpty() const
{
	Locker<Mutex> locker(m_mutex);
    return m_queue.empty();
}

template<class T>
T&  WaitableQueue<T>::Front() const
{
	Locker<Mutex> locker;
    return m_queue.front(); 
}

template<class T>
T&  WaitableQueue<T>::Last() const
{
	Locker<Mutex> locker;
    return  m_queue.last(); 
}

} // namespace advcpp

#endif //end WAITABLEQUEUE2_H