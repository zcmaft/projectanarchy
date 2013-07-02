/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */
#include <Vision/Samples/Engine/RPGPlugin/Precompiled.h>

#include <Vision/Samples/Engine/RPGPlugin/ManaPickup.h>

#include <Vision/Samples/Engine/RPGPlugin/GameManager.h>
#include <Vision/Samples/Engine/RPGPlugin/Character.h>
#include <Vision/Samples/Engine/RPGPlugin/PlayerCharacter.h>

V_IMPLEMENT_SERIAL(RPG_ManaPickup, RPG_Pickup, 0, &g_RPGPluginModule);

START_VAR_TABLE(RPG_ManaPickup, RPG_Pickup, "A mana pickup item. Gives mana to a character when used.", 0, "");
  DEFINE_VAR_INT(RPG_ManaPickup, m_manaAmount, "The amount of mana to give", "5", 0, 0);
END_VAR_TABLE



RPG_ManaPickup::RPG_ManaPickup() 
: RPG_Pickup()
, m_manaAmount(5)
{
}

void RPG_ManaPickup::OnPickup(RPG_Character* character)
{
  // add mana to character
  character->AddMana(m_manaAmount);
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
