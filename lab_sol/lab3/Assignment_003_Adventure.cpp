/*
 * @Author: Wenjie, Luo
 * @Description: Adventure is a CLI game.
 * The player has to explore a castle, which consists of many rooms.
 * The task of the player is to find the room where the princess is prisoned and
 * take her leave!There are many types of rooms, and each type has distinct
 * exits. Note that there is a monster in one of the rooms, whose exact location
 * is unknown. But once the player meets the monster, the game is over. The
 * program always shows information about the room into which the player enters:
 * the name of the room, how many exits are there, and example of a room
 * image(shows where can go).
 * For example, the player go to one room, and the program outputs:
 * ```
 * Welcome to room 2. There are 2 exits.
 *  _____
 * |     |
 *       |
 * |__ __|
 * ```
 * Then the player can input the command go followed by the name of the exit
 * that he/she would like to pass through, e.g.,
 * ```
 * go west
 * ```
 * Consequently, the player goes into the room to the east. The program gives
 * the information of that room, like what is shown above for the lobby. This
 * process repeats.
 * During this process, if the player enters a room with a monster, the program
 * shows a message and game over. Likewise, once the player enters the secret
 * room where the princess is, the program shows the conversation between the
 * role and the princess. After that, she is ready to leave with the role. Then
 * the player has to find their way out. The only way to leave the castle is via
 * the lobby. and the princess is going to leave with the player. The player
 * then has to find their way out the castle. The only way to leave the castle
 * is via the lobby.
 * @Notion:
 * 1. Each room is randomly generated and its variables are not
 * initialized until after entry.
 * 2. You can return to a room you have already explored and no new rooms
 * will be created.
 * 3. The game guarantees that you will definitely find the princess before you
 * meet the monster.
 * @Data: 2022.10.27
 */

#include <time.h>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// This is the back door, uncomment it to get the location of the princess and
// the monster
// #define BACKDOOR
#define rand_range 5       // set the range of the number of rooms
#define min_room_number 5  // set the min of the number of rooms

int princess;          // where princess is in
int monster;           // where monster is in
bool findpcs = false;  // has the princess been found
int roomid = -1;       // every room has a id, the lobby's id is -1

string diecrtion[4] = {"north", "south", "west",
                       "east"};  // used to randomly set exits to rooms
map<string, int> countdir{
    {"north", 1},
    {"south", -1},
    {"west", 1},
    {"east", -1}};  // used to determine if the path forms a closed loop

class Room {
   private:
    int id;                       // room number
    string name;                  // the name of room
    map<string, Room*> nextroom;  // the four directions of the room correspond
                                  // to the positions
    int is_princess;              // is there a princess
    int is_monster;               // is there a monster

   public:
    Room();                                    // default initialization
    Room(int id);                              // initialisation for lobby
    Room(int id, string dir, Room* pre_room);  // initialisation for normal room
    ~Room();
    void print_room();        // print the room
    Room* go(string dir);     // moving in one direction
    int get_roomid();         // ge the id of room
    bool can_go(string dir);  // determine if there is an exit in this direction
    void link_room(string dir, Room* linked_room);  // connect two rooms
    int is_back(string dir);  // determine if return to a visited room
    int have_monster();       // determine if this room has monster
    int have_princess();      // determine if this room has princess
};

vector<Room*> rooms;    // store all explored rooms
stack<string> choices;  // store all Actions

int main() {
    // get a random map
    srand(time(NULL));
    int n = rand() % rand_range + min_room_number;
    princess = rand() % (n - 1) + 1;  // Avoid princesses appearing in the first
                                      // room or at the same time as monster
    monster = n;                      // Set the room where monster appear

#ifdef BACKDOOR
    cout << "n = " << n << " princess is in " << princess << " monster is in "
         << monster << endl;
#endif

    string move, dir;
    Room start(roomid++);  // Initialize the first room(lobby)

    cout << "Welcome to the Adventure! you have to save the princess." << endl;
    cout << endl;
    cout << "You are now in the lobby. Let's go! (input 'go')" << endl;
    cout << "Or you can be a deserter. (input 'leave')" << endl;
    getline(cin, move);

    // Action in lobby, don't stay here too long
    while (move != "go" || move == "leave") {
        if (move == "leave") {
            cout << "The princess is waiting for YOU, are you sure?(if so, "
                    "enter \"yes\")";
            string sign;
            getline(cin, sign);
            if (sign == "yes")
                return 0;
            else
                cout << "Regain your courage." << endl;
        } else
            cout << "Wrong command, didn't you want to save princess?" << endl;
        getline(cin, move);
    }

    // Enter the castle, begin the adventure.
    Room* room = start.go("north");
    room->print_room();
    cout << "Enter you command. (input:go 'dir')" << endl;

    // The main loop, you will be exploring the castle.
    while (room->get_roomid() != -1 || !findpcs) {
        cin >> move >> dir;
        if (move == "go" && countdir.count(dir)) {
            if (room->can_go(dir)) {
                room = room->go(dir);
                room->print_room();
                if (room->have_monster()) {
                    cout << "The monster is here! You were killed by him and "
                            "the princess has been in endless pain and torment."
                         << endl;
                    return 0;
                } else if (room->have_princess()) {
                    cout << "You find the princess! Get out of the castle soon!"
                         << endl;
                    findpcs = true;
                }
            } else
                cout << "There is no room, find another way." << endl;
            if (room->get_roomid() != -1 || !findpcs)
                cout << "Enter you command. (input:go 'dir')" << endl;
        } else if (move == "quit" || move == "q" || move == "Q") {
            return 0;
        } else {
            cout << "Illegaly input!" << endl;
            cout << "Please input again." << endl;
        }
    }
    cout << "Congratulations! From then on, you and the princess lived happily "
            "ever after."
         << endl;
    return 0;
}

