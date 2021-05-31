// 3.6 Animal Shelter: 
// An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
// out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
// or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
// that type). They cannot select which specific animal they would like. Create the data structures to
// maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
// and dequeueCat. You may use the built-in Linked List data structure.

#include <iostream>
#include <vector>
#include <optional>
#include <cassert>
#include <stack>
#include <queue>
#include <list>
#include <string>

class AnimalShelter {
public:
    void enqueue(int type, std::string name) {
        if(type == 0) {
            dog.push_back(std::make_pair(time, name));
        } else {
            cat.push_back(std::make_pair(time, name));
        }
        ++time;
    }
    
    std::string dequeueAny() {
        std::string name{};
        if(dog.empty() && cat.empty()) {
            return name;
        }
        if(dog.empty()) {
            name = cat.front().second;
            cat.pop_front();
            return name;
        }
        if(cat.empty()) {
            name = dog.front().second;
            dog.pop_front();
            return name;
        }

        if(dog.front().first < cat.front().first) {
            name = dog.front().second;
            dog.pop_front();
        } else {
            name = cat.front().second;
            cat.pop_front();
        }
        return name;
    }
    std::string dequeueDog() {
        std::string doggo;
        if(dog.empty()) {
            return doggo;
        }
        doggo = dog.front().second;
        dog.pop_front();
        return doggo;
    }
    std::string dequeueCat() {
        std::string kitty;
        if(cat.empty()) {
            return kitty;
        }
        kitty = cat.front().second;
        cat.pop_front();
        return kitty;
    }
public:
    std::list<std::pair<int, std::string>> dog;
    std::list<std::pair<int, std::string>> cat;
    int time{0};
};

int main() {
    AnimalShelter shelter;
    shelter.enqueue(1, "Kitty1");
    shelter.enqueue(0, "Bobby1");
    shelter.enqueue(1, "Kitty2");
    shelter.enqueue(0, "Bobby2");
    shelter.enqueue(0, "Bobby3");
    shelter.enqueue(1, "Kitty3");
    shelter.enqueue(0, "Bobby4");
    shelter.enqueue(0, "Bobby5");
    shelter.enqueue(1, "Kitty4");
    shelter.enqueue(0, "Bobby6");
    shelter.enqueue(1, "Kitty5");
    
    assert("Kitty1" == shelter.dequeueAny());
    assert("Bobby1" == shelter.dequeueAny());
    assert("Bobby2" == shelter.dequeueDog());
    assert("Kitty2" == shelter.dequeueAny());
    assert("Kitty3" == shelter.dequeueCat());

    return 0;
}
