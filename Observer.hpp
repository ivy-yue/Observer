//
//  Observer.hpp
//  Observer
//
//  Created by wangyue on 2016/11/16.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

//#ifndef Observer_hpp
//#define Observer_hpp
//
//#include <stdio.h>
//
//
//
//#include <list>
//
//typedef int STATE;
//
//class Observer;
//class Subject;
//
////subject 抽象基类
//class Subject {
//public:
//    Subject(): SubjectState(-1){}
//    virtual ~Subject();
//    //通知对象
//    void Notify();
//    //新增对象
//    void Attach(Observer *pObserver);
//    //删除、解除对象
//    void Detach(Observer *pObserver);
//    
//    
//    //虚函数提供默认的实现
//    //设置状态
//    virtual void setState(STATE nState);
//    //得到状态
//    virtual STATE getState();
//    
//private:
//    STATE SubjectState;
//    std::list<Observer*> listObserver; //记录observer指针的链表；一对多
//
//};
//
//
//class ConcreteSubject:public Subject {
//public:
//    ConcreteSubject(): Subject(){}
//    virtual ~ConcreteSubject(){}
//    
//    virtual void SetState(STATE nstate);
//    virtual STATE GetState();
//};
//
//class Observer {
//public:
//    Observer(): ObserverState(-1){}
//    virtual ~Observer(){}
//    
//    // 各个派生类可能有不同的实现
//    // 通知Observer状态发生了变化
//    virtual void Update(Subject* pSubject) = 0;
//protected:
//    STATE ObserverState;
//};
//
//// ConcreteObserver类派生自Observer
//class ConcreteObserver: public Observer {
//public:
//    ConcreteObserver(): Observer(){}
//    virtual ~ConcreteObserver(){}
//    
//    virtual void Update(Subject* pSubject);
//};
//
//#endif /* Observer_hpp */
//


#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <list>
using namespace std;
class Observer;
/* 被观察者接口 */
class Subject
{
public:
    Subject():m_Issue(0)
    {
        
        
    }
    void Attach(Observer *oo);//订阅此对象
    void Detach(Observer *oo);//解除订阅
    void Notify();//通知订阅者更新
    void virtual Issue() = 0;//发行函数
    bool GetIssue()
    {
        return m_Issue;
    }
    ~Subject()
    {
        list<Observer*>::iterator iter1,iter2,temp;
        for (iter1 = m_observerList.begin(), iter2 = m_observerList.end();
             iter1 != iter2;
             )
        {
            temp = iter1;
            ++iter1;
            m_observerList.erase(temp);
        }
        
        
        m_observerList.clear();
    }
protected:
    bool m_Issue;//发行标志
    list<Observer*> m_observerList;//订阅者队列
};

/*观察者接口*/
class Observer
{
public:
    Observer():m_receive(0){};
    void virtual Update()//更新函数
    {
        
    }
    void virtual ShowMessage() = 0;//模拟与被观察者相关的函数
protected:
    bool m_receive;//收到报纸标志
};
/* 具体的被观察者 */
class ConcreteSubject:public Subject
{
public:
    ConcreteSubject()
    {}
    void Issue();
};
/* 具体的观察者 */
class Subscriber1:public Observer
{
public:
    void virtual Update();
    void ShowMessage();
};

class Subscriber2:public Observer
{
public:
    void virtual Update();
    void ShowMessage();
};

class Subscriber3:public Observer
{
public:
    void virtual Update();
    void ShowMessage();
};
#endif




