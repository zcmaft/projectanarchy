/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

//HK_REFLECTION_PARSER_EXCLUDE_FILE

// Autogenerated by generateReflections.py (reflectedClasses.py)
// Changes will not be lost unless:
// - The workspace is re-generated using build.py
// - The corresponding reflection database (reflection.db) is deleted
// - The --force-output or --force-rebuild option is added to the pre-build generateReflection.py execution

// Generated from 'Vision/Runtime/EnginePlugins/Havok/HavokPhysicsEnginePlugin/vHavokVisionShapes.h'
#include <Vision/Runtime/EnginePlugins/Havok/HavokPhysicsEnginePlugin/HavokPhysicsEnginePluginPCH.h>
#include <Common/Base/Reflection/hkClass.h>
#include <Common/Base/Reflection/hkInternalClassMember.h>
#include <Common/Base/Reflection/hkTypeInfo.h>
#include <Common/Base/Reflection/Attributes/hkAttributes.h>
#include <Vision/Runtime/EnginePlugins/Havok/HavokPhysicsEnginePlugin/vHavokVisionShapes.h>
#define True true
#define False false


// External pointer and enum types
extern const hkClass VTerrainSectorClass;
extern const hkClass hkBitFieldClass;
extern const hkClass hkvMeshMaterialClass;

//
// Class hkvConvexVerticesShape
//
extern const hkClass hkpConvexVerticesShapeClass;

const hkInternalClassMember hkvConvexVerticesShape::Members[] =
{
	{ "iFileTime", HK_NULL, HK_NULL, hkClassMember::TYPE_INT64, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvConvexVerticesShape,m_iFileTime), HK_NULL }
};
extern const hkClass hkvConvexVerticesShapeClass;
const hkClass hkvConvexVerticesShapeClass(
	"hkvConvexVerticesShape",
	&hkpConvexVerticesShapeClass, // parent
	sizeof(::hkvConvexVerticesShape),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkvConvexVerticesShape::Members),
	HK_COUNT_OF(hkvConvexVerticesShape::Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	hkUint32(0) // version
	);
#ifndef HK_HKCLASS_DEFINITION_ONLY
const hkClass& HK_CALL hkvConvexVerticesShape::staticClass()
{
	return hkvConvexVerticesShapeClass;
}
HK_COMPILE_TIME_ASSERT2( \
	sizeof(hkIsVirtual(static_cast<hkvConvexVerticesShape*>(0))) == sizeof(hkBool::CompileTimeTrueType), \
	REFLECTION_PARSER_VTABLE_DETECTION_FAILED );
static void HK_CALL finishLoadedObjecthkvConvexVerticesShape(void* p, int finishing = 1)
{
	hkFinishLoadedObjectFlag f;
	f.m_finishing = finishing;
	new (p) hkvConvexVerticesShape(f);
}
static void HK_CALL cleanupLoadedObjecthkvConvexVerticesShape(void* p)
{
	static_cast<hkvConvexVerticesShape*>(p)->~hkvConvexVerticesShape();
}
static const void* HK_CALL getVtablehkvConvexVerticesShape()
{
	#if HK_LINKONCE_VTABLES==0
	#if HK_HASHCODE_VTABLE_REGISTRY==1
	return ((const void*)(typeid(hkvConvexVerticesShape).hash_code()));
	#else
	return ((const void*)(typeid(hkvConvexVerticesShape).name()));
	#endif
	#else
	union { HK_ALIGN16(void* ptr); char buf[sizeof(hkvConvexVerticesShape)]; } u;
	hkFinishLoadedObjectFlag f;
	new (u.buf) hkvConvexVerticesShape(f);
	return u.ptr;
	#endif
}
extern const hkTypeInfo hkvConvexVerticesShapeTypeInfo;
const hkTypeInfo hkvConvexVerticesShapeTypeInfo(
	"hkvConvexVerticesShape",
	"!hkvConvexVerticesShape",
	finishLoadedObjecthkvConvexVerticesShape,
	cleanupLoadedObjecthkvConvexVerticesShape,
	getVtablehkvConvexVerticesShape(),
	sizeof(hkvConvexVerticesShape)
	);
