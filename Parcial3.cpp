#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
};

// Función para insertar un nuevo nodo en el árbol binario
void insertarNodoBinario(Nodo** raiz, int valor) {
    // Se crea un nuevo nodo y se asigna el valor proporcionado
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->valor = valor;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;

    // Si la raíz del árbol es nula, el nuevo nodo se convierte en la raíz
    if (*raiz == nullptr) {
        *raiz = nuevoNodo;
    }
    else {
        // Si la raíz no es nula, se inicia la búsqueda del lugar adecuado para el nuevo nodo
        Nodo* nodoActual = *raiz;
        while (true) {
            // Si el valor es menor que el valor del nodo actual, se mueve al nodo izquierdo
            if (valor < nodoActual->valor) {
                // Si el nodo izquierdo es nulo, se inserta el nuevo nodo aquí y se sale del bucle
                if (nodoActual->izquierdo == nullptr) {
                    nodoActual->izquierdo = nuevoNodo;
                    break;
                }
                // Si el nodo izquierdo no es nulo, se avanza al nodo izquierdo y se continúa la búsqueda
                else {
                    nodoActual = nodoActual->izquierdo;
                }
            }
            // Si el valor es mayor o igual que el valor del nodo actual, se mueve al nodo derecho
            else {
                // Si el nodo derecho es nulo, se inserta el nuevo nodo aquí y se sale del bucle
                if (nodoActual->derecho == nullptr) {
                    nodoActual->derecho = nuevoNodo;
                    break;
                }
                // Si el nodo derecho no es nulo, se avanza al nodo derecho y se continúa la búsqueda
                else {
                    nodoActual = nodoActual->derecho;
                }
            }
        }
    }
}


// Función para calcular la altura de un árbol
int calcularAltura(Nodo* nodo) {
    // Comprueba si el nodo actual es nulo (subárbol vacío)
    if (nodo == nullptr) {
        // Si es nulo, el árbol tiene una altura de 0
        return 0;
    }
    else {
        // Calcula recursivamente la altura del subárbol izquierdo
        int alturaIzquierdo = calcularAltura(nodo->izquierdo);
        // Calcula recursivamente la altura del subárbol derecho
        int alturaDerecho = calcularAltura(nodo->derecho);
        // La altura del árbol es la máxima altura entre el subárbol izquierdo y derecho, más 1 por el nodo actual
        return 1 + max(alturaIzquierdo, alturaDerecho);
    }
}

// Función para imprimir el recorrido Inorder
void imprimirInorder(Nodo* nodo) {
    if (nodo != nullptr) {
        imprimirInorder(nodo->izquierdo);
        cout << nodo->valor << " ";
        imprimirInorder(nodo->derecho);
    }
}

// Función para imprimir el recorrido Postorder
void imprimirPostorder(Nodo* nodo) {
    if (nodo != nullptr) {
        imprimirPostorder(nodo->izquierdo);
        imprimirPostorder(nodo->derecho);
        cout << nodo->valor << " ";
    }
}

// Función para imprimir el recorrido Preorder
void imprimirPreorder(Nodo* nodo) {
    if (nodo != nullptr) {
        cout << nodo->valor << " ";
        imprimirPreorder(nodo->izquierdo);
        imprimirPreorder(nodo->derecho);
    }
}


// Función para calcular la cantidad de nodos en un árbol
int calcularCantidadNodos(Nodo* nodo) {
    // Comprueba si el nodo actual es nulo (subárbol vacío)
    if (nodo == nullptr) {
        // Si es nulo, el número de nodos es 0
        return 0;
    }
    else {
        // Calcula recursivamente la cantidad de nodos en el subárbol izquierdo
        int cantidadIzquierdo = calcularCantidadNodos(nodo->izquierdo);
        // Calcula recursivamente la cantidad de nodos en el subárbol derecho
        int cantidadDerecho = calcularCantidadNodos(nodo->derecho);
        // La cantidad de nodos en el árbol es la suma de los nodos en el subárbol izquierdo, derecho y el nodo actual
        return 1 + cantidadIzquierdo + cantidadDerecho;
    }
}


