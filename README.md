# Project Description
This project hides a secret text message inside a BMP image using the Least Significant Bit (LSB) steganography technique. The program reads a cover image and a secret text file, embeds the message bits into the LSB of the image pixels, and generates a new encoded image. The hidden message can later be extracted using a decoding program.

# Technologies Used
C Programming
File Handling
Bit Manipulation
BMP Image File Format
Least Significant Bit (LSB) Algorithm
Data Encoding and Decoding

# Working 

# Step 1: Understand the Concept
Steganography hides secret data inside another file so that the presence of the message is not noticeable.

# Step 2: Input Files
Take a BMP image as the cover image and a text file containing the secret message.

# Step 3: Read the Image File
Open the BMP image and skip the header section to avoid damaging the image format.

# Step 4: Read the Secret Message
Open the text file and read the secret data along with its length.

# Step 5: Encode the Message
Convert the message characters into binary and embed each bit into the LSB of the image bytes.

# Step 6: Create Encoded Image
Save the modified image as a new BMP file that now contains the hidden message.

# Step 7: Decode the Message
Read the encoded image and extract the LSB bits to recover the hidden data.

# Step 8: Recover the Secret Text
Convert the extracted bits back into characters and store them in an output text file.

# Advantages

Provides secure hidden communication

Image appears unchanged to the human eye

Easy to implement using C programming

Does not significantly affect image quality

# Applications

Secure data transmission

Digital watermarking

Copyright protection

Military and confidential communication

Data hiding in multimedia files
