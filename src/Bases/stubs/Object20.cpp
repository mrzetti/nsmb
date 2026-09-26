#include "Object20.hpp"

extern "C" {
	extern volatile u8 data_ov000_020ca2a4[];
	extern u8 *data_020887f0;
	extern u32 data_0208af3c[2];

	extern Object20Event data_ov054_0217262c;
	extern Object20Event data_ov054_02172634;
	extern Object20Event data_ov054_0217263c;
	extern Object20Event data_ov054_02172644;
	extern Object20Event data_ov054_0217264c;
	extern Object20Event data_ov054_02172654;
	extern Object20Event data_ov054_0217265c;

	void func_ov054_0216821c(Object20 *, u32, u32);
	void func_ov054_02168418(Object20 *, u32);
	void func_ov054_02168bac(u32, u32);
	void func_ov054_02168c80(Object20 *, u32);
	void func_ov054_02168e80(Object20 *, u32);
	void func_ov054_02169014(Object20 *, u32);
}

extern "C" {

bool func_ov054_021692f4(Object20 *self, Object20Event *event) {
	if (self->_14 != event) {
		if (self->_14) {
			self->_41a = -1;
			Object20Event *old = (Object20Event *)self->_14;
			s32 tag = old->_4;
			u8 *base = (u8 *)self + (tag >> 1);
			u32 fn = tag & 1 ? *(u32 *)((u8 *)*(u32 **)base + old->_0) : old->_0;
			((void (*)(void))fn)();
		}
		self->_14 = event;
		self->_41a = 0;
		Object20Event *cur = (Object20Event *)self->_14;
		s32 tag = cur->_4;
		u8 *base = (u8 *)self + (tag >> 1);
		u32 fn = tag & 1 ? *(u32 *)((u8 *)*(u32 **)base + cur->_0) : cur->_0;
		((void (*)(void))fn)();
	}
	return true;
}

void func_ov054_02167be4(Object20 *self) {
	if (func_020202a0() == 1) {
		u8 owner = ((StageActor *)Game::getPlayer(*data_020887f0))->_2be;
		if (owner == self->_2be) {
			return;
		}
		self->destroy(false);
	} else {
		u8 owner0 = ((StageActor *)Game::getPlayer(0))->_2be;
		u8 owner1 = ((StageActor *)Game::getPlayer(1))->_2be;
		if (owner0 == self->_2be) {
			return;
		}
		if (owner1 == self->_2be) {
			return;
		}
		self->destroy(false);
	}
}

bool func_ov054_0216914c(Object20 *self) {
	if (self->_41a == 0) {
		self->_41a++;
		return true;
	}
	if (self->_41a == -1) {
		return true;
	}

	u32 shift = self->_408 >> 4;
	u32 oldLo = self->_3f8;
	u32 oldHi = *(u32 *)((u8 *)self + 0x3fc);
	u32 lo = oldLo & data_0208af3c[0];
	u32 hi = oldHi & data_0208af3c[1];

	if (hi == oldHi && lo == oldLo) {
		u32 curHi = self->_404;
		u32 curLo = self->_400;
		if (curHi == hi && curLo == lo) {
			return true;
		}
		self->_400 = lo;
		self->_404 = hi;
		if (self->_408 & 1) {
			self->setTimedEvent(self->_414, 0, false, false, false);
		} else {
			self->setTimedEvent(self->_414, 0, true, false, false);
		}
		if (!(shift & 0xf)) {
			self->Base::destroy();
		}
	} else {
		if ((shift & 0xf) == 2) {
			if (self->_404 != hi || self->_400 != lo) {
				if (self->_408 & 1) {
					self->setTimedEvent(self->_414, 0, true, false, false);
				} else {
					self->setTimedEvent(self->_414, 0, false, false, false);
				}
			}
		}
		self->_400 = lo;
		self->_404 = hi;
	}

	return true;
}

void func_ov054_021692ac(Object20 *self) {
	if (self->_14 == 0) {
		func_ov054_021692f4(self, (Object20Event *)&data_ov054_02172644);
	}
	Object20Event *cur = (Object20Event *)self->_14;
	s32 tag = cur->_4;
	u8 *base = (u8 *)self + (tag >> 1);
	u32 fn = tag & 1 ? *(u32 *)((u8 *)*(u32 **)base + cur->_0) : cur->_0;
	((void (*)(void))fn)();
}

bool func_ov054_02169290(Object20 *self) {
	if (self->_41a == 0) {
		self->_41a++;
	}
	return true;
}

}

