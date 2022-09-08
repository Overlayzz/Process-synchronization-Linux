#include "Product.h"
class Worker
{
private:
    
public: 
    void Naladka(Product &p);
};
void Worker::Naladka(Product &p){
    if(p.bezopasnost<90){
        p.bezopasnost+= rand()%10 +9;
    }
    if(p.celosntost<90){
        p.celosntost+= rand()%10 +9;
    }if(p.funcional<90){
        p.funcional+= rand()%10 +9;
    }
}