# Python3 code does the following  
# Takes DNA sequence with atleast 100 characters and prints 2 exons
# exons1 from begining to 62 length, exons2 from 82nd to end of DNA sequence.

# while loop ensures execution atleast once
while True:
    dnaSeq = input("Enter DNA Sequence atleast with 100 character size :")
    print(dnaSeq)
    #If DNA sequence length is less than 100 characters, it prompts to re-enter
    if(len(dnaSeq) < 100) : 
        print("DNA sequence length is shorter than requested lenght :", len(dnaSeq))
    #When user enters proper length, it breaks from loop for further processing.
    else :
        break;

#substring which takes from start to till 62 character length.
exons1 = dnaSeq[:62]
#substing which takes from 81st character till end of the sequence.
exons2 = dnaSeq[81:]
print("Exons1 sequence till 62 character :", exons1)
print("Exons2 sequence from 82 character till end :",exons2)
        