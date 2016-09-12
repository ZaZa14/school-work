#!/usr/bin/python3
import os
import sys


# Breadth first search
def bfsSearch(start, goal):
  print("Inside of BFS: start-->" + start + " goal-->" + goal)


# Depth first search
def dfsSearch(start, goal):
  print("Inside of DFS: start-->" + start + " goal-->" + goal)


# Uniform Cost Search
def ucsSearch(start, goal):
  print("Inside of UCS: start-->" + start + " goal-->" + goal)


if __name__ == '__main__':
  print("Start of the program")
  print('Number of arguments:', len(sys.argv), 'arguments.')
  if(len(sys.argv) == 5):
    print("inside of if clause")
    inputFile = sys.argv[1]
    start = sys.argv[2]
    goal = sys.argv[3]
    search = sys.argv[4]    

  with open(inputFile, 'r') as fp:
    for line in fp:
        print(line, end="")

  # making search based on the command
  if(search == "BFS"):
    bfsSearch(start, goal)
  elif(search == "DFS"):
    dfsSearch(start, goal)
  else:
    ucsSearch(start, goal)

  hashMap = {1 : [2, 3 ,4], 
              2 : [5, 6],
              3 : [7, 8],
              4 : []}
  print(hashMap[1])
  print(hashMap[4])
  hashMap[4] = [1, 5, 9]
  print(hashMap[4])
  print(hashMap.keys())





