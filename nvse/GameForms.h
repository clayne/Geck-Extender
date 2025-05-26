
#pragma once

#include <vector>
#include "Utilities.h"
#include "GameTypes.h"
#include "GameBSExtraData.h"
#include "commctrl.h"

enum FormType {
	kFormType_None = 0,
	kFormType_TES4,
	kFormType_Group,
	kFormType_GMST,
	kFormType_BGSTextureSet,
	kFormType_BGSMenuIcon,
	kFormType_TESGlobal,
	kFormType_TESClass,
	kFormType_TESFaction,
	kFormType_BGSHeadPart,
	kFormType_TESHair,
	kFormType_TESEyes,
	kFormType_TESRace,
	kFormType_TESSound,
	kFormType_BGSAcousticSpace,
	kFormType_TESSkill,
	kFormType_EffectSetting,
	kFormType_Script,
	kFormType_TESLandTexture,
	kFormType_EnchantmentItem,
	kFormType_SpellItem,
	kFormType_TESObjectACTI,
	kFormType_BGSTalkingActivator,
	kFormType_BGSTerminal,
	kFormType_TESObjectARMO,			// inv object
	kFormType_TESObjectBOOK,			// inv object
	kFormType_TESObjectCLOT,			// inv object
	kFormType_TESObjectCONT,
	kFormType_TESObjectDOOR,
	kFormType_IngredientItem,			// inv object
	kFormType_TESObjectLIGH,			// inv object
	kFormType_TESObjectMISC,			// inv object
	kFormType_TESObjectSTAT,
	kFormType_BGSStaticCollection,
	kFormType_BGSMovableStatic,
	kFormType_BGSPlaceableWater,
	kFormType_TESGrass,
	kFormType_TESObjectTREE,
	kFormType_TESFlora,
	kFormType_TESFurniture,
	kFormType_TESObjectWEAP,			// inv object
	kFormType_TESAmmo,					// inv object
	kFormType_TESNPC,
	kFormType_TESCreature,
	kFormType_TESLevCreature,
	kFormType_TESLevCharacter,
	kFormType_TESKey,					// inv object
	kFormType_AlchemyItem,				// inv object
	kFormType_BGSIdleMarker,
	kFormType_BGSNote,					// inv object
	kFormType_BGSConstructibleObject,	// inv object
	kFormType_BGSProjectile,
	kFormType_TESLevItem,				// inv object
	kFormType_TESWeather,
	kFormType_TESClimate,
	kFormType_TESRegion,
	kFormType_NavMeshInfoMap,
	kFormType_TESObjectCELL,
	kFormType_TESObjectREFR,
	kFormType_Character,
	kFormType_Creature,
	kFormType_MissileProjectile,
	kFormType_GrenadeProjectile,
	kFormType_BeamProjectile,
	kFormType_FlameProjectile,
	kFormType_TESWorldSpace,
	kFormType_TESObjectLAND,
	kFormType_NavMesh,
	kFormType_TLOD,
	kFormType_TESTopic,
	kFormType_TESTopicInfo,
	kFormType_TESQuest,
	kFormType_TESIdleForm,
	kFormType_TESPackage,
	kFormType_TESCombatStyle,
	kFormType_TESLoadScreen,
	kFormType_TESLevSpell,
	kFormType_TESObjectANIO,
	kFormType_TESWaterForm,
	kFormType_TESEffectShader,
	kFormType_TOFT,						// table of Offset (see OffsetData in Worldspace)
	kFormType_BGSExplosion,
	kFormType_BGSDebris,
	kFormType_TESImageSpace,
	kFormType_TESImageSpaceModifier,
	kFormType_BGSListForm,
	kFormType_BGSPerk,
	kFormType_BGSBodyPartData,
	kFormType_BGSAddonNode,
	kFormType_ActorValueInfo,
	kFormType_BGSRadiationStage,
	kFormType_BGSCameraShot,
	kFormType_BGSCameraPath,
	kFormType_BGSVoiceType,
	kFormType_BGSImpactData,
	kFormType_BGSImpactDataSet,
	kFormType_TESObjectARMA,
	kFormType_BGSEncounterZone,
	kFormType_BGSMessage,
	kFormType_BGSRagdoll,
	kFormType_DOBJ,
	kFormType_BGSLightingTemplate,
	kFormType_BGSMusicType,
	kFormType_TESObjectIMOD,			// inv object
	kFormType_TESReputation,
	kFormType_ContinuousBeamProjectile,
	kFormType_TESRecipe,
	kFormType_TESRecipeCategory,
	kFormType_TESCasinoChips,			// inv object
	kFormType_TESCasino,
	kFormType_TESLoadScreenType,
	kFormType_MediaSet,
	kFormType_MediaLocationController,
	kFormType_TESChallenge,
	kFormType_TESAmmoEffect,
	kFormType_TESCaravanCard,			// inv object
	kFormType_TESCaravanMoney,			// inv object
	kFormType_TESCaravanDeck,
	kFormType_BGSDehydrationStage,
	kFormType_BGSHungerStage,
	kFormType_BGSSleepDeprevationStage,
	kFormType_Count
};



struct ModInfo;		// in GameData.h 
class TESFullName;
class EnchantmentItem;
class TESSound;
class BGSItemList;
class Character;
class BSPortalGraph;
class NiNode;
class EffectItem;
class EffectSetting;
class TESAmmo;
class TESAmmoEffect;
class BGSListForm;
class BoundObjectListHead;
class BGSVoiceType;
class TESFaction;
class SpellItem;
class TESLevSpell;
class BGSBodyPartData;
class TESRace;
class TESQuest;
class BGSProjectile;
class BGSImpactDataSet;
class FaceGenUndo;
class TESCombatStyle;
class TESObjectLAND;
class TESWorldSpace;
class BGSLightingTemplate;
class TESImageSpace;
class TESWaterForm;
class Script;
class TESObjectREFR;
struct ScriptEventList;
class TESObjectLIGH;
class TESEffectShader;
class TESObjectIMOD;
class TESObjectMISC;
class TESPackage;
class Actor;
class BGSImpactData;
class BGSMusicType;
class BGSEncounterZone;
class BGSExplosion;
class BGSDebris;
class BGSRagdoll;

struct Condition;

/**** bases ****/

class BaseFormComponent
{
public:
	BaseFormComponent();
	~BaseFormComponent();

	virtual void	Init(void);
	virtual void	Free(void);
	virtual void	CopyFromBase(BaseFormComponent* component);
	virtual bool	CompareWithBase(BaseFormComponent* src);

	//	void		** _vtbl;	// 000
};

struct PermanentClonedForm
{
	UInt32 orgRefID;
	UInt32 cloneRefID;
};

typedef tList<EffectItem> EffectList;

// 02C
class TESForm : public BaseFormComponent
{
public:
	TESForm();
	~TESForm();

	virtual void		Unk_04();
	virtual void		Unk_05();
	virtual void		Unk_06();
	virtual void		Unk_07();
	virtual void		DialogHas_IDC_ID_Control(HWND hWnd);
	virtual void		Unk_09();
	virtual void		Unk_0A();
	virtual void		Unk_0B();
	virtual void		Destroy(bool bDoFree);
	virtual void		Unk_0D();
	virtual void		Unk_0E();
	virtual void		Unk_0F();
	virtual void		Unk_10();
	virtual void		Unk_11();
	virtual void		Unk_12();
	virtual void		Unk_13();
	virtual void		Unk_14();
	virtual void		Unk_15();
	virtual void		Unk_16();
	virtual void		Unk_17();
	virtual void		Unk_18();
	virtual void		Unk_19();
	virtual void		InitItem();
	virtual void		Unk_1B();
	virtual void		GetDebugString(char* dst);
	virtual bool		IsPersistent() const;
	virtual void		Unk_1E();
	virtual void		Unk_1F();
	virtual void		Unk_20();
	virtual void		Unk_21();
	virtual void		Unk_22();
	virtual void		Unk_23();
	virtual void		Unk_24();
	virtual void		Unk_25();
	virtual void		Unk_26();
	virtual void		Unk_27();
	virtual void		Unk_28();
	virtual void		Unk_29();
	virtual void		MarkAsModified(bool bModified = true);
	virtual void		Unk_2B();
	virtual void		Unk_2C();
	virtual void		Unk_2D();
	virtual void		Unk_2E();
	virtual void		Unk_2F();
	virtual void		Unk_30();
	virtual void		Unk_31();
	virtual bool		IsBoundObject();
	virtual void		Unk_33();
	virtual void		Unk_34();
	virtual void		Unk_35();
	virtual void		Unk_36();
	virtual void		Unk_37();
	virtual void		Unk_38();
	virtual bool		IsActor() const;
	virtual void		Unk_3A();
	virtual void		Unk_3B();
	virtual void		Unk_3C();
	virtual void		Unk_3D();
	virtual void		Unk_3E();
	virtual const char* GetEditorID() const;
	virtual void		Unk_40();
	virtual void		Unk_41();
	virtual void		Unk_42();
	virtual bool		Unk_43();
	virtual void		Unk_44();
	virtual void		GetFormPath(String* str);
	virtual void		Unk_46();
	virtual void		Unk_47();
	virtual void		Unk_48();
	virtual void		Unk_49();
	virtual void		Unk_4A();
	virtual void		Unk_4B();
	virtual void		Unk_4C();
	virtual void		Unk_4D();
	virtual bool		Unk_4E(void);
	virtual void		Unk_4F(void);
	virtual void		Unk_50(void);
	virtual void		Unk_51(void);
	virtual bool		Unk_52(void);
	virtual void		Unk_53(void);
	virtual bool		DialogCallback(HWND hDlg, int a3, int a4, int a5, void* a6);
	virtual void		Unk_55(void);
	virtual void		Unk_56(void);
	virtual void		Unk_57(void);
	virtual void		Unk_58(void);
	virtual void		OpenDialog(HWND hWndParent, char a3, char a4);
	virtual void		SetupListViewDisplayInfo(LPNMLVDISPINFOA displayInfo);
	virtual signed int 	Compare(TESForm* to, int compareType);
	virtual void		Unk_5C(void);
	virtual void		Unk_5D(void);

	struct EditorData {
		String		editorID;			// 00
		UInt32		vcMasterFormID;		// 08 - Version control 1 (looks to be a refID inside the Version Control master)
		UInt32		vcRevision;			// 0C
	};

	enum
	{
		kFormFlags_Initialized = 0x00000008,	// set by TESForm::InitItem()
		kFormFlags_Modified = 0x2,
		kFormFlags_Deleted = 0x20,
		kFormFlags_QuestItem = 0x00000400,
		kFormFlags_InitiallyDisabled = 0x800,
		kFormFlags_Temporary = 0x00004000,
		kFormFlags_Compressed = 0x00040000,
	};

	enum
	{
		kModified_Flags = 0x00000001
		//	UInt32	flags;
	};

	UInt8	typeID;					// 004
	UInt8	typeIDPad[3];			// 005
	UInt32	flags;					// 008
	union
	{
		UInt32		refID;			// 00C
		struct
		{
			UInt8	id[3];
			UInt8	modIndex;
		};
	};
	EditorData	editorData;			// +10
	tList<ModInfo> mods;			// 010 ModReferenceList in Oblivion	
	UInt8 byte28;
	UInt8 gap29[3];

	TESForm* TryGetREFRParent(void);
	UInt8			GetModIndex() const;
	TESFullName* GetFullName();
	const char* GetTheName() { return CdeclCall <const char*>(0x437DB0, this); };
	bool			IsCloned() const;
	bool IsDisabled() { return flags & kFormFlags_InitiallyDisabled; };
	void SetDisabled(bool abDisabled);

	bool IsWeapon() { return typeID == kFormType_TESObjectWEAP; }
	bool IsArmor() { return typeID == kFormType_TESObjectARMO; }
	bool IsAmmo() { return typeID == kFormType_TESAmmo; }
	bool IsIngestible() { return typeID == kFormType_AlchemyItem; }
	void SetTemporary() { ThisCall(0x4FBA50, this); }

	MEMBER_FN_PREFIX(TESForm);
};
STATIC_ASSERT(sizeof(TESForm) == 0x2C);

struct ColorRGB
{
	UInt8	red;	// 000
	UInt8	green;	// 001
	UInt8	blue;	// 002
	UInt8	alpha;	// 003 or unused if no alpha
};	// 004 looks to be endian swapped !

class TESObject : public TESForm
{
public:
	TESObject();
	~TESObject();

	virtual void		Unk_5E(void);
	virtual void		Unk_5F(void);
	virtual void		Unk_60(void);
	virtual void		Unk_61(void);
	virtual void		Unk_62(void);
	virtual void		Unk_63(void);
	virtual void		Unk_64(void);
	virtual void		Unk_65(void);
	virtual void		Unk_66(void);
	virtual void		Unk_67(void);						// Actor: GetMagicEffectList
	virtual void		Unk_68(void);						// Actor: GetMagicEffectList
	virtual void		Unk_69(void);						// Actor: GetMagicEffectList
	virtual void		Unk_6A(void);						// Actor: GetMagicEffectList
	virtual void		Unk_6B(void);
	virtual void		Unk_6C(void);	// REFR: GetBSFaceGenNiNodeSkinned
	virtual NiNode* LoadGraphics(TESForm* apBaseForm);

	UInt32 unk2C;
	void* unk30;
};

// 30
class TESBoundObject : public TESObject
{
public:
	TESBoundObject();
	~TESBoundObject();

	virtual void		Unk_6E(void);
	virtual void		Unk_6F(void);
	virtual void		Unk_70(void);
	virtual void		Unk_71(void);

	struct BOUND_DATA
	{
		NiNPShortPoint3 min;
		NiNPShortPoint3 max;
	};

	BoundObjectListHead* head;		// 034
	TESBoundObject* prev;		// 038
	TESBoundObject* next;		// 03C
	UInt32 unk40;				// 040
	BOUND_DATA					bounds;	// 044
	UInt32 unk50;				// 050
};

// C
class TESFullName : public BaseFormComponent
{
public:
	TESFullName();
	~TESFullName();

	String	name;		// 004
};

// 00C
class TESTexture : public BaseFormComponent
{
public:
	TESTexture();
	~TESTexture();

	virtual UInt32	Unk_04(void);
	virtual void	GetNormalMap(String* str);
	virtual char* GetPathRoot(void);

	String ddsPath;
	UInt32 unk;
	UInt32 textFieldControlId;
	UInt32 editButtonControlId;
	UInt32 iconControlId;
};
static_assert(sizeof(TESTexture) == 0x1C);

// 00C
class TESIcon : public TESTexture
{
public:
	TESIcon();
	~TESIcon();

	void SetPath(const char* newPath) { ddsPath.Set(newPath); }
};


// C
class TESScriptableForm : public BaseFormComponent
{
public:
	TESScriptableForm();
	~TESScriptableForm();

	Script* script;	// 004
	bool	resolved;	// 008	called during LoadForm, so scripts do not wait for TESForm_InitItem to be resolved
	UInt8	pad[3];		// 009
};

// 010
class BGSMessageIcon : public BaseFormComponent
{
public:
	BGSMessageIcon();
	~BGSMessageIcon();

	TESIcon	icon;		// 004
};


// 008
class TESValueForm : public BaseFormComponent
{
public:
	enum
	{
		kModified_GoldValue = 0x00000008,
		// UInt32	value
	};

	TESValueForm();
	~TESValueForm();

	virtual UInt32	GetSaveSize(UInt32 changedFlags);
	virtual void	Save(UInt32 changedFlags);
	virtual void	Load(UInt32 changedFlags);

	//	DEFINE_MEMBER_FN_LONG(TESValueForm, SetValue, void, _TESValueForm_SetValue, UInt32 newVal);

	UInt32	value;
	// 008
};

// 10
class TESEnchantableForm : public BaseFormComponent
{
public:
	TESEnchantableForm();
	~TESEnchantableForm();

	virtual UInt32	Unk_04(void);	// returns unk2

	EnchantmentItem* enchantItem;	// 04
	UInt16	enchantment;			// 08
	UInt16	unk1;					// 0A
	UInt32	unk2;					// 0C
	// 010
};

// 08
class TESImageSpaceModifiableForm : public BaseFormComponent
{
public:
	TESImageSpaceModifiableForm();
	~TESImageSpaceModifiableForm();

	UInt32	unk04;	// 04
};

// 008
class TESWeightForm : public BaseFormComponent
{
public:
	TESWeightForm();
	~TESWeightForm();

	float	weight;		// 004
	// 008
};

// 008
class TESHealthForm : public BaseFormComponent
{
public:
	TESHealthForm();
	~TESHealthForm();

	virtual UInt32	GetHealth(void);	// 0004

	UInt32	health;		// 004
};

// 008
class TESAttackDamageForm : public BaseFormComponent
{
public:
	TESAttackDamageForm();
	~TESAttackDamageForm();

	virtual UInt16	GetDamage(void);

	UInt16	damage;	// 04
	UInt16	unk0;	// 06 - bitmask? perhaps 2 UInt8s?
	// 008
};


// 24
class EffectItem
{
public:
	EffectItem();
	~EffectItem();

	enum
	{
		kRange_Self = 0,
		kRange_Touch,
		kRange_Target,
	};

	struct ScriptEffectInfo
	{
		UInt32 scriptRefID;
		UInt32 school;
		String effectName;
		UInt32 visualEffectCode;
		UInt32 isHostile;

		void SetName(const char* name);
		void SetSchool(UInt32 school);
		void SetVisualEffectCode(UInt32 code);
		void SetIsHostile(bool bIsHostile);
		bool IsHostile() const;
		void SetScriptRefID(UInt32 refID);

		ScriptEffectInfo* Clone() const;
		void CopyFrom(const ScriptEffectInfo* from);
		static ScriptEffectInfo* Create();
	};

	// mising flags
	UInt32				magnitude;			// 00	used as a float
	UInt32				area;				// 04
	UInt32				duration;			// 08
	UInt32				range;				// 0C
	UInt32				actorValueOrOther;	// 10
	EffectSetting* setting;			// 14
	float				cost;				// 18 on autocalc items this seems to be the cost
	tList<Condition>	conditions;			// 1C

	//bool HasActorValue() const;
	//UInt32 GetActorValue() const;
	//bool IsValidActorValue(UInt32 actorValue) const;
	//void SetActorValue(UInt32 actorValue);

	//bool IsScriptedEffect() const;
	//UInt32 ScriptEffectRefId() const;
	//UInt32 ScriptEffectSchool() const;
	//UInt32 ScriptEffectVisualEffectCode() const;
	//bool IsScriptEffectHostile() const;

	//EffectItem* Clone() const;
	//void CopyFrom(const EffectItem* from);
	//static EffectItem* Create();
	//static EffectItem* ProxyEffectItemFor(UInt32 effectCode);
	//
	//bool operator<(EffectItem*rhs) const;
	//// return the magicka cost of this effect item
	//// adjust for skill level if actorCasting is used
	//float MagickaCost(TESForm* actorCasting = NULL) const;

	//void SetMagnitude(UInt32 magnitude);
	//void ModMagnitude(float modBy);
	//void SetArea(UInt32 area);
	//void ModArea(float modBy);
	//void SetDuration(UInt32 duration);
	//void ModDuration(float modBy);
	//void SetRange(UInt32 range);
	//bool IsHostile() const;
};

// C
class EffectItemList : public BSSimpleList<EffectItem>
{
public:
	EffectItemList();
	~EffectItemList();

	UInt32	unk00C;	// 00C

	EffectItem* ItemAt(UInt32 whichItem);
	UInt32 CountItems() const;
	const char* GetNthEIName(UInt32 whichEffect) const;

	//	bool HasNonHostileItem() const;
	//	UInt32 CountHostileItems() const;
	//	UInt32 AddItem(EffectItem* effectItem);
	//	UInt32 AddItemCopy(EffectItem* effectItem);
	//	UInt32 CopyItemFrom(EffectItemList& fromList, UInt32 whichItem);
	bool RemoveNthEffect(UInt32 index);
};

STATIC_ASSERT(sizeof(EffectItemList) == 0x10);

// 1C
class MagicItem : public TESFullName
{
public:
	MagicItem();
	~MagicItem();

	// pure virtual args/return values unknown
	virtual void	Unk_04(void); // pure virtual
	virtual void	Unk_05(void); // pure virtual
	virtual void	Unk_06(void); // pure virtual
	virtual bool	Unk_07(void);
	virtual bool	Unk_08(void);
	virtual void	Unk_09(void); // pure virtual
	virtual void	Unk_0A(void); // pure virtual
	virtual void	Unk_0B(void); // pure virtual
	virtual void	Unk_0C(void); // pure virtual
	virtual void	Unk_0D(void); // pure virtual
	virtual void	Unk_0E(void);
	virtual void	Unk_0F(void); // pure virtual

	EffectItemList	list;	// 00C

	// perhaps types are no longer correct!
	enum EType {
		kType_None = 0,
		kType_Spell = 1,
		kType_Enchantment = 2,
		kType_Alchemy = 3,
		kType_Ingredient = 4,
	};
	EType Type() const;
};

STATIC_ASSERT(sizeof(MagicItem) == 0x1C);

// 034
class MagicItemForm : public TESForm
{
public:
	MagicItemForm();
	~MagicItemForm();

	virtual void	ByteSwap(void); // pure virtual

	// base
	MagicItem	magicItem;	// 018
};

STATIC_ASSERT(sizeof(MagicItemForm) == 0x34);

// 18
class TESModel : public BaseFormComponent
{
public:
	TESModel();
	~TESModel();

	enum
	{
		kFacegenFlag_Head = 0x01,
		kFacegenFlag_Torso = 0x02,
		kFacegenFlag_RightHand = 0x04,
		kFacegenFlag_LeftHand = 0x08,
	};

	virtual void* Destroy(bool noDealloc);	// 04
	virtual char* GetModelPath(void);
	virtual void	SetModelPath(char* path);	// 06

	String	nifPath;		// 04
	UInt32	unk0C;			// 0C	referenced when saving Texture Hashes, init'd as a byte or is it a pointer to a structure starting with a byte followed by a pointer to some allocated data ?
	void* unk10;		// 10
	UInt8	facegenFlags;	// 14
	UInt8	pad15[3];		// 15

	void SetPath(const char* newPath) { nifPath.Set(newPath); }
};

// 18
class BGSTextureModel : public TESModel
{
public:
	BGSTextureModel();
	~BGSTextureModel();
};

