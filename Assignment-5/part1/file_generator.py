#!/usr/bin/python

from random import random
from random import randint
from random import seed
from random import choice
import string

outFile = "datafile.txt"
letters = string.ascii_letters

seed(1)

with open(outFile, "w") as f:
    for x in range(1278600):
        colsToAdd = []
        colsToAdd.append(str(randint(0,10000))) # int col 1
        colsToAdd.append(str(randint(0,10000))) # int col 2
        colsToAdd.append(str(randint(0,10000))) # int col 3
        colsToAdd.append(str(random() * 100)) # float 4
        colsToAdd.append(str(random() * 100)) # float 5
        colsToAdd.append(str(randint(0,1))) # bool 6
        colsToAdd.append(str(randint(0,1))) # bool 7
        colsToAdd.append(''.join(choice(letters) for i in range(randint(3,20)))) # string 8
        colsToAdd.append(''.join(choice(letters) for i in range(randint(3,20)))) # string 9
        colsToAdd.append(''.join(choice(letters) for i in range(randint(3,20)))) # string 10
        f.write('\t'.join(colsToAdd) + '\n')
