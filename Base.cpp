#include "Base.h"

CBase::CBase()
	:iRef(0)
{
}

CBase::CBase(CBase& _pPrototype)
	:iRef(_pPrototype.iRef)
{
}

_uint CBase::AddRef()
{
	return iRef++;
}

_uint CBase::ReleaseRef()
{
	iRef--;

	if (iRef < 0) {
		Free();

		delete this;

		return -1;
	}

	return iRef;
}
