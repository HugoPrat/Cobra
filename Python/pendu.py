#!/usr/bin/python3

import sys
import os

def pendu():
    os.system('clear')
    mot = sys.argv[1]
    vie = 10
    myst = mot[0]
    i = 1
    find = 0
    while i != len(sys.argv[1]):
        i = i + 1
        myst = myst + '_'
    list1 = list(myst)
    while myst != mot and vie != 0:
        print("il vous reste {0} vie(s):{1}".format(vie,myst))
        print("Quel est votre proposition:", end='')
        lettre = input()
        if lettre == mot:
            break
        i = 0
        find = 0
        while i != len(mot) - 1:
            i = i + 1
            if lettre == mot[i]:
                list1[i] = lettre
                myst = ''.join(list1)
                find = 1
        print('\n')
        if find == 0:
            print("Erreur, vous perdez une vie...")
            vie = vie - 1
        else:
            print("GG la 3G")
    print('\n')
    if (vie != 0):
        print("Bravo, vous avez Gagné !")
    else:
        print("Dommage, vous avez perdu !")

if __name__=="__main__":
    if len(sys.argv) == 2:
        pendu()
    else:
        print("Error")
