# Segmentation de vert

Le logiciel développé permet de segmenter une image RGB sur un niveau de vert seuil. La segmentation utilise accélération matérielle de l'API CUDA des GPU Nvidia.
 
## Exigences du logiciel 

Carte graphique Nvidia compatible avec CUDA.
 
## Hiérarchie du projet
 
Le projet se consitue principalement de :

La classe **Player_interface** rassemble les méthodes principales : 
	- openFile : permet l'ouverture de l'image rgb demandée.
	- gpu_seg  : lance la segmentation avec CUDA.
	- cpu_seg  : lance la segmentation avec le CPU.
	- save_im_out : enregistre l'image de sortie dans ce même répertoire.
 
Le header **seg_macros** qui rassemble les macros utilitaires.

Le fichier source CUDA **gpu_seg.cu** qui définit le kernel utilisé, ainsi que la fonction **gpu_im_seg** qui organise la segmentation avec le GPU Nvidia.

Enfin **main.cpp** est le programme principal. 

## Utilisation

1) Au lancement du logiciel, l'explorateur des fichiers s'ouvre pour localiser l'image RGB à segmenter.

2) Ensuite, la segmentation se fait automatiquement sans intervention humaine.

3) A la fin du programme, l'image de sortie générée va être stockée dans ce même répertoire sous le nom "binarisee.jpg".  
 

## Historique
 
Version 0.1 (23-09-2019) 
 
## Credits
 
Principal développeur - Amjad OULED-AMEUR (@amjadameur)
 
## License
 
GNU General Public License (GPLv3)
