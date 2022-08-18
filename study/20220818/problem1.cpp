#include <iostream>
using namespace std;

class Car  // �⺻ ���� �ڵ���
{
public:
	Car(int gasoline)
		: mGasolineGauge(gasoline)
	{
		cout << "�� ���ָ�: " << gasoline << endl;
	}
	int GetGasolineGauge()
	{
		return mGasolineGauge;
	}

private:
	int mGasolineGauge;
};

class HybridCar : public Car  // ������
{
public:
	HybridCar(int gasoline, int electric)
		: Car(gasoline)
		, mElectricGauge(electric)
	{
		cout << "�� ���ⷮ: " << electric << endl;
	}
	int GetElectricGauge()
	{
		return mElectricGauge;
	}

private:
	int mElectricGauge;
};

class HybridWaterCar : public HybridCar  // ���� ���� �ڵ���
{
public:
	HybridWaterCar(int gasoline, int electric, int water)
		: HybridCar(gasoline, electric)
		, mWaterGauge(water)
	{
		cout << "�� ���ͷ�: " << water << endl;
	}
	int GetWaterGauge()
	{
		return mWaterGauge;
	}

	void PrintCurrentGauge()
	{
		cout << "�ܿ� ���ָ�: " << GetGasolineGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElectricGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << GetWaterGauge() << endl;
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