// 020
class TESModelTextureSwap : public TESModel
{
public:
	TESModelTextureSwap();
	~TESModelTextureSwap();

	struct Texture
	{
		UInt32	textureID;			// 00
		UInt32	index3D;			// 04
		char	textureName[0x80];	// 08
	};	// there seem to be an array (length 6) post 0x88

	virtual void* Destroy(bool noDealloc);
	virtual char* GetPath(void);
	virtual void	SetPath(char* path);
	virtual void* Unk_07(void);

	tList<Texture> textureList;	// 018
};

// 008
class BGSClipRoundsForm : public BaseFormComponent
{
public:
	BGSClipRoundsForm();
	~BGSClipRoundsForm();

	UInt8	clipRounds;
	UInt8	padding[3];
	// 008
};

// 18
struct DestructionStage
{
	enum
	{
		kFlags_CapDamage = 1,
		kFlags_DisableObject = 2,
		kFlags_DestroyObject = 4,
	};

	UInt8				dmgStage;		// 00
	UInt8				healthPrc;		// 01
	UInt16				flags;			// 02
	UInt32				selfDmgSec;		// 04
	BGSExplosion* explosion;		// 08
	BGSDebris* debris;		// 0C
	UInt32				debrisCount;	// 10
	TESModelTextureSwap* replacement;	// 14
};

// 0C
struct DestructibleData
{
	UInt32				health;		// 00
	UInt8				stageCount;	// 04
	bool				targetable;	// 05
	UInt8				unk06[2];	// 06
	DestructionStage** stages;	// 08
};

// 08
class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
	BGSDestructibleObjectForm();
	~BGSDestructibleObjectForm();

	DestructibleData* data;			// 04
};

STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x8);

// 00C
class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
	BGSPickupPutdownSounds();
	~BGSPickupPutdownSounds();

	TESSound* pickupSound;		// 004
	TESSound* putdownSound;		// 008
};

// 008
class BGSAmmoForm : public BaseFormComponent
{
public:
	BGSAmmoForm();
	~BGSAmmoForm();

	TESForm* ammo; // 04	either TESAmmo or BGSListForm
};

// 008
class BGSRepairItemList : public BaseFormComponent
{
public:
	BGSRepairItemList();
	~BGSRepairItemList();

	BGSListForm* listForm;	// 04
};

// 008
class BGSEquipType : public BaseFormComponent
{
public:
	BGSEquipType();
	~BGSEquipType();

	UInt32	equipType;	// 08
};

// 004
class BGSPreloadable : public BaseFormComponent
{
public:
	BGSPreloadable();
	~BGSPreloadable();

	virtual void	Fn_04(void); // pure virtual
};

// 008
class BGSBipedModelList : public BaseFormComponent
{
public:
	BGSBipedModelList();
	~BGSBipedModelList();

	BGSListForm* models;		// 004
	// 008
};

// 018
class TESModelRDT : public TESModel
{
public:
	TESModelRDT();
	~TESModelRDT();

	virtual UInt32	Fn_07(void);
};

// 0DC
class TESBipedModelForm : public BaseFormComponent
{
public:
	TESBipedModelForm();
	~TESBipedModelForm();

	// bit indices starting from lsb
	enum EPartBit {
		ePart_Head = 0,
		ePart_Hair,
		ePart_UpperBody,
		ePart_LeftHand,
		ePart_RightHand,
		ePart_Weapon,
		ePart_PipBoy,
		ePart_Backpack,
		ePart_Necklace,
		ePart_Headband,
		ePart_Hat,
		ePart_Eyeglasses,
		ePart_Nosering,
		ePart_Earrings,
		ePart_Mask,
		ePart_Choker,
		ePart_MouthObject,
		ePart_BodyAddon1,
		ePart_BodyAddon2,
		ePart_BodyAddon3
	};

	enum EPartBitMask {
		ePartBitMask_Full = 0x07FFFF,
	};

	enum ESlot {
		eSlot_Head = 0x1 << ePart_Head,
		eSlot_Hair = 0x1 << ePart_Hair,
		eSlot_UpperBody = 0x1 << ePart_UpperBody,
		eSlot_LeftHand = 0x1 << ePart_LeftHand,
		eSlot_RightHand = 0x1 << ePart_RightHand,
		eSlot_Weapon = 0x1 << ePart_Weapon,
		eSlot_PipBoy = 0x1 << ePart_PipBoy,
		eSlot_Backpack = 0x1 << ePart_Backpack,
		eSlot_Necklace = 0x1 << ePart_Necklace,
		eSlot_Headband = 0x1 << ePart_Headband,
		eSlot_Hat = 0x1 << ePart_Hat,
		eSlot_Eyeglasses = 0x1 << ePart_Eyeglasses,
		eSlot_Nosering = 0x1 << ePart_Nosering,
		eSlot_Earrings = 0x1 << ePart_Earrings,
		eSlot_Mask = 0x1 << ePart_Mask,
		eSlot_Choker = 0x1 << ePart_Choker,
		eSlot_MouthObject = 0x1 << ePart_MouthObject,
		eSlot_BodyAddon1 = 0x1 << ePart_BodyAddon1,
		eSlot_BodyAddon2 = 0x1 << ePart_BodyAddon2,
		eSlot_BodyAddon3 = 0x1 << ePart_BodyAddon3
	};

	enum EBipedFlags {
		eBipedFlag_HasBackPack = 0x4,
		eBipedFlag_MediumArmor = 0x8,
		eBipedFlag_PowerArmor = 0x20,
		eBipedFlag_NonPlayable = 0x40,
		eBipedFlag_HeavyArmor = 0x80,
	};

	enum EBipedPath {
		ePath_Biped,
		ePath_Ground,
		ePath_Icon,
		ePath_Max
	};

	// missing part mask and flags
	UInt32					partMask;			// 004
	UInt8					bipedFlags;			// 008
	UInt8					fil009[3];			// 009 seen badly initialized (ArmorCombat)
	TESModelTextureSwap		bipedModel[2];		// 00C
	TESModelTextureSwap		groundModel[2];		// 04C
	TESIcon					icon[2];			// 08C
	BGSMessageIcon			messageIcon[2];		// 0A4
	TESModelRDT				modelRDT;			// 0C4
	// 0DC

	static UInt32 MaskForSlot(UInt32 mask);

	bool IsPowerArmor() const { return (bipedFlags & eBipedFlag_PowerArmor) == eBipedFlag_PowerArmor; }
	bool IsNonPlayable() const { return (bipedFlags & eBipedFlag_NonPlayable) == eBipedFlag_NonPlayable; }
	bool IsPlayable() const { return !IsNonPlayable(); }
	void SetPowerArmor(bool bPA) {
		if (bPA) {
			bipedFlags |= eBipedFlag_PowerArmor;
		}
		else {
			bipedFlags &= ~eBipedFlag_PowerArmor;
		}
	}
	void SetNonPlayable(bool bNP) {
		if (bNP) {
			bipedFlags |= eBipedFlag_NonPlayable;
		}
		else {
			bipedFlags &= ~eBipedFlag_NonPlayable;
		}
	}
	void SetPlayable(bool doset) { if (doset) bipedFlags &= ~eBipedFlag_NonPlayable; else bipedFlags |= eBipedFlag_NonPlayable; }
	void  SetPath(const char* newPath, UInt32 whichPath, bool bfemalePath);
	const char* GetPath(UInt32 whichPath, bool bFemalePath);

	UInt32 GetSlotsMask() const;
	void SetSlotsMask(UInt32 mask);	// Limited by ePartBitMask_Full

	UInt32 GetBipedMask() const;
	void SetBipedMask(UInt32 mask);
};

STATIC_ASSERT(sizeof(TESBipedModelForm) == 0x0DC);

// 30
class TESBoundAnimObject : public TESBoundObject
{
public:
	TESBoundAnimObject();
	~TESBoundAnimObject();
};

struct ContainerExtraData
{
	TESForm* owner;
	UInt32	globalOrRequiredRank;
	double	itemCondition;
};

// 00C
class TESContainer : public BaseFormComponent
{
public:
	TESContainer();
	~TESContainer();

	struct FormCount
	{
		SInt32				count;			//	00
		TESForm* form;			//	04
		ContainerExtraData* contExtraData;	//	08
	};

	typedef tList<FormCount> FormCountList;
	FormCountList formCountList;	// 004

	static TESContainer* Create();
	void Destroy();
	// 00C
};

// 00C
class BGSTouchSpellForm : public BaseFormComponent
{
public:
	BGSTouchSpellForm();
	~BGSTouchSpellForm();

	TESForm* unarmedEffect;	// 04
	UInt16	unarmedAnim;	// 08
	UInt16	pad0A;			// 0A
};

// 034
class TESActorBaseData : public BaseFormComponent
{
public:
	TESActorBaseData();
	~TESActorBaseData();

	virtual void			Fn_04(TESForm* selectedForm);	// Called during form initialization after LoadForm and InitForm
	// flags access
	virtual bool			Fn_05(void);	// 00100000
	virtual bool			Fn_06(void);	// 00200000
	virtual bool			Fn_07(void);	// 10000000
	virtual bool			Fn_08(void);	// 20000000
	virtual bool			Fn_09(void);	// 80000000
	virtual bool			Fn_0A(void);	// 00400000
	virtual bool			Fn_0B(void);	// 00400000
	virtual bool			Fn_0C(void);	// 00800000
	virtual bool			Fn_0D(void);
	virtual bool			Fn_0E(void);
	virtual bool			Fn_0F(void);
	virtual bool			Fn_10(void);
	virtual bool			Fn_11(void);
	virtual bool			Fn_12(void);
	virtual void			Fn_13(void* arg);
	virtual bool			Fn_14(void);
	virtual void			Fn_15(void* arg);
	virtual UInt32			Fn_16(void);
	virtual void			Fn_17(void* arg);
	virtual UInt32			Fn_18(void);	// return unk08
	virtual float			Fn_19(void);	// return unk14
	virtual BGSVoiceType* GetVoiceType(void);

	enum
	{
		kFlags_Female = 1 << 0,
		kFlags_CreatureBiped = kFlags_Female,
		kFlags_Essential = 1 << 1,
		kFlags_HasCharGenFace = 1 << 2,
		kFlags_CreatureWeaponAndShield = kFlags_HasCharGenFace,
		kFlags_Respawn = 1 << 3,
		kFlags_AutoCalcStats = 1 << 4,
		kFlags_CreatureSwims = kFlags_AutoCalcStats,
		kFlags_CreatureFlies = 1 << 5,
		kFlags_CreatureWalks = 1 << 6,
		kFlags_PCLevelMult = 1 << 7,
		kFlags_UseTemplate = 1 << 8,
		kFlags_NoLowLevelProcessing = 1 << 9,
		//									1 << 10,
		kFlags_NoBloodSpray = 1 << 11,
		kFlags_NoBloodDecal = 1 << 12,
		//									1 << 13,
		//									1 << 14,
		kFlags_CreatureNoHead = 1 << 15,
		kFlags_CreatureNoRightArm = 1 << 16,
		kFlags_CreatureNoLeftArm = 1 << 17,
		kFlags_CreatureNoCombatInWater = 1 << 18,
		kFlags_CreatureNoShadow = 1 << 19,
		kFlags_NoVATSMelee = 1 << 20,
		kFlags_CreatureAllowPCDialogue = 1 << 21,
		kFlags_CanBeAllRaces = 1 << 22,
		kFlags_CreatureCantOpenDoor = kFlags_CanBeAllRaces,
		kFlags_CreatureImmobile = 1 << 23,
		kFlags_CreatureTiltFrontBack = 1 << 24,
		kFlags_CreatureTiltLeftRight = 1 << 25,
		kFlags_NoKnockdowns = 1 << 26,
		kFlags_NotPushable = 1 << 27,
		kFlags_CreatureAllowPickpocket = 1 << 28,
		kFlags_CreatureIsGhost = 1 << 29,
		kFlags_NoRotateToHeadTrack = 1 << 30,
		kFlags_CreatureInvulnerable = 1 << 31,
	};

	enum
	{
		kTemplateFlag_UseTraits = 1 << 0,
		kTemplateFlag_UseStats = 1 << 1,
		kTemplateFlag_UseFactions = 1 << 2,
		kTemplateFlag_UseActorEffectList = 1 << 3,
		kTemplateFlag_UseAIData = 1 << 4,
		kTemplateFlag_UseAIPackages = 1 << 5,
		kTemplateFlag_UseModelAnimation = 1 << 6,
		kTemplateFlag_UseBaseData = 1 << 7,
		kTemplateFlag_UseInventory = 1 << 8,
		kTemplateFlag_UseScript = 1 << 9,
	};

	struct FactionListData
	{
		TESFaction* faction;
		UInt8		rank;
		UInt8		pad[3];
	};

	UInt32			flags;				// 04	Comparing with LoadForm and FNVEdit
	UInt16			fatigue;			// 08	Fatique
	UInt16			barterGold;			// 0A	Barter Gold
	SInt16			level;				// 0C	Level/ Level Mult
	UInt16			calcMin;			// 0E	Calc min
	UInt16			calcMax;			// 10	Calc max
	UInt16			speedMultiplier;	// 12	Speed Multiplier (confirmed)
	float			Karma;				// 14	Karma
	UInt16			dispositionBase;	// 18	Disposition Base
	UInt16			templateFlags;		// 1A	Template Flags
	TESForm* deathItem;		// 1C	Death Item: object or FormList
	BGSVoiceType* voiceType;		// 20
	TESForm* templateActor;		// 24	Points toward Template
#ifdef RUNTIME
	UInt32			changedFlags;		// 28/000	Absent in Editor
#endif
	tList<FactionListData>	factionList;	// 2C/28

	SInt8 GetFactionRank(TESFaction* faction);
	void SetFactionRank(TESFaction* faction, SInt8 rank);

	bool IsFemale() { return flags & kFlags_Female ? true : false; }
};

// 14
class TESSpellList : public BaseFormComponent
{
public:
	enum
	{
		kModified_BaseSpellList = 0x00000020,
		// CHANGE_ACTOR_BASE_SPELLLIST
		//	UInt16	numSpells;
		//	UInt32	spells[numSpells];
	};

	TESSpellList();
	~TESSpellList();

	virtual UInt32	GetSaveSize(UInt32 changedFlags);
	virtual void	Save(UInt32 changedFlags);
	virtual void	Load(UInt32 changedFlags);

	tList<SpellItem>	spellList;			// 004
	tList<SpellItem>	leveledSpellList;	// 00C

	UInt32	GetSpellCount() const {
		return spellList.Count();
	}

	// return the nth spell
	SpellItem* GetNthSpell(SInt32 whichSpell) const
	{
		return spellList.GetNthItem(whichSpell);
	}

	// removes all spells and returns how many spells were removed
	//UInt32 RemoveAllSpells();
};

// 020
class TESAIForm : public BaseFormComponent
{
public:
	TESAIForm();
	~TESAIForm();

	typedef tList<TESPackage> PackageList;

	virtual UInt32	GetSaveSize(UInt32 changedFlags);
	virtual void	Save(UInt32 changedFlags);
	virtual void	Load(UInt32 changedFlags);

	UInt8	agression;				// 04
	UInt8	confidence;				// 05 
	UInt8	energyLevel;			// 06
	UInt8	responsibility;			// 07
	UInt8	mood;					// 08
	UInt8	pad09[3];				// 09

	UInt32	buySellsAndServices;	// 0C
	UInt8	teaches;				// 10
	UInt8	maximumTrainingLevel;	// 11
	UInt8	assistance;				// 12
	UInt8	aggroRadiusBehavior;	// 13
	SInt32	aggroRadius;			// 14

	PackageList	packageList;	// 18

	UInt32	GetPackageCount() const {
		return packageList.Count();
	}

	// return the nth package
	TESPackage* GetNthPackage(SInt32 anIndex) const
	{
		return packageList.GetNthItem(anIndex);
	}

	// replace the nth package
	TESPackage* SetNthPackage(TESPackage* pPackage, SInt32 anIndex)
	{
		return packageList.ReplaceNth(anIndex == -1 ? eListEnd : anIndex, pPackage);
	}

	// return the nth package
	SInt32 AddPackageAt(TESPackage* pPackage, SInt32 anIndex)
	{
		return packageList.AddAt(pPackage, anIndex == -1 ? eListEnd : anIndex);
	}

	TESPackage* RemovePackageAt(SInt32 anIndex)
	{
		return packageList.RemoveNth(anIndex == -1 ? eListEnd : anIndex);
	}

	// removes all packages and returns how many were removed
	UInt32 RemoveAllPackages() const
	{
		UInt32 cCount = GetPackageCount();
		packageList.RemoveAll();
		return cCount - GetPackageCount();
	}
};

// 00C
class TESAttributes : public BaseFormComponent
{
public:
	TESAttributes();
	~TESAttributes();

	enum
	{
		kStrength = 0,
		kPerception,
		kEndurance,
		kCharisma,
		kIntelligence,
		kAgility,
		kLuck,
	};

	UInt8	attributes[7];	// 4
	UInt8	padB;			// B
};

// 00C
class TESAnimation : public BaseFormComponent
{
public:
	TESAnimation();
	~TESAnimation();

	typedef tList<char> AnimNames;

	// constructor and Fn_01 sugest this is a tList of char string.
	// In GECK it is an array
	AnimNames	animNames;
	// 00C
};

class ActorValueOwner
{
public:
	ActorValueOwner();
	~ActorValueOwner();

	virtual UInt32	GetBaseActorValue(UInt32 actorValueCode);	// GetBaseActorValue (used from Eval) result in EAX
	virtual float	Fn_01(UInt32 actorValueCode);	// GetBaseActorValue internal, result in st
	virtual UInt32	Fn_02(UInt32 actorValueCode);	// GetActorValue internal, result in EAX
	virtual float	GetActorValue(UInt32 actorValueCode);	// GetActorValue (used from Eval) result in EAX
	virtual float	Fn_04(UInt32 actorValueCode);	// GetBaseActorValue04 (internal) result in st
	virtual float	GetActorValueDamage(UInt32 actorValueCode);
	virtual float	Fn_06(UInt32 actorValueCode);	// GetDamageActorValue or GetModifiedActorValue		called from Fn_08, result in st, added to Fn_01
	virtual UInt32	Fn_07(UInt32 actorValueCode);	// Manipulate GetPermanentActorValue, maybe convert to integer.
	virtual float	Fn_08(UInt32 actorValueCode);	// GetPermanentActorValue (used from Eval) result in EAX
	virtual Actor* Fn_09(void);					// GetActorBase (= this - 0x100) or GetActorBase (= this - 0x0A4)
	virtual UInt16	GetLevel();						// GetLevel (from ActorBase)

	// SkillsCurrentValue[14] at index 20
};

STATIC_ASSERT(sizeof(ActorValueOwner) == 0x004);

class CachedValuesOwner
{
public:
	CachedValuesOwner();
	~CachedValuesOwner();

	virtual float	Fn_00(void);
	virtual float	Fn_01(void);
	virtual float	Fn_02(void);
	virtual float	Fn_03(void);
	virtual float	Fn_04(void);
	virtual float	Fn_05(void);
	virtual float	Fn_06(void);
	virtual float	Fn_07(void);
	virtual float	Fn_08(void);
	virtual float	Fn_09(void);
	virtual float	Fn_0A(void);
	virtual UInt32	Fn_0B(void);
	virtual UInt32	Fn_0C(void);
	virtual float	Fn_0D(void);
	virtual float	Fn_0E(void);
	virtual bool	Fn_0F(void);
};

STATIC_ASSERT(sizeof(CachedValuesOwner) == 0x004);

// 10C
class TESActorBase : public TESBoundAnimObject
{
public:
	TESActorBase();
	~TESActorBase();

	virtual BGSBodyPartData* GetBodyPartData(void);
	virtual void				Fn_61(void* arg);
	virtual TESCombatStyle* GetCombatStyle(void);	// Result saved as ZNAM GetCombatStyle
	virtual void				SetCombatStyle(TESCombatStyle* combatStyle);
	virtual void				SetAttr(UInt32 idx, float value);	// calls Fn65
	virtual void				SetAttr(UInt32 idx, UInt32 value);
	virtual void				ModActorValue(UInt32 actorValueCode, float value);
	virtual void				Fn_67(void* arg0, UInt32 arg1);	// mod actor value?

	// bases
	TESActorBaseData			baseData;		// 030/054
	TESContainer				container;		// 064/084
	BGSTouchSpellForm			touchSpell;		// 070/090	Unarmed attack effect
	TESSpellList				spellList;		// 07C/09C
	TESAIForm					ai;				// 090
	TESHealthForm				health;			// 0B0
	TESAttributes				attributes;		// 0B8
	TESAnimation				animation;		// 0C4/0E4	special idles
	TESFullName					fullName;		// 0D0/0F8
	TESModel					model;			// 0DC/104
	TESScriptableForm			scriptable;		// 0F4/128
	ActorValueOwner				avOwner;		// 100
	BGSDestructibleObjectForm	destructible;	// 104
	// 10C
};

STATIC_ASSERT(offsetof(TESActorBase, avOwner) == 0x100);
STATIC_ASSERT(sizeof(TESActorBase) == 0x10C);

// 14
class TESModelList : public BaseFormComponent
{
public:
	TESModelList();
	~TESModelList();

	tList<char>	modelList;	// 04
	UInt32		count;		// 0C
	UInt32		unk10;		// 10

	SInt32 GetIndex(char* path);
	bool RemoveEntry(char* nifToRemove);
	bool AddEntry(char* nifToAdd);
	bool ModelListAction(char* path, SInt8 action);
};

// 008
class TESDescription : public BaseFormComponent
{
public:
	TESDescription();
	~TESDescription();

	virtual char* Get(TESForm* overrideForm, UInt32 chunkID);

	UInt32	formDiskOffset;	// 4 - how does this work for descriptions in mods?
	// maybe extracts the mod ID then uses that to find the src file?
};

// 10
class TESReactionForm : public BaseFormComponent
{
public:
	TESReactionForm();
	~TESReactionForm();

	struct Reaction
	{
		enum
		{
			kNeutral = 0,
			kEnemy,
			kAlly,
			kFriend
		};

		TESFaction* faction;
		SInt32		modifier;
		UInt32		reaction;
	};

