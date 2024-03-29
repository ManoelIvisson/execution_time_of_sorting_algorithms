#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

vector<int> criarVetorAleatorio() {
    int tamanho = 10000;
    
    vector<int> vetor;
    
    random_device aleatorio;
    mt19937 gerador(aleatorio());
    uniform_int_distribution<int> distribuicao(0, 1000);
    
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(distribuicao(gerador));
    }
    return vetor;
}

void imprimirLista(vector<int> &v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout<<v[i]<<" ";
    }
}

void bubleSort(vector<int> &v, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int x = 0; x < tamanho - i - 1; x++) {
            if (v[x] > v[x + 1]) {
                int intermedio = v[x];
                v[x] = v[x + 1];
                v[x + 1] = intermedio;
            }
        }
    }
}

int main()
{
    vector<int> vetor = criarVetorAleatorio();
    int tamanho = vetor.size();
    
    imprimirLista(vetor, tamanho);
    
    auto inicio = steady_clock::now();
    bubleSort(vetor, tamanho);
    auto fim = steady_clock::now();

    auto duracao = fim - inicio;
    auto duracao_convertida = duration_cast<seconds>(duracao).count();

    cout<<" "<<endl;
    cout<<" "<<endl;

    imprimirLista(vetor, tamanho);
    
    cout<<" "<<endl;
    cout<<" "<<endl;
    
    cout <<"tempo de execução:"<<endl;
    cout << duration<double>{duracao_convertida}.count();

    return 0;
}



