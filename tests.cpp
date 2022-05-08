#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"


TEST(grid, defaultConstructor){
Grid<int> g1;
ASSERT_EQ(g1.size(),16);
ASSERT_EQ(g1.numrows(), 4);
ASSERT_EQ(g1.numcols(0),4);
ASSERT_EQ(g1.numcols(1),4);
ASSERT_EQ(g1.numcols(2),4);
ASSERT_EQ(g1.numcols(3),4);
ASSERT_EQ(g1(2,3), 0);
EXPECT_ANY_THROW(g1(1,5));
g1(2,3) = 3;
ASSERT_EQ(g1(2,3), 3);
Grid<char> g2;
ASSERT_EQ(g2.size(),16);
ASSERT_EQ(g2.numrows(), 4);
ASSERT_EQ(g2.numcols(0),4);
ASSERT_EQ(g2.numcols(1),4);
ASSERT_EQ(g2.numcols(2),4);
ASSERT_EQ(g2.numcols(3),4);
EXPECT_ANY_THROW(g2(1,5));
Grid<string> g3;
ASSERT_EQ(g3.size(),16);
ASSERT_EQ(g3.numrows(), 4);
ASSERT_EQ(g3.numcols(0),4);
ASSERT_EQ(g3.numcols(1),4);
ASSERT_EQ(g3.numcols(2),4);
ASSERT_EQ(g3.numcols(3),4);
EXPECT_ANY_THROW(g3(1,5));
Grid<bool> g4;
ASSERT_EQ(g4.size(),16);
ASSERT_EQ(g4.numrows(), 4);
ASSERT_EQ(g4.numcols(0),4);
ASSERT_EQ(g4.numcols(1),4);
ASSERT_EQ(g4.numcols(2),4);
ASSERT_EQ(g4.numcols(3),4);
EXPECT_ANY_THROW(g4(1,5));
Grid<double> g5;
ASSERT_EQ(g5.size(),16);
ASSERT_EQ(g5.numrows(), 4);
ASSERT_EQ(g5.numcols(0),4);
ASSERT_EQ(g5.numcols(1),4);
ASSERT_EQ(g5.numcols(2),4);
ASSERT_EQ(g5.numcols(3),4);
EXPECT_ANY_THROW(g5(1,5));
Grid<float> g6;
ASSERT_EQ(g6.size(),16);
ASSERT_EQ(g6.numrows(), 4);
ASSERT_EQ(g6.numcols(0),4);
ASSERT_EQ(g6.numcols(1),4);
ASSERT_EQ(g6.numcols(2),4);
ASSERT_EQ(g6.numcols(3),4);
EXPECT_ANY_THROW(g6(1,5));
Grid<int> g7(g1);
ASSERT_EQ(g7.size(),16);
ASSERT_EQ(g7.numrows(), 4);
ASSERT_EQ(g7.numcols(0),4);
ASSERT_EQ(g7.numcols(1),4);
ASSERT_EQ(g7.numcols(2),4);
ASSERT_EQ(g7.numcols(3),4);
ASSERT_EQ(g7(1,3), 0);
EXPECT_ANY_THROW(g7(1,5));
g7(1,3) = 10;
ASSERT_EQ(g7(1,3), 10);
ASSERT_EQ(g1(1,3), 0);
EXPECT_ANY_THROW(g7(1,4));
Grid<int> g8;
g8 = g7;
ASSERT_EQ(g8.numrows(), 4);
ASSERT_EQ(g8(1,3), 10);
ASSERT_EQ(g8.numcols(0),4);
ASSERT_EQ(g8.numcols(1),4);
ASSERT_EQ(g8.numcols(2),4);
ASSERT_EQ(g8.numcols(3),4);
ASSERT_EQ(g8(1,3), 10);
EXPECT_ANY_THROW(g8(1,5));
g8(1,3) = 9;
ASSERT_EQ(g8(1,3), 9);
ASSERT_EQ(g7(1,3), 10);
ASSERT_EQ(g1(1,3), 0);
EXPECT_ANY_THROW(g7(1,4));
EXPECT_ANY_THROW(g7(1,5));
EXPECT_ANY_THROW(g7(1,6));
EXPECT_ANY_THROW(g7(1,7));
EXPECT_ANY_THROW(g7(1,8));
EXPECT_ANY_THROW(g7(1,9));
EXPECT_ANY_THROW(g7(1,10));
EXPECT_ANY_THROW(g7(1,11));
EXPECT_ANY_THROW(g7(-5,-5));
EXPECT_ANY_THROW(g7(-2,-3));
EXPECT_ANY_THROW(g7(-10,-8));
EXPECT_ANY_THROW(g7(7,-3));
EXPECT_ANY_THROW(g7(11,-2));
EXPECT_ANY_THROW(g7(0,-3));
EXPECT_ANY_THROW(g7(-3,4));
EXPECT_ANY_THROW(g7(-5,0));
EXPECT_ANY_THROW(g7(0,5));
EXPECT_ANY_THROW(g7(-2,-4));
EXPECT_ANY_THROW(g7(-1,-5));
EXPECT_ANY_THROW(g7(2,-4));
EXPECT_ANY_THROW(g7(0,5));
ASSERT_EQ(g1(0,0), 0);
ASSERT_EQ(g1(0,1), 0);
ASSERT_EQ(g1(0,2), 0);
ASSERT_EQ(g1(0,3), 0);
ASSERT_EQ(g1(1,0), 0);
ASSERT_EQ(g1(2,0), 0);
ASSERT_EQ(g1(3,0), 0);
ASSERT_EQ(g1(1,1), 0);
ASSERT_EQ(g1(2,1), 0);
ASSERT_EQ(g1(3,1), 0);
ASSERT_EQ(g1(2,2), 0);
ASSERT_EQ(g1(3,2), 0);
ASSERT_EQ(g2(0,0), '\0');
ASSERT_EQ(g2(0,1), '\0');
ASSERT_EQ(g2(0,2), '\0');
ASSERT_EQ(g2(0,3), '\0');
ASSERT_EQ(g2(1,0), '\0');
ASSERT_EQ(g3(2,0), "");
ASSERT_EQ(g3(3,0), "");
ASSERT_EQ(g3(1,1), "");
ASSERT_EQ(g3(2,1), "");
ASSERT_EQ(g5(3,1), 0.0);
ASSERT_EQ(g5(2,2), 0.0);
ASSERT_EQ(g5(3,2), 0.0);

}

