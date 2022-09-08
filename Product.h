#pragma once 
#include <iostream>
#include <random>
class Product
{
public: 
   
    
    int celosntost;
    int funcional; 
    int bezopasnost;
    Product(){
       std:: random_device random_device;
       std:: mt19937 generator(random_device());
       std:: uniform_int_distribution<> distribution(89, 94);

     celosntost = distribution(generator);
     funcional = distribution(generator);
     bezopasnost = distribution(generator);
    }
    
};


