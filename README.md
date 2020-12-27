	README TEMA 2 - PA
	Student: Sima Nicoleta-Lavinia

	Problema 1
	O prima solutie pentru prima problema a fost sa blochez pe rand orasele
din permutarea data pana cand as fi gasit primul oras care inchidea toate caile 
lorzilor catre Robin. Solutia a fost ineficienta, iar pentru testele mari
algoritmul nu reusea sa se incadreze in timp deoarce se parcurgeau foarte multe
noduri. O cautare eficienta in vector este cautarea binara deorece se parcurge
doar bucata din vector de care am nevoie. Astfel, blochez toate nodurile pana
la mid = (left + right) / 2 si fac bfs din nodul 1. Am ales sa fac bfs pentru 
il aveam deja implementat de mine in laborator. La fel ca in laborator, calculez
distantele dintre sursa 1 si celelalte noduri si in cazul nodurilor blocate distanta
ramane initializata cu infinit. Pentru a vedea daca am blocat toate orasele in care
sunt lorzi verific distantele dintre orasul 1 in care se afla Robin si orasele lorzilor.
Daca distanta dintre nodul 1 si un nod care reprezinta un oras din care pleaza lorzii
este diferita de Infinit, inseamana ca exista cale pana la Robin si trebuie inchise
mai multe orase din permutare, drept pentru care maresc left. Daca, in schimb, toate
orasele au fost inchise voi cauta o varianta in care pot fi inchise mai putine orase
mergand spre stanga in vector. In acest caz rezultatul este elementul mid + 1 pe care
il retin mereu pe parcurs. 
Complexitate: cautare: O(log(N)) (in permutare sunt N - 1 noduri)
	      BFS: O(M + N) 
	      TOTAL: O(log(N)*(M + N)), N = numarul de noduri, M = numarul de muchii din graf
	
	Problema 2
	Problema 2 presupune calcularea drumul de cost minim intre o sursa si o destinatie.
O prima solutie este aplicarea algortimului Bellman-Ford deoarece este valabil si pentru
grafuri cu muchii de cost negativ. Complexitatea algorimului a fost prea mare pentru 
problema si depasea timpul alocat executiei. O alta varianta este sortarea topologica
a nodurilor folosind dfs. In acest caz ultimul nod care va fi finalizat, va fi nodul
sursa adica 1. Algoritmul de sortare topologica este cel implementat de mine in cadrul
laboratorului. In stiva sunt adaugate nodurile dupa ce sunt finalizate, iar la final 
voi adauga toate aceste noduri in vectorul topsort. In continuare actualizez distanta catre
celelalte noduri incepand cu muchiile care pleaca din nodul sursa, asigurand astfel calea cea
mai scurta de la sursa la restul nodurilor, exact ceea ce cautam.
La inceput toate vor fi initializate cu infinit, iar pe masura ce gasesc un drum mai 
scurt de la sursa la nod, actualizez distanta. Rezultatul final va fi distanta dintre nodul 
sursa si nodul destinatie care se va gasi in cost[dest].
Complexitate: sortare: O(N + M)
	      actualizare distante: O(N * M)
	      TOTAL: O(N * M + N + M), N = numarul de noduri, M = numarul de muchii din graf

	Problema 3
	Problema 3 presupune calculul energiei maxime cu care Robin ajunge in Notthingam.
Pentru aceasta, am ales sa folosesc Algoritmul lui Dijkstra deoarece energia consumata care 
tine loc de cost este mereu pozitiva. Am ales o coada de prioritati care este implementata ca 
max heap by default pentru a retine energia si nodul in care se ajunge. Robin porneste din nodul
sursa 1 cu energia E si pe masura ce se parcurge graful se calculeaza la fiecare pas efortul maxim
cu care poate ramane Robin atunci cand ajunge intr-un nod conform formulei. Daca energia 
deja calculata pentru a ajunge intr-un nod este mai mica decat energia calculata pentru 
a ajunge in acelasi nod, dar pe o cale diferita atunci se actualizeaza energia consumata
pana in nodul respectiv cu maximul dintre ele. La final rezultatul se va afla in vectorul
d in care calculez energia maxima ramasa pana la nod, pe ultima pozitie. Pentru a reconstrui
calea folosesc functia recursiva findPath care merge in sens invers de la nodul N pana cand 
parintele nodului curent este 0, caz in care am ajuns la sursa. Folosesc functia reverse din C++
pentru a recrea calea de la nodul 1 pana la nodul N.
Complexitate: Dijkstra: O(Nlog(M)), N = numarul de noduri, M = numarul de muchii
