#include "cursus.h"

TC* TC::instanceUnique=0;

void TC::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

TC& TC::donneInstance(){
    if (instanceUnique==0) instanceUnique=new TC;
    return *instanceUnique;
}


HuTech* HuTech::instanceUnique=0;

void HuTech::libereInstance(){
    if (instanceUnique!=0) delete instanceUnique;
    instanceUnique = 0;
}

HuTech& HuTech::donneInstance(){
    if (instanceUnique==0) instanceUnique=new HuTech;
    return *instanceUnique;
}
