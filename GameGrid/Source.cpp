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

class SpiralGrid
{
public:

	SpiralGrid(int s)
	{
		coordinates = GenerateGrid(s);
	};
	~SpiralGrid() {};


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
		for (int i = 0; i < coordinates.size(); i++)
		{
			std::cout << i << " " <<  coordinates[i].first << " " << coordinates[i].second << std::endl;
		}
	}

	std::pair<int, int> GetCoordAtIndex(int index)
	{		
		std::pair<int, int> coord = { 0, 0 };

		
		return coord;
	}

private:
	std::vector<std::pair<int, int>> coordinates; // X and Y Coordinates of each location on the grid.

	std::vector<std::pair<int, int>>& GenerateGrid(const int& s)
	{
		coordinates.resize(s * s);
		coordinates[0] = { 0, 0 };

		int sign = 1;
		bool dir = false;

		for (unsigned int i = 1; i < coordinates.size(); ++i)
		{
			if (dir)
				coordinates[i] = { coordinates[i - 1].first += sign, coordinates[i - 1].second };
			else
				coordinates[i] = { coordinates[i - 1].first, coordinates[i - 1].second += sign };

			if (isSpiral(i)) // i == 0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30
			{
				if (isSpiral2(i)) // i == 0, 2, 6, 12, 20, 30
				{
					dir = false;
					sign *= -1;
				}	
				else
				{
					dir = true;
				}				
			}
		}

		return coordinates;
	}

	bool isSpiral(int x)
	{
		return (ceil(sqrt(4 * x)) != ceil(sqrt(4 * (x + 1))));
	}

	bool isSpiral2(int x)
	{
		return (round(sqrt(x)) != round(sqrt(x + 1)));
	}
};




int main()
{
	SpiralGrid g(11);
	g.PrintGrid();

	//std::cout << "At index 4: "<<(g.GetCoordAtIndex(4).first) << " " << (g.GetCoordAtIndex(4).second) << std::endl;

	//for (int x = 0; x < 20; x++)
	//	std::cout << ( round(pow(x,2) / 4) ) << std::endl;

	//for (int x = 0; x < 40; x++)
	//	std::cout << round(sqrt(1 * x)) << "   " << x << std::endl;

	//for (int x = 0; x < 40; x++)
	//{
	//	if (isInteger1(x))
	//		std::cout << x << std::endl;
	//}
		

	//std::cout << isPerfectSquare(12) << std::endl;


	
	//std::cout << *(g.AdjesentLocation(0, NORTH)) << std::endl;

	//g.ResizeGrid(4);

	//std::cout << g.GetGridSize() << std::endl;
	
	//std::cout << *(g.AdjesentLocation(6, NORTH)) << std::endl;

	//g.AdjesentLocation(7, NORTH);

	std::cin.get();
}