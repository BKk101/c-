#include <iostream>
using namespace std;

class Car
{
private:
	int gasonlineGauge;
public:
	Car(int gas): gasonlineGauge(gas)
	{}
	int GetGasGauge()
	{
		return gasonlineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec): Car(gas), electricGauge(elec)
	{}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water): HybridCar(gas, elec), waterGauge(water)
	{}
	void ShowCurrentGauge()
	{
		cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
		cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
		cout<<"잔여 워터량: "<<waterGauge<<endl;
	}
};

int main()
{
	HybridWaterCar wCar(79,65,35);
	wCar.ShowCurrentGauge();
	return 0;
}