#endif

//
// Class hkvMeshMaterial
//
static const hkInternalClassMember hkvMeshMaterialClass_Members[] =
{
	{ "fFriction", HK_NULL, HK_NULL, hkClassMember::TYPE_REAL, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvMeshMaterial,m_fFriction), HK_NULL },
	{ "fRestitution", HK_NULL, HK_NULL, hkClassMember::TYPE_REAL, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvMeshMaterial,m_fRestitution), HK_NULL },
	{ "userData", HK_NULL, HK_NULL, hkClassMember::TYPE_STRINGPTR, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvMeshMaterial,m_userData), HK_NULL },
	{ "iOrignalSubMeshIndex", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvMeshMaterial,m_iOrignalSubMeshIndex), HK_NULL }
};
const hkClass hkvMeshMaterialClass(
	"hkvMeshMaterial",
	HK_NULL, // parent
	sizeof(::hkvMeshMaterial),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkvMeshMaterialClass_Members),
	HK_COUNT_OF(hkvMeshMaterialClass_Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	hkUint32(0) // version
	);
#ifndef HK_HKCLASS_DEFINITION_ONLY
const hkClass& HK_CALL hkvMeshMaterial::staticClass()
{
	return hkvMeshMaterialClass;
}
HK_COMPILE_TIME_ASSERT2( \
	sizeof(hkIsVirtual(static_cast<hkvMeshMaterial*>(0))) == sizeof(hkBool::CompileTimeFalseType), \
	REFLECTION_PARSER_VTABLE_DETECTION_FAILED );
static void HK_CALL finishLoadedObjecthkvMeshMaterial(void* p, int finishing = 1)
{
	hkFinishLoadedObjectFlag f;
	f.m_finishing = finishing;
	new (p) hkvMeshMaterial(f);
}
static void HK_CALL cleanupLoadedObjecthkvMeshMaterial(void* p)
{
	static_cast<hkvMeshMaterial*>(p)->~hkvMeshMaterial();
}
extern const hkTypeInfo hkvMeshMaterialTypeInfo;
const hkTypeInfo hkvMeshMaterialTypeInfo(
	"hkvMeshMaterial",
	"!hkvMeshMaterial",
	finishLoadedObjecthkvMeshMaterial,
	cleanupLoadedObjecthkvMeshMaterial,
	HK_NULL,
	sizeof(hkvMeshMaterial)
	);
#endif

//
// Class hkvBvCompressedMeshShape
//
extern const hkClass hkpBvCompressedMeshShapeClass;

const hkInternalClassMember hkvBvCompressedMeshShape::Members[] =
{
	{ "iFileTime", HK_NULL, HK_NULL, hkClassMember::TYPE_INT64, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvBvCompressedMeshShape,m_iFileTime), HK_NULL },
	{ "materials", &hkvMeshMaterialClass, HK_NULL, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_STRUCT, 0, 0, HK_OFFSET_OF(hkvBvCompressedMeshShape,m_materials), HK_NULL }
};
extern const hkClass hkvBvCompressedMeshShapeClass;
const hkClass hkvBvCompressedMeshShapeClass(
	"hkvBvCompressedMeshShape",
	&hkpBvCompressedMeshShapeClass, // parent
	sizeof(::hkvBvCompressedMeshShape),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkvBvCompressedMeshShape::Members),
	HK_COUNT_OF(hkvBvCompressedMeshShape::Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	hkUint32(0) // version
	);
#ifndef HK_HKCLASS_DEFINITION_ONLY
const hkClass& HK_CALL hkvBvCompressedMeshShape::staticClass()
{
	return hkvBvCompressedMeshShapeClass;
}
HK_COMPILE_TIME_ASSERT2( \
	sizeof(hkIsVirtual(static_cast<hkvBvCompressedMeshShape*>(0))) == sizeof(hkBool::CompileTimeTrueType), \
	REFLECTION_PARSER_VTABLE_DETECTION_FAILED );
