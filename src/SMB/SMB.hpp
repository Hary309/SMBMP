/** @file SMB.hpp
 ** @authors Piotr Krupa (piotrkrupa06@gmail.com)
 **          Tomasz Jatkowski (tomaszjatkowski@outlook.com)
 ** @license GPL-3.0
 **/

#pragma once

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN

#include <stdint.h>
#include <string>

#include <d3d.h>

#include "SMB/Offsets.hpp"

class MeatBoyCharactor;
class MeatBoyDisplay;
class Camera;
class LevelManager;
class Level;
class Display;

#include <Vector2.hpp>

#include "SMB/RenderLayerObject.hpp"
#include "SMB/SceneObject2D.hpp"
#include "SMB/ReplayManager.hpp"
#include "SMB/Characters.hpp"
#include "SMB/MeatBoyCharactor.hpp"
#include "SMB/MeatBoyDisplay.hpp"
#include "SMB/Camera.hpp"
#include "SMB/Layers.hpp"
#include "SMB/GMeatHUD.hpp"
#include "SMB/GSuperMeatBoy.hpp"
#include "SMB/Level.hpp"
#include "SMB/LevelManager.hpp"
#include "SMB/Renderer.hpp"
#include "SMB/Sprite.hpp"
#include "SMB/Window.hpp"
#include "SMB/GSMBMenu.hpp"

#include "SMB/Characters/DefaultMeatBoy.hpp"