	tList <Reaction>	reactions;	// 4
	UInt8	unkC;		// C
	UInt8	padD[3];	// D
};

// 08
class TESRaceForm : public BaseFormComponent
{
public:
	TESRaceForm();
	~TESRaceForm();

	TESRace* race;	// 04
};

// 8
// ### derives from NiObject
class BSTextureSet
{
public:
	BSTextureSet();
	~BSTextureSet();

	void* _vtbl;	// 0
	UInt32	unk04;		// 4
};

// C?
class TESSoundFile : public BaseFormComponent
{
public:
	TESSoundFile();
	~TESSoundFile();

	virtual void	Set(const char* str);

	String	path;	// 4
};

// 4+
class BGSQuestObjective
{
public:
	BGSQuestObjective();
	~BGSQuestObjective();

	enum {
		eQObjStatus_displayed = 1,
		eQObjStatus_completed = 2,
	};

	struct TargetData
	{
		TESObjectREFR* target;
		UInt8			flags;
		UInt8			filler[3];
	};

	struct ParentSpaceNode;
	struct TeleportLink
	{
		TESObjectREFR* door;
		UInt32			unk004[3];
	};	// 016

	struct Target
	{
		UInt8							byt000;				// 000
		UInt8							fill[3];			// 001
		tList<Condition>				conditions;			// 004
		TESObjectREFR* target;				// 00C
		BSSimpleArray<ParentSpaceNode>	parentSpaceNodes;	// 010 - The four fields coud be a struct
		BSSimpleArray<TeleportLink>		teleportLinks;		// 020
		UInt32							unk030;				// 030
		UInt32							unk034;				// 034
	};

	UInt32			objectiveId;	// 004 Objective Index in the GECK
	String			displayText;	// 008
	TESQuest* quest;			// 010
	tList<Target*>	targets;		// 014
	UInt32			unk01C;			// 01C
	UInt32			status;			// 020	bit0 = displayed, bit 1 = completed. 1 and 3 significant. If setting it to 3, quest flags bit1 will be set also.

	virtual void* Destroy(bool noDealloc);
};

class BGSOpenCloseForm
{
public:
	virtual void	Unk_00(UInt32 arg0, UInt32 arg1);
	virtual void	Unk_01(UInt32 arg0, UInt32 arg1);
	virtual bool	Unk_02(void);

	BGSOpenCloseForm();
	~BGSOpenCloseForm();
};

/**** forms ****/

class TESTopic;
class TESModelAnim : public TESModel
{
public:
	TESModelAnim();		// Identical to TESModel with a different vTable
	~TESModelAnim();

};	// 018

class TESIdleForm : public TESForm
{
public:
	TESIdleForm();
	~TESIdleForm();

	enum {
		eIFgf_groupIdle = 0,
		eIFgf_groupMovement = 1,
		eIFgf_groupLeftArm = 2,
		eIFgf_groupLeftHand = 3,
		eIFgf_groupLeftWeapon = 4,
		eIFgf_groupLeftWeaponUp = 5,
		eIFgf_groupLeftWeaponDown = 6,
		eIFgf_groupSpecialIdle = 7,
		eIFgf_groupWholeBody = 20,
		eIFgf_groupUpperBody = 20,

		eIFgf_flagOptionallyReturnsAFile = 128,
		eIFgf_flagUnknown = 64,
	};

	struct Data {
		UInt8			groupFlags;		// 000	animation group and other flags
		UInt8			loopMin;		// 001
		UInt8			loopMax;		// 002
		UInt8			fil03B;			// 003
		UInt16			replayDelay;	// 004
		UInt8			flags;			// 006	bit0 is No attacking
		UInt8			fil03F;			// 007
	};

	TESModelAnim		anim;			// 018
	tList<Condition>	conditions;		// 030
	Data				data;			// 038
	UInt32				unk040;			// 040	NiFormArray, contains all idle anims in path if eIFgf_flagUnknown is set
	TESIdleForm* parent;		// 044
	TESIdleForm* previous;		// 048
	String				str04C;			// 04C
};

struct TESTopicInfoResponse
{
	struct Data
	{
		UInt32	emotionType;	//	00
		UInt32	emotionValue;	//	04	Init'd to 0x32
		UInt32	unused;			//	08
		UInt8	responseNumber;	//	0C
		UInt8	pad00D[3];
		UInt32	sound;			//	10
		UInt8	flags;			//	14	Init'd to 1
		UInt8	pad015[3];
	};

	Data			data;					//	000
	String			responseText;			//	018
	TESIdleForm* spkeakerAnimation;		//	020
	TESIdleForm* listenerAnimation;		//	024
	TESTopicInfoResponse* next;			//	028
};

// 50
class TESTopicInfo : public TESForm
{
public:
	TESTopicInfo();
	~TESTopicInfo();

	struct RelatedTopics
	{
		tList<TESTopic>	linkFrom;
		tList<TESTopic>	choices;
		tList<TESTopic>	unknown;
	};

	tList<Condition>	conditions;			// 18
	UInt16				unk20;				// 20
	UInt8				saidOnce;			// 22
	UInt8				type;				// 23
	UInt8				nextSpeaker;		// 24
	UInt8				flags1;				// 25
	UInt8				flags2;				// 26
	UInt8				pad27;				// 27
	String				prompt;				// 28
	tList<TESTopic>		addTopics;			// 30
	RelatedTopics* relatedTopics;		// 38
	TESForm* speaker;			// 3C
	UInt32				actorValueOrPerk;	// 40
	UInt32				speechChallenge;	// 44
	TESQuest* quest;				// 48
	UInt32				modInfoFileOffset;	// 4C	during LoadForm
	void RunResultScript(Actor* actor, bool onEnd);
};

typedef NiTArray<TESTopicInfo*> TopicInfoArray;
typedef void* INFO_LINK_ELEMENT;

// 40
class TESTopic : public TESForm
{
public:
	TESTopic();
	~TESTopic();

	struct Info	//	34
	{
		TESQuest* quest;		//	00
		TopicInfoArray	infoArray;	//	04
		BSSimpleArray<INFO_LINK_ELEMENT>		unk01C;
		TESQuest* quest2;		//	2C
		UInt8			unk030;
		UInt8			pad031[3];
	};

	TESFullName		fullName;	// 18

	UInt8			type;			// 24	DATA
	UInt8			flags;			// 25	DATA also used as bool or flag, connected to INFOGENERAL
	UInt8			pad26[2];		// 26
	float			priority;		// 28	PNAM
	tList<Info>		infos;			// 2C
	String			unk34;			// 34	TDUM
	UInt16			unk3C;			// 3C	XIDX
	UInt16			unk3E;			// 3E
	String			editorIDstr;	// 40

	TESTopicInfo* GetTopicInfo(Actor* actor, Actor* target);
};

STATIC_ASSERT(offsetof(TESTopic, fullName) == 0x018);

// A0
class BGSTextureSet : public TESBoundObject
{
public:
	BGSTextureSet();
	~BGSTextureSet();

	enum	// texture types
	{
		kDiffuse = 0,
		kNormal,
		kEnvMask,
		kGlow,
		kParallax,
		kEnv
	};

	enum
	{
		kTexFlag_NoSpecMap = 0x0001,
	};

	// 24
	struct DecalInfo
	{
		enum
		{
			kFlag_Parallax = 0x01,
			kFlag_AlphaBlend = 0x02,
			kFlag_AlphaTest = 0x04,
		};

		float	minWidth;		// 00
		float	maxWidth;		// 04
		float	minHeight;		// 08
		float	maxHeight;		// 0C
		float	depth;			// 10
		float	shininess;		// 14
		float	parallaxScale;	// 18
		UInt8	parallaxPasses;	// 1C
		UInt8	flags;			// 1D
		UInt8	pad1E[2];		// 1E
		UInt32	color;			// 20
	};

	BSTextureSet	bsTexSet;		// 30

	TESTexture		textures[6];	// 38
	DecalInfo* decalInfo;	// 80
	UInt16			texFlags;		// 84
	UInt8			pad86[2];		// 86
	UInt32			unk88;			// 88
	UInt32			unk8C;			// 8C
	UInt32			unk90;			// 90
	UInt32			unk94;			// 94
	UInt32			unk98;			// 98
	UInt32			unk9C;			// 9C
};

STATIC_ASSERT(sizeof(BGSTextureSet) == 0xA0);

// 24
class BGSMenuIcon : public TESForm
{
public:
	BGSMenuIcon();
	~BGSMenuIcon();

	TESIcon	icon;	// 18
};

STATIC_ASSERT(sizeof(BGSMenuIcon) == 0x24);

// 28
class TESGlobal : public TESForm
{
public:
	TESGlobal();
	~TESGlobal();

	enum
	{
		kType_Short = 's',
		kType_Long = 'l',
		kType_Float = 'f'
	};

	String	name;		// 18
	UInt8	type;		// 20
	UInt8	pad21[3];	// 21
	float	data;		// 24
};

STATIC_ASSERT(sizeof(TESGlobal) == 0x28);

// 60
class TESClass : public TESForm
{
public:
	TESClass();
	~TESClass();

	enum
	{
		kFlag_Playable = 0x00000001,
		kFlag_Guard = 0x00000002,
	};

	enum
	{
		kService_Weapons = 0x00000001,
		kService_Armor = 0x00000002,
		kService_Clothing = 0x00000004,
		kService_Books = 0x00000008,
		kService_Food = 0x00000010,
		kService_Chems = 0x00000020,
		kService_Stimpacks = 0x00000040,
		kService_Lights = 0x00000080,	// ??
		kService_Misc = 0x00000400,
		kService_Potions = 0x00002000,	// probably deprecated
		kService_Training = 0x00004000,
		kService_Recharge = 0x00010000,
		kService_Repair = 0x00020000,
	};

	TESFullName		fullName;		// 18
	TESDescription	description;	// 24
	TESTexture		texture;		// 2C
	TESAttributes	attributes;		// 38

	// corresponds to DATA chunk
	UInt32			tagSkills[4];	// 44
	UInt32			classFlags;		// 54
	UInt32			services;		// 58
	UInt8			teaches;		// 5C
	UInt8			trainingLevel;	// 5D
	UInt8			pad5E[2];		// 5E
};

STATIC_ASSERT(sizeof(TESClass) == 0x60);

class TESReputation : public TESForm
{
public:
	TESReputation();
	~TESReputation();
};

// 4C
class TESFaction : public TESForm
{
public:
	TESFaction();
	~TESFaction();
	enum
	{
		// TESForm flags

		// TESReactionForm flags

		kModified_FactionFlags = 0x00000004
		// CHANGE_FACTION_FLAGS
		// UInt8	flags;
	};

	enum
	{
		kFlag_HiddenFromPC = 0x00000001,
		kFlag_Evil = 0x00000002,
		kFlag_SpecialCombat = 0x00000004,

		kFlag_TrackCrime = 0x00000100,
		kFlag_AllowSell = 0x00000200,
	};

	// 1C
	struct Rank
	{
		String		name;		// 00
		String		femaleName;	// 08
		TESTexture	insignia;	// 10 - effectively unused, can be set but there is no faction UI
	};

	TESFullName		fullName;	// 18
	TESReactionForm	reaction;	// 24

	UInt32			factionFlags;	// 34
	TESReputation* reputation;		// 38
	tList <Rank>	ranks;			// 3C
	UInt32			crimeCount44;	// 44
	UInt32			crimeCount48;	// 48

	bool IsFlagSet(UInt32 flag) {
		return (factionFlags & flag) != 0;
	}
	void SetFlag(UInt32 flag, bool bMod) {
		factionFlags = bMod ? (factionFlags | flag) : (factionFlags & ~flag);
	}
	bool IsHidden()
	{
		return IsFlagSet(kFlag_HiddenFromPC);
	}
	bool IsEvil()
	{
		return IsFlagSet(kFlag_Evil);
	}
	bool HasSpecialCombat()
	{
		return IsFlagSet(kFlag_SpecialCombat);
	}
	void SetHidden(bool bHidden)
	{
		SetFlag(kFlag_HiddenFromPC, bHidden);
	}
	void SetEvil(bool bEvil)
	{
		SetFlag(kFlag_Evil, bEvil);
	}
	void SetSpecialCombat(bool bSpec)
	{
		SetFlag(kFlag_SpecialCombat, bSpec);
	}
	const char* GetNthRankName(UInt32 whichRank, bool bFemale = false);
	void SetNthRankName(const char* newName, UInt32 whichRank, bool bFemale);
};

STATIC_ASSERT(sizeof(TESFaction) == 0x4C);

// 50
class BGSHeadPart : public TESForm
{
public:
	BGSHeadPart();
	~BGSHeadPart();

	enum
	{
		kFlag_Playable = 0x01,
	};

	TESFullName			fullName;	// 18
	TESModelTextureSwap	texSwap;	// 24

	UInt8				headFlags;	// 44
	UInt8				pad45[3];	// 45
	UInt32				unk48;		// 48
	UInt32				unk4C;		// 4C
};

STATIC_ASSERT(sizeof(BGSHeadPart) == 0x50);

// 4C
class TESHair : public TESForm
{
public:
	TESHair();
	~TESHair();

	enum
	{
		kFlag_Playable = 0x01,
		kFlag_NotMale = 0x02,
		kFlag_NotFemale = 0x04,
		kFlag_Fixed = 0x08,
	};

	TESFullName		fullName;	// 18
	TESModel		model;		// 24
	TESTexture		texture;	// 3C

	UInt8			hairFlags;	// 48	Playable, not Male, not Female, Fixed
	UInt8			pad49[3];	// 49
	bool IsPlayable() { return (hairFlags & kFlag_Playable) == kFlag_Playable; }
	void SetPlayable(bool doset) { if (doset) hairFlags |= kFlag_Playable; else hairFlags &= ~kFlag_Playable; }
};

STATIC_ASSERT(sizeof(TESHair) == 0x4C);

// 34
class TESEyes : public TESForm
{
public:
	TESEyes();
	~TESEyes();

	enum
	{
		kFlag_Playable = 0x01,
		kFlag_NotMale = 0x02,
		kFlag_NotFemale = 0x04,
	};

	TESFullName		fullName;	// 18
	TESTexture		texture;	// 24

	UInt8			eyeFlags;	// 30
	UInt8			pad31[3];	// 31
	bool IsPlayable() { return (eyeFlags & kFlag_Playable) == kFlag_Playable; }
	void SetPlayable(bool doset) { if (doset) eyeFlags |= kFlag_Playable; else eyeFlags &= ~kFlag_Playable; }
};

STATIC_ASSERT(sizeof(TESEyes) == 0x34);

// 4E4 - incomplete
class TESRace : public TESForm
{
public:
	// 18
	struct FaceGenData
	{
		UInt32	unk00;
		UInt32	unk04;
		UInt32	unk08;
		UInt32	unk0C;
		UInt32	unk10;
		UInt32	unk14;
	};

	// 2
	struct SkillMod
	{
		UInt8	actorValue;
		SInt8	mod;
	};

	enum
	{
		kFlag_Playable = 0x00000001,
		kFlag_Child = 0x00000004,
	};

	TESRace();
	~TESRace();

	TESFullName		fullName;				// 018
	TESDescription	desc;					// 024
	TESSpellList	spells;					// 02C
	TESReactionForm	reaction;				// 040

	SkillMod		skillMods[7];			// 050
	UInt8			pad05E[2];				// 05E
	float			height[2];				// 060 male/female
	float			weight[2];				// 068 male/female
	UInt32			raceFlags;				// 070

	TESAttributes	baseAttributes[2];		// 074 male/female
	tList<TESHair>	hairs;					// 08C
	TESHair* defaultHair[2];			// 094 male/female
	UInt8			defaultHairColor[2];	// 09C male/female
	UInt8			fill09E[2];				// 09E

	UInt32			unk0A0[(0xA8 - 0xA0) >> 2];	// 0A0

	tList<TESEyes>	eyes;					// 0A8

	TESModel		faceModels[2][8];			// 0B0	male/female Head, Ears, Mouth, TeethLower, TeethUpper, Tongue, LeftEye, RightEye
	TESTexture		faceTextures[2][8];			// 230	male/female Head, Ears, Mouth, TeethLower, TeethUpper, Tongue, LeftEye, RightEye
	TESTexture		bodyPartsTextures[2][3];	// 2F0	male/female	UpperBody, LeftHand, RightHand
	TESModel		bodyModels[2][3];			// 338	male/female	UpperBody, LeftHand, RightHand
	BGSTextureModel	bodyTextures[2];			// 3C8	male/female	EGT file, not DDS.
	FaceGenData		unk3F8[2][4];				// 3F8  male/female

	UInt32			unk4B8[(0x4CC - 0x4B8) >> 2]; // 4B8

	String				name;				// 4CC
	NiTArray <void*>	faceGenUndo;		// 4D4 - NiTPrimitiveArray<FaceGenUndo *>
	UInt32			unk4E4[(0x4FC - 0x4E4) >> 2]; // 4E4
	BGSVoiceType* voiceTypes[2];			// 4FC // VTCK male/female
	TESRace* ageRace[2];				// 504 // ONAM/YNAM
	bool IsPlayable() const { return (raceFlags & kFlag_Playable) == kFlag_Playable; }
	void SetPlayable(bool doset) { if (doset) raceFlags |= kFlag_Playable; else raceFlags &= ~kFlag_Playable; }
};

// 68
class TESSound : public TESBoundAnimObject
{
public:
	TESSound();
	~TESSound();

	enum
	{
		kFlag_RandomFrequencyShift = 1,
		kFlag_PlayAtRandom = 2,
		kFlag_EnvironmentIgnored = 4,
		kFlag_RandomLocation = 8,
		kFlag_Loop = 16,
		kFlag_MenuSound = 32,
		kFlag_2D = 64,
		kFlag_360LFE = 128,
		kFlag_DialogueSound = 256,
		kFlag_EnvelopeFast = 512,
		kFlag_EnvelopeSlow = 1024,
		kFlag_2DRadius = 2048,
		kFlag_MuteWhenSubmerged = 4096,
		kFlag_StartAtRandomPosition = 8192,
	};

	TESSoundFile	soundFile;				// 30

	UInt32			unk3C;					// 3C
	UInt16			unk40;					// 40
	UInt16			unk42;					// 42
	UInt8			minAttenuationDist;		// 44
	UInt8			maxAttenuationDist;		// 45
	SInt16			frequencyAdj;			// 46
	UInt32			soundFlags;				// 48
	UInt16			staticAttenuation;		// 4C
	UInt8			endsAt;					// 4E
	UInt8			startsAt;				// 4F
	UInt16			attenuationCurve[5];	// 50
	UInt16			reverbAttenuation;		// 5A
	UInt32			priority;				// 5C
	UInt32			unk60;					// 60
	UInt32			unk64;					// 64

	void SetFlag(UInt32 pFlag, bool bMod)
	{
		soundFlags = bMod ? (soundFlags | pFlag) : (soundFlags & ~pFlag);
	}
};
STATIC_ASSERT(sizeof(TESSound) == 0x68);

// 3C
class BGSAcousticSpace : public TESBoundObject
{
public:
	BGSAcousticSpace();
	~BGSAcousticSpace();

	UInt32	unk30;	// 30
	UInt32	unk34;	// 34
	UInt32	unk38;	// 38
};

STATIC_ASSERT(sizeof(BGSAcousticSpace) == 0x3C);

// 60
class TESSkill : public TESForm
{
public:
	TESSkill();
	~TESSkill();

	TESDescription	description;	// 18
	TESTexture		texture;		// 20

	UInt32			unk2C;			// 2C
	UInt32			unk30;			// 30
	UInt32			unk34;			// 34
	float			unk38;			// 38
	float			unk3C;			// 3C
	TESDescription	desc2[3];		// 40
	UInt32			unk58[(0x60 - 0x58) >> 2];	// 58
};

STATIC_ASSERT(sizeof(TESSkill) == 0x60);

// B0
class EffectSetting : public TESForm	// MGEF
{
public:
	EffectSetting();
	~EffectSetting();

	enum
	{
		kArchType_ValueModifier = 0,
		kArchType_Script,
		kArchType_Dispel,
		kArchType_CureDisease,
		kArchType_Absorb,
		kArchType_Shield,
		kArchType_Calm,
		kArchType_Demoralize,
		kArchType_Frenzy,
		kArchType_CommandCreature,
		kArchType_CommandHumanoid,
		kArchType_Invisibility,
		kArchType_Chameleon,
		kArchType_Light,
		kArchType_Darkness,
		kArchType_NightEye,
		kArchType_Lock,
		kArchType_Open,
		kArchType_BoundItem,
		kArchType_SummonCreature,
		kArchType_DetectLife,
		kArchType_Telekinesis,
		kArchType_DisintigrateArmor,
		kArchType_DisinitgrateWeapon,
		kArchType_Paralysis,
		kArchType_Reanimate,
		kArchType_SoulTrap,
		kArchType_TurnUndead,
		kArchType_SunDamage,
		kArchType_Vampirism,
		kArchType_CureParalysis,
		kArchType_CureAddiction,
		kArchType_CurePoison,
		kArchType_Concussion,
		kArchType_ValueAndParts,
		kArchType_LimbCondition,
		kArchType_Turbo,
	};

	TESModel			model;					// 18
	TESDescription		description;			// 30
	TESFullName			fullName;				// 38
	TESIcon				icon;					// 44
	UInt32				unk50;					// 50
	UInt32				unk54;					// 54
	UInt32				effectFlags;			// 58 - start of DATA
	float				baseCost;				// 5C
	TESForm* associatedItem;			// 60 - Script* for ScriptEffects
	UInt32				magicSchool;			// 64 - unused
	UInt32				resistVal;				// 68 - actor value for resistance
	UInt16				counterEffectCount;		// 6C - counter effects count
	UInt8				pad6E[2];				// 6E
	TESObjectLIGH* light;					// 70
	float				projectileSpeed;		// 74
	TESEffectShader* effectShader;			// 78 - effect shader
	TESEffectShader* objectDisplayShader;	// 7C
	TESSound* effectSound;			// 80
	TESSound* boltSound;				// 84
	TESSound* hitSound;				// 88
	TESSound* areaSound;				// 8C
	float				unused090;				// 90 - fMagicDefaultCEEnchantFactor
	float				unused094;				// 94 - fMagicDefaultCEBarterFactor
	UInt32				archtype;				// 98
	UInt32				actorVal;				// 9C - actor value - last field of DATA
	tList<EffectSetting>	counterEffects;		// A0 - counter effects list
	UInt32				unkA8;					// A8
	UInt32				unkAC;					// AC

