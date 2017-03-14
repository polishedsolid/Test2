#include "stdafx.h"
#include "Mediator.h"


CMediator::CMediator()
{
}


CMediator::~CMediator()
{
}




//-----------------------------------------
void CMainFrame::makeObject()
{
	pYearList = make_unique<CYearList>();
	pMonthList = make_unique<CMonthList>();
	pDayList = make_unique<CDayList>();
	pAgeField = make_unique<CAgeField>();

	pYearList->setMediator(this);
	pMonthList->setMediator(this);
	pDayList->setMediator(this);
}

void CMainFrame::colleagueChanged(CColleague* colleague)
{
	int year, month, day;

	if (colleague == pYearList.get() || colleague == pMonthList.get())
	{

	}
	else if (colleague == pDayList.get())
	{

	}
	else
	{
	
	}

	pAgeField->changeDate(year, month, day);
}





void CColleague::setMediator(CMediator* mediator)
{
	Mediator = mediator;
}



void CYearList::itemStateChange()
{
	Mediator->colleagueChanged(this);
}

void CMonthList::itemStateChange()
{
	Mediator->colleagueChanged(this);
}

void CDayList::itemStateChange()
{
	Mediator->colleagueChanged(this);
}

void CAgeField::changeDate(int year, int month, int day)
{
}