static void HK_CALL finishLoadedObjecthkvBvCompressedMeshShape(void* p, int finishing = 1)
{
	hkFinishLoadedObjectFlag f;
	f.m_finishing = finishing;
	new (p) hkvBvCompressedMeshShape(f);
}
static void HK_CALL cleanupLoadedObjecthkvBvCompressedMeshShape(void* p)
{
	static_cast<hkvBvCompressedMeshShape*>(p)->~hkvBvCompressedMeshShape();
}
static const void* HK_CALL getVtablehkvBvCompressedMeshShape()
{
	#if HK_LINKONCE_VTABLES==0
	#if HK_HASHCODE_VTABLE_REGISTRY==1
	return ((const void*)(typeid(hkvBvCompressedMeshShape).hash_code()));
	#else
	return ((const void*)(typeid(hkvBvCompressedMeshShape).name()));
	#endif
	#else
	union { HK_ALIGN16(void* ptr); char buf[sizeof(hkvBvCompressedMeshShape)]; } u;
	hkFinishLoadedObjectFlag f;
	new (u.buf) hkvBvCompressedMeshShape(f);
	return u.ptr;
	#endif
}
extern const hkTypeInfo hkvBvCompressedMeshShapeTypeInfo;
const hkTypeInfo hkvBvCompressedMeshShapeTypeInfo(
	"hkvBvCompressedMeshShape",
	"!hkvBvCompressedMeshShape",
	finishLoadedObjecthkvBvCompressedMeshShape,
	cleanupLoadedObjecthkvBvCompressedMeshShape,
	getVtablehkvBvCompressedMeshShape(),
	sizeof(hkvBvCompressedMeshShape)
	);
#endif

//
// Class hkvSampledHeightFieldShape
//
extern const hkClass hkpSampledHeightFieldShapeClass;

const hkInternalClassMember hkvSampledHeightFieldShape::Members[] =
{
	{ "pSector", HK_NULL, HK_NULL, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_VOID, 0, 0|hkClassMember::SERIALIZE_IGNORED, HK_OFFSET_OF(hkvSampledHeightFieldShape,m_pSector), HK_NULL },
	{ "iTerrainIndex", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvSampledHeightFieldShape,m_iTerrainIndex), HK_NULL },
	{ "iSectorIndexX", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvSampledHeightFieldShape,m_iSectorIndexX), HK_NULL },
	{ "iSectorIndexY", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvSampledHeightFieldShape,m_iSectorIndexY), HK_NULL }
};
extern const hkClass hkvSampledHeightFieldShapeClass;
const hkClass hkvSampledHeightFieldShapeClass(
	"hkvSampledHeightFieldShape",
	&hkpSampledHeightFieldShapeClass, // parent
	sizeof(::hkvSampledHeightFieldShape),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkvSampledHeightFieldShape::Members),
	HK_COUNT_OF(hkvSampledHeightFieldShape::Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	hkUint32(0) // version
	);
#ifndef HK_HKCLASS_DEFINITION_ONLY
const hkClass& HK_CALL hkvSampledHeightFieldShape::staticClass()
{
	return hkvSampledHeightFieldShapeClass;
}
HK_COMPILE_TIME_ASSERT2( \
	sizeof(hkIsVirtual(static_cast<hkvSampledHeightFieldShape*>(0))) == sizeof(hkBool::CompileTimeTrueType), \
	REFLECTION_PARSER_VTABLE_DETECTION_FAILED );
