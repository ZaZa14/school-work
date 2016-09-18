#!/usr/bin/python3
# =================================================
# Project 1--Graph Search
# Student: Zafar Mamarakhimov
# Email: mzafar2@umbc.edu
# =================================================
import os
import sys
import re

from collections import defaultdict, deque


# --------------------------------------------------
# Graph class where nodes connected with each other.
class Graph(object):
  # constructor for Graph
  def __init__(self):
    self.nodes = set()
    self.verteces = defaultdict(list)
    self.weight = {}

  # adding a vertex into the graph
  def addNode(self, value):
        self.nodes.add(value)
        print("added node " + value)

  # connecting two nodes with weight
  def makeEdge(self, from_node, to_node, distance):
    self.verteces[from_node].append(to_node)
    # self.verteces[to_node].append(from_node)
    self.weight[(from_node, to_node)] = distance
    print("distance between {} and {} is {}".format(from_node, to_node, distance)) # for debugging purposes

  # returning set of nodes;
  # nodes are un-ordered
  def getNodes(self):
    return self.nodes
    


# calculates shortest path to every node in the graph
def dikjstra(nodes, start):
  visited = {start: 0}
  path = {}

  allNodes = set(graph.getNodes())

  while allNodes:
    min_node = None
    for node in allNodes:
      if node in visited:
        if min_node is None:
          min_node = node
        elif visited[node] < visited[min_node]:
          min_node = node

    if min_node is None:
      break
    allNodes.remove(min_node)
    current_weight = visited[min_node]

    for edge in nodes.verteces[min_node]:
      try:
        weight = int(current_weight) + int(nodes.weight[(min_node, edge)])
      except:
        continue
      if edge not in visited or weight < visited[edge]:
        visited[edge] = weight
        path[edge] = min_node

  return visited, path




# Breadth first search
def bfsSearch(graph, start, goal):
  print("Inside of BFS: start-->" + start + " goal-->" + goal)


# Depth first search
def dfsSearch(graph, start, goal):
  print("Inside of DFS: start-->" + start + " goal-->" + goal)


# Uniform Cost Search a.k.a Dikjstra Algorithm
def ucsSearch(graph,start, goal):
  print("Inside of UCS: start-->" + start + " goal-->" + goal)
  visited_nodes, path = dikjstra(graph, start)

  # create a queue
  shortest_path = deque()
  
  try:
    adjacent_node = path[goal] # go backwards, start from the goal and go to the start
  except:
    # if there is no path between nodes print the message and close the program
    print("There is no path between node {} and node {}".format(start, goal))
    sys.exit()

  while adjacent_node != start:
    shortest_path.appendleft(adjacent_node)
    adjacent_node = path[adjacent_node]

  shortest_path.appendleft(start)
  shortest_path.append(goal)

  return list(shortest_path), visited_nodes[goal]






if __name__ == '__main__':
  print("Start of the program")
  print('Number of arguments:', len(sys.argv), 'arguments.')
  if(len(sys.argv) == 5):
    print("inside of if clause")
    inputFile = sys.argv[1]
    start = sys.argv[2]
    goal = sys.argv[3]
    search = sys.argv[4]

    graph = Graph()   

    try:
      with open(inputFile, 'r') as fp:
        for line in fp:
          #line = line.replace(" ", "") # removing all white spaces from the string   
          line = re.findall(r'\d+', line) # get numbers using regular expression       
          graph.addNode(line[0])
          graph.addNode(line[1])
          graph.makeEdge(line[0], line[1], line[2])
          print(line)
    except IOError:
      print("Cannot find the input file")

    print(graph.getNodes())

    # making search based on the command
    if(search == "BFS"):
      bfsSearch(graph, start, goal)
    elif(search == "DFS"):
      dfsSearch(graph, start, goal)
    else:
      print(ucsSearch(graph, start, goal))

  else:
    print("Enter correct number of arguments") # if input is not correct
