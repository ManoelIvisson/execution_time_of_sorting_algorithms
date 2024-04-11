#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Função para imprimir o vetor
template<typename Tipo>
void imprimirVetor(const vector<Tipo> &vetor, const string& nomeOrdenacao, bool aposOrdenacao = false) {
    // Verifica se o vetor está sendo impresso antes ou depois da ordenação
    if (aposOrdenacao) {
        cout << "Array após o " << nomeOrdenacao << ": ";
    } else {
        cout << "Array antes do " << nomeOrdenacao << ": ";
    }
    // Imprime os elementos do vetor separados por espaço
    for (const auto &elemento : vetor) {
        cout << elemento << " ";
    }
    cout << endl;
}

// Função para criar um vetor com números aleatórios
vector<int> criarVetorAleatorio(int tamanho) {
    // Configuração do gerador de números aleatórios
    random_device dispositivo;
    mt19937 gerador(dispositivo());
    uniform_int_distribution<int> distribuicao(0, 100);

    // Preenche o vetor com números aleatórios entre 0 e 100
    vector<int> vetor(tamanho);
    generate(vetor.begin(), vetor.end(), [&]() { return distribuicao(gerador); });
    return vetor;
}

// Função para medir o tempo de execução de uma função de ordenação
template<typename Tipo>
double medirTempo(void (*funcaoOrdenacao)(vector<Tipo> &), vector<Tipo> &vetor) {
    // Marca o tempo inicial
    auto inicio = steady_clock::now();
    // Chama a função de ordenação
    funcaoOrdenacao(vetor);
    // Marca o tempo final
    auto fim = steady_clock::now();
    // Calcula o tempo de execução em milissegundos e retorna
    return duration<double, milli>(fim - inicio).count();
}

// Algoritmo de ordenação: Bubble Sort
void ordenacaoBubble(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Itera sobre o vetor
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = 0; j < tamanho - i - 1; ++j) {
            // Compara elementos adjacentes e os troca se estiverem fora de ordem
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}

// Algoritmo de ordenação: Insertion Sort
void ordenacaoInsertion(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Itera sobre o vetor a partir do segundo elemento
    for (int i = 1; i < tamanho; ++i) {
        int chave = vetor[i];
        int j = i - 1;
        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            --j;
        }
        vetor[j + 1] = chave;
    }
}

// Algoritmo de ordenação: Selection Sort
void ordenacaoSelection(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Itera sobre o vetor
    for (int i = 0; i < tamanho - 1; ++i) {
        int indiceMinimo = i;
        // Encontra o índice do menor elemento restante
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[j] < vetor[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (indiceMinimo != i) {
            swap(vetor[indiceMinimo], vetor[i]);
        }
    }
}

// Algoritmo de ordenação: Shell Sort
void ordenacaoShell(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Define o tamanho do intervalo de comparação
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        // Itera sobre o vetor com o intervalo atual
        for (int i = intervalo; i < tamanho; ++i) {
            int temporario = vetor[i];
            int j;
            // Move os elementos que são maiores que o elemento temporário
            // uma posição à frente do local de inserção
            for (j = i; j >= intervalo && vetor[j - intervalo] > temporario; j -= intervalo)
                vetor[j] = vetor[j - intervalo];
            vetor[j] = temporario;
        }
    }
}

// Algoritmo de ordenação: Merge Sort
void merge(vector<int> &vetor, int inicio, int meio, int fim) {
    int tamanhoEsquerdo = meio - inicio + 1;
    int tamanhoDireito = fim - meio;

    vector<int> vetorEsquerdo(tamanhoEsquerdo), vetorDireito(tamanhoDireito);

    // Copia os elementos para os subvetores esquerdo e direito
    for (int i = 0; i < tamanhoEsquerdo; ++i)
        vetorEsquerdo[i] = vetor[inicio + i];
    for (int j = 0; j < tamanhoDireito; ++j)
        vetorDireito[j] = vetor[meio + 1 + j];

    int indiceEsquerdo = 0, indiceDireito = 0, indiceResultado = inicio;
    // Mescla os subvetores de volta ao vetor original
    while (indiceEsquerdo < tamanhoEsquerdo && indiceDireito < tamanhoDireito) {
        if (vetorEsquerdo[indiceEsquerdo] <= vetorDireito[indiceDireito])
            vetor[indiceResultado++] = vetorEsquerdo[indiceEsquerdo++];
        else
            vetor[indiceResultado++] = vetorDireito[indiceDireito++];
    }

    // Copia os elementos restantes do subvetor esquerdo, se houver
    while (indiceEsquerdo < tamanhoEsquerdo)
        vetor[indiceResultado++] = vetorEsquerdo[indiceEsquerdo++];
    // Copia os elementos restantes do subvetor direito, se houver
    while (indiceDireito < tamanhoDireito)
        vetor[indiceResultado++] = vetorDireito[indiceDireito++];
}

