make -C ./BONUS/A/ ||
for i in 2 3 4 5 6
do echo "relaxat_k $i"; ./BONUS/A/main_multicore.exe $i > "./test_multicore/relaxat_k$i.txt" ; done