//
//  Observer.cpp
//  Observer
//
//  Created by wangyue on 2016/11/16.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#include "Observer.hpp"
#include <algorithm>
#include <iostream>

/* 订阅报纸 */
void Subject::Attach(Observer *oo)
{
    m_observerList.push_back(oo);
    cout<<"One customer subscribes the newspaper!\n";
}


/* 取消订阅 */
void Subject::Detach(Observer *oo)
{
    list<Observer*>::iterator iter;
    iter = std::find(m_observerList.begin(),m_observerList.end(),oo);
    m_observerList.erase(iter);

}


/*通知更新*/
void Subject::Notify()
{
    list<Observer*>::iterator iter=m_observerList.begin();
    for ( ; iter != m_observerList.end(); iter++)
    {
        (*iter)->Update();
    }
}


/* 更改状态 */
void ConcreteSubject::Issue()
{
    this->m_Issue = !this->m_Issue;
    if ( this->m_Issue )
    {
        cout << "Newspaper is Issued!\n";
        this->Notify();
        this->m_Issue = false;
    }
    
}


/*订阅者1更新*/
void Subscriber1::Update()
{
    this->m_receive = true;
    this->ShowMessage();
    this->m_receive = false;
}

void Subscriber1::ShowMessage()
{
    cout << "Customer1 has received the newspapers!\n";
}


/*订阅者2更新*/
void Subscriber2::Update()
{
    this->m_receive = true;
    this->ShowMessage();
    this->m_receive = false;
}
void Subscriber2::ShowMessage()
{
    cout << "Customer2 has received the newspapers!\n";
}

/*订阅者3更新*/
void Subscriber3::Update()
{
    this->m_receive = true;
    this->ShowMessage();
    this->m_receive = false;
}
void Subscriber3::ShowMessage()
{
    cout << "Customer3 has received the newspapers!\n";
}





