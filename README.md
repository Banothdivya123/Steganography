# Image Steganography using LSB (C)
# 📌 Project Description

The Image Steganography project hides secret text inside an image using the Least Significant Bit (LSB) technique. The program encodes a secret message into a BMP image file by modifying the least significant bits of image bytes. During decoding, the hidden message is extracted from the image without affecting the visible quality of the image.

# 🎯 Objective

To securely hide secret information inside an image file.

To understand the concept of steganography and data hiding techniques.

To implement encoding and decoding algorithms using C programming.

# 🧠 Concepts Used

File Handling in C

Bit Manipulation

Image Processing Basics

Data Encoding and Decoding

LSB (Least Significant Bit) Technique

# ⚙️ How the System Works

The program takes a BMP image file as the cover image.

It reads the secret text file that needs to be hidden.

The size of the secret file is encoded into the image first.

Each bit of the secret data is embedded into the least significant bit of the image bytes.

A new stego image is generated containing the hidden data.

During decoding, the program extracts the hidden bits from the image and reconstructs the original secret text.

# ✨ Features

Hide secret text inside an image

Decode hidden text from the stego image

Maintains the visual quality of the image

Simple and secure data hiding technique

# 🚀 Advantages

Secure communication of hidden information

No visible change in the image

Simple and efficient implementation

Demonstrates practical data hiding techniques

# 💡 Applications

Secure data communication

Digital watermarking

Copyright protection

Military and confidential communication

Information security systems

# 🛠️ Technologies Used

Programming Language: C

Concepts: Bit Manipulation, File Handling

Image Format: BMP

Compiler: GCC

Platform: Linux / Terminal

# 📂 Project Structure
Steganography/
│

├── main.c

├── encode.c

├── decode.c

├── header.h

├── types.h

└── test_files/

# ▶️ Steps to Run the Project
1. Compile the Program
gcc *.c
2. Encode Secret Data
./a.out -e input.bmp secret.txt output.bmp
3. Decode Secret Data
./a.out -d output.bmp decoded.txt
# 📊 Example

# After encoding:

Input Image  : input.bmp
Secret File  : secret.txt
Output Image : output.bmp

# After decoding:

Decoded message successfully saved in decoded.txt
# 📚 Learning Outcomes

Understanding of steganography and data hiding techniques

Practical experience with bit manipulation in C

Implementation of encoding and decoding algorithms

Hands-on practice with file handling and image processing in C
