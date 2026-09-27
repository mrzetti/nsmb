#include "Object131.hpp"

extern s8 data_ov013_0213be60;
extern s8 data_ov013_0213be64;
extern s16 data_ov013_0213b358[];
extern u8 data_ov013_0213b5cc[];
extern u8 data_ov013_0213b620[];
extern u8 data_ov013_0213b880[];
extern u8 data_ov013_0213b424[];
extern u32 data_ov013_0213baa8[];
extern u8 data_ov000_020ca880;
extern u8 data_ov000_020ca898;

struct Quad {
	s32 v[2][2];
};

struct Slot5 {
	u32 v[5];
};

extern Quad data_ov013_0213b54c;
extern Quad data_ov013_0213b55c;
extern Slot5 data_ov013_0213b63c;
extern Slot5 data_ov013_0213b858;
extern u32 data_ov013_0213b8c0[2];
extern u32 data_ov013_0213b3f4[2];

namespace Nitro
{
void Math_func_01ffbcac(void *, void *, void *);
}

extern "C" {
void func_ov013_0212fae0(Object131::Elem *);
void func_ov013_0212fb14(Object131::Elem *, Model *);
s32 func_ov013_0212fd78(Object131 *);
s32 func_ov013_0212fdcc(Object131 *);
void func_ov013_0213128c(Object131 *);
bool func_ov013_02135080(Object131 *);
void func_ov013_021371d0(Object131 *);
bool func_ov013_021376d8(Object131 *);
void func_ov013_021379bc(Object131 *);
void func_ov013_02130010(Object131 *);
void func_ov013_02130368(Object131 *);
void func_ov013_021305a0(Object131 *);
void func_ov013_021306e8(Object131 *);
void func_ov013_02130e34(Object131 *);
void func_ov013_02130f08(Object131 *);
void func_ov013_02130f28(Object131 *);
void func_ov013_021312e4(Object131 *);
void func_ov013_0213132c(Object131 *);
void func_ov013_021316dc(Object131 *);
bool func_ov013_02131d0c(Object131 *);
void func_ov013_02131d5c(Object131 *);
void func_ov013_02131d7c(Object131 *);
void func_ov013_021328bc(Object131 *);
void func_ov013_021328e4(Object131 *);
void func_ov013_0213290c(Object131 *);
void func_ov013_02132ec0(Object131 *, u32);
void func_ov013_021363c4(Object131 *);
void func_ov013_0213694c(Object131 *);
void func_ov013_021371c0(Object131 *);
void func_ov013_02137298(Object131 *);
void func_ov013_021372ac(Object131 *);
s32 func_ov013_0213884c();
void func_ov013_0213885c(s8);
bool func_ov013_0213886c();
s32 func_ov013_02138888();
void func_ov013_02138898(s8);

void func_02022134(u32, u32);
void func_020433f8(void *, s32, s32);
void func_ov000_020a47a0(ActiveCollider *, Base *, void *, s32);
void func_ov010_020f982c(s32, s32);
void func_ov010_0211f2ec(void *);
void func_ov013_02137328(Object131 *, s32, s32);
void func_ov013_0213775c(Object131 *, s32, s32, s32);
}

// 0x0212fae0
extern "C" void func_ov013_0212fae0(Object131::Elem *self)
{
	self->~Elem();
}

// 0x0212fc14
extern "C" void func_ov013_0212fc14(Object131::Elem *self, Vec3_32 *v)
{
	self->_14.x = v->x;
	self->_14.y = v->y;
	self->_14.z = v->z;
	self->_4.z += self->_10;
}

// 0x0212fd78
extern "C" s32 func_ov013_0212fd78(Object131 *self)
{
	Quad tab = data_ov013_0213b54c;

	return self->position.x + tab.v[self->sub._69][(self->rotation.y < 0) ? 1 : 0];
}

// 0x0212fdcc
extern "C" s32 func_ov013_0212fdcc(Object131 *self)
{
	Quad tab = data_ov013_0213b55c;

	return self->position.x + tab.v[self->sub._69][(self->rotation.y < 0) ? 1 : 0];
}