static void HK_CALL finishLoadedObjecthkvSampledHeightFieldShape(void* p, int finishing = 1)
{
	hkFinishLoadedObjectFlag f;
	f.m_finishing = finishing;
	new (p) hkvSampledHeightFieldShape(f);
}
static void HK_CALL cleanupLoadedObjecthkvSampledHeightFieldShape(void* p)
{
	static_cast<hkvSampledHeightFieldShape*>(p)->~hkvSampledHeightFieldShape();
}
static const void* HK_CALL getVtablehkvSampledHeightFieldShape()
{
	#if HK_LINKONCE_VTABLES==0
	#if HK_HASHCODE_VTABLE_REGISTRY==1
	return ((const void*)(typeid(hkvSampledHeightFieldShape).hash_code()));
	#else
	return ((const void*)(typeid(hkvSampledHeightFieldShape).name()));
	#endif
	#else
	union { HK_ALIGN16(void* ptr); char buf[sizeof(hkvSampledHeightFieldShape)]; } u;
	hkFinishLoadedObjectFlag f;
	new (u.buf) hkvSampledHeightFieldShape(f);
	return u.ptr;
	#endif
}
extern const hkTypeInfo hkvSampledHeightFieldShapeTypeInfo;
const hkTypeInfo hkvSampledHeightFieldShapeTypeInfo(
	"hkvSampledHeightFieldShape",
	"!hkvSampledHeightFieldShape",
	finishLoadedObjecthkvSampledHeightFieldShape,
	cleanupLoadedObjecthkvSampledHeightFieldShape,
	getVtablehkvSampledHeightFieldShape(),
	sizeof(hkvSampledHeightFieldShape)
	);
#endif

//
// Class hkvTriSampledHeightFieldCollection
//
extern const hkClass hkpTriSampledHeightFieldCollectionClass;

const hkInternalClassMember hkvTriSampledHeightFieldCollection::Members[] =
{
	{ "iCollide", HK_NULL, HK_NULL, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvTriSampledHeightFieldCollection,m_iCollide), HK_NULL },
	{ "iNonCollide", HK_NULL, HK_NULL, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvTriSampledHeightFieldCollection,m_iNonCollide), HK_NULL },
	{ "iStrideX", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvTriSampledHeightFieldCollection,m_iStrideX), HK_NULL },
	{ "iTileSamplesX", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvTriSampledHeightFieldCollection,m_iTileSamplesX), HK_NULL },
	{ "iTileSamplesY", HK_NULL, HK_NULL, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvTriSampledHeightFieldCollection,m_iTileSamplesY), HK_NULL },
	{ "tileHoleMask", &hkBitFieldClass, HK_NULL, hkClassMember::TYPE_STRUCT, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkvTriSampledHeightFieldCollection,m_tileHoleMask), HK_NULL }
};
extern const hkClass hkvTriSampledHeightFieldCollectionClass;
const hkClass hkvTriSampledHeightFieldCollectionClass(
	"hkvTriSampledHeightFieldCollection",
	&hkpTriSampledHeightFieldCollectionClass, // parent
	sizeof(::hkvTriSampledHeightFieldCollection),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkvTriSampledHeightFieldCollection::Members),
	HK_COUNT_OF(hkvTriSampledHeightFieldCollection::Members),
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	hkUint32(0) // version
	);
#ifndef HK_HKCLASS_DEFINITION_ONLY
const hkClass& HK_CALL hkvTriSampledHeightFieldCollection::staticClass()
{
	return hkvTriSampledHeightFieldCollectionClass;
}
HK_COMPILE_TIME_ASSERT2( \
	sizeof(hkIsVirtual(static_cast<hkvTriSampledHeightFieldCollection*>(0))) == sizeof(hkBool::CompileTimeTrueType), \
	REFLECTION_PARSER_VTABLE_DETECTION_FAILED );
static void HK_CALL finishLoadedObjecthkvTriSampledHeightFieldCollection(void* p, int finishing = 1)
{
	hkFinishLoadedObjectFlag f;
	f.m_finishing = finishing;
	new (p) hkvTriSampledHeightFieldCollection(f);
}
static void HK_CALL cleanupLoadedObjecthkvTriSampledHeightFieldCollection(void* p)
{
	static_cast<hkvTriSampledHeightFieldCollection*>(p)->~hkvTriSampledHeightFieldCollection();
}
static const void* HK_CALL getVtablehkvTriSampledHeightFieldCollection()
{
	#if HK_LINKONCE_VTABLES==0
	#if HK_HASHCODE_VTABLE_REGISTRY==1
	return ((const void*)(typeid(hkvTriSampledHeightFieldCollection).hash_code()));
	#else
	return ((const void*)(typeid(hkvTriSampledHeightFieldCollection).name()));
	#endif
	#else
	union { HK_ALIGN16(void* ptr); char buf[sizeof(hkvTriSampledHeightFieldCollection)]; } u;
	hkFinishLoadedObjectFlag f;
	new (u.buf) hkvTriSampledHeightFieldCollection(f);
	return u.ptr;
	#endif
}
extern const hkTypeInfo hkvTriSampledHeightFieldCollectionTypeInfo;
const hkTypeInfo hkvTriSampledHeightFieldCollectionTypeInfo(
	"hkvTriSampledHeightFieldCollection",
	"!hkvTriSampledHeightFieldCollection",
	finishLoadedObjecthkvTriSampledHeightFieldCollection,
	cleanupLoadedObjecthkvTriSampledHeightFieldCollection,
	getVtablehkvTriSampledHeightFieldCollection(),
	sizeof(hkvTriSampledHeightFieldCollection)
	);
