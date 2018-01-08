# -*- coding: utf-8 -*-
"""
@author: Adrien
"""
# La taille standart d'une icone est de 32 x 32


import os 
import decoupeTerrain as dt
import decoupePerso as dp
from PIL import Image
import mergeIMG as me
import determinationCouleurCoupe as dcc
import time 

os.chdir(r"C:\Users\adrie\OneDrive\Documents\2017 - ENSAE 2A\S1\C++ pour la finance\RPG\mergeIMG")

ch_bdd = "C:/Users/adrie/OneDrive/Documents/2017 - ENSAE 2A/S1/C++ pour la finance/RPG/Pokémon Essentials v17.2 2017-10-15/Graphics"

   
#t0 = time.time()
#dp.img_explosion_personnages(ch_bdd + "/Characters", "./Characters")
#dt.img_explosion_terrains(ch_bdd + "/Tilesets", "./Tilesets")
#dt.img_explosion_terrains(ch_bdd + "/Autotiles", "./Autotiles")
#t = time.time() - t0
#print("Tps execution = " + str(t))

#me.merge_case("./Tilesets/Caves", "28_2.png", "./Tilesets/Caves", "8_2.png", ".", col_coupe = (0,0,0))

t0 = time.time()
dcc.couleur("./Tilesets/Caves", "8_2.png")
t = time.time() - t0
print("Tps execution = " + str(t))