#include <stdexcept>
#include <iostream>
#include <vector>

class Platformer 
{
public:
    Platformer(int n, int position) : _n(n), _position(position) {}

    std::vector<int> tileVector()
    {
        std::vector<int> tile_v(_n, 1);                         // create a tile vector and make all elements equal to one
        if (_n <= 0)
            throw std::logic_error("Waiting to be implemented");
        
        return tile_v;
    }
    
    void jumpLeft() 
    {
        platform[_position] = 0;                                // set position to zero (to indicate we've been there)
        int leftTile = _position - 2;                           // jump left two tiles
        while (leftTile >= 0)                                   // if we are still on the tiles (i.e. in the tile vector) then go ahead
        {
            if (platform[leftTile] == 1)                        // if we haven't been to this tile before (it's not a hole) then go ahead and act on it
            {
                platform[leftTile] = 0;                         // set the new location to zero indicating that we are here
                _position = leftTile;                           // adjust to the new position
                break;                                          // get out of this loop
            }
            if (platform[leftTile] == 0)
                leftTile = leftTile + 1;
        }
        if (leftTile >= _n)
            throw std::logic_error("There are no Left tiles to move to!"); // ran out of platform to work with
    }

    void jumpRight() 
    {
        platform[_position] = 0;                                // set position to zero (to indicate we've been there)
        int rightTile = _position + 2;                          // jump right two tiles
        while (rightTile <= _n - 1)                             // if we are still on the tiles (i.e. in the tile vector) then go ahead
        {
            if (platform[rightTile] == 1)                       // if we haven't been to this tile before (it's not a hole) then go ahead and act on it
            {
                platform[rightTile] = 0;                        // set the new location to zero indicating that we are here
                _position = rightTile;                          // adjust to the new position
                break;                                          // get out of this loop
            }
            if (platform[rightTile] == 0)
                rightTile = rightTile + 1;
        }
        if (rightTile >= _n)
            throw std::logic_error("There are no Right tiles to move to!"); // ran out of platform to work with
    }

    int position() 
    {
        return _position;
    }

private:
    int _n;
    int _position;
    std::vector<int> platform = tileVector();
};

#ifndef RunTests
int main()
{
    Platformer platformer(6, 3);
    std::cout << platformer.position() << std::endl; // should print 3

    platformer.jumpLeft();
    std::cout << platformer.position() << std::endl; // should print 1

    platformer.jumpRight();
    std::cout << platformer.position() << std::endl; // should print 4
}
#endif