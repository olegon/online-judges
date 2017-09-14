/*
Containers
https://www.urionlinejudge.com.br/judge/pt/problems/view/2237

Tempo gasto: 288ms
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue> 
#include <unordered_set> 

using namespace std;

struct container {
    vector<int> disposicao;
    int custo;
};

struct container_less {
    bool operator() (container &a, container &b) {
        return a.custo > b.custo;
    }
};

struct container_hasher {
    size_t operator() (const container &a) const {
        size_t hash = 0;
        size_t t = 1;

        for (int e : a.disposicao) {
            hash += e * t;
            t *= 10;
        }

        return hash;
    }
};

struct container_equal {
    bool operator() (const container &a, const container &b) const {
        for (int i = 0; i < a.disposicao.size(); i++) {
            if (a.disposicao[i] != b.disposicao[i]) return false;
        }

        return true;
    }
};

typedef priority_queue<container, vector<container>, container_less> pq_container;
typedef unordered_set<container, container_hasher, container_equal> set_container;

void tentarTrocar(container &atual, int i, int j, pq_container &paraVisitar, set_container &visitados);

int main(void) {
    ios::sync_with_stdio(false);
    
    container origem, destino;

    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        origem.disposicao.push_back(x);
    }

    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        destino.disposicao.push_back(x);
    }

    origem.custo = 0;

    pq_container paraVisitar;
    set_container visitados;    
    container_equal isMesmoContainer;
    
    paraVisitar.push(origem);
    while (!paraVisitar.empty()) {
        auto atual = paraVisitar.top();
        paraVisitar.pop();        

        if (visitados.find(atual) != visitados.end()) continue;
        visitados.insert(atual);

        if (isMesmoContainer(atual, destino)) {
            cout << atual.custo << endl;
            break;
        }

        tentarTrocar(atual, 0, 1, paraVisitar, visitados);
        tentarTrocar(atual, 1, 2, paraVisitar, visitados);
        tentarTrocar(atual, 2, 3, paraVisitar, visitados);

        tentarTrocar(atual, 4, 5, paraVisitar, visitados);
        tentarTrocar(atual, 5, 6, paraVisitar, visitados);
        tentarTrocar(atual, 6, 7, paraVisitar, visitados);

        tentarTrocar(atual, 0, 4, paraVisitar, visitados);
        tentarTrocar(atual, 1, 5, paraVisitar, visitados);
        tentarTrocar(atual, 2, 6, paraVisitar, visitados);
        tentarTrocar(atual, 3, 7, paraVisitar, visitados);
    }

    return EXIT_SUCCESS;
}

void tentarTrocar(container &atual, int i, int j, pq_container &paraVisitar, set_container &visitados) {
    container clone(atual);

    int aux = clone.disposicao[i];
    clone.disposicao[i] = clone.disposicao[j];
    clone.disposicao[j] = aux;

    if (visitados.find(clone) == visitados.end()) {
        clone.custo = atual.custo + clone.disposicao[i] + clone.disposicao[j];
        paraVisitar.push(clone);
    }
}