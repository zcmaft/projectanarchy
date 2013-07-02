/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_STATIC_COMPOUND_AGENT_H
#define HK_STATIC_COMPOUND_AGENT_H

#include <Physics2012/Collide/Agent/CompoundAgent/BvTree/hkpBvTreeAgent.h>

class hkpCollisionDispatcher;

/// Agent used to handle collisions with hkpStaticCompoundShape
class hkpStaticCompoundAgent : public hkpBvTreeAgent
{	
	public:

		enum
		{
			// Maximum number of results that can be obtained from an AABB query
#if !defined(HK_PLATFORM_HAS_SPU)
			HK_MAX_NUM_HITS_PER_AABB_QUERY = 2048
#else
			HK_MAX_NUM_HITS_PER_AABB_QUERY = 1024
#endif
		};

	public:

		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE);

			/// Registers this agent with the collision dispatcher
		static void HK_CALL registerAgent(hkpCollisionDispatcher* dispatcher);

			/// Used by the collision dispatcher to create an agent for collisions between a shape of any type and a hkpBvCompressedMeshShape
		static hkpCollisionAgent* HK_CALL createShapeVsStaticCompoundAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr);

			/// Used by the collision dispatcher to create an agent for collisions between a hkpBvCompressedMeshShape and a shape of any type
		static hkpCollisionAgent* HK_CALL createStaticCompoundVsShapeAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr);

			/// Used by the collision dispatcher to create an agent for collisions between two hkpBvCompressedMeshShape shapes
		static hkpCollisionAgent* HK_CALL createStaticCompoundVsStaticCompoundAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpCollisionInput& input, hkpContactMgr* mgr);


		/////////////////////////////////
		// hkpCollisionAgent interface	

			/// hkpCollisionAgent interface implementation, refer to that class for details
		virtual void linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);

			/// Static version of linearCast for its use in dispatchers
		static void HK_CALL staticLinearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkpLinearCastCollisionInput& input, hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);		

	#if defined(HK_PLATFORM_SPU)

			/// Initializes the agent functions in a hkpSpuCollisionQueryDispatcher
		static void HK_CALL initAgentFunc(hkpSpuCollisionQueryDispatcher::AgentFuncs& f);

			/// Initializes the inverse agent functions in a hkpSpuCollisionQueryDispatcher
		static void HK_CALL initAgentFuncInverse(hkpSpuCollisionQueryDispatcher::AgentFuncs& f);

	#endif

	protected:

			/// Constructor, called by the agent creation function.
		hkpStaticCompoundAgent(hkpContactMgr* mgr);
};


#endif // HK_STATIC_COMPOUND_AGENT_H

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
