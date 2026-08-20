#include <iostream>
class Occupant {
    private:
    std::string name;
    int stayDuration;
    public:
    Occupant(const std::string& o_Name, int o_stayDuration) 
    : name(o_Name),
    stayDuration(o_stayDuration)
    {
    }
    const std::string& getName() const {
        return name;
    }
    void setName(const std::string& inputName) {
        name = inputName;
    }
    int getStayDuration() const {
        return stayDuration;
    }
    void setStayDuration(int duration) {
        stayDuration = duration;
    }
};

/* CLASSES + METHODS
    occupants - stay duration, name
    rooms - room #, rate, floor #, isOccupied
    floors - number
    player - dollars, name, age

*/

int main(){
    /* GAME LOOP
        Welcome player, set up some basic stuff, name, hotel stuff, etc
        
        create new occupant, ask player where to put in hotel -> draw on screen
        put occupant in room, room now occupied -> draw updated on screen

        end of day calculate profit and add to player balance
        
        ask if they want to upgrade hotel -> buy more floors/rooms

        proceed to next day

    */
    
    std::cout << "Hello, there!";

    return 0;
}