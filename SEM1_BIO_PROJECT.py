import csv
import time

print("")
print("")
print("===============================GENE FINDER PROGRAM===============================")
print("credits: ritvik, srihari, anubhav, shanmukha, sibiram and aditya")
print("=================================================================================")
time.sleep(1)
print("This program reads your CSV file in the same directory[dnaseq.csv] for dna data")
print("=====================================READING=====================================")
time.sleep(2)
print("")
print("")
def genefinder(dnaseq):
    start_codon = "ATG" 
    stop_codons = ["TAA", "TAG", "TGA"]  
    genes = []  
    start_gene, stop_gene = 0, 3
    
    while start_gene < len(dnaseq):  
        start_gene = dnaseq.find(start_codon, start_gene)
        if start_gene == -1:
            return ["No gene in the given sequence"]
        
        for stop_codon in stop_codons:
            stop_gene = dnaseq.find(stop_codon, start_gene + 3)
            if (stop_gene != -1) and (stop_gene - start_gene) % 3 == 0:
                genes.append(dnaseq[start_gene:stop_gene + 3])
                start_gene = stop_gene + 3
                stop_gene = start_gene + 3
                break
        else:
            start_gene += 1
            stop_gene += 1

    return genes

with open("dnaseq.csv", mode="r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        dnaseq = row["enter_data_line_by_line"]
        genes = genefinder(dnaseq)
        time.sleep(1)
        print(f"The genes identified in the sequence '{dnaseq}' are:")
        for gene in genes:
            print(gene)
        print()  
print("=================================================================================")
time.sleep(1)
print("Edit the CSV file containing the dna sequence to change input parameters")

