#include "Tracker.h"

Tracker::Tracker()
{
	p_currentCell = 0;

}

Tracker::~Tracker()
{
	delete p_currentCell;
}

void Tracker::findPath(Map* p_map)
{
	
	Cell* p_new;
	p_new = p_map->getStartCell();
	p_currentCell = p_new;
	onPathCells.push(p_currentCell);
	p_currentCell->setHasBeenVisited(true);
	p_currentCell->setOnPath(true);

	while (true)
	{
		if (p_currentCell->getType() == 'E')
		{
			break;
		}
		
		p_new = p_map->getNorth(p_currentCell);

		if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
		{
			p_currentCell = p_new;
			onPathCells.push(p_currentCell);
			p_currentCell->setHasBeenVisited(true);
			//p_currentCell->setOnPath(true);
			
		}
		else
		{
			p_new = p_map->getNorthEast(p_currentCell);
			if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
			{
				p_currentCell = p_new;
				onPathCells.push(p_currentCell);
				p_currentCell->setHasBeenVisited(true);
				//p_currentCell->setOnPath(true);
			}
			else
			{
				p_new = p_map->getEast(p_currentCell);
				if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
				{
					p_currentCell = p_new;
					onPathCells.push(p_currentCell);
					p_currentCell->setHasBeenVisited(true);
					//p_currentCell->setOnPath(true);
				}
				else
				{
					p_new = p_map->getSouthEast(p_currentCell);
					if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
					{
						p_currentCell = p_new;
						onPathCells.push(p_currentCell);
						p_currentCell->setHasBeenVisited(true);
						//p_currentCell->setOnPath(true);
					}
					else
					{
						p_new = p_map->getSouth(p_currentCell);
						if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
						{
							p_currentCell = p_new;
							onPathCells.push(p_currentCell);
							p_currentCell->setHasBeenVisited(true);
							//p_currentCell->setOnPath(true);
						}
						else
						{
							p_new = p_map->getSouthWest(p_currentCell);
							if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
							{
								p_currentCell = p_new;
								onPathCells.push(p_currentCell);
								p_currentCell->setHasBeenVisited(true);
								//p_currentCell->setOnPath(true);
							}
							else
							{
								p_new = p_map->getWest(p_currentCell);
								if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
								{
									p_currentCell = p_new;
									onPathCells.push(p_currentCell);
									p_currentCell->setHasBeenVisited(true);
									//p_currentCell->setOnPath(true);
								}
								else
								{
									p_new = p_map->getNorthWest(p_currentCell);
									if (p_new != 0 && p_new->getType() != 'B' && p_new->getHasBeenVisited() == false)
									{
										p_currentCell = p_new;
										onPathCells.push(p_currentCell);
										p_currentCell->setHasBeenVisited(true);
										//p_currentCell->setOnPath(true);
									}
									else
									{
										//p_currentCell->setOnPath(false);
										onPathCells.pop(p_currentCell);
										p_new = onPathCells.top(p_currentCell);
										
									}

								}

							}

						}

					}

				}

			}
		}
	}
	for (int i = onPathCells.size() - 1; i > 0; i--)
	{
		p_currentCell = onPathCells.top(p_currentCell);
		p_currentCell->setOnPath(true);
		onPathCells.pop(p_currentCell);
	}

}
