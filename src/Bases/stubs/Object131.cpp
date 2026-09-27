#include "Object131.hpp"

extern s8 data_ov013_0213be60;
extern s8 data_ov013_0213be64;
extern s16 data_ov013_0213b358[];
extern u8 data_ov013_0213b5cc[];
extern u8 data_ov013_0213b604[];
extern u8 data_ov013_0213b4d4[];
extern u8 data_ov013_0213b4e0[];
extern u8 data_ov013_0213b4ec[];
extern u8 data_ov013_0213b3dc[];
extern u8 data_ov013_0213b39c[];
extern u8 data_ov013_0213b414[];
extern u8 data_ov013_0213b4bc[];
extern u8 data_ov013_0213b5b4[];
extern u8 data_ov013_0213b5b8[];
extern u8 data_ov013_0213ba9c[];
extern u32 data_ov000_020ca8c0;
extern u8 data_ov000_020ca298;
extern u8 data_ov013_0213b620[];
extern u8 data_ov013_0213b880[];
extern u8 data_ov013_0213b424[];
extern u32 data_ov013_0213baa8[];
extern u8 data_ov000_020ca880;
extern u8 data_ov000_020ca898;

struct Quad {
	s32 v[2][2];
};

struct Tri {
	u16 v[3];
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
extern u8 data_ov013_0213b35c[];
extern u8 data_ov013_0213b364[];
extern u8 data_ov013_0213b36c[];
extern u8 data_ov013_0213b374[];
extern u8 data_ov013_0213b37c[];
extern u8 data_ov013_0213b384[];
extern u8 data_ov013_0213b38c[];
extern u8 data_ov013_0213b394[];
extern u8 data_ov013_0213b3a4[];
extern u8 data_ov013_0213b3ac[];
extern u8 data_ov013_0213b3bc[];
extern u8 data_ov013_0213b3c4[];
extern u8 data_ov013_0213b3cc[];
extern u8 data_ov013_0213b3d4[];
extern u8 data_ov013_0213b3ec[];

namespace Nitro
{
void Math_func_01ffbcac(void *, void *, void *);
}

extern "C" {
void func_ov013_0212fae0(Object131::Elem *);
void func_ov013_0212fb14(Object131::Elem *, Model *);
void func_ov013_0212fe20(Object131 *);
void func_ov013_0212fe84(Object131 *);
void func_ov013_0212fee8(Object131 *);
void func_ov013_0212ff4c(Object131 *);
void func_ov013_0212ffac(Object131 *);
void func_ov013_02130054(Object131 *);
void func_ov013_021300b4(Object131 *);
void func_ov013_02130114(Object131 *);
void func_ov013_02130178(Object131 *);
void func_ov013_021301dc(Object131 *);
void func_ov013_02130240(Object131 *);
void func_ov013_021302a0(Object131 *);
void func_ov013_02130304(Object131 *);
void func_ov013_021303b0(Object131 *);
void func_ov013_02130540(Object131 *);
s32 func_ov013_0212fd78(Object131 *);
s32 func_ov013_0212fdcc(Object131 *);
void func_ov013_02131158(Object131 *);
void func_ov013_021311c4(Object131 *);
void func_ov013_02131230(Object131 *);
void func_ov013_021314a4(Object131 *);
void func_ov013_02131504(Object131 *);
void func_ov013_0213128c(Object131 *);
void func_ov013_02130f48(Object131 *);
void func_ov013_02131048(Object131 *);
void func_ov013_0213108c(Object131 *);
void func_ov013_021310d0(Object131 *);
void func_ov013_02131114(Object131 *);
void func_ov013_02131694(Object131 *);
bool func_ov013_0213772c(Object131 *);
bool func_ov013_02138724();
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
void func_ov013_0213a008();
s32 func_ov013_0212fdcc(Object131 *);
s32 func_ov013_0212fd78(Object131 *);
s32 func_ov013_02135000(Object131 *);
void func_ov013_0212fce8(s32, s32 *, s32, s32);
void func_ov013_02130178(Object131 *);
void func_ov013_021304bc(Object131 *);
void func_ov013_02131370(Object131 *);
void func_ov013_02131564(Object131 *);
void func_ov013_02132828(Object131 *);
void func_ov013_021358d4(Object131 *);
bool func_ov013_02135c90(Object131 *);
bool func_ov013_02135d5c(Object131 *);
void func_ov013_02137228(Object131 *);
bool func_ov013_02137830(Object131 *);

void func_ov010_020f98f4();
void *func_02022a04(s32);
void func_ov013_0213a05c();
bool func_ov013_021376d8(Object131 *);
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
	s32 *d;

	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b5cc, 0);
	d = (s32 *)data_ov013_0213b5cc;
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

// 0x0212fe20
extern "C" void func_ov013_0212fe20(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3ec;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x40000000, 0x1000, 0x0);
}

