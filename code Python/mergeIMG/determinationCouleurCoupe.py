# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 19:54:23 2017

@author: Adrien
"""

from PIL import Image

def couleur(ch, nom):
    """ 
    Détermine la couleur sur laquelle devra s'effectuer la fusion
    """
    im = Image.open(ch + "/" + nom)
    (pix_largeur, pix_hauteur)= (im.size[0], im.size[1])
    rgb_im = im.convert('RGB')
    pix = rgb_im.load()
    n = 0
    (sR, sV, sB) = (0, 0, 0)
    for j in [0,1, pix_hauteur-2, pix_hauteur-1]:
        for i in [0,1, pix_hauteur-2, pix_hauteur-1]:
            (R, V, B) = pix[i,j]
            sR += R 
            sV += V
            sB += B
    if sR < 20 and sB < 20 and sV < 20:
        return (0,0,0)
    return (255, 255, 255)