#include <iostream>
#include <csignal>
#include <unistd.h>
#include <chrono>

using namespace std;


pid_t checkPID;
int countP=0;
bool stop;

void startRepair(int sigNum){
     
     cout << "\x1B[2J\x1B[H";
     cout<<"Пришел прибор для отладки"<<endl;

    if(sigNum==SIGUSR1){
        countP++;
        for(int i=1; i<=10;i++){
            sleep(0.2);
            cout<<"Ремонт "<<i*10<<"%"<<endl;
        }
        kill(checkPID,SIGUSR2); 
        cout<<"Прибор отправлен на проверку"<<endl;

    }else if(sigNum==SIGUSR2){
        cout<<"Количество отлаженных приборов "<<countP<<endl;
        cout<<"Ожидание прекращено"<<endl;
        stop=true;
    } 
}
 int main() {

    cout<<"Номер отладочного цеха  \n"<<getpid()<<endl;   
    cout<<"ВВедите номер проверочного цеха"<<endl;
    cin>>checkPID;
    signal(SIGUSR1,startRepair);
    signal(SIGUSR2,startRepair);
    for( ; ;){
        if(stop==false){
                    sleep(1);
        }else{
            break;
        }
    }
    return 0;
}