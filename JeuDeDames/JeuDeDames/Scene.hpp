//
//  Scene.hpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 15/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp
// base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

// Materials
#include <osg/Material>
#include <osg/StateSet>
#include <osgDB/ReadFile>

//textures
#include <osg/TexMat>
#include <osg/Geometry>

//Lighting
#include <osg/Light>
#include <osg/LightSource>
#include <osg/MatrixTransform>

//Position
#include <osg/PositionAttitudeTransform>


#endif /* Scene_hpp */

osg::ref_ptr<osg::Node> creerLaScene();
osg::Node* findNamedNode(const std::string& searchName,osg::Node* currNode);
