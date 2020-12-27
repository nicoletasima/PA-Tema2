#include <bits/stdc++.h>
using namespace std;

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(compute_solution());
	}

 private:
	int N, M;
	double E;
	double effort = 0;
	vector<pair<int, double> > adj[kNmax];
	void read_input() {
		ifstream fin("p3.in");
		fin >> N >> M >> E;
		for (int i = 1; i <= M; i++) {
			int x, y;
			double w;
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
		}
		fin.close();
	}

	void findPath(vector<int> &parents, vector<int> &path, int i) {
		if (parents[i] == 0) {
			return;
		}
		path.push_back(parents[i]);
		findPath(parents, path, parents[i]);
	}

    vector<int> compute_solution() {
    	vector<double> d(N + 1, 0.0);
    	vector<bool> s(N + 1, false);
    	vector<int> parents(N + 1, 0);
    	vector<int> path;		// vector care contine drumul

    	// coada de prioritati in care se retine efortul maxim calculat
    	//  pentru a ajunge la fiecare nod si nodul respectiv
    	priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
    	// Dijkstra modificat-> retine efortul in loc de cost si se calculeaza
    	// efortul depus pentru a ajunge la fiecare nod
		pq.push(make_pair(E, 1));
		d[1] = E;
        while (!pq.empty()) {
            pair<double, int> u = pq.top();
            pq.pop();
            s[u.second] = true;

            for (pair<int, double> v : adj[u.second]) {
                if (s[v.first] == false && d[v.first] < d[u.second] *
                						(1 - (v.second/100.0))) {
                    d[v.first] = d[u.second] * (1 - (v.second/100.0));
                    parents[v.first] = u.second;
                    pq.push(make_pair(d[v.first], v.first));
                }
            }
        }
        // adaug nodul N in cale
        int i = N;
        path.push_back(N);
        // parcurg recursiv parintii pana la nodul sursa
        findPath(parents, path, N);
        // inversez ordinea nodurilor din cale pentru a fi in
        // ordine de la sursa la destinatie
        reverse(path.begin(), path.end());
      	effort = d[N];
      	return path;
    }

	void print_output(vector<int> result) {
		ofstream fout("p3.out");
		fout << fixed;
		fout << setprecision(3) << effort << '\n';
		for (unsigned int i = 0; i < result.size(); i++) {
			fout << result[i] << " ";
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
