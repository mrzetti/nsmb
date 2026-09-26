#include "Object345.hpp"

extern "C" {
void func_ov127_02098c54(Object345 *, u32);
void func_ov127_02098df8();
void func_02044a50(void *);
void func_ov128_020ba0f0(Object345 *, u32);
void func_ov130_021235d0();
void func_02023bfc();
void func_ov128_020b96d8(Object345 *);
void func_ov127_0209a3e4();
void func_ov128_020bdd98(Object345_Sensor *);
void func_ov127_0209c96c();
void func_ov128_020ba2b0(Object345 *);
void func_ov128_020b949c(void *);
void func_ov128_020c6c00(Object345 *);
void func_ov130_02123624();
}

namespace Nitro {
void func_02063a20(void *, u32, u32);
void func_020639b8(void *, u32, u32);
void func_02066eac(void *, u32, u32);
}

extern "C" {
extern u8 data_0208b588;
extern u8 data_0208b58c;
extern u8 data_0208b590;
extern u8 data_0208b594;
}

void *Object345::create()
{
	return new Object345();
}

s32 Object345::onCreate()
{
	return 0;
}

bool Object345::preCreate()
{
	return true;
}

void Object345::postCreate(u32 a)
{
	this->_15();
	func_ov127_02098df8();
	func_ov127_02098c54(this, a);
}

s32 Object345::onDestroy()
{
	return 0;
}

bool Object345::preDestroy()
{
	return true;
}

void Object345::postDestroy(u32 a)
{
	if (a == 2) {
		func_02044a50(this->_25f0);
		func_02044a50(this->_25f4);
		func_ov128_020ba0f0(this, a);
	}
}

s32 Object345::onUpdate()
{
	return 0;
}

bool Object345::preUpdate()
{
	return true;
}

void Object345::postUpdate(u32)
{
}

s32 Object345::onRender()
{
	return 0;
}

bool Object345::preRender()
{
	if (!MGScene::preRender()) {
		return false;
	}
	if (this->onUpdate_7()) {
		func_ov128_020b96d8(this);
		return false;
	}
	if (this->_b4._24 == 0) {
		func_ov127_0209a3e4();
		func_ov128_020bdd98(&this->_b4);
	}
	func_ov127_0209c96c();
	func_ov128_020ba2b0(this);
	return true;
}

void Object345::postRender(u32)
{
}

void Object345::pendingDestroy()
{
}

bool Object345::prepareResourcesSafe(u32, Heap *)
{
	return true;
}

bool Object345::prepareResourcesFast(u32, Heap *)
{
	return true;
}

bool Object345::onHeapCreated()
{
	return true;
}

void Object345::setPosX(u32)
{
}

void Object345::incPosX(u32 a)
{
	if (a == 0) {
		if (this->_64 < 0x7CF) {
			this->_64++;
			if (this->_64 > 0x270E) {
				this->_64 = 0x270E;
			}
		}
	}
	else {
		this->_36ec = nullptr;
		this->_64 = 0;
		if (this->_64 > 0x270E) {
			this->_64 = 0x270E;
		}
		func_ov128_020b949c(this->_36ec);
		this->_a8 = this->_36ec;
	}
	func_ov128_020c6c00(this);
}

bool Object345::onUpdate_0()
{
	return true;
}

bool Object345::_01()
{
	return true;
}

bool Object345::onUpdate_1()
{
	return true;
}

bool Object345::onUpdate_defeated()
{
	return true;
}

bool Object345::onUpdate_3()
{
	if (this->onUpdate_7() != this->_24ec) {
		if (this->onUpdate_7() == 0) {
			this->_13();
		}
		else if (this->onUpdate_7() == 1 && this->_24ec == 0) {
			this->_12();
		}
		this->_24ec = this->onUpdate_7();
	}
	return true;
}

bool Object345::onUpdate_4()
{
	return !this->onUpdate_7();
}

bool Object345::onUpdate_5()
{
	return true;
}

bool Object345::onUpdate_6()
{
	return false;
}

u32 Object345::onUpdate_7()
{
	return this->_24e8;
}

void Object345::onUpdate_8()
{
}

void Object345::onUpdate_9()
{
	this->_24e8++;
	if (this->_24e8 == 1) {
		func_ov130_02123624();
		this->_24f4 = -0x80;
		this->_24f6 = 0x40;
		this->_24f8 = 0x180;
		this->_24fa = 0x80;
		this->_24fc = 0x80;
		this->_24fe = 0xF0;
		this->_b2 = 0;
		this->_2506 = -1;
		this->_2500 = 0;
	}
}

void Object345::_11()
{
	this->_24e8--;
	if (this->_24e8 == 0) {
		func_ov130_021235d0();
		if (this->onUpdate_6()) {
			func_02023bfc();
		}
	}
}

void Object345::_12()
{
}

void Object345::_13()
{
	data_0208b594 = 0;
	data_0208b590 = 0;
	REG_DISPCNT = REG_DISPCNT & ~0x1F00;
	REG_DISPCNT_SUB = REG_DISPCNT_SUB & ~0x1F00;
	REG_POWER_CNT = (REG_POWER_CNT & ~0x8000) | (this->_e4 << 15);
	REG_DISPCNT = (REG_DISPCNT & ~0xE000) | (data_0208b588 << 13);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0xE000) | (data_0208b58c << 13);
	Nitro::func_0206134c(this->_98);
	Nitro::func_02063a20(&this->_20e8[0], 0x20, 0x1E0);
	Nitro::func_020639b8(&this->_20e8[0] + 0x300, 0, 0x40);
	Nitro::func_02066eac(&this->_e8, 0x06400000, 0x1000);
	data_0208b594 = this->_dc;
	data_0208b590 = this->_e0;
	REG_DISPCNT = (REG_DISPCNT & ~0x1F00) | (data_0208b594 << 8);
	REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1F00) | (data_0208b590 << 8);
}

void Object345::_14()
{
}

void Object345::_15()
{
}

void Object345::_16()
{
}

bool Object345::_17()
{
	return (this->settings & 0xFF) == 1;
}

// 0x020feb50
ObjectProfile Object345_Profile = { Object345::create, 345, 345 };
