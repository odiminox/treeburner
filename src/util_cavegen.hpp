/*
 * Copyright (c) 2009 Jice
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of Jice may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Jice ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Jice BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once
#include <libtcod.hpp>

class CaveGenerator : public ITCODBspCallback {
 public:
  CaveGenerator(int level);  // bsp / cellular automate dungeon

  // the final dungeon map
  TCODMap* map = nullptr;  // normal resolution for pathfinding
  TCODMap* map2x = nullptr;  // double resolution for fovs
  // dungeon generation parameters
  int size;
  int size2x;  // well.. size*2
  TCODImage* ground = nullptr;  // ground color (subcell rez)

  // dungeon generator stuff
  bool visitNode(TCODBsp* node, void* userData);
  // apply blur to ground bitmap
  static void smoothImage(TCODImage* img);

 protected:
  int level;
  int bspDepth;  // how many times we split the map
  int minRoomSize;  // minimum room width/height
  bool randomRoom;  // a room fills a random part of the node or the maximum available space ?
  bool roomWalls;  // if true, rooms from BSP leafs are always isolated by walls

  void initData(int size);
};
