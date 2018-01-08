# -*- coding: utf-8 -*-
"""
Created on Fri Oct 27 18:47:52 2017

@author: Adrien
"""
from PIL import Image
import os

def decoupage_image_carre_pixel(chemin, nom_fichier, ch_sauv, nb_pixel = 32):
    """ 
    Permet de découper une image selon un modèle carré de nb_pixel de côté 
    et sauvegarde les fichiers dans un répertoire spécifique. 
    Attention, il faut que les images soit découpable (ie est des dimensions multiples
    de nb_pixel)
    chemin = chemin d'accès au fichier
    nom_fichier = nom du fichier
    ch_sauv = chemin de sauvegarde du fichier
    """
    im = Image.open(chemin + "/" + nom_fichier)
    (largeur, hauteur)= (im.size[0] // nb_pixel, im.size[1] // nb_pixel)
    rgb_im = im.convert('RGB')
    pix = rgb_im.load()
    (nomImg, ext) = os.path.splitext(nom_fichier)
    for j in range(hauteur):
        for i in range(largeur):
            imgNew = Image.new('RGB',(nb_pixel, nb_pixel))
            L = []
            for y in range(nb_pixel): # Parcours de la hauteur
                for x in range(nb_pixel): # Parcours de la largeur
                    L.append(pix[i* nb_pixel + x,j * nb_pixel + y])
            imgNew.putdata(L)
            if not os.path.exists(ch_sauv + "/" + nomImg):
                os.makedirs(ch_sauv + "/" + nomImg)
            imgNew.save(ch_sauv + "/" + nomImg + "/" + str(j) + "_" + str(i) + ext)   
    return


def decoupage_image_dimension(chemin, nom_fichier, nb_im_x, nb_im_y, ch_sauv):
    """ 
    Découpe une image en fonction du nb de cases horizontales et verticales 
    chemin = chemin d'accès au fichier
    nom_fichier = nom du fichier
    ch_sauv = chemin de sauvegarde du fichier
    nb_im_x = nombre d'image en colonnes
    nb_im_y = nombre d'image en lignes
    """
    im = Image.open(chemin + "/" + nom_fichier)
    (N, M)= im.size
    nb_pixelX = N // nb_im_x
    nb_pixelY = M // nb_im_y
    rgb_im = im.convert('RGB')
    pix = rgb_im.load()
    (nomImg, ext) = os.path.splitext(nom_fichier)
    for i in range(nb_im_x):
        for j in range(nb_im_y):
            imgNew = Image.new('RGBA',(nb_pixelX, nb_pixelY))
            L = []
            for y in range(nb_pixelY):
                for x in range(nb_pixelX):
                    L.append(pix[i* nb_pixelX + x,j * nb_pixelY + y])
            imgNew.putdata(L)
            if not os.path.exists(ch_sauv + "/" + nomImg):
                os.makedirs(ch_sauv + "/" + nomImg)
            imgNew.save(ch_sauv + "/" + nomImg + "/" + str(j) + "_" + str(i) + ext)   
    return