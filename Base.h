#pragma once
#include "Define.h"

class CBase abstract {
protected:
	CBase();
	CBase(CBase& _pPrototype);
	virtual ~CBase() = default;

private:
	_uint iRef{};

public:
	_uint AddRef();
	_uint ReleaseRef();
protected:
	virtual void Free() PURE;
};