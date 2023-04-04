#include <iostream>

using namespace std;

class Película {
    private:
        string titulo;
        string director;
        string genero;
        int año;
        int duracion;
    public:
    int getDuracion() {
        return duracion;
    }
    int getAño() {
        return año;
    }
};

class Alquiler : public Película {
    private:
        float total;
        int año;
        int duracion;
    public:
        Película pelicula;
        float calcularTotal() {
            duracion = getDuracion();
            año = getAño();
            return total = duracion * año;
        }
};

int main() {
    Alquiler alquiler;
    alquiler.calcularTotal();
    return 0;
}