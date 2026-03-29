/*
🔥 First: Association Types

👉 Association has 2 types:

1.Aggregation

2. Composition

📊 Easy Comparison
Feature	Aggregation	Composition
Relationship	Weak	Strong
Dependency	Independent	Dependent
Lifetime	Separate	Same
Example	Team–Player	House–Room


🧠 Correct Definitions (Fix This Carefully)
🔹 1. Aggregation (HAS-A, weak relationship)

👉 Objects are related but can exist independently

✅ Example:

Class: Team

Class: Player

👉 Player can exist without Team
👉 Team can have players

🔹 2. Composition (HAS-A, strong relationship)

👉 Objects are dependent on each other (lifecycle bound)

❌ If parent is destroyed → child is also destroyed
✅ Example:

Class: House

Class: Room

👉 Room cannot exist without House

*/

// aggregation

class Player{

    public:
    string name;
    Player(string n): name(n){}
};

class Team{

    private:
    vector<Player*>players;
    public:
    void addPlayer(Player *p)
    {
        players.push_back(p);
    }
    void showPlayers(){
        for( auto p: players)
        {
            cout<<p->name<<endl;
        }
    }
};

int main(){
    Player p1("saket");
    Player p2("kohli");
    Team t;
    t.addPlayer(&p1);
    t.addPlayer(&p2);
    t.showPlayers();
}

//composition
class Room{

    public:
    Room(){
        cout<<"Room created"<<endl;
    }
};
class House{
    private:
    Room room; // composion(object inside)
    public:
    House(){
        cout<<"House created"<<endl;
    }
};

int main(){
    House h;
    return 0;
}

//OR

class Passenger{

    public:
    string name;
    Passenger(string n): name(n){}


};

class Booking {

    private:
    vector<Passenger*>passengers;

    public:

    void addPassenger(Passenger *p)
    {
        passengers.emplace_back(p);
    }
    void show(){
        for( auto &p : passengers)
        {
            cout<<p.name<<endl;
        }
    }
};

int main(){

    Passenger p1("saket");
    Passenger p2("ram");
    Booking b1;
    b1.addPassenger(&p1);
    b1.addPassenger(&p2);
    b1.show();
}