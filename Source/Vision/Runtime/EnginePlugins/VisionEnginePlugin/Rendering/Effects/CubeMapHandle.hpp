/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

/// \file CubeMapHandle.hpp

//***********************************************************************
// CubeMapHandle_cl Class
//***********************************************************************

#ifndef CUBEMAPHANDLE_HPP_INCLUDED
#define CUBEMAPHANDLE_HPP_INCLUDED

#include <Vision/Runtime/EnginePlugins/VisionEnginePlugin/Rendering/Effects/EffectsModule.hpp>

class FlipAndBlurRenderLoop_cl;
 
/// \brief
///   The CubeMapHandle_cl class is an entity class used for rendering a cubemap at the entity's
///   position.
/// 
/// The cubemap textures generated by this entity class can be referenced by the cubemap's key.
/// 
/// This class is intended for use as part of the Cubemap Shape in vForge and generally shouldn't be used
/// directly through the API.
class CubeMapHandle_cl : public VisBaseEntity_cl, public IVisCallbackHandler_cl
{
  friend class FlipAndBlurRenderLoop_cl;

public:
  /// \brief
  ///   Cube Map handle constructor
  EFFECTS_IMPEXP CubeMapHandle_cl();

  /// \brief
  ///   Cube Map handle destructor
  EFFECTS_IMPEXP virtual ~CubeMapHandle_cl();

  /// \brief
  ///   Enables dynamic cubemap rendering.
  EFFECTS_IMPEXP void SetActivate(bool bStatus);

  /// \brief
  ///   Returns the texture object associated with this cubemap instance
  inline VTextureObject* GetCubeMapTexture()
  { 
    #ifdef SUPPORTS_RENDERABLE_CUBEMAPS
      return m_spCubemap;
    #else
      VASSERT_ALWAYS_MSG(false, "Renderable cubemaps are not supported on this platform!");
      return NULL;
    #endif
  }

  /// \brief
  ///   Sets the near and far clip planes for cubemap rendering. Both can be <0 to use the main
  ///   context's distances
  EFFECTS_IMPEXP void SetClipPlanes(float fNear, float fFar);

  /// \brief
  ///   Returns the clip plane distances set via SetClipPlanes
  inline void GetClipPlanes(float &fNear, float &fFar) const 
  { 
    fNear = m_fNearClipPlane;
    fFar = m_fFarClipPlane; 
  }


  /// \brief
  ///   Sets edge size of the cubemap. Must be a power of two
  inline void SetSize(int iNewSize) 
  {
    SetCubemapKey(GetEntityKey(), iNewSize);
  }


  /// \brief
  ///   Returns the edge size of the cubemap
  inline int  GetSize() const { return m_iSize; }

  /// \brief
  ///   Sets the flag for continuous cubemap update. If false, the cubemap gets only rendered at
  ///   creation time
  EFFECTS_IMPEXP void SetContinuousUpdate(bool bStatus);

  /// \brief
  ///   If enabled, only one cubemap face is rendered per frame/update rather than all six faces at the same time. The default status is false.
  inline void SetAlternatingUpdate(bool bStatus)
  {
    m_bAlternateUpdate = bStatus;
    m_iCurrentFaceMask = 0xff;
  }

  /// \brief
  ///   Gets the flag for continuous cubemap update
  inline bool GetContinuousUpdate() const { return m_bContinuousUpdate==TRUE; }

  /// \brief
  ///   Sets the update interval (in seconds). Interval can be set to 0.0 to update every frame.
  inline void SetUpdateParams(float fInterval, int iUnused = 0)
  {
    m_fUpdateInterval=fInterval; 
  }

  /// \brief
  ///   Returns the update parameters (see SetUpdateParams)
  inline void GetUpdateParams(float &fInterval, int &iUnused) const
  {
    fInterval=m_fUpdateInterval;
    iUnused = 0;
  }
  
  /// \brief
  ///   Sets a render filter bitmask that is used for rendering scene elements. Forwards to
  ///   VisRenderContext_cl::SetRenderFilterMask
  EFFECTS_IMPEXP void SetRenderFilterMask(int iMask);

  /// \brief
  ///   Returns the render filter bitmask. THe default is VIS_ENTITY_VISIBLE_IN_CUBEMAP
  inline int GetRenderFilterMask() const 
  {
    return m_iRenderFilterMask;
  }

  /// \brief
  ///   Sets a custom render loop for cubemap rendering.
  EFFECTS_IMPEXP void SetRenderLoop(IVisRenderLoop_cl *pLoop);

  /// \brief
  ///   Returns the current render loop instance. First defaults to the default cubemap render
  ///   loop, then to an instance of VisionRenderLoop_cl
  EFFECTS_IMPEXP IVisRenderLoop_cl* GetRenderLoop();

