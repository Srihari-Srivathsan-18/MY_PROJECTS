# Gene Finder Program

🧬 A bioinformatics tool to identify genes in DNA sequences by detecting start codons (ATG) and stop codons (TAA, TAG, TGA).

## 📋 Project Overview

This project was developed as part of Semester 1 coursework and implements a gene-finding algorithm that processes DNA sequences from CSV files. The program identifies open reading frames (ORFs) by locating start and stop codons while ensuring proper reading frame alignment.

## ✨ Features

- **Dual Implementation**: Available in both Python and C
- **CSV Input Support**: Reads DNA sequences from `dnaseq.csv` file
- **Multiple Gene Detection**: Identifies all genes within a DNA sequence
- **Reading Frame Validation**: Ensures detected genes maintain correct codon alignment
- **User-Friendly Output**: Clear display of identified genes with processing feedback

## 🔬 How It Works

The gene finder algorithm:

1. Searches for the start codon `ATG` in the DNA sequence
2. Looks for valid stop codons (`TAA`, `TAG`, `TGA`) downstream
3. Validates that the distance between start and stop codons is divisible by 3 (proper reading frame)
4. Extracts and displays the complete gene sequence including the stop codon
5. Continues searching for additional genes in the remaining sequence

## 🚀 Getting Started

### Prerequisites

**For Python version:**
- Python 3.x
- No additional libraries required (uses standard library)

**For C version:**
- GCC compiler or any C compiler
- Standard C libraries

### Input File Format

Create a file named `dnaseq.csv` in the same directory with the following format:

```csv
enter_data_line_by_line
ATGTAAGCATAGTAGCCCATG
ATGCCCGGGTAATTTATG
```

### Running the Program

**Python Version:**
```bash
python SEM1_BIO_PROJECT.py
```

**C Version:**
```bash
gcc SEM1_BIO_PROJECT.c -o genefinder
./genefinder
```

## 📁 Repository Structure

```
MY_PROJECTS/
├── SEM1_BIO_PROJECT.py      # Python implementation
├── SEM1_BIO_PROJECT.c       # C implementation
├── SEM_1_BIO_PROJECT.csv    # Sample DNA sequence data
├── README.md                # This file
└── LICENSE                  # MIT License
```

## 🧪 Example Output

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

## 🛠️ Technologies Used

- **Python 3**: High-level implementation with CSV module
- **C**: Performance-optimized implementation with file I/O
- **Standard Libraries**: csv, time (Python) | stdio.h, stdlib.h, string.h, unistd.h (C)

## 👥 Contributors

- Ritvik
- Srihari
- Anubhav
- Shanmukha
- Sibiram
- Aditya

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page.

## 📧 Contact

Srihari Srivathsan - [@Srihari-Srivathsan-18](https://github.com/Srihari-Srivathsan-18)

Project Link: [https://github.com/Srihari-Srivathsan-18/MY_PROJECTS](https://github.com/Srihari-Srivathsan-18/MY_PROJECTS)

## 🎓 Academic Context

This project was developed as part of the Artificial Intelligence curriculum at SRM Institute of Science and Technology (2024-2029).

---

**Note**: To use the program, ensure that `dnaseq.csv` is in the same directory as the executable. The CSV file should contain DNA sequences with one sequence per line under the header `enter_data_line_by_line`.
