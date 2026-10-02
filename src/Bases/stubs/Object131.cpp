#include "Object131.hpp"

extern s8 data_ov013_0213be60;
extern s8 data_ov013_0213be64;
extern s16 data_ov013_0213b354[];
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
extern u32 data_02085a7c[];
extern u32 data_ov000_020cae0c[];
extern u32 data_ov013_0213b48c[];
extern u32 data_ov013_0213b51c[];
extern u32 data_ov013_0213b528[];
extern u32 data_ov013_0213b534[];
extern u32 data_ov013_0213b860[];
extern u32 data_ov013_0213b868[];
extern u32 data_ov013_0213ba38[];
extern u32 data_ov013_0213be6c[];
extern u32 data_ov013_0213be8c[];
extern u32 data_ov013_0213be70[];
extern u32 data_ov013_0213be74[];
extern u32 data_ov013_0213ba70[];
extern u32 data_ov013_0213b848[];
extern u32 data_ov013_0213b850[];
extern u8 data_ov000_020ca298;
extern u8 data_ov013_0213b620[];
extern u8 data_ov013_0213b424[];
extern u8 data_0208af3c[];
extern u32 data_ov013_0213b44c[];
extern u32 data_ov013_0213b454[];
extern u32 data_ov013_0213b464[];
extern u32 data_ov013_0213b45c[];
extern u32 data_ov013_0213baa8[];
extern u8 data_ov000_020ca880;
extern u8 data_ov000_020ca898;

struct Quad {
	s32 v[2][2];
};

struct Pair {
	s32 a, b;
};

// An 8-byte copy of this union is a WIDE SCALAR move in mwccarm: both source words are
// loaded before either is stored. The same two words as a plain aggregate come out
// interleaved (ldr/str/ldr/str), which is not what the target has.
union Pair8 {
	struct _ {
		s32 a, b;
	} s;
	u64 q;
};

struct Tri {
	u16 v[3];
};

struct Tri3 {
	u32 v[3];
};

struct Slot5 {
	u32 v[5];
};

extern Tri3 data_ov013_0213b498;
extern Tri3 data_ov013_0213b540;
extern u8 data_ov013_0213b3b4[];
extern u8 data_ov013_0213b3e4[];
extern Pair data_ov013_0213b858;
extern Pair data_ov013_0213b880;
extern Pair data_ov013_0213b960;
extern Pair data_ov013_0213b968;
extern Pair data_ov013_0213b970;
extern Pair data_ov013_0213b8f8;
extern Pair data_ov013_0213b900;
extern Pair data_ov013_0213ba10;
extern Pair data_ov013_0213b9f0;
extern Pair data_ov013_0213b8b8;
extern Pair data_ov013_0213b9b8;
extern Pair8 data_ov013_0213b700;
extern Pair8 data_ov013_0213b710;
extern Pair8 data_ov013_0213b718;
extern Pair8 data_ov013_0213b728;
extern Pair8 data_ov013_0213b738;
extern Pair8 data_ov013_0213b740;
extern Pair8 data_ov013_0213b750;
extern Pair8 data_ov013_0213b778;
extern Pair8 data_ov013_0213b798;
extern Pair8 data_ov013_0213b7a0;
extern Pair8 data_ov013_0213b7a8;
extern Pair8 data_ov013_0213b7b0;
extern Pair8 data_ov013_0213b7b8;
extern Pair8 data_ov013_0213b7c0;
extern Pair8 data_ov013_0213b7d0;
extern Pair8 data_ov013_0213b7d8;
extern Pair8 data_ov013_0213b7e0;
extern Pair8 data_ov013_0213b800;
extern Pair8 data_ov013_0213b818;
extern Pair8 data_ov013_0213b820;
extern Pair8 data_ov013_0213b828;
extern Pair8 data_ov013_0213b840;
extern Pair8 data_ov013_0213b888;
extern Pair8 data_ov013_0213b8a8;
extern Pair8 data_ov013_0213b8b0;
extern Pair8 data_ov013_0213b8c8;
extern Pair8 data_ov013_0213b8d8;
extern Pair8 data_ov013_0213b908;
extern Pair8 data_ov013_0213b928;
extern Pair8 data_ov013_0213b958;
extern Pair8 data_ov013_0213b980;
extern Pair8 data_ov013_0213b988;
extern Pair8 data_ov013_0213b990;
extern Pair8 data_ov013_0213b9c0;
extern Pair8 data_ov013_0213b9c8;
extern Pair8 data_ov013_0213b9d0;
extern Pair8 data_ov013_0213b9e8;
extern Pair8 data_ov013_0213b9f8;
extern Pair8 data_ov013_0213ba00;
extern Pair8 data_ov013_0213ba08;
extern Pair8 data_ov013_0213ba20;
extern Pair8 data_ov013_0213ba48;
extern Pair8 data_ov013_0213ba50;
extern Pair8 data_ov013_0213ba58;
extern Pair8 data_ov013_0213ba60;
extern Quad data_ov013_0213b54c;
extern Quad data_ov013_0213b55c;
extern Slot5 data_ov013_0213b63c;
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
bool func_ov013_02133fc4(Object131 *);
void func_ov013_0213170c(Object131 *);
void func_ov013_021315f8(Object131 *, s32);
void func_ov000_020a46bc(ActiveCollider *);
void func_ov013_021305ec(void *);
void func_ov013_021372c0(Object131 *);
void func_ov013_021374b8(Object131 *);
void func_ov013_02137550(Object131 *, s32);
void func_ov013_02137e38(Object131 *, Base *);
bool func_ov013_0213875c();
void func_020205ec(Base *);
s32 func_0200aca0(s32);
s32 func_0200acc4(s32);
void func_ov010_020e6964(s32, void *, s32);
void *func_02022a04(s32);
void func_ov013_0213a05c();
bool func_ov013_021376d8(Object131 *);
void func_ov013_02137328(Object131 *, s32, s32);
bool func_ov013_0213775c(Object131 *, Pair, s32);
s32 func_ov013_02136d9c(Object131 *);
void func_ov013_021375e8(Object131 *, s32);
void func_ov013_02130414(Object131 *);
bool func_ov013_02136f50(Object131 *, s32);
bool func_ov013_02137114(Object131 *, s32);
void func_ov013_02135e0c(Object131 *);
void func_ov013_02130414(Object131 *);
bool func_ov013_02133f00(Object131 *);
void func_ov013_02137914(Object131 *, PlayerBase *);
void func_ov013_02130e58(Object131 *);
bool func_ov013_02136aac(Object131 *);
bool func_ov013_02134dd4(Object131 *);
s32 func_ov000_020a917c(CollisionManager *);
// The target calls this one as a BARE symbol, so it is not a member of CollisionMgr in
// the original: it takes the manager as a plain first argument. Declaring it as a free
// C-linkage function here is what makes the call site emit `bl func_01ffe778`.
bool func_01ffe778(CollisionManager *, i32 *, u32);
bool func_ov013_02135eb4(Object131 *);
void func_ov013_02130f68(Object131 *);
s32 func_ov013_02135dd8(Object131 *);
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
	func_ov013_0213775c(self, data_ov013_0213b858, 1);
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

