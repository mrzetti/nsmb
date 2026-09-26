#pragma once
#include "../../Minigame/MGScene.hpp"
#include "../../AAA.hpp"
#include "../../Vec.hpp"
#include "../../../lib/Nitro/Nitro.hpp"

struct Object345_Sensor {
	u8 _0[0x18];
	s32 _18;
	s32 _1c;
	s32 _20;
	s32 _24;
};

struct Object345_Pair {
	Vec2_32 a;
	Vec2_32 b;
	u8 _pad[8];
};

// MainProfileTable slot 345  |  ov128  |  profile @ 0x020feb50
class Object345 : public MGScene {
public:
	u8 _5c[0x8];
	u32 _64;
	u8 _68[0x30];
	u32 _98;
	u8 _9c[0xc];
	u32 *_a8;
	u8 _ac[0x6];
	u8 _b2;
	u8 _b3;
	Object345_Sensor _b4;
	u32 _dc;
	u32 _e0;
	u32 _e4;
	u8 _e8[0x2000];
	u8 _20e8[0x400];
	u32 _24e8;
	u32 _24ec;
	u8 _24f0[0x4];
	i16 _24f4;
	i16 _24f6;
	i16 _24f8;
	i16 _24fa;
	i16 _24fc;
	i16 _24fe;
	u32 _2500;
	u8 _2504[0x2];
	i16 _2506;
	u32 _2508;
	u8 _250c[0x14];
	Vec2_32 _2520[4];
	u8 _2550[0x58];
	Vec2_32 _25a8;
	Vec2_32 _25b4;
	Vec2_32 _25c0;
	Vec2_32 _25cc;
	Vec2_32 _25d8;
	u8 _25e4[0xc];
	u32 *_25f0;
	u32 *_25f4;
	u8 _25f8[0x10];
	Vec2_32 _2608[4];
	Vec2_32 _2638[4];
	u8 _2668[4];
	Object345_Pair _266c[0x80];
	u8 _366c[0x80];
	u32 *_36ec;
	u8 _36f0[0x10];

	static void *create();
	inline Object345() {};
	inline ~Object345() {};

	virtual s32 onCreate();
	virtual bool preCreate();
	virtual void postCreate(u32);
	virtual s32 onDestroy();
	virtual bool preDestroy();
	virtual void postDestroy(u32);
	virtual s32 onUpdate();
	virtual bool preUpdate();
	virtual void postUpdate(u32);
	virtual s32 onRender();
	virtual bool preRender();
	virtual void postRender(u32);
	virtual void pendingDestroy();
	virtual bool prepareResourcesSafe(u32, Heap *);
	virtual bool prepareResourcesFast(u32, Heap *);
	virtual bool onHeapCreated();

	virtual void setPosX(u32);
	virtual void incPosX(u32);
	virtual bool onUpdate_0();
	virtual bool _01();
	virtual bool onUpdate_1();
	virtual bool onUpdate_defeated();
	virtual bool onUpdate_3();
	virtual bool onUpdate_4();
	virtual bool onUpdate_5();
	virtual bool onUpdate_6();
	virtual u32 onUpdate_7();
	virtual void onUpdate_8();
	virtual void onUpdate_9();
	virtual void _11();
	virtual void _12();
	virtual void _13();
	virtual void _14();
	virtual void _15();
	virtual void _16();
	virtual bool _17();
};

NTR_SIZE_GUARD(Object345, 0x3700);

extern ObjectProfile Object345_Profile;
