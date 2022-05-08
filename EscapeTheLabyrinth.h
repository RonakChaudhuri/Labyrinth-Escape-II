#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Ronak Chaudhuri";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "SSSNNEESSWENNESS";
const string kPathOutOfTwistyMaze = "WEENESSENSEW";

/* This function checks current position, changes boolean value if item is
   found at current position */
void updateBools(MazeCell *curr, bool &potion, bool &book, bool &wand) {
    if(curr->whatsHere == "Potion") {
        potion = true;
    } else if(curr->whatsHere == "Spellbook") {
        book = true;
    } else if(curr->whatsHere == "Wand") {
        wand = true;
    }
}
/* This function loops through moves string parameter, returns valse if non
   non valid char is found. Then for each direction char in moves, it updates
   the current pointer to move in that direction. After that, if curr points
   to a nullpointer, the function returns false. After each iteration, it checks
   to see if there is an item at that spot, and once all three items are found
   the function will return true. */
bool isPathToFreedom(MazeCell *start, const string& moves) {
    MazeCell *curr = start;
    bool potion = false; bool book = false;
    bool wand = false; bool found = false;
    updateBools(curr, potion, book, wand);
    for(int i = 0; i < moves.size(); i++) {
        if(moves.at(i) != 'N' && moves.at(i) != 'S' && moves.at(i) != 'E' &&
           moves.at(i) != 'W') {
            return false;
        }
        if(moves.at(i) == 'N') {
            curr = curr->north;
        } else if(moves.at(i) == 'S') {
            curr = curr->south;
        } else if(moves.at(i) == 'E') {
            curr = curr->east;
        } else if(moves.at(i) == 'W') {
            curr = curr->west;
        }
        if(curr == nullptr) {
            return false;
        }
        updateBools(curr, potion, book, wand);
        if(potion && book && wand) {
            found = true;
        }
    }
    return found;
}