	Script* GetScript() { return 1 == archtype ? (Script*)associatedItem : NULL; };
	bool HasScript() { return 1 == archtype ? true : false; };
	Script* RemoveScript();
	Script* SetScript(Script* newScript);
};

STATIC_ASSERT(sizeof(EffectSetting) == 0xB0);

class TESChallenge : public TESForm
{
public:
	TESChallenge();
	~TESChallenge();

	enum challengeFlags	//
	{
		kFlag_StartDisabled = 1 << 0,
		kFlag_Recurring = 1 << 1,
		kFlag_ShowZeroProgress = 1 << 2
	};

	struct challengeData	// 018
	{
		UInt32		type;			// needs enumeration
		UInt32		threshold;
		UInt32		flags;
		UInt32		interval;
		UInt16		value1;			// these fields change based on challenge type
		UInt16		value2;			// might need unions...
		UInt32		value3;
	};

	TESFullName				fullName;		// 018
	TESDescription			description;	// 024
	TESIcon					icon;			// 02C
	TESScriptableForm		scriptable;		// 038
	UInt32					unk044[4];		// 044
	challengeData			data;			// 054 //
	TESForm* SNAM;			// 06C // depends on type
	TESForm* XNAM;			// 070 // depends on type
};

// 68
class TESGrass : public TESBoundObject
{
public:
	TESGrass();
	~TESGrass();

	TESModel		model;					// 30

	UInt8			density;				// 48
	UInt8			minSlope;				// 49
	UInt8			maxSlope;				// 4A
	UInt8			pad4B;					// 4B
	UInt16			unitFromWaterAmount;	// 4C
	UInt8			pad4E[2];				// 4E
	UInt8			unitFromWaterType;		// 50
	UInt8			pad51[3];				// 51
	float			positionRange;			// 54
	float			heightRange;			// 58
	float			colorRange;				// 5C
	float			wavePeriod;				// 60
	UInt8			flags;					// 64
	UInt8			pad65[3];				// 65
};

STATIC_ASSERT(sizeof(TESGrass) == 0x68);

// 28
class TESLandTexture : public TESForm
{
public:
	TESLandTexture();
	~TESLandTexture();

	BGSTextureSet* textureSet;		// 18
	UInt8			materialType;		// 1C
	UInt8			friction;			// 1D
	UInt8			restitution;		// 1E
	UInt8			specularExponent;	// 1F
	tList<TESGrass>	grasses;			// 20

	SInt32	GetGrassIndex(TESGrass* grass);
};
STATIC_ASSERT(sizeof(TESLandTexture) == 0x28);

// 44
class EnchantmentItem : public MagicItemForm
{
public:
	EnchantmentItem();
	~EnchantmentItem();

	virtual void	ByteSwap(void);

	enum
	{
		kType_Weapon = 2,
		kType_Apparel,
	};

	UInt32		type;		// 34
	UInt32		unk38;		// 38
	UInt32		unk3C;		// 3C
	UInt8		enchFlags;	// 40
	UInt8		pad41[3];	// 41
};

STATIC_ASSERT(offsetof(EnchantmentItem, type) == 0x34);
STATIC_ASSERT(sizeof(EnchantmentItem) == 0x44);

// 44
class SpellItem : public MagicItemForm
{
public:
	SpellItem();
	~SpellItem();

	virtual void	ByteSwap(void);

	enum
	{
		kType_ActorEffect = 0,
		kType_Disease,
		kType_Power,
		kType_LesserPower,
		kType_Ability,
		kType_Poison,
		kType_Addiction = 10,
	};

	UInt32		type;		// 34
	UInt32	unk38;		// 38	Cost Unused
	UInt32	unk3C;		// 3C	Level Unused
	UInt8		spellFlags;	// 40
	UInt8	pad41[3];	// 41
};

STATIC_ASSERT(sizeof(SpellItem) == 0x44);

class BGSTalkingActivator;

// TESObjectACTI (84)
class TESObjectACTI : public TESBoundAnimObject
{
public:
	TESObjectACTI();
	~TESObjectACTI();

	// bases
	TESFullName					fullName;			// 30
	TESModelTextureSwap			modelTextureSwap;	// 3C
	TESScriptableForm			scriptable;			// 5C
	BGSDestructibleObjectForm	destructible;		// 68
	BGSOpenCloseForm			openClose;			// 70

	TESSound* loopingSound;		// 74	SNAM
	TESSound* activationSound;	// 78	VNAM
	TESSound* radioTemplate;		// 7C	INAM
	TESWaterForm* waterType;			// 80	WNAM 
	BGSTalkingActivator* radioStation;		// 84	RNAM
	String						activationPrompt;	// 88	XATO
};

STATIC_ASSERT(sizeof(TESObjectACTI) == 0x90);

// BGSTalkingActivator (8C)
class BGSTalkingActivator : public TESObjectACTI
{
public:
	BGSTalkingActivator();
	~BGSTalkingActivator();

	BGSVoiceType* voiceType;			// 94
};

class BGSNote;

// BGSTerminal (9C)
class BGSTerminal : public TESObjectACTI
{
public:
	BGSTerminal();
	~BGSTerminal();

	enum
	{
		kTerminalFlagLeveled = 1 << 0,
		kTerminalFlagUnlocked = 1 << 1,
		kTerminalFlagAltColors = 1 << 2,
		kTerminalFlagHideWelcome = 1 << 3,
	};

	enum
	{
		kEntryFlagAddNote = 1 << 0,
		kEntryFlagForceRedraw = 1 << 1,
	};

	struct TermData
	{
		UInt8 difficulty;       // 0: very easy, 1: easy, 2: average, 3: hard, 4: very hard, 5: requires key
		UInt8 terminalFlags;
		UInt8 type;             // 0-9, corresponds to GECK types 1-10
	};

	struct MenuEntry
	{
		String				entryText;
		String				resultText;
		UInt8				entryFlags;
		BGSNote* displayNote;
		BGSTerminal* subMenu;
		ScriptEventList* scriptEventList;
		tList<Condition*>	conditions;
	};

	String				desc;			// 090	DESC
	tList<MenuEntry>	menuEntries;	// 098
	BGSNote* password;		// 0A0	PNAM
	TermData			data;			// 0A4	DNAM
};

// 180
class TESObjectARMO : public TESBoundObject
{
public:
	TESObjectARMO();
	~TESObjectARMO();

	// children
	TESFullName					fullName;				// 030
	TESScriptableForm			scriptable;				// 03C
	TESEnchantableForm			enchantable;			// 048
	TESValueForm				value;					// 058
	TESWeightForm				weight;					// 060
	TESHealthForm				health;					// 068
	TESBipedModelForm			bipedModel;				// 070
	BGSDestructibleObjectForm	destuctible;			// 14C
	BGSEquipType				equipType;				// 154
	BGSRepairItemList			repairItemList;			// 15C
	BGSBipedModelList			bipedModelList; 		// 164
	BGSPickupPutdownSounds		pickupPutdownSounds;	// 16C
	UInt16						armorRating;			// 178
	UInt16						modifiesVoice;			// 17A
	float						damageThreshold;		// 17C
	UInt32						armorFlags;				// 180
	//BGSCameraPath				*cameraPath;			// 184 ?? need to figure out wtf this is
	//UInt32					unk184[3];				// 184 ??
	// 180
};
//STATIC_ASSERT(sizeof(TESObjectARMO) == 0x188);	// this appears to be wrong...
STATIC_ASSERT(offsetof(TESObjectARMO, damageThreshold) == 0x17C);

// C4
class TESObjectBOOK : public TESBoundObject
{
public:
	TESObjectBOOK();
	~TESObjectBOOK();

	TESFullName					fullName;		// 30
	TESModelTextureSwap			model;			// 3C
	TESIcon						icon;			// 5C
	TESScriptableForm			scriptable;		// 68
	TESEnchantableForm			enchantable;	// 74
	TESValueForm				value;			// 84
	TESWeightForm				weight;			// 8C
	TESDescription				description;	// 94
	BGSDestructibleObjectForm	destuctible;	// 9C
	BGSMessageIcon				messageIcon;	// A4
	BGSPickupPutdownSounds		sounds;			// B4

	UInt32						unkC0;			// C0
};
STATIC_ASSERT(sizeof(TESObjectBOOK) == 0xC4);


// 154
class TESObjectCLOT : public TESBoundObject
{
public:
	TESObjectCLOT();
	~TESObjectCLOT();

	// bases
	TESFullName					fullName;		// 030
	TESScriptableForm			scriptable;		// 03C
	TESEnchantableForm			enchantable;	// 048
	TESValueForm				value;			// 058
	TESWeightForm				weight;			// 060
	TESBipedModelForm			bipedModel;		// 068
	BGSDestructibleObjectForm	destuctible;	// 144
	BGSEquipType				equipType;		// 14C
	// unk data
};

// TESObjectCONT (9C / D4)
class TESObjectCONT : public TESBoundAnimObject
{
public:
	TESObjectCONT();
	~TESObjectCONT();

	TESContainer                container;          // 30
	TESFullName					name;				// 3C
	TESModelTextureSwap			model;				// 48
	TESScriptableForm			scriptForm;			// 68
	TESWeightForm				weightForm;			// 74
	//	TESMagicCasterForm			magicCaster;		// 
	//	TESMagicTargetForm			magicTarget;		// 
	BGSDestructibleObjectForm	destructForm;		// 7C
	BGSOpenCloseForm			openCloseForm;		// 84 / B8
	UInt32						padding;			// offsets below were off 4 bytes

	TESSound* openSound;						// 08C
	TESSound* closeSound;						// 090
	TESSound* randomLoopingSound;				// 094
	UInt8		flags;								// 098
	UInt8		pad099[3];
};

// TESObjectDOOR (90)
class TESObjectDOOR : public TESBoundAnimObject
{
public:
	TESObjectDOOR();
	~TESObjectDOOR();

	enum flags
	{
		doorFlag_Automatic = 0x02,
		doorFlag_Hidden = 0x04,
		doorFlag_MinimalUse = 0x08,
		doorFlag_SlidingDoor = 0x10,
	};

	TESFullName					name;				// 30
	TESModelTextureSwap			model;				// 3C
	TESScriptableForm			scriptForm;			// 5C
	//	TESMagicCasterForm			magicCaster;		// 
	//	TESMagicTargetForm			magicTarget;		// 
	BGSDestructibleObjectForm	destructForm;		// 68
	BGSOpenCloseForm			openCloseForm;		// 70
	TESSound* soundLooping;		//
	// There is a tList in 088 (likely TESObjectCELL, but unused in Fallout)
};

// IngredientItem (A4)
class IngredientItem;

// TESObjectLIGH (C8)
class TESObjectLIGH : public TESBoundAnimObject
{
public:
	TESObjectLIGH();
	~TESObjectLIGH();

	enum
	{
		kFlag_Dynamic = 1,
		kFlag_CanBeCarried = 2,
		kFlag_Negative = 4,
		kFlag_Flicker = 8,
		kFlag_Unused = 16,
		kFlag_OffByDefault = 32,
		kFlag_FlickerSlow = 64,
		kFlag_Pulse = 128,
		kFlag_PulseSlow = 256,
		kFlag_SpotLight = 512,
		kFlag_SpotShadow = 1024,
	};

	TESFullName					fullName;		// 030
	TESModelTextureSwap			modelSwap;		// 03C
	TESIcon						icon;			// 05C
	BGSMessageIcon				messageIcon;	// 068
	TESScriptableForm			scriptable;		// 078
	TESWeightForm				weight;			// 084
	TESValueForm				value;			// 08C
	BGSDestructibleObjectForm	destructible;	// 094

	SInt32						time;			// 09C
	UInt32						radius;			// 0A0
	UInt8						red;			// 0A4
	UInt8						green;			// 0A5
	UInt8						blue;			// 0A6
	UInt8						padA7;			// 0A7
	UInt32						lightFlags;		// 0A8
	float						falloffExp;		// 0AC
	float						FOV;			// 0B0
	float						fadeValue;		// 0B4
	TESSound* sound;			// 0B8
	UInt32						padBC[3];		// 0BC

	void SetFlag(UInt32 pFlag, bool bMod)
	{
		lightFlags = bMod ? (lightFlags | pFlag) : (lightFlags & ~pFlag);
	}
};
STATIC_ASSERT(sizeof(TESObjectLIGH) == 0x0C8);

// TESObjectMISC (A8)
class TESObjectMISC : public TESBoundObject
{
public:
	TESObjectMISC();
	~TESObjectMISC();

	//UInt32	unk30[30];
	TESFullName fullName;
	TESModelTextureSwap model;

};

// 50
class TESObjectSTAT : public TESBoundObject
{
public:
	TESObjectSTAT();
	~TESObjectSTAT();

	// children
	TESModel	model;	// 
};

// BGSStaticCollection (50)
class BGSStaticCollection;

// BGSMovableStatic (6C)
class BGSMovableStatic;

// BGSPlaceableWater (50)
class BGSPlaceableWater : public TESBoundObject
{
public:
	BGSPlaceableWater();
	~BGSPlaceableWater();

	TESModel			model;	// 030
	UInt32				flags;	// 048
	TESWaterForm* water;	// 04C
};

// TESObjectTREE (94)
class TESObjectTREE;

// TESFlora (90)
class TESFlora;

// TESFurniture (88)
class TESFurniture;

class TESObjectIMOD : public TESBoundObject
{
public:
	TESObjectIMOD();
	~TESObjectIMOD();

	// bases
	TESFullName					name;				// 030
	TESModelTextureSwap			model;				// 03C
	TESIcon						icon;				// 05C
	TESScriptableForm			scriptForm;			// 068
	TESDescription				description;		// 074
	TESValueForm				value;				// 07C
	TESWeightForm				weight;				// 084
	BGSDestructibleObjectForm	destructible;		// 08C
	BGSMessageIcon				messageIcon;		// 094
	BGSPickupPutdownSounds		pickupPutdownSounds;// 0A4
};

// 388
class TESObjectWEAP : public TESBoundObject
{
public:
	TESObjectWEAP();
	~TESObjectWEAP();

	enum EWeaponType {
		kWeapType_HandToHandMelee = 0,
		kWeapType_OneHandMelee,
		kWeapType_TwoHandMelee,
		kWeapType_OneHandPistol,
		kWeapType_OneHandPistolEnergy,
		kWeapType_TwoHandRifle,
		kWeapType_TwoHandAutomatic,
		kWeapType_TwoHandRifleEnergy,
		kWeapType_TwoHandHandle,
		kWeapType_TwoHandLauncher,
		kWeapType_OneHandGrenade,
		kWeapType_OneHandMine,
		kWeapType_OneHandLunchboxMine,
		kWeapType_OneHandThrown,
		kWeapType_Last	// During animation analysis, player weapon can be classified as 0x0C = last
	};

	enum EWeaponSounds {
		kWeapSound_Shoot3D = 0,
		kWeapSound_Shoot2D,
		kWeapSound_Shoot3DLooping,
		kWeapSound_NoAmmo,
		kWeapSound_Swing = kWeapSound_NoAmmo,
		kWeapSound_Block,
		kWeapSound_Idle,
		kWeapSound_Equip,
		kWeapSound_Unequip
	};

	enum EHandGrip {
		eHandGrip_Default = 0xFF,
		eHandGrip_1 = 0xE6,
		eHandGrip_2 = 0xE7,
		eHandGrip_3 = 0xE8,
		eHandGrip_4 = 0xE9,
		eHandGrip_5 = 0xEA,
		eHandGrip_6 = 0xEB,
		eHandGrip_Count = 7,
	};

	enum EAttackAnimations {
		eAttackAnim_Default = 0xff,	// 11111111
		eAttackAnim_Attack3 = 0x26,	// 00100110
		eAttackAnim_Attack4 = 0x2c, // 00101100
		eAttackAnim_Attack5 = 0x32,	// 00110010
		eAttackAnim_Attack6 = 0x38, // 
		eAttackAnim_Attack7 = 0x3e,
		eAttackAnim_Attack8 = 0x44,
		eAttackAnim_AttackLeft = 0x1a,
		eAttackAnim_AttackLoop = 0x4a,
		eAttackAnim_AttackRight = 0x20,
		eAttackAnim_AttackSpin = 0x50,
		eAttackAnim_AttackSpin2 = 0x56,
		eAttackAnim_AttackThrow = 0x6d,
		eAttackAnim_AttackThrow2 = 0x73,
		eAttackAnim_AttackThrow3 = 0x79,
		eAttackAnim_AttackThrow4 = 0x7F,
		eAttackAnim_AttackThrow5 = 0x85,
		eAttackAnim_PlaceMine = 0x61,
		eAttackAnim_PlaceMine2 = 0x67,
		eAttackAnim_Count = 19,
	};

	enum ReloadAnim {
		eReload_A = 0,
		eReload_B,
		eReload_C,
		eReload_D,
		eReload_E,
		eReload_F,
		eReload_G,
		eReload_H,
		eReload_I,
		eReload_J,
		eReload_K,
		eReload_L,
		eReload_M,
		eReload_N,
		eReload_O,
		eReload_P,
		eReload_Q,
		eReload_R,
		eReload_S,
		eReload_W,
		eReload_X,
		eReload_Y,
		eReload_Z,
		eReload_Count,
	};
	STATIC_ASSERT(eReload_Count == 23);

	enum EWeaponFlags1 {
		eFlag_IgnoresNormalWeapResist = 0x1,
		eFlag_IsAutomatic = 0x2,
		eFlag_HasScope = 0x4,
		eFlag_CantDrop = 0x8,
		eFlag_HideBackpack = 0x10,
		eFlag_EmbeddedWeapon = 0x20,
		eFlag_No1stPersonISAnims = 0x40,
		Eflag_NonPlayable = 0x80
	};

	enum EWeaponFlags2 {
		eFlag_PlayerOnly = 0x1,
		eFlag_NPCsUseAmmo = 0x2,
		eFlag_NoJamAfterReload = 0x4,
		eFlag_ActionPointOverride = 0x8,
		eFlag_MinorCrime = 0x10,
		eFlag_FixedRange = 0x20,
		eFlag_NotUsedNormalCombat = 0x40,
		eFlag_DamageToWeaponOverride = 0x80,
		eFlag_No3rdPersonISAnims = 0x100,
		eFlag_BurstShot = 0x200,
		eFlag_RumbleAlternate = 0x400,
		eFlag_LongBurst = 0x800,
	};

	enum EEmbedWeapAV {
		eEmbedAV_Perception = 0,
		eEmbedAV_Endurance,
		eEmbedAV_LeftAttack,
		eEmbedAV_RightAttack,
		eEmbedAV_LeftMobility,
		eEmbedAV_RightMobility,
		eEmbedAV_Brain,
	};

	enum EOnHit {
		eOnHit_Normal = 0,
		eOnHit_DismemberOnly,
		eOnHit_ExplodeOnly,
		eOnHit_NoDismemberOrExplode,
	};

	enum ERumblePattern {
		eRumblePattern_Constant = 0,
		eRumblePattern_Square,
		eRumblePattern_Triangle,
		eRumblePattern_Sawtooth
	};

	enum ECritDamageFlags {
		eCritDamage_OnDeath = 0x1
	};

	enum
	{
		kWeaponModEffect_None = 0,
		kWeaponModEffect_IncreaseDamage,
		kWeaponModEffect_IncreaseClipCapacity,
		kWeaponModEffect_DecreaseSpread,
		kWeaponModEffect_DecreaseWeight,
		kWeaponModEffect_Unused05,
		kWeaponModEffect_RegenerateAmmo,
		kWeaponModEffect_DecreaseEquipTime,
		kWeaponModEffect_IncreaseRateOfFire,		// 8
		kWeaponModEffect_IncreaseProjectileSpeed,
		kWeaponModEffect_IncreaseMaxCondition,
		kWeaponModEffect_Silence,
		kWeaponModEffect_SplitBeam,
		kWeaponModEffect_VATSBonus,
		kWeaponModEffect_IncreaseZoom,				// 14
	};

	// bases
	TESFullName					fullName;			// 030
	TESModelTextureSwap			textureSwap;		// 03C
	TESIcon						icon;				// 05C
	TESScriptableForm			scritpable;			// 068
	TESEnchantableForm			enchantable;		// 074
	TESValueForm				value;				// 084
	TESWeightForm				weight;				// 08C
	TESHealthForm				health;				// 094
	TESAttackDamageForm			attackDmg;			// 09C
	BGSAmmoForm					ammo;				// 0A4
	BGSClipRoundsForm			clipRounds;			// 0AC
	BGSDestructibleObjectForm	destructible;		// 0B4
	BGSRepairItemList			repairItemList;		// 0BC
	BGSEquipType				equipType;			// 0C4
	BGSPreloadable				preloadable;		// 0CC
	BGSMessageIcon				messageIcon;		// 0D0
	BGSBipedModelList			bipedModelList;		// 0E0
	BGSPickupPutdownSounds		pickupPutdownSounds;// 0E8

