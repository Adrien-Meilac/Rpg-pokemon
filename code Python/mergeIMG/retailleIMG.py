# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 18:46:51 2017

@author: Adrien
"""
from PIL import Image

def div_reste(a, b):
    return (a // b, a % b)

def retaillage_vertical(chemin, nom_fichier, nb_pixel = 32, col = (0,0,0)):
    """Donne à une image une taille verticale multiple de nb_pixel, aligné
    sur le bas"""
    im = Image.open(chemin + "/" + nom_fichier)
    (case_hauteur, reste_hauteur) = div_reste(im.size[1], nb_pixel) # Hauteur
    pixel_largeur = im.size[0]
    if reste_hauteur == 0:
        return
    L = []
    rgb_im = im.convert('RGB')
    pix = rgb_im.load()
    imgNew = Image.new('RGB',(pixel_largeur, (case_hauteur + 1) * nb_pixel))
    for i in range(nb_pixel - reste_hauteur):
        for j in range(pixel_largeur):
            L.append(col) # black
    for i in range((case_hauteur + 1) * nb_pixel - (nb_pixel - reste_hauteur)):
        for j in range(pixel_largeur):
            L.append(pix[j,i])
    imgNew.putdata(L)
    im.close()
    imgNew.save(chemin + "/" + nom_fichier)
    return 


def retaillage_horizontal(chemin, nom_fichier, nb_pixel = 32, col=(0,0,0)): 
    """Donne à une image une taille horizontale multiple de nb_pixel, centré
    attention le code ne marche pas si le nombre de pixel est impair !!!
    col = couleur en RGB
    """
    im = Image.open(chemin + "/" + nom_fichier)
    (case_largueur, reste_largueur) = div_reste(im.size[0], nb_pixel) # Hauteur
    pixel_hauteur = im.size[1]
    if reste_largueur == 0:
        return
    L = []
    rgb_im = im.convert('RGB')
    pix = rgb_im.load()
    imgNew = Image.new('RGB',((case_largueur + 1) * nb_pixel, pixel_hauteur))
    for i in range(pixel_hauteur):
        for j in range(((case_largueur + 1) * nb_pixel - im.size[0])//2):
            L.append(col) # black
        for j in range(im.size[0]):
            L.append(pix[j, i])   
        for j in range(((case_largueur + 1) * nb_pixel - im.size[0])//2):
            L.append(col) # black
    imgNew.putdata(L)
    im.close()
    imgNew.save(chemin + "/" + nom_fichier)
    return 