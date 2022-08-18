#include <iostream>
using namespace std;

class Car  // 기본 연료 자동차
{
public:
	Car(int gasoline)
		: mGasolineGauge(gasoline)
	{
		cout << "총 가솔린: " << gasoline << endl;
	}
	int GetGasolineGauge()
	{
		return mGasolineGauge;
	}

private:
	int mGasolineGauge;
};

class HybridCar : public Car  // 전기차
{
public:
	HybridCar(int gasoline, int electric)
		: Car(gasoline)
		, mElectricGauge(electric)
	{
		cout << "총 전기량: " << electric << endl;
	}
	int GetElectricGauge()
	{
		return mElectricGauge;
	}

private:
	int mElectricGauge;
};

class HybridWaterCar : public HybridCar  // 수력 발전 자동차
{
public:
	HybridWaterCar(int gasoline, int electric, int water)
		: HybridCar(gasoline, electric)
		, mWaterGauge(water)
	{
		cout << "총 워터량: " << water << endl;
	}
	int GetWaterGauge()
	{
		return mWaterGauge;
	}

	void PrintCurrentGauge()
	{
		cout << "잔여 가솔린: " << GetGasolineGauge() << endl;
		cout << "잔여 전기량: " << GetElectricGauge() << endl;
		cout << "잔여 워터량: " << GetWaterGauge() << endl;
	}

private:
	int mWaterGauge;
};

int main()
{
	int gasoline = 100;
	int electric = 200;
	int water = 300;
	HybridWaterCar myCar(gasoline, electric, water);

	myCar.PrintCurrentGauge();
}