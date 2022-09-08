#include "Product.h"
#include "Checker.h"
#include "Worker.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <csignal>
#include <termios.h>
#include <stack>
using namespace std;

int countB;
int countCh;
int countR;
stack<Product> Allproducts;
stack<Product>Store;
stack<Product>Repair;
pid_t dispPID;
Product temporary_repair;
Checker checker;
Worker worker;
bool send;

void sendToRepair(){
    if(!Repair.empty()){
        temporary_repair = Repair.top();
        kill(dispPID,SIGUSR1);
        send=true;
    }
}
void GetRepeared(int signum){       
        if(!Repair.empty()){
             Repair.pop();
             worker.Naladka(temporary_repair);
             Allproducts.push(temporary_repair);
             cout<<"пришел отремонтирваонный прибор"<<endl; 
             send=false;
        }       
}
void init(){
 for(int i=0;i<20;i++)
    {
        Product p;
        Allproducts.push(p);
    }   
}
int main()
{			
      cout <<"Номер цеха \n"<<getpid()<<endl;
      cout << "Введите номер отладочного цеха: ";
      cin >> dispPID;
      signal(SIGUSR2,GetRepeared);
      init();
        while (true){
            sleep(2);
            Product product = Allproducts.top();
            Allproducts.pop(); 
            countCh++;
            cout<<countCh<<" Проверка прибора"<<endl;
            if(checker.check(product)){
                Store.push(product);
                cout<<"Направлен в в склад готовой продукции "<<endl;
                cout<<"Количество годных приборов "<< Store.size()<<endl;
            }else{       
                countB++;         
                cout<<"Направлен в отладочный цех"<<endl;
                Repair.push(product);
                sendToRepair();
            }
            if(!Allproducts.empty()){
                       continue;
            }else if (Allproducts.empty()&&send==true)
            {
                continue;

            }
            cout << "\x1B[2J\x1B[H";
            kill(dispPID,SIGUSR2);
            cout<<"Проверка приборов завершена "<<endl;
            cout<<"Проверок проведено "<<countCh<<endl;
            cout<<"Неисправных приборов выявлено "<<countB<<endl;
            int proc =  (static_cast<float>(countB) / static_cast<float>(Store.size()))*100;
            cout<<"Процентное соотношение брака после выпуска"<<proc<<endl;

            return 0;
            
        } 
    return 0;						
}	
