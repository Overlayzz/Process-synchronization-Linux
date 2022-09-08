#pragma once 
#include "Product.h"
class Checker
{
private:
public:

    bool check(Product p){
        if(p.bezopasnost<90||p.celosntost<90||p.funcional<90){
           std::cout<<"***************************************"<<std::endl;
            std::cout<<"Деталь проверку не прошла"<<std::endl;
            std::cout<<"Отклонения от норм" <<std::endl;
            if(p.bezopasnost<90){
                int otkl = 90-p.bezopasnost;
                 std::cout<<"Безопасность "<<otkl<<std::endl;

            }
             if(p.celosntost<90){
                int otkl = 90-p.celosntost;
                 std::cout<<"Целосность "<<otkl<<std::endl;

            } if(p.funcional<90){
                int otkl = 90-p.funcional;
                 std::cout<<"Функционал "<<otkl<<std::endl;
            }
            std::cout<<"***************************************"<<std::endl;

            return false;
        }else{
             std::cout<<"Деталь прошла проверку"<<std::endl;
            std::cout<<"***************************************"<<std::endl;
            return true;
        }
    }
   
};
