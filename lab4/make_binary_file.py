###
# generates a binary file with N random integers between A and B
# first command line argument is the output filename
# call with python 3
###
import random
import sys

N = 10
A = 0
B = 5

with open(sys.argv[1], 'wb') as f_out:
    for _ in range(N):
        f_out.write((random.randint(A,B)).to_bytes(4, byteorder='little'))
