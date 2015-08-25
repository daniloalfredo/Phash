cd Images
ls *.jpg > ../imagelist.txt
cd ..

#Pré-processamento do Blockhash
echo "" > hashlist.txt
echo -n "" > imagelist2.txt
while read line; do
	echo $(blockhash Images/$line) >> hashlist.txt
	echo $line >> imagelist2.txt
done <imagelist.txt
g++ -o hammingDistance hammingDistance.cpp

#Pré-processamento do pHash
g++ -o DisplayImage DisplayImage.cpp `pkg-config --cflags --libs opencv` `pkg-config --cflags --libs pHash`

#criação dos arquivos de resultado de cada método
echo -n blockhash, > result_blockhash.csv
echo -n phash, > result_phash.csv
while read line; do
	echo -n $line, >> result_phash.csv
	echo -n $line, >> result_blockhash.csv
done <imagelist.txt
echo "" >> result_blockhash.csv
echo "" >> result_phash.csv

#execução de ambos e comparação de resultados
while read line; do  
	./DisplayImage Images/$line
	echo $(blockhash Images/$line) > input.txt
	./hammingDistance Images/$line
done <imagelist.txt

#execução do dhash
python dhash.py