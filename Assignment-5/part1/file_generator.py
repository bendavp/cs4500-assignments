#!/usr/bin/python

from random import random
from random import randint
from random import seed
from random import choice
import string
import sys

# takes 2 inputs
# first input = "file_name.txt"
# second input = number of rows
# details about the file that can be changed
outFile = sys.argv[1]
numRows = int(sys.argv[2])

# for generating ints/floats/bools/strings
letters = string.ascii_letters
seed(1)

with open(outFile, "w") as f:
    for x in range(numRows):
        colsToAdd = []
        colsToAdd.append(str(randint(0,200))) # int col 1
        colsToAdd.append(str(randint(0,200))) # int col 2
        colsToAdd.append(str(randint(0,200))) # int col 3
        colsToAdd.append(str(random() * 200)) # float 4
        colsToAdd.append(str(random() * 200)) # float 5
        colsToAdd.append(str(randint(0,1))) # bool 6
        colsToAdd.append(str(randint(0,1))) # bool 7
        colsToAdd.append(''.join(choice(letters) for i in range(randint(3,20)))) # string 8
        colsToAdd.append(''.join(choice(letters) for i in range(randint(3,20)))) # string 9
        colsToAdd.append(''.join(choice(letters) for i in range(randint(3,20)))) # string 10
        f.write('\t'.join(colsToAdd) + '\n')
