#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../Collision/Collider.hpp"
#include "../../Collision/platform.hpp"

class Object214;

// A pointer-to-member-function the way mwccarm lays one out on the stack:
// { function address, or vtable offset }, followed by the this-adjustment.
// The adjustment is (thisOffset << 1) | 1 for a virtual member and 0 otherwise,
// which is what the call sequence tests and shifts.
struct Object214Func {
	u32 fn;
	u32 adj;
};

typedef void (Object214::*Object214VoidFn)(u32);

// The chain node the byte buffer at 0x400 walks over. 0xA8 bytes.
struct Object214Link {
	Vec3_32 v0;		// 0x00
	Vec3_32 v1;		// 0x10
	Vec2_32 v2;		// 0x20
	s32 f2c;		// 0x2C
	s32 f30;		// 0x30
	u16 f34;		// 0x34
	u8 pad36[2];	// 0x36
	Collider collider;	// 0x38
	u8 pad98[0xB];	// 0x98
	u8 fA3;			// 0xA3
	Object214 *owner;	// 0xA4
};

// One node of the moving platform chain. 0x10C bytes.
struct Object214Node {
	u8 active;		// 0x00
	Vec2_32 v0;		// 0x04
	Vec2_32 v1;		// 0x10
	Vec2_32 v2;		// 0x1C
	s16 f28;		// 0x28
	u8 pad2A[2];	// 0x2A
	Collider collider;	// 0x2C
	u8 pad8C[0xB];	// 0x8C
	u8 f97;			// 0x97
	RotatingPlatform platform;	// 0x98
	Object214 *owner;		// 0x108
};

// A row of the level's path table, indexed through data_0208b168.
struct Object214PathPoint {
	u16 _0;
	s16 a;
	s16 b;
	u8 pad6[0xA];
};

// Enough of the player for the two collision helpers to reach.
struct Object214Player {
	u8 pad00[0xC];
	u16 f0c;
	u8 pad0e[0x52];
	u32 f60;
	u8 pad64[0x6A8];
	s8 f7ac;
	u8 pad70d[0x7E];
	u32 f78c;
	u8 pad790[0x234];
	u32 f9c4;
};

// MainProfileTable slot 214  |  ov109  |  profile @ 0x0218c638
class Object214 : public StageEntity {
public:
	static void *create();
	~Object214();

	s32 onCreate();
	s32 onDestroy();
	bool onUpdate_0();
	s32 onRender();
	void onStomped();
	void pendingDestroy();
	bool onHeapCreated();
	bool _01();

	u8 _3f2;
	u8 linkIdx;		// 0x3F3
	u8 count;		// 0x3F4
	u8 count2;		// 0x3F5
	u8 count3;		// 0x3F6
	u8 pad3f7;		// 0x3F7
	Vec2_32 *pts;		// 0x3F8
	u16 f3fc;		// 0x3FC
	s8 f3fe;		// 0x3FE
	u8 pad3ff;		// 0x3FF
	s8 *buf;		// 0x400
	s32 bufLen;		// 0x404
	s8 f408;		// 0x408
	u8 f409;		// 0x409
	s8 f40a;		// 0x40A
	s8 f40b;		// 0x40B
	Object214VoidFn f40c;	// 0x40C
	s32 f414;		// 0x414
	fx32 f418;		// 0x418
	RotatingPlatform platform;	// 0x41C
	Object214VoidFn f48c;	// 0x48C
	s8 state;		// 0x494
	Object214VoidFn f498;	// 0x498
	u8 link[0x150];		// 0x4A0, Object214Link[2]
	Object214Node *nodes;	// 0x5F0
};

extern ActorProfile Object214_Profile;
