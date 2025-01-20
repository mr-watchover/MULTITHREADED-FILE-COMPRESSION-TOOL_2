# MULTITHREADED-FILE-COMPRESSION-TOOL_2

**COMPANY**: CODTECH IT SOLUTIONS

**NAME**: MOHAMMAD MUSTAFA KARAM KHALID

**INTERN ID**: CT08GIX

**DOMAIN NAME**: C++ PROGRAMMING

**BATCH DURATION**: December 25th, 2024 to January 25th, 2025.

**MENTOR NAME**: NEELA SANTHOSH

# DESCRIPTION:The multithreaded file compression tool is a C++ application designed to optimize file compression and decompression using multithreading. This project leverages parallel processing to improve performance by splitting files into smaller chunks that can be processed simultaneously. It uses the widely adopted zlib library for compression and decompression, ensuring efficient and standard file handling.

Objective
The primary goal of this project is to demonstrate the performance benefits of multithreading in file compression and decompression tasks. By distributing the workload across multiple threads, the tool achieves faster processing times, particularly for large files. It also provides users with a straightforward menu-driven interface to interact with the application.

Features
File Compression:

Compresses large files into smaller, optimized formats using the deflate algorithm from the zlib library.
Allows users to choose the number of threads for processing, offering flexibility in performance optimization.
File Decompression:

Decompresses files compressed by the tool, restoring them to their original form using the inflate algorithm.
Handles errors gracefully, ensuring data integrity during decompression.
Multithreading:

Divides the file into chunks, which are processed by individual threads for parallel compression.
Reduces overall compression time by utilizing available CPU cores efficiently.
User-Friendly Interface:

Provides a simple, menu-driven interface for selecting operations (compression or decompression).
Prompts users for file names and thread count, making the tool intuitive to use.
Performance Measurement:

Displays the time taken for compression, allowing users to observe the benefits of multithreading in real-time.

How It Works
1. Compression Process
The input file is read into memory and divided into equal-sized chunks. The number of chunks is determined by the user-defined thread count.
Each chunk is assigned to a thread, which compresses it independently using zlib's deflate function.
The compressed chunks are written sequentially to the output file, ensuring they can be decompressed in the correct order.
2. Decompression Process
The compressed file is read into memory as a single stream.
The inflate function from zlib processes the data sequentially, decompressing it back into its original form.
The decompressed data is written to the specified output file.
3. Multithreading Implementation
The std::thread library is used to manage threads.
For compression, each thread processes a specific chunk of data in parallel.
Threads synchronize by joining at the end of their execution, ensuring all chunks are processed before the program proceeds.
4. Performance Demonstration
The program measures the time taken to compress a file using the high-resolution clock from the <chrono> library.
Users can test the tool with varying thread counts to observe the impact of multithreading on performance.

#OUTPUT OF THE TASK: 
![Image](https://github.com/user-attachments/assets/cc12d1a3-2107-4848-ab35-798b2c3197bc)