// Función para buscar el camino desde la raíz hasta un nodo dado en un árbol binario
bool buscarCamino(Nodo* nodo, int valor, string& camino) {
    // Comprueba si el nodo actual es nulo (subárbol vacío)
    if (nodo == nullptr) {
        // Si es nulo, el valor no se encontró en el árbol
        return false;
    }
    // Comprueba si el valor del nodo actual coincide con el valor buscado
    if (nodo->valor == valor) {
        // Si coincide, se agrega el valor al camino y se retorna true
        camino += to_string(nodo->valor);
        return true;
    }
    // Busca recursivamente el valor en el subárbol izquierdo y derecho
    bool encontrado = buscarCamino(nodo->izquierdo, valor, camino) || buscarCamino(nodo->derecho, valor, camino);
    // Si el valor se encontró en alguno de los subárboles, se agrega el valor del nodo actual al camino
    if (encontrado) {
        camino += " -> " + to_string(nodo->valor);
    }
    // Retorna el resultado de la búsqueda (true si se encontró el valor, false en caso contrario)
    return encontrado;
}


// Función para mostrar los nodos del árbol en orden ascendente
void mostrarEnOrden(Nodo* nodo) {
    // Comprueba si el nodo actual no es nulo
    if (nodo != nullptr) {
        // Muestra en orden los nodos del subárbol izquierdo
        mostrarEnOrden(nodo->izquierdo);
        // Muestra el valor del nodo actual
        cout << nodo->valor << " ";
        // Muestra en orden los nodos del subárbol derecho
        mostrarEnOrden(nodo->derecho);
    }
}


// Función para insertar un nuevo nodo en un árbol AVL
Nodo* insertarNodoAVL(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = valor;
        nuevoNodo->izquierdo = nullptr;
        nuevoNodo->derecho = nullptr;
        return nuevoNodo;
    }

    if (valor < raiz->valor) {
        raiz->izquierdo = insertarNodoAVL(raiz->izquierdo, valor);
    }
    else if (valor > raiz->valor) {
        raiz->derecho = insertarNodoAVL(raiz->derecho, valor);
    }

    int alturaIzquierdo = calcularAltura(raiz->izquierdo);
    int alturaDerecho = calcularAltura(raiz->derecho);
    int nuevaAltura = 1 + max(alturaIzquierdo, alturaDerecho);

    int factorEquilibrio = alturaIzquierdo - alturaDerecho;
    if (factorEquilibrio > 1) {
        if (valor < raiz->izquierdo->valor) {
            Nodo* nuevaRaiz = raiz->izquierdo;
            raiz->izquierdo = nuevaRaiz->derecho;
            nuevaRaiz->derecho = raiz;
            return nuevaRaiz;
        }
        else {
            Nodo* nuevaRaiz = raiz->izquierdo;
            raiz->izquierdo = nuevaRaiz->derecho;
            nuevaRaiz->derecho = raiz;
            raiz->izquierdo = nuevaRaiz->derecho;
            nuevaRaiz->derecho = raiz;
            return nuevaRaiz;
        }
    }
    else if (factorEquilibrio < -1) {
        if (valor > raiz->derecho->valor) {
            Nodo* nuevaRaiz = raiz->derecho;
            raiz->derecho = nuevaRaiz->izquierdo;
            nuevaRaiz->izquierdo = raiz;
            return nuevaRaiz;
        }
        else {
            Nodo* nuevaRaiz = raiz->derecho;
            raiz->derecho = nuevaRaiz->izquierdo;
            nuevaRaiz->izquierdo = raiz;
            raiz->derecho = nuevaRaiz->izquierdo;
            nuevaRaiz->izquierdo = raiz;
            return nuevaRaiz;
        }
    }

    return raiz;
}


