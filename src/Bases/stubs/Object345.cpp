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
void func_ov127_0209a024(u32 *, s32, s32, s32, s32);
void func_ov127_0209c96c();
void func_ov128_020ba2b0(Object345 *);
void func_ov128_020b949c(u32);
void func_ov128_020b9850(Object345 *);
void func_ov128_020ba26c(u32);
void func_ov128_020bb07c(Object345 *, u32, u32, u32);
void func_ov128_020bddf0(Object345_Sensor *);
void func_ov128_020c5090(Object345 *);
void func_ov128_020c51b4(Object345 *);
void func_ov128_020c5e28(Object345 *);
void func_ov128_020c6950(Object345 *);
void func_ov128_020c6c00(Object345 *);
void func_ov128_020c7328(Object345 *);
void func_ov127_0209a468();
void func_ov127_0209c9ac();
void func_ov127_020996ac(u32);
u32 *func_0200a4c8(u32, u32);
u32 *func_02021580(u32);
void func_02043464(u8 *, u32, u32);
u32 func_020442b0(u32);
s32 func_02045cd0(void *);
s32 func_02045e10(void *);
void func_02045f14(void *, s32);
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
extern Object345_Tbl data_ov128_020fb410;
extern u32 *data_ov127_020b4574[];
extern u32 *data_ov128_02104348[];
extern u32 data_ov127_020b6f70;
extern u32 data_0203996c;
extern u8 data_0208b4c4[];
extern u8 data_0208b4c8[];
extern u8 data_0208b4c9[];
extern u32 data_0208b5e8;
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
	switch (this->_25a0) {
	case 0:
		if (this->_25a4 == 1) {
			func_ov128_020c6c00(this);
		}
		else if (this->_25a5 == 1) {
			func_ov128_020c6c00(this);
		}
		else {
			func_ov128_020c6950(this);
		}
		this->_25a0 = 1;
	case 1:
		func_ov128_020c5090(this);
		func_ov128_020c51b4(this);
		if (this->_36e0 == 1) {
			this->_36ec += 0x64;
		}
		else {
			this->_36ec += this->_36e4;
		}
		{
			s32 v = this->_36ec;
			s32 n;
			this->_36ec = v & 0xF;
			n = v / 16;
			if (this->_36e4 > 0) {
				this->_36e4--;
				if (this->_36e4 == 0) {
					if (this->_25a5 == 1) {
						this->_36c4 = 0x3C;
						this->_25a0 = 2;
					}
					else if (this->_3678 < 5) {
						this->_25a0 = 0;
					}
					else {
						this->_36c4 = 0x3C;
						this->_25a0 = 2;
						this->_25a4 = 1;
					}
				}
			}
			for (s32 i = 0; i < n; i++) {
				if (this->_25a0 != 1) {
					break;
				}
				func_ov128_020c5e28(this);
			}
		}
		if (this->_36c8 > 0) {
			this->_36c8--;
			if (this->_36c8 <= 0) {
				func_ov127_020996ac(0xE);
				if (this->_b3 == 0) {
					this->_b2 = 1;
					this->_b3 = 1;
					this->_b0 = 0;
				}
			}
		}
		func_ov128_020b949c(this->_36ec);
		this->_a8 = this->_36ec;
		break;
	case 2:
		this->_36e0 = 0;
		if (this->_36c4 > 0) {
			this->_36c4--;
		}
		if (this->_36c4 == 0) {
			this->_b2 = 0;
			if (this->_25a4 == 1) {
				this->_25a0 = 3;
				func_ov128_020ba26c(0);
			}
			else {
				this->_25a0 = 3;
				func_ov128_020ba26c(0x12);
				this->_36d4 = 0xB4;
				this->_2668 = 0;
			}
		}
		break;
	case 3:
		if (this->_36d4 > 0) {
			this->_36d4--;
		}
		if (this->_36d4 < 0x78) {
			s32 idx = data_0208b4c4[0];
			if (data_0208b4c8[idx * 4] != 0 && data_0208b4c9[idx * 4] != 0) {
				this->_36d4 = 0;
			}
		}
		if (this->_25a4 == 1) {
			this->_2668++;
			for (s32 i = 0; i < 4; i++) {
				this->_2638[i].y -= 0x100;
				this->_2608[i].x += this->_2638[i].x;
				this->_2608[i].y += this->_2638[i].y;
			}
			for (s32 i = 0; i < 0x80; i++) {
				if (this->_266c[i]._1c == 0) {
					continue;
				}
				this->_266c[i].a.x += this->_266c[i].b.x;
				this->_266c[i].a.y += this->_266c[i].b.y;
				s32 v = func_02045e10(&this->_266c[i].b);
				v = v * 7 / 8;
				if (func_02045cd0(&this->_266c[i].b) != 0) {
					func_02045f14(&this->_266c[i].b, v);
				}
				this->_266c[i]._18++;
				if (this->_266c[i]._18 >= 0x10) {
					this->_266c[i]._1c = 0;
				}
			}
			{
				s32 start = 0;
				s32 life = 0;
				s32 active = 1;
				for (s32 k = 0; k < 4; k++) {
					if (this->_25f8[k] == 0) {
						continue;
					}
					for (s32 j = start; j < 0x80; j++) {
						if (this->_266c[j]._1c == 1) {
							continue;
						}
						{
							u32 r1 = func_020442b0(data_0208b5e8);
							u32 r2 = func_020442b0(data_0208b5e8);
							i16 a1 = (i16)((r2 >> 16) & 0x7FFF) >> 1;
							i16 a2 = (i16)((r1 >> 16) & 0x7FFF) * 2;
							i32 c1 = _FixedCos(a2);
							i32 s1 = _FixedSin(a2);
							i32 c2 = _FixedCos(a1);
							this->_266c[j].a.x = _FixedMul(c2, _FixedMul(c1, 0x8000));
							this->_266c[j].a.y = _FixedMul(s1, 0x8000);
							this->_266c[j].a.x += this->_2608[k].x;
							this->_266c[j].a.y += this->_2608[k].y;
							this->_266c[j].b.x = _FixedMul(c1 << 12, 0x8000);
							this->_266c[j].b.y = _FixedMul(s1 << 12, 0x8000);
							this->_266c[j].b.y -= 0x400;
						}
						this->_266c[j]._1c = active;
						this->_266c[j]._18 = life;
						break;
					}
				}
			}
		}
		break;
	default:
		break;
	}
	return 1;
}

