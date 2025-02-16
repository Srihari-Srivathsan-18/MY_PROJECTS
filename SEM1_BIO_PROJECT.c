#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for that sleep function ig

#define maxlinelen 1024
#define maxgenelen 100

void genefinder(const char *dnaseq, char genes[maxgenelen][maxlinelen], int *geneCount) 
{
    const char *start_codon = "ATG";
    const char *stop_codons[] = {"TAA", "TAG", "TGA"};
    *geneCount = 0;

    int start_gene = 0;
    int len = strlen(dnaseq);

    while (start_gene < len) 
    {
        char *start_pos = strstr(dnaseq + start_gene, start_codon);
        if (start_pos == NULL) 
        {
            if (*geneCount == 0) 
            {
                strcpy(genes[0], "No gene in the given sequence");
                *geneCount = 1;
            }
            return;
        }

        start_gene = start_pos - dnaseq;

        for (int i = 0; i < 3; i++) 
        {
            char *stop_pos = strstr(dnaseq + start_gene + 3, stop_codons[i]);
            if (stop_pos != NULL) 
            {
                int stop_gene = stop_pos - dnaseq; 
                if ((stop_gene - start_gene) % 3 == 0) 
                {
                    strncpy(genes[*geneCount], dnaseq + start_gene, stop_gene - start_gene + 3);
                    genes[*geneCount][stop_gene - start_gene + 3] = '\0'; 
                    (*geneCount)++;
                    start_gene = stop_gene + 3; 
                    break;
                }
            }
        }

        start_gene++;
    }
}

int main() {
    printf("\n\n");
    printf("===============================GENE FINDER PROGRAM===============================\n");
    printf("credits: ritvik, srihari, anubhav, shanmukha, sibiram and aditya\n");
    printf("=================================================================================\n");
    sleep(1);
    printf("This program reads your CSV file in the same directory [dnaseq.csv] for DNA data\n");
    printf("=====================================READING=====================================\n");
    sleep(2);
    printf("\n\n");

    FILE *file = fopen("dnaseq.csv", "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return 1;
    }

    char line[maxlinelen];
    char genes[maxgenelen][maxlinelen];
    int geneCount;

    // Read the header line
    if (fgets(line, sizeof(line), file) == NULL) 
    {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    // Process each line
    while (fgets(line, sizeof(line), file)) 
    {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        printf("Processing DNA sequence: %s\n", line);
        genefinder(line, genes, &geneCount);

        sleep(1);
        printf("The genes identified in the sequence '%s' are:\n", line);
        for (int i = 0; i < geneCount; i++) {
            printf("%s\n", genes[i]);
        }
        printf("\n");
    }

    fclose(file);

    printf("=================================================================================\n");
    sleep(1);
    printf("Edit the CSV file containing the DNA sequence to change input parameters\n");

    return 0;
}

