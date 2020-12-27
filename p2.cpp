#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int kNmax = 100005;
const int kInf = 0x3f3f3f3f;

class Task {
 public:
	void solve() {
		read_input();
		print_output(compute_solution());
	}

 private:
	int N, M;
	int source, dest;
	vector<pair<int, int> > adj[kNmax];
	void read_input() {
		ifstream fin("p2.in");
		fin >> N >> M;
		fin >> source >> dest;
		for (int i = 1, x, y, w; i <= M; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
		}
		fin.close();
	}
	// agoritmul de parccurgere in adancime
	void explorare(int i, vector<int> &c, stack<int> &st) {
		c[i] = 1;

		for (pair<int, int> u : adj[i]) {
			if (c[u.first] == 0) {
				explorare(u.first, c, st);
			}
		}
		c[i] = 2;		// nodul a fost finalizat
		st.push(i);		// nodul se adauga in stiva dupa procesare
	}

	int compute_solution() {
		vector<int> cost(N + 1, kInf);		// vector de costuri
		vector<int> c(N + 1, 0);			// vector de culori	0 = alb, 1 = gri, 2 = negru
		stack<int> st;
		vector<int> topsort;		// nodurile sortate in ordine topologica

		for (int i = 1; i <= N; i++) {
			if (c[i] == 0) {
				explorare(i, c, st);
			}
		}

		cost[source] = 0;
		while (!st.empty()) {			// adaug elementele din stiva in vector
			cout << st.top() << " ";
			topsort.push_back(st.top());
			st.pop();
		}
		for (unsigned int i = 0; i < topsort.size(); i++) {
			int v = topsort[i];
			for (pair<int, int> u : adj[v]) {
				// relaxarea muchiilor
				if (cost[v] != kInf && cost[v] + u.second < cost[u.first]) {
			 		cost[u.first] = cost[v] + u.second;		// retine costul minim
				}
		}
	}
		return cost[dest];
}

	void print_output(int cost) {
		ofstream fout("p2.out");
		fout << cost;
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
