# Gene Finder Program

This bioinformatics tool identifies genes in DNA sequences by locating start codons (ATG) and stop codons (TAA, TAG, TGA). Developed for Semester 1 coursework, it processes sequences from CSV files to find open reading frames while checking for proper alignment.

## Project Overview

The program implements a gene-finding algorithm that reads DNA data and detects potential genes. It ensures the distance between start and stop codons is a multiple of three to maintain the correct reading frame. This approach helps in basic genomic analysis without needing advanced libraries.

## Key Features

- Dual versions in Python and C for flexibility in performance and ease of use
- Reads input from a simple CSV file named `dnaseq.csv`
- Detects multiple genes in a single sequence
- Validates codon alignment to avoid false positives
- Provides clear output showing identified genes and feedback

## How It Works

The algorithm starts by scanning for the ATG start codon in the sequence. Once found, it searches downstream for a stop codon and confirms the length is divisible by three. It then extracts the full gene sequence, including the stop, and continues scanning the rest of the input. This iterative process handles overlapping or multiple genes effectively.

## Getting Started

### Prerequisites

For the Python version, you need Python 3.x and no extra libraries beyond the standard ones. The C version requires a compiler like GCC and basic standard libraries.

### Input Format

Create `dnaseq.csv` in the project directory with a header "enter_data_line_by_line" followed by one DNA sequence per line, such as:

```
enter_data_line_by_line
ATGTAAGCATAGTAGCCCATG
ATGCCCGGGTAATTTATG
```

### Running the Program

**Python version:**
```bash
python SEM1_BIO_PROJECT.py
```

**C version:**
```bash
gcc SEM1_BIO_PROJECT.c -o genefinder
./genefinder
```

## Repository Structure

```
MY_PROJECTS/
├── SEM1_BIO_PROJECT.py      # Python code
├── SEM1_BIO_PROJECT.c       # C code
├── SEM_1_BIO_PROJECT.csv    # Sample data
├── README.md                # Documentation
└── LICENSE                  # MIT license file
```

## Example Output

The program displays a header with credits to contributors, reads the CSV, and lists found genes like `ATGTAA` and `ATGCCCTAG` from the sequence `ATGTAAATGCCCTAG`. It ends with instructions to edit the CSV for new inputs.

```
===============================GENE FINDER PROGRAM===============================
credits: ritvik, srihari, anubhav, shanmukha, sibiram and aditya
=================================================================================
This program reads your CSV file in the same directory[dnaseq.csv] for dna data
=====================================READING=====================================

The genes identified in the sequence 'ATGTAAATGCCCTAG' are:
ATGTAA
ATGCCCTAG

=================================================================================
Edit the CSV file containing the DNA sequence to change input parameters
```

## Technologies and Contributors

It uses Python's CSV module for input handling and C's standard I/O for efficiency. 

**Contributors:**
- Ritvik
- Srihari
- Anubhav
- Shanmukha
- Sibiram
- Aditya

## License

The project follows the MIT License and welcomes contributions via GitHub issues.

## Contact

Srihari Srivathsan - [@Srihari-Srivathsan-18](https://github.com/Srihari-Srivathsan-18)

Project Link: [https://github.com/Srihari-Srivathsan-18/MY_PROJECTS](https://github.com/Srihari-Srivathsan-18/MY_PROJECTS)

## Academic Context

This project was developed as part of the Artificial Intelligence curriculum at SRM Institute of Science and Technology (2024-2029).
