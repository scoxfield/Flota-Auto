Introducere
Acest document servește drept documentație tehnică și ghid de utilizare pentru un sistem simplu de închiriere a mașinilor. Sistemul este implementat în limbajul C++ și permite utilizatorilor să adauge, actualizeze, șteargă și caute mașini disponibile, să facă rezervări și să anuleze rezervările existente. De asemenea, sistemul poate afișa lista mașinilor disponibile și rezervările efectuate.
Cuprins
1.	Introducere
2.	Instalare și rulare
3.	Utilizare 3.1. Meniul principal 3.2. Adăugare mașină 3.3. Actualizare mașină 3.4. Ștergere mașină 3.5. Căutare mașină 3.6. Realizare rezervare 3.7. Anulare rezervare 3.8. Afișare mașini disponibile 3.9. Afișare rezervări 3.10. Salvare date 3.11. Închidere
Rulare
Pentru a utiliza acest sistem de închiriere a mașinilor, urmați pașii de mai jos:
1.	Asigurați-vă că aveți instalat compilatorul C++ și mediul de dezvoltare adecvat (ex Visual Studio/Codeblocks)
2.	Puneti codul sursa intr-un fisier cu extensia .cpp (de exemplu, car_rental_system.cpp/orice alt nume).
3.	Compilați fișierul .cpp folosind compilatorul C++. De exemplu, folosind comanda g++ car_rental_system.cpp -o car_rental_system.
4.	Rulați programul generat. De exemplu, folosind comanda ./car_rental_system|orice alt nume./ prin linia de comanda
Utilizare
3.1. Meniul principal
După ce rulați programul, veți fi întâmpinat de un meniu principal. Acesta afișează o listă de opțiuni disponibile și vă permite să selectați o acțiune prin introducerea unui număr corespunzător opțiunii dorite.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/bab7cea6-63eb-45f4-b6cb-c229105654c3)




 
3.2. Adăugare mașină
Pentru a adăuga o mașină nouă în sistem, selectați opțiunea "Adaugă mașină" din meniul principal. Veți fi solicitat să introduceți următoarele informații despre mașină:
•	Marcă (brand)
•	Model (type)
•	Număr de locuri (seats)
Introduceți informațiile cerute și mașina va fi adăugată în sistem.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/27a22da8-3a7e-4ecf-848a-003645389c82)

 
3.3. Actualizare mașină
Dacă doriți să actualizați informațiile despre o mașină existentă, selectați opțiunea "Actualizează mașină" din meniu. Dupa care ve-ti fi nevoiti sa furnizati 
•	Marcă (brand)
•	Model (type)

In cazul in care masina dumneavoastra a fost gasita cu succes in fisier, aceasta va fi actualizata iar dumneavoastra ve-ti introduce noile date :

•	Marcă (brand)
•	Model (type)
•	Număr de locuri (seats)

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/df6ab422-988f-4d78-9e1d-ab364c31ad9e)

 
3.4. Ștergere mașină
Pentru a șterge o mașină din sistem, selectați opțiunea "Șterge mașină" din meniul principal. Veți fi solicitat să introduceți marca & modelul. Introduceți datele corespunzatoare și mașina va fi eliminată din sistem.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/cc462658-fde4-465f-9bc1-6ea2f4a67f31)

 
3.5. Căutare mașină
Pentru a căuta o mașină în sistem, selectați opțiunea "Caută mașină" din meniul principal. Veți fi solicitat să introduceți un criteriu de căutare (de exemplu, marcă, model sau număr de locuri). Introduceți criteriul și sistemul va afișa mașinile care îndeplinesc criteriul specificat.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/95aa32b2-4211-4bb5-bc0a-0584cdb41d14)

 
3.6. Realizare rezervare
Pentru a efectua o rezervare pentru o mașină disponibilă, selectați opțiunea "Realizează rezervare" din meniul principal. Veți fi solicitat să introduceți un nume de utilizator pentru mașina pe care doriți să o rezervați și detaliile rezervării (de exemplu, numele dvs. și data rezervării). Introduceți informațiile cerute și rezervarea va fi înregistrată în sistem.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/8bb65ce5-e6fe-44a8-9763-be44c17b389c)

 
3.7. Anulare rezervare
Dacă doriți să anulați o rezervare existentă, selectați opțiunea "Anulează rezervare" din meniul principal. Veți fi solicitat să introduceți un nume de utilizator pentru rezervarea pe care doriți să o anulați. Introduceți ID-ul/numele corespunzător și rezervarea va fi anulată în sistem.


 ![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/dec7560a-a51e-4a4c-9c2d-3c095c502679)

 
3.8. Afișare mașini disponibile
Pentru a vedea lista mașinilor disponibile în sistem, selectați opțiunea "Afișează mașini disponibile" din meniul principal. Sistemul va afișa informațiile despre mașinile care sunt disponibile pentru închiriere.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/3cf4abaf-db06-40a5-a115-5b6ca67d5786)

 
3.9. Afișare rezervări
Pentru a afișa lista rezervărilor efectuate, selectați opțiunea "Afișează rezervări" din meniul principal. Sistemul/terminal-ul va afișa informațiile despre rezervările existente, inclusiv detalii despre mașină și informații despre rezervare.

![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/88775356-0db7-460c-83d6-c22450527b5c)

 
3.10. Salvare date
Pentru a salva datele sistemului, inclusiv mașinile și rezervările, selectați opțiunea "Salvează date" din meniul principal. Aceasta va salva toate informațiile într-un fișier pentru utilizarea ulterioară.

 ![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/72f5289a-bf1d-4f69-8847-864c24e8d039)
 ![image](https://github.com/scoxfield/Flota-Auto/assets/87240939/0e75ac83-8487-48b8-b0c9-14b0ab5d4293)

 
3.11. Închidere
Pentru a închide sistemul, selectați opțiunea "Închide" din meniul principal. Toate datele nesalvate vor fi pierdute, așa că asigurați-vă că ați salvat înainte de a închide.
