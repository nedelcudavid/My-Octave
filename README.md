Nedelcu Andrei David
314CA

Algoritmul Iterative
Functia reprezinta o implementare a algoritmului Iterative, aceasta primeste
 ca argumente: numele fisierului de unde preluam graful, coeficientul d si
eroarea. Functia intoarce apoi vectorul P.

Dupa ce am extras informatiile necesare  din fisier, am aflat numarul de resurse web (N)
de pe prima pozitie a matricei fisierului. Am intializat matricea de adiacenta, A, si
vectorul de vecini, Q, cu 0. Apoi am parcurs informatiile din fisier
 si am construit matricea de vecini si matricea de adiacenta.
Dupa ce am terminat de construit matricea de adiacenta si vectorul de vecini,
 il aduc pe Q la o forma diagonala si calculez matricea de graduri, M, dupa
 formula: M = (inv(Q) * A)'
Calculul vectorului P este facut pana cand norma vectorului P de la pasul
 curent si vectorul P de la pasul anterior este mai mica decat eps. Vectorul
 P s-a calculat dupa formula: R = d * M * + (1 - d) / N * ones(N, 1)

Algoritmul Algebraic
Functia reprezinta o implementare a algoritmului Algebraic. Functia primeste ca
argumente: numele fisierului din care se citeste graful, coeficientul d si 
eroarea care apare in calculul vectorului P. Functia intoarce vectorul P.

Implementarea functiei este asemanatoare cu implementarea functiei Iterative. 
Singura diferenta dintre cele doua functii fiind calcularea vectorului P.

Vectorul P este calculat dupa formula: R = GramSchm(I - d * M) * (1 - d) / N * ones(N, 1),
 unde functia GramSchm() este o functie care calculeaza inversa unei matrici,
 folosind metoda Gram-Schmidt. Implementarea algoritmului Gram-Schmidt este 
cea de la laborator.

Gradul de apartenenta
Functia PageRank primeste ca argumente numele unui fisier si parametrii d si
 eps. Functia afiseaza intr-un nou fisier: numarul de pagini web analizate, N,
 vectorul P calculat cu algoritmul Iterative, vectorul P calculat cu 
algoritmul Algebraic si un clasament al celor mai importante pagini, pe prima
 coloana aflandu-se locul obtinut, pe a doua coloana numarul paginii care a 
obtinut acest loc, iar pe ultima coloana se afla gradul de apartenenta a acestei
 pagini la multimea paginilor importante.

La inceputul functiei deschid fisierul primit ca parametru si citesc numarul de 
resurse web pentru a afla cele 2 valor v1 si v2.

Dupa ce am aflat valorile necesare, am inchis fiserul pe care l-am primit ca 
parametru si am creat fisierul de iesire. Il deschid, afisez N, afisez vectorul 
PR1 aflat cu algoritmul Iterative, afisez vectorul calculat cu algoritmul Algebraic.
 Sortez descrescator vectorul PR1 aflat cu algoritmul Algebraic, folosinf functia sort()
 si sortez si un vector de indecsi, idx, care prezinta aranjarea elementelor din vector.
 Apartenenta este calculata intr-o functie cu acelasi nume. Functia primeste ca parametru 
un numar x ce semnifica un element din vectorul PR sortat, val1 si val2 si care calculeaza 
valoarea functiei membru in punctul x. Dupa ce terminam tot de afisat in fisier, il inchidem.