	UInt8				eWeaponType;		// 0F4
	UInt8				pad[3];
	float				animMult;			// 0F8
	float				reach;				// 0FC
	Bitfield8			weaponFlags1;		// 100
	UInt8				handGrip;			// 101
	UInt8				ammoUse;			// 102
	UInt8				reloadAnim;			// 103
	float				minSpread;			// 104
	float				spread;				// 108
	UInt32				unk10C;				// 10C
	float				sightFOV;			// 110
	UInt32				unk114;				// 114
	BGSProjectile* projectile;		// 118
	UInt8				baseVATSChance;		// 11C
	UInt8				attackAnim;			// 11D
	UInt8				numProjectiles;		// 11E
	UInt8				embedWeaponAV;		// 11F
	float				minRange;			// 120
	float				maxRange;			// 124
	UInt32				onHit;				// 128
	Bitfield32			weaponFlags2;		// 12C
	float				animAttackMult;		// 130
	float				fireRate;			// 134
	float				AP;					// 138
	float				rumbleLeftMotor;	// 13C
	float				rumbleRightMotor;	// 140
	float				rumbleDuration;		// 144
	float				damageToWeaponMult;	// 148
	float				animShotsPerSec;	// 14C
	float				animReloadTime;		// 150
	float				animJamTime;		// 154		
	float				aimArc;				// 158
	UInt32				weaponSkill;		// 15C - actor value
	UInt32				rumblePattern;		// 160 - reload anim?
	float				rumbleWavelength;	// 164
	float				limbDamageMult;		// 168
	UInt32				resistType;			// 16c - actor value
	float				sightUsage;			// 170
	float				semiAutoFireDelayMin;	// 174
	float				semiAutoFireDelayMax;	// 178
	UInt32				unk17C;				// 17C - 0-0x10: 0x8:str req 0x10: - skill req  - 0xb:kill impulse B158 - mod 1 val B15C - Mod 2 val Effects: 0x1: e(zoom) 0x2: a 0x3:0 0x4-6: Values c-e Mod Effects Val2:1-3 
	UInt32				effectMods[3];		// 180
	float				value1Mod[3];		// 18C
	UInt32				powerAttackAnimOverride;	// 198
	UInt32				strRequired;		// 19C
	UInt8				unk1A0;				// 1A0
	UInt8				modReloadAnim;		// 1A1
	UInt8				pad1A2[2];			// 1A2
	float				regenRate;			// 1A4
	float				killImpulse;		// 1A8
	float				value2Mod[3];		// 1AC
	float				impulseDist;		// 1B8
	UInt32				skillRequirement;	// 1BC
	UInt32				criticalDamage;		// 1C0
	float				criticalPercent;	// 1C4
	UInt8				critDamageFlags;	// 1C8
	UInt8				pad1C9[3];			// 1C9
	SpellItem* criticalEffect;	// 1CC
	TESModel			shellCasingModel;	// 1DO
	TESModel			targetNIF;			// 1E8 - target NIF
	TESModel			model200;			// 200 - could be a texture swap
	UInt32				unk218;				// 218
	TESSound* sounds[12];		// 21C
	BGSImpactDataSet* impactDataSet;	// 24C
	TESObjectSTAT* worldStatic;		// 250
	TESObjectSTAT* mod1Static;		// 254
	TESObjectSTAT* mod2Static;		// 258
	TESObjectSTAT* mod3Static;		// 25C
	TESObjectSTAT* mod12Static;		// 260
	TESObjectSTAT* mod13Static;		// 264
	TESObjectSTAT* mod23Static;		// 268
	TESObjectSTAT* mod123Static;		// 26C
	TESModelTextureSwap	textureMod1;		// 270 Mod 1
	TESModelTextureSwap	textureMod2;		// 290 Mod 2
	TESModelTextureSwap	textureMod3;		// 2B0 Mod 3
	TESModelTextureSwap	textureMod12;		// 2D0 Mod 1-2
	TESModelTextureSwap	textureMod13;		// 2F0 Model 1-3
	TESModelTextureSwap	textureMod23;		// 310 Model 2-3
	TESModelTextureSwap	textureMod123;		// 330 Model 1-2-3
	TESObjectIMOD* itemMod1;			// 350
	TESObjectIMOD* itemMod2;			// 354
	TESObjectIMOD* itemMod3;			// 358
	String				embeddedNodeName;	// 35C
	UInt32				soundLevel;			// 364
	UInt32				unk368;				// 368
	UInt32				unk36C;				// 36C
	SpellItem* VATSEffect;		// 370
	UInt32				unk374;				// 374
	UInt32				unk378;				// 378
	UInt32				unk37C;				// 37C
	UInt32				recharge;			// 380 maybe recharge
	UInt8				unk384;				// 384
	UInt8				unk385[3];			// 385


	bool IsAutomatic() const { return weaponFlags1.IsSet(eFlag_IsAutomatic); }
	void SetIsAutomatic(bool bAuto) { weaponFlags1.Write(eFlag_IsAutomatic, bAuto); }
	bool HasScope() const { return weaponFlags1.IsSet(eFlag_HasScope); }
	bool IsNonPlayable() { return weaponFlags1.IsSet(0x80); }
	bool IsPlayable() { return !IsNonPlayable(); }
	void SetPlayable(bool doset) { weaponFlags1.Write(Eflag_NonPlayable, !doset); }
	UInt8 HandGrip() const;
	void SetHandGrip(UInt8 handGrip);
	UInt8 AttackAnimation() const;
	void SetAttackAnimation(UInt8 attackAnim);
	TESObjectIMOD* GetItemMod(UInt8 which);
	UInt32 GetItemModEffect(UInt8 which) { which -= 1; ASSERT(which < 3); return effectMods[which]; }
	float GetItemModValue1(UInt8 which) { which -= 1; ASSERT(which < 3); return value1Mod[which]; }
	float GetItemModValue2(UInt8 which) { which -= 1; ASSERT(which < 3); return value2Mod[which]; }
	bool IsThrown() { return ThisCall<bool>(0x529D90, this); }
};

STATIC_ASSERT(offsetof(TESObjectWEAP, fullName) == 0x030);
STATIC_ASSERT(offsetof(TESObjectWEAP, icon) == 0x5C);
STATIC_ASSERT(offsetof(TESObjectWEAP, ammo) == 0xA4);
STATIC_ASSERT(offsetof(TESObjectWEAP, handGrip) == 0x101);
STATIC_ASSERT(offsetof(TESObjectWEAP, projectile) == 0x118);
STATIC_ASSERT(offsetof(TESObjectWEAP, animShotsPerSec) == 0x14C);
STATIC_ASSERT(offsetof(TESObjectWEAP, impactDataSet) == 0x24C);
STATIC_ASSERT(sizeof(TESObjectWEAP) == 0x388);

class TESAmmoEffect : public TESForm
{
public:
	TESAmmoEffect();
	~TESAmmoEffect();

	enum
	{
		kEffectType_DamageMod = 0,
		kEffectType_DRMod = 1,
		kEffectType_DTMod = 2,
		kEffectType_SpreadMod = 3,
		kEffectType_ConditionMod = 4,
		kEffectType_FatigueMod = 5,
	};

	enum
	{
		kOperation_Add = 0,
		kOperation_Multiply = 1,
		kOperation_Subtract = 2,
	};

	TESFullName		fullName;	// 018	
	UInt32			type;		// 024
	UInt32			operation;	// 028
	float			value;		// 02C
};
STATIC_ASSERT(sizeof(TESAmmoEffect) == 0x30);

// DC
class TESAmmo : public TESBoundObject
{
public:
	TESAmmo();
	~TESAmmo();

	enum eAmmoFlags
	{
		kFlags_IgnoreWeapResistance = 1,
		kFlags_NonPlayable = 2,
	};

	// bases
	TESFullName					fullName;				// 030
	TESModelTextureSwap			model;					// 03C
	TESIcon						icon;					// 05C
	BGSMessageIcon				messageIcon;			// 068	
	TESValueForm				value;					// 078
	BGSClipRoundsForm			clipRounds;				// 080
	BGSDestructibleObjectForm	destructible;			// 088
	BGSPickupPutdownSounds		pickupPutdownsounds;	// 090
	TESScriptableForm			scriptable;				// 09C

	float						speed;					// 0A8	8 bytes makes it DATA
	UInt32						flags;					// 0AC	only 8 bits most likely. 0 is Ignores Normal Weapon Resistance', 1 is Non-Playable
	UInt32						projPerShot;			// 0B0
	BGSProjectile* projectile;			// 0B4
	float						weight;					// 0B8
	TESObjectMISC* casing;				// 0BC
	float						ammoPercentConsumed;	// 0C0
	String						shortName;				// 0C4
	String						abbreviation;			// 0CC
	tList<TESAmmoEffect>		effectList;				// 0D4

	bool IsNonPlayable() { return (flags & kFlags_NonPlayable) == kFlags_NonPlayable; }
	bool IsPlayable() { return !IsNonPlayable(); }
	void SetPlayable(bool doset) { if (doset) flags &= ~kFlags_NonPlayable; else flags |= kFlags_NonPlayable; }
	SInt32 GetEffectIndex(TESAmmoEffect* effect);
};

STATIC_ASSERT(sizeof(TESAmmo) == 0xDC);
class TESCaravanCard : public TESBoundObject
{
public:
	TESCaravanCard();
	~TESCaravanCard();
};

class BSFaceGenNiNode;

// 02B4
struct ValidBip01Names {	// somehow descend from NiNodeArray
	enum eOptionalBoneType {
		kOptionalBone_Bip01Head = 0,
		kOptionalBone_Weapon = 1,
		kOptionalBone_Bip01LForeTwist = 2,
		kOptionalBone_Bip01Spine2 = 3,
		kOptionalBone_Bip01Neck1 = 4,
	};

	// 008
	struct OptionalBone
	{
		bool	exists;
		NiNode* bone;
	};

	// 010
	struct Data
	{
		TESForm* model;	// 000 can be a modelled form (Armor or Weapon) or a Race if not equipped
		TESModel* texture;	// 004 texture or model for said form
		NiNode* bones;	// 008 NiNode for the modelled form
		UInt32		unk00C;		// 00C Number , bool or flag
	};

	NiNode* bip01;		// 000 receive Bip01 node, then optionally Bip01Head, Weapon, Bip01LForeTwist, Bip01Spine2, Bip01Neck1
	OptionalBone	bones[5];		// 004
	Data			unk002C[20];	// 02C indexed by the EquipSlot
	Data			unk016C[20];	// 16C indexed by the EquipSlot
	Character* character;	// 2B0

	MEMBER_FN_PREFIX(ValidBip01Names);
#if RUNTIME_VERSION == RUNTIME_VERSION_1_4_0_525
	DEFINE_MEMBER_FN(Destroy, bool, 0x00418E00, ValidBip01Names*, bool);	// Destoy and optionally free the structure/class
#elif RUNTIME_VERSION == RUNTIME_VERSION_1_4_0_525ng
	DEFINE_MEMBER_FN(Destroy, bool, 0x00418C60, ValidBip01Names*, bool);	// Destoy and optionally free the structure/class
#elif EDITOR
#else
#error
#endif
};

// 1EC
class TESNPC : public TESActorBase
{
public:
	TESNPC();
	~TESNPC();

	enum eFaceGenDataType {
		kFaceGenData_GeometrySymetric = 0,
		kFaceGenData_GeometryAsymetric = 0,
		kFaceGenData_TextureSymetric = 0,

	};

	// 20 - facegen data
	struct Data
	{
		void* unk000;
		void* unk004;	// used as this owning unk000.
		UInt32	unk008;
		void* unk00C;	// the last three looks a lot like an array.
		UInt32	unk010;
		UInt32	unk014;
		UInt32 unk018[(0x058 - 0x018) >> 2];	// used as an array of 88 bytes
	};	// the owner of the array is FaceGenData::Unk008

	struct FaceGenData
	{						// sample Sunny Smiles
		UInt32	unk00;		// 000 134 filled		filled			filled
		void* unk04;	// 004 138 null			null			null
		UInt32	unk08;		// 008 13C null			null			null
		float** values;	// 00C 140 filled		filled			filled			base for offset to data. Looks like an array of arrays.
		UInt32	useOffset;	// 010 144 filled +0xC8	filled +0x78	filled +0xC8	participate in array base calculation
		UInt32	maxOffset;	// 014 148 = unk144		= unk144		= unk144
		UInt32  count;		// 018 14C 0x32			0x1e			0x32
		UInt32  size;		// 01C 150 0x01			0x01			0x01			also participate in array offset calculation (offset = count * size)
	};

	TESRaceForm	race;							// 10C/140
	UInt8		skillValues[0x0E];				// 114/148
	UInt8		skillOffsets[0x0E];				// 122
	TESClass* classID;						// 130/164
	FaceGenData	faceGenData[3];					// 134/180	runtime suggests there are 2 arrays of 2 FaceGenData. the last one being null.
	UInt32		pad194[(0x1A4 - 0x194) >> 2];		// 194
	UInt32		unk1A4;
	UInt32		unk1A8;
	UInt32		unk1AC;
	UInt32		unk1B0;							// 1B0
	void* unk1B4;						// 1B4	pointer to 84 bytes struct related to Face, can be returned instead of faceGenData so identical or at least starts the same ?
	TESHair* hair;							// 1B8/1EC
	float		hairLength;						// 1BC/1F0
	TESEyes* eyes;							// 1C0/1F4
	BSFaceGenNiNode* unk1C4;					// 1C4
	BSFaceGenNiNode* unk1C8;					// 1C8
	UInt32		unk1CC;							// 1CC
	UInt16		unk1D0;							// 1D0
	UInt16		unk1D2;							// 1D2
	TESCombatStyle* combatStyle;				// 1D4
	UInt32		hairColor;						// 1D8/20C
	tList<BGSHeadPart>	headPart;				// 1DC/210
	UInt32		impactMaterialType;				// 1E4/218
	UInt32      unk01E8;						// 1E8
	TESRace* race1EC;						// 1EC
	TESNPC* copyFrom;						// 1F0		not set once PlayerRef exists and the target is the Player
	float		height;							// 1F4/21C
	float		weight;							// 1F8/220 Aparently, getWeight purposly returns height except for the player.
	NiTArray <FaceGenUndo*>	faceGenUndo;	// 1FC
};

STATIC_ASSERT(sizeof(TESNPC) == 0x20C);

// 160
class TESCreature : public TESActorBase
{
public:
	TESCreature();
	~TESCreature();

	TESAttackDamageForm			attackDmg;		// 10C
	TESModelList				modelList;		// 114

	// data
	TESCreature* creatureTemplate;	// 128
	UInt8						type;				// 12C
	UInt8						combatSkill;		// 12D
	UInt8						magicSkill;			// 12E
	UInt8						stealthSkill;		// 12F
	UInt8						attackReach;		// 130
	UInt8						pad0131[3];			// 131
	float						turningSpeed;		// 134
	float						footWeight;			// 138
	float						baseScale;			// 13C
	TESCombatStyle* combatStyle;		// 140
	BGSBodyPartData* bodyPartData;		// 144
	UInt32						materialType;		// 148
	BGSImpactDataSet* impactDataSet;		// 14C
	UInt32						unk0150;			// 150
	UInt32						soundLevel;			// 154
	BGSListForm* meleeWeaponList;	// 158
	UInt8						byt015C;			// 15C
	UInt8						pad015D[3];			// 15D
};

STATIC_ASSERT(offsetof(TESCreature, modelList) == 0x114);
STATIC_ASSERT(offsetof(TESCreature, creatureTemplate) == 0x128);

class TESLeveledList : public BaseFormComponent
{
public:
	struct LoadBaseData	// as used by LoadForm
	{
		SInt16			level;		// 000
		UInt16			fill002;	// 002
		TESObjectREFR* refr;		// 004
		SInt16			count;		// 008
		UInt16			fill00A;	// 00A
	};	// 00C

	struct ListExtra
	{
		TESForm* owner;		// 000
		UInt32			rank;		// 004
		float			health;		// 008
	}; // 00C

	struct ListData
	{
		TESForm* form;		// 000
		SInt16			count;		// 004
		SInt16			level;		// 006
		ListExtra* extra;		// 008
	}; // 00C

	enum
	{
		kFlags_CalcAllLevels = 1 << 0,
		kFlags_CalcEachInCount = 1 << 1,
		kFlags_UseAll = 1 << 2,
	};

	tList<ListData> list;			// 004
	UInt8				chanceNone;		// 00C
	UInt8				flags;			// 00D
	UInt16				pad00E;			// 00E
	TESGlobal* unk010;			// 010 use global value for chance none?
	ExtraDataList		extraDatas;		// 014 ??? BaseExtraList::DebugDump() shows no data

	void CalculateCurrentFormList(signed int ausLevel, int ausCount, TESContainer* apOut, int aeAllBelowForce);
};	// 034

// TESLevCreature (68)
class TESLevCreature : public TESBoundObject
{
public:
	TESLevCreature();
	~TESLevCreature();

	TESLeveledList		list;		// 030
	TESModelTextureSwap	texture;	// 04C
};

// TESLevCharacter (68)
class TESLevCharacter : public TESBoundObject
{
public:
	TESLevCharacter();
	~TESLevCharacter();

	TESLeveledList		list;		// 030
	TESModelTextureSwap	texture;	// 04C
};

// TESKey (A8)
class TESKey : public TESObjectMISC
{
public:
	TESKey();
	~TESKey();
};

// D8
class AlchemyItem : public TESBoundObject
{
public:
	AlchemyItem();
	~AlchemyItem();

	TESFullName					fullName;				// 30
	EffectItemList				effects;				// 3C
	TESModelTextureSwap			model;					// 4C
	TESIcon						icon;					// 6C
	BGSMessageIcon				messageIcon;			// 78
	TESScriptableForm			scriptable;				// 88
	BGSDestructibleObjectForm	destructible;			// 94
	BGSEquipType				equipType;				// 9C

	UInt32						unkA4[2];				// A4
	BGSPickupPutdownSounds		pickupPutdownsounds;	// AC
	UInt32						value;					// B8
	UInt8						alchFlags;				// BC
	UInt8						padBD[3];				// BD
	SpellItem* withdrawalEffect;		// C0
	float						addictionChance;		// C4
	TESSound* consumeSound;			// C8
	TESIcon						iconCC;					// CC

	bool IsPoison();
};

STATIC_ASSERT(sizeof(AlchemyItem) == 0xD8);


// BGSIdleMarker (40)
class BGSIdleMarker : public TESBoundObject
{
public:
	BGSIdleMarker();
	~BGSIdleMarker();

	UInt32				unk030;			// 030
	UInt8				markerFlags;	// 034 // IDLF
	UInt8				animCount;		// 035 // IDLC
	UInt8				pad036[2];		// 036
	TESIdleForm** animations;		// 038 // IDLA
	float				timer;			// 03C // IDLT
};

// BGSNote (80)
class BGSNote : public TESBoundObject
{
public:
	BGSNote();
	~BGSNote();

	// bases
	TESModel					model;					// 030
	TESFullName					fullName;				// 048
	TESIcon						icon;					// 054
	BGSPickupPutdownSounds		pickupPutdownSounds;	// 060
	TESDescription* noteText;				// 06C
	UInt32						unk070[3];				// 070
	UInt8                       unk07C;					// 07C
	UInt8                       read;					// 07D
	UInt8                       unk07E;					// 07E
	UInt8                       unk07F;					// 07F
};

STATIC_ASSERT(offsetof(BGSNote, pickupPutdownSounds) == 0x60);
STATIC_ASSERT(offsetof(BGSNote, noteText) == 0x06C);
STATIC_ASSERT(sizeof(BGSNote) == 0x80);

// BGSConstructibleObject (B0)
class BGSConstructibleObject;

// 0C0
class BGSProjectile : public TESBoundObject
{
public:
	BGSProjectile();
	~BGSProjectile();

	enum
	{
		kFlags_Hitscan = 1 << 0,
		kFlags_Explosion = 1 << 1,
		kFlags_AltTrigger = 1 << 2,
		kFlags_MuzzleFlash = 1 << 3,
		//								1 << 4,
		kFlags_CanBeDisabled = 1 << 5,
		kFlags_CanBePicked = 1 << 6,
		kFlags_Supersonic = 1 << 7,
		kFlags_PinsLimbs = 1 << 8,
		kFlags_PassSmallTransparent = 1 << 9,
		kFlags_Detonates = 1 << 10,
		kFlags_Rotation = 1 << 11,
	};

	TESFullName						fullName;			// 030
	TESModel						model;				// 03C
	BGSPreloadable					preloadable;		// 054
	BGSDestructibleObjectForm		destructible;		// 058

	UInt16							projFlags;			// 060
	UInt16							type;				// 062
	float							gravity;			// 064
	float							speed;				// 068
	float							range;				// 06C
	TESObjectLIGH* lightProjectile;	// 070
	TESObjectLIGH* lightMuzzleFlash;	// 074
	float							tracerChance;		// 078
	float							altProximity;		// 07C
	float							altTimer;			// 080
	BGSExplosion* explosion;			// 084
	TESSound* soundProjectile;	// 088
	float							flashDuration;		// 08C
	float							fadeDuration;		// 090
	float							impactForce;		// 094
	TESSound* soundCountDown;		// 098
	TESSound* soundDisable;		// 09C
	TESObjectWEAP* defaultWeapSrc;		// 0A0
	float							rotationX;			// 0A4
	float							rotationY;			// 0A8
	float							rotationZ;			// 0AC
	float							bouncyMult;			// 0B0
	TESModel						muzzleFlash;		// 0B4
	UInt8							soundLevel;			// 0CC

	void SetFlag(UInt32 pFlag, bool bMod)
	{
		projFlags = bMod ? (projFlags | pFlag) : (projFlags & ~pFlag);
	}
};

class TESLevItem : public TESBoundObject
{
public:
	TESLeveledList list;
};

class TESImageSpaceModifier;

// 2F4
class TESWeather : public TESForm
{
public:
	TESWeather();
	~TESWeather();

	UInt32					unk018;						// 018
	TESImageSpaceModifier* imageSpaceMods[6];			// 01C
	TESTexture				layerTextures[4];			// 034
	UInt8					cloudSpeed[4];				// 064
	UInt32					unk068[24];					// 068
	TESModel				model;						// 0C8
	UInt8					windSpeed;					// 0E0
	UInt8					cloudSpeedLower;			// 0E1
	UInt8					cloudSpeedUpper;			// 0E2
	UInt8					transDelta;					// 0E3
	UInt8					sunGlare;					// 0E4
	UInt8					sunDamage;					// 0E5
	UInt8					precipitationBeginFadeIn;	// 0E6
	UInt8					precipitationEndFadeOut;	// 0E7
	UInt8					lightningBeginFadeIn;		// 0E8
	UInt8					lightningEndFadeOut;		// 0E9
	UInt8					lightningFrequency;			// 0EA
	UInt8					weatherClassification;		// 0EB
	UInt32					lightningColor;				// 0EC
	float					fogDistance[6];				// 0F0
	UInt32					colors[10][6];				// 108
	UInt32					unk1F8[63];					// 1F8
};

STATIC_ASSERT(sizeof(TESWeather) == 0x2F4);

struct WeatherEntry
{
	TESWeather* weather;
	UInt32			chance;
	TESGlobal* global;

	void Set(TESWeather* pWtr, UInt32 pChn, TESGlobal* pGlb)
	{
		weather = pWtr;
		chance = pChn;
		global = pGlb;
	}
};
typedef tList<WeatherEntry> WeatherTypes;