s32 Object20::onCreate() {
	u16 id = this->object_id;

	this->_408 = this->settings;
	this->_3f8 = 0;
	this->_400 = 0;
	this->_404 = 0;
	this->_414 = data_ov000_020ca2a4[0] - 1;
	this->collisionType = 1;

	if (id == 0x89) {
		u8 n = data_ov000_020ca2a4[1];
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 24) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 16) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 8) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_02172634);
	} else if (id == 0x8a) {
		u8 n = data_ov000_020ca2a4[1];
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 24) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 16) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 8) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217263c);
	} else if (id == 0x8b) {
		u8 n;
		this->_418 = 0xff;
		this->_417 = this->_418;
		this->_416 = this->_417;
		this->_415 = this->_416;
		n = data_ov000_020ca2a4[1];
		if (n) {
			this->_415 = n - 1;
		}
		n = (this->_408 >> 24) & 0xff;
		if (n) {
			this->_416 = n - 1;
		}
		n = (this->_408 >> 16) & 0xff;
		if (n) {
			this->_417 = n - 1;
		}
		n = (this->_408 >> 8) & 0xff;
		if (n) {
			this->_418 = n - 1;
		}
		this->_3f8 |= (u64)1 << this->_414;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217262c);
	} else if (id == 0x8c) {
		this->_40c = (this->_408 >> 24) & 0xff;
		this->_417 = (this->_408 >> 16) & 0xf;
		this->_416 = (this->_408 >> 20) & 0xf;
		this->_415 = data_ov000_020ca2a4[1] - 1;
		this->_3f8 |= (u64)1 << this->_415;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217265c);
	} else if (id == 0x8d) {
		this->_419 = data_ov000_020ca2a4[1];
		this->_415 = this->_408 >> 24;
		this->_416 = this->_408 >> 16;
		this->_417 = (this->_408 >> 12) & 0xf;
		this->_418 = (this->_408 >> 8) & 0xf;
		this->_3f8 |= (u64)1 << this->_414;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_02172654);
	} else if (id == 0x8e) {
		this->_419 = data_ov000_020ca2a4[1] - 1;
		this->_415 = this->_408 >> 24;
		this->_413 = this->_419;
		this->_416 = (this->_408 >> 4) & 0xf;
		this->_40e = this->_415 * 10;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217264c);
	} else {
		u8 value = 0;
		bool enable = false;
		if (!(this->_408 & 1)) {
			if (this->_408 & 0x10) {
				value = (this->settings >> 24) & 0xff;
				enable = true;
			}
			u8 n = data_ov000_020ca2a4[0];
			if (n) {
				this->setTimedEvent((u8)(n - 1), value, enable, false, false);
			}
			n = data_ov000_020ca2a4[1];
			if (n) {
				this->setTimedEvent((u8)(n - 1), value, enable, false, false);
			}
		}
		this->Base::destroy();
	}

	return 1;
}

s32 Object20::onDestroy() {
	return true;
}

bool Object20::onUpdate_0() {
	func_ov054_021692ac(this);
	func_ov054_02167be4(this);
	return true;
}

void Object20::pendingDestroy() {

}

void *Object20::create()
{
	return new Object20();
}

void *Object137::create()
{
	return new Object137();
}

void *Object138::create()
{
	return new Object138();
}

void *Object139::create()
{
	return new Object139();
}

void *Object140::create()
{
	return new Object140();
}

void *Object141::create()
{
	return new Object141();
}

void *Object142::create()
{
	return new Object142();
}

// 0x02170820
ActorProfile Object20_Profile = { Object20::create, 20, 27, NULL };

// 0x0217082c
ActorProfile Object137_Profile = { Object137::create, 137, 113, NULL };

// 0x021707f0
ActorProfile Object138_Profile = { Object138::create, 138, 114, NULL };

// 0x021707fc
ActorProfile Object139_Profile = { Object139::create, 139, 115, NULL };

// 0x02170814
ActorProfile Object140_Profile = { Object140::create, 140, 116, NULL };

// 0x02170838
ActorProfile Object141_Profile = { Object141::create, 141, 117, NULL };

// 0x02170808
ActorProfile Object142_Profile = { Object142::create, 142, 118, NULL };

