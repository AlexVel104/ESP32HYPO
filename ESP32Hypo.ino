// estructuras datos: vector, array, tuple, pair 
// pair<T1,T2> = template class

#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <tuple>
#include <utility> // pair
//#include <math.h> // sqrt
#include <cmath> // hypot

#define INLINE inline __attribute__((always_inline))

using namespace std;

int led = 2; //led integrado ESP32

INLINE float square(float num) { return num * num; }

INLINE float hipo(float n1, float n2) { return sqrt(square(n1) + square(n2)); }

double sumahipo;

int parpadeos;

boolean ledState = false;

using Catetos = pair<float,float>; // sinonimo-tipo array<float,2>; tuple<float, float>; 
//using Catetos = tuple<float,float>; // sinonimo-tipo array<float,2>; tuple<float, float>; 
//using Catetos = array<float,2>; // sinonimo-tipo array<float,2>; tuple<float, float>;   //tie no funciona con arreglos
using  Triang = vector<Catetos>;

Triang cat = { Catetos {2.0F, 2.5F}, Catetos {5.0F, 5.5F}, Catetos {5.0F, 6.0F} }; // vector<pair<float, float>>

void setup() {
    Serial.begin(115200);
    delay(8000);
    //for (auto [c1, c2] : cat) { // type inferencing + structured binding + for-collection
    for (auto par : cat) // structured binding
    {                               
        float c1,c2;
        tie(c1,c2) = par;
        sumahipo += static_cast<double>(hypot(c1, c2));
        cout
            << fixed << setw(5) << setprecision(2)
            << "cateto#1: "   << c1 
            << ", cateto#2: " << c2 << ", hipotenusa: "
            << hypot(c1, c2)<<endl;
    }
    parpadeos = static_cast<int>(sumahipo)*2; 
    
    pinMode(led, OUTPUT);
}

void loop()
{
    if(--parpadeos < 0) return; 
    ledState = !ledState;
    cout<<"Parpadeo # "<<parpadeos<<(ledState? "ON" : "OFF")<<endl; //IF aritmetico
    digitalWrite(led, (ledState? HIGH : LOW));
    delay(1000);
}
