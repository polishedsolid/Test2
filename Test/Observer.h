#pragma once
#include <vector>
#include <memory>

template <typename T>
class CObserver
{
public:
	CObserver();
	~CObserver();

	virtual void Update(T t) = 0;
};

template <typename T>
class CObserverConcrete
{
	std::vector<std::unique_ptr<CObserver<T>>> contena;

public:
	void Add(std::unique_ptr<CObserver> obj)
	{
		contena.emplace_back(obj);
	}

	void Update(T t)
	{
		for (auto& d : contena)
		{
			d->Update(t);
		}
	}
};

template <typename T>
class CObserverA : public CObserver<T>
{
	T mT;
public:
	virtual void Update(T t)
	{
		mT = t;
	}
};

class CConcrete
{
public:
	CConcrete() {};

	void Init() {};
	void Body()
	{
		CObserverConcrete <int>concrete;


	}
};

