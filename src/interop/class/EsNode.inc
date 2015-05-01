



//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _EsNodeMetaString	"DDGraphics_EsNode"

struct EsNodeWrapper
{

  void addSub(EsNodeWrapper* p1)
  {
    _ref->addSub(p1->_ref);
  }
  void setColor(float p1,float p2,float p3,float p4)
  {
    _ref->setColor(p1,p2,p3,p4);
  }
  void setScale(float p1,float p2,float p3)
  {
    _ref->setScale(p1,p2,p3);
  }
  void setTransform(float p1,float p2,float p3)
  {
    _ref->setTransform(p1,p2,p3);
  }
  void setRotate(float p1,float p2,float p3,float p4)
  {
    _ref->setRotate(p1,p2,p3,p4);
  }
  void setVisible(bool p1)
  {
    _ref->setVisible(p1);
  }
  EsNode* _ref;
  static const char* MetaName;
};


const char* EsNodeWrapper::MetaName = _EsNodeMetaString;



static int EsNode_addSub(lua_State *L) 
{
	if(lua_gettop(L)!=2){
		luaL_error(L, "Need %d parameters for %s", 2, __FUNCTION__);
	}


  EsNodeWrapper* p1 = checkUserData<EsNodeWrapper>(L, 1);
  EsNodeWrapper* p2 = checkUserData<EsNodeWrapper>(L, 2);
  p1->addSub(p2);
  return 0;
}



static int EsNode_setColor(lua_State *L) 
{
	if(lua_gettop(L)!=5){
		luaL_error(L, "Need %d parameters for %s", 5, __FUNCTION__);
	}


  EsNodeWrapper* p1 = checkUserData<EsNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  float p3 = lua_tonumber(L, 3);
  float p4 = lua_tonumber(L, 4);
  float p5 = lua_tonumber(L, 5);
  p1->setColor(p2,p3,p4,p5);
  return 0;
}



static int EsNode_setScale(lua_State *L) 
{
	if(lua_gettop(L)!=4){
		luaL_error(L, "Need %d parameters for %s", 4, __FUNCTION__);
	}


  EsNodeWrapper* p1 = checkUserData<EsNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  float p3 = lua_tonumber(L, 3);
  float p4 = lua_tonumber(L, 4);
  p1->setScale(p2,p3,p4);
  return 0;
}



static int EsNode_setTransform(lua_State *L) 
{
	if(lua_gettop(L)!=4){
		luaL_error(L, "Need %d parameters for %s", 4, __FUNCTION__);
	}


  EsNodeWrapper* p1 = checkUserData<EsNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  float p3 = lua_tonumber(L, 3);
  float p4 = lua_tonumber(L, 4);
  p1->setTransform(p2,p3,p4);
  return 0;
}



static int EsNode_setRotate(lua_State *L) 
{
	if(lua_gettop(L)!=5){
		luaL_error(L, "Need %d parameters for %s", 5, __FUNCTION__);
	}


  EsNodeWrapper* p1 = checkUserData<EsNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  float p3 = lua_tonumber(L, 3);
  float p4 = lua_tonumber(L, 4);
  float p5 = lua_tonumber(L, 5);
  p1->setRotate(p2,p3,p4,p5);
  return 0;
}



static int EsNode_setVisible(lua_State *L) 
{
	if(lua_gettop(L)!=2){
		luaL_error(L, "Need %d parameters for %s", 2, __FUNCTION__);
	}


  EsNodeWrapper* p1 = checkUserData<EsNodeWrapper>(L, 1);
  bool p2 = lua_toboolean(L, 2);
  p1->setVisible(p2);
  return 0;
}

static luaL_Reg EsNodeTmpIndex[] = {
  {"addSub", EsNode_addSub},
  {"setColor", EsNode_setColor},
  {"setScale", EsNode_setScale},
  {"setTransform", EsNode_setTransform},
  {"setRotate", EsNode_setRotate},
  {"setVisible", EsNode_setVisible},
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadEsNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _EsNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, EsNodeTmpIndex);

	// Or this code will not compile without _${BaseClass}MetaString
