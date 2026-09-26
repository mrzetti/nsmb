#include "Object232.hpp"

extern "C" void func_ov054_02160654();
extern "C" bool func_ov054_02160624(void *);
extern "C" void func_0201c01c(void *);
extern "C" void func_ov054_0215fed0(void *, Vec3_32 *);
extern "C" void func_0201b6d4(void *, void *, void *, void *, void *, void *);
extern "C" void func_0201c080(void *);
extern "C" void func_0201bd60(void *, void *, i32, i32, i32, i32, i32, i32, i32, i32);
extern "C" void func_ov054_02160118(void *);
extern "C" void func_0201dbcc(void *, i32, i32, i32, i32);
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

// 0x02188514
s32 Object232::onCreate()
{
	if (!prepareResourcesSafe(0x40, Memory_gameHeap))
		return 0;

	position.z = 0x100000;
	scale.set(0x1000, 0x1000, 0x1000);

	_7ac = ((settings >> 28) & 0xFF) << 15;
	if (_7ac == 0)
		_7ac = 0x80000;

	s32 dir = ((settings << 4) >> 28) & 0xFF;
	_77c[0].set(0, 0);
	_77c[1].set(_7ac, -0x8000);
	_77c[2].set(_7ac, -0x8000);

	if (dir >= 8)
		dir -= 0x10;
	_77c[3].x = _7ac << 1;
	_77c[3].y = dir << 16;

	{
		Vec2_32 v0;
		v0.x = _77c[0].x;
		v0.y = _77c[0].y;
		Vec2_32 v1;
		v1.x = _77c[3].x;
		v1.y = _77c[3].y;
		Vec2_32 v2;
		v2.x = _77c[1].x;
		v2.y = _77c[1].y;
		Vec2_32 v3;
		v3.x = _77c[2].x;
		v3.y = _77c[2].y;

		func_0201b6d4(&_3f4, this, &v0, &v1, &v2, &v3);
	}
	func_0201c080(&_3f4);

	func_0201bd60(&_69c[0], this, _77c[0].x, _77c[0].y, 0x3000, 0x8000, -0x8000, 0, 0, 0);
	func_0201c080(&_69c[0]);

	func_0201bd60(&_69c[1], this, _77c[3].x, _77c[3].y, 0x3000, 0x8000, -0x8000, 0, 0, 0);
	func_0201c080(&_69c[1]);

	Vec2_32 rel;
	func_ov054_02160118(&_494);

	_5c8 = 1;

	_4a4[0].x = _77c[0].x;
	_4a4[0].y = _77c[0].y;

	rel = func_ov098_02187d20(this, false);
	_4a4[1].x = rel.x;
	_4a4[1].y = rel.y;

	rel = func_ov098_02187d20(this, true);
	_4a4[2].x = rel.x;
	_4a4[2].y = rel.y;

	_4a4[3].x = _77c[3].x;
	_4a4[3].y = _77c[3].y;

	func_0201dbcc(&_5cc[0], 0x400, 0x140, _77c[1].y, 0x7FFFFFFF);
	func_0201dbcc(&_5ec[0], 0x400, 0x140, _77c[2].y, 0x7FFFFFFF);

	_7b0 = 0;
	collisionType = CT_Collisionless;

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