#endif

//
// Class hkvTriSampledHeightFieldBvTreeShape
//
extern const hkClass hkpTriSampledHeightFieldBvTreeShapeClass;

extern const hkClass hkvTriSampledHeightFieldBvTreeShapeClass;
const hkClass hkvTriSampledHeightFieldBvTreeShapeClass(
	"hkvTriSampledHeightFieldBvTreeShape",
	&hkpTriSampledHeightFieldBvTreeShapeClass, // parent
	sizeof(::hkvTriSampledHeightFieldBvTreeShape),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	HK_NULL,
	0,
	HK_NULL, // defaults
	HK_NULL, // attributes
	0, // flags
	hkUint32(0) // version
	);
#ifndef HK_HKCLASS_DEFINITION_ONLY
const hkClass& HK_CALL hkvTriSampledHeightFieldBvTreeShape::staticClass()
{
	return hkvTriSampledHeightFieldBvTreeShapeClass;
}
HK_COMPILE_TIME_ASSERT2( \
	sizeof(hkIsVirtual(static_cast<hkvTriSampledHeightFieldBvTreeShape*>(0))) == sizeof(hkBool::CompileTimeTrueType), \
	REFLECTION_PARSER_VTABLE_DETECTION_FAILED );
static void HK_CALL finishLoadedObjecthkvTriSampledHeightFieldBvTreeShape(void* p, int finishing = 1)
{
	hkFinishLoadedObjectFlag f;
	f.m_finishing = finishing;
	new (p) hkvTriSampledHeightFieldBvTreeShape(f);
}
static void HK_CALL cleanupLoadedObjecthkvTriSampledHeightFieldBvTreeShape(void* p)
{
	static_cast<hkvTriSampledHeightFieldBvTreeShape*>(p)->~hkvTriSampledHeightFieldBvTreeShape();
}
static const void* HK_CALL getVtablehkvTriSampledHeightFieldBvTreeShape()
{
	#if HK_LINKONCE_VTABLES==0
	#if HK_HASHCODE_VTABLE_REGISTRY==1
	return ((const void*)(typeid(hkvTriSampledHeightFieldBvTreeShape).hash_code()));
	#else
	return ((const void*)(typeid(hkvTriSampledHeightFieldBvTreeShape).name()));
	#endif
	#else
	union { HK_ALIGN16(void* ptr); char buf[sizeof(hkvTriSampledHeightFieldBvTreeShape)]; } u;
	hkFinishLoadedObjectFlag f;
	new (u.buf) hkvTriSampledHeightFieldBvTreeShape(f);
	return u.ptr;
	#endif
}
extern const hkTypeInfo hkvTriSampledHeightFieldBvTreeShapeTypeInfo;
const hkTypeInfo hkvTriSampledHeightFieldBvTreeShapeTypeInfo(
	"hkvTriSampledHeightFieldBvTreeShape",
	"!hkvTriSampledHeightFieldBvTreeShape",
	finishLoadedObjecthkvTriSampledHeightFieldBvTreeShape,
	cleanupLoadedObjecthkvTriSampledHeightFieldBvTreeShape,
	getVtablehkvTriSampledHeightFieldBvTreeShape(),
	sizeof(hkvTriSampledHeightFieldBvTreeShape)
	);
#endif

/*
 * Havok SDK - Base file, BUILD(#20130624)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available from salesteam@havok.com.
 * 
 */