// 0x0212fe84
extern "C" void func_ov013_0212fe84(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3c4;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x0, 0x40000000, 0x800, 0x22);
}

// 0x0212fee8
extern "C" void func_ov013_0212fee8(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3a4;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x40000000, 0x800, 0x0);
}

// 0x0212ff4c
extern "C" void func_ov013_0212ff4c(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b384;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x0, 0x40000000, 0x800, 0x0);
}

// 0x0212ffac
extern "C" void func_ov013_0212ffac(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b374;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x40000000, 0x800, 0x0);
}

// 0x02130054
extern "C" void func_ov013_02130054(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3ac;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x4, 0x0, 0x800, 0x0);
}

// 0x021300b4
extern "C" void func_ov013_021300b4(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b364;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x0, 0x800, 0x0);
}

// 0x02130114
extern "C" void func_ov013_02130114(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b37c;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x4, 0x40000000, 0x800, 0x0);
}

// 0x02130178
extern "C" void func_ov013_02130178(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b36c;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x40000000, 0x800, 0x0);
}

// 0x021301dc
extern "C" void func_ov013_021301dc(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b394;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x4, 0x40000000, 0x800, 0x0);
}

// 0x02130240
extern "C" void func_ov013_02130240(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b35c;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x4, 0x0, 0x800, 0x0);
}

// 0x021302a0
extern "C" void func_ov013_021302a0(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3d4;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x4, 0x40000000, 0x800, 0x0);
}

// 0x02130304
extern "C" void func_ov013_02130304(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3bc;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x40000000, 0x800, 0x0);
}

// 0x021303b0
extern "C" void func_ov013_021303b0(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b3cc;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0x40000000, 0x800, 0x0);
}

// 0x02130540
extern "C" void func_ov013_02130540(Object131 *self)
{
	Tri v;

	v = *(Tri *)data_ov013_0213b38c;

	self->blendModel.pushAnimation(v.v[self->sub._68], 0x4, 0x0, 0x800, 0x0);
}


// 0x02131158
extern "C" void func_ov013_02131158(Object131 *self)
{
	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b5cc, 0);
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0x12000 + self->sub._6c.x - self->position.x;
	*(s32 *)((u8 *)&self->collider1 + 0x18) = self->sub._6c.y - self->position.y - 0x1a000;
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = 0x14000;
	*(s32 *)((u8 *)&self->collider1 + 0x20) = 0x22000;
}

// 0x021311c4
extern "C" void func_ov013_021311c4(Object131 *self)
{
	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b5cc, 0);
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0x12000 + self->sub._6c.x - self->position.x;
	*(s32 *)((u8 *)&self->collider1 + 0x18) = self->sub._6c.y - self->position.y - 0x12000;
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = 0xe000;
	*(s32 *)((u8 *)&self->collider1 + 0x20) = 0x1c000;
}

// 0x02131230
extern "C" void func_ov013_02131230(Object131 *self)
{
	s32 *d;

	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b5cc, 0);
	d = (s32 *)data_ov013_0213b604;
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0x12000 - d[0];
	*(s32 *)((u8 *)&self->collider1 + 0x18) = d[1];
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = d[2] + 0x9000;
	*(s32 *)((u8 *)&self->collider1 + 0x20) = d[3];
}

// 0x021314a4
extern "C" void func_ov013_021314a4(Object131 *self)
{
	s32 *d;

	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b604, 0);
	if (self->rotation.y < 0) {
		return;
	}
	d = (s32 *)data_ov013_0213b604;
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0x8000 - d[0];
	*(s32 *)((u8 *)&self->collider1 + 0x18) = d[1];
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = d[2];
	*(s32 *)((u8 *)&self->collider1 + 0x20) = d[3];
}

