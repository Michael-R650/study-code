#include <iostream>
#include <thread>
#include <semaphore>
#include <queue>
#include <chrono> // Für die Zeitverzögerung

#define MAX_COUNT 1000

std::binary_semaphore door(1);
std::counting_semaphore<> sem(0); 

std::queue<int> idVec;

void produce(){
    for (int i = 0; i < MAX_COUNT; i++) {
        door.acquire();
        int number = i + 1; 
        idVec.push(number);
        std::cout << "[Producer] Erstellt: " << idVec.back() << std::endl;
        door.release();
        
        sem.release(); 

        // Verlangsamt den Producer ein wenig (z.B. 10 Millisekunden)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consume(){
    for (int i = 0; i < MAX_COUNT; i++) {
        sem.acquire(); 
        
        door.acquire();
        std::cout << "[Consumer] Holt ab: " << idVec.front() << std::endl;
        idVec.pop();
        door.release();

        // Verlangsamt den Consumer ein wenig (z.B. 15 Millisekunden)
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}

int main(){
    std::thread a{produce};
    std::thread b{consume};
    std::thread c{consume};
    std::thread d{consume};
    a.join();
    b.join();
    c.join();
    d.join();
    
    return 0;
}