// 58
class TESClimate : public TESForm
{
public:
	TESClimate();
	~TESClimate();

	TESModel			nightSkyModel;		// 18
	WeatherTypes		weatherTypes;		// 30
	TESTexture			sunTexture;			// 38
	TESTexture			sunGlareTexture;	// 44
	UInt8				sunriseBegin;		// 50
	UInt8				sunriseEnd;			// 51
	UInt8				sunsetBegin;		// 52
	UInt8				sunsetEnd;			// 53
	UInt8				volatility;			// 54
	UInt8				phaseLength;		// 55
	UInt8				pad56[2];			// 56

	WeatherEntry* GetWeatherEntry(TESWeather* weather, bool rmv);
};

STATIC_ASSERT(sizeof(TESClimate) == 0x58);

// 08
class TESRegionData : public BaseFormComponent
{
public:
	TESRegionData();
	~TESRegionData();

	enum
	{
		eHeader_Grass = 0x1023B24,
		eHeader_Imposter = 0x1023BC8,
		eHeader_Land = 0x1023C8C,
		eHeader_Map = 0x1023D28,
		eHeader_Sound = 0x1023DA4,
		eHeader_Weather = 0x1023E18,
	};
	bool		bOverride;	// 04
	UInt8		unk5;		// 05
	UInt8		priority;	// 06
	UInt8		unk7;		// 07
};
typedef tList<TESRegionData> RegionDataEntryList;

class TESRegionDataGrass : public TESRegionData
{
public:
	TESRegionDataGrass();
	~TESRegionDataGrass();
};

// 10
class TESRegionDataImposter : public TESRegionData
{
public:
	TESRegionDataImposter();
	~TESRegionDataImposter();

	tList<TESObjectREFR>	imposters;	// 08
};

class TESRegionDataLandscape : public TESRegionData
{
public:
	TESRegionDataLandscape();
	~TESRegionDataLandscape();
};

// 10
class TESRegionDataMap : public TESRegionData
{
public:
	TESRegionDataMap();
	~TESRegionDataMap();

	String	mapName;	// 08
};

struct SoundType
{
	TESSound* sound;
	UInt32			flags;
	UInt32			chance;
};
typedef tList<SoundType> SoundTypeList;

// 20
class TESRegionDataSound : public TESRegionData
{
public:
	TESRegionDataSound();
	~TESRegionDataSound();

	UInt32		unk08;				// 08
	SoundTypeList	soundTypes;			// 0C
	UInt32		incidentalMediaSet;		// 14
	tList<UInt32>	mediaSetEntries;		// 18
};

// 10
class TESRegionDataWeather : public TESRegionData
{
public:
	TESRegionDataWeather();
	~TESRegionDataWeather();

	WeatherTypes	weatherTypes;	// 08
};

struct AreaPointEntry
{
	float	x;
	float	y;
};
typedef tList<AreaPointEntry> AreaPointEntryList;

struct RegionAreaEntry
{
	AreaPointEntryList	points;
	UInt32				unk08[2];
	float				unk10[4];
	UInt32				edgeFallOff;
	UInt32				pointCount;
};
typedef tList<RegionAreaEntry> RegionAreaEntryList;

// 38
class TESRegion : public TESForm
{
public:
	TESRegion();
	~TESRegion();

	RegionDataEntryList* dataEntries;	// 18
	RegionAreaEntryList* areaEntries;	// 1C
	TESWorldSpace* worldSpace;	// 20
	TESWeather* weather;		// 24
	UInt32				unk28[4];		// 28
};

STATIC_ASSERT(sizeof(TESRegion) == 0x38);

class TESRegionList : public BSSimpleList<TESRegion>
{
public:
	TESRegionList();
	~TESRegionList();
};

class NavMeshInfoMap;
class NavMesh;
class TESObjectLAND;
class BSMultiBoundNode;

class TESObjectCELL : public TESForm, public TESFullName
{
public:
	TESObjectCELL();
	~TESObjectCELL();

	enum CELL_STATE {
		CS_NOTLOADED = 0,
		CS_UNLOADING = 1,
		CS_LOADING = 2,
		CS_LOADED = 3,
		CS_DETACHING = 4,
		CS_ATTACHING = 5,
		CS_ATTACHED = 6,
	};

	typedef tList<TESObjectREFR> RefList;

	struct ExteriorData {
		SInt32	iCellX;
		SInt32	iCellY;
		UInt8	byte08;
	};

	struct InteriorData {
		UInt32		uiAmbient;
		UInt32		uiDirectional;
		UInt32		uiFogColorNear;
		float		fFogNear;
		float		fFogFar;
		SInt32		iDirectionalXY;
		SInt32		iDirectionalZ;
		float		fDirectionalFade;
		float		fClipDist;
		float		fFogPower;
		void* pGetValuesFrom;
	};

	union CellData {
		ExteriorData* pCellDataExterior;
		InteriorData* pCellDataInterior;
	};

	struct LOADED_CELL_DATA
	{
		NiNode* masterNode;
		tList<TESObjectREFR> largeAnimatedRefs;
		NiTMapBase<TESObjectREFR*, NiNode*> animatedRefs;
		NiTMapBase < TESForm*, TESObjectREFR*> emittanceSourceRefMap;
		NiTMapBase < TESObjectREFR*, NiNode*> emittanceLightRefMap;
		NiTMapBase < TESObjectREFR*, NiPointer<BSMultiBoundNode>> multiboundRefMap;
		tList<TESObjectREFR> scriptedRefs;
		tList<TESObjectREFR> activateRefChildren;
		tList<TESObjectREFR> placeableWatersList;
	};

	UInt8 cellFlags;
	UInt8 cellState;
	UInt8 byte3A;
	UInt8 gap3B;
	ExtraDataList extraDataList;
	CellData pCellData;
	TESObjectLAND* land;
	float waterHeight;
	UInt8 bAutoWaterLoaded;
	TESTexture noiseTexture;
	NavMesh** navMeshArray;
	UInt32 unk80[5];
	RTL_CRITICAL_SECTION refLockSemaphore;
	UInt32 unkB8;
	UInt32 unkBC;
	SInt32 numNonActorRefs;
	SInt32 numRefs;
	UInt16 countVisibleDistant;
	UInt16 visibleWhenDistantCountLoaded;
	tList<TESObjectREFR> objectList;
	NiPointer<NiNode>	spLightMarkerNode;
	NiPointer<NiNode>	spSoundMarkerNode;
	UInt32 unkDC;
	LOADED_CELL_DATA* renderData;
	float unkE4;
	UInt8 byteE8;
	UInt8 byteE9;
	UInt8 byteEA;
	UInt8 byteEB;
	UInt8 byteEC;
	UInt8 byteED;
	UInt8 byteEE;
	UInt8 byteEF;
	BSPortalGraph* portalGraph;
	UInt32 unkF4;
	UInt32 inheritFlags;
	BGSLightingTemplate* lightingTemplate;

	SInt32 GetPosX() { return ThisCall<SInt32>(0x625A70, this); };
	SInt32 GetPosY() { return ThisCall<SInt32>(0x625A90, this); };
	bool IsInterior() { return cellFlags & 1; };
	bool GetLandHeight(NiPoint3* pos, float* heightOut)
	{
		auto land = ThisCall<TESObjectLAND*>(0x627140, this);
		return ThisCall<bool>(0x61A810, land, pos, heightOut);
	}

	void CellRefLockEnter() {
		ThisCall(0x625850, this);
	}

	void CellRefLockLeave() {
		ThisCall(0x625870, this);
	}

	void MarkAsModified(bool abModified) {
		ThisCall(0x6286B0, this, abModified);
	}

	NiNode* Load3D();

	void AttachModels(bool abSetupMopp);

	void AddObjectsToLoadedRefCollection();

	BSMultiBoundNode* AddMultiBoundRef(TESObjectREFR* apMultiBound);
};
static_assert(sizeof(TESObjectCELL) == 0x100);

// TESObjectREFR (60) - see GameObjects.h

struct LODdata;	// 03C
class BSPortalGraph;

// TESWorldSpace (EC)
class TESWorldSpace : public TESForm
{
public:
	TESWorldSpace();
	~TESWorldSpace();

	struct CoordXY {
		float	X;	// 000
		float	Y;	// 004
	};	// 008

	struct DCoordXY {
		SInt32	X;	// 000
		SInt32	Y;	// 004
	};	// 008

	struct WCoordXY {
		SInt16	X;	// 000
		SInt16	Y;	// 002
	};	// 004

	struct Offset_Data
	{
		UInt32** unk000;	// 000 array of UInt32 stored in OFST record (indexed by relative CellXY).
		CoordXY min;		// 004 NAM0
		CoordXY max;		// 00C NAM9
		UInt32	fileOffset;	// 014 TESWorldspace file offset in modInfo
	};	// 014

	struct MapData
	{
		DCoordXY	usableDimensions;
		WCoordXY	cellNWCoordinates;
		WCoordXY	cellSECoordinates;
	};	// 010

	struct ImpactData
	{
		typedef NiTMapBase<BGSImpactData*, BGSImpactData*> ImpactImpactMap;
		enum MaterialType
		{
			eMT_Stone = 0,
			eMT_Dirt,
			eMT_Grass,
			eMT_Glass,
			eMT_Metal,
			eMT_Wood,
			eMT_Organic,
			eMT_Cloth,
			eMT_Water,
			eMT_HollowMetal,
			eMT_OrganicBug,
			eMT_OrganicGlow,

			eMT_Max
		};

		ImpactImpactMap	impactImpactMap[eMT_Max];	// 000
		char			footstepMaterials[0x12C];	// 030
	};

	typedef NiTPointerMap<BSSimpleList<TESObjectREFR> > RefListPointerMap;
	typedef NiTPointerMap<TESObjectCELL> CellPointerMap;
	typedef NiTMapBase<ModInfo*, TESWorldSpace::Offset_Data*> OffsetDataMap;

	TESFullName			fullName;			// 018 confirmed
	TESTexture			texture;			// 024 confirmed ICON
	CellPointerMap* cellMap;			// 030 confirmed
	TESObjectCELL* cell;				// 034 should be the Permanent cell
	UInt32				unk038;				// 038
	LODdata* lodData;			// 03C looks to be the LOD data (That is what is returned when checking the parent "Use LOD data" flag)
	TESClimate* climate;			// 040 confirmed CNAM
	TESImageSpace* imageSpace;		// 044 confirmed INAM
	ImpactData* impacts;			// 048 confirmed
	UInt8				flags;				// 04C confirmed DATA
	BSPortalGraph* portalGraph;
	TESWorldSpace* parent;			// 070 confirmed
	TESWaterForm* waterFormFirst;	// 074 confirmed NAM2
	TESWaterForm* waterFormLast;	// 078 confirmed NAM3 LOD Water type for xEdit
	float				waterHeight;		// 07C confirmed NAM4
	MapData				mapData;			// 080 confirmed MNAM
	float				worldMapScale;		// 090 confirmed ONAM for three floats
	float				worldMapCellX;		// 094 confirmed
	float				worldMapCellY;		// 098 confirmed
	BGSMusicType* music;			// 09C confirmed ZNAM
	CoordXY				min;				// 0A0 confirmed NAM0 min of all Offset_Data.min
	CoordXY				max;				// 0A8 confirmed NAM9 max of all Offset_data.max
	float				defaultLandHeight;	// 0C8 confirmed DNAM for the two
	float				defaultWaterHeight;	// 0CC
	BGSEncounterZone* encounterZone;	// 0D0 confirmed	
	TESTexture			canopyShadow;		// 0D4 confirmed NNAM
	TESTexture			waterNoiseTexture;	// 0E0 confirmed XNAM

	TESObjectCELL* GetCellAtCoord(SInt32 aiX, SInt32 aiY) const;
	TESObjectCELL* GetCellAtPos(const NiPoint3& arPos) const;

};	// I am seeing a tList at 60, a map at 50 indexed by XY coord !!!, another map at B0, indexed by modInfo::Unklist elements

static_assert(sizeof(TESWorldSpace) == 0xFC);

// TESObjectLAND (2C)
class TESObjectLAND;

// NavMesh (108)
class NavMesh : public TESForm
{

};

struct Condition
{
	UInt8			type;		// 000
	UInt8			pad[3];
	union
	{
		float	value;
		UInt32	global;
	} comparisonValue;			// 004
	UInt32			function;	// 008
	union
	{
		float	value;
		UInt32	number;
		void* pointer;
	}				parameter1;	// 00C
	union
	{
		float	value;
		UInt32	number;
		void* pointer;
	}				parameter2;		// 010
	UInt32			runOn;		// 014	Subject, Target, Reference, CombatTarget, LinkedReference
	TESObjectREFR* reference;	// 018
};

struct VariableInfo
{
	UInt32			idx;		// 00
	UInt32			pad04;		// 04
	double			data;		// 08
	UInt8			type;		// 10
	UInt8			pad11[3];	// 11
	UInt32			unk14;		// 14
	String			name;		// 18
};

// TESQuest (6C)
class TESQuest : public TESForm
{
public:
	TESQuest();
	~TESQuest();

	virtual char* GetEditorName() const;			// 4E

	// bases
	TESScriptableForm			scriptable;			// 018
	TESIcon						icon;				// 024
	TESFullName					fullName;			// 030

	struct StageInfo {
		UInt8			stage;	// 00 stageID
		UInt8			unk001;	// 01 status ?
		UInt8			pad[2];	// 02
		tList<void*>	unk004;	// 04 log entries
	};	// 00C

	union LocalVariableOrObjectivePtr
	{
		BGSQuestObjective* objective;
		VariableInfo* varInfoIndex;
	};

	UInt8						questflags;						// 03C	bit0 is startGameEnabled/isRunning
	UInt8						priority;					// 03D
	UInt8						pad03E[2];					// 03E
	float						questDelayTime;				// 040
	tList<StageInfo>			stages;						// 044
	tList<LocalVariableOrObjectivePtr>	lVarOrObjectives;	// 04C	So: this list would contain both Objectives and LocalVariables !
	// That seems very strange but still, looking at Get/SetObjective... and ShowQuestVars there's no doubt.
	tList<Condition>			conditions;					// 054
	ScriptEventList* scriptEventList;			// 05C
	UInt8						currentStage;				// 060
	UInt8						pad061[3];					// 061
	String						editorName;					// 064
};

STATIC_ASSERT(offsetof(TESQuest, questflags) == 0x03C);
STATIC_ASSERT(offsetof(TESQuest, lVarOrObjectives) == 0x04C);
STATIC_ASSERT(offsetof(TESQuest, conditions) == 0x54);
STATIC_ASSERT(sizeof(TESQuest) == 0x6C);

// TESIdleForm (54)
class TESIdleForm;

class TESPackageData
{
public:
	TESPackageData();
	~TESPackageData();
	virtual void	Destroy(bool free);
	virtual void	CopyFrom(TESPackageData* packageData);
	virtual void	Unk_02(void);
	virtual void	Save(ModInfo* modInfo);
	virtual void	Unk_04(void);
	virtual void	Unk_05(void);
	virtual void	Unk_06(void);
	virtual void	Unk_07(void);
};

class TESPatrolPackageData : public TESPackageData
{
public:
	TESPatrolPackageData();
	~TESPatrolPackageData();

	UInt8	patrolFlags;
};

// TESPackage (80) class definition duplicated from Oblivion. Enum not updated
class TESPackage : public TESForm
{
public:
	TESPackage();
	~TESPackage();

	virtual void	Unk_5D();
	virtual void	Unk_5E();

	enum	// From OBSE and FNVEdit
	{
		kPackageFlag_OffersServices = 1 << 0,
		kPackageFlag_MustReachLocation = 1 << 1,
		kPackageFlag_MustComplete = 1 << 2,
		kPackageFlag_LockDoorsAtStart = 1 << 3,
		kPackageFlag_LockDoorsAtEnd = 1 << 4, 	// set by CHANGE_PACKAGE_WAITING ?
		kPackageFlag_LockDoorsAtLocation = 1 << 5,
		kPackageFlag_UnlockDoorsAtStart = 1 << 6,
		kPackageFlag_UnlockDoorsAtEnd = 1 << 7,
		kPackageFlag_UnlockDoorsAtLocation = 1 << 8,
		kPackageFlag_ContinueIfPCNear = 1 << 9,
		kPackageFlag_OncePerDay = 1 << 10,
		kPackageFlag_Unk11 = 1 << 11,
		kPackageFlag_SkipFalloutBehavior = 1 << 12,
		kPackageFlag_AlwaysRun = 1 << 13,
		kPackageFlag_Unk14 = 1 << 14,
		kPackageFlag_NeverRun = 1 << 15,	// Save only ?
		kPackageFlag_Unk16 = 1 << 16,
		kPackageFlag_AlwaysSneak = 1 << 17,
		kPackageFlag_AllowSwimming = 1 << 18,
		kPackageFlag_AllowFalls = 1 << 19,
		kPackageFlag_ArmorUnequipped = 1 << 20,
		kPackageFlag_WeaponsUnequipped = 1 << 21,
		kPackageFlag_DefensiveCombat = 1 << 22,
		kPackageFlag_WeaponsDrawn = 1 << 23,
		kPackageFlag_NoIdleAnims = 1 << 24,
		kPackageFlag_PretendInCombat = 1 << 25,
		kPackageFlag_ContinueDuringCombat = 1 << 26,
		kPackageFlag_NoCombatAlert = 1 << 27,
		kPackageFlag_NoWarnAttackBehavior = 1 << 28,
		kPackageFlag_Unk29 = 1 << 29,
		kPackageFlag_Unk30 = 1 << 30,
		kPackageFlag_Unk31 = 1 << 31
	};

	enum	// From OBSE and FNVEdit. Runtimes has 0x24 types!
	{
		kPackageType_Find = 0,		// 00
		kPackageType_Follow,
		kPackageType_Escort,
		kPackageType_Eat,
		kPackageType_Sleep,
		kPackageType_Wander,
		kPackageType_Travel,
		kPackageType_Accompany,
		kPackageType_UseItemAt,
		kPackageType_Ambush,
		kPackageType_FleeNotCombat,
		kPackageType_Unk11,
		kPackageType_Sandbox,
		kPackageType_Patrol,
		kPackageType_Guard,
		kPackageType_Dialogue,
		kPackageType_UseWeapon,			// 10

		// unless shown otherwise kPackageType_CombatController,	// Actor::GetCombatController returns package only if type matches this
		// start conversation can lead to a package of type 1C, which is recorded in PlayerCharacter::Unk0224

		kPackType_MAX
	};

	// 8
	struct PackageTime
	{
		enum
		{
			kDay_Any = 0,
			kTime_Any = 0xFF,
		};

		enum
		{
			kMonth_January = 0,
			kMonth_February,
			kMonth_March,
			kMonth_April,
			kMonth_May,
			kMonth_June,
			kMonth_July,
			kMonth_August,
			kMonth_September,
			kMonth_October,
			kMonth_November,
			kMonth_December,
			kMonth_Spring,	// march, april, may
			kMonth_Summer,	// june, july, august
			kMonth_Autumn,	// september, august, november (in Geck)
			kMonth_Winter,	// december, january, february

			kMonth_Any = 0xFF,
		};

		enum
		{
			kWeekday_Sundays = 0,
			kWeekday_Morndays,
			kWeekday_Tuesdays,
			kWeekday_Wednesdays,
			kWeekday_Thursdays,
			kWeekday_Frydays,
			kWeekday_Saturdays,
			kWeekday_Weekdays,
			kWeekday_Weekends,
			kWeekday_MWF,
			kWeekday_TT,

			kWeekday_Any = 0xFF
		};

		UInt8	month;
		UInt8	weekDay;
		UInt8	date;
		UInt8	time;
		UInt32	duration;

		static const char* MonthForCode(UInt8 monthCode);
		static const char* DayForCode(UInt8 dayCode);
		static UInt8 CodeForMonth(const char* monthStr);
		static UInt8 CodeForDay(const char* dayStr);
		static bool IsValidMonth(UInt8 m) { return (m + 1) <= kMonth_Winter; }
		static bool IsValidTime(UInt8 t) { return (t + 1) <= 24; }
		static bool IsValidDay(UInt8 d) { return (d + 1) <= kWeekday_TT; }
		static bool IsValidDate(UInt8 d) { return d <= 31; }
	};

	union ObjectType
	{
		TESForm* form;
		TESObjectREFR* refr;
		UInt32			objectCode;
	};

	// order only somewhat related to kFormType_XXX (values off by 17, 20, or 21)
	enum	// From OBSE and FNVEdit
	{
		kObjectType_None = 0,
		kObjectType_Activators,
		kObjectType_Armor,
		kObjectType_Books,
		kObjectType_Clothing,
		kObjectType_Containers,
		kObjectType_Doors,
		kObjectType_Ingredients,
		kObjectType_Lights,
		kObjectType_Misc,
		kObjectType_Flora,
		kObjectType_Furniture,
		kObjectType_WeaponsAny,
		kObjectType_Ammo,
		kObjectType_NPCs,
		kObjectType_Creatures,
		kObjectType_Keys,				//	10
		kObjectType_Alchemy,
		kObjectType_Food,
		kObjectType_AllCombatWearable,
		kObjectType_AllWearable,
		kObjectType_WeaponsRanged,
		kObjectType_WeaponsMelee,
		kObjectType_WeaponsNone,
		kObjectType_ActorEffectAny,
		kObjectType_ActorEffectRangeTarget,
		kObjectType_ActorEffectRangeTouch,
		kObjectType_ActorEffectRangeSelf,
		kObjectType_ActorsAny,

		kObjectType_Max,						//	1E
	};

	struct LocationData
	{
		enum {
			kPackLocation_NearReference = 0,
			kPackLocation_InCell = 1,
			kPackLocation_CurrentLocation = 2,
			kPackLocation_EditorLocation = 3,
			kPackLocation_ObjectID = 4,
			kPackLocation_ObjectType = 5,
			kPackLocation_LinkedReference = 6,

			kPackLocation_Max,
		};

		UInt8		locationType;	// 000
		UInt8		pad[3];
		UInt32		radius;			// 004
		ObjectType  object;			// 008

		static LocationData* Create();
		static const char* StringForLocationCode(UInt8 locCode);
		const char* StringForLocationCodeAndData(void);
		static UInt8 LocationCodeForString(const char* locStr);
		static bool IsValidLocationType(UInt8 locCode) { return locCode < kPackLocation_Max; }
	};