// Función para borrar un nodo de un árbol AVL
Nodo* borrarNodoAVL(Nodo* raiz, int valor) {
    // Verificar si la raíz es nula, en ese caso no hay nada que borrar
    if (raiz == nullptr) {
        return raiz;
    }

    // Verificar si el valor es menor que la raíz, buscar en el subárbol izquierdo
    if (valor < raiz->valor) {
        raiz->izquierdo = borrarNodoAVL(raiz->izquierdo, valor);
    }
    // Verificar si el valor es mayor que la raíz, buscar en el subárbol derecho
    else if (valor > raiz->valor) {
        raiz->derecho = borrarNodoAVL(raiz->derecho, valor);
    }
    else {
        // El nodo actual contiene el valor a borrar
        if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
            // Nodo sin hijos, se elimina y se retorna nullptr
            delete raiz;
            return nullptr;
        }
        else if (raiz->izquierdo == nullptr) {
            // Nodo con un hijo derecho, se guarda el hijo derecho en un nodo temporal, se elimina el nodo actual y se retorna el hijo derecho
            Nodo* nodoTemp = raiz->derecho;
            delete raiz;
            return nodoTemp;
        }
        else if (raiz->derecho == nullptr) {
            // Nodo con un hijo izquierdo, se guarda el hijo izquierdo en un nodo temporal, se elimina el nodo actual y se retorna el hijo izquierdo
            Nodo* nodoTemp = raiz->izquierdo;
            delete raiz;
            return nodoTemp;
        }
        else {
            // Nodo con dos hijos
            // Se encuentra el nodo con el valor mínimo en el subárbol derecho
            Nodo* nodoMinimo = raiz->derecho;
            while (nodoMinimo->izquierdo != nullptr) {
                nodoMinimo = nodoMinimo->izquierdo;
            }
            // Se reemplaza el valor del nodo actual con el valor mínimo encontrado
            raiz->valor = nodoMinimo->valor;
            // Se elimina el nodo mínimo del subárbol derecho recursivamente
            raiz->derecho = borrarNodoAVL(raiz->derecho, nodoMinimo->valor);
        }
    }

    // Actualizar la altura del nodo actual
    int alturaIzquierdo = calcularAltura(raiz->izquierdo);
    int alturaDerecho = calcularAltura(raiz->derecho);
    int nuevaAltura = 1 + max(alturaIzquierdo, alturaDerecho);

    // Verificar el equilibrio del árbol
    int factorEquilibrio = alturaIzquierdo - alturaDerecho;
    if (factorEquilibrio > 1) {
        // Desbalanceado a la izquierda
        if (calcularAltura(raiz->izquierdo->izquierdo) >= calcularAltura(raiz->izquierdo->derecho)) {
            // Rotación simple a la derecha
            Nodo* nuevaRaiz = raiz->izquierdo;
            raiz->izquierdo = nuevaRaiz->derecho;
            nuevaRaiz->derecho = raiz;
            return nuevaRaiz;
        }
        else {
            // Rotación doble a la izquierda-derecha
            Nodo* nuevaRaiz = raiz->izquierdo;
            raiz->izquierdo = nuevaRaiz->derecho;
            nuevaRaiz->derecho = raiz;
            raiz->izquierdo = nuevaRaiz->derecho;
            nuevaRaiz->derecho = raiz;
            return nuevaRaiz;
        }
    }
    else if (factorEquilibrio < -1) {
        // Desbalanceado a la derecha
        if (calcularAltura(raiz->derecho->derecho) >= calcularAltura(raiz->derecho->izquierdo)) {
            // Rotación simple a la izquierda
            Nodo* nuevaRaiz = raiz->derecho;
            raiz->derecho = nuevaRaiz->izquierdo;
            nuevaRaiz->izquierdo = raiz;
            return nuevaRaiz;
        }
        else {
            // Rotación doble a la derecha-izquierda
            Nodo* nuevaRaiz = raiz->derecho;
            raiz->derecho = nuevaRaiz->izquierdo;
            nuevaRaiz->izquierdo = raiz;
            raiz->derecho = nuevaRaiz->izquierdo;
            nuevaRaiz->izquierdo = raiz;
            return nuevaRaiz;
        }
    }

    // Si el árbol está equilibrado, simplemente retornar la raíz sin cambios
    return raiz;
}


