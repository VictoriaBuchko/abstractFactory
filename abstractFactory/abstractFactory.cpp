#include <iostream>
using namespace std;


class Herbivore abstract {
public:
	virtual string GetName() abstract;
	virtual int GetWeight() abstract;
	virtual void EatGrass() abstract;
	virtual bool IsAlive() abstract;
    virtual void SetAlive(bool Alive)abstract;
};

class Predator abstract {
public:
	virtual string GetName() abstract;
	virtual int GetPower()abstract;
	virtual void Eat(Herbivore* herbivore)abstract;
};


class Wildebeest : public Herbivore {
private:
    int weight;
    bool alive;
public:

    Wildebeest() : weight(300), alive(true) {}

    string GetName() override {
        return "Wildebeest";
    }
    int GetWeight() override {
        return weight;
    }
    void EatGrass() override {
        weight += 10;
    }
    bool IsAlive() override {
        return alive;
    }
    void SetAlive(bool Alive) {
        alive = Alive;
    }
};

class Bison : public Herbivore {
private:
    int weight;
    bool alive;
public:
    Bison() : weight(500), alive(true) {}
    string GetName() override {
        return "Bison";
    }
    int GetWeight() override {
        return weight;
    }
    void EatGrass() override {
        weight += 10;
    }
    bool IsAlive()  override {
        return alive;
    }
    void SetAlive(bool Alive) {
        alive = Alive;
    }
};

class Elk : public Herbivore {
private:
    int weight;
    bool alive;
public:

    Elk() : weight(400), alive(true) {}

    string GetName() override {
        return "Elk";
    }
    int GetWeight() override {
        return weight;
    }
    void EatGrass() override {
        weight += 10;
    }
    bool IsAlive() override {
        return alive;
    }
    void SetAlive(bool Alive) {
        alive = Alive;
    }
};

class Lion : public Predator {
private:
    int power;
public:
    Lion() : power(400) {}

    string GetName() override {
        return "Lion";
    }
    int GetPower() override {
        return power;
    }
    void Eat(Herbivore* herbivore) override {
        if (power > herbivore->GetWeight()) {
            power += 10;
            herbivore->SetAlive(false);
            cout << "Lion eats " << herbivore->GetName() << " and gains power\n";
        }
        else {
            power -= 10;
            cout << "Lion fails to eat " << herbivore->GetName() << " and loses power\n";
        }
    }
};

class Wolf : public Predator {
private:
    int power;
public:
    Wolf() : power(400) {}
    string GetName() override {
        return "Wolf";
    }
    int GetPower()  override {
        return power;
    }
    void Eat(Herbivore* herbivore) override {

        if (power > herbivore->GetWeight()) {
            power += 10;
            herbivore->SetAlive(false);
            cout << "Lion eats " << herbivore->GetName() << " and gains power\n";
        }
        else {
            power -= 10;
            cout << "Lion fails to eat " << herbivore->GetName() << " and loses -10 power\n";
        }
    }
};


class Tiger : public Predator {
private:
    int power;
public:
    Tiger() : power(450) {}
    string GetName() override {
        return "Tiger";
    }
    int GetPower()  override {
        return power;
    }
    void Eat(Herbivore* herbivore) override {

        if (power > herbivore->GetWeight()) {
            power += 10;
            herbivore->SetAlive(false);
            cout << "Lion eats " << herbivore->GetName() << " and gains power\n";
        }
        else {
            power -= 10;
            cout << "Lion fails to eat " << herbivore->GetName() << " and loses -10 power\n";
        }
    }
};


class Continent abstract {
public:
    virtual Herbivore* CreateHerbivore() abstract;
    virtual Predator* CreateCarnivore() abstract;
};

class Africa : public Continent {
public:
    Herbivore* CreateHerbivore() override {
        return new Wildebeest();
    }
    Predator* CreateCarnivore() override {
        return new Lion();
    }
};


class NorthAmerica : public Continent {
public:
    Herbivore* CreateHerbivore() override {
        return new Bison();
    }
    Predator* CreateCarnivore() override {
        return new Tiger();
    }
};

class Eurasia : public Continent {
public:
    Herbivore* CreateHerbivore() override {
        return new Elk();
    }
    Predator* CreateCarnivore() override {
        return new Wolf();
    }
};

class AnimalWorld {
private:
    Herbivore* herbivore;
    Predator* predator;
public:
    AnimalWorld(Continent* factory) {
        herbivore = factory->CreateHerbivore();
        predator = factory->CreateCarnivore();
    }

    void MealsHerbivores() {
        if (herbivore->IsAlive()) {
            herbivore->EatGrass();
            cout << herbivore->GetName() << " eats grass and now weighs " << herbivore->GetWeight() << " kg\n";
        }
    }
    void NutritionCarnivores() {
        if (herbivore->IsAlive()) {
            predator->Eat(herbivore);
        }
    }
};

void TypeAnimalWorld(Continent* continent, const string& continentName) {
    cout << continentName << endl;
    AnimalWorld world(continent);
    world.MealsHerbivores();
    world.NutritionCarnivores();
    cout << endl;
    delete continent;
}

int main() {
    TypeAnimalWorld(new Africa(), "Africa");
    TypeAnimalWorld(new NorthAmerica(), "North America");
    TypeAnimalWorld(new Eurasia(), "Eurasia");

    return 0;
}