bool Object345::preUpdate()
{
	if (!MGScene::preUpdate()) {
		return false;
	}

	if (data_0208b614->_5()) {
		if (func_0200a4c8(0, 8) || func_0200a4c8(0, 4) || func_0200a4c8(0, 1)
		 || func_0200a4c8(0, 2)) {
			if (this->onUpdate_7()) {
				if (this->_2506 < 0) {
					this->_11();
				}
			}
			else if (!func_02021580(0) && data_ov127_020b6f70 == 0) {
				this->onUpdate_9();
			}
		}
	}

	if (this->onUpdate_7()) {
		func_ov128_020b9850(this);
		return false;
	}
	if (this->_24ec != 0) {
		return false;
	}
	if (this->_b4._24 == 0) {
		func_ov128_020bddf0(&this->_b4);
		func_ov127_0209a468();
	}
	func_ov127_0209c9ac();

	if (this->_68 == 0 && !data_0208b614->_5()) {
		return false;
	}

	func_02043464(this->_a0, this->_9c, data_0203996c);
	this->_7c++;
	if (this->_7c >= 0x28) {
		this->_7c = 0;
	}

	return true;
}

void Object345::postUpdate(u32)
{
}

s32 Object345::onRender()
{
	func_ov128_020bb07c(this, 0xE0, 0x14, 1);

	if (this->_25a0 == 3 && this->_36d4 == 0) {
		data_0208b594 &= ~1;
		data_0208b590 &= ~1;

		if (this->_25a4 == 1) {
			Object345_Tbl t;
			Object345_Tbl tbl = data_ov128_020fb410;

			for (s32 i = 0; i < 4; i++) {
				if (this->_25f8[i] == 0) {
					continue;
				}
				this->_36a0[i]++;
				t = tbl;
				if (this->_36a0[i] >= t.v[i]) {
					this->_36a0[i] = 0;
					this->_36b0[i]++;
					if (this->_36b0[i] >= 0xE) {
						this->_36b0[i] = 0;
					}
					func_ov127_0209a024(data_ov127_020b4574[this->_36b0[i]], this->_2608[i].x >> 12,
					                    (this->_2608[i].y >> 12) - 4, -1, 0);
				}
			}

			for (s32 j = 0; j < 0x80; j++) {
				if (this->_266c[j]._1c == 0) {
					continue;
				}
				func_ov127_0209a024(data_ov128_02104348[this->_266c[j]._18 / 4],
				                    this->_266c[j].a.x >> 12, this->_266c[j].a.y >> 12, -1, 0);
			}
		}

		return 1;
	}

	data_0208b594 |= 1;
	data_0208b590 |= 1;
	func_ov128_020c7328(this);
	return 1;
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

// TODO: the ROM symbol is _ZN9Object3457setPosXEm (one u32) and vtable slot 18 points
// at it, but the body reads r1/r2/r3 and pushes a 5th stack argument, i.e. it takes
// four value parameters. mwccarm 1.2sp3 rejects an out-of-line definition whose
// parameter list differs from the in-class declaration, and every four-parameter
// spelling mangles to ...Emmmm, so this body is not writable under that name.
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
		this->_36ec = 0;
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