	enum
	{
		kTargetType_Refr = 0,
		kTargetType_BaseObject = 1,
		kTargetType_TypeCode = 2,

		kTargetType_Max = 3,
	};

	struct TargetData
	{
		UInt8		targetType;	// 00
		UInt8		pad[3];		// 01
		ObjectType	target;		// 04
		UInt32		count;		// 08 can be distance too
		float		unk0C;		// 0C

		static TargetData* Create();
		static const char* StringForTargetCode(UInt8 targetCode);
		const char* StringForTargetCodeAndData(void);
		static UInt8 TargetCodeForString(const char* targetStr);
		static bool IsValidTargetCode(UInt8 c) { return c < TESPackage::kTargetType_Max; }
	};


	enum eProcedure {			// UInt32	// Checked the Geck Wiki. Not consistent with s_procNames (which has a diffferent order and 0x37 procedures)
		kProcedure_TRAVEL = 0,
		kProcedure_ACTIVATE,
		kProcedure_ACQUIRE,
		kProcedure_WAIT,
		kProcedure_DIALOGUE,
		kProcedure_GREET,
		kProcedure_GREET_DEAD,
		kProcedure_WANDER,
		kProcedure_SLEEP,
		kProcedure_OBSERVE_COMBAT,
		kProcedure_EAT,
		kProcedure_FOLLOW,
		kProcedure_ESCORT,
		kProcedure_COMBAT,
		kProcedure_ALARM,
		kProcedure_PURSUE,
		kProcedure_FLEE,					// 0x10
		kProcedure_DONE,
		kProcedure_YELD,
		kProcedure_TRAVEL_TARGET,
		kProcedure_CREATE_FOLLOW,
		kProcedure_GET_UP,
		kProcedure_MOUNT_HORSE,
		kProcedure_DISMOUNT_HORSE,
		kProcedure_DO_NOTHING,
		kProcedure_UNK019,
		kProcedure_UNK01A,
		kProcedure_ACCOMPANY,
		kProcedure_USE_ITEM_AT,
		kProcedure_SANDMAN,
		kProcedure_WAIT_AMBUSH,
		kProcedure_SURFACE,					// 0x20
		kProcedure_WAIT_FOR_SPELL,
		kProcedure_CHOOSE_CAST,
		kProcedure_FLEE_NON_COMBAT,
		kProcedure_REMOVE_WORN_ITEMS,
		kProcedure_SEARCH,
		kProcedure_CLEAR_MOUNT_POSITION,
		kProcedure_SUMMON_CREATURE_DEFEND,
		kProcedure_AVOID_AREA,
		kProcedure_UNEQUIP_ARMOR,
		kProcedure_PATROL,
		kProcedure_USE_WEAPON,
		kProcedure_DIALOGUE_ACTIVATE,
		kProcedure_GUARD,
		kProcedure_SANDBOX,
		kProcedure_USE_IDLE_MARKER,
		kProcedure_TAKE_BACK_ITEM,
		kProcedure_SITTING,					// 0x30
		kProcedure_MOVEMENT_BLOCKED,
		kProcedure_CANIBAL_FEED,			// 0x32

		kProcedure_MAX						// 0x33
	};

	// In DialoguePackage, there are 0x58 virtual functions (including 0x4E from TESForm)

	UInt32			procedureArrayIndex;	// 018 index into array of array of eProcedure terminated by 0x2C. 
	//	   -1 if no procedure array exists for package type.
	UInt32				packageFlags;		// 01C
	UInt8				type;				// 020
	UInt8				pad021[1];			// 021
	UInt16				behaviorFlags;		// O22
	UInt32				specificFlags;		// 024
	TESPackageData* packageData;		// 028
	LocationData* location;			// 02C
	TargetData* target;				// 030	target ?
	UInt32				unk034;				// 034	idles
	PackageTime			time;				// 038
	UInt32 unk040[(0x80 - 0x40) >> 2];		// 040	040 is a tList of Condition, 7C is an Interlocked counter
	//	048 is a DWord CombatStyle, 
	//	04C, 05C and 06C are the same 4 DWord struct onBegin onEnd onChange, { TESIdle* idle; EmbeddedScript* script; Topic* topic; UInt32 unk0C; }
	//	07C is a DWord

	void SetTarget(TESObjectREFR* refr);
	void SetTarget(TESForm* baseForm, UInt32 count);
	void SetTarget(UInt8 typeCode, UInt32 count);
	void SetCount(UInt32 aCount);
	void SetDistance(UInt32 aDistance) { SetCount(aDistance); }
	TargetData* GetTargetData();
	LocationData* GetLocationData();

	bool IsFlagSet(UInt32 flag);
	void SetFlag(UInt32 flag, bool bSet);

	static const char* StringForPackageType(UInt32 pkgType);
	static const char* StringForObjectCode(UInt8 objCode);
	static UInt8 ObjectCodeForString(const char* objString);
	static bool IsValidObjectCode(UInt8 o) { return o < kObjectType_Max; }
	static const char* StringForProcedureCode(eProcedure proc);
};

STATIC_ASSERT(sizeof(TESPackage) == 0x80);

struct DialogueResponse {
	String			responseText;	// 000
	UInt32			emotionType;	// 008
	SInt32			emotionValue;	// 00C
	String			voiceFileName;	// 010
	TESIdleForm* speakerIdle;	// 018	idle
	TESIdleForm* listenerIdle;	// 01C	idle
	TESSound* sound;			// 020
	UInt32			unk024;			// 024	uninitialized, unused in xEdit
	UInt32			unk028;			// 028
};

struct DialogueItem {
	tList<DialogueResponse>	responses;				// 000
	DialogueResponse* currentResponse;	// 008
	TESTopicInfo* currentTopicInfo;	// 00C
	TESTopic* currentTopic;		// 010
	TESQuest* currentQuest;		// 014
	TESForm* currentSpeaker;		// 018
};

// DialoguePackage : Only package tested and verified effectivly
class DialoguePackage : public TESPackage
{
public:
	DialoguePackage();
	~DialoguePackage();

	struct Data0080 {	// The constructor is referenced 169 time all over the place !
		UInt32	unk000;		//	000
		UInt8	byt004;		//	004
		UInt8	pad005[3];	//	005-007
		UInt32	unk008;		//	008
	};	//	00C

	Data0080	data0080;		// 080
	TESTopic* topic;		// 08C
	float		flt090;			// 090
	Character* speaker;		// 094
	UInt8		unk098;			// 098
	UInt8		unk099;			// 098
	UInt8		unk09A;			// 098
	UInt8		unk09B;			// 098
	TESForm* unk09C;		// 09C
	UInt32		unk0A0;			// 0A0
	void* unk0A4;			// 0A4	list of Dialogue Item and Dialogue Response, plus current item and current response
	UInt32		unk0A8;			// 0A8
	UInt32		unk0AC;			// 0AC
	Character* subject;		// 0B0
	Character* target;		// 0B4
	TESForm* unk0B8;		// 0B8
	UInt8		unk0BC;			// 0BC
	UInt8		unk0BD;			// 0BD
	UInt8		unk0BE;			// 0BE
	UInt8		unk0BF;			// 0BF
	UInt8		unk0C0;			// 0C0
	UInt8		unk0C1;			// 0C1
	UInt8		unk0C2;			// 0C2
	UInt8		unk0C3;			// 0C3
	UInt32		unk0C4;			// 0C4
	UInt32		unk0C8;			// 0C8
	UInt8		unk0CC;			// OCC
	UInt8		unk0CD[3];		// OCD
};	// 0D0

typedef struct {
	float vector[3];
} ThreeFloatArray;

class FleePackage : public TESPackage
{
public:
	FleePackage();
	~FleePackage();

	UInt8			unk080;		// 080
	UInt8			unk081;		// 081
	UInt8			pad082[2];	// 082
	ThreeFloatArray	unk084;		// 084	is array of 3 floats, should be Pos
	float			unk090;		// 090
	UInt8			unk094;		// 094
	UInt8			pad095[3];	// 095
	tList<TESForm*>	list098;	// 098
	TESForm* unk0A0;	// 0A0
	TESForm* unk0A4;	// 0A4
	UInt8			unk0A8;		// 0A8
	UInt8			unk0A9;		// 0A9
	UInt8			pad0AA[2];	// 0AA
};	// 0AC

class TressPassPackage : public TESPackage
{
public:
	TressPassPackage();
	~TressPassPackage();

	float		unk080;		// 080
	UInt32		unk084;		// 084
	TESForm* unk088;	// 088
	TESForm* unk08C;	// 08C
	UInt32		unk090;		// 090
	UInt32		unk094;		// 094
	UInt32		unk098;		// 098
};	// 09C

struct SpectatorThreatInfo
{
	TESForm* unk000;	// 000
	TESForm* unk004;	// 004
	UInt32			unk008;		// 008
	UInt32			unk00C;		// 00C	elapsed tick count
	UInt32			unk010;		// 010
	ThreeFloatArray	unk014;		// 014	is array of 3 floats, should be Pos
	ThreeFloatArray	unk020;		// 020	is array of 3 floats, should be Rot
	UInt8			unk02C;		// 02C
	UInt8			unk02D;		// 02D
	UInt8			pad[2];		// 02E
};	// 030

class SpectatorPackage : public TESPackage
{
public:
	SpectatorPackage();
	~SpectatorPackage();

	UInt32			unk080;		// 080
	UInt32			unk084;		// 084
	UInt32			unk088;		// 088
	UInt32			unk08C;		// 08C
	UInt8			unk090;		// 090
	UInt8			pad091[3];	// 091
	ThreeFloatArray	unk094;		// 094	is array of 3 floats, should be Pos
	BSSimpleArray<SpectatorThreatInfo>	arr0A0;	// 0A0
	// There is an object containing a semaphore at B0/B4
};	// 0B4

class TESFollowPackageData : public TESPackageData
{
public:
	TESFollowPackageData();
	~TESFollowPackageData();
	TESPackage::LocationData* endLocation;
	float	flt008;
};

// TESCombatStyle (108)
class TESCombatStyle : public TESForm
{
public:
	TESCombatStyle();
	~TESCombatStyle();

	enum
	{
		kFlag_ChooseAttackUsingChance = 1,
		kFlag_MeleeAlertOK = 2,
		kFlag_FleeBasedOnPersonalSurvival = 4,
		kFlag_IgnoreThreats = 16,
		kFlag_IgnoreDamagingSelf = 32,
		kFlag_IgnoreDamagingGroup = 64,
		kFlag_IgnoreDamagingSpectators = 128,
		kFlag_CannotUseStealthboy = 256,
	};

	float	coverSearchRadius;				// 018
	float	takeCoverChance;				// 01C
	float	waitTimeMin;					// 020
	float	waitTimeMax;					// 024
	float	waitToFireTimerMin;				// 028
	float	waitToFireTimerMax;				// 02C
	float	fireTimerMin;					// 030
	float	fireTimerMax;					// 034
	float	rangedWeapRangeMultMin;			// 038
	UInt8	pad3C[4];						// 03C
	UInt8	weaponRestrictions;				// 040
	UInt8	pad41[3];						// 041
	float	rangedWeapRangeMultMax;			// 044
	float	maxTargetingFOV;				// 048
	float	combatRadius;					// 04C
	float	semiAutoFiringDelayMultMin;		// 050
	float	semiAutoFiringDelayMultMax;		// 054
	UInt8	dodgeChance;					// 058
	UInt8	LRChance;						// 059
	UInt8	pad5A[2];						// 05A
	float	dodgeLRTimerMin;				// 05C
	float	dodgeLRTimerMax;				// 060
	float	dodgeFWTimerMin;				// 064
	float	dodgeFWTimerMax;				// 068
	float	dodgeBKTimerMin;				// 06C
	float	dodgeBKTimerMax;				// 070
	float	idleTimerMin;					// 074
	float	idleTimerMax;					// 078
	UInt8	blockChance;					// 07C
	UInt8	attackChance;					// 07D
	UInt8	pad7E[2];						// 07E
	float	staggerBonusToAttack;			// 080
	float	KOBonusToAttack;				// 084
	float	H2HBonusToAttack;				// 088
	UInt8	powerAttackChance;				// 08C
	UInt8	pad8D[3];						// 08D
	float	staggerBonusToPower;			// 090
	float	KOBonusToPower;					// 094
	UInt8	powerAttackN;					// 098
	UInt8	powerAttackF;					// 099
	UInt8	powerAttackB;					// 09A
	UInt8	powerAttackL;					// 09B
	UInt8	powerAttackR;					// 09C
	UInt8	pad9D[3];						// 09D
	float	holdTimerMin;					// 0A0
	float	holdTimerMax;					// 0A4
	UInt16	csFlags;						// 0A8
	UInt8	pad0AA[2];						// 0AA
	UInt8	acrobaticDodgeChance;			// 0AC
	UInt8	rushAttackChance;				// 0AD
	UInt8	pad0AE[2];						// 0AE
	float	rushAttackDistMult;				// 0B0
	float	dodgeFatigueModMult;			// 0B4
	float	dodgeFatigueModBase;			// 0B8
	float	encumSpeedModBase;				// 0BC
	float	encumSpeedModMult;				// 0C0
	float	dodgeUnderAttackMult;			// 0C4
	float	dodgeNotUnderAttackMult;		// 0C8
	float	dodgeBackUnderAttackMult;		// 0CC
	float	dodgeBackNotUnderAttackMult;	// 0D0
	float	dodgeFWAttackingMult;			// 0D4
	float	dodgeFWNotAttackingMult;		// 0D8
	float	blockSkillModMult;				// 0DC
	float	blockSkillModBase;				// 0E0
	float	blockUnderAttackMult;			// 0E4
	float	blockNotUnderAttackMult;		// 0E8
	float	attackSkillModMult;				// 0EC
	float	attackSkillModBase;				// 0F0
	float	attackUnderAttackMult;			// 0F4
	float	attackNotUnderAttackMult;		// 0F8
	float	attackDuringBlockMult;			// 0FC
	float	powerAttackFatigueModBase;		// 100
	float	powerAttackFatigueModMult;		// 104

	void SetFlag(UInt32 pFlag, bool bMod)
	{
		csFlags = bMod ? (csFlags | pFlag) : (csFlags & ~pFlag);
	}
};
STATIC_ASSERT(sizeof(TESCombatStyle) == 0x108);

// 2C
class TESRecipeCategory : public TESForm
{
public:
	TESRecipeCategory();
	~TESRecipeCategory();

	TESFullName			name;
	//UInt32				unk;
	UInt32				flags;

};

STATIC_ASSERT(sizeof(TESRecipeCategory) == 0x28);

class TESRecipe : public TESForm
{
public:
	TESRecipe();
	~TESRecipe();

	struct Entry
	{
		UInt32			count;	//
		TESForm* item;	//
	};

	TESFullName			fullName;					// 18 //
	UInt32				reqSkill;					// 24 //
	UInt32				reqSkillLevel;				// 28 //
	UInt32				categoryRefID;				// 2C ? these appear to be the refID instead of a form pointer...
	UInt32				subcategoryRefID;			// 30 ?
	tList<Condition>	conditions;					// 34 //
	tList<Entry>		inputs;						// 3C //
	tList<Entry>		outputs;					// 44 //
	UInt32				unk04C;						// 4C
	UInt32				unk050;						// 50

	TESRecipeCategory* category;					// 54 //
	TESRecipeCategory* subcategory;				// 58 //
	// 5C
};

STATIC_ASSERT(sizeof(TESRecipe) == 0x5C);

class TESLoadScreenType : public TESForm
{
public:
	TESLoadScreenType();
	~TESLoadScreenType();

	struct floatRGB
	{
		float R, G, B;
	};

	UInt32			type;						// 018
	// Data 1
	UInt32			x;							// 01C
	UInt32			y;							// 020
	UInt32			width;						// 024
	UInt32			height;						// 028
	UInt32			orientation;				// 02C
	UInt32			font1;						// 030
	floatRGB		fontcolor1;					// 034
	UInt32			justification;				// 040
	UInt32			unk044[(0x58 - 0x44) >> 2];	// 044
	// Data 2
	UInt32			font2;						// 058
	floatRGB		fontcolor2;					// 05C
	UInt32			unk068;						// 068
	UInt32			stats;						// 06C
};



// TESLoadScreen (3C)
class TESLoadScreen : public TESForm
{
public:
	TESLoadScreen();
	~TESLoadScreen();

	TESTexture			texture;			// 018
	TESDescription		description;		// 024
	UInt32				unk2C[2];			// 02C
	TESLoadScreenType* type;				// 034
};

// TESLevSpell (44)
class TESLevSpell;

// TESObjectANIO (3C)
class TESObjectANIO : public TESForm
{
public:
	TESObjectANIO();
	~TESObjectANIO();

	TESModelTextureSwap	modelSwap;		// 18
	TESIdleForm* idleForm;		// 38
};

// TESWaterForm (190, 194 in 1.5)
class TESWaterForm : public TESForm
{
public:
	TESWaterForm();
	~TESWaterForm();

	TESFullName				fullName;						// 018 FULL
	TESAttackDamageForm		attackDamage;					// 024 DATA
	UInt32					unk02C;							// 02C (seen: 0x01)
	UInt32					unk030[(0x064 - 0x030) >> 2];	// 030
	TESTexture				noiseMap;						// 064 NNAM
	UInt8					opacity;						// 070 ANAM
	UInt8					flags;							// 071 FNAM (0x01: causes damage, 0x02: reflective)
	UInt8					unk072[2];						// 072
	UInt32					unk074[2];						// 074
	TESSound* sound;							// 07C SNAM
	TESWaterForm* waterForm;						// 080 // ??
#if 1
	float					visData[(0x148 - 0x084) >> 2];	// 084 DNAM (outlined below)
#else
	UInt32					junk084[4];						// 084
	float					waterProp_094[3];				// 094 // sun power, reflectivity, fresnel amount
	UInt32					unk0A0;							// 0A0
	float					fogProp0A4[2];					// 0A4 // above - distance (near plane, far plane)
	ColorRGB				colorShallow;					// 0AC
	ColorRGB				colorDeep;						// 0B0
	ColorRGB				colorReflection;				// 0B4
	UInt32					unk0B8;							// 0B8 // looks like RGBA
	float					rainSim[4];						// 0BC // force, velocity, falloff, dampener
	float					displacementSim[5];				// 0CC // starting size, force, velocity, falloff, dampener
	float					rainSim0E0;						// 0E0 // starting size
	float					noiseProp0E4;					// 0E4 // noise scale
	float					noiseProp[3][2];				// 0E4 // [layer] wind direction, wind speed
	float					noiseProp100[2];				// 100 // normals - depth falloff start, end
	float					fogProp108;						// 108 // above - fog amount
	float					noiseProp10C;					// 10C // normals - UV scale
	float					forProp110[3];					// 110 // under - amount, distance (near plane, far plane)
	float					waterProp11C[5];				// 11C // distortion amount, shininess, reflection HDR mult, light radius, light brightness
	float					noiseProp130[3][2];				// 130 // [layer] UV scale, amplitude scale
#endif
	UInt32					unk148[(0x178 - 0x148) >> 2];	// 148
	SpellItem* actorEffect;					// 178 XNAM
	UInt32					unk17C[3];						// 17C
	UInt8					radiation;						// 188
	UInt8					pad189[3];						// 189
	UInt32					unk18C[2];						// 18C

	// 084 begins DNAM - Visual Data:
	//01	084: unknown (float)
	//02	088: unknown (float)
	//03	08C: unknown (float)
	//04	090: unknown (float)
	//05	094: water prop - sun power
	//06	098: water prop - reflectivity
	//07	09C: water prop - fresnel amount
	//08	0A0: unknown (null)
	//09	0A4: fog prop - above water - fog distance (near plane)
	//10	0A8: fog prop - above water - for distance (far plane)
	//11	0AC: shallow color, in 3 8-bit ints with 1 pad
	//12	0B0: deep color, in 3 8-bit ints with 1 pad
	//13	0B4: reflection color, in 3 8-bit ints with 1 pad
	//14	0B8: unknown (int)
	//15	0BC: rain sim - force
	//16	0C0: rain sim - velocity
	//17	0C4: rain sim - falloff
	//18	0C8: rain sim - dampener
	//19	0CC: displacement sim - starting size
	//20	0D0: displacement sim - force
	//21	0D4: displacement sim - velocity
	//22	0D8: displacement sim - falloff
	//23	0DC: displacement sim - dampener
	//24	0E0: rain sim - starting size
	//25	0E4: noise prop - normals - noise scale
	//26	0E8: noise prop - layer 1 - wind direction
	//27	0EC: noise prop - layer 2 - wind direction
	//28	0F0: noise prop - layer 3 - wind direction
	//29	0F4: noise prop - layer 1 - wind speed
	//30	0F8: noise prop - layer 2 - wind speed
	//31	0FC: noise prop - layer 3 - wind speed
	//32	100: noise prop - normals - depth falloff start
	//33	104: noise prop - normals - depth falloff end
	//34	108: fog prop - above water - fog amount
	//35	10C: noise prop - normals - UV scale
	//36	110: fog prop - under water - fog amount
	//37	114: fog prop - under water - fog distance (near plane)
	//38	118: fog prop - under water - fog distance (far plane)
	//39	11C: water prop - distortion amount
	//40	120: water prop - shininess
	//41	124: water prop - reflection HDR mult
	//42	128: water prop - light radius
	//43	12C: water prop - light brightness
	//44	130: noise prop - layer 1 - UV scale
	//45	134: noise prop - layer 2 - UV scale
	//46	138: noise prop - layer 3 - UV scale
	//47	13C: noise prop - layer 1 - amplitude scale
	//48	140: noise prop - layer 2 - amplitude scale
	//49	144: noise prop - layer 3 - amplitude scale

};
STATIC_ASSERT(offsetof(TESWaterForm, fullName) == 0x018);
STATIC_ASSERT(offsetof(TESWaterForm, waterForm) == 0x080);
STATIC_ASSERT(offsetof(TESWaterForm, actorEffect) == 0x178);
STATIC_ASSERT(sizeof(TESWaterForm) == 0x194);

// TESEffectShader (170)
class TESEffectShader : public TESForm
{
public:
	TESEffectShader();
	~TESEffectShader();

	UInt32 unk018[(0x170 - 0x18) >> 2];
};

