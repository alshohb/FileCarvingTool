# File Carving Tool

## Description
This tool automatically extracts segments of a binary file based on specified header and footer byte patterns. It is designed to handle multiple occurrences of these patterns, extracting each segment as a separate file.

## Installation Instructions
1. Clone the repository to your local machine.
2. Ensure you have a C++ compiler installed, such as g++.
3. Navigate to the directory containing the project files.

## Usage Instructions
Compile the tool using the following command:

'g++ -o FileCarvingTool FileCarvingTool.cpp'


Then run the tool with:

'./FileCarvingTool <input_file> <header_hex> <footer_hex>'


Replace the placeholders with actual values:
- `<input_file>`: Path to the binary file you want to process.
- `<header_hex>`: Hexadecimal string representing the header pattern.
- `<footer_hex>`: Hexadecimal string representing the footer pattern.