TEST(grid, paramConstructor) {
Grid<int> g1(5,5);
ASSERT_EQ(g1.size(),25);
ASSERT_EQ(g1.numrows(), 5);
ASSERT_EQ(g1.numcols(0),5);
ASSERT_EQ(g1.numcols(1),5);
ASSERT_EQ(g1.numcols(2),5);
ASSERT_EQ(g1.numcols(3),5);
EXPECT_ANY_THROW(g1(1,5));
ASSERT_EQ(g1(2,3), 0);
g1(2,3) = 3;
ASSERT_EQ(g1(2,3), 3);
Grid<char> g2(5,6);
ASSERT_EQ(g2.size(),30);
ASSERT_EQ(g2.numrows(), 5);
ASSERT_EQ(g2.numcols(0),6);
ASSERT_EQ(g2.numcols(1),6);
ASSERT_EQ(g2.numcols(2),6);
ASSERT_EQ(g2.numcols(3),6);
EXPECT_ANY_THROW(g1(1,6));
Grid<string> g3(1,1);
ASSERT_EQ(g3.size(),1);
ASSERT_EQ(g3.numrows(), 1);
ASSERT_EQ(g3.numcols(0),1);
EXPECT_ANY_THROW(g1(1,5));
Grid<bool> g4(2,1);
ASSERT_EQ(g4.size(),2);
ASSERT_EQ(g4.numrows(), 2);
ASSERT_EQ(g4.numcols(0),1);
ASSERT_EQ(g4.numcols(1),1);
EXPECT_ANY_THROW(g1(1,5));
Grid<double> g5(3,6);
ASSERT_EQ(g5.size(),18);
ASSERT_EQ(g5.numrows(), 3);
ASSERT_EQ(g5.numcols(0),6);
ASSERT_EQ(g5.numcols(1),6);
ASSERT_EQ(g5.numcols(2),6);
EXPECT_ANY_THROW(g1(1,7));
Grid<float> g6(0,0);
ASSERT_EQ(g6.size(),0);
ASSERT_EQ(g6.numrows(), 0);
EXPECT_ANY_THROW(g1(1,5));
Grid<int> g7(g1);
ASSERT_EQ(g7.size(),25);
ASSERT_EQ(g7.numrows(), 5);
ASSERT_EQ(g7.numcols(0),5);
ASSERT_EQ(g7.numcols(1),5);
ASSERT_EQ(g7.numcols(2),5);
ASSERT_EQ(g7.numcols(3),5);
ASSERT_EQ(g7(1,3), 0);
EXPECT_ANY_THROW(g1(1,6));
g7(1,3) = 10;
ASSERT_EQ(g7(1,3), 10);
ASSERT_EQ(g1(1,3), 0);
EXPECT_ANY_THROW(g7(1,5));
Grid<int> g8;
g8 = g7;
ASSERT_EQ(g8.numrows(), 5);
ASSERT_EQ(g8(1,3), 10);
ASSERT_EQ(g8.numcols(0),5);
ASSERT_EQ(g8.numcols(1),5);
ASSERT_EQ(g8.numcols(2),5);
ASSERT_EQ(g8.numcols(3),5);
ASSERT_EQ(g8(1,3), 10);
EXPECT_ANY_THROW(g8(1,5));
g8(1,3) = 9;
ASSERT_EQ(g8(1,3), 9);
ASSERT_EQ(g7(1,3), 10);
ASSERT_EQ(g1(1,3), 0);
EXPECT_ANY_THROW(g8(1,5));
EXPECT_ANY_THROW(g7(1,5));
EXPECT_ANY_THROW(g7(1,6));
EXPECT_ANY_THROW(g7(1,7));
EXPECT_ANY_THROW(g7(1,8));
EXPECT_ANY_THROW(g7(1,9));
EXPECT_ANY_THROW(g7(1,10));
EXPECT_ANY_THROW(g7(1,11));
EXPECT_ANY_THROW(g7(-5,-5));
EXPECT_ANY_THROW(g7(-2,-3));
EXPECT_ANY_THROW(g7(-10,-8));
EXPECT_ANY_THROW(g7(7,-3));
EXPECT_ANY_THROW(g7(11,-2));
EXPECT_ANY_THROW(g7(0,-3));
EXPECT_ANY_THROW(g7(-3,4));
EXPECT_ANY_THROW(g7(-5,0));
EXPECT_ANY_THROW(g7(0,5));
EXPECT_ANY_THROW(g7(-2,-4));
EXPECT_ANY_THROW(g7(-1,-5));
EXPECT_ANY_THROW(g7(2,-4));
EXPECT_ANY_THROW(g7(0,5));
ASSERT_EQ(g1(0,0), 0);
ASSERT_EQ(g1(0,1), 0);
ASSERT_EQ(g1(0,2), 0);
ASSERT_EQ(g1(0,3), 0);
ASSERT_EQ(g1(1,0), 0);
ASSERT_EQ(g1(2,0), 0);
ASSERT_EQ(g1(3,0), 0);
ASSERT_EQ(g1(1,1), 0);
ASSERT_EQ(g1(2,1), 0);
ASSERT_EQ(g1(3,1), 0);
ASSERT_EQ(g1(2,2), 0);
ASSERT_EQ(g1(3,2), 0);
ASSERT_EQ(g2(0,0), '\0');
ASSERT_EQ(g2(0,1), '\0');
ASSERT_EQ(g2(0,2), '\0');
ASSERT_EQ(g2(0,3), '\0');
ASSERT_EQ(g2(1,0), '\0');
ASSERT_EQ(g3(0,0), "");
ASSERT_EQ(g5(2,1), 0.0);
ASSERT_EQ(g5(2,2), 0.0);
ASSERT_EQ(g5(0,2), 0.0);
}

//// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
vector<string> textMaze;

textMaze.push_back("* *-W *");
textMaze.push_back("| |   |");
textMaze.push_back("*-* * *");
textMaze.push_back("  | | |");
textMaze.push_back("S *-*-*");
textMaze.push_back("|   | |");
textMaze.push_back("*-*-* P");

Maze m(textMaze);

MazeCell* start = m.getStart(2, 2);

/* These paths are the ones in the handout. They all work. */
EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

/* These paths don't work, since they don't pick up all items. */
EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

/* These paths don't work, since they aren't legal paths. */
EXPECT_FALSE(isPathToFreedom(start, "WW"));
EXPECT_FALSE(isPathToFreedom(start, "NN"));
EXPECT_FALSE(isPathToFreedom(start, "EE"));
EXPECT_FALSE(isPathToFreedom(start, "SS"));
}
//
//// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
vector<string> textMaze;

textMaze.push_back("* S *");
textMaze.push_back("     ");
textMaze.push_back("W * P");
textMaze.push_back( "     ");
textMaze.push_back( "* * *");

Maze m(textMaze);

MazeCell* start = m.getStart(1, 1);

EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}
//
//// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
vector<string> textMaze;

textMaze.push_back("P-S-W");

Maze m(textMaze);
MazeCell* start = m.getStart(0, 0);

