make -C ./ ||
make -C ./BONUS/A/ ||
make -C ./BONUS/B/ ||
for i in 2 3 4 5 6
do echo "estandard_k $i" ; ./main.exe $i > "./test/estandard_k$i.txt" ; done ||
for i in 2 3 4 5 6
do echo "relaxat_k $i"; ./BONUS/A/main.exe $i > "./test/relaxat_k$i.txt" ; done ||
for i in 2 3 4 5 6
do echo "squarish_k $i"; ./BONUS/B/main.exe $i > "./test/squarish_k$i.txt" ; done ||
