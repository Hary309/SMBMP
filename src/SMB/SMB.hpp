#pragma once

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN

#include <stdint.h>
#include <string>

#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>

#include "GameOffsets.hpp"

class MeatBoyCharactor;
class Camera;
class LevelManager;
class Level;

#include "SMB/Vector.hpp"
#include "SMB/RenderLayerObject.hpp"
#include "SMB/SceneObject2D.hpp"
#include "SMB/ReplayManager.hpp"
#include "SMB/Characters.hpp"
#include "SMB/MeatBoyCharactor.hpp"
#include "SMB/Layers.hpp"
#include "SMB/GMeatHUD.hpp"
#include "SMB/GSuperMeatBoy.hpp"
#include "SMB/Level.hpp"
#include "SMB/LevelManager.hpp"
#include "SMB/Renderer.hpp"
#include "SMB/Sprite.hpp"
#include "SMB/Camera.hpp"
#include "SMB/Window.hpp"
#include "SMB/GSMBMenu.hpp"

#include "SMB/Characters/DefaultMeatBoy.hpp"