EXPECT_TRUE(isPathToFreedom(start, "EE"));
start = m.getStart(0, 1);
EXPECT_TRUE(isPathToFreedom(start, "WEE"));
start = m.getStart(0, 2);
EXPECT_TRUE(isPathToFreedom(start, "WW"));

}
//
//// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
vector<string> textMaze;

textMaze.push_back("* *-W *");
textMaze.push_back("| |   |");
textMaze.push_back("*-* * *");
textMaze.push_back("  | | |");
textMaze.push_back("S *-*-*");
textMaze.push_back("|   | |");
textMaze.push_back("*-*-* P");

Maze m(textMaze);
MazeCell* start = m.getStart(0, 0);

/* These paths contain characters that aren't even close to permissible. */
EXPECT_FALSE(isPathToFreedom(start, "Q"));
EXPECT_FALSE(isPathToFreedom(start, "X"));
EXPECT_FALSE(isPathToFreedom(start, "!"));
EXPECT_FALSE(isPathToFreedom(start, "?"));

EXPECT_FALSE(isPathToFreedom(start, "n"));
EXPECT_FALSE(isPathToFreedom(start, "s"));
EXPECT_FALSE(isPathToFreedom(start, "e"));
EXPECT_FALSE(isPathToFreedom(start, "w"));

///* These are tricky - they're legal paths that happen to have an unexpected
// * character at the end.
start = m.getStart(2, 2);
EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

}

TEST(maze, other) {
vector<string> textMaze;

textMaze.push_back("* *-W *");
textMaze.push_back("| |   |");
textMaze.push_back("*-* * *");
textMaze.push_back("  | | |");
textMaze.push_back("S *-*-*");
textMaze.push_back("|   | |");
textMaze.push_back("*-*-* P");

Maze m(textMaze);
MazeCell* start = m.getStart(0, 0);

EXPECT_FALSE(isPathToFreedom(start, "Z"));
EXPECT_FALSE(isPathToFreedom(start, "@"));
EXPECT_FALSE(isPathToFreedom(start, "^"));
EXPECT_FALSE(isPathToFreedom(start, "B"));

EXPECT_FALSE(isPathToFreedom(start, "NW"));
EXPECT_FALSE(isPathToFreedom(start, "SE"));
EXPECT_FALSE(isPathToFreedom(start, "EN"));
EXPECT_FALSE(isPathToFreedom(start, "WE"));

start = m.getStart(2, 3);
EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWN#Y^"));
EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES***"));
EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENESYNSEN"));

}

TEST(maze, other2) {
vector<string> textMaze;

textMaze.push_back("* *-W *");
textMaze.push_back("| |   |");
textMaze.push_back("*-* * *");
textMaze.push_back("  | | |");
textMaze.push_back("S *-*-*");
textMaze.push_back("|   | |");
textMaze.push_back("*-*-* P");

Maze m(textMaze);

MazeCell* start = m.getStart(1, 1);

EXPECT_TRUE(isPathToFreedom(start, "NEWSSEESNWSWWN"));
EXPECT_TRUE(isPathToFreedom(start, "SEESNWSWWNSEENWNNE"));
EXPECT_TRUE(isPathToFreedom(start, "SESWWNSEENESNWWNNE"));

EXPECT_FALSE(isPathToFreedom(start, "WNSE"));
EXPECT_FALSE(isPathToFreedom(start, "NE"));
EXPECT_FALSE(isPathToFreedom(start, "SESWWN"));

EXPECT_FALSE(isPathToFreedom(start, "E"));
EXPECT_FALSE(isPathToFreedom(start, "EE"));
EXPECT_FALSE(isPathToFreedom(start, "SS"));
EXPECT_FALSE(isPathToFreedom(start, "NN"));
}
//
//// Provided Test: This tests your personalized regular maze to see if you were
//// able to escape.
TEST(maze, escapeRegularMaze) {
Maze m(4, 4);
MazeCell* start = m.mazeFor(kYourName);
EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}

//// Provided Test: This tests your personalized twisty maze to see if you were
//// able to escape.
TEST(maze, escapeTwistyMaze) {
Maze m(4, 4);
MazeCell* start = m.twistyMazeFor(kYourName);
EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

