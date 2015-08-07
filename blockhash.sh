cd Images
ls *.jpg > ../imagelist.txt
cd ..

#Blockhash
echo "" > hashlist.txt
while read line; do
	echo $(blockhash Images/$line) >> hashlist.txt 
done <imagelist.txt

g++ -o hammingDistance hammingDistance.cpp

#pHash
g++ -o DisplayImage DisplayImage.cpp `pkg-config --cflags --libs opencv` `pkg-config --cflags --libs pHash`

while read line; do
	#compara a imagem Mod1.jgp com as imagens contidas no diretório Images  
	./DisplayImage Images/$line
	echo $(blockhash Images/$line) > input.txt
	./hammingDistance Images/$line
done <imagelist.txt