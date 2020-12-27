#include <bits/stdc++.h>
using namespace std;

const int kNmax = 200005;
const int kInf = 0x3f3f3f3f;

class Task {
 public:
	void solve() {
		read_input();
		print_output(compute_solution());
	}

 private:
	int N, M, K;
	vector<int> lc;
	vector<int> cities;
	vector<int> adj[kNmax];

void read_input() {
        ifstream fin("p1.in");		// citire date
        fin >> N >> M >> K;
        for (int i = 1, x; i <= K; i++) {
        	fin >> x;
        	lc.push_back(x);
        }
        for (int i = 1, x; i <= N - 1; i++) {
        	fin >> x;
        	cities.push_back(x);
        }
        for (int i = 1, u, v; i <= M; i++) {
        	fin >> u >> v;
        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }
        fin.close();
	}

	int compute_solution() {		// calcularea solutiei
		int left = 0;
		int right = cities.size() - 1;
		int min_cities;
		while (left <= right) {			// cautare binara in vector
			int mid = (left + right) / 2;
			// vector de noduri selectate in explorare
			vector<bool> selected(N + 1, false);
			// vector de noduri blocate din permutari
			vector<bool> blocked(N + 1);
			// vector de distante de la 1 la celelalte noduri
			vector<int> d(N + 1, kInf);
			// se blocheaza primele mid noduri
			for (int i = 0; i <= mid; i++) {
				int j = cities[i];
				blocked[j] = true;
			}

			queue<int> Q;								// coada folosita in BFS
			d[1] = 0;
			Q.push(1);

			while (!Q.empty()) {
				int u = Q.front();
				for (int v : adj[u]) {
					/* daca nodul curent nu este blocat si nici selectat in BFS */
					if (d[v] == kInf &&  blocked[v] == false && selected[v] == false) {
						d[v] = d[u] + 1;		// distanta noua
						selected[v] = true;		// se adauga la nodurile selectate
						Q.push(v);
					}
				}
				selected[u] = true;
				Q.pop();
			}

			int i = 0;
			/* parcurg toate orasele din care pornesc lorzii si daca in explorare
			am atins vreun oras inseamna ca lorzii zu drum catre Robin si trebuie sa 
			blochez mai multe orase */
			for (i = 0; i < K; i++) {
				int j = lc[i];
				if (d[j] != kInf) {
					break;
				}
			}

			if (i < K) {
				left = mid + 1;
			} else {
				/* rezultatul se afla in primul oras din permutare care blocheaza toate 
				caile lorzilor catre Robin */
				min_cities = mid + 1;
				right = mid - 1;
			}
		}

		return min_cities;
    }

	void print_output(int min_cities) {
		ofstream fout("p1.out");
		fout << min_cities;
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