// 0x02131504
extern "C" void func_ov013_02131504(Object131 *self)
{
	s32 *d;

	func_ov000_020a47a0(&self->collider1, self, data_ov013_0213b5cc, 0);
	if (self->rotation.y < 0) {
		return;
	}
	d = (s32 *)data_ov013_0213b5cc;
	*(s32 *)((u8 *)&self->collider1 + 0x14) = 0x8000 - d[0];
	*(s32 *)((u8 *)&self->collider1 + 0x18) = d[1];
	*(s32 *)((u8 *)&self->collider1 + 0x1C) = d[2];
	*(s32 *)((u8 *)&self->collider1 + 0x20) = d[3];
}

// 0x02130f48
extern "C" void func_ov013_02130f48(Object131 *self)
{
	func_020433f8(&self->sub._d2, 0, 0x400);
}

// 0x02131048
extern "C" void func_ov013_02131048(Object131 *self)
{
	Mat4x3 mtx;
	s32 v[3];

	self->blendModel.getNodeMatrix(6, &mtx);
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)&self->sub + 0xA0));
}

// 0x0213108c
extern "C" void func_ov013_0213108c(Object131 *self)
{
	Mat4x3 mtx;
	s32 v[3];

	self->blendModel.getNodeMatrix(3, &mtx);
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)&self->sub + 0x90));
}

// 0x021310d0
extern "C" void func_ov013_021310d0(Object131 *self)
{
	Mat4x3 mtx;
	s32 v[3];

	self->blendModel.getNodeMatrix(0xa, &mtx);
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)&self->sub + 0x80));
}

// 0x02131114
extern "C" void func_ov013_02131114(Object131 *self)
{
	Mat4x3 mtx;
	s32 v[3];

	self->blendModel.getNodeMatrix(0xf, &mtx);
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)&self->sub + 0x70));
}

// 0x02131694
extern "C" void func_ov013_02131694(Object131 *self)
{
	self->collisionMgr.func_ov000_020ab010(self, data_ov013_0213b4ec, data_ov013_0213b4d4, data_ov013_0213b4ec, 0);
}

// 0x0213772c
extern "C" bool func_ov013_0213772c(Object131 *self)
{
	self->sub._62++;
	self->sub._62 &= 1;
	self->sub._d4 = -1;
	return func_ov013_021376d8(self);
}

// 0x02138724
extern "C" bool func_ov013_02138724()
{
	func_ov013_0213a008();
	FS::loadFileToOverlayEmb(0x577, 0);
	FS::loadFileEmb(0x576, 0);
	return true;
}

// 0x0212fce8
extern "C" void func_ov013_0212fce8(s32 a, s32 *dst, s32 b, s32 count)
{
	u32 *list = (u32 *)func_02022a04(a);
	s32 i;

	if (list == 0) {
		return;
	}
	if (list[2] == 0) {
		return;
	}
	for (i = 0; i < count; i++) {
		dst[1] = list[8] + list[0x38];
		dst[2] = list[12] + list[0x3c];
		dst[3] = list[16] + list[0x40];
		list = list + 0;
		if (list == 0) {
			break;
		}
	}
}

// 0x021304bc
extern "C" void func_ov013_021304bc(Object131 *self)
{
	Tri a;
	Tri b;

	a = *(Tri *)data_ov013_0213b3dc;
	b = *(Tri *)data_ov013_0213b39c;
	self->blendModel.pushAnimation(b.v[self->sub._68], a.v[self->sub._68], 0xa, 0, 0);
}

// 0x02131370
extern "C" void func_ov013_02131370(Object131 *self)
{
	s32 *d;
	s32 dy, dx;

	func_ov000_020a47a0(&self->collider2, self, data_ov013_0213b620, 0);
	d = (s32 *)data_ov013_0213b620;
	dy = self->sub._6c.y - self->position.y;
	dx = self->sub._6c.x - self->position.x;
	if (self->rotation.y >= 0) {
		*(s32 *)((u8 *)&self->collider2 + 0x14) = dx - d[0];
		*(s32 *)((u8 *)&self->collider2 + 0x18) = dy + d[1];
	} else {
		*(s32 *)((u8 *)&self->collider2 + 0x14) = dx + d[0];
		*(s32 *)((u8 *)&self->collider2 + 0x18) = dy + d[1];
	}
	*(s32 *)((u8 *)&self->collider2 + 0x1C) = 0x16000;
	*(s32 *)((u8 *)&self->collider2 + 0x20) = 0xd000;
}

