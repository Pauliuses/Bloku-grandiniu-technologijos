# Blokų grandinių technologijos

# V0.1

## Naudoti tekstiniai failai
- **g.txt**, kuris turi vieną simbolį "g"
- **h.txt**, kuris turi vieną simbolį "h"
- **2000.txt**, kuris turi 2000 atsitiktinai sugeneruotų simbolių
- **8000.txt**, kuris turi 8000 atsitiktinai sugeneruotų simbolių
- **3000b.txt** ir **3000a.txt**, kurie turi 3000 atsitiktinai sugeneruotų simbolių ir skiriasi tik vienu simboliu (1594 eilutėje skiriasi simboliai Z ir R)
- **empty.txt**, kuris yra tuščias
- **10x25000.txt**, kuriame yra 25000 eilučių po 10 simbolių
- **100x25000.txt**, kuriame yra 25000 eilučių po 100 simbolių
- **500x25000.txt**, kuriame yra 25000 eilučių po 500 simbolių
- **1000x25000.txt**, kuriame yra 25000 eilučių po 1000 simbolių
- **difsymbol.txt**, kuris turi 200000 porų kurios skiriasi 1 simboliu
- **huge.txt**, kuris turi 32000000 simbolių
- **konstitucija.txt**, kuris turi dėstytojų pateiktą konstitucijos tekstą

# Maišos funkcijos rezultatai
Naudojant failą **g.txt** gaunamas outputas:
![image](https://user-images.githubusercontent.com/100035297/192888635-756d96ae-2f2a-44f4-9d8f-1a9749df1486.png)

Naudojant failą **h.txt** gaunamas outputas:
![image](https://user-images.githubusercontent.com/100035297/192888732-b27bf45a-76ea-47a0-9edb-988b47c0cfcd.png)

Naudojant failą **2000.txt** gaunamas outputas:
![image](https://user-images.githubusercontent.com/100035297/192888924-d4095494-62a1-43bd-83c1-3dc915393830.png)

Naudojant failą **8000.txt** gaunamas outputas:
![image](https://user-images.githubusercontent.com/100035297/192889005-54d9e6d4-f6f8-442c-b8ca-008f30c5b1ca.png)

Naudojant failus **3000a.txt** ir **3000b.txt** gaunami outputai:
![image](https://user-images.githubusercontent.com/100035297/192889169-6546f972-a238-411d-8220-11b63006cfc5.png)

![image](https://user-images.githubusercontent.com/100035297/192889149-069b7657-4d39-46fe-be4d-966cfd409d45.png)

Naudojant failą **empty.txt** gaunamas outputas:
![image](https://user-images.githubusercontent.com/100035297/192889266-709d8f8d-a07b-4611-a859-6874d832cf8a.png)


# Maišos funkcijos trukmės priklausomybė nuo simbolių (teksto) kiekio:
![image](https://user-images.githubusercontent.com/100035297/192889674-ad062e6a-7172-48cb-bb52-75f7bebc5a77.png)

# Maišos funkcijos trukmės priklausomybe nuo eilučių kiekio:
![image](https://user-images.githubusercontent.com/100035297/192897033-1b74c751-02bb-49a8-80e8-8bf0e66d6325.png)


# Atsparumo kolizijai tyrimas
Tyrimui buvo naudojami 4 tekstiniai failai: **10x25000.txt**, **100x25000.txt**, **500x25000.txt**, **1000x25000.txt**
![image](https://user-images.githubusercontent.com/100035297/192890213-28a179f5-0da6-4e25-bf35-7e4cda27a35d.png)
![image](https://user-images.githubusercontent.com/100035297/192890237-24b3325e-7333-490e-8fea-24483c0fcdb6.png)
![image](https://user-images.githubusercontent.com/100035297/192890248-407eac32-efa3-4a05-8779-df696e37b99f.png)
![image](https://user-images.githubusercontent.com/100035297/192890256-7e29905e-3010-4c1a-9043-26afc47a11c5.png)

# Minimalios, maksimalios ir vidutinės "skirtingumo" reikšmės
![image](https://user-images.githubusercontent.com/100035297/192890538-aae0743c-d907-4505-92f9-8849773a2be9.png)

# Išvados
Šios maišos funkcijos stiprioji pusė yra trumpas veikimo laikas. Su dideliais failas nekilo sunkumų ir programa greitai pateikdavo maišos funkcijos rezultatą. Galima teigti, jog dirbant su dar didesniais simbolių eilučių kiekiais atsirastų kolizijų, todėl programą būtų galima tobulinti iki kol kolizijų skaičius sumažėtų iki minimumo.

# Kaip pasileisti programą
- Parsisiųsti ir įsidiegti C++ kompiliatorių
- Norint sukompiliuoti programą terminale rašykite **make**
- Norint paleisti programą terminale rašykite **./prog**
