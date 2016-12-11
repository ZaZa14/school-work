# to remove warnings 
def warn(*args, **kwargs):
    pass
import warnings
warnings.warn = warn

# -*- coding: utf-8 -*-
import word2vec
from sklearn.cross_validation import cross_val_score
from sklearn.feature_extraction.text import CountVectorizer
from collections import Counter
import string
import itertools
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
            # a = makeLower(re.sub("[^\w]", " ",  fp.read()).split())
            rgx = re.compile("(\w[\w']*\w|\w)")
            a = makeLower(rgx.findall(fp.read()))
            listofWords.append(a)            
        except IOError:
          print("Cannot open file ", file )   
  return list(itertools.chain.from_iterable(listofWords))

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
            #word.strip(string.punctuation) for word in text.split()
            # a = makeLower(word.strip(string.punctuation) for word in re.sub("[^a-zA-Z0-9'_]", " ",  fp.read()).split())
            rgx = re.compile("(\w[\w']*\w|\w)")
            a = makeLower(rgx.findall(fp.read()))
            #a = makeLower(re.sub("[^[\w[\w']*\w|\w]]", " ",  ).split())
            listofWords.append(a)
            #print(listofWords, '*********************')
        except IOError:
          print("Cannot open file ", file )  
  return list(itertools.chain.from_iterable(listofWords))

def makeLower(words):
  l = [item.lower() for item in words]
  return l

def getMostUsed(words):
  print("Top 10 words: ")
  c = Counter(words)
  return c.most_common(10)

def main():
  # print(readLiberal())

  # print(len(readConservative()))
  # print(len(readLiberal()))

  print(getMostUsed(readConservative()))
  print(getMostUsed(readLiberal()))
  print("inside of the main function")

if __name__ == '__main__':
  main()

print("End of project")