// 0x02131564
extern "C" void func_ov013_02131564(Object131 *self)
{
	switch (self->sub._68) {
		case 0:
		case 1:
			self->sub._b8 = (self->position.x & 0xf00000) + 0x40000;
			self->sub._bc = self->sub._b8 + 0x84000;
			self->sub._b8 -= 0x4000;
			self->sub._bc -= 0x4000;
			break;
		case 2:
			self->sub._b8 = (self->position.x & 0xf00000) + 0x40000;
			self->sub._bc = self->sub._b8 + 0x84000;
			self->sub._b8 -= 0xa0000;
			self->sub._bc -= 0x90000;
			break;
	}
}

// 0x02132828
extern "C" void func_ov013_02132828(Object131 *self)
{
	switch (self->sub._e8) {
		case 0:
			func_02022134((u32)data_ov013_0213b5b4[self->sub._68 * 2], (u32)&self->sub._6c);
			func_02022134((u32)data_ov013_0213b5b8[self->sub._68 * 2], (u32)&self->sub._6c);
			break;
		case 1:
		case 2:
			func_02022134(0x13, (u32)&self->sub._6c);
			func_02022134(0x14, (u32)&self->sub._6c);
			break;
	}
}

// 0x02135000
extern "C" s32 func_ov013_02135000(Object131 *self)
{
	s32 r;

	if (self->sub._d4 > 0) {
		self->sub._d4 = -1;
		self->sub._62 = self->sub._d4;
		return self->sub._d4;
	}
	if ((self->sub._64 >> 0x10) & 1) {
		r = (func_ov013_0212fd78(self) >= self->sub._bc) ? 0 : 1;
	} else {
		r = (func_ov013_0212fdcc(self) <= self->sub._b8) ? 1 : 0;
	}
	self->sub._d4 = r;
	self->sub._62 = r;
	return r;
}

// 0x021358d4
extern "C" void func_ov013_021358d4(Object131 *self)
{
	s32 t[2];

	t[0] = data_ov013_0213b414[0];
	t[1] = data_ov013_0213b414[1];
	self->sub._d1 = 1;
	self->sub._dc = 0;
	self->velocity.x = t[func_ov013_02135000(self)];
	self->velocity.y = data_ov013_0213b4bc[self->sub._68];
	self->velocity.z = 0;
	func_ov013_02130178(self);
}

// 0x02135c90
extern "C" bool func_ov013_02135c90(Object131 *self)
{
	if (self->velocity.x < 0) {
		if (func_ov013_0212fdcc(self) > self->sub._b8) {
			return false;
		}
		if (self->blendModel.frameController.currentFrame != 0x29800) {
			return false;
		}
		return true;
	}
	if (self->velocity.x > 0) {
		if (func_ov013_0212fd78(self) < self->sub._bc - 0x10000) {
			return false;
		}
		if (self->blendModel.frameController.currentFrame == 0x2000) {
			return true;
		}
	}
	return false;
}

// 0x02135d5c
extern "C" bool func_ov013_02135d5c(Object131 *self)
{
	if (self->velocity.x < 0) {
		if (func_ov013_0212fdcc(self) > self->sub._b8) {
			return false;
		}
		if (self->blendModel.frameController.currentFrame != 0x29800) {
			return false;
		}
		return true;
	}
	if (self->velocity.x > 0) {
		if (func_ov013_0212fd78(self) < self->sub._bc - 0x8000) {
			return false;
		}
		if (self->blendModel.frameController.currentFrame == 0x2000) {
			return true;
		}
	}
	return false;
}

// 0x02137228
extern "C" void func_ov013_02137228(Object131 *self)
{
	s16 *tab = (s16 *)data_ov013_0213ba9c[self->sub._68];

	self->sub._e2 = tab[self->sub._e0];
	if (self->sub._68 == 2) {
		if (func_ov013_02138888() == 0) {
			self->sub._e2 += 0xb4;
		}
	}
	self->sub._e0++;
	self->sub._e0 &= 7;
}

// 0x02137830
extern "C" bool func_ov013_02137830(Object131 *self)
{
	if (self->sub._68 == 2) {
		if (ProcessManager::getNextObjectByObjectID(0x71, 0) != 0) {
			return true;
		}
	}
	*(u8 *)((u8 *)Game::getPlayer(0) + 0x7b7) = 0;
	data_ov000_020ca8c0 |= 1;
	data_ov000_020ca298 = 0;
	extern void func_02011e3c(s32);

	func_02011e3c(0x3c);
	func_ov010_020f98f4();
	*(u8 *)((u8 *)self + 0x3e6) = 1;
	return true;
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