int main() {
    Nodo* raizBinario = nullptr;
    Nodo* raizAVL = nullptr;
    // Se declaran dos punteros a Nodo: raizBinario y raizAVL.
    // raizBinario es un puntero que apunta a la raíz de un árbol binario. En este caso, es inicializado como nullptr, lo que indica que el árbol está vacío.
    // raizAVL es un puntero que apunta a la raíz de un árbol AVL. Al igual que raizBinario, es inicializado como nullptr, lo que indica que el árbol está vacío.
    // Estos punteros son utilizados para mantener el seguimiento de las raíces de los árboles binario y AVL respectivamente. Dependiendo del contexto y del flujo de tu programa, estas variables serán modificadas y utilizadas para realizar operaciones de inserción, eliminación, búsqueda u otras operaciones en los árboles.
    
    int opcion;
    do {
        cout << "Menú de opciones:" << endl;
        cout << "1) Cargar un árbol binario" << endl;
        cout << "2) Cargar un árbol AVL" << endl;
        cout << "3) Calcular altura, cantidad de nodos y camino de nodo" << endl;
        cout << "4) Insertar nodo al AVL y al binario" << endl;
        cout << "5) Borrar nodo del AVL y del binario" << endl;
        cout << "6) Mostrar recorridos" << endl;
        cout << "7) Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                cout << "Ingrese el valor del nodo para el árbol binario (0 para terminar): ";
                cin >> valor;
                while (valor != 0) {
                    insertarNodoBinario(&raizBinario, valor);
                    cout << "Ingrese el valor del nodo para el árbol binario (0 para terminar): ";
                    cin >> valor;
                }
                break;
            }
            case 2: {
                int valor;
                cout << "Ingrese el valor del nodo para el árbol AVL (0 para terminar): ";
                cin >> valor;
                while (valor != 0) {
                    raizAVL = insertarNodoAVL(raizAVL, valor);
                    cout << "Ingrese el valor del nodo para el árbol AVL (0 para terminar): ";
                    cin >> valor;
                }
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor del nodo para calcular altura, cantidad de nodos y camino: ";
                cin >> valor;

                // Calcular altura
                int alturaBinario = calcularAltura(raizBinario);
                int alturaAVL = calcularAltura(raizAVL);
                cout << "Altura del árbol binario: " << alturaBinario << endl;
                cout << "Altura del árbol AVL: " << alturaAVL << endl;

                // Calcular cantidad de nodos
                int cantidadNodosBinario = calcularCantidadNodos(raizBinario);
                int cantidadNodosAVL = calcularCantidadNodos(raizAVL);
                cout << "Cantidad de nodos del árbol binario: " << cantidadNodosBinario << endl;
                cout << "Cantidad de nodos del árbol AVL: " << cantidadNodosAVL << endl;

                // Calcular camino de nodo
                string caminoBinario;
                bool encontradoBinario = buscarCamino(raizBinario, valor, caminoBinario);
                string caminoAVL;
                bool encontradoAVL = buscarCamino(raizAVL, valor, caminoAVL);

                if (encontradoBinario) {
                    cout << "Camino del nodo " << valor << " en el árbol binario: " << caminoBinario << endl;
                }
                else {
                    cout << "El nodo " << valor << " no se encontró en el árbol binario." << endl;
                }

                if (encontradoAVL) {
                    cout << "Camino del nodo " << valor << " en el árbol AVL: " << caminoAVL << endl;
                }
                else {
                    cout << "El nodo " << valor << " no se encontró en el árbol AVL." << endl;
                }

                break;
            }
            case 4: {
                int valor;
                cout << "Ingrese el valor del nodo a insertar en el AVL y en el binario: ";
                cin >> valor;

                insertarNodoBinario(&raizBinario, valor);
                raizAVL = insertarNodoAVL(raizAVL, valor);

                cout << "Nodo insertado correctamente en el AVL y en el binario." << endl;

                break;
            }
            case 5: {
                int valor;
                cout << "Ingrese el valor del nodo a borrar del AVL y del binario: ";
                cin >> valor;

                raizBinario = borrarNodoAVL(raizBinario, valor);
                raizAVL = borrarNodoAVL(raizAVL, valor);

                cout << "Nodo borrado correctamente del AVL y del binario." << endl;

                break;
            }
            case 6: {
                int op;
                cout << "1) Recorrido avl" <<endl;
                cout << "2) Recorrido binario" <<endl;
                cout << "Ingrese una opción: ";
                cin >> op;
                switch (op) {
                    case 1: {
                        cout << "Recorrido AVL: " << endl;
                        cout << "Inorder: ";
                        imprimirInorder(raizAVL);
                        cout << "\n";
                        cout << "Postorder: ";
                        imprimirPostorder(raizAVL);
                        cout << "\n";
                        cout << "Preorder: ";
                        imprimirPreorder(raizAVL);
                        cout << "\n";
                        break;
                    }
                    case 2: {
                        cout << "Recorrido binario: " << endl;
                        cout << "Inorder: ";
                        imprimirInorder(raizBinario);
                        cout << "\n";
                        cout << "Postorder: ";
                        imprimirPostorder(raizBinario);
                        cout << "\n";
                        cout << "Preorder: ";
                        imprimirPreorder(raizBinario);
                        cout << "\n";
                        break;
                    }
                    default: {
                        cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                        break;
                    }
                }
            }
            case 7: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                break;
            }
        }

        cout << endl;
    } while (opcion != 7);

    return 0;
}
