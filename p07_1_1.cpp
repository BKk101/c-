#include <iostream>
using namespace std;

class Car
{
private:
	int gasolinegauge;
public:
	Car(int gas):gasolinegauge(gas)
	{} 
	int GetGasgauge()
	{
		return gasolinegauge;
	}
};

class HybridCar: public Car
{
private:
	int electricgauge;
public:
	HybridCar(int gas, int elec) : Car(gas), electricgauge(elec)
	{}
	int GetElecgauge()
	{
		return electricgauge;
	}
};

class HybridWaterCar: public HybridCar
{
private:
	int watergauge;
public:
	HybridWaterCar(int gas, int elec, int water=100) : HybridCar(gas, elec), watergauge(water)
	{}
	void ShowCurrentgauge()
	{
		cout<<"remain gasoline: "<<GetGasgauge()<<endl;
		cout<<"remain electricity: "<<GetElecgauge()<<endl;
		cout<<"remain water: "<<watergauge<<endl;
	}
};

int main()
{
	Car car1(100);
	HybridCar car2(80, 80);
	HybridWaterCar car3(60, 60, 60);
	HybridWaterCar car4(60, 50);

	cout<<car1.GetGasgauge()<<endl;
	cout<<car2.GetGasgauge()<<endl;
	cout<<car2.GetElecgauge()<<endl;
	car3.ShowCurrentgauge();
	car4.ShowCurrentgauge();

	return 0;
}