#if 0
	luaL_getmetatable(L, _${BaseClass}MetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _ParticleNodeMetaString	"DDGraphics_ParticleNode"

struct ParticleNodeWrapper
 : public EsNodeWrapper 
{

  static const char* MetaName;
};


const char* ParticleNodeWrapper::MetaName = _ParticleNodeMetaString;

static luaL_Reg ParticleNodeTmpIndex[] = {
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadParticleNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _ParticleNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, ParticleNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _BlenderNodeMetaString	"DDGraphics_BlenderNode"

struct BlenderNodeWrapper
 : public EsNodeWrapper 
{

  void setFaceDefaultColor(float p1,float p2,float p3,float p4)
  {
    static_cast<BlenderNode*>(_ref)->setFaceDefaultColor(p1,p2,p3,p4);
  }
  static const char* MetaName;
};


const char* BlenderNodeWrapper::MetaName = _BlenderNodeMetaString;



static int BlenderNode_setFaceDefaultColor(lua_State *L) 
{
	if(lua_gettop(L)!=5){
		luaL_error(L, "Need %d parameters for %s", 5, __FUNCTION__);
	}


  BlenderNodeWrapper* p1 = checkUserData<BlenderNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  float p3 = lua_tonumber(L, 3);
  float p4 = lua_tonumber(L, 4);
  float p5 = lua_tonumber(L, 5);
  p1->setFaceDefaultColor(p2,p3,p4,p5);
  return 0;
}

static luaL_Reg BlenderNodeTmpIndex[] = {
  {"setFaceDefaultColor", BlenderNode_setFaceDefaultColor},
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadBlenderNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _BlenderNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, BlenderNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _BlenderNormalMetaString	"DDGraphics_BlenderNormal"

struct BlenderNormalWrapper
 : public BlenderNodeWrapper 
{

  static const char* MetaName;
};


const char* BlenderNormalWrapper::MetaName = _BlenderNormalMetaString;

static luaL_Reg BlenderNormalTmpIndex[] = {
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadBlenderNormalTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _BlenderNormalMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, BlenderNormalTmpIndex);

	// Or this code will not compile without _BlenderNodeMetaString
#if 1
	luaL_getmetatable(L, _BlenderNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _BlenderParticleMetaString	"DDGraphics_BlenderParticle"

struct BlenderParticleWrapper
 : public BlenderNormalWrapper 
{

  static const char* MetaName;
};


const char* BlenderParticleWrapper::MetaName = _BlenderParticleMetaString;

static luaL_Reg BlenderParticleTmpIndex[] = {
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadBlenderParticleTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _BlenderParticleMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, BlenderParticleTmpIndex);

	// Or this code will not compile without _BlenderNormalMetaString
#if 1
	luaL_getmetatable(L, _BlenderNormalMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _AxisNodeMetaString	"DDGraphics_AxisNode"

struct AxisNodeWrapper
 : public EsNodeWrapper 
{

  static const char* MetaName;
};


const char* AxisNodeWrapper::MetaName = _AxisNodeMetaString;

static luaL_Reg AxisNodeTmpIndex[] = {
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadAxisNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _AxisNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, AxisNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _FieldNodeMetaString	"DDGraphics_FieldNode"

struct FieldNodeWrapper
 : public EsNodeWrapper 
{

  static const char* MetaName;
};


const char* FieldNodeWrapper::MetaName = _FieldNodeMetaString;

static luaL_Reg FieldNodeTmpIndex[] = {
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadFieldNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _FieldNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, FieldNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _LightNodeMetaString	"DDGraphics_LightNode"

struct LightNodeWrapper
 : public EsNodeWrapper 
{

  void setTimeScale(float p1)
  {
    static_cast<LightNode*>(_ref)->setTimeScale(p1);
  }
  void setVAngleSpeed(float p1)
  {
    static_cast<LightNode*>(_ref)->setVAngleSpeed(p1);
  }
  void setHAngleSpeed(float p1)
  {
    static_cast<LightNode*>(_ref)->setHAngleSpeed(p1);
  }
  static const char* MetaName;
};


const char* LightNodeWrapper::MetaName = _LightNodeMetaString;



static int LightNode_setTimeScale(lua_State *L) 
{
	if(lua_gettop(L)!=2){
		luaL_error(L, "Need %d parameters for %s", 2, __FUNCTION__);
	}


  LightNodeWrapper* p1 = checkUserData<LightNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  p1->setTimeScale(p2);
  return 0;
}



static int LightNode_setVAngleSpeed(lua_State *L) 
{
	if(lua_gettop(L)!=2){
		luaL_error(L, "Need %d parameters for %s", 2, __FUNCTION__);
	}


  LightNodeWrapper* p1 = checkUserData<LightNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  p1->setVAngleSpeed(p2);
  return 0;
}



static int LightNode_setHAngleSpeed(lua_State *L) 
{
	if(lua_gettop(L)!=2){
		luaL_error(L, "Need %d parameters for %s", 2, __FUNCTION__);
	}


  LightNodeWrapper* p1 = checkUserData<LightNodeWrapper>(L, 1);
  float p2 = lua_tonumber(L, 2);
  p1->setHAngleSpeed(p2);
  return 0;
}

static luaL_Reg LightNodeTmpIndex[] = {
  {"setTimeScale", LightNode_setTimeScale},
  {"setVAngleSpeed", LightNode_setVAngleSpeed},
  {"setHAngleSpeed", LightNode_setHAngleSpeed},
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadLightNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _LightNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, LightNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _MimicNodeMetaString	"DDGraphics_MimicNode"

struct MimicNodeWrapper
 : public EsNodeWrapper 
{

  static const char* MetaName;
};


const char* MimicNodeWrapper::MetaName = _MimicNodeMetaString;

static luaL_Reg MimicNodeTmpIndex[] = {
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadMimicNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _MimicNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, MimicNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}





//////////////////
//These codes shall be generated automatically.
//Sat Apr 11 2015 00:04:40 GMT+0800 (CST)

#define _CubeNodeMetaString	"DDGraphics_CubeNode"

struct CubeNodeWrapper
 : public EsNodeWrapper 
{

  void shiftXZ()
  {
    static_cast<CubeNode*>(_ref)->shiftXZ();
  }
  static const char* MetaName;
};


const char* CubeNodeWrapper::MetaName = _CubeNodeMetaString;



static int CubeNode_shiftXZ(lua_State *L) 
{
	if(lua_gettop(L)!=1){
		luaL_error(L, "Need %d parameters for %s", 1, __FUNCTION__);
	}


  CubeNodeWrapper* p1 = checkUserData<CubeNodeWrapper>(L, 1);
  p1->shiftXZ();
  return 0;
}

static luaL_Reg CubeNodeTmpIndex[] = {
  {"shiftXZ", CubeNode_shiftXZ},
  {NULL, NULL}
};

//This is the only thing you need to code yourself.

void loadCubeNodeTmpIndex(lua_State*L)
{
	//_DeclareState()
	luaL_newmetatable(L, _CubeNodeMetaString);	

	// If it is necessary to get a GC for our class.
	// lua_pushvalue(L, -1);
	// lua_pushcfunction(L, __gcEsNode);
	// lua_setfield(L, -2, "__gc");	

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, CubeNodeTmpIndex);

	// Or this code will not compile without _EsNodeMetaString
#if 1
	luaL_getmetatable(L, _EsNodeMetaString);
	lua_setmetatable(L, -2);
#endif
}

#define EXPORT_LOADNODES()\
  loadEsNodeTmpIndex(L);\
  loadParticleNodeTmpIndex(L);\
  loadBlenderNodeTmpIndex(L);\
  loadBlenderNormalTmpIndex(L);\
  loadBlenderParticleTmpIndex(L);\
  loadAxisNodeTmpIndex(L);\
  loadFieldNodeTmpIndex(L);\
  loadLightNodeTmpIndex(L);\
  loadMimicNodeTmpIndex(L);\
  loadCubeNodeTmpIndex(L);\


static int createBlenderNormal(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 1){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 1, __FUNCTION__, 2);
	}
	const char* p1 = lua_tostring(L, 1);
	bool p2;
	if(top >= 2) { p2 = lua_toboolean(L, 2); }
	else { p2 = true; }
	// For now, we are all EsNode derives. No one is special.
	BlenderNormalWrapper *rv = createUserData<BlenderNormalWrapper>(L);
	rv->_ref = BlenderNormal::create(p1,p2);
	return 1;
}


static int createBlenderNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 1){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 1, __FUNCTION__, 2);
	}
	const char* p1 = lua_tostring(L, 1);
	bool p2;
	if(top >= 2) { p2 = lua_toboolean(L, 2); }
	else { p2 = false; }
	// For now, we are all EsNode derives. No one is special.
	BlenderNodeWrapper *rv = createUserData<BlenderNodeWrapper>(L);
	rv->_ref = BlenderNode::create(p1,p2);
	return 1;
}


static int createAxisNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 0){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 0, __FUNCTION__, 0);
	}
	// For now, we are all EsNode derives. No one is special.
	AxisNodeWrapper *rv = createUserData<AxisNodeWrapper>(L);
	rv->_ref = AxisNode::create();
	return 1;
}


