# File Carving Tool

## Description
This tool automatically extracts segments of a binary file based on specified header and footer byte patterns. It is designed to handle multiple occurrences of these patterns, extracting each segment as a separate file.

## Installation Instructions
1. Clone the repository to your local machine.
2. Ensure you have a C++ compiler installed, such as g++.
3. Navigate to the directory containing the project files.

## Usage Instructions
Compile the tool using:
```bash
g++ -o FileCarvingTool FileCarvingTool.cpp

Run the tool with:
```bash
./FileCarvingTool <input_file> <header_hex> <footer_hex>
