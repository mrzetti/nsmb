#include "Object214.hpp"

extern "C" {

// ---- helpers living in other translation units ----
void *func_ov010_020fa77c(u32 bank);
void func_ov000_020af30c(u32 a, u16 b, u16 c, u32 d, u32 e);
void func_0204c0ac(void *a);
void func_0201c0f4(void *a);
void func_0201be64(void *a);
void func_0201c080(void *a);
void func_0201c01c(void *a);
void func_0201bd60(RotatingPlatform *, StageActor *, u32, u32, u32, u32, u32, u32, u32, Vec3_32 *);

void *__cxa_vec_new(u32 count, u32 size, u32 align, void (*ctor)(void *), void (*dtor)(void *));
void __cxa_vec_delete(void *p, u32 size, u32 align, void (*dtor)(void *));
void __cxa_vec_ctor(void *base, u32 count, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void __cxa_vec_cleanup(void *base, u32 count, u32 size);

// ---- this unit ----
void func_ov109_02189a38(Vec2_32 *);
void func_ov109_02189aac(Vec2_32 *);
void func_ov109_02189b20(Object214 *);
void func_ov109_02189b84(Object214 *);
void func_ov109_02189b90(Object214 *);
void func_ov109_02189c28(Object214 *);
void func_ov109_02189ec4(Object214 *, s8);
void func_ov109_02189f60(Object214 *);
void func_ov109_0218a03c(Object214 *);
void func_ov109_0218a0d8(Object214 *);
void func_ov109_0218a1e0(Object214 *);
void func_ov109_0218a340(Object214 *);
void func_ov109_0218a3ec(Object214 *);
s32 func_ov109_0218a534(Object214 *);
s32 func_ov109_0218a70c(Object214 *);
void func_ov109_0218a9c8(Object214 *);
void func_ov109_0218ac40(Object214Node *);
Object214Node *func_ov109_0218ac8c(Object214Node *);
void func_ov109_0218accc(Object214 *);
void func_ov109_0218ae20(Object214 *);
bool func_ov109_0218afe8(Object214 *);
void func_ov109_0218b01c(Object214 *);
void func_ov109_0218b118(Object214 *);
void func_ov109_0218b194(Object214 *);
void func_ov109_0218b224(Object214 *);
void func_ov109_0218b3cc(Object214 *);
void func_ov109_0218b43c(Object214 *);
bool func_ov109_0218b524(Object214 *);
void func_ov109_0218b550(Object214 *);
bool func_ov109_0218b5d8(Object214 *, u32);
void func_ov109_0218b628(Object214 *, Object214VoidFn, u32);
void func_ov109_0218b6ec(Object214 *, Object214Player *);
void func_ov109_0218b764(Object214 *, Object214Player *);
bool func_ov109_0218b7e0();
Object214 *func_ov109_0218ba40(Object214 *);
void func_ov109_0218bac0(Object214Node *);
void func_ov109_0218bb64(Object214Node *);
void func_ov109_0218bc8c(Object214Node *);
void func_ov109_0218bd98(Object214Node *);
void func_ov109_0218be3c(Object214Node *);
void func_ov109_0218bf5c(Object214Node *);
void func_ov109_0218c040(Object214Node *);
void func_ov109_0218c050(Object214Link *);
void func_ov109_0218c0e4(Object214Link *);
void func_ov109_0218c1dc(Object214Link *);
void func_ov109_0218c2b4(Object214Link *);
s32 func_ov109_0218c2e4(Object214Link *);
void func_ov109_0218c458(Object214Link *);
void func_ov109_0218c464(Object214Link *, Object214 *, Vec3_32 *, u16, s32 *, s32 *);
void func_ov109_0218c4d0(Object214Link *);
Object214Link *func_ov109_0218c514(Object214Link *);

// ---- data ----
extern char _ZTV7Vec2_32[];
extern char _ZTV7Vec3_32[];
extern char _ZTV9Object214[];
extern char _ZTV16RotatingPlatform[];

extern u32 data_ov000_020cad40;
extern s8 data_ov109_0218c7a0;
extern s32 data_ov109_0218c584[2];
extern s32 data_ov109_0218c58c[];
extern s32 data_ov109_0218c5a0[];
extern Object214PathPoint *data_0208b168[16];
extern Collider **data_ov109_0218c644;
extern Collider **data_ov109_0218c660;

extern Object214VoidFn data_ov109_0218c5c0;
extern Object214VoidFn data_ov109_0218c5c8;
extern Object214VoidFn data_ov109_0218c5d0;
extern Object214VoidFn data_ov109_0218c5d8;
extern Object214VoidFn data_ov109_0218c5e0;
extern Object214VoidFn data_ov109_0218c5e8;
extern Object214VoidFn data_ov109_0218c5f0;
extern Object214VoidFn data_ov109_0218c5f8;
extern Object214VoidFn data_ov109_0218c600;
extern Object214VoidFn data_ov109_0218c608;
extern Object214VoidFn data_ov109_0218c610;
extern Object214VoidFn data_ov109_0218c618;
extern Object214VoidFn data_ov109_0218c620;
extern Object214VoidFn data_ov109_0218c628;
extern Object214VoidFn data_ov109_0218c630;

}

// Experiment: can a declared class reproduce dsd's `PlayerActor::func_ov010_02102108`?
class PlayerActor {
public:
	void func_ov010_02102108();
};

static inline Object214Link *linkAt(Object214 *self, u32 i)
{
	return (Object214Link *)(self->link + i * 0xa8);
}

// ============================== Object214Link ==============================

extern "C" Object214Link *func_ov109_0218c514(Object214Link *self)
{
	*(void **)&self->v0 = (void *)&_ZTV7Vec3_32[8];
	*(void **)&self->v1 = (void *)&_ZTV7Vec3_32[8];
	*(void **)&self->v2 = (void *)&_ZTV7Vec2_32[8];
	if (self->owner == 0)
		self->owner = 0;
	return self;
}

extern "C" void func_ov109_0218c4d0(Object214Link *self)
{
	if (self->owner == 0)
		self->owner = 0;
	self->collider.~Collider();
	*(void **)&self->v2 = (void *)&_ZTV7Vec2_32[8];
	*(void **)&self->v1 = (void *)&_ZTV7Vec3_32[8];
	*(void **)&self->v0 = (void *)&_ZTV7Vec3_32[8];
}

extern "C" void func_ov109_0218c464(Object214Link *self, Object214 *owner, Vec3_32 *v, u16 count, s32 *a, s32 *b)
{
	self->v0.x = v->x;
	self->v0.y = v->y;
	self->v0.z = v->z;
	self->v1.x = v->x;
	self->v1.y = v->y;
	self->v1.z = v->z;
	self->v2.x = v->x;
	self->v2.y = v->y;
	if (self->owner == 0)
		self->owner = (Object214 *)*b;
	self->f34 = count;
	self->f2c = *a;
	self->f30 = *b;
}

extern "C" void func_ov109_0218c2b4(Object214Link *self)
{
	if (self->owner == 0)
		return;
	if (self->owner->linkIdx == 0)
		self->f34++;
	else
		self->f34--;
}

extern "C" void func_ov109_0218c050(Object214Link *self)
{
	if (self->owner == 0)
		return;
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	self->owner->position = self->v0;
	self->collider.unlink();
	self->owner->position = s0;
}

extern "C" void func_ov109_0218c0e4(Object214Link *self)
{
	if (self->owner == 0)
		return;
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1 = *(Vec3_32 *)((u8 *)self->owner + 0x6c);
	self->owner->position = self->v0;
	self->owner->lastPosition = self->v1;
	self->collider.updatePosition();
	self->owner->position = s0;
	self->owner->lastPosition = s1;
}

extern "C" void func_ov109_0218c1dc(Object214Link *self)
{
	if (self->owner == 0)
		return;
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 v;
	self->owner->position = self->v0;
	v = Vec3_32(0x1000);
	self->collider.init(self->owner, data_ov109_0218c644, 0, 0, (u32)(void *)&v);
	self->fA3 = 4;
	self->collider.link();
	self->owner->position = s0;
}

extern "C" s32 func_ov109_0218c2e4(Object214Link *self)
{
	s8 t;
	s32 d;

	if (self->owner->buf == 0)
		return 0;
	t = self->owner->buf[self->f34];
	if (t == 0)
		return 0;

	self->v1.x = self->v0.x;
	self->v1.y = self->v0.y;
	self->v1.z = self->v0.z;
	if (self->owner->linkIdx == 0) {
		self->v0.x += self->owner->f418 * data_ov109_0218c58c[t];
		self->v0.y += self->owner->f418 * data_ov109_0218c5a0[t];
	} else {
		self->v0.x -= self->owner->f418 * data_ov109_0218c58c[t];
		self->v0.y -= self->owner->f418 * data_ov109_0218c5a0[t];
	}

	if ((u8)(t - 3) <= 1)
		d = self->v0.x - self->v2.x;
	else
		d = self->v0.y - self->v2.y;
	if (d < 0)
		d = -d;
	if (d < 0x10000)
		return 0;

	if (self == linkAt(self->owner, self->owner->linkIdx)) {
		func_02012398(0x85, (Vec3_32 *)self);
		func_ov109_0218a03c(self->owner);
		func_ov109_02189f60(self->owner);
	}
	func_ov109_0218c2b4(self);
	self->v2.x = self->v0.x;
	self->v2.y = self->v0.y;
	return 1;
}

// ============================== Object214Node ==============================

extern "C" Object214Node *func_ov109_0218ac8c(Object214Node *self)
{
	*(void **)&self->v0 = (void *)&_ZTV7Vec2_32[8];
	*(void **)&self->v1 = (void *)&_ZTV7Vec2_32[8];
	*(void **)&self->v2 = (void *)&_ZTV7Vec2_32[8];
	func_0201be64(&self->platform);
	self->active = 0;
	self->owner = 0;
	return self;
}

extern "C" void func_ov109_0218ac40(Object214Node *self)
{
	func_ov109_0218bd98(self);
	*(void **)&self->platform = (void *)&_ZTV16RotatingPlatform[8];
	*(void **)((u8 *)&self->platform + 0x58) = (void *)&_ZTV7Vec2_32[8];
	func_0201c0f4(&self->platform);
	self->collider.~Collider();
	*(void **)&self->v2 = (void *)&_ZTV7Vec2_32[8];
	*(void **)&self->v1 = (void *)&_ZTV7Vec2_32[8];
	*(void **)&self->v0 = (void *)&_ZTV7Vec2_32[8];
}

extern "C" void func_ov109_0218bd98(Object214Node *self)
{
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1(self->v0.x, self->v0.y, 0);
	self->owner->position = s1;
	self->collider.unlink();
	self->owner->position = s0;
}

extern "C" void func_ov109_0218be3c(Object214Node *self)
{
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1 = *(Vec3_32 *)((u8 *)self->owner + 0x6c);
	Vec3_32 s2(self->v0.x, self->v0.y, 0);
	Vec3_32 s3(self->v1.x, self->v1.y, 0);
	self->owner->position = s2;
	self->owner->lastPosition = s3;
	self->collider.updatePosition();
	self->owner->position = s0;
	self->owner->lastPosition = s1;
}

extern "C" void func_ov109_0218bf5c(Object214Node *self)
{
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1(self->v0.x, self->v0.y, 0);
	Vec3_32 v;
	self->owner->position = s1;
	v = Vec3_32(0x1000);
	self->collider.init(self->owner, data_ov109_0218c660, 0, 0, (u32)(void *)&v);
	self->f97 = 4;
	self->collider.link();
	self->owner->position = s0;
}

extern "C" void func_ov109_0218c040(Object214Node *self)
{
	func_ov109_02189aac(&self->v0);
}

extern "C" void func_ov109_0218bac0(Object214Node *self)
{
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1(self->v0.x, self->v0.y, 0);
	self->owner->position = s1;
	func_0201c01c(&self->platform);
	self->owner->position = s0;
}

extern "C" void func_ov109_0218bb64(Object214Node *self)
{
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1 = *(Vec3_32 *)((u8 *)self->owner + 0x6c);
	Vec3_32 s2(self->v0.x, self->v0.y, 0);
	Vec3_32 s3(self->v1.x, self->v1.y, 0);
	self->owner->position = s2;
	self->owner->lastPosition = s3;
	self->platform.update();
	self->owner->position = s0;
	self->owner->lastPosition = s1;
}

extern "C" void func_ov109_0218bc8c(Object214Node *self)
{
	Vec3_32 s0 = *(Vec3_32 *)((u8 *)self->owner + 0x5c);
	Vec3_32 s1(self->v0.x, self->v0.y, 0);
	Vec3_32 v;
	self->owner->position = s1;
	v = Vec3_32(0x1000);
	func_0201bd60(&self->platform, (StageActor *)self, 0x8000, 0, 0, 0x8000, -0x8000, 0, 0, &v);
	self->platform.unk51 = 1;
	self->platform.flags &= ~0x40;
	self->platform.flags |= 0x2000;
	func_0201c080(&self->platform);
	self->owner->position = s0;
}

// ============================== Object214 ==============================

extern "C" bool func_ov109_0218b7e0()
{
	return true;
}

extern "C" Object214 *func_ov109_0218ba40(Object214 *self)
{
	*(void **)self = (void *)&_ZTV9Object214[8];
	func_0201be64(&self->platform);
	__cxa_vec_ctor(self->link, 2, 0xa8, (void (*)(void *))func_ov109_0218c514,
	               (void (*)(void *))func_ov109_0218c4d0);
	self->buf = 0;
	self->pts = 0;
	self->nodes = 0;
	data_ov109_0218c7a0++;
	return self;
}

extern "C" void func_ov109_02189a38(Vec2_32 *p)
{
	Vec2_32 v;

	v = Vec2_32(0x1000);
	drawSprite(data_ov011_0212f180[0xe], p->x + 0x8000, p->y - 0x8000, 0x10, 0, 0, &v, 0, 0, 0);
}

extern "C" void func_ov109_02189aac(Vec2_32 *p)
{
	Vec2_32 v;

	v = Vec2_32(0x1000);
	drawSprite(data_ov011_0212f180[0xe], p->x + 0x8000, p->y - 0x8000, 0x10, 0, 0, &v, 0, 0, 0);
}

extern "C" void func_ov109_0218c458(Object214Link *self)
{
	func_ov109_02189a38((Vec2_32 *)self);
}

extern "C" void func_ov109_02189b90(Object214 *self)
{
	func_ov109_0218c458(linkAt(self, 0));
	func_ov109_0218c458(linkAt(self, 1));
}

extern "C" void func_ov109_02189b84(Object214 *self)
{
	func_ov109_02189b20(self);
}

extern "C" void func_ov109_02189b20(Object214 *self)
{
	s32 i;

	for (i = 0; i < (s32)self->count + 2; i++) {
		bool b = self->nodes[i].active == 1;
		if (b)
			func_ov109_0218c040(&self->nodes[i]);
	}
}

extern "C" void func_ov109_02189ec4(Object214 *self, s8 a)
{
	s32 i;
	s32 n;

	if (self->count == 0)
		return;
	if (self->pts == 0)
		return;
	n = (s32)self->count + 2;
	for (i = 0; i < n; i++)
		func_ov000_020af30c(data_ov000_020cad40, self->pts[i].x >> 0xc, -(self->pts[i].y >> 0xc), 0xd, 0);
}

extern "C" void func_ov109_02189f60(Object214 *self)
{
	s32 i;
	s32 n;

	if (self->count == 0)
		return;
	if (self->pts == 0)
		return;
	n = (s32)self->count + 1;
	func_ov000_020af30c(data_ov000_020cad40, self->pts[n].x >> 0xc, -(self->pts[n].y >> 0xc), 0, 0);
	for (i = 0; i < n; i++)
		func_ov000_020af30c(data_ov000_020cad40, self->pts[i].x >> 0xc, -(self->pts[i].y >> 0xc), 0xd, 0);
}

extern "C" void func_ov109_0218a03c(Object214 *self)
{
	s32 i;
	s32 n = self->count;

	if (n == 0)
		return;
	if (self->pts == 0)
		return;
	for (i = 0; i < n + 1; i++) {
		self->pts[n + 1 - i].x = self->pts[n - i].x;
		self->pts[n + 1 - i].y = self->pts[n - i].y;
	}
	self->pts->x = linkAt(self, self->linkIdx)->v0.x;
	self->pts->y = linkAt(self, self->linkIdx)->v0.y;
}

extern "C" void func_ov109_0218a0d8(Object214 *self)
{
	s32 i;
	s32 n;
	s32 x;
	s32 y;

	if (self->count == 0)
		return;
	self->pts = new Vec2_32[self->count + 2];
	if (self->linkIdx == 0) {
		n = self->count + 1;
		x = linkAt(self, 0)->v0.x;
		y = linkAt(self, 0)->v0.y;
		for (i = 0; i < n; i++) {
			self->pts[i].x = x;
			self->pts[i].y = y;
			x -= 0x10000;
		}
	} else {
		n = self->count + 1;
		x = linkAt(self, 1)->v0.x;
		y = linkAt(self, 1)->v0.y;
		for (i = 0; i < n; i++) {
			self->pts[i].x = x;
			self->pts[i].y = y;
			x += 0x10000;
		}
	}
}

extern "C" void func_ov109_0218a1e0(Object214 *self)
{
	Vec3_32 v0;
	Vec3_32 v1;
	Vec3_32 v2;
	s32 a;
	s32 b;
	u32 idx;
	s32 px;
	s32 py;
	u8 *bank;

	bank = (u8 *)func_ov010_020fa77c((self->settings >> 4) & 0xf);
	idx = bank[4];
	px = data_0208b168[0xb][(self->settings >> 16) & 0xff].a >> 12 << 12;
	py = -data_0208b168[0xb][(self->settings >> 16) & 0xff].b >> 12 << 12;
	v0 = Vec3_32(px, py, self->position.z);
	v1 = Vec3_32(px + ((self->count + 1) << 16), py, self->position.z);
	v2 = Vec3_32(px, py, self->position.z);
	a = self->count + 2;
	b = self->bufLen;
	func_ov109_0218c464(linkAt(self, 0), self, &v1, (u16)(self->count + 2), &a, &b);
	a = 1;
	b = self->bufLen - (self->count + 1);
	func_ov109_0218c464(linkAt(self, 1), self, &v2, 1, &a, &b);
	func_ov109_0218c1dc(linkAt(self, 0));
	func_ov109_0218c1dc(linkAt(self, 1));
}

extern "C" void func_ov109_0218a3ec(Object214 *self)
{
	s32 tbl[2];

	tbl[0] = data_ov109_0218c584[0];
	tbl[1] = data_ov109_0218c584[1];
	self->f418 = tbl[(self->settings >> 24) & 1];
}

extern "C" void func_ov109_0218a340(Object214 *self)
{
	Object214VoidFn tbl[5];

	tbl[0] = data_ov109_0218c5d8;
	tbl[1] = data_ov109_0218c5f8;
	tbl[2] = data_ov109_0218c628;
	tbl[3] = data_ov109_0218c5c0;
	tbl[4] = data_ov109_0218c5e8;
	self->f40c = tbl[(self->settings >> 28) & 7];
}

extern "C" void func_ov109_02189c28(Object214 *self)
{
	Object214PathPoint *tbl;
	u8 *bank;
	s32 total;
	s32 i;
	s32 j;
	s32 pos;
	s32 x0;
	s32 y0;
	s32 x1;
	s32 y1;
	s32 dx;
	s32 dy;
	s32 dir;
	u8 c;

	bank = (u8 *)func_ov010_020fa77c((self->settings >> 4) & 0xf);
	tbl = data_0208b168[0xb];
	total = 0;
	for (i = 0; (u32)i < ((self->settings >> 16) & 0xff); i++) {
		dx = tbl[i + 1].a >> 4;
		dx -= tbl[i].a >> 4;
		if (dx < 0)
			dx = -dx;
		dy = tbl[i + 2].b >> 4;
		dy -= tbl[i + 1].b >> 4;
		if (dy < 0)
			dy = -dy;
		total += dx + dy;
	}
	self->bufLen = total;
	self->buf = new s8[total + 2];
	pos = 0;
	for (i = 0; i < (s32)(((u16 *)bank)[2] - 1); i++) {
		x0 = tbl[i].a >> 4;
		x1 = tbl[i + 1].a >> 4;
		y0 = tbl[i].b >> 4;
		y1 = tbl[i + 1].b >> 4;
		dx = x1 - x0;
		dy = y1 - y0;
		if (dx < 0)
			dx = -dx;
		if (dy < 0)
			dy = -dy;
		if (dx > dy) {
			c = 4;
			if (dy > 0)
				c = 3;
		} else if (dy > 0) {
			c = 1;
		} else {
			c = 2;
		}
		if (dx > dy) {
			for (j = 0; j < dx; j++) {
				self->buf[pos] = c;
				self->buf[pos + 1] = 2;
				pos += 2;
			}
			for (j = 0; j < dx - dy; j++) {
				self->buf[pos] = 2;
				pos++;
			}
		} else {
			for (j = 0; j < dy; j++) {
				self->buf[pos] = c;
				self->buf[pos + 1] = 2;
				pos += 2;
			}
			for (j = 0; j < dy - dx; j++) {
				self->buf[pos] = c;
				pos++;
			}
		}
	}
	self->buf[0] = 0;
	self->buf[total + 1] = 0;
}

extern "C" s32 func_ov109_0218a534(Object214 *self)
{
	s32 i;
	Object214Node *n;
	bool b;

	if (self->state == 0) {
		self->f40a = 0;
		self->state = self->state + 1;
	} else if (self->state != -1) {
		b = self->nodes[self->count + 1].f28 < 0;
		if (b) {
			self->collisionType |= 0x2000;
			return 1;
		}
		self->f40b = self->buf[0xb] + 1;
		self->f40b = self->buf[0xb] & 7;
		if (self->buf[0xb] == 0) {
			if (self->buf[0xa] < self->count + 1)
				self->f40a = self->buf[0xa] + 1;
		}
		n = self->nodes;
		for (i = 0; i < (s32)self->count + 2; i++, n++) {
			b = n->active == 1;
			if (b) {
				n->f28--;
				b = n->f28 < 0;
				if (b) {
					func_ov109_0218bd98(n);
					n->active = 0;
				} else {
					if (i <= self->buf[0xa]) {
						n->v2.y += 0x300;
						if (n->v2.y > 0x4000)
							n->v2.y = 0x4000;
						n->v0.x += n->v2.x;
						n->v0.y -= n->v2.y;
						n->f28--;
					}
					func_ov109_0218be3c(n);
					n->v1.x = n->v0.x;
					n->v1.y = n->v0.y;
				}
			}
		}
	}
}

extern "C" s32 func_ov109_0218a70c(Object214 *self)
{
	s32 i;
	s32 k;

	if (self->state == 0) {
		self->f40a = 0;
		self->f40a = -1;
		self->f40b = -1;
		self->state = self->state + 1;
	} else if (self->state != -1) {
		if (self->nodes[self->count + 1].f28 < 0) {
			self->collisionType |= 0x2000;
			return 1;
		}
		if (self->buf[0xa] < (s8)self->count + 1) {
			self->f40b = self->buf[0xb] + 1;
			self->f40b = self->buf[0xb] & 7;
			if (self->buf[0xb] == 0) {
				if (self->buf[0xa] < self->count + 1)
					self->f40a = self->buf[0xa] + 1;
			}
			func_ov109_0218bd98(&self->nodes[self->buf[0xa]]);
			func_ov109_0218bc8c(&self->nodes[self->buf[0xa]]);
		}
		k = self->bufLen;
		for (i = 0; i < (s32)self->count + 2; i++) {
			if (self->nodes[i].active == 1) {
				self->nodes[i].f28--;
				if (self->nodes[i].f28 < 0) {
					func_ov109_0218bac0(&self->nodes[i]);
					self->nodes[i].active = 0;
				} else {
					if (i <= self->buf[0xa]) {
						s8 t = self->buf[self->bufLen];
						if ((u8)(t - 1) <= 1)
							self->nodes[i].v2.x = 0x800;
						self->nodes[i].v2.y += 0x300;
						if (self->nodes[i].v2.y > 0x4000)
							self->nodes[i].v2.y = 0x4000;
						self->nodes[i].v0.x += self->nodes[i].v2.x;
						self->nodes[i].v0.y -= self->nodes[i].v2.y;
						self->nodes[i].f28--;
						func_ov109_0218bb64(&self->nodes[i]);
					} else {
						s8 t = self->buf[k];
						Vec2_32 v;
						k--;
						v = Vec2_32(data_ov109_0218c58c[t] << 13, data_ov109_0218c5a0[t] << 13);
						self->nodes[i].v0.x += v.x;
						self->nodes[i].v0.y += v.y;
						func_ov109_0218be3c(&self->nodes[i]);
					}
					self->nodes[i].v1.x = self->nodes[i].v0.x;
					self->nodes[i].v1.y = self->nodes[i].v0.y;
				}
			}
		}
	}
}

extern "C" void func_ov109_0218a9c8(Object214 *self)
{
	s32 i;
	Object214Node *n;

	if (self->count == 0)
		return;
	self->nodes = (Object214Node *)__cxa_vec_new(self->count + 2, 0x10c, 8,
	                                            (void (*)(void *))func_ov109_0218ac8c,
	                                            (void (*)(void *))func_ov109_0218ac40);
	n = &self->nodes[0];
	n->v0.x = linkAt(self, 0)->v0.x;
	n->v0.y = linkAt(self, 0)->v0.y;
	n->v1.x = n->v0.x;
	n->v1.y = n->v0.y;
	n->v2.set(0);
	n->f28 = 0xf0;
	if (n->owner == 0)
		n->owner = self;
	func_ov109_0218bf5c(n);
	n->active = 1;
	n = &self->nodes[1];
	n->v0.x = linkAt(self, 1)->v0.x;
	n->v0.y = linkAt(self, 1)->v0.y;
	n->v1.x = n->v0.x;
	n->v1.y = n->v0.y;
	n->v2.set(0);
	n->f28 = 0xf0;
	if (n->owner == 0)
		n->owner = self;
	func_ov109_0218bf5c(n);
	n->active = 1;
	for (i = 0; i < (s32)self->count; i++) {
		n = &self->nodes[i + 1];
		n->v0.x = self->pts[i].x;
		n->v0.y = self->pts[i].y;
		n->v1.x = n->v0.x;
		n->v1.y = n->v0.y;
		n->v2.set(0);
		n->f28 = 0xf0;
		if (n->owner == 0)
			n->owner = self;
		func_ov109_0218bf5c(n);
		n->active = 1;
	}
}

extern "C" void func_ov109_0218accc(Object214 *self)
{
	s32 i;

	if (self->buf[0x94] == 0) {
		self->velocity.set(0);
		self->minVelocity.x = 0;
		self->minVelocity.y = -0x2000;
		self->minVelocity.z = 0;
		self->accelV = -0x300;
		self->f3fc = 0x168;
		self->state = 1;
	} else if (self->buf[0x94] != -1) {
		self->f3fc--;
		if ((s16)self->f3fc < 0) {
			self->collisionType |= 0x2000;
			return;
		}
		self->updateVerticalVelocity();
		for (i = 0; i < (s32)self->count + 2; i++) {
			self->nodes[i].v0.x += self->velocity.x;
			self->nodes[i].v0.y += -self->velocity.y;
			func_ov109_0218be3c(&self->nodes[i]);
			self->nodes[i].v1.x = self->nodes[i].v0.x;
			self->nodes[i].v1.y = self->nodes[i].v0.y;
		}
	}
}

extern "C" void func_ov109_0218ae20(Object214 *self)
{
	s32 i;

	if (self->state == 0) {
		self->velocity.set(0x1000, 0, 0);
		self->minVelocity.x = 0;
		self->f3fc = 0x30;
		self->state = 1;
	} else if (self->state != -1) {
		self->f3fc--;
		if ((s16)self->f3fc < 0) {
			if (self->buf[9] == 1) {
				func_ov109_0218b628(self, data_ov109_0218c5f0, 1);
			} else if (self->buf[9] == 2) {
				func_ov109_0218b628(self, data_ov109_0218c5d0, 1);
			} else if (self->buf[9] == 0) {
				func_ov109_0218b628(self, data_ov109_0218c630, 1);
			}
			return;
		}
		if ((s16)self->f3fc & 1)
			self->velocity.x = -self->velocity.x;
		for (i = 0; i < (s32)self->count + 2; i++) {
			self->nodes[i].v0.x += self->velocity.x;
			self->nodes[i].v0.y += self->velocity.y;
			func_ov109_0218be3c(&self->nodes[i]);
			self->nodes[i].v1.x = self->nodes[i].v0.x;
			self->nodes[i].v1.y = self->nodes[i].v0.y;
		}
	}
}

extern "C" bool func_ov109_0218afe8(Object214 *self)
{
	Platform *p = self->platform.manager->head;

	while (p != 0) {
		if (p->owner->actorType == 1)
			return true;
		p = p->next;
	}
	return false;
}

extern "C" void func_ov109_0218b01c(Object214 *self)
{
	Vec3_32 v0;
	Vec3_32 v1;
	Vec3_32 v2;
	s32 d;

	v0 = linkAt(self, 0)->v0;
	v1 = linkAt(self, 1)->v0;
	d = v0.x + 0x10000 - v1.x;
	if (d < 0)
		d = -d;
	v2 = Vec3_32(v1.x + (d >> 1), v1.y + 0x2000, v0.z);
	self->position.x = v2.x;
	self->position.y = v2.y;
	self->position.z = v2.z;
	func_0201bd60(&self->platform, (StageActor *)self, 0, 0, 0, d >> 1, -(d >> 1), 0, 0, 0);
	func_0201c080(&self->platform);
}

extern "C" void func_ov109_0218b118(Object214 *self)
{
	if (self->state == 0) {
		func_ov109_0218b01c(self);
		self->state = self->state + 1;
	} else if (self->state == -1) {
		func_0201c01c(&self->platform);
	} else {
		if (func_ov109_0218afe8(self))
			func_ov109_0218b628(self, data_ov109_0218c600, 0);
	}
}

extern "C" void func_ov109_0218b194(Object214 *self)
{
	func_ov109_02189ec4(self, self->f408);
	self->f408 = 0;
	func_ov109_0218a9c8(self);
	func_ov109_0218c050(linkAt(self, 0));
	func_ov109_0218c050(linkAt(self, 1));
	if (((self->settings >> 28) & 7) == 1)
		self->f409 = 1;
	else if (((self->settings >> 28) & 7) == 4)
		self->f409 = 2;
	self->f498 = data_ov109_0218c610;
	func_ov109_0218b628(self, data_ov109_0218c608, 1);
}

extern "C" void func_ov109_0218b224(Object214 *self)
{
	Vec3_32 v0;
	Vec3_32 v1;
	s32 i;
	s32 j;
	s32 tx;
	s32 ty;

	self->linkIdx ^= 1;
	func_ov109_02189ec4(self, self->f408);
	for (i = 0; i < 2; i++) {
		if (self->linkIdx != 0)
			((u16 *)self->buf)[0x6a] = (u16)linkAt(self, i)->f30;
		else
			((u16 *)self->buf)[0x6a] = (u16)linkAt(self, i)->f2c;
	}
	if (self->count == 0)
		return;
	if (self->pts == 0)
		return;
	for (i = 0; i < (s32)(self->count / 2); i++) {
		j = self->count - i;
		tx = self->pts[i + 1].x;
		ty = self->pts[i + 1].y;
		self->pts[i + 1].x = self->pts[j].x;
		self->pts[i + 1].y = self->pts[j].y;
		self->pts[j].x = tx;
		self->pts[j].y = ty;
	}
	v0 = linkAt(self, self->linkIdx)->v0;
	v1 = linkAt(self, (self->linkIdx + 1) & 1)->v0;
	self->pts[0].x = v0.x;
	self->pts[0].y = v0.y;
	self->pts[self->count + 1].x = v1.x;
	self->pts[self->count + 1].y = v1.y;
	func_ov109_02189f60(self);
}

extern "C" void func_ov109_0218b3cc(Object214 *self)
{
	func_ov109_02189ec4(self, self->f408);
	self->f408 = 0;
	func_ov109_0218a9c8(self);
	func_ov109_0218c050(linkAt(self, 0));
	func_ov109_0218c050(linkAt(self, 1));
	self->f409 = 0;
	self->f498 = data_ov109_0218c5c8;
	func_ov109_0218b628(self, data_ov109_0218c618, 1);
}

extern "C" void func_ov109_0218b43c(Object214 *self)
{
	Vec3_32 v0;
	Vec3_32 v1;

	v0 = linkAt(self, 0)->v0;
	v1 = linkAt(self, 1)->v0;
	func_ov000_020af30c(data_ov000_020cad40, v0.x >> 0xc, -(v0.y >> 0xc), 0xd, 0);
	func_ov000_020af30c(data_ov000_020cad40, v1.x >> 0xc, -(v1.y >> 0xc), 0xd, 0);
	self->f408 = 0;
	self->collisionType |= 0x2000;
}

extern "C" bool func_ov109_0218b524(Object214 *self)
{
	return self->buf[linkAt(self, self->linkIdx)->f34] == 0;
}

extern "C" void func_ov109_0218b550(Object214 *self)
{
	if (self->state == 0) {
		self->state = self->state + 1;
	} else if (self->state != -1) {
		if (func_ov109_0218b524(self)) {
			(self->*self->f40c)(0);
		} else {
			func_ov109_0218c2e4(linkAt(self, 0));
			func_ov109_0218c2e4(linkAt(self, 1));
		}
	}
}

extern "C" bool func_ov109_0218b5d8(Object214 *self, u32 arg)
{
	if (*(u32 *)&self->f48c == 0)
		return true;
	(self->*self->f48c)(arg);
}

extern "C" void func_ov109_0218b628(Object214 *self, Object214VoidFn f, u32 arg)
{
	if (*(u32 *)&self->f48c != 0) {
		self->state = -1;
		(self->*self->f48c)(arg);
	}
	self->f48c = f;
	self->state = 0;
	if (*(u32 *)&f != 0)
		(self->*self->f48c)(arg);
}

extern "C" void func_ov109_0218b6ec(Object214 *self, Object214Player *p)
{
	s8 t;

	if (p->f0c != 0x15)
		return;
	t = self->buf[linkAt(self, 0)->f34];
	if (t == 4) {
		if (p->f60 >= linkAt(self, 0)->v0.x + 0x8000)
			p->f9c4 |= 8;
	} else if (t == 3) {
		if (p->f60 <= linkAt(self, 0)->v0.x - 0x8000)
			p->f9c4 |= 4;
	}
}

extern "C" void func_ov109_0218b764(Object214 *self, Object214Player *p)
{
	if (p->f0c != 0x15)
		return;
	if (self->buf[((u16 *)self->buf)[0x6a]] != 1)
		return;
	if (p->f7ac != 3)
		return;
	if (!(p->f78c & 2))
		return;
	((PlayerActor *)p)->func_ov010_02102108();
}

// ============================== members ==============================

Object214::~Object214()
{
	if (buf) {
		func_0204c0ac(buf);
		buf = 0;
	}
	if (pts) {
		delete[] pts;
		pts = 0;
	}
	if (nodes) {
		__cxa_vec_delete(nodes, 0x10c, 8, (void (*)(void *))func_ov109_0218ac40);
		nodes = 0;
	}
	if (--data_ov109_0218c7a0 < 0)
		data_ov109_0218c7a0 = 0;
	__cxa_vec_cleanup(link, 2, 0xa8);
}

s32 Object214::onCreate()
{
	if (((settings >> 16) & 0xff) != 0) {
		if (data_ov109_0218c7a0 > 1)
			return 0;
	}
	if (!prepareResourcesSafe(0x40, Memory_gameHeap))
		return 0;
	func_ov109_0218a3ec(this);
	count = ((settings >> 12) & 0xf) + 1;
	count2 = ((settings >> 12) & 0xf) + 3;
	count3 = count;
	func_ov109_02189c28(this);
	func_ov109_0218a1e0(this);
	nodes = 0;
	f3fe = -1;
	func_ov109_0218a0d8(this);
	func_ov109_02189f60(this);
	f408 = 1;
	func_ov109_0218a340(this);
	f498 = data_ov109_0218c620;
	func_ov109_0218b628(this, data_ov109_0218c5e0, 0);
	return 1;
}

s32 Object214::onDestroy()
{
	if (f408 == 1)
		func_ov109_02189ec4(this, f408);
	func_ov109_0218c050(linkAt(this, 0));
	func_ov109_0218c050(linkAt(this, 1));
	return 1;
}

bool Object214::onUpdate_0()
{
	func_ov109_0218c0e4(linkAt(this, 0));
	func_ov109_0218c0e4(linkAt(this, 1));
	func_ov109_0218b5d8(this, 0);
	return true;
}

s32 Object214::onRender()
{
	(this->*f498)(0);
	return 1;
}

void Object214::onStomped()
{
	destroy(true);
}

void Object214::pendingDestroy()
{
}

bool Object214::onHeapCreated()
{
	return true;
}

bool Object214::_01()
{
	return false;
}

void *Object214::create()
{
	void *ptr = Base::operator new(0x5f4);

	if (ptr == 0)
		return 0;
	return func_ov109_0218ba40((Object214 *)ptr);
}

// 0x0218c638
ActorProfile Object214_Profile = { Object214::create, 214, 276, func_ov109_0218b7e0 };
