import Image
def dhash(image, hash_size = 8):
        # Grayscale and shrink the image in one step.
        image = image.convert('L').resize(
            (hash_size + 1, hash_size),
            Image.ANTIALIAS,
        )
 
        pixels = list(image.getdata())
 
        # Compare adjacent pixels.
        difference = []
        for row in xrange(hash_size):
            for col in xrange(hash_size):
                pixel_left = image.getpixel((col, row))
                pixel_right = image.getpixel((col + 1, row))
                difference.append(pixel_left > pixel_right)
 
        # Convert the binary array to a hexadecimal string.
        decimal_value = 0
        hex_string = []
        for index, value in enumerate(difference):
            if value:
                decimal_value += 2**(index % 8)
            if (index % 8) == 7:
                hex_string.append(hex(decimal_value)[2:].rjust(2, '0'))
                decimal_value = 0
 
        return ''.join(hex_string)

def hamming_distance(s1, s2):
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2))

entrada = open("imagelist.txt", "r")
en2 = open("imagelist2.txt", "r")
out = open("result_dhash.csv", "w")
out.write("dHash,")
for line in entrada:
    line = line.rstrip('\n')
    out.write(line)
    out.write(",")
out.write("\n")   
entrada.seek(0, 0)

for line in entrada:
    line = line.rstrip('\n')
    out.write(line)
    Im1 = Image.open("Images/%s" % line)
    hash1 = dhash(Im1)
    for lin2 in en2:
        lin2 = lin2.rstrip('\n')
        Im2 = Image.open("Images/%s" % lin2)
        hash2 = dhash(Im2)
        val = ",%d" % hamming_distance(hash1, hash2)
        out.write(val)
    out.write("\n")
    en2.seek(0,0)