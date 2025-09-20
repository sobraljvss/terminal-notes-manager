#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cstring>

class Chore{
    public:
        int id;
        std::string description;
        int priority;
        bool done;

        Chore(int id, std::string description, int priority, bool done){
            this->id = id;
            this->description = description;
            this->priority = priority;
            this->done = done;
        }

        void display(){
            std::cout << id << ":" << description << " (" << priority << "/" << (done ? "done" : "todo") << ")\n";
        };
};

namespace chores{
    std::vector<Chore> chores;

    std::vector<Chore> getAll(){
        return chores;
    };

    Chore getById(int id){
        for (Chore i : chores){
            if (i.id == id){
                return i;
            }
        }
        return Chore(0, "", 0, false);
    };

    void add(std::string description, int priority){
        chores.push_back(Chore(rand() % 1001, description, priority, false));
    };

    void update(int id, std::string description, int priority, bool done){
        for (unsigned int i = 0; i < chores.size(); i++){
            if (chores[i].id == id){
                chores.insert(chores.begin() + i, Chore(rand() % 1001, description, priority, done));
            }
        }
    };

    void remove(int id){
        for (unsigned int i = 0; i < chores.size(); i++){
            if (chores[i].id == id){
                chores.erase(chores.begin() + i);
            }
        }
    };

    void check(int id){
        Chore chore = getById(id);
        chore.done = true;
    };
}

int main(){

    srand(time(0));

    while (1==1){
        int op;
        std::cout << "option: ";
        std::cin >> op;

        switch (op){
            case 0: break;
            case 1:{
                    for (Chore c : chores::getAll()){
                        c.display();
                    };
                    break;
                }
            case 2:{
                    std::cout << "id: ";
                    int id;
                    std::cin >> id;
                    chores::getById(id).display();
                    break;
                }
            case 3:{
                    std::cout << "description: ";
                    std::string desc;
                    std::cin >> desc;
                    std::cout << desc;
                    std::cout << "priority: ";
                    int p;
                    std::cin >> p;
                    chores::add(desc, p);
                    break;
                }
            case 4:{
                    std::cout << "id: ";
                    int id;
                    std::cin >> id;
                    Chore oldChore = chores::getById(id);
                    std::cout << "change description? ";
                    int op1;
                    int op2;
                    std::string desc;
                    int p;
                    std::cin >> op1;
                    if (op1 != 0){
                        std::cout << "description: ";
                        std::cin >> desc;
                    } else {
                        desc = oldChore.description;
                    }
                    std::cout << "change priority? ";
                    std::cin >> op2;
                    if (op2 != 0){
                        std::cout << "priority: ";
                        std::cin >> p;
                    } else {
                        p = oldChore.priority;
                    }
                    chores::update(id, desc, p, false);
                    break;
                }
            case 5:{
                    std::cout << "id: ";
                    int id;
                    std::cin >> id;
                    chores::remove(id);
                    break;
                }
            case 6:{
                    std::cout << "id: ";
                    int id;
                    std::cin >> id;
                    chores::check(id);
                        chores::getById(id).display();
                    break;
                }
        }
    }
    return 0;
}