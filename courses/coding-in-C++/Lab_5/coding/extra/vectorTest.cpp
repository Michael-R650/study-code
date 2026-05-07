#include <iostream>
#include <vector>
#include <list>
#include <map>
int main()
{
    // Vector
    std::vector<int> v = {1, 2, 3};
    v.push_back(4); // Element hinzufügen
    v.pop_back();   // Element entfernen
    std::cout << "1. Element: " << v.front() << "\n";
    std::cout
        << "Letztes Element: " << v.back() << "\n";
    std::cout << "Element an Index 1: " << v[1] << "\n";

    for(int x : v){
        std::cout <<x<<" ";
    }
    std::cout <<"\n";

    // List
    std::list<int> l{1, 2, 3};
    l.push_front(0);
    l.push_back(4);
    l.pop_front();
    std::cout << "Front: " << l.back() << "\n";
    std::cout << "Back: " << l.front() << "\n";
    std::cout << "Length: " << l.size() << "\n";

    //Output V1
    std::cout << "Alle Elemente der List: ";
    for(std::list<int>::iterator it = l.begin(); it!=l.end(); it++){
        std::cout <<*it <<" ";
    }
    std::cout <<"\n";

    //Output V2
    std::cout << "Alle Elemente der List: ";
    while (!l.empty())
    {
        std::cout << l.front() << " ";
        l.pop_front();
    }
    std::cout << "\n";

    // Map
    std::map<std::string, int> m;
    m["Alice"] = 25;
    m.insert({"Bob", 30});
    m.erase("Alice");

    return 0;
}