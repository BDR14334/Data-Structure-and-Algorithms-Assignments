#include <iostream>
#include <ctime>
#include <cassert>
#include "Map.h"
#include "Tracker.h"


using namespace std;

int main()
{
    //create a map from a file
    Map* p_map = new Map("C:/Users/brand/Documents/txt/6x6.txt");

    //create a tracker capable of traversing through a map
    Tracker* p_tracker = new Tracker;

    //send the tracker to find a path through the map
    p_tracker->findPath(p_map);

    //print the original cells from the file
    p_map->printCells();

    ////print an X/O map from the start to the end
    p_map->printRoute();

    ////I would never forget to delete these!
    //delete p_map;
    //delete p_tracker;

    return 0;
}