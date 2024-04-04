#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void imprimirLista(vector<int> &v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout<<v[i]<<" ";
    }
}

vector<int> criarVetorAleatorio() {
    int tamanho = 50000;
    
    vector<int> vetor;
    
    random_device aleatorio;
    mt19937 gerador(aleatorio());
    uniform_int_distribution<int> distribuicao(0, 100);
    
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(distribuicao(gerador));
    }
    return vetor;
}

vector<int> passarVetorOriginal(vector<int> &vetor,int tamanho) {
    vector<int> vetorCopia;
    
    for (int i = 0; i < tamanho; i++) {
        vetorCopia.push_back(vetor[i]);
    }
    
    return vetorCopia;
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

void insertionSort(vector<int> &v){
	int n=v.size();
	int i,key,j;
	for(i=1;i<n;i++){
		key=v[i];
		j=i-1;
		while(j>=0&&v[j]>key){
			v[j+1]=v[j];
			j=j-1;
		}
		v[j+1]=key;
	}
}

void selectionSort(vector<int> &v){
	int min_idx;
	int n=v.size();
	for(int i=0;i<n-1;i++){
		min_idx=i;
		for(int j=i+1;j<n;j++){
			if(v[j]<v[min_idx])
				min_idx=j;
		}
		if(min_idx!=i){
			int temp=v[min_idx];
			v[min_idx]=v[i];
			v[i]=temp;
		}
	}
}

int main()
{
    vector<int> vetor = criarVetorAleatorio();
    int tamanho = vetor.size();
    
    // imprimirLista(vetor, tamanho);
    
    vector<int> vetorCopia = passarVetorOriginal(vetor, tamanho);
    
    double soma = 0;
    
    for (int i = 0; i < 3; i++) {
        auto inicio = steady_clock::now();
        bubleSort(vetorCopia, tamanho);
        auto fim = steady_clock::now();
        
        auto duracao = fim - inicio;
        auto duracao_convertida = duration_cast<seconds>(duracao).count();
    
        // cout <<"tempo de execução:"<<endl;
        // cout << duration<double>{duracao_convertida}.count();
        soma += duration<double>{duracao_convertida}.count();
    }
    
    double media = soma / 3;
    
    std::cout << "BubleSort media: " << std::endl;
    cout << media<<endl;
    std::cout << "" << std::endl;
    
    // insertion Sort
    
    vetorCopia = passarVetorOriginal(vetor, tamanho);
    
    soma = 0;
    
    for (int i = 0; i < 3; i++) {
        auto inicio = steady_clock::now();
        insertionSort(vetorCopia);
        auto fim = steady_clock::now();
        
        auto duracao = fim - inicio;
        auto duracao_convertida = duration_cast<seconds>(duracao).count();
    
        // cout <<"tempo de execução:"<<endl;
        // cout << duration<double>{duracao_convertida}.count();
        soma += duration<double>{duracao_convertida}.count();
    }
    
    media = soma / 3;
    
    std::cout << "InsertionSort media: " << std::endl;
    cout << media<<endl;
    std::cout << "" << std::endl;
    
    // Selection Sort
    
    vetorCopia = passarVetorOriginal(vetor, tamanho);
    
    soma = 0;
    
    for (int i = 0; i < 3; i++) {
        auto inicio = steady_clock::now();
        selectionSort(vetorCopia);
        auto fim = steady_clock::now();
        
        auto duracao = fim - inicio;
        auto duracao_convertida = duration_cast<seconds>(duracao).count();
    
        // cout <<"tempo de execução:"<<endl;
        // cout << duration<double>{duracao_convertida}.count();
        soma += duration<double>{duracao_convertida}.count();
    }
    
    media = soma / 3;
    
    std::cout << "SelectionSort media: " << std::endl;
    cout << media<<endl;
    std::cout << "" << std::endl;
    
    // cout<<" "<<endl;
    // cout<<" "<<endl;

    // imprimirLista(vetorBuble, tamanho);
    
    // cout<<" "<<endl;
    // cout<<" "<<endl;
    
    return 0;
}
