# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 18:49:22 2017

@author: Adrien
"""

import decoupeGenerale as dg
import retailleIMG as rt
import os 

def img_explosion_personnage(ch, nom, ch_sauv, dimX = 4, dimY = 4):
    dg.decoupage_image_dimension(ch, nom, dimX, dimY, ch_sauv)
    ch = ch_sauv + "/" + os.path.splitext(nom)[0]
    for f in os.listdir(ch):
        rt.retaillage_horizontal(ch, f)
        rt.retaillage_vertical(ch, f)
        dg.decoupage_image_carre_pixel(ch, f, ch)
        os.remove(ch + "/" + f)
        
        
def img_explosion_personnages(ch, ch_sauv):
    for f in os.listdir(ch):
        print("explosion perso : " + f)
        img_explosion_personnage(ch, f, ch_sauv)
        
# 11 images de 16 découpées en 1 seconde