// 0x02130010
extern "C" void func_ov013_02130010(Object131 *self)
{
	if (self->sub._68 != 0) {
		return;
	}
	self->blendModel.pushAnimation(0xc, 4, 0, 0x800, 0);
}

// 0x02130368
extern "C" void func_ov013_02130368(Object131 *self)
{
	if (self->sub._68 != 1) {
		return;
	}
	self->blendModel.pushAnimation(0x10, 0xa, 0x40000000, 0xc00, 0);
}

// 0x021305a0
extern "C" void func_ov013_021305a0(Object131 *self)
{
	s16 v[3] = { 0, 0, 0 };

	self->blendModel.pushAnimation(v[self->sub._68], 0xa, 0, 0x800, 0);
}

// 0x021306e8
extern "C" void func_ov013_021306e8(Object131 *self)
{
	for (s32 i = 0; i < 8; i++) {
		func_ov013_0212fb14(&self->elems[i], &self->models[0]);
	}
}

// 0x02130e34
extern "C" void func_ov013_02130e34(Object131 *self)
{
	func_020433f8(&self->sub._d2, -0x800, 0x400);
}

// 0x02130f08
extern "C" void func_ov013_02130f08(Object131 *self)
{
	func_020433f8(&self->sub._d2, 0, 0x400);
}

// 0x02130f28
extern "C" void func_ov013_02130f28(Object131 *self)
{
	func_020433f8(&self->sub._d2, 0, 0x400);
}

// 0x0213128c
extern "C" void func_ov013_0213128c(Object131 *self)
{
	s32 *d = (s32 *)data_ov013_0213b5cc;

	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b5cc, 0);
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0xd000 - d[0];
	*(s32 *)((u8 *)&self->collider1 + 0x18) = d[1];
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = d[2] + 0x5000;
	*(s32 *)((u8 *)&self->collider1 + 0x20) = d[3];
}

// 0x021312e4
extern "C" void func_ov013_021312e4(Object131 *self)
{
	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b620, 0);
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0;
	*(s32 *)((u8 *)&self->collider1 + 0x18) = 0x1b000;
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = 0x16000;
	*(s32 *)((u8 *)&self->collider1 + 0x20) = 0x1b000;
}

// 0x0213132c
extern "C" void func_ov013_0213132c(Object131 *self)
{
	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b620, 0);
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0;
	*(s32 *)((u8 *)&self->collider1 + 0x18) = 0x14000;
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = 0x14000;
	*(s32 *)((u8 *)&self->collider1 + 0x20) = 0x14000;
}

// 0x021316dc
extern "C" void func_ov013_021316dc(Object131 *self)
{
	self->direction = self->func_ov000_0209acd4(&self->position);
	self->rotation.y = data_ov013_0213b358[self->direction * 2];
}

// 0x02131d0c
extern "C" bool func_ov013_02131d0c(Object131 *self)
{
	if (!func_ov013_0213886c()) {
		return false;
	}
	func_ov013_0213775c(self, data_ov013_0213b858.v[0], data_ov013_0213b858.v[1], 1);
	self->sub._8 = data_ov013_0213b8c0[0];
	self->sub._c = data_ov013_0213b8c0[1];
	return true;
}

// 0x02131d5c
extern "C" void func_ov013_02131d5c(Object131 *self)
{
	self->sub._e4 = 0x10;
	if (self->sub._e2 > 0) {
		self->sub._e2--;
	}
}

// 0x02131d7c
extern "C" void func_ov013_02131d7c(Object131 *self)
{
	if (self->sub._e4 <= 0) {
		return;
	}
	if (self->sub._e2 <= 0) {
		return;
	}
	if (self->sub._e6 <= 0) {
		return;
	}
	self->sub._e2--;
	self->sub._e4--;
	self->sub._e6--;
}

// 0x02135080
extern "C" bool func_ov013_02135080(Object131 *self)
{
	bool done;

	self->sub._dc--;
	done = (self->sub._dc == 0);
	if (done) {
		return self->func_ov000_0209acd4(&self->position) == 0;
	}
	return false;
}

// 0x0213694c
// (moved)

