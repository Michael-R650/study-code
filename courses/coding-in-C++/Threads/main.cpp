#include <iostream>
#include <thread>
#include <semaphore>


#define NUM_ITTERATIONS 1000000
#define NUM_DECREMENTATION 500000
std::binary_semaphore door(1);

void count(int *counter){
    
    for (int i = 0; i<NUM_ITTERATIONS;i++){
        door.acquire();
        (*counter) ++;
        door.release();
    }
}
void decout(int *counter){
    
    for (int i = 0; i<NUM_DECREMENTATION;i++){
        door.acquire();
        (*counter) --;
        door.release();
    }
}
int main(){
    int counter = 0;
    std::thread a{count,&counter};
    std::thread b{count,&counter};
    std::thread c{decout,&counter};
    a.join();
    b.join();
    c.join();
    std::cout <<counter<<"\n";
    return 0;
}
/*---2---
0           
terminate called without an active exception
*/
