#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// Call descriptor used by Object20's event pointer at 0x3F4
struct Object20Event {
	u32 _0;
	s32 _4;
};

// MainProfileTable slot 20  |  ov054  |  profile @ 0x02170820
class Object20 : public StageEntity {
public:
	void* _14;
	u64 _3f8;
	u32 _400;
	u32 _404;
	u32 _408;
	u16 _40c;
	u16 _40e;
	u16 _410;
	u8 _412;
	u8 _413;
	u8 _414;
	u8 _415;
	u8 _416;
	u8 _417;
	u8 _418;
	u8 _419;
	s8 _41a;
	static void *create();
	inline Object20() {};
	inline ~Object20() {};

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual void pendingDestroy();
	virtual bool onUpdate_0();
};

class Object137 : public Object20 {
	public:
	static void *create();
	inline Object137() {};
	inline ~Object137() {};
};

class Object138 : public Object20 {
	public:
	static void *create();
	inline Object138() {};
	inline ~Object138() {};
};

class Object139 : public Object20 {
	public:
	static void *create();
	inline Object139() {};
	inline ~Object139() {};
};

class Object140 : public Object20 {
	public:
	static void *create();
	inline Object140() {};
	inline ~Object140() {};
};

class Object141 : public Object20 {
	public:
	static void *create();
	inline Object141() {};
	inline ~Object141() {};
};

class Object142 : public Object20 {
	public:
	static void *create();
	inline Object142() {};
	inline ~Object142() {};
};

extern ActorProfile Object20_Profile;

// MainProfileTable slot 137  |  ov054  |  profile @ 0x0217082c
extern ActorProfile Object137_Profile;

// MainProfileTable slot 138  |  ov054  |  profile @ 0x021707f0
extern ActorProfile Object138_Profile;

// MainProfileTable slot 139  |  ov054  |  profile @ 0x021707fc
extern ActorProfile Object139_Profile;

// MainProfileTable slot 140  |  ov054  |  profile @ 0x02170814
extern ActorProfile Object140_Profile;

// MainProfileTable slot 141  |  ov054  |  profile @ 0x02170838
extern ActorProfile Object141_Profile;

// MainProfileTable slot 142  |  ov054  |  profile @ 0x02170808
extern ActorProfile Object142_Profile;

