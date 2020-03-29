/* Programming Problem

DNA analysis is an important part of medical exploration and
discovery. In this assignment^*, we examine both hemoglobin genes for
each of four people, with each gene consisting of 444 DNA bases
(A,C,T,G). These are the four bases (letters) that make up DNA.

Sickle-cell anemia is a disorder that is caused by a single mutation
in the hemoglobin gene.

A sickle hemoglobin gene has a T in the 20th position.
A person is anemic if he/she has two sickle hemoglobin genes.
A person is a carrier if he/she has one sickle hemoglobin gene.
Otherwise, the person is normal.

The input file, called dna.txt and found on UR Courses, contains the DNA of
the two hemoglobin genes of four people. The file contains the gene DNA
information in this order:
geneA1
geneA2
geneB1
geneB2
geneC1
geneC2
geneD1
geneD2
where 1 and 2 denote the first and second gene, and A,B,C,D denote people.
The required information is found in the first 3552 characters of dna.txt,
that is, there is no whitespace before or between the eight genes.
Create a report, called DNAanalysis.txt, that indicates whether each person
is anemic, a carrier, or normal. For example,
Person X is anemic.
Person Y is normal.
Person Z is a carrier.

Two individuals are related if they share at least one gene.
Determine whether any of the above four individuals are related
and indicate this in DNAanalysis.txt. For example,
Person X is related to person Y.

Include a subfunction, called SameGene, that takes two character arrays and their size,
and returns true if they are the same gene; and returns false, otherwise.

Upload your C++ program and output to UR Courses.

Hint: you may want to use eight arrays of type char and of size 444.

Txt file: dna.txt

ATGGTGCATCTGACTCCTGAGGGTGATAATGCCGTTACTGCCCTGTGGGGCAAGGTGAACGTGGATGAAGTTGGTGGCAGGGCCCTGGGCAGGCTGCTGGTGGTCTACCCTTGGACCCAGAGGTTCTTTGAGTCCTTTGGGGATCTTTCCACTCCTGATGCTGTTATGGGCAACCCTAAGGTGAAGGCTCATGGCAAGAAGCGGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGGACAACCTCAAGGGCACCTTTGCCACACTGAGTGAGCTGCACTGTGATAAGCTGCACGTGGATCCTGAGAACTCGAGGCTCCTTCGCAACGTGCTGAAGTGTGTGCTGGCCCATCACTTTGGCAAAGAATTCACGCCACCAGTGCAGGCTGCCTATCAGAAAGTGGTGGCTGGTGTGGCTAATGCCCTGGCCCACAAGTATCACTAAATGGTGCATCTGACTCCTGAGGAGAAGTCTGCCGTTACTGCCCTGTGGGGCAAGGTGAACGTGGATGAAGTTGGTGGTGAGGCCCTGGGCAGGCTGCTGGTGGTCTACCCTTGGACCCAGAGGTTCTTTGAGTCCTTTGGGGATCTGTCCACTCCTGATGCTGTTATGGGCAACCCTAAGGTGAAGGCTCATGGCAAGAAAGTGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGGACAACCTCAAGGGCACCTTTGCCACACTGAGTGAGCTGCACTGTGACAAGCTGCACGTGGATCCTGAGAACTTCAGGCTCCTGGGCAACGTGCTGGTCTGTGTGCTGGCCCATCACTTTGGCAAAGAATTCACCCCACCAGTGCAGGCTGCCTATCAGAAAGTGGTGGCTGGTGTGGCTAATGCCCTGGCCCACAAGTATCACTAAATGGTGCATCTGACTCCTGAGGAGAAGTCTGCCGTTACTGCCCTGTGGGGCAAGGTGAACGTGGATGAAGTTGGTGGTGAGGCCCTGGGCAGGCTGCTGGTGGTCTACCCTTGGACCCAGAGGTTCTTTGAGTCCTTTGGGGATCTGTCCACTCCTGATGCTGTTATGGGCAACCCTAAGGTGAAGGCTCATGGCAAGAAAGTGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGGACAACCTCAAGGGCACCTTTGCCACACTGAGTGAGCTGCACTGTGACAAGCTGCACGTGGATCCTGAGAACTTCAGGCTCCTGGGCAACGTGCTGGTCTGTGTGCTGGCCCATCACTTTGGCAAAGAATTCACCCCACCAGTGCAGGCTGCCTATCAGAAAGTGGTGGCTGGTGTGGCTAATGCCCTGGCCCACAAGTATCACTAAATGGTGCATCTGACTCCTGTGGAGAAGTCTGCCGTTACTGCCCTGTGGGGCAAGGTGAACGTGGATGATGTTGGTGGTGAGGCCTTCGGCAGAGGGCTGGTGGTCTACCCTTGGACCCAGAGGTTCTTTGAGTAAGTTGGGGATCTGTCCACTCCTGATGCTGTTATGGGCAACCCTAAGGTGAAGGCTCATGGCAAGAAATTGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGAAGAACCTCAACTTCACCTTTGCCACACTGAGTGAGCTGCACTGTGACAAGCTGCACGTGGATCCTGAGAACTTCAGGCTCCTGGGCAACGTGCTGGTCTGTGTGCTGGCCCATCACTTTGGTCGAGAATTCACCCCACCAGTGCAGGCTGCCTATCAGAAAGGCATGGCTGGTGTGGCTAATGCCCTGGCCCACAATCCTCCCTAAATGGTGCATCTGACTCCTGAGGGTGATAATGCCGTTACTGTTCTGTGGGGCAAGGTGAACGTGGATGCGGTTGGTGGCAGGGCCCTGGGCAGGCTGCTGGTGGTCTACCCTTGGACCCAGAGGTTCTTTGAGTCCTTTGGGGATCTTTCCACTCCTGGAGCTGTTCAAGGCAACCCTAAGGTGAAGGCTCATGGCAAATAGCGGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGAAAAACCTCAAGGGCACGTTTGCCACACTGAGTGAGCTGCACTGTGATAAGCTGCACGTGGATCCTGAGAACTCGAGGCTCCTTCGCAACGTGCTGAAGTGTGTGCTGGCCCATCACTTTGGGACAGAATAGTCGCCACCAGTGCAGGCTGCCTAATTGAAAGTGTAAGCTGGTGTGGCTAATGCCCTGGCCCACAAGTATTGATAAATGGTGCATCTGACTCCTGAGCGTGATAATGCCGTTACTGTTCTGTGGGGCAAGGAGGACGTGGGTCCGGTTGGTGGCAGGGCCCTGGGCAGGCTGCTGGTGGTCTACCCTTGGACCCAGCGGTTCTTTGAGTCCTTTGGGGATCTTTCCACTCCTGGAGCTGTTCAAGGCAACCCTAAGGTGAAGGCTCATGGCCTTTAGCGGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGAAAAACCTCAAGGGCACGTTTGCCACACTGAGTGAGCTGCACTGTGATAAGCTGCACGTGGATCCTGAGAACTCGAGGCTCCTTCGCAACGTGCTGAAGTGTGTGCTGGCCCATCACTTTGGGACAGAATAGTCGCCACCAGTGCAGGCTGCCTAATTGAAAGTGTAAGCTGGTGTGGCTAATGCCCTGGCCCACAAGTATTGATAAATGGTGCATCTGACTCCTGTGGGTGATAATGCCGTTACTGTTCTGTGGCGCAAGGTGAACGTGGATGCGGTTGGTGGCAGGGCCCTGGGCAGGCTGCTGGTGGTCTACCCTTGGACCCAGAGTTTCTTTGAGTGCTTTGGGGTTCTTTCCACTCCTGGAGCTGTTCAAGGCAACCCTAAGGTGAAGGCTCATGGCAAATAGCGGCTCGGTGCCTTTAGTGATGGCCTGGCTCACCTGAAAAACCTCAAGGGCACGTTTCCCACACGGAGTGAGCTGCGCTGTGATAAGCTGCACGTGGATCCTGAGAACTTGAGGCTCCTTCGCAACGTGCTGAAGTGTGTGCTGGCCCATCACTTTGGGACAGAATAGTCGCCACCAGTGCAGGCTGCCTAATTGAAAGTGTAAGCTGGTGTGGCTAATGCCCTGGTCCAGAAGTATTGATAAATGGTGCATCTGACTCCTGTGGGTGATAATGCCGTTACTGTTCTGTGGCGCGAGGTGAACGTGGATGCGGTTGGTGGCAGGGCCCTGGGCAGGCTGGTGGTGGTCTACCCTTGGACCCAGAGTTTCTTTGAGTGCTTTGGGGTTCTTTCCACTCCTGGAGCTGTTCAAGGCAACCCTAAGGTGAAGGGTCATCGCAAGTAGCGGCTCGGTGCCTTTAGTGATGGCCTGGGTCACCTGAAAAACCTCAAGGGCACGTTTCCCACACGGAGTGAGCTGCGCTGTGATACGCTGCACGTGGATCCTGAGAACTTGAGGCTCCTTCGCACCGTGCTGAAGTGTGTGCTGGCCCGTCACTTTGGGACAGAATAGTCGCCACCACTGCAGGCTGCCTAATTGAAAGTGTAAGCTGGTGTGGCTAATGCCCTGGTACAGAAGTATTGATAA
*/
================ main.cpp ===================

