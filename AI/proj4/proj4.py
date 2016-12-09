import word2vec
import sklearn
import os
import glob
path = '/home/inson/Desktop/AI/school-work/AI/proj4'
mn = 20
folders = ([name for name in os.listdir(path)
           if os.path.isdir(os.path.join(path, name)) and name.startswith("c")]) # get all directories 
for folder in folders:
    contents = os.listdir(os.path.join(path,folder)) # get list of contents
    for file in contents:
      file_name = 'conservative/' + file
      try:
        with open(file_name, 'r') as fp:
          print("------------------------", file_name, "-----------------------")
          a = fp.read()                
          print(a)
      except IOError:
        print("Cannot open file ", file )
    # print(contents[0]) # printing the title of one txt file
    # try: 


    # if len(contents) > mn: # if greater than the limit, print folder and number of contents
    #     print(folder,len(contents))


#print (glob.glob(path))
print("End of project")