Room::Room(int id) {
    this->id = id;
    name = "the lobby";
    is_princess = 0;
    is_monster = 0;
    rooms.push_back(this);
}

Room::Room(int id, string dir, Room* pre_room) {
    this->id = id;
    is_princess = (this->id == princess);
    is_monster = (this->id == monster);
    if (is_princess) {
        name = "the secret room";
        roomid--;
        princess = -2;
    } else if (is_monster) {
        name = "the scary room";
        roomid--;
        monster = -2;
    } else
        name = "room " + to_string(id);
    int have = -1;  // Make sure this room has at least one exit
    for (int i = 0; i < 4; i++) {
        int x = rand() % 2;  // Randomly assign exits to rooms
        if (x) {
            nextroom[diecrtion[i]] = nullptr;
            have++;
        }
    }
    // If this room does not already have an exit, then actively assign to it.
    if (have < 1) {
        int x = rand() % 3;
        nextroom[diecrtion[x]] = nullptr;
        nextroom[diecrtion[x + 1]] = nullptr;
    }
    // Connect the newly created room to the previous room
    link_room(dir, pre_room);
}

Room::~Room() {}

void Room::link_room(string dir, Room* linking_room) {
    // Connecting two houses by assigning pointers to their nextroom
    if (dir == "north") {
        nextroom["south"] = linking_room;
        linking_room->nextroom["north"] = this;
    } else if (dir == "south") {
        nextroom["north"] = linking_room;
        linking_room->nextroom["south"] = this;
    } else if (dir == "west") {
        nextroom["east"] = linking_room;
        linking_room->nextroom["west"] = this;
    } else if (dir == "east") {
        nextroom["west"] = linking_room;
        linking_room->nextroom["east"] = this;
    }
}

int Room::have_monster() {
    return is_monster;
};

int Room::have_princess() {
    return is_princess;
};

void Room::print_room() {
    cout << endl << "Welcome to " << name << ". ";
    if (id != -1) {  // If went to a normal room, output the number of exits
                     // in the room
        cout << "There are " << nextroom.size()
             << ((nextroom.size() == 1) ? " exit." : " exits.") << endl;
    } else if (!findpcs) {  // If went to lobby but haven't find princess
        cout << "Why are you back? Go and save the princess, now!" << endl;
    } else
        cout << endl;
    // Print images of the room
    cout << " __" << (can_go("north") ? " " : "_") << "__ " << endl;
    cout << "|     |" << endl;
    cout << (can_go("west") ? "   " : "|  ")
         << (is_princess ? "P" : (is_monster ? "M" : " "))
         << (can_go("east") ? "   " : "  |") << endl;
    cout << "|__" << (can_go("south") ? " " : "_") << "__|" << endl;
}

int Room::get_roomid() {
    return id;
}

bool Room::can_go(string dir) {
    return nextroom.count(dir) ? true : false;
}

int Room::is_back(string dir) {
    stack<string> c = choices;
    int row = 0;
    int column = 0;
    int count = 1;
    if (dir == "north" || dir == "south")
        row += countdir[dir];
    else
        column += countdir[dir];
    // Iterate until you find that past path form a closed loop
    while (!c.empty()) {
        count++;
        // Get the last action.
        string choice = c.top();
        c.pop();
        if (choice == "north" || choice == "south") {
            row += countdir[choice];
        } else {
            column += countdir[choice];
        }
        if (row == 0 && column == 0)
            return count;
    }
    return 0;
}

Room* Room::go(string dir) {
    // If you come to a visited room, return the pointer to that room.
    // Otherwise, create a new room and return a pointer to it.
    int count = 0;
    if (count = is_back(dir)) {
        (*(rooms.end() - count))->link_room(dir, this);
        // Store this room and your action.
        choices.push(dir);
        rooms.push_back(*(rooms.end() - count));
        return *(rooms.end() - count - 1);
    } else {
        Room* newroom = new Room(roomid++, dir, this);
        // Store this room and your action.
        choices.push(dir);
        rooms.push_back(newroom);
        return newroom;
    }
}