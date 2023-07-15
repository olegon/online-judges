from collections import deque

class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        w = World(grid)
        return w.resolve()

class World:
    def __init__(self, grid):
        self.grid = grid
        self.size = len(grid)

    def resolve(self):
        self.findIslands()
        return self.findBestCost()

    def printGrid(self):
        for row in self.grid:
            print(row)

    def findIslands(self):
        island_letters = ['a', 'b']

        for i, row in enumerate(self.grid):
            for j, value in enumerate(row):
                if value == 1:
                    position = (i, j)
                    self.fillIsland(position, island_letters.pop())

    def fillIsland(self, position, letter):
        if self.getValue(position) == 1:
            self.setValue(position, letter)
            for nextPosition in self.getNextPositions(position):
                self.fillIsland(nextPosition, letter)

    def getValue(self, position):
        i, j = position
        return self.grid[i][j]

    def setValue(self, position, value):
        i, j = position
        self.grid[i][j] = value

    def getNextPositions(self, position):
        positions = []
        i, j = position

        for nextPosition in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
            if self.isValidPosition(nextPosition):
                positions.append(nextPosition)

        return positions

    def isValidPosition(self, position):
        i, j = position
        return 0 <= i < self.size and 0 <= j < self.size

    def findBestCost(self):
        q = deque()
        origin = set()

        for i, row in enumerate(self.grid):
            for j, value in enumerate(row):
                if value == 'a':
                    position = (i, j)
                    origin.add(position)
                    q.append(position)
                    self.grid[i][j] = 0

        while len(q) > 0:
            currentPosition = q.popleft()
            currentValue = self.getValue(currentPosition)

            for nextPosition in self.getNextPositions(currentPosition):
                nextValue = self.getValue(nextPosition)
                
                if nextPosition in origin:
                    continue
                if nextValue == 'b':
                    return currentValue
                elif nextValue == 0:
                    self.setValue(nextPosition, currentValue + 1)
                    q.append(nextPosition)

        raise Exception('No solution found.')
