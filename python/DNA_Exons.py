
while True:
    dnaSeq = input("Enter DNA Sequence atleast with 100 character size :")
    print(dnaSeq)
    if(len(dnaSeq) < 100) :
        print("DNA sequence length is shorter than requested lenght :", len(dnaSeq))
    else :
        break;

exons1 = dnaSeq[:5]
exons2 = dnaSeq[5:]
print(exons1)
print(exons2)
        