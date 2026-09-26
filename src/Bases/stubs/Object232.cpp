#include "Object232.hpp"

extern "C" void func_ov054_02160654();
extern "C" bool func_ov054_02160624(void *);
extern "C" void func_0201c01c(void *);
extern "C" void func_ov054_0215fed0(void *, Vec3_32 *);
extern u8 data_02085b20[1];

namespace Nitro {
	void func_02062418(void *);
}

extern "C" Vec2_32 func_ov098_02187d20(Object232 *self, bool alt);

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

// 0x0218834C
s32 Object232::onRender()
{
	Vec3_32 v;

	v.x = _3f4.pointStart.x;
	v.y = _3f4.pointStart.y - 0x5000;
	v.z = position.z + 0x10000;

	MTX::setTranslation(Game_modelMatrix, v);
	_60c.matrix = Game_modelMatrix;
	_60c.render(&scale);

	v.x = _3f4.pointEnd.x;
	v.y = _3f4.pointEnd.y - 0x5000;

	MTX::setTranslation(Game_modelMatrix, v);
	_60c.matrix = Game_modelMatrix;
	_60c.render(&scale);

	Nitro::func_01ff9010();
	Nitro::func_02062418(data_02085b20);

	v.x = position.x;
	v.y = position.y;
	v.z = position.z;
	v.y -= 0x2000;

	func_ov054_0215fed0(&_494, &v);

	return true;
}

// 0x02187D20 - out = (alt ? _44c[3] : _44c[2]) - Platform::pointStart
extern "C" Vec2_32 func_ov098_02187d20(Object232 *self, bool alt)
{
	Vec2_32 v;
	if (!alt) {
		Vec2_32 *p = &self->_44c[2];
		v = *p;
	} else {
		Vec2_32 *p = &self->_44c[3];
		v = *p;
	}
	i32 *q = &self->_3f4.pointStart.x;
	v.x -= q[0];
	v.y -= q[1];
	return v;
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