// Same fixed dispatch intrinsic as PmfPair in onCreate (see the comment there): the field
// address in r3, the adjustment word in r1, `ands #1 / ldrne x3 / ldrne x3 / ldreq x3 / blx`.
// This function needs the third of the 8-byte function fields as well, at Sub+0x30 (0xa30),
// so it gets its own wrapper rather than extending PmfPair. Object131's layout is untouched.
class PmfTriple {
public:
	u8 _pad[0xa20];
	void (Object131::*fn0)();
	void (Object131::*fn1)();
	void (Object131::*fn2)();
};

// 0x02134dd4
// Every exit funnels into the one `return true`, which is what collapses four separate
// epilogues in the source into the target's single `mov r0,#1` tail.
extern "C" bool func_ov013_02134dd4(Object131 *self)
{
	PmfTriple *h = (PmfTriple *)self;

	if (self->sub._60 == 0) {
		*(s32 *)((u8 *)self + 0xd0) = 0;
		self->sub._d1 = 1;
		func_ov013_02130540(self);
		self->direction = 1;
		self->sub._60++;
	} else if (self->sub._60 != -1) {
		self->blendModel.update();
		self->updateVerticalVelocity();
		self->func_ov000_0209c85c();
		if (func_ov000_020a917c(&self->collisionMgr)) {
			*(s32 *)((u8 *)self + 0xd4) = 0;
		}
		(self->*h->fn2)();
		func_ov000_020a46bc(&self->collider1);
		self->rotation.y += data_ov013_0213b354[self->direction];
		func_ov013_02130f08(self);
		if (self->rotation.y >= data_ov013_0213b358[0]) {
			self->rotation.y = data_ov013_0213b358[0];
			(self->*h->fn0)();
			func_ov000_020a46bc(&self->collider1);
			(self->*h->fn1)();
			func_ov000_020a46bc(&self->collider2);
			func_ov013_0213775c(self, data_ov013_0213b900, 1);
		} else {
			if (self->rotation.y <= data_ov013_0213b358[1]) {
				self->rotation.y = data_ov013_0213b358[1];
				(self->*h->fn0)();
				func_ov000_020a46bc(&self->collider1);
				(self->*h->fn1)();
				func_ov000_020a46bc(&self->collider2);
				self->sub._62 = 0;
				self->sub._64 = 0;
				func_ov013_0213775c(self, data_ov013_0213b8f8, 1);
			}
		}
	}
	return true;
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
	func_ov013_0213775c(self, data_ov013_0213b880, 1);
	return true;
}