#include <iostream>
#include <fstream>

using namespace std;

int checkIfPatientIsAnemic(char gene1[444], char gene2[444])
{
const int anemicPosition = 20;
int anemicMatchCount = 0;

if((gene1[anemicPosition-1] == 'T') && (gene2[anemicPosition-1] == 'T'))
anemicMatchCount = 2;
else if((gene1[anemicPosition-1] == 'T') || (gene2[anemicPosition-1] == 'T'))
anemicMatchCount = 1;

return anemicMatchCount;
}

bool sameGene(char gene1[444], char gene2[444])
{
bool isSame= true;
for(int i =0; i<444; i++)
{
if(gene1[i]!= gene2[i])
{
isSame = false;
break;
}

}

return isSame;
}

void printDNAAnalasysForPatientsToFile(char patient, int anemicCount, ofstream& outFileWriter)
{

switch(anemicCount)
{
case 0:
outFileWriter << "Person " << patient << " is normal" << std::endl;
cout << "Person " << patient << " is normal" << std::endl;
break;
case 1:
outFileWriter << "Person " << patient << " is carrier" << std::endl;
cout << "Person " << patient << " is carrier" << std::endl;
break;
case 2:
outFileWriter << "Person " << patient << " is anemic" << std::endl;
cout << "Person " << patient << " is anemic" << std::endl;
break;
}


}

