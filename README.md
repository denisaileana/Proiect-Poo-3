# Proiect-Poo-3
● Cerințe comune tuturor temelor:
	1. utilizarea sabloanelor
	2. utilizarea STL
	3. utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const
	4. utilizarea conceptelor de RTTI raportat la template-uri
	5. tratarea excepțiilor
	6. citirea informațiilor complete a n obiecte, memorarea și afișarea acestora
● cerințe generale aplicate fiecărei teme din acest fișier:
	- să se identifice și să se implementeze ierarhia de clase;
	- clasele să conțină constructori, destructori, =, funcție prietena de citire a datelor;
	- clasa de baza sa conțină funcție virtuala de afisare, rescrisa în clasele derivate, 
	  iar operatorul de citire să fie implementat ca funcție prieten (în clasele derivate să se facă
	  referire la implementarea acestuia în clasa de baza).
Tema 5. În luna mai se organizează târgul mașinilor sport, astfel ca pasionatii se pot delecta cu modele din clasa:
COUPE
HOT-HATCH (modele hatchback de clasa mica și compacta cu motoare performante ce au la bază modele obișnuite), 
CABRIO(modele decapotabile cu acoperiș metalic sau din material textil)
SUPERSPORT(masini de viteza gen Audi R8, Bugatti Veyron, Lexus LF-A, etc.)
O parte din masinile supersport poate să fie vânduta chiar în cadrul expozitiei, dacă se face plata pe loc.
Structura de date: ​vector sau list <pair<masina, preț>> 
(se rețin mașinile vândute și prețul de vanzare, daca masina nu a fost vanduta prețul este -1)
Să se adauge toate campurile relevante pentru modelarea acestei probleme.
Să se construiască clasa template ​Expoziție care sa conțină nr total de mașini expuse (incrementat automat) și 
  un vector de obiecte de tipul unei mașini, alocat dinamic.