// Função recursiva para realizar a ordenação Merge Sort
void ordenacaoMerge(vector<int> &vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        // Chama a função recursivamente para os subvetores esquerdo e direito
        ordenacaoMerge(vetor, inicio, meio);
        ordenacaoMerge(vetor, meio + 1, fim);
        // Combina os subvetores ordenados
        merge(vetor, inicio, meio, fim);
    }
}

// Função wrapper para chamar a ordenação Merge Sort com os parâmetros corretos
void wrapperOrdenacaoMerge(vector<int> &vetor) {
    ordenacaoMerge(vetor, 0, vetor.size() - 1);
}

// Função auxiliar para realizar a partição no Quick Sort
int particao(vector<int> &vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int indiceMenor = inicio - 1;
    for (int indiceAtual = inicio; indiceAtual <= fim - 1; ++indiceAtual) {
        if (vetor[indiceAtual] < pivo) {
            ++indiceMenor;
            swap(vetor[indiceMenor], vetor[indiceAtual]);
        }
    }
    swap(vetor[indiceMenor + 1], vetor[fim]);
    return indiceMenor + 1;
}

// Função recursiva para realizar a ordenação Quick Sort
void ordenacaoQuick(vector<int> &vetor, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particao(vetor, inicio, fim);
        // Chama a função recursivamente para os subvetores antes e depois do pivo
        ordenacaoQuick(vetor, inicio, indicePivo - 1);
        ordenacaoQuick(vetor, indicePivo + 1, fim);
    }
}

// Função wrapper para chamar a ordenação Quick Sort com os parâmetros corretos
void wrapperOrdenacaoQuick(vector<int> &vetor) {
    ordenacaoQuick(vetor, 0, vetor.size() - 1);
}

// Função principal
int main() {
    const int tamanhoVetor = 100000; // Tamanho do vetor
    vector<int> vetor = criarVetorAleatorio(tamanhoVetor); // Cria um vetor com números aleatórios
    vector<int> vetorCopia(vetor); // Cria uma cópia do vetor para cada algoritmo de ordenação

    // Mede o tempo de execução de cada algoritmo de ordenação
    double tempoTotalBubble = medirTempo(ordenacaoBubble, vetorCopia);
    vetorCopia = vetor; // Restaura o vetor original
    double tempoTotalInsertion = medirTempo(ordenacaoInsertion, vetorCopia);
    vetorCopia = vetor;
    double tempoTotalSelection = medirTempo(ordenacaoSelection, vetorCopia);
    vetorCopia = vetor;
    double tempoTotalQuick = medirTempo(wrapperOrdenacaoQuick, vetorCopia);
    vetorCopia = vetor;
    double tempoTotalMerge = medirTempo(wrapperOrdenacaoMerge, vetorCopia);
    vetorCopia = vetor;
    double tempoTotalShell = medirTempo(ordenacaoShell, vetorCopia);

    // Exibe os tempos médios de execução de cada algoritmo
    cout << "\nTempo Médio (Bubble Sort): " << tempoTotalBubble << " milissegundos" << endl;
    cout << "Tempo Médio (Insertion Sort): " << tempoTotalInsertion << " milissegundos" << endl;
    cout << "Tempo Médio (Selection Sort): " << tempoTotalSelection << " milissegundos" << endl;
    cout << "Tempo Médio (Quick Sort): " << tempoTotalQuick << " milissegundos" << endl;
    cout << "Tempo Médio (Merge Sort): " << tempoTotalMerge << " milissegundos" << endl;
    cout << "Tempo Médio (Shell Sort): " << tempoTotalShell << " milissegundos" << endl;

    return 0;
}