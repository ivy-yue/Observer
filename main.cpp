//
//  main.cpp
//  Observer
//
//  Created by wangyue on 2016/11/16.
//  Copyright © 2016年 ___ivy___. All rights reserved.
//

#include <iostream>



#include "Observer.hpp"
#include <iostream>
int main()
{
    Subject *sub=new ConcreteSubject(); //被观察者
    Observer *customer1 = new Subscriber1();//观察者1
    Observer *customer2 = new Subscriber2();//观察者2
    Observer *customer3 = new Subscriber3();//观察者3
    
    sub->Attach(customer1);//观察者1订阅报纸
    sub->Attach(customer2);//观察者2订阅报纸
    sub->Attach(customer3);//观察者3订阅报纸
    cout<<"*********************************\n";
    
    if (sub->GetIssue())
    {
        cout << "Newspapers has issued!\n";
    }
    else
    {
        cout << "Newspapers has not issued!\n";
    }
    cout<<"*********************************\n";
    sub->Issue();       //发行报纸
    cout<<"*********************************\n";
    if (sub->GetIssue())
    {
        cout << "Newspapers has issued!\n";
    }
    else
    {
        cout << "Newspapers has not issued!\n";
    }
    cout<<"*********************************\n";
    sub->Detach(customer3);//观察者1取消订阅
    cout<<"Customer3 unsubcribes the newspaper!\n";
    cout<<"*********************************\n";
    sub->Issue();        //发行报纸
    return 0;
}
