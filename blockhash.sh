#calcula o hash de 256 de bits das imagens listadas
hash1=$(blockhash doc1function.bmp doc1new.bmp doc2function.bmp doc2new.bmp doc1.bmp doc1new.bmp)

echo $hash1 > input.txt

g++ -o hammingDistance hammingDistance.cpp

./hammingDistance


