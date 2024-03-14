# TP_Systemes_microcontroleurs

1.2.13 Pourquoi PB9 est relié à la masse ? 

Réponse : 

PB9 n’est pas relié directement à la masse. Elle est reliée à la masse à travers une résistance pull down. Elle fonctionne comme une résistance de tirage (vers le bas). Son rôle est de s'assurer que la broche reste à un niveau logique bas (0V) lorsque rien n'est connecté à celle-ci ou si le dispositif connecté est en haute impédance. Cela évite que la broche flotte, ce qui pourrait mener à des états logiques indéfinis et à une consommation de courant inutile due aux oscillations de la tension. 

De plus si PB9 est utilisée comme entrée, la résistance permet à la broche de détecter un niveau bas jusqu'à ce qu'elle soit intentionnellement mise à un niveau haut par un autre circuit.  

La valeur élevée de la résistance (100k ohms) assure qu'il y a une très faible consommation de courant à travers la résistance lorsque la broche est mise à un niveau haut par le microcontrôleur ou un autre circuit. Cette configuration permet donc d'économiser de l'énergie et de prévenir un état indéfini sans interférer avec les signaux actifs. 

1.2.14 Quel est le rôle de L1, C5 et C7 ? 

Réponse : 

C5 et C7 sont des condensateurs de découplage et L1 joue le rôle de filtre 

L1 forme une barrière contre le bruit de haute fréquence tandis que C7 aide à court-circuiter ce bruit vers la masse, l'éliminant ainsi du système. C5 agit comme un réservoir d'énergie pour gérer les besoins en courant plus lent et plus large de la puce. Cette combinaison permet de filtrer une large gamme de fréquences de bruit et assurer une alimentation propre et stable pour le microcontrôleur. 

1.3.3 Quelle page de la datasheet indique les valeurs des condensateurs ? 

Réponse :  Page 3 du datasheet “buxxsd5wg-e”. (voir fichier word pour capture)

1.3.5 Quelle page de la datasheet nous indique les valeurs de condensateurs ? 

Réponse : Page 15 du datasheet “22244B-54643” (voir fichier word pour capture)

1.3.6 Quel est le rôle de la broche CS?  

Réponse :  La broche CS est utilisée pour activer et désactiver le dispositif DAC. Lorsque la broche CS est mise à bas (niveau logique 0), le DAC est sélectionné et peut communiquer avec le microcontrôleur. Lorsque CS est à haut (niveau logique 1), le DAC ignore les signaux du bus SPI, permettant ainsi à d'autres dispositifs sur le même bus SPI de communiquer sans interférence.  

1.3.7 Quel est le rôle de la broche LDAC ?  

Réponse : La broche LDAC est utilisée pour contrôler le moment où la sortie du DAC est mise à jour. Dans certains DACs, il est possible d’écrire dans un premier temps la donnée numérique dans un registre interne, puis, en mettant la broche LDAC à bas, d'indiquer au DAC de mettre à jour la sortie analogique avec la valeur stockée dans ce registre. 

1.3.8 Pourquoi le signal MISO n’est pas utilisé ? 

Réponse : Le signal MISO n'est pas utilisé dans ce cas car le MCP4801 est un DAC unidirectionnel qui ne nécessite que des données entrantes du microcontrôleur pour définir le niveau de tension de sortie. Il n'y a pas de nécessité pour le DAC d'envoyer des données en retour au microcontrôleur, d'où l'absence de connexion MISO dans ce cas. Le bus SPI est donc utilisé en mode unidirectionnel ici, seulement pour envoyer des données au DAC. 

1.3.10 Où trouve-t-on les indications du pinout du connecteur SWD ? 

Réponse :  Les indications sont trouvables sur le lien suivant :  

https://stm32-base.org/guides/connecting-your-debugger.html (voir word pour capture

1.4.3 Que signifie 0805 ? 0603 ? 1206 ?  

Réponse :  Les chiffres 0805, 0603 et 1206 font référence à des tailles standard de composants électroniques en montage en surface (SMD, pour Surface-Mount Device). Ces chiffres indiquent les dimensions du composant : 0603 désigne un composant qui mesure environ 0.06 pouces x 0.03 pouces, soit 1.6 mm x 0.8 mm. 

0805 désigne un composant qui mesure environ 0.08 pouces x 0.05 pouces, soit 2.0 mm x 1.25 mm. 

1206 désigne un composant qui mesure environ 0.12 pouces x 0.06 pouces, soit 3.0 mm x 1.5 mm. 

1.4.4 Que signifie LQFP ? SOT-223 ? SOIC ? Ne vous contentez pas de donner le sigle, j’attends une petite description (vous pouvez copier-coller depuis wikipedia, mais lisez avant quand même)) 

Réponse :   

LQFP (Low-profile Quad Flat Package) : Il s'agit d'un type de boîtier plat rectangulaire avec des connexions sur les quatre côtés. Il est conçu pour occuper peu d'espace en hauteur (d'où le terme "low-profile") et offre une bonne efficacité pour la dissipation thermique. Les broches sortent des côtés du composant et se replient sous le boîtier, ce qui permet un montage en surface sur un circuit imprimé. 

SOT-223 (Small Outline Transistor-223) : C'est un type de boîtier pour les composants à semi-conducteurs qui est plus grand que le traditionnel SOT-23, offrant une meilleure capacité de dissipation de chaleur. Le boîtier SOT-223 a généralement trois broches et une grande languette métallique à l'arrière qui sert à la fois de broche électrique supplémentaire et de dissipateur thermique. 

SOIC (Small Outline Integrated Circuit) : C'est un type de boîtier à montage en surface utilisé pour les circuits intégrés. Il a des broches sur les deux côtés et est plus étroit que le boîtier DIP (Dual In-line Package) traditionnel. 

3.1.4 Que signifie __STATIC_INLINE ?

Réponse :

__STATIC_INLINE permet d'indiquer au compilateur de remplacer les appels de la fonction par le contenu de la fonction (similaire à une fonction macro)

3.1.5 Et pourquoi y a-t-il du code dans un .h alors que Môssieur Fiack vous a expres-
sément demandé de pas le faire ? (Les deux questions sont peut-être liés, va
savoir)

Réponse : Si c'est une fonction INLINE dans un header, elle est copiée dans le fichier source.

3.2.2 

Quelle valeur donner au prescaler ?

Réponse :

On donne 64 au prescaler car 16 Mhz/64 = 250 kHz. On obtient une période de 255 pour le compteur du timer et 1 khz pour le PWR.

3.3.3 Quelles sont les valeurs de PSC et de ARR ?

Réponse : 

On sait que la fréquence du processeur est de 16 MHz. Et on souhaite un timer qui déclenche une interruption toutes les milli-secondes, donc avec une fréquence de 1 khz. On règle donc le PSC à 250 et l'ARR à 64 pour avoir 1 kHz.

3.3.6 Où se situe la routine de service d’interruption ?

Réponse :

Elle se situe dans "stm3210xx_it.c"

3.3.7 Que manque-t-il par rapport au code généré par la HAL ?

Réponse:

La désactivation du flag d'interruption

3.3.8 En quoi est-ce catastrophique ?

Réponse :

L'interruption va être lancée en boucle

3.3.9 Que faire ?

Réponse :

Ecrire le flag dans la routine d'interruption

3.4.5 Une erreur s’est glissée dans le code précédent, saurez-vous la retrouver ?

Réponse : 

Il faut rajouter un & dans la ligne SerialTransmit(&ch,1);
Il est nécessaire de passer un pointeur sur le char.