// 0x021371d0
extern "C" void func_ov013_021371d0(Object131 *self)
{
	s16 *tab = (s16 *)data_ov013_0213baa8[self->sub._68];
	s32 r;

	r = (Wifi::random() & 0x7fff) * 0x7fff;
	r = (r << 1) >> 16;
	self->sub._e4 = tab[(r & 3) * 2];
}

// 0x021376d8
extern "C" bool func_ov013_021376d8(Object131 *self)
{
	u32 tab[2];

	tab[0] = data_ov013_0213b3f4[0];
	tab[1] = data_ov013_0213b3f4[1];
	self->sub._64 = tab[self->sub._62];
	func_ov013_0213775c(self, data_ov013_0213b880[0], data_ov013_0213b880[1], 1);
	return true;
}

// 0x021379bc
extern "C" void func_ov013_021379bc(Object131 *self)
{
	s32 v, f, k, r;

	v = self->sub._de;
	f = (v >> 2) & 1;
	k = 3 - (v & 3);
	if (f) {
		r = k * 0xc0;
	} else {
		r = 0x300 - k * 0xc0;
	}
	v = ((s32 *)data_ov013_0213b424)[self->sub._69] + r;
	self->scale.y = v;
	self->scale.z = v;
}

// 0x021328bc
extern "C" void func_ov013_021328bc(Object131 *self)
{
	func_02022134(0x22, (u32)&self->position);
	func_ov013_02137328(self, 3, 0xd7);
}

// 0x021328e4
extern "C" void func_ov013_021328e4(Object131 *self)
{
	func_02022134(0xf, (u32)&self->position);
	func_ov013_02137328(self, 0, 0xd9);
}

// 0x0213290c
extern "C" void func_ov013_0213290c(Object131 *self)
{
	func_02022134(0xe, (u32)&self->position);
	func_ov013_02137328(self, 3, 0xd7);
}

// 0x02132ec0
extern "C" void func_ov013_02132ec0(Object131 *self, u32 arg)
{
	u32 *v = data_ov013_0213b63c.v + self->sub._68 * 5;

	for (s32 i = 0; i < 5; i++) {
		func_02022134(*v, arg);
		v++;
	}
}

// 0x021363c4
extern "C" void func_ov013_021363c4(Object131 *self)
{
	if (self->sub._e4 <= 0) {
		return;
	}
	if (self->sub._e2 > 0) {
		self->sub._e2--;
		self->sub._e4--;
	}
}

// 0x0213694c
extern "C" void func_ov013_0213694c(Object131 *self)
{
	func_ov010_0211f2ec(Game::getPlayer(0));
	data_ov000_020ca880 &= ~1;
	data_ov000_020ca898 &= ~0x10;
}

// 0x021371c0
extern "C" void func_ov013_021371c0(Object131 *self)
{
	self->sub._e6 = 0x10;
}

// 0x02137298
extern "C" void func_ov013_02137298(Object131 *self)
{
	func_ov010_020f982c(8, self->_2be);
}

// 0x021372ac
extern "C" void func_ov013_021372ac(Object131 *self)
{
	func_ov010_020f982c(7, self->_2be);
}

// 0x0213884c
extern "C" s32 func_ov013_0213884c()
{
	return data_ov013_0213be64;
}

// 0x0213885c
extern "C" void func_ov013_0213885c(s8 value)
{
	data_ov013_0213be64 = value;
}

// 0x0213886c
extern "C" bool func_ov013_0213886c()
{
	return data_ov013_0213be60 == 1;
}

// 0x02138888
extern "C" s32 func_ov013_02138888()
{
	return data_ov013_0213be60;
}

// 0x02138898
extern "C" void func_ov013_02138898(s8 value)
{
	data_ov013_0213be60 = value;
}

void *Object131::create()
{
	return new Object131();
}

void *Object132::create()
{
	return new Object132();
}

void *Object133::create()
{
	return new Object133();
}

// 0x0213ba78
ActorProfile Object131_Profile = { Object131::create, 131, 149, NULL /* TODO: 0x021387f4 */ };

// 0x0213ba84
ActorProfile Object132_Profile = { Object132::create, 132, 150, NULL /* TODO: 0x0213875c */ };

// 0x0213ba90
ActorProfile Object133_Profile = { Object133::create, 133, 151, NULL /* TODO: 0x02138724 */ };
