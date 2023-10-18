# Arbres k-Dimensionals 

Un problema molt comú en la informàtica és la cerca del veí més proper, conegut també com a nearest neighbour queries. Els arbres K-Dimensionals resulten ser l’estructura de dades més adequada per resoldre l’algorisme de manera eficient. En aquest projecte, doncs, analitzarem en profunditat la implementació dels arbres k-dimensionals, l’algorisme per trobar el veí més proper i també el seu cost. De manera addicional, hem estudiat i analitzat altres variacions com els k-d trees relaxats i els squarish k-d trees


## Instruccions

### Manual
Tens un Makefile a tots els directoris que es poden compilar el programa

### Automatic
Per compilar i generar les dades es pot utilitzar els següents scripts:
```
./genTest.sh
```
o 
```
./genTest_multicore.sh
```
Per a generar les dades utilitzant multiprocesos, en aquest cas s'hauran de reordenar les dades, hi ha un script en python en el directory test_multicore que et facilitar el procés.

Un cop generat les dades els pots trobar en el directori ./test o ./test_multicore depenent de com ho hagis fet.
