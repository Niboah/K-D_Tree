# Arbres k-Dimensionals 

Un problema molt comú en la informàtica és la cerca del veí més proper, conegut també com a nearest neighbour queries. Els arbres K-Dimensionals resulten ser l’estructura de dades més adequada per resoldre l’algorisme de manera eficient. En aquest projecte, doncs, analitzarem en profunditat la implementació dels arbres k-dimensionals, l’algorisme per trobar el veí més proper i també el seu cost. De manera addicional, hem estudiat i analitzat altres variacions com els k-d trees relaxats i els squarish k-d trees


## Instruccions
Per obtenir les dades dels costos per diferents arbres i nombre de nodes ho podem fe de dos maneres.
### Manual
Hi ha un Makefile a tots els directoris que es poden compilar el programa. Es a dir, es pot fer una crida a la comanda `make` en el directori arrel per compilar el programa per a arbres k-dimensionals estandarts, en el directori BONUS/A/ es pot fer una crida a la comanda `make`  per compilar el programa per a arbres k-dimensionals relaxat i en el directori BONUS/B/ es pot fer una crida a la comanda `make` per compilar el programa per a arbres k-dimensionals squarish.
Una vegada compilat els programes pots fer una crida al `main.exe` seguidamen del numero de dimensio k, per a fer una ejecucio de 0 a 10000 node, 10 vegades cada node.
```
./main.exe 3
```
si no se especifique la k, pren el valor de 2 per defecte.

Hi ha una alternativa `main_multicore.exe` per fer la ejecucio multicore.
```
./main_multicore.exe 3
```

### Automatic
Per compilar i generar les dades es pot utilitzar el següent script:
```
./genTest.sh
```
o per a generar les dades utilitzant multicore, en aquest cas s'hauran de reordenar les dades, hi ha un script en python en el directory test_multicore que et facilitar el procés.
```
./genTest_multicore.sh
```
Un cop generat les dades els pots trobar en el directori ./test o ./test_multicore depenent de com ho hagis fet.