int main()
{

ifstream fReader;
char ch;
const int GENE_LENTH = 444;
int i = 0, j=0;
char geneA1[GENE_LENTH], geneA2[GENE_LENTH];
char geneB1[GENE_LENTH], geneB2[GENE_LENTH];
char geneC1[GENE_LENTH], geneC2[GENE_LENTH];
char geneD1[GENE_LENTH], geneD2[GENE_LENTH];

cout << "This program compares Genes codes and finds if patent is anemic, normal, carrier" << std::endl;
cout << "Also checks if any of the persons are related by checking common genes" <<std::endl;

fReader.open ("dna.txt"); // open file in read mode

if (!fReader) // print error if file doesnt exists
{
cout << "File not present" << endl;
exit(1);
}

// reads from dna.txt file character by character and writes to each gene code for A, B, C , D Persons
while (fReader)
{
fReader.get(ch);

if(i >= 0 && i <= (GENE_LENTH -1))
{
geneA1[i%GENE_LENTH] = ch;
}
else if (i >= GENE_LENTH && i <= (2*GENE_LENTH -1))
{
geneA2[i%GENE_LENTH] = ch;
}
else if (i >= (2 * GENE_LENTH) && i <= (3*GENE_LENTH -1))
{
geneB1[i%GENE_LENTH] = ch;
}
else if (i >= (3 * GENE_LENTH) && i <= (4*GENE_LENTH -1))
{
geneB2[i%GENE_LENTH] = ch;
}
else if (i >= (4 * GENE_LENTH) && i <= (5*GENE_LENTH -1))
{
geneC1[i%GENE_LENTH] = ch;
}
else if (i >= (5 * GENE_LENTH) && i <= (6*GENE_LENTH -1))
{
geneC2[i%GENE_LENTH] = ch;
}
else if (i >= (6 * GENE_LENTH) && i <= (7*GENE_LENTH -1))
{
geneD1[i%GENE_LENTH] = ch;
}
else if (i >= (7 * GENE_LENTH) && i <= (8*GENE_LENTH -1))
{
geneD2[i%GENE_LENTH] = ch;
}


i++;

}

int anemicCount = 0;
ofstream outFileWriter;
outFileWriter.open ("DNAanalysis.txt");

// Calculates if any of the Gene code has anemia and writes the same to file as normal, carrier, anemic
anemicCount = checkIfPatientIsAnemic(geneA1, geneA2);
printDNAAnalasysForPatientsToFile('A',anemicCount,outFileWriter);

anemicCount = checkIfPatientIsAnemic(geneB1, geneB2);
printDNAAnalasysForPatientsToFile('B',anemicCount,outFileWriter);

anemicCount = checkIfPatientIsAnemic(geneC1, geneC2);
printDNAAnalasysForPatientsToFile('C',anemicCount,outFileWriter);

anemicCount = checkIfPatientIsAnemic(geneD1, geneD2);
printDNAAnalasysForPatientsToFile('D',anemicCount,outFileWriter);

// Checks each combination of Genes if related to any other person for each A, B, C, D Persons
if(sameGene(geneA1,geneB1) ||sameGene(geneA1,geneB2) || sameGene(geneA2,geneB1) || sameGene(geneA2,geneB2))
{
outFileWriter << "Person A is related to Person B " << std::endl;
cout << "Person A is related to Person B " << std::endl;
}
if(sameGene(geneA1,geneC1) ||sameGene(geneA1,geneC2) || sameGene(geneA2,geneC1) || sameGene(geneA2,geneC2))
{
outFileWriter << "Person A is related to Person C " << std::endl;
cout << "Person A is related to Person C " << std::endl;
}
if(sameGene(geneA1,geneD1) ||sameGene(geneA1,geneD2) || sameGene(geneA2,geneD1) || sameGene(geneA2,geneD2))
{
outFileWriter << "Person A is related to Person D " << std::endl;
cout << "Person A is related to Person D " << std::endl;
}
if(sameGene(geneB1,geneC1) ||sameGene(geneB1,geneC2) || sameGene(geneB2,geneC1) || sameGene(geneB2,geneC2))
{
outFileWriter << "Person B is related to Person C " << std::endl;
cout << "Person B is related to Person C " << std::endl;
}
if(sameGene(geneB1,geneD1) ||sameGene(geneB1,geneD2) || sameGene(geneB2,geneD1) || sameGene(geneB2,geneD2))
{
outFileWriter << "Person B is related to Person D " << std::endl;
cout << "Person B is related to Person D " << std::endl;
}
if(sameGene(geneD1,geneC1) ||sameGene(geneD1,geneC2) || sameGene(geneD2,geneC1) || sameGene(geneD2,geneC2))
{
outFileWriter << "Person D is related to Person C " << std::endl;
cout << "Person D is related to Person C " << std::endl;
}

outFileWriter.close ();

return 0;
}