// BGSExplosion (A4)
class BGSExplosion : public TESBoundObject
{
public:
	BGSExplosion();
	~BGSExplosion();

	enum
	{
		kFlags_Unknown = 1,
		kFlags_AlwaysUseWorldOrientation = 2,
		kFlags_KnockDownAlways = 4,
		kFlags_KnockDownByFormula = 8,
		kFlags_IgnoreLOSCheck = 16,
		kFlags_PushSourceRefOnly = 32,
		kFlags_IgnoreImageSpaceSwap = 64,
	};

	TESFullName					fullName;			// 030
	TESModel					model;				// 03C
	TESEnchantableForm			enchantable;		// 054
	BGSPreloadable				preloadable;		// 064
	TESImageSpaceModifiableForm	imageSpaceModForm;	// 068

	TESForm* placedObj;			// 070
	float						force;				// 074
	float						damage;				// 078
	float						radius;				// 07C
	TESObjectLIGH* light;				// 080
	TESSound* sound1;			// 084
	UInt32						explFlags;			// 088
	float						ISradius;			// 08C
	BGSImpactDataSet* impactDataSet;		// 090
	TESSound* sound2;			// 094
	float						RADlevel;			// 098
	float						dissipationTime;	// 09C
	float						RADradius;			// 0A0
	UInt8						soundLevel;			// A4	0 - Loud, 1 - Normal, 2 - Silent
	UInt8						padA5[3];			// A5

	void SetFlag(UInt32 flag, bool val)
	{
		explFlags = val ? (explFlags | flag) : (explFlags & ~flag);
	}
};

STATIC_ASSERT(sizeof(BGSExplosion) == 0xA8);

// BGSDebris (24)
class BGSDebris : public TESForm
{
	BGSDebris();
	~BGSDebris();

	BGSPreloadable				preloadable;	// 018
	UInt32	unk01C;
	UInt32	unk020;
};

// TESImageSpace (B0)
class TESImageSpace : public TESForm
{
public:
	TESImageSpace();
	~TESImageSpace();

	UInt32 unk018[(0xB0 - 0x18) >> 2];		// 018
};

STATIC_ASSERT(sizeof(TESImageSpace) == 0xB0);

// TESImageSpaceModifier (728)
class TESImageSpaceModifier : public TESForm
{
public:
	TESImageSpaceModifier();
	~TESImageSpaceModifier();

	UInt32 unk018[(0x728 - 0x18) >> 2];		// 018
};

STATIC_ASSERT(sizeof(TESImageSpaceModifier) == 0x728);

// 24
class BGSListForm : public TESForm
{
public:
	BGSListForm();
	~BGSListForm();

	tList<TESForm> list;			// 018

	UInt32	numAddedObjects;	// number of objects added via script - assumed to be at the start of the list

	UInt32 Count() const {
		return list.Count();
	}

	TESForm* GetNthForm(SInt32 n) const {
		return list.GetNthItem(n);
	}

	UInt32 AddAt(TESForm* pForm, SInt32 n) {
		SInt32	result = list.AddAt(pForm, n);

		if (result >= 0 && IsAddedObject(n))
			numAddedObjects++;

		return result;
	}

	SInt32 GetIndexOf(TESForm* pForm);

	TESForm* RemoveNthForm(SInt32 n) {
		TESForm* form = list.RemoveNth(n);

		if (form && IsAddedObject(n))
		{
			if (numAddedObjects == 0)
			{
				_MESSAGE("BGSListForm::RemoveNthForm: numAddedObjects = 0");
			}
			else
			{
				numAddedObjects--;
			}
		}

		return form;
	}

	TESForm* ReplaceNthForm(SInt32 n, TESForm* pReplaceWith) {
		return list.ReplaceNth(n, pReplaceWith);
	}

	SInt32 RemoveForm(TESForm* pForm);
	SInt32 ReplaceForm(TESForm* pForm, TESForm* pReplaceWith);

	bool IsAddedObject(SInt32 idx)
	{
		return (idx >= 0) && (idx < numAddedObjects);
	}

	void RemoveAll()
	{
		list.RemoveAll();
		numAddedObjects = 0;
	}
};

STATIC_ASSERT(sizeof(BGSListForm) == 0x024);

// 08
class BGSPerkEntry
{
public:
	BGSPerkEntry();
	~BGSPerkEntry();

	UInt32				vtbl;				// 00
	UInt8				rank;				// 04 +1 for value shown in GECK
	UInt8				priority;			// 05
	UInt16				type;				// 06 (Quest: 0xC24, Ability: 0xB27, Entry Point: 0xD16) 0xD15 for entryPoint?
};

// 10
class BGSQuestPerkEntry : public BGSPerkEntry
{
public:
	BGSQuestPerkEntry();
	~BGSQuestPerkEntry();

	TESQuest* quest;				// 08
	UInt8				stage;				// 0C
	UInt8				pad[3];				// 0D
};

// 0C
class BGSAbilityPerkEntry : public BGSPerkEntry
{
public:
	BGSAbilityPerkEntry();
	~BGSAbilityPerkEntry();

	SpellItem* ability;			// 08
};

class BGSEntryPointFunctionData
{
public:
	BGSEntryPointFunctionData();
	~BGSEntryPointFunctionData();

	UInt32				vtbl;				// 00
};

// 08
class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
{
public:
	BGSEntryPointFunctionDataOneValue();
	~BGSEntryPointFunctionDataOneValue();

	float				value;				// 04
};

// 0C
class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
public:
	BGSEntryPointFunctionDataTwoValue();
	~BGSEntryPointFunctionDataTwoValue();

	float				value[2];			// 04
};

class BGSEntryPointFunctionDataLeveledList : public BGSEntryPointFunctionData
{
public:
	BGSEntryPointFunctionDataLeveledList();
	~BGSEntryPointFunctionDataLeveledList();

	TESLevItem* leveledList;		// 04
};

class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
{
public:
	BGSEntryPointFunctionDataActivateChoice();
	~BGSEntryPointFunctionDataActivateChoice();

	String				label;				// 04
	Script* script;			// 0C
	UInt32				flags;				// 10 // 'Run Immediately'
};

struct EntryPointConditions
{
	tList<Condition>		tab1;
	tList<Condition>		tab2;
	tList<Condition>		tab3;
};

// 14
class BGSEntryPointPerkEntry : public BGSPerkEntry
{
public:
	BGSEntryPointPerkEntry();
	~BGSEntryPointPerkEntry();

	UInt8						entryPoint;		// 08
	UInt8						function;		// 09
	UInt8						conditionTabs;	// 0A
	UInt8						pad0B;			// 0B
	BGSEntryPointFunctionData* data;			// 0C
	struct
	{
		tList<Condition> tab1;
		tList<Condition> tab2;
		tList<Condition> tab3;
	}							*conditions;	// 10
};

// 50
class BGSPerk : public TESForm
{
public:
	BGSPerk();
	~BGSPerk();

	struct PerkData
	{
		UInt8				isTrait;	// 00
		UInt8				minLevel;	// 01
		UInt8				numRanks;	// 02
		UInt8				isPlayable;	// 03 unverified
		UInt8				isHidden;	// 04 unverified
		UInt8				pad05[3];		// 05 todo: collapse to pad[3] after verifying isPlayable and isHidden
	};

	TESFullName				fullName;			// 18
	TESDescription			description;		// 24
	TESIcon					icon;				// 2C
	PerkData				data;				// 38
	tList<Condition>		conditions;			// 40
	tList<BGSPerkEntry>		entries;			// 48
	bool IsPlayable() { return data.isPlayable ? true : false; }
	void SetPlayable(bool doset) { data.isPlayable = doset ? 1 : 0; }
};

// B0
class BGSBodyPart : public BaseFormComponent
{
public:
	BGSBodyPart();
	~BGSBodyPart();

	enum
	{
		kFlags_Severable = 1,
		kFlags_IKData = 2,
		kFlags_BipedData = 4,
		kFlags_Explodable = 8,
		kFlags_IsHead = 16,
		kFlags_Headtracking = 32,
		kFlags_Absolute = 64,
	};

	String				partNode;				// 04
	String				VATSTarget;				// 0C
	String				startNode;				// 14
	String				partName;				// 1C
	String				targetBone;				// 24
	TESModel			limbReplacement;		// 2C
	UInt32				unk44[6];				// 44	Another model?
	float				damageMult;				// 5C
	UInt8				flags;					// 60
	UInt8				pad61;					// 61
	UInt8				healthPercent;			// 62
	UInt8				actorValue;				// 63
	UInt8				toHitChance;			// 64
	UInt8				explChance;				// 65
	UInt8				explDebrisCount;		// 66
	UInt8				pad67;					// 67
	BGSDebris* explDebris;			// 68
	BGSExplosion* explExplosion;			// 6C
	float				trackingMaxAngle;		// 70
	float				explDebrisScale;		// 74
	UInt8				sevrDebrisCount;		// 78
	UInt8				pad79[3];				// 79
	BGSDebris* sevrDebris;			// 7C
	BGSExplosion* sevrExplosion;			// 80
	float				sevrDebrisScale;		// 84
	float				goreEffTranslate[3];	// 88
	float				goreEffRotation[3];		// 94
	BGSImpactDataSet* sevrImpactDS;			// A0
	BGSImpactDataSet* explImpactDS;			// A4
	UInt8				sevrDecalCount;			// A8
	UInt8				explDecalCount;			// A9
	UInt8				padAA[2];				// AA
	float				limbRepScale;			// AC

	void SetFlag(UInt32 pFlag, bool bMod)
	{
		flags = bMod ? (flags | pFlag) : (flags & ~pFlag);
	}
};

STATIC_ASSERT(sizeof(BGSBodyPart) == 0xB0);

// 74
class BGSBodyPartData : public TESForm
{
public:
	BGSBodyPartData();
	~BGSBodyPartData();

	enum
	{
		eBodyPart_Torso = 0,
		eBodyPart_Head1,
		eBodyPart_Head2,
		eBodyPart_LeftArm1,
		eBodyPart_LeftArm2,
		eBodyPart_RightArm1,
		eBodyPart_RightArm2,
		eBodyPart_LeftLeg1,
		eBodyPart_LeftLeg2,
		eBodyPart_LeftLeg3,
		eBodyPart_RightLeg1,
		eBodyPart_RightLeg2,
		eBodyPart_RightLeg3,
		eBodyPart_Brain,
		eBodyPart_Weapon,
	};

	TESModel		model;				// 018
	BGSPreloadable	preloadable;		// 030
	BGSBodyPart* bodyParts[15];		// 034
	BGSRagdoll* ragDoll;			// 070
};

STATIC_ASSERT(sizeof(BGSBodyPartData) == 0x74);

// BGSAddonNode (60)
class BGSAddonNode : public TESBoundObject
{
public:
	BGSAddonNode();
	~BGSAddonNode();

	TESModel	model;				// 030
	UInt32 unk48[(0x60 - 0x48) >> 2]; // 048
};

STATIC_ASSERT(sizeof(BGSAddonNode) == 0x60);

// ActorValueInfo (C4)
class ActorValueInfo : public TESForm {
public:
	UInt32 fill_018[(0x038 - 0x018) >> 2];		// 018 0037
	char* actorValueName;						// 038
	UInt32 fill_03C[(0x044 - 0x03C) >> 2];		// 03C 043
	UInt32 avFlags;								// 044
	//		bit 0x01	used in list of modified ActorValue for Player and others. Either can damage or "special damage", see 0x00937280
	//		bit 0x03
	//		bit 0x04
	//		bit 0x07
	//		bit 0x08
	//		bit 0x0B
	//		bit 0x0C
	//		bit 0x0E	canModify
	UInt32 unk_048;								// 048
	UInt32 unk_04C;								// 04C		// Address of callback used in GetValueInfo, result in st
	UInt32 unk_050;								// 050
	UInt32 unk_054;								// 054		// Address of a callback used in SetActorValue
	UInt32 fill_058[(0x098 - 0x058) >> 2];		// 058 097
	UInt32 unk_098;								// 098
	UInt32 fill_09C[(0x0C4 - 0x09C) >> 2];		// 09C 0C3
};

STATIC_ASSERT(sizeof(ActorValueInfo) == 0x0C4);

extern const ActorValueInfo** ActorValueInfoPointerArray;

typedef ActorValueInfo* (*_GetActorValueInfo)(UInt32 actorValueCode);
extern const _GetActorValueInfo GetActorValueInfo;

// BGSRadiationStage (20)
class BGSRadiationStage : public TESForm
{
public:
	BGSRadiationStage();
	~BGSRadiationStage();

	UInt32	unk018;			// 018
	UInt32	unk01C;			// 01C
};

// BGSCameraShot (78)
class BGSCameraShot : public TESForm
{
	BGSCameraShot();
	~BGSCameraShot();

	TESModel	model;								// 018
	//	TESImageSpaceModifiableForm imageSpaceModForm;	// 024

	UInt32 unk024[(0x78 - 0x24) >> 2];	// 024
};

// BGSCameraPath (38)
class BGSCameraPath;

// BGSVoiceType (24)
class BGSVoiceType : public TESForm
{
public:
	BGSVoiceType();
	~BGSVoiceType();

	UInt32		unk018;		// 018
	UInt32		unk01C;		// 01C
	UInt32		unk020;		// 020
};



struct DecalData
{
	float		minWidth;		// 000
	float		maxWidth;		// 004
	float		minHeight;		// 008
	float		maxHeight;		// 00C
	float		depth;			// 010
	float		shininess;		// 014
	float		parallaxScale;	// 018
	UInt8		parallaxPasses;	// 01C
	UInt8		flags;			// 01D	Parallax, Alpha - Blending, Alpha - Testing
	UInt8		unk01E[2];		// 01E
	ColorRGB	color;			// 020
};	// 024

STATIC_ASSERT(sizeof(DecalData) == 0x024);

// BGSImpactData (78)
class BGSImpactData : public TESForm
{
public:
	BGSImpactData();
	~BGSImpactData();

	struct Data
	{
		float	effectDuration;		// 000
		UInt32	effectorientation;	// 004	Surface Normal, Projectile vector, Projectile reflection
		float	angleThreshold;		// 008
		float	placementRadius;	// 00C
		UInt32	soundLevel;			// 010	enum
		UInt32	flags;				// 014	No decal data
	};	// 018

	TESModel	model;			// 018
	Data		data;			// 030	DATA
	TESTexture* textureSet;	// 048 DNAM Texture Set
	TESSound* sound1;		// 04C
	TESSound* sound2;		// 050
	DecalData	decalData;		// 054 DODT [begining of DATA before form version 0x0A]
};

STATIC_ASSERT(sizeof(BGSImpactData) == 0x078);

// 4C
class BGSImpactDataSet : public TESForm
{
public:
	BGSImpactDataSet();
	~BGSImpactDataSet();

	BGSPreloadable	preloadable;		// 018
	BGSImpactData* data[12];	// 01C
};

STATIC_ASSERT(offsetof(BGSImpactDataSet, preloadable) == 0x018);
STATIC_ASSERT(sizeof(BGSImpactDataSet) == 0x4C);

// TESObjectARMA (180)
class TESObjectARMA : public TESBoundObject
{
public:
	TESObjectARMA();
	~TESObjectARMA();

	TESFullName					fullName;				// 030
	TESScriptableForm			scriptable;				// 03C
	TESEnchantableForm			enchantable;			// 048
	TESValueForm				value;					// 058
	TESWeightForm				weight;					// 060
	TESHealthForm				health;					// 068
	TESBipedModelForm			bipedModelForm;			// 070
	BGSDestructibleObjectForm	destructible;			// 14C
	BGSEquipType				equipType;				// 154
	BGSRepairItemList			repairList;				// 15C
	BGSBipedModelList			bipedModelList;			// 164
	BGSPickupPutdownSounds		pickupPutdownSounds;	// 16C
	UInt32						unk178;					// 178			
	UInt32						unk17C;					// 17C
};

STATIC_ASSERT(sizeof(TESObjectARMA) == 0x180);

// BGSEncounterZone (30)
class BGSEncounterZone : public TESForm
{
public:
	BGSEncounterZone();
	~BGSEncounterZone();

	//UInt32 unk018[(0x30-0x18) >> 2];		// 018
	TESForm* owner;						// 018
	UInt8		rank;						// 01C
	UInt8		minLevel;					// 01D
	UInt8		zoneFlags;					// 01E
	UInt8		pad01C;						// 01F
	UInt32		unk020[(0x30 - 0x20) >> 2];		// 020
};

// BGSMessage (40)
class BGSMessage : public TESForm
{
public:
	BGSMessage();
	~BGSMessage();

	struct Button {
		String				buttonText;	// 000
		tList<Condition>	condition;	// 008
	};

	TESFullName		fullName;			// 018
	TESDescription	description;		// 024

	BGSMenuIcon* menuIcon;		// 2C
	tList<Button>	buttons;		// 030
	UInt32			messageFlags;	// 038 init'd to 1 1:MessageBox 2:Auto-display
	float			displayTime;	// 03C init'd to 2
};

STATIC_ASSERT(sizeof(BGSMessage) == 0x040);

// BGSRagdoll (148)
class BGSRagdoll : public TESForm
{
public:
	BGSRagdoll();
	~BGSRagdoll();

	TESModel	model;					// 018
	UInt32	unk030[(0x148 - 0x30) >> 2];	// 030
};

STATIC_ASSERT(sizeof(BGSRagdoll) == 0x148);

// BGSLightingTemplate (44)
class BGSLightingTemplate : public TESForm
{
public:
	BGSLightingTemplate();
	~BGSLightingTemplate();

	UInt32	unk018[(0x44 - 0x18) >> 2];
};

STATIC_ASSERT(sizeof(BGSLightingTemplate) == 0x44);

// BGSMusicType (30)
class BGSMusicType : public TESForm
{
public:
	BGSMusicType();
	~BGSMusicType();

	TESSoundFile		soundFile;	// 018
	UInt32	unk024;
	UInt32	unk028;
	UInt32	unk02C;
};

// BGSDefaultObjectManager, with help from "Luthien Anarion"

STATIC_ASSERT(sizeof(BGSMusicType) == 0x30);

const char kDefaultObjectNames[34][28] = {	// 0x0118C360 is an array of struct: { char * Name, UInt8 kFormType , UInt8 pad[3] }
	  "Stimpack",
	  "SuperStimpack",
	  "RadX",
	  "RadAway",
	  "Morphine",
	  "Perk Paralysis",
	  "Player Faction",
	  "Mysterious Stranger NPC",
	  "Mysterious Stranger Faction",
	  "Default Music",
	  "Battle Music",
	  "Death Music",
	  "Success Music",
	  "Level Up Music",
	  "Player Voice (Male)",
	  "Player Voice (Male Child)",
	  "Player Voice (Female)",
	  "Player Voice (Female Child)",
	  "Eat Package Default Food",
	  "Every Actor Ability",
	  "Drug Wears Off Image Space",
	  "Doctor's Bag",
	  "Miss Fortune NPC",
	  "Miss Fortune Faction",
	  "Meltdown Explosion",
	  "Unarmed Forward PA",
	  "Unarmed Backward PA",
	  "Unarmed Left PA",
	  "Unarmed Right PA",
	  "Unarmed Crouch PA",
	  "Unarmed Counter PA",
	  "Spotter Effect",
	  "Item Detected Effect",
	  "Cateye Mobile Effect (NYI)"
};

// BGSDefaultObjectManager (A0)
class BGSDefaultObjectManager : public TESForm
{
public:
	BGSDefaultObjectManager();
	~BGSDefaultObjectManager();

	static BGSDefaultObjectManager* GetSingleton();

	enum {
		kDefaultObject_Max = 34,
	};

	typedef TESForm* FormArray[kDefaultObject_Max];

	struct FormStruct {
		TESForm* Stimpak;
		TESForm* SuperStimpak;
		TESForm* RadX;
		TESForm* RadAway;
		TESForm* Morphine;
		TESForm* PerkParalysis;
		TESForm* PlayerFaction;
		TESForm* MysteriousStranger;
		TESForm* MysteriousStrangerFaction;
		TESForm* DefaultMusic;
		TESForm* BattleMusic;
		TESForm* DefaultDeath;
		TESForm* SuccessMusic;
		TESForm* LevelUpMusic;
		TESForm* PlayerVoiceMale;
		TESForm* PlayerVoiceMaleChild;
		TESForm* PlayerVoiceFemale;
		TESForm* PlayerVoiceFemaleChild;
		TESForm* EatPackageDefaultFood;
		TESForm* EveryActorAbility;
		TESForm* DrugWearOffImageSpace;
		// FNV
		TESForm* DoctorsBag;
		TESForm* MissFortuneNPC;
		TESForm* MissFortuneFaction;
		TESForm* MeltdownExplosion;
		TESForm* UnarmedForwardPA;
		TESForm* UnarmedBackwardPA;
		TESForm* UnarmedLeftPA;
		TESForm* UnarmedRightPA;
		TESForm* UnarmedCrouchPA;
		TESForm* UnarmedCounterPA;
		TESForm* SpotterEffect;
		TESForm* ItemDetectedEffect;
		TESForm* CateyeMobileEffectNYI;
	};

	union DefaultObjects {
		FormStruct	asStruct;
		FormArray	asArray;
	};

	DefaultObjects	defaultObjects;	// 018
};

STATIC_ASSERT(sizeof(BGSDefaultObjectManager) == 0xA0);

enum EActionListForm
{
	eActionListForm_AddAt = 00,
	eActionListForm_DelAt,
	eActionListForm_ChgAt,
	eActionListForm_GetAt,
	eActionListForm_Check,
	eActionListForm_Max,
};

enum EWhichListForm
{
	eWhichListForm_RaceHair = 00,
	eWhichListForm_RaceEyes,
	eWhichListForm_RaceHeadPart,			// ? //
	eWhichListForm_BaseFaction,
	eWhichListForm_BaseRank,
	eWhichListForm_BasePackage,
	eWhichListForm_BaseSpellListSpell,
	eWhichListForm_BaseSpellListLevSpell,
	eWhichListForm_FactionRankName,
	eWhichListForm_FactionRankFemaleName,
	eWhichListForm_HeadParts,
	eWhichListForm_LevCreatureRef,
	eWhichListForm_LevCharacterRef,
	eWhichListForm_FormList,
	eWhichListForm_Max,
};