// 0x0213775c
// The Pair argument is the state pair stored at _pad9e0[0]: it is compared and assigned
// through a real pmf type, which is what makes the compiler take the address of BOTH
// operands (`add r1,this,#0x9e0` / `add r0,sp,#0x14`) and compare the words one at a time
// instead of as a u64. Both dispatch sites reach the member as `add r3, this, #0x9e0`, a
// single add off this, so it is addressed through a wrapper rather than a saved pointer,
// and never through a pmf-typed local.
typedef void (Object131::*PmfS32)(s32);

class Object131Pmf {
public:
	u8 _pad[0x9e0];
	PmfS32 fn;
};

// The early-outs fall into the one shared exit rather than repeating it, which is what
// materialises the target's `mov r0,#1` on a single tail instead of inline epilogues.
extern "C" bool func_ov013_0213775c(Object131 *self, Pair p, s32 arg)
{
	Object131Pmf *h = (Object131Pmf *)self;

	if (h->fn != *(PmfS32 *)&p) {
		if (h->fn != NULL) {
			self->sub._60 = -1;
			(self->*h->fn)(arg);
		}
		h->fn = *(PmfS32 *)&p;
		self->sub._60 = 0;
		(self->*h->fn)(arg);
	}
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

	self->blendModel.getNodeMatrix(6, &mtx);
	s32 v[3] = { 0, 0, 0 };
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)self + 0xAA0));
}

// 0x0213108c
extern "C" void func_ov013_0213108c(Object131 *self)
{
	Mat4x3 mtx;

	self->blendModel.getNodeMatrix(3, &mtx);
	s32 v[3] = { 0, 0, 0 };
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)self + 0xA90));
}

// 0x021310d0
extern "C" void func_ov013_021310d0(Object131 *self)
{
	Mat4x3 mtx;

	self->blendModel.getNodeMatrix(0xa, &mtx);
	s32 v[3] = { 0, 0, 0 };
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)self + 0xA80));
}

// 0x02131114
extern "C" void func_ov013_02131114(Object131 *self)
{
	Mat4x3 mtx;

	self->blendModel.getNodeMatrix(0xf, &mtx);
	s32 v[3] = { 0, 0, 0 };
	Nitro::Math_func_01ffbcac(v, &mtx, (void *)((u8 *)self + 0xA70));
}

