#pragma once
#include <memory>

//namespace using std;
using namespace std;

class CMediator
{
public:
	CMediator();
	~CMediator();

	virtual void colleagueChanged(CColleague* colleague) = 0;
};




class CMainFrame : public CMediator
{
public:
	void makeObject();
	virtual void colleagueChanged(CColleague* colleague);

private:
	unique_ptr<CYearList> pYearList;
	unique_ptr<CMonthList> pMonthList;
	unique_ptr<CDayList> pDayList;
	unique_ptr<CAgeField> pAgeField;
};




class CColleague
{
protected:
	CMediator* Mediator;
public:
	virtual void setMediator(CMediator* mediator);
	virtual void itemStateChange() = 0;
};


class CYearList : public CColleague
{
public:
	virtual void itemStateChange();
};

class CMonthList : public CColleague
{
public:
	virtual void itemStateChange();
};

class CDayList : public CColleague
{
public:
	virtual void itemStateChange();
};

class CAgeField
{
public:
	void changeDate(int year, int month, int day);
};