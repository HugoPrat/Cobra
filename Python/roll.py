#!/usr/bin/python3

import sys
import random

def roll():
    if len(sys.argv) != 2:
        return "Error"
    chaine = sys.argv[1]
    nbr_dice = int(chaine[0])
    dice = int(chaine[2:len(chaine)]) - 1
    result = 0
    if (dice == 0 || nbr_dice == 0):
        return "Error"
    while nbr_dice != 0:
        result = result + (random.random()*dice) + 1
        nbr_dice = nbr_dice - 1
    return result

if __name__=="__main__":
    print(round(roll()))