// 0x02131694
extern "C" void func_ov013_02131694(Object131 *self)
{
	self->collisionMgr.func_ov000_020ab010(self, data_ov013_0213b4d4, data_ov013_0213b4e0, data_ov013_0213b4ec, 0);
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

// 0x0212fc40
extern "C" void func_ov013_0212fc40(Object131::Elem *e, s32 *a, s32 v)
{
	s32 r;

	r = Wifi::random();
	e->_0 = v;
	r = (r & 0x7fff) * 0x7fff;
	r = (r >> 15) & 0xf;
	e->_4.x = 0;
	e->_4.y = 0;
	e->_4.z = (r << 12) - 0x8000;
	e->_10 = 0x300;
	e->_14.x = a[1];
	e->_14.y = a[2];
	e->_14.z = a[3];
}

// 0x02130718
extern "C" void func_ov013_02130718(Object131 *self, s32 *a, s8 *b, s32 count)
{
	for (s32 i = 0; i < 8; i++) {
		if (i < count) {
			func_ov013_0212fc40(&self->elems[i], a, b[i]);
		} else {
			func_ov013_0212fc40(&self->elems[i], a, -1);
		}
	}
}

// 0x021327c0
extern "C" void func_ov013_021327c0(Object131 *self, u32 arg)
{
	func_02022134(data_ov013_0213b51c[self->sub._68], arg);
	func_02022134(data_ov013_0213b528[self->sub._68], arg);
	func_02022134(data_ov013_0213b534[self->sub._68], arg);
}

// 0x02132fa0
extern "C" void func_ov013_02132fa0(Object131 *self)
{
	Vec3_32 v;

	v.x = self->position.x;
	v.y = ((u32 *)data_ov000_020cae0c)[((u32 *)data_02085a7c)[0]];
	v.z = 0x200000;
	func_02022134(0x10, (u32)&v);
	func_02022134(0x11, (u32)&v);
}

// 0x021350d4
extern "C" void func_ov013_021350d4(Object131 *self, s32 *a)
{
	s32 v;

	a[1] += 0xc000;
	a[2] += 0xa000;
	s8 id = self->sub._68;
	s32 flags = 0xffff0 & (((s16 *)data_ov013_0213b48c)[self->sub._ea] << 4);

	flags |= 3;
	flags |= id << 28;
	v = 0x1400;
	Actor::spawnActor(0x4e, flags, (Vec3_32 *)a, 0, &v, 0);
}

// 0x021351c8
extern "C" void func_ov013_021351c8(Object131 *self, Vec3_32 *a)
{
	s8 id = self->sub._68;
	s32 v;

	v = 0x1400;
	Actor::spawnActor(0x4e, 0x1001 | (id << 28), a, 0, &v, 0);
}

// 0x02135210
extern "C" void func_ov013_02135210(Object131 *self, Vec3_32 *a)
{
	s8 id = self->sub._68;
	s32 v;

	v = 0x1000;
	Actor::spawnActor(0x4e, id << 28, a, 0, &v, 0);
}

// 0x021352cc
extern "C" void func_ov013_021352cc(Object131 *self)
{
	Vec3_32 v;
	s32 t[2];

	v.x = self->sub._7c.x;
	v.y = self->sub._7c.y;
	v.z = self->sub._7c.z - 0x10000;
	func_02012398(0x135, &v);
	t[0] = 0;
	t[1] = 0;
	func_ov010_020e6964(4, t, 0);
}

// 0x02135d0c
extern "C" s32 func_ov013_02135d0c(Object131 *self)
{
	if (self->velocity.x < 0) {
		if (func_ov013_0212fdcc(self) > self->sub._b8) {
			return 0;
		}
		return 1;
	}
	if (self->velocity.x > 0) {
		if (func_ov013_0212fd78(self) >= self->sub._bc - 0x2000) {
			return 2;
		}
	}
	return 0;
}

// 0x021387f4
extern "C" bool func_ov013_021387f4()
{
	func_ov013_0213a05c();
	FS::loadFileEmb(0x577, 0);
	FS::loadFileEmb(0x576, 0);
	FS::loadFileToOverlayEmb(0x4d9, 0);
	FS::loadFileToOverlayEmb(0x4da, 0);
	return true;
}

// 0x02133fc4
extern "C" bool func_ov013_02133fc4(Object131 *self)
{
	if (self->sub._60 == 0) {
		func_ov013_0212ffac(self);
		self->velocity.x = 0;
		self->velocity.y = 0;
		self->velocity.z = 0;
		self->sub._d1 = 0;
		self->sub._b5 = 1;
		self->sub._60++;
	} else if (self->sub._60 != -1) {
		self->_11();
		if (self->blendModel.frameController.finished()) {
			func_ov013_02137550(self, 1);
		}
	}
	return true;
}

// 0x021372c0
extern "C" void func_ov013_021372c0(Object131 *self)
{
	func_020205ec(self);
	func_ov010_020f982c(3, self->_2be);
	Vec3_32 v;
	s32 pz = self->position.z;
	v.y = func_0200aca0(0);
	v.x = func_0200acc4(0);
	v.z = pz;
	func_02012398(0xd7, &v);
}

// 0x021374b8
extern "C" void func_ov013_021374b8(Object131 *self)
{
	u32 *flag = (u32 *)data_ov013_0213be6c;
	Pair *e;

	if ((*flag & 1) == 0) {
		Pair *t = (Pair *)data_ov013_0213be8c;

		t[0] = *(Pair *)data_ov013_0213b860;
		t[1] = *(Pair *)data_ov013_0213b868;
		t[2] = *(Pair *)data_ov013_0213ba38;
		*flag |= 1;
	}
	e = (Pair *)data_ov013_0213be8c + self->sub._68;
	func_ov013_0213775c(self, *e, 1);
}

// 0x02137550
extern "C" void func_ov013_02137550(Object131 *self, s32 arg)
{
	u32 *flag = (u32 *)data_ov013_0213be70;
	Pair *e;

	if ((*flag & 1) == 0) {
		Pair *t = (Pair *)data_ov013_0213be74;

		t[0] = *(Pair *)data_ov013_0213ba70;
		t[1] = *(Pair *)data_ov013_0213b848;
		t[2] = *(Pair *)data_ov013_0213b850;
		*flag |= 1;
	}
	e = (Pair *)data_ov013_0213be74 + self->sub._68;
	func_ov013_0213775c(self, *e, 1);
}

// 0x02137e38
extern "C" void func_ov013_02137e38(Object131 *self, Base *b)
{
	void (**vt)(Base *, Object131 *, s32, s32, s32);
	void *p;

	if (self->sub._c6 != 0) {
		return;
	}
	if (self->sub._da != 0) {
		return;
	}
	if (*(s16 *)((u8 *)b + 0x79c) != 0) {
		return;
	}
	if (*(u8 *)((u8 *)b + 0x7c1) == 0) {
		return;
	}
	p = *(void **)b;
	vt = (void (**)(Base *, Object131 *, s32, s32, s32))p;
	vt[25](b, self, 0, 0x4000, 0);
}

// 0x0213875c
extern "C" bool func_ov013_0213875c()
{
	func_ov013_0213a05c();
	FS::loadFileToOverlayEmb(0x4d9, 0);
	FS::loadFileEmb(0x4d8, 0);
	FS::loadFileToOverlayEmb(0x4d2, 0);
	FS::loadFileToOverlayEmb(0x4d3, 0);
	FS::loadFileToOverlayEmb(0x4d4, 0);
	FS::loadFileToOverlayEmb(0x4d5, 0);
	FS::loadFileToOverlayEmb(0x4d6, 0);
	FS::loadFileToOverlayEmb(0x4d7, 0);
	return true;
}

// mwccarm lowers a call through a pointer-to-member FUNCTION FIELD with a fixed
// intrinsic: the field address in r3, the adjustment word in r1, and the dispatch
// `ands #1 / ldrne r2,[r0] / ldrne r1,[r3] / ldrne r1,[r2,r1] / ldreq r1,[r3] /
// blx r1`. The 8 bytes of `Sub` at +0xa20 are that field. This wrapper only names it;
// the class layout of Object131 is untouched.
class PmfPair {
public:
	u8 _pad[0xa20];
	void (Object131::*fn0)();
	void (Object131::*fn1)();
};

// 0x021324c8
s32 Object131::onCreate()
{
	Tri3 v;
	PmfPair *h;
	s32 i;

	func_ov013_0213170c(this);
	v = data_ov013_0213b540;
	if (!prepareResourcesSafe(v.v[sub._68], Memory_gameHeap)) {
		return 0;
	}
	func_ov013_021316dc(this);
	scale.x = 0x1200;
	scale.y = 0x1200;
	scale.z = 0x1200;
	func_ov013_02131694(this);
	h = (PmfPair *)this;
	(this->*h->fn0)();
	func_ov000_020a46bc(&collider1);
	(this->*h->fn1)();
	func_ov000_020a46bc(&collider2);
	velocity.x = 0;
	velocity.y = 0;
	velocity.z = 0;
	accelV = -0x300;
	minVelocity.x = 0x4000;
	minVelocity.y = -0x8000;
	minVelocity.z = 0;
	sub._de = -1;
	sub._d7 = 0;
	sub._c4 = 0;
	sub._pad5[1] = 3;
	sub._c6 = 0;
	sub._cc = 0;
	sub._6a = 0;
	sub._da = 0;
	if (sub._68 == 2) {
		sub._pad5[0] = 0x1e;
	} else {
		sub._pad5[0] = 9;
	}
	func_ov013_02131564(this);
	i = ((s32 *)data_ov013_0213b424)[sub._69];
	scale.x = i;
	scale.y = i;
	scale.z = i;
	sub._b4 = 0;
	sub._b5 = 0;
	func_ov013_021315f8(this, 0);
	func_ov013_02138898(0);
	func_ov013_0213885c(0);
	blendModel.setCommandCallback(func_ov013_021305ec, 0, 6, 2);
	blendModel.drawable.userData = this;
	collisionType = 1;
	_pad8[1] = 1;
	return 1;
}

Object131::~Object131()
{
}

bool Object131::_01()
{
	return false;
}

void Object131::_11()
{
	blendModel.update();
}

void Object131::pendingDestroy()
{
}

void *Object131::create()
{
	return new Object131();
}

// 0x02137328
extern "C" void func_ov013_02137328(Object131 *self, s32 a, s32 b)
{
	func_020205ec(self);
	func_ov010_020f982c(a, self->_2be);
	Vec3_32 v;
	s32 pz = self->position.z;
	v.y = func_0200aca0(0);
	v.x = func_0200acc4(0);
	v.z = pz;
	func_02012398(b, &v);
}

// 0x02136f50
extern "C" bool func_ov013_02136f50(Object131 *self, s32 i)
{
	u32 cur = *(u32 *)((u8 *)self + 0x488);

	if (!(self->sub._e2 > 0) && cur == data_ov013_0213b44c[i]) {
		func_ov013_021375e8(self, 1);
		func_ov013_02137228(self);
		return true;
	}
	if (!(self->sub._e4 > 0) && cur == data_ov013_0213b454[i]) {
		func_ov013_021371d0(self);
		if (func_ov013_02136d9c(self)) {
			func_ov013_0213775c(self, data_ov013_0213ba10, 1);
			return true;
		}
	}
	return false;
}

// 0x02137114
extern "C" bool func_ov013_02137114(Object131 *self, s32 i)
{
	u32 cur = *(u32 *)((u8 *)self + 0x488);

	if (!(self->sub._e2 > 0) && cur == data_ov013_0213b464[i]) {
		func_ov013_021375e8(self, 1);
		func_ov013_02137228(self);
		return true;
	}
	if (!(self->sub._e4 > 0) && cur == data_ov013_0213b45c[i]) {
		func_ov013_021371d0(self);
		if (func_ov013_02136d9c(self)) {
			func_ov013_0213775c(self, data_ov013_0213b9f0, 1);
			return true;
		}
	}
	return false;
}

// Same pmf intrinsic as PmfPair / PmfTriple, over the four function fields at +0x9f0,
// +0x9f8, +0xa08 and +0xa48. The wrapper has to start at the LOWEST of them, so it
// swallows Sub+0x00..Sub+0x4c; Object131's own layout is untouched.
class PmfQuad {
public:
	u8 _pad[0x9f0];
	void (Object131::*f0)();
	bool (Object131::*f1)(s32);
	u8 _pad1[8];
	bool (Object131::*f2)();
	u8 _pad2[0x38];
	void (Object131::*f3)();
};

// 0x02135eb4
extern "C" bool func_ov013_02135eb4(Object131 *self)
{
	PmfQuad *q = (PmfQuad *)self;

	if (self->sub._60 == 0) {
		func_ov013_02135e0c(self);
		self->sub._60++;
	} else if (self->sub._60 != -1) {
		// NOT onUpdate_8(): this mwccarm places a virtual's call offset 8 bytes below the
		// slot it occupies in _ZTV9Object131, so the target's `ldr r1,[r1,#0x7c]` - the slot
		// _ZTV9Object131 gives to onUpdate_8 - is what `_11()` compiles to here. _11 also
		// returns void, which is why the target discards the result.
		self->_11();
		if ((self->*q->f2)()) {
			return true;
		}
		(self->*q->f0)();
		if ((self->*q->f1)(1)) {
			return true;
		}
		self->updateVerticalVelocity();
		self->func_ov000_0209c85c();
		if (func_ov000_020a917c(&self->collisionMgr)) {
			*(s32 *)((u8 *)self + 0xd4) = 0;
		}
		if (func_01ffe778(&self->collisionMgr, 0, 0)) {
			*(s32 *)((u8 *)self + 0xd0) = 0;
		}
		(self->*q->f3)();
		if (self->sub._dc > 0) {
			if (func_ov013_02135080(self)) {
				func_ov013_0213775c(self, data_ov013_0213b970, 1);
				return true;
			}
		} else if (self->direction != self->func_ov000_0209acd4(&self->position)) {
			self->sub._dc = 10;
		}
		func_ov013_02130f68(self);
		s32 n = func_ov013_02135dd8(self);

		if (n == 1) {
			func_ov013_0213775c(self, data_ov013_0213b968, 1);
		} else if (n == 2) {
			self->sub._d4 = -1;
			self->sub._62 = 0;
			func_ov013_021371c0(self);
			func_ov013_0213775c(self, data_ov013_0213b960, 1);
		}
	}
	return true;
}

// 0x02135e0c
extern "C" void func_ov013_02135e0c(Object131 *self)
{
	self->sub._dc = 0;
	self->sub._d1 = 1;
	Tri3 t = data_ov013_0213b498;
	if (func_ov013_02135000(self) == 0) {
		*(s32 *)((u8 *)self + 0xd0) = -t.v[self->sub._68];
		*(s32 *)((u8 *)self + 0xd4) = 0;
		*(s32 *)((u8 *)self + 0xd8) = 0;
		func_ov013_021304bc(self);
	} else {
		*(s32 *)((u8 *)self + 0xd0) = t.v[self->sub._68];
		*(s32 *)((u8 *)self + 0xd4) = 0;
		*(s32 *)((u8 *)self + 0xd8) = 0;
		func_ov013_02130414(self);
	}
}

// 0x02130414
extern "C" void func_ov013_02130414(Object131 *self)
{
	Tri v;
	Tri t;

	v = *(Tri *)data_ov013_0213b3b4;
	t = *(Tri *)data_ov013_0213b3e4;
	self->blendModel.pushAnimation(v.v[self->sub._68], 0xa, 0, -t.v[self->sub._68],
		self->blendModel.frameController.getFrameCount() - 1);
}

// 0x02133f00
extern "C" bool func_ov013_02133f00(Object131 *self)
{
	if (self->sub._60 == 0) {
		self->blendModel.pushAnimation(0xd, 2, 0x40000000, 0x800, 0);
		*(s32 *)((u8 *)self + 0xd0) = 0;
		*(s32 *)((u8 *)self + 0xd4) = 0;
		*(s32 *)((u8 *)self + 0xd8) = 0;
		self->sub._d1 = 0;
		self->sub._b5 = 1;
		self->sub._60++;
	} else if (self->sub._60 != -1) {
		self->_11();
		if (self->blendModel.frameController.finished()) {
			func_ov013_0213775c(self, data_ov013_0213b8b8, 1);
		}
	}
	return true;
}

// 0x02137914
extern "C" void func_ov013_02137914(Object131 *self, PlayerBase *p)
{
	s32 d = *(s32 *)((u8 *)p + 0xd0);
	s32 v;

	if (d > 0) {
		self->sub._d0 = 1;
		*(s32 *)((u8 *)p + 0xb4) = -0x2b00;
		v = 0x6000;
	} else if (d < 0) {
		self->sub._d0 = 0;
		*(s32 *)((u8 *)p + 0xb4) = 0x2b00;
		v = 0x6000;
	} else {
		if (*(s32 *)((u8 *)p + 0x60) > *(s32 *)((u8 *)self + 0x60)) {
			self->sub._d0 = 0;
			*(s32 *)((u8 *)p + 0xb4) = 0x1b00;
		} else {
			self->sub._d0 = 1;
			*(s32 *)((u8 *)p + 0xb4) = -0x1b00;
		}
		v = 0x3000;
	}
	p->func_ov011_0212beb8(v, 0, 1, 1, 0);
}

// 0x02130e58
extern "C" void func_ov013_02130e58(Object131 *self)
{
	PlayerBase *p = (PlayerBase *)Game::getPlayer(0);
	Vec3_32 v1 = p->func_ov011_0212bbdc();
	Vec3_32 v2;
	s32 *q = (s32 *)((u8 *)p + 0x574);

	v2.x = q[0];
	v2.y = q[1];
	v2.z = q[2];
	if (v1.y - 0x10000 >= *(s32 *)((u8 *)self + 0xa74)) {
		func_020433f8(&self->sub._d2, -0x2000, 0x400);
	} else {
		func_020433f8(&self->sub._d2, 0, 0x400);
	}
}

// 0x02136aac
extern "C" bool func_ov013_02136aac(Object131 *self)
{
	if (self->sub._60 == 0) {
		*(s32 *)((u8 *)self + 0xd0) = 0;
		*(s32 *)((u8 *)self + 0xd4) = 0;
		*(s32 *)((u8 *)self + 0xd8) = 0;
		self->sub._d1 = 0;
		self->sub._60++;
	} else if (self->sub._60 != -1) {
		s32 n = *(u8 *)((u8 *)self + 0x33c) - 1;

		if (*(u64 *)data_0208af3c & ((u64)1 << n)) {
			self->sub._64 = 0;
			func_ov013_0213775c(self, data_ov013_0213b9b8, 1);
		}
	}
	return true;
}

// 0x0213170c
// The seven t0..t6 locals are what give this function its frame. A local is only given a
// frame slot once its live range crosses a later statement, so they are assigned in
// descending destination order and consumed after the direct copy that sits between the
// loads and the stores - that is what produces the target's 0x38 window per case, the
// load burst, and the 14 spill/reload pairs.
extern "C" void func_ov013_0213170c(Object131 *self)
{
	if (self->object_id == 0x83) {
		self->sub._68 = 0;
		self->sub._69 = 0;
		Pair8 t0, t1, t2, t3, t4, t5, t6;

		*(Pair8 *)&self->_pad9e0[8] = data_ov013_0213b958;
		*(Pair8 *)&self->_pad9e0[0x10] = data_ov013_0213b980;
		*(Pair8 *)&self->_pad9e0[0x18] = data_ov013_0213b9c0;
		t0 = data_ov013_0213b9c8;
		self->sub._e8 = 0;
		*(Pair8 *)&self->sub._0 = t0;
		*(Pair8 *)&self->sub._8 = data_ov013_0213b9e8;
		*(Pair8 *)&self->sub._10[0] = data_ov013_0213b9f8;
		*(Pair8 *)&self->sub._10[1] = data_ov013_0213ba20;
		t4 = data_ov013_0213b710;
		t3 = data_ov013_0213b990;
		t2 = data_ov013_0213b7d8;
		t1 = data_ov013_0213b7e0;
		*(Pair8 *)&self->sub._10[2] = data_ov013_0213ba48;
		*(Pair8 *)&self->sub._10[3] = t1;
		*(Pair8 *)&self->sub._10[4] = t2;
		*(Pair8 *)&self->sub._10[5] = t3;
		*(Pair8 *)&self->sub._10[6] = t4;
		t6 = data_ov013_0213b7b0;
		t5 = data_ov013_0213b7b8;
		*(Pair8 *)&self->sub._10[7] = data_ov013_0213b7c0;
		*(Pair8 *)&self->sub._10[8] = t5;
		*(Pair8 *)&self->sub._10[9] = t6;
	} else if (self->object_id == 0x84) {
		self->sub._68 = 1;
		self->sub._69 = 0;
		Pair8 t0, t1, t2, t3, t4, t5, t6;

		*(Pair8 *)&self->_pad9e0[8] = data_ov013_0213b7a8;
		*(Pair8 *)&self->_pad9e0[0x10] = data_ov013_0213b7a0;
		*(Pair8 *)&self->_pad9e0[0x18] = data_ov013_0213b928;
		t0 = data_ov013_0213b798;
		self->sub._e8 = 0;
		*(Pair8 *)&self->sub._0 = t0;
		*(Pair8 *)&self->sub._8 = data_ov013_0213b740;
		*(Pair8 *)&self->sub._10[0] = data_ov013_0213b908;
		*(Pair8 *)&self->sub._10[1] = data_ov013_0213b750;
		t4 = data_ov013_0213b8b0;
		t3 = data_ov013_0213ba60;
		t2 = data_ov013_0213b828;
		t1 = data_ov013_0213b8c8;
		*(Pair8 *)&self->sub._10[2] = data_ov013_0213b778;
		*(Pair8 *)&self->sub._10[3] = t1;
		*(Pair8 *)&self->sub._10[4] = t2;
		*(Pair8 *)&self->sub._10[5] = t3;
		*(Pair8 *)&self->sub._10[6] = t4;
		t6 = data_ov013_0213b888;
		t5 = data_ov013_0213b800;
		*(Pair8 *)&self->sub._10[7] = data_ov013_0213b8a8;
		*(Pair8 *)&self->sub._10[8] = t5;
		*(Pair8 *)&self->sub._10[9] = t6;
	} else if (self->object_id == 0x85) {
		self->sub._68 = 2;
		self->sub._69 = 1;
		Pair8 t0, t1, t2, t3, t4, t5, t6;

		*(Pair8 *)&self->_pad9e0[8] = data_ov013_0213b818;
		*(Pair8 *)&self->_pad9e0[0x10] = data_ov013_0213b820;
		*(Pair8 *)&self->_pad9e0[0x18] = data_ov013_0213b840;
		t0 = data_ov013_0213ba58;
		self->sub._e8 = 1;
		*(Pair8 *)&self->sub._0 = t0;
		*(Pair8 *)&self->sub._8 = data_ov013_0213b8d8;
		*(Pair8 *)&self->sub._10[0] = data_ov013_0213ba00;
		*(Pair8 *)&self->sub._10[1] = data_ov013_0213b988;
		t4 = data_ov013_0213b7d0;
		t3 = data_ov013_0213b700;
		t2 = data_ov013_0213ba50;
		t1 = data_ov013_0213ba08;
		*(Pair8 *)&self->sub._10[2] = data_ov013_0213b9d0;
		*(Pair8 *)&self->sub._10[3] = t1;
		*(Pair8 *)&self->sub._10[4] = t2;
		*(Pair8 *)&self->sub._10[5] = t3;
		*(Pair8 *)&self->sub._10[6] = t4;
		t6 = data_ov013_0213b738;
		t5 = data_ov013_0213b728;
		*(Pair8 *)&self->sub._10[7] = data_ov013_0213b718;
		*(Pair8 *)&self->sub._10[8] = t5;
		*(Pair8 *)&self->sub._10[9] = t6;
	}
}

void *Object132::create()
{
	return new Object131();
}

void *Object133::create()
{
	return new Object131();
}

// 0x0213ba78
ActorProfile Object131_Profile = { Object131::create, 131, 149, NULL /* TODO: 0x021387f4 */ };

// 0x0213ba84
ActorProfile Object132_Profile = { Object132::create, 132, 150, NULL /* TODO: 0x0213875c */ };

// 0x0213ba90
ActorProfile Object133_Profile = { Object133::create, 133, 151, NULL /* TODO: 0x02138724 */ };
