#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
public:
	Employee(const char* name)
	{
		strcpy_s(this->mName, strlen(name) + 1, name);
	}
	void ShowName() const
	{
		cout << "name: " << mName << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;

private:
	char mName[100];
};

class PermanentWorker : public Employee
{
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), mSalary(money)
	{

	}
	virtual int GetPay() const override
	{
		return mSalary;
	}
	virtual void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "salary: " << GetPay() << endl << endl;
	}

private:
	int mSalary;
};

class TemporaryWorker : public Employee
{
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), mWorkTime(0), mPayPerHour(pay)
	{

	}
	void AddWorkTime(int time)
	{
		mWorkTime += time;
	}
	virtual int GetPay() const override
	{
		return mWorkTime * mPayPerHour;
	}
	virtual void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "salary: " << GetPay() << endl << endl;
	}

private:
	int mWorkTime;
	int mPayPerHour;
};

class SalesWorker : public PermanentWorker
{
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), mSalesResult(0), mBonusRatio(ratio)
	{  }
	void AddSalesResult(int value)
	{
		mSalesResult += value;
	}
	virtual int GetPay() const override
	{
		return PermanentWorker::GetPay()
			+ (int)(mSalesResult * mBonusRatio);
	}

private:
	int mSalesResult;    // 월 판매실적
	double mBonusRatio;    // 상여금 비율 
};

class ForeignSalesWorker : public SalesWorker
{
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), mRiskLevel(static_cast<eRISK_LEVEL>(risk))
	{

	}
	float GetRiskRatio() const
	{
		switch (mRiskLevel)
		{
		case eRISK_LEVEL::RISK_A:
			return 0.3f;
		case eRISK_LEVEL::RISK_B:
			return 0.2f;
		case eRISK_LEVEL::RISK_C:
			return 0.1f;
		default:
			return 0;
		}
	}
	int GetRiskPay() const
	{
		float riskPay = SalesWorker::GetPay() * GetRiskRatio();
		return static_cast<int>(riskPay);
	}
	virtual int GetPay() const override
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	virtual void ShowSalaryInfo() const override
	{
		ShowName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl;
	}

public:
	static enum class eRISK_LEVEL
	{
		RISK_A,
		RISK_B,
		RISK_C,

	};
private:
	eRISK_LEVEL mRiskLevel;  // 위험 수준
};

class EmployeeHandler
{
public:
	EmployeeHandler() : mEmpNum(0)
	{

	}
	void AddEmployee(Employee* emp)
	{
		mEmpList[mEmpNum++] = emp;  // mEmpList[mEmpNum] = emp; and then ++mEmpNum:
	}
	void ShowAllSalaryInfo() const
	{

		for (int i = 0; i < mEmpNum; i++)
		{
			mEmpList[i]->ShowSalaryInfo();
			cout << "" << endl;
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < mEmpNum; i++)
			sum += mEmpList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < mEmpNum; i++)
			delete mEmpList[i];
	}

private:
	Employee* mEmpList[50];
	int mEmpNum;
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker(
		"KIM", 1000, 0.1, static_cast<int>(ForeignSalesWorker::eRISK_LEVEL::RISK_A)
	);
	fseller1->AddSalesResult(7000);  // 영업실적 7000
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker(
		"Yoon", 1000, 0.1, static_cast<int>(ForeignSalesWorker::eRISK_LEVEL::RISK_B)
	);
	fseller2->AddSalesResult(7000);  // 영업실적 7000
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker(
		"Lee", 1000, 0.1, static_cast<int>(ForeignSalesWorker::eRISK_LEVEL::RISK_C)
	);
	fseller3->AddSalesResult(7000);  // 영업실적 7000
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
}