static int createFieldNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 1){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 1, __FUNCTION__, 1);
	}
	int p1 = lua_tointeger(L, 1);
	// For now, we are all EsNode derives. No one is special.
	FieldNodeWrapper *rv = createUserData<FieldNodeWrapper>(L);
	rv->_ref = FieldNode::create(p1);
	return 1;
}


static int createLightNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 3){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 3, __FUNCTION__, 3);
	}
	float p1 = lua_tonumber(L, 1);
	float p2 = lua_tonumber(L, 2);
	float p3 = lua_tonumber(L, 3);
	// For now, we are all EsNode derives. No one is special.
	LightNodeWrapper *rv = createUserData<LightNodeWrapper>(L);
	rv->_ref = LightNode::create(p1,p2,p3);
	return 1;
}


static int createMimicNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 0){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 0, __FUNCTION__, 0);
	}
	// For now, we are all EsNode derives. No one is special.
	MimicNodeWrapper *rv = createUserData<MimicNodeWrapper>(L);
	rv->_ref = MimicNode::create();
	return 1;
}


static int createCubeNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 2){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 2, __FUNCTION__, 5);
	}
	float p1 = lua_tonumber(L, 1);
	float p2 = lua_tonumber(L, 2);
	float p3;
	if(top >= 3) { p3 = lua_tonumber(L, 3); }
	else { p3 = 0.1f; }
	float p4;
	if(top >= 4) { p4 = lua_tonumber(L, 4); }
	else { p4 = 0.1f; }
	float p5;
	if(top >= 5) { p5 = lua_tonumber(L, 5); }
	else { p5 = 0.1f; }
	// For now, we are all EsNode derives. No one is special.
	CubeNodeWrapper *rv = createUserData<CubeNodeWrapper>(L);
	rv->_ref = CubeNode::create(p1,p2,p3,p4,p5);
	return 1;
}


