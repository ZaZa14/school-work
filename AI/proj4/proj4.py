# to remove warnings 
def warn(*args, **kwargs):
    pass
import warnings
warnings.warn = warn

# -*- coding: utf-8 -*-
import word2vec
from sklearn.cross_validation import cross_val_score
import os
import glob
import re


def readConservative():
  path = '/home/inson/Desktop/AI/school-work/AI/proj4'  
  listofWords = list()
  folders = ([name for name in os.listdir(path)
             if os.path.isdir(os.path.join(path, name)) and name.startswith("c")]) # get all directories 
  for folder in folders:
      contents = os.listdir(os.path.join(path,folder)) # get list of contents
      for file in contents:
        file_name = 'conservative/' + file
        try:
          with open(file_name, 'r') as fp:            
            a = makeLower(re.sub("[^\w]", " ",  fp.read()).split())
            listofWords.append(a)            
        except IOError:
          print("Cannot open file ", file )
  print('list of words ', len(listofWords))
  return listofWords

def readLiberal():
  path = '/home/inson/Desktop/AI/school-work/AI/proj4'
  listofWords = []
  folders = ([name for name in os.listdir(path)
             if os.path.isdir(os.path.join(path, name)) and name.startswith("Liber")]) # get all directories
  for folder in folders:
      contents = os.listdir(os.path.join(path,folder)) # get list of contents
      for file in contents:
        file_name = 'Liberal/' + file
        try:
          with open(file_name, 'r') as fp:
            #print("------------------------", file_name, "-----------------------")
            a = makeLower(re.sub("[^a-zA-Z0-9_]", " ",  fp.read()).split())
            listofWords.append(a)
            #print(listofWords, '*********************')
        except IOError:
          print("Cannot open file ", file )
  print('list of words ')
  return listofWords

def makeLower(words):
  l = [item.lower() for item in words]
  return l

def main():
  #print(readConservative())
  #print(readLiberal())
  print("inside of the main function")

if __name__ == '__main__':
  main()

print("End of project")


