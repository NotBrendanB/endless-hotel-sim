#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
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
    Occupant* currentOccupant = nullptr;
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
        return currentOccupant != nullptr;
    }
    void setOccupant(Occupant* person) {
        currentOccupant = person;
    }
    void removeOccupant() {
        currentOccupant = nullptr; 
    }
    Occupant* getOccupant() const {
        return currentOccupant;
    }
};
/* CLASSES + METHODS
    occupants - stay duration, name
    rooms - room #, rate, floor #, isOccupied
    floors - number
    player - dollars, name, age

*/
std::vector<Room> createStartRooms();
void drawHotel(const std::vector<std::vector<Room>>& hotelState);
void spawnGuests(std::vector<std::vector<Room>>& rooms);
void newday(std::vector<std::vector<Room>>& rooms, Player& player);
void performUpgrades(std::vector<std::vector<Room>>& rooms, Player& player);
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
    int ageInput;
    int roomNumberInput;

    std::cout << "**********************************\n";
    std::cout << "    Welcome to Hotel Simulator   \n";
    std::cout << "**********************************\n\n";

    std::cout << "What is your name?: ";
    std::cin >> nameInput;
    std::cout << "How old are you?: ";
    std::cin >> ageInput;
    Player mainPlayer(0, nameInput, ageInput);
    std::cout << "Hello " << nameInput << "!\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout <<"What would you like to name your Hotel?: ";
    std::cin >> hotelNameInput;
    
    Floor startingFloor(1, 5);
    std::vector<std::vector<Room>> roomList;
    std::vector<Room> firstFloor = createStartRooms();
    roomList.push_back(firstFloor);
    
    

    std::cout << nameInput << " is now the proud owner of " << hotelNameInput << " Hotel!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "It features " << startingFloor.getNumberFloors() << " floor and " << startingFloor.getNumberRooms() << " rooms.\n\n";
    std::cout << "**********************************\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));


    std::cout << "Guests will spawn everyday and it is now up to you to run the " << hotelNameInput << " Hotel!\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "It is your job to assign them to a room and perform upgrades to the hotel.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Good Luck!\n\n";
    std::cout << "**********************************\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));


    std::cout << "Here is the current state of your hotel!\n";
    drawHotel(roomList);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "\nHere is your first guest!\n";
    Occupant* tutorialGuy = new Occupant("Brendan", 3);
    std::cout << "Guest Name: " << tutorialGuy->getName() << '\n';
    std::cout << "Stay Duration: " << tutorialGuy->getStayDuration() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nWhich room would you like " << tutorialGuy->getName() << " to stay in?: ";
    std::cin >> roomNumberInput;
    for(int i = 0; i < roomList.size(); i++) {
        for(int j = 0; j < roomList[i].size(); j++) {
            if (roomList[i][j].getRoomNumber() == roomNumberInput) {
                roomList[i][j].setOccupant(tutorialGuy);
                std::cout << "Congratulations! Room " << roomNumberInput << " is now occupied by " << tutorialGuy->getName() << '\n';
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nYou can figure the rest of the game out, have fun!\n";
    std::cout << "**********************************\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    int day = 1;
    while (true) {
        std::cout << "Current Hotel State -> \n";
        drawHotel(roomList);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        spawnGuests(roomList);
        newday(roomList, mainPlayer);
        performUpgrades(roomList, mainPlayer);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Day " << day << ": You now have $" << mainPlayer.getMoney() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\n**********************************\n";
        day++;
    }
    return 0;
}
std::vector<Room> createStartRooms() {
    std::vector<Room> rooms;
    rooms.push_back(std::move(Room(101, 120, 1, false)));
    rooms.push_back(std::move(Room(102, 120, 1, false)));
    rooms.push_back(std::move(Room(103, 120, 1, false)));
    rooms.push_back(std::move(Room(104, 120, 1, false)));
    rooms.push_back(std::move(Room(105, 120, 1, false)));
    return rooms;
}
void drawHotel(const std::vector<std::vector<Room>>& hotelState) {
    for (int i = hotelState.size() - 1; i >= 0; i--) {
        std::cout << std::string(hotelState[i].size() * 8, '-') << "\n";
        for (int j = 0; j < hotelState[i].size(); j++) {
            if (hotelState[i][j].getOccupant() == nullptr) {
                std::cout << "|" << hotelState[i][j].getRoomNumber() << "|";
            } else {
                Occupant* occ = hotelState[i][j].getOccupant();
                std::cout << "|" << occ->getName() << "|";
            }
        }
        std::cout <<'\n'<<std::string(hotelState[i].size() * 8, '-') << "\n";
    }
}
void spawnGuests(std::vector<std::vector<Room>>& rooms) {
    /*
        Create Occupant Objects, ask where to put, check if occupied, if -> prompt again, not -> assign to room
        can happen variable amount of times per day but player can always deny room placement
    */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::string guestNames[] = {"James Smith", "Olivia Johnson", "Liam Williams", "Emma Brown", "Noah Jones", 
    "Ava Garcia", "Oliver Miller", "Sophia Davis", "Elijah Rodriguez", "Isabella Martinez", 
    "Lucas Hernandez", "Mia Lopez", "Mason Gonzalez", "Charlotte Wilson", "Logan Anderson", 
    "Amelia Thomas", "Ethan Taylor", "Harper Moore", "Jackson Jackson", "Evelyn Martin", 
    "Sebastian Lee", "Abigail Perez", "Alexander Thompson", "Emily White", "Aiden Harris", 
    "Elizabeth Sanchez", "Matthew Clark", "Sofia Ramirez", "Samuel Lewis", "Avery Robinson", 
    "David Walker", "Elena Young", "Joseph Allen", "Madison King", "Carter Wright", 
    "Layla Scott", "Owen Torres", "Victoria Nguyen", "Wyatt Hill", "Chloe Flores", 
    "John Green", "Grace Adams", "Jack Nelson", "Zoey Baker", "Luke Hall", 
    "Penelope Rivera", "Dylan Campbell", "Riley Mitchell", "Levi Carter", "Lily Roberts"
    };
    std::uniform_int_distribution<> distr(0, sizeof(guestNames)/sizeof(guestNames[0]) - 1);
    int randomNameIndex = distr(gen);
    std::uniform_int_distribution<> stayDistr(1, 9);
    int randomStayIndex = stayDistr(gen);

    Occupant* guest = new Occupant(guestNames[randomNameIndex], randomStayIndex);

    std::cout << "Guest Name: " << guest->getName() << '\n';
    std::cout << "Stay Duration: " << guest->getStayDuration() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));

    bool validRoomNumber = true;
    while(validRoomNumber) {
        std::cout << "\nWhich room would you like " << guest->getName() << " to stay in?(Enter 0 to deny customer): ";
        int roomNumberInput;
        std::cin >> roomNumberInput;
        if (roomNumberInput == 0) {
            std::cout << "You denied " << guest->getName() << " a room for the night.";
            delete guest;
            validRoomNumber = true;
            break;
        }
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j].getRoomNumber() == roomNumberInput && !rooms[i][j].getIsOccupied()) {
                    rooms[i][j].setOccupant(guest);
                    std::cout << "Congratulations! Room " << roomNumberInput << " is now occupied by " << guest->getName() << '\n';
                    validRoomNumber = false;
                }
            }
        }
    }
        
    std::cout << "\n**********************************\n\n";
}
void performUpgrades(std::vector<std::vector<Room>>& rooms, Player& player) {
    /*
    Ask if they would like to get a new room

    if the floor has less than 5 rooms, create new room on floor
    otherwise create new room on new floor

    need a way to keep track of room cost on each floor, increment by 20$
    need a way to keep track of room number for room creation
    */
    char input;
    std::cout << "Would you like to construct a new room? It does cost money!: (y/n)";
    std::cin >> input;
    if (input == 'n') {
    } else {
        int lastFloorIdx = rooms.size() - 1;
        int roomsLastFloor = rooms[lastFloorIdx].size();
        if (roomsLastFloor < 5) {
            if (player.getMoney() >= 1000 * (lastFloorIdx + 1)) {
                rooms[lastFloorIdx].push_back(Room((lastFloorIdx + 1) * 100 + roomsLastFloor + 1, (lastFloorIdx + 1) * 100 + 20, lastFloorIdx + 1, false));
                player.setMoney(player.getMoney() - 1000 * (lastFloorIdx + 1));
            } else {
                std::cout << "Insufficient Funds!\n";
            }
        } else {
            if (player.getMoney() >= 1000 * (lastFloorIdx + 2)) {
                std::vector<Room> newFloor;
                newFloor.push_back(Room((lastFloorIdx + 2) * 100 + 1, (lastFloorIdx + 2) * 100 + 20, lastFloorIdx + 2, false));
                rooms.push_back(newFloor);
                player.setMoney(player.getMoney() - 1000 * (lastFloorIdx + 2));
            } else {
                std::cout << "Insufficient Funds!\n";
            }
        }
    }
}


void newday(std::vector<std::vector<Room>>& rooms, Player& player) {
/*
    collect money, update money, decrement roomdurations, update isoccupied
    draw hotel

    go through rooms, look at occupant, if stayduration > 1 -> decrement, look at room rate and add to player money, otherwise, remove occupant and checkout -> remove from guestlist
*/
    
    for(int i = 0; i < rooms.size(); i++) {
        for(int j = 0; j < rooms[i].size(); j++) {
            Occupant* guest = rooms[i][j].getOccupant();
            if (guest != nullptr) {
                if (guest->getStayDuration() > 1) {
                    guest->setStayDuration(guest->getStayDuration() - 1);
                    player.setMoney(player.getMoney() + rooms[i][j].getRate());
                } else {
                    std::cout << guest->getName() << " is checking out of room " << rooms[i][j].getRoomNumber() << '\n';
                    rooms[i][j].removeOccupant();
                    delete guest;
                }
            }
        }
    }
}