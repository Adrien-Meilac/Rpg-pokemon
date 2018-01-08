# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 19:40:26 2017

@author: Adrien
"""

import os
from PIL import Image
import determinationCouleurCoupe as dcc


def merge_case(ch1, nom1, ch2, nom2, ch_sauv, col_coupe = None):
    """
    Place l'image 2 sur l'image 1 qui est en fond
    ch1 = chemin vers l'image 1
    nom1 = nom de l'image 1
    ch2 = chemin vers l'image 2
    nom2 = nom de l'image 2
    Les deux images ont la même taille supposée (32x32) au moins carrée
    """
    if col_coupe == None:
        col_coupe = dcc.couleur(ch2, nom2)
    im1 = Image.open(ch1 + "/" + nom1)
    im2 = Image.open(ch2 + "/" + nom2)
    (largeur, hauteur) = (im1.size[0], im1.size[1])
    rgb_im1 = im1.convert('RGB')
    pix1 = rgb_im1.load()
    rgb_im2 = im2.convert('RGB')
    pix2 = rgb_im2.load()
    imgNew = Image.new('RGB',(largeur, hauteur))
    L = []
    for y in range(hauteur): # Parcours de la hauteur
        for x in range(largeur): # Parcours de la largeur
            if pix2[x, y] == col_coupe:
                L.append(pix1[x, y])
            else:
                L.append(pix2[x, y])
    imgNew.putdata(L)
    (nomImg, ext) = os.path.splitext(nom1)
    if not os.path.exists(ch_sauv + "/" + nomImg):
        os.makedirs(ch_sauv + "/" + nomImg)
    (nomImg2, ext) = os.path.splitext(nom2)  
    imgNew.save(ch_sauv + "/" + nomImg + "/" + nomImg2 + ext)   
    return

    
    
    