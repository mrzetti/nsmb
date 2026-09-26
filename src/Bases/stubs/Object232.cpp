#include "Object232.hpp"

extern "C" void func_ov054_02160654();
extern "C" bool func_ov054_02160624(void *);
extern "C" void func_0201c01c(void *);

void *Object232::create()
{
	return new Object232();
}

void Object232::pendingDestroy()
{
}

s32 Object232::onDestroy()
{
	func_0201c01c(&_3f4);
	func_0201c01c(&_69c[0]);
	func_0201c01c(&_69c[1]);

	return true;
}

bool Object232::onHeapCreated()
{
	if (!_60c.create(FS::Cache::getFile(0x5C3), 0, 0))
		return false;

	return func_ov054_02160624(&_494);
}

// 0x02187CF8 - Object232_Profile::loadResources
extern "C" bool func_ov098_02187cf8()
{
	FS::Cache::loadFile(0x5C3, false);
	func_ov054_02160654();

	return true;
}

// 0x02189718
ActorProfile Object232_Profile = { Object232::create, 232, 195, func_ov098_02187cf8 };
