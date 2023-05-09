// (1) Desarrollar un programa para la simulación de un cajero automático.
// Se cuenta con la siguiente información:
// - Llegan clientes a la puerta del cajero cada 2 ó 3 minutos.
// - Cada cliente tarda entre 2 y 4 minutos para ser atendido.

// Obtener la siguiente información:
// 1 - Cantidad de clientes que se atienden en 10 horas.
// 2 - Cantidad de clientes que hay en cola después de 10 horas.
// 3 - Hora de llegada del primer cliente que no es atendido luego de 10 horas (es decir la persona que está primera en la cola cuando se cumplen 10 horas)

#include <iostream>
#include <queue>
#include <random>
#include <cstdlib>

using namespace std;

int main()
{
    queue<int> clientsQueue;
    float clientsAttended = 0.0;
    float clientsNotAttended = 0.0;
    float clientsNotAttendedAfter10Hours = 0.0;
    float clientsArrived = 0.0;
    float clientsArrivedAfter10Hours = 0;
    float clientsArrivedAfter10HoursNotAttended = 0;
    float clientsArrivedAfter10HoursAttended = 0;

    //data
    float checkoutTime = rand() % 3 + 2;
    float checkoutTimeMax = rand() % 4 + 2;
    
    float clientsPerHour = 60 / (checkoutTime + checkoutTimeMax);
    float clientsInQueueAfter10Hours = 0;

    //simulation
    for (int i = 0; i < 600; i++)
    {
        //clients arrive
        if (rand() + 1 % 2 == 0)
        {
            clientsQueue.push(i);
            clientsArrived++;
            clientsArrivedAfter10Hours++;
        }

        //clients leave
        if (clientsQueue.size() > 0 && i - clientsQueue.front() >= checkoutTime)
        {
            clientsQueue.pop();
            clientsAttended++;
            clientsInQueueAfter10Hours--;
            clientsArrivedAfter10HoursAttended++;
        }

        //clients not attended
        if (clientsQueue.size() > 0 && i - clientsQueue.front() >= checkoutTimeMax)
        {
            clientsQueue.pop();
            clientsNotAttended++;
            clientsInQueueAfter10Hours--;
            clientsArrivedAfter10HoursNotAttended++;
        }

        //clients in queue
        clientsInQueueAfter10Hours += clientsQueue.size();
    }

    //results
    cout << "clients llegados: " << endl;
    cout << "clients atendidos: " << clientsAttended << endl;
    cout << "clientes no atendidos: " << clientsNotAttended << endl;
    cout << "clientes en la cola despues de 10 horas: " << clientsInQueueAfter10Hours << endl;
    cout << "clients llegados despues de 10 horas: " << clientsArrivedAfter10Hours << endl;
    cout << "clients llegados despues de 10 horas atendidos: " << clientsArrivedAfter10HoursAttended << endl;
    cout << "clients llegados despues de 10 horas no atendidos: " << clientsArrivedAfter10HoursNotAttended << endl;


    return 0;
}