#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Superhero {
public:
    Superhero(const std::string& name, const std::string& power) : name(name), power(power) {
        dynamicData = nullptr;
    }
    
    virtual void showDetails() const {
        std::cout << "Name: " << name << "\nPower: " << power << std::endl;
    }
    
    bool operator==(const Superhero& other) const {
        return name == other.name && power == other.power;
    }
    
    static int totalSuperheroes;
    
    friend void introduce(const Superhero& hero);
    
    const std::string& getName() const {
        return name;
    }
    
protected:
    std::string name;
    std::string power;
    static int instances;
    int* dynamicData;
    
    void allocateDynamicData() {
        dynamicData = new int[10];
    }
    
    void constFunction() const {
        // Cannot modify member variables.
    }
};

int Superhero::totalSuperheroes = 0;
int Superhero::instances = 0;

void introduce(const Superhero& hero) {
    std::cout << "Meet " << hero.name << ", a superhero with " << hero.power << " power!" << std::endl;
}

class Sidekick : public Superhero {
public:
    Sidekick(const std::string& name, const std::string& power, const Superhero& mentor)
        : Superhero(name, power), mentor(mentor) {
        allocateDynamicData();
    }

    Sidekick(const Sidekick& other) 
        : Superhero(other), mentor(other.mentor) {
        allocateDynamicData();
    }
    
    void showDetails() const override {
        Superhero::showDetails();
        std::cout << "Mentor: " << mentor.getName() << std::endl;
    }

    ~Sidekick() {
        delete[] dynamicData;
    }

private:
    Superhero mentor;
};

class SuperheroCatalog {
public:
    void addSuperhero(const Superhero& hero) {
        superheroes.push_back(hero);
    }

    void addSidekick(const Sidekick& sidekick) {
        sidekicks.push_back(sidekick);
    }

    const std::vector<Superhero>& getSuperheroes() const {
        return superheroes;
    }

    const std::vector<Sidekick>& getSidekicks() const {
        return sidekicks;
    }

    bool removeSuperhero(const Superhero& hero) {
        auto it = std::find(superheroes.begin(), superheroes.end(), hero);
        if (it != superheroes.end()) {
            superheroes.erase(it);
            return true;
        }
        return false;
    }

    bool removeSidekick(const Sidekick& sidekick) {
        auto it = std::find(sidekicks.begin(), sidekicks.end(), sidekick);
        if (it != sidekicks.end()) {
            sidekicks.erase(it);
            return true;
        }
        return false;
    }

    void listSuperheroes() const {
        std::cout << "Superheroes:\n";
        for (const Superhero& hero : superheroes) {
            hero.showDetails();
            std::cout << "---------------\n";
        }
    }

    void listSidekicks() const {
        std::cout << "Sidekicks:\n";
        for (const Sidekick& sidekick : sidekicks) {
            sidekick.showDetails();
            std::cout << "---------------\n";
        }
    }

private:
    std::vector<Superhero> superheroes;
    std::vector<Sidekick> sidekicks;
};

int main() {
    SuperheroCatalog catalog;
    while (true) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Add Superhero\n";
        std::cout << "2. Add Sidekick\n";
        std::cout << "3. Remove Superhero\n";
        std::cout << "4. Remove Sidekick\n";
        std::cout << "5. List Superheroes\n";
        std::cout << "6. List Sidekicks\n";
        std::cout << "7. Exit\n";

        int option;
        std::cin >> option;
        std::cin.ignore();  // To handle newline character after option input

        if (option == 1) {
            std::string name, power;
            std::cout << "Enter the name of the superhero: ";
            std::getline(std::cin, name);
            std::cout << "Enter the power of the superhero: ";
            std::getline(std::cin, power);
            Superhero superhero(name, power);
            catalog.addSuperhero(superhero);
        } 
        else if (option == 2) {
            std::string name, power;
            std::string mentorName;
            std::cout << "Enter the name of the sidekick: ";
            std::getline(std::cin, name);
            std::cout << "Enter the power of the sidekick: ";
            std::getline(std::cin, power);
            std::cout << "Enter the name of the mentor superhero: ";
            std::getline(std::cin, mentorName);

            const std::vector<Superhero>& superheroes = catalog.getSuperheroes();
            Superhero mentor("Unknown", "Unknown");
            bool mentorFound = false;

            for (const Superhero& hero : superheroes) {
                if (hero.getName() == mentorName) {
                    mentor = hero;
                    mentorFound = true;
                    break;
                }
            }

            if (mentorFound) {
                Sidekick sidekick(name, power, mentor);
                catalog.addSidekick(sidekick);
            } else {
                std::cout << "Mentor superhero not found. Sidekick not added.\n";
            }
        } 
        else if (option == 3) {
            std::string name, power;
            std::cout << "Enter the name of the superhero to remove: ";
            std::getline(std::cin, name);
            std::cout << "Enter the power of the superhero to remove: ";
            std::getline(std::cin, power);
            Superhero heroToRemove(name, power);
            if (catalog.removeSuperhero(heroToRemove)) {
                std::cout << "Superhero removed.\n";
            } else {
                std::cout << "Superhero not found.\n";
            }
        } 
        else if (option == 4) {
            std::string name, power;
            std::cout << "Enter the name of the sidekick to remove: ";
            std::getline(std::cin, name);
            std::cout << "Enter the power of the sidekick to remove: ";
            std::getline(std::cin, power);
            Sidekick sidekickToRemove(name, power, Superhero("Unknown", "Unknown"));
            if (catalog.removeSidekick(sidekickToRemove)) {
                std::cout << "Sidekick removed.\n";
            } else {
                std::cout << "Sidekick not found.\n";
            }
        } 
        else if (option == 5) {
            catalog.listSuperheroes();
        } 
        else if (option == 6) {
            catalog.listSidekicks();
        } 
        else if (option == 7) {
            break;
        }
    }
    return 0;
}
