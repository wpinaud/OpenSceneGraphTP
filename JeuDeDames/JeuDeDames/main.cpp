//
//  main.cpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 15/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

// base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/Geode>

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

#include <osgGA/GUIEventHandler>
//Animation
#include <osg/AnimationPath>



#include "Scene.hpp"
#include "Events.hpp"
#include "NodeVisitor.hpp"

int main()
{
    
    InfoVisitor infoVisitor;
    
    //MyKeyboardEventHandler* myFirstEventHandler = new MyKeyboardEventHandler();

    //Creating the viewer
    osgViewer::Viewer viewer;
    
    //La racine
    osg::ref_ptr<osg::Node> root = creerLaScene();
    root->accept(infoVisitor);
    //patternVistor
    //OSG update traversal
    
    //root->Node::
    
    // Set the scene data
    viewer.setSceneData(root);
    
    
    
/* KEYBOARD INPUT */
    //Stats Event Handler s key
    viewer.addEventHandler(new osgViewer::StatsHandler);
    
    //Windows size handler
    viewer.addEventHandler(new osgViewer::WindowSizeHandler);
    
    // add the state manipulator
    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );
    
    // ajout de la gestion des touches du clavier
//    viewer.addEventHandler(myFirstEventHandler);
    
    //viewer.setThreadingModel(osgViewer::Viewer::SingleThreaded);
    
    

    
//    viewer.getCamera()->setViewMatrixAsLookAt(osg::Vec3(20.0f,-200.0f,45.0f), osg::Vec3(), osg::Z_AXIS );
//    viewer.getCamera()->setAllowEventFocus( false );
    /* START VIEWER */
    
    //The viewer.run() method starts the threads and the traversals.
    return (viewer.run());
}