static int createParticleNode(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 0){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 0, __FUNCTION__, 1);
	}
	int p1;
	if(top >= 1) { p1 = lua_tointeger(L, 1); }
	else { p1 = 5000; }
	// For now, we are all EsNode derives. No one is special.
	ParticleNodeWrapper *rv = createUserData<ParticleNodeWrapper>(L);
	rv->_ref = ParticleNode::create(p1);
	return 1;
}


static int createBlenderParticle(lua_State *L)
{
	int top = lua_gettop(L);
	if (top < 2){
		luaL_error(L, "At least %d parameters for %s. %d would be best.", 2, __FUNCTION__, 6);
	}
	const char* p1 = lua_tostring(L, 1);
	int p2 = lua_tointeger(L, 2);
	float p3;
	if(top >= 3) { p3 = lua_tonumber(L, 3); }
	else { p3 = 0.1f; }
	float p4;
	if(top >= 4) { p4 = lua_tonumber(L, 4); }
	else { p4 = 0.0f; }
	float p5;
	if(top >= 5) { p5 = lua_tonumber(L, 5); }
	else { p5 = 0.0f; }
	float p6;
	if(top >= 6) { p6 = lua_tonumber(L, 6); }
	else { p6 = 0.0f; }
	// For now, we are all EsNode derives. No one is special.
	BlenderParticleWrapper *rv = createUserData<BlenderParticleWrapper>(L);
	rv->_ref = BlenderParticle::create(p1,p2,p3,p4,p5,p6);
	return 1;
}

static luaL_Reg _ddStatics[] = {
  {"createBlenderNormal", createBlenderNormal },
  {"createBlenderNode", createBlenderNode },
  {"createAxisNode", createAxisNode },
  {"createFieldNode", createFieldNode },
  {"createLightNode", createLightNode },
  {"createMimicNode", createMimicNode },
  {"createCubeNode", createCubeNode },
  {"createParticleNode", createParticleNode },
  {"createBlenderParticle", createBlenderParticle },
  {NULL, NULL}
};
void load_ddStatics(lua_State*L){ luaL_register(L, "dd", _ddStatics); }