  /// \brief
  ///  Sets a renderer node to use for rendering the cubemap faces instead of a render loop.
  ///
  /// Due to the overhead of using a full renderer node, using this feature is not recommended
  /// for use with dynamic cube maps, but for generating accurate reflections in vForge.
  /// Currently, the renderer node setting will not be serialized into the exported scene.
  ///
  /// \param pRendererNode
  ///  The renderer node that will be used. Must be deinitialized and not have a final target context yet.
  EFFECTS_IMPEXP void SetRendererNode(IVRendererNode* pRendererNode);

  /// \brief
  ///  Gets the currently used renderer node.
  EFFECTS_IMPEXP IVRendererNode* GetRendererNode();

  /// \brief
  ///   Associates a texture filename with the cubemap.
  EFFECTS_IMPEXP void SetCubemapKey(const char *szKey, int iEdgeSize);

  /// \brief
  ///   Forces a cubemap update next frame.
  EFFECTS_IMPEXP void Invalidate();

  /// \brief
  ///   Sets the number of gaussian blur passes applied to the cubemap each time it is updated
  ///   (significantly affects performance!)
  EFFECTS_IMPEXP void SetBlurPasses(int iPasses);

  /// \brief
  ///   Returns the number of gaussian blur passes applied to the cubemap each time it is updated
  EFFECTS_IMPEXP int GetBlurPasses() const;

  /// \brief
  ///   Enables/disables automatic mipmap generation for this cubemap (affects performance)
  EFFECTS_IMPEXP void SetAutoGenMipMaps(bool bStatus);

  /// \brief
  ///   Enables/disables automatic mipmap generation for this cubemap (affects performance)
  EFFECTS_IMPEXP bool GetAutoGenMipMaps() const;

  /// \brief
  ///   Sets the default render loop to be used for all cubemaps that don't have a render loop
  ///   explicitly specified.
  EFFECTS_IMPEXP static void SetDefaultRenderLoop(IVisRenderLoop_cl *pRenderLoop);

  /// \brief
  ///   Returns the currently set default render loop for cubemaps.
  EFFECTS_IMPEXP static IVisRenderLoop_cl *GetDefaultRenderLoop();


  protected:
  // internal functions:
  void InitContexts();

  void DeInitContexts();
  void EnableRendering();
  void DisableRendering();
  bool WasRecentlyRendered() const;

  void SetContextOrientation();

  void CreateBlurTarget();
  void CreateBlurTechnique();

  void DestroyBlurTarget();
  void FlipAndBlur(int iFace);



  // overridden functions
  virtual void InitFunction() HKV_OVERRIDE;
  virtual void DeInitFunction() HKV_OVERRIDE;
  void UpdateFaceStatus();
  
  virtual void OnHandleCallback(IVisCallbackDataObject_cl *pData) HKV_OVERRIDE;
 
  //serialization
  V_DECLARE_SERIAL_DLLEXP( CubeMapHandle_cl,  EFFECTS_IMPEXP )
  EFFECTS_IMPEXP virtual void Serialize( VArchive &ar ) HKV_OVERRIDE;
  IMPLEMENT_OBJ_CLASS(CubeMapHandle_cl);
#ifdef SUPPORTS_SNAPSHOT_CREATION
  virtual void GetDependencies(VResourceSnapshot &snapshot) HKV_OVERRIDE;
#endif

private:
  VisRenderableCubeMapPtr m_spCubemap;
  VisRenderableTexturePtr m_spDepthTarget;

  // Face update related status
  float m_fElapsedTime;     /// Time since last update
  bool m_bUpdateForced;     /// Update forced in the next frame
  bool m_bRenderingEnabled; /// Rendering is enabled in the next frame (m_bUpdateForced || m_bContinuousUpdate) and callbacks are registered
  int m_iCurrentFace;       /// Current active face when m_bAlternateUpdate is true
  int m_iCurrentFaceMask;   /// ORed bitmask of the face indices to be rendered

  // properties
  bool m_bActive;           /// Dynamic rendering is enabled (in general), graphics resources are allocated
  BOOL m_bGenMipMaps;       /// Auto-create mip maps
  int m_iBlurPasses;        /// Number of blur passes
  int m_iSize;              /// Resolution of the cubemap face
  BOOL m_bContinuousUpdate; /// Update the faces continuously
  float m_fUpdateInterval;  /// Time in seconds between updates
  bool m_bAlternateUpdate;  /// Update faces alternatingly instead of at once

  float m_fNearClipPlane;   /// Near plane
  float m_fFarClipPlane;    /// Far plane
  int m_iRenderFilterMask;  /// Entity filter mask for rendering

  VisRenderContextPtr m_spRenderContext[6];

  IVisRenderLoopPtr m_spRenderLoop;

  IVRendererNodePtr m_spRendererNode;

  VisRenderableTexturePtr m_spBlurTarget[2];
  VisRenderContextPtr m_spBlurContext[2];
  VCompiledTechniquePtr m_spBlurTechnique;
  VConstantBufferRegister m_blurStepRegister;

  static IVisRenderLoopPtr s_spDefaultRenderLoop;
};

#endif  // CUBEMAPHANDLE_HPP_INCLUDED

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
