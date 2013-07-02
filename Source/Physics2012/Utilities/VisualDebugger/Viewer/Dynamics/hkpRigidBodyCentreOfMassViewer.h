/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_UTILITIES2_RIGIDBODY_CENTREOFMASS_VIEWER_H
#define HK_UTILITIES2_RIGIDBODY_CENTREOFMASS_VIEWER_H

#include <Physics2012/Utilities/VisualDebugger/Viewer/Dynamics/hkpWorldViewerBase.h>
#include <Physics2012/Dynamics/World/Listener/hkpWorldPostSimulationListener.h>
#include <Physics2012/Dynamics/Entity/hkpEntityListener.h>

class hkDebugDisplayHandler;
class hkpWorld;
class hkpRigidBody;

	/// Shows the centre of mass of all rigid bodies added to the world.
class hkpRigidBodyCentreOfMassViewer :	public hkpWorldViewerBase,
								protected hkpEntityListener, protected hkpWorldPostSimulationListener
{
	public:
	HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE);
			/// Creates a hkpRigidBodyCentreOfMassViewer.
		static hkProcess* HK_CALL create(const hkArray<hkProcessContext*>& contexts);

			/// Registers the hkpRigidBodyCentreOfMassViewer with the hkProcessFactory.
		static void HK_CALL registerViewer();

			/// Gets the tag associated with this viewer type
		virtual int getProcessTag() { return m_tag; }

		virtual void init();

		static inline const char* HK_CALL getName() { return "Center of Mass"; }

	protected:

		hkpRigidBodyCentreOfMassViewer(const hkArray<hkProcessContext*>& contexts);
		virtual ~hkpRigidBodyCentreOfMassViewer();

		void addWorld(hkpWorld* world);
		void removeWorld(hkpWorld* world);

		virtual void entityAddedCallback( hkpEntity* entity );
		virtual void entityRemovedCallback( hkpEntity* entity );

		virtual void postSimulationCallback( hkpWorld* world );

		virtual void worldAddedCallback( hkpWorld* world );
		virtual void worldRemovedCallback( hkpWorld* world );

	protected:
		static int m_tag;

		hkArray<hkpRigidBody*> m_entitiesCreated;

	public:
		static hkReal m_scale;
};

#endif	// HK_UTILITIES2_RIGIDBODY_CENTREOFMASS_VIEWER_H

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
