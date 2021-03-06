/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */
#include <Vision/Samples/Engine/RPGPlugin/Precompiled.h>

#include <Vision/Samples/Engine/RPGPlugin/VisionTimer.h>

RPG_VisionTimer::RPG_VisionTimer()
  : VDefaultTimer()
{
  // vForge calls Init but vSceneViewer doesn't
  Init();
}

void RPG_VisionTimer::Update()
{
  float const physicsTimeStep = vHavokPhysicsModule::GetInstance()->GetPhysicsTimeStep();
  float accumulatedTimeDifference = 0.0f;

  // Limit frame rate:
  // Basically prevent ThinkFunction from being called more frequently than the physics update
  for(;;)
  {
    VDefaultTimer::Update();

    accumulatedTimeDifference += GetTimeDifference();
    if ( (accumulatedTimeDifference < 1e-6f) || (accumulatedTimeDifference >= physicsTimeStep) )
      break;
  }

  if(accumulatedTimeDifference > GetMaxTimeDifference())
    accumulatedTimeDifference = GetMaxTimeDifference();

  SetTimeDifference(accumulatedTimeDifference);
}

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
