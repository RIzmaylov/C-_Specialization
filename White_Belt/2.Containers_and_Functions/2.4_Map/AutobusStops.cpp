#include <iostream>
#include <map>
#include <vector>

/*
Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

 - NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и 
 stop_countостановками с названиями stop1, stop2, ...

 - BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.

 - STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, 
 на которые можно пересесть на каждой из остановок.

 - ALL_BUSES — вывести список всех маршрутов с остановками.

Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

    Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, 
что маршрут bus отсутствует, количество остановок больше 0, 
а после числа stop_count следует именно такое количество названий остановок, 
причём все названия в каждом списке различны.

Формат вывода
 - Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

 - На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, 
 проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS. 
 Если остановка stop не существует, выведите No stop.

 - На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, 
 в котором они были заданы в соответствующей команде NEW_BUS. 
 Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, 
 проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS, 
 за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, 
 кроме bus, вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.

 - На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. 
 Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., 
 где stop1 stop2 ... — список остановок автобуса bus в порядке, 
 в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.

Предупреждение
Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, 
перечитайте условие ещё раз.

 

Пример 1
Ввод

10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
 

Вывод

No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
*/
void NewBusQuery(std::map<std::string, std::vector<std::string>>& bus_to_stops, 
                std::map<std::string, std::vector<std::string>>& stop_to_buses) {
    std::string bus;
    int stop_count = 0;

    std::cin >> bus >> stop_count;
    
    while (stop_count--) {
        std::string stop;
        std::cin >> stop;
        bus_to_stops[bus].push_back(stop);
        stop_to_buses[stop].push_back(bus);
        
        //----------------------------------------
        // for (auto& [bus, stops] : bus_to_stops) {
        //     std::cout << "Bus " << bus << ":";
        //     for (auto& stop : stops) {
        //         std::cout << ' ' << stop;
        //     }
        //     std::cout << std::endl;
        // }
        // for (auto& [stop, buses] : stop_to_buses) {
        //     std::cout << "Stop " << stop << ":";
        //     for (auto& bus : buses) {
        //         std::cout << ' ' << bus;
        //     }
        //     std::cout << std::endl;
        // }
        //-----------------------------------------
    }
}

void BusesForStopQuery(std::map<std::string, std::vector<std::string>>& stop_to_buses) {
    std::string stop;
    std::cin >> stop;

    if (stop_to_buses.count(stop)) {
        for (auto& bus : stop_to_buses[stop])
        {
            std::cout << bus << ' ';
        }
        std::cout << std::endl;
    } else {
        std::cout << "No stop" << std::endl;
    }
}

void StopsForBus(std::map<std::string, std::vector<std::string>>& bus_to_stops, 
                std::map<std::string, std::vector<std::string>>& stop_to_buses) {
    std::string bus;
    std::cin >> bus;

    if (bus_to_stops.count(bus)) {
        for (auto& stop : bus_to_stops[bus])
        {
            std::cout << "Stop " << stop << ":";
            if (stop_to_buses[stop].size() == 1) {
                std::cout << " no interchange" << std::endl;
            } else {
                for (auto& next_bus : stop_to_buses[stop]) {
                    if (next_bus != bus) {
                        std::cout << ' ' << next_bus;
                    }
                }
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "No bus" << std::endl;
    }
}

void AllBusesQuery(std::map<std::string, std::vector<std::string>>& bus_to_stops) {
    if (bus_to_stops.empty()) {
        std::cout << "No buses" << std::endl;
    } else {
        for (auto& [bus, stops] : bus_to_stops) {
            std::cout << "Bus " << bus << ":";
            for (auto& stop : stops) {
                std::cout << ' ' << stop;
            }
            std::cout << std::endl;
        }
    }
}

void QueryProcessing(std::map<std::string, std::vector<std::string>>& bus_to_stops, 
                std::map<std::string, std::vector<std::string>>& stop_to_buses) {

    std::string req;
    std::cin >> req;
    if (req == "NEW_BUS") {
        NewBusQuery(bus_to_stops, stop_to_buses);
    } else if (req == "BUSES_FOR_STOP") {
        BusesForStopQuery(stop_to_buses);
    } else if (req == "STOPS_FOR_BUS") {
        StopsForBus(bus_to_stops, stop_to_buses);
    } else if (req == "ALL_BUSES") {
        AllBusesQuery(bus_to_stops);
    }
}

int main() {
    std::map<std::string, std::vector<std::string>> bus_to_stops;
    std::map<std::string, std::vector<std::string>> stop_to_buses;

    int Q;
    std::cin >> Q;

    while(Q--) {
        QueryProcessing(bus_to_stops, stop_to_buses);
    }
    return 0;
}