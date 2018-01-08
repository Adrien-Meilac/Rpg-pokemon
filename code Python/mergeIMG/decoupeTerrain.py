# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 16:03:10 2017

@author: Adrien
"""
import os 

# im.size = (largeur * hauteur)

import decoupeGenerale as dg

def img_explosion_terrain(ch, nom, ch_sauv):
    dg.decoupage_image_carre_pixel(ch, nom, ch_sauv)
        
        
def img_explosion_terrains(ch, ch_sauv):
    for f in os.listdir(ch):
        print("explosion terrain : " + f)
        img_explosion_terrain(ch, f, ch_sauv)
    
