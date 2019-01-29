#include <iostream>
#include <vector>
#include <utility>

#define NORTH 0
#define NORTHEAST 1
#define EAST 2
#define SOUTHEAST 3
#define SOUTH 4
#define SOUTHWEST 5
#define WEST 6
#define NORTHWEST 7

class Grid
{
public:

	Grid(int s)
	{
		coordinates = GenerateGrid(s);
	};
	~Grid() {};


	//int* AdjesentLocation(const int& loc, const int& dir)
	//{
		//return -1;//std::pair // use coordinate to backwards calc the position.
	//}

	void ResizeGrid(const int& s)
	{
		coordinates.size();// get square root of coordinates, then
		//int newsize = currentsize - (s*s);
	}

	int GetGridSize()
	{
		return coordinates.size(); 
	}

	void PrintGrid()
	{
		for (auto & coord : coordinates)
		{
			std::cout << coord.first << " " << coord.second << std::endl;
		}
	}

private:
	std::vector<std::pair<int, int>> coordinates; // X and Y Coordinates of each location on the grid.

	std::vector<std::pair<int, int>>& GenerateGrid(const int& s)
	{
		coordinates.resize(s * s);
		coordinates[0] = { 0, 0 };

		int inc = 1, times = 1, b = times;
		bool which = false;

		for (unsigned int i = 1; i < coordinates.size(); ++i)
		{
			if (which)	
				coordinates[i] = { coordinates[i - 1].first += inc, coordinates[i - 1].second };
			else
				coordinates[i] = { coordinates[i - 1].first, coordinates[i - 1].second += inc };

			b--;

			if (b == 0) // i == 0, 1, 2, 4, 6, 9, 12, 16, 20
			{
				if (which) // i == 0, 2, 6, 12, 20
				{
					which = false;
					inc *= -1;
					times++;
				}	
				else
					which = true;
				
				b = times;
			}
		}

		return coordinates;
	}

};

int main()
{
	Grid g(5);
	g.PrintGrid();

	std::cout << g.GetGridSize() << std::endl;
	
	//std::cout << *(g.AdjesentLocation(0, NORTH)) << std::endl;

	//g.ResizeGrid(4);

	//std::cout << g.GetGridSize() << std::endl;
	
	//std::cout << *(g.AdjesentLocation(6, NORTH)) << std::endl;

	//g.AdjesentLocation(7, NORTH);

	std::cin.get();
}