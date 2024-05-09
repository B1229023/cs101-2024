#include <iostream>
using namespace std;

class FuelTank{
    private:
        int m_FuelTankCapacity;
        int m_gas_grade;
    public:
        FuelTank(int FuelTankCapacity=3000, int Gas=98){
            m_FuelTankCapacity = FuelTankCapacity;
            m_gas_grade = Gas;
        }
        int fuel_up(int v, int gas){
            if (v > m_FuelTankCapacity&&gas != m_gas_grade){
               cout << "Error: Fueltank capacity: " << m_FuelTankCapacity << " but fuel up: " << v << endl;
               cout << "Error: Gas grade: " << gas << " Correct Gas grade: " << m_gas_grade << endl;
            }
            else if (v > m_FuelTankCapacity){
                cout << "Error: Fueltank capacity: " << m_FuelTankCapacity << " but fuel up: " << v << endl;
            } else if (gas != m_gas_grade){
                cout << "Error: Gas grade: " << gas << " Correct Gas grade: " << m_gas_grade << endl;
            } else {
                cout << "fuel_up: " << v << " Gas_grade: " << gas << endl;
            }
            return 0; 
        }
        int set_Gas_grade(int Gas_grade){
            m_gas_grade = Gas_grade;
            cout <<"Set Gas_grade: "<<m_gas_grade<<endl;
            return m_gas_grade;
        }
        int get_Gas_grade(){
            return m_gas_grade;
        }
};

class Engine{
    private:
        int m_EngineCapacity;
        int m_Horsepower;
        bool m_EngineRunning;
    public:
        Engine(int EngineCapacity=2000, int Horsepower=200){
            m_EngineCapacity = EngineCapacity;
            m_Horsepower = Horsepower;
            m_EngineRunning = false;
        }
        bool EngineStart(){
            if (!m_EngineRunning){
                m_EngineRunning = true;
                return true;
            }
            return false;
        }
        bool get_EngineStatus(){
            return m_EngineRunning;
        }
};

class Car {
    private:
        Engine m_Engine;
        FuelTank m_FuelTank;
        int m_MaxSeating;
        int m_price;
        string m_brand;
        string m_model;
        int m_year;
        void m_UpdatePrice(int base=500000){
            m_price = m_MaxSeating * base;   
        }
    public:
        Car(string x, string y, int z, int s){
            m_brand = x; 
            m_model = y;
            m_year = z;
            m_MaxSeating = s;
            m_price = m_MaxSeating * 500000;    
        }
        int get_MaxSeating(){
            return m_MaxSeating; 
        }
        int get_Price(){
            return m_price;    
        }
        bool get_EngineStatus(){
            return m_Engine.get_EngineStatus(); 
        }
        bool startEngine(){
            return m_Engine.EngineStart();
        }
        int get_Gas_grade(){
            return m_FuelTank.get_Gas_grade();
        }
        int set_Gas_grade(int gas=98){
            return m_FuelTank.set_Gas_grade(gas);
        }
        int fuel_up(int v, int gas=98){
            return m_FuelTank.fuel_up(v, gas);
        }
        string get_brand(){
            return m_brand;
        }
};

class AUDI_Car:public Car{
    public:
    AUDI_Car(string y, int z, int s):Car("Audi", y, z, s){
        cout <<"Constructing AUDI_Car\n";
    }
};

int main(){
    AUDI_Car car_2("A1",2021,2);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.set_Gas_grade(95);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300,95); 
    return 0;
}
