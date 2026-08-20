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
    void setName(const std::string& newName) {
        name = newName;
    }
    int getStayDuration() const {
        return stayDuration;
    }
    void setStayDuration(int newDuration) {
        stayDuration = newDuration;
    }
};
class Player {
    private:
    int money;
    std::string name;
    int age;
    public:
    Player(int p_money, const std::string& p_name, int p_age) 
    : money(p_money),
    name(p_name),
    age(p_age)
    {
    }
    int getMoney() const {
        return money;
    }
    void setMoney(int newMoney) {
        money = newMoney;
    }
    const std::string& getName() const { 
        return name;
    }
    void setName(const std::string& newName) {
        name = newName;
    }
};
class Floor {
    private:
    int numberFloors;
    int numberRooms;
    public:
    Floor(int n_Floors, int n_Rooms)
    : numberFloors(n_Floors),
    numberRooms(n_Rooms)
    {
    }
    int getNumberFloors() const{
        return numberFloors;
    }
    void setNumberFloors(int newNumberFloors) {
        numberFloors = newNumberFloors;
    }
    int getNumberRooms() const {
        return numberRooms;
    }
    void setNumberRooms(int newNumberRooms) {
        numberRooms = newNumberRooms;
    }
};
class Room {
    private:
    int roomNumber;
    int rate;
    int floorNumber;
    bool isOccupied;
    public:
    Room(int r_RoomNumber, int r_rate, int r_FloorNumber, bool r_IsOccupied)
    : roomNumber(r_RoomNumber),
    rate(r_rate),
    floorNumber(r_FloorNumber),
    isOccupied(r_IsOccupied)
    {
    }
    int getRoomNumber() const {
        return roomNumber;
    }
    void setRoomNumber(int newRoomNumber) {
        roomNumber = newRoomNumber;
    }
    int getRate() const {
        return rate;
    }
    void setRate(int newRate) {
        rate = newRate;
    }
    int getFloorNumber() const {
        return floorNumber;
    }
    void setFloorNumber(int newFloorNumber) {
        floorNumber = newFloorNumber;
    }
    bool getIsOccupied() const {
        return isOccupied;
    }
    void setIsOccupied(bool newIsOccupied) {
        isOccupied = newIsOccupied;
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
    std::string nameInput;
    std::string hotelNameInput;

    std::cout << "**********************************\n";
    std::cout << "    Welcome to Hotel Simulator   \n";
    std::cout << "**********************************\n\n";

    std::cout << "What is your name?: ";
    std::cin >> nameInput;
    std::cout << "Hello " << nameInput << "!\n\n";

    std::cout <<"What would you like to name your Hotel?: ";
    std::cin >> hotelNameInput;

    


    return 0;
}