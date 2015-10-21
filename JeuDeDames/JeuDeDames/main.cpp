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



//#include "Scene.hpp"
#include "Events.hpp"
#include "NodeVisitor.hpp"
#include "Pion.hpp"
#include "ModelControler.hpp"
#include "monSuperCallback.hpp"

int main()
{
    std::srand(time(NULL));
    /* OBJECTS CREATION */
    
    
    
    //Creating the root node
    osg::ref_ptr<osg::Group> root (new osg::Group);
    
    /*PION*/
    
    //The geode containing our shape
   	//osg::ref_ptr<osg::Geode> geodePion (new osg::Geode);
    //La shape du Pion principal
    osg::ref_ptr<osg::Cylinder> monPion (new osg::Cylinder(osg::Vec3f(0,0,1),2,1));
    
    //std::vector<osg::ref_ptr<osg::Geode>> geodePions;
    //std::vector<osg::ref_ptr<osg::PositionAttitudeTransform>> PATPions;
    
    for (int i=0; i<13; i++) {
        //The geode containing our shape
        osg::ref_ptr<osg::Geode> geodePion (new osg::Geode);
        //La shape drawable du pion
        osg::ref_ptr<osg::ShapeDrawable> pionDrawable (new osg::ShapeDrawable(monPion.get()));
        geodePion->addDrawable(pionDrawable.get());
        osg::ref_ptr<osg::PositionAttitudeTransform> PATPion (new osg::PositionAttitudeTransform);
        
        osg::ref_ptr<osg::StateSet> pionSS (geodePion->getOrCreateStateSet());
        /*Materiaux des pions*/
        osg::ref_ptr<osg::Texture2D> bois_blanc (new osg::Texture2D);
        // load an image by reading a file:
        osg::ref_ptr<osg::Image> img_bois_blanc (osgDB::readImageFile("/Users/willispinaud/Desktop/kch-w.gif"));
        // protect from being optimized away as static state:
        bois_blanc->setDataVariance(osg::Object::DYNAMIC);
        // Assign the texture to the image we read from file:
        bois_blanc->setImage(img_bois_blanc);
        // Assign texture unit 0 of our new StateSet to the texture
        //  we just created and enable the texture.
        pionSS->setTextureAttributeAndModes(0, bois_blanc,osg::StateAttribute::ON);
        // Associate this state set
        geodePion->setStateSet(pionSS);
        
        if (i<4) {
            osg::Vec3f pionPosTrans = osg::Vec3f(i*965%(965*4)/100,0.0,0.0);
            PATPion->setPosition(pionPosTrans);
            PATPion->addChild(geodePion.get());
            root->addChild(PATPion.get());
        }
        else if (i>=9){
            osg::Vec3f pionPosTrans = osg::Vec3f(5.0f+i*965%(965*4)/100,5.0,0.0);
            PATPion->setPosition(pionPosTrans);
            PATPion->addChild(geodePion.get());
            root->addChild(PATPion.get());
        }
        else{
            osg::Vec3f pionPosTrans = osg::Vec3f(i*965%(965*4)/100,10,0.0);
            PATPion->setPosition(pionPosTrans);
            PATPion->addChild(geodePion.get());
            root->addChild(PATPion.get());
        }
        
        
        
    }
    /*TABLE*/
    //The geode containing our shape
   	osg::ref_ptr<osg::Geode> geodeTable (new osg::Geode);
    //La shape de la table de jeu principale
    osg::ref_ptr<osg::Box> maTable (new osg::Box(osg::Vec3f(17.5,17.5,0),40,40,1));
    //La shape drawable de la table
    osg::ref_ptr<osg::ShapeDrawable> tableDrawable (new osg::ShapeDrawable(maTable.get()));
    
    //
    /*State Set*/
    //    // Create a new StateSet with default settings:
    //    //osg::ref_ptr<osg::StateSet> pionSS (geodePion->getOrCreateStateSet());
    osg::ref_ptr<osg::StateSet> tableSS (geodeTable->getOrCreateStateSet());
    geodeTable->addDrawable(tableDrawable);
    osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
    mt->addChild( geodeTable.get() );
    
    osg::ref_ptr<ModelController> ctrler = new ModelController( mt.get() );
    
    
    
    
    root->addChild( mt.get() );
    
    for (int i=0; i<13; i++) {
        //The geode containing our shape
        osg::ref_ptr<osg::Geode> geodePion (new osg::Geode);
        //La shape drawable du pion
        osg::ref_ptr<osg::ShapeDrawable> pionDrawable (new osg::ShapeDrawable(monPion.get()));
        geodePion->addDrawable(pionDrawable.get());
        osg::ref_ptr<osg::PositionAttitudeTransform> PATPion (new osg::PositionAttitudeTransform);
        
        osg::ref_ptr<osg::StateSet> pionSS (geodePion->getOrCreateStateSet());
        /*Materiaux des pions*/
        osg::ref_ptr<osg::Texture2D> bois_noir (new osg::Texture2D);
        // load an image by reading a file:
        osg::ref_ptr<osg::Image> img_bois_noir (osgDB::readImageFile("/Users/willispinaud/Desktop/kch-clr.gif"));
        // protect from being optimized away as static state:
        bois_noir->setDataVariance(osg::Object::DYNAMIC);
        // Assign the texture to the image we read from file:
        bois_noir->setImage(img_bois_noir);
        // Assign texture unit 0 of our new StateSet to the texture
        //  we just created and enable the texture.
        pionSS->setTextureAttributeAndModes(0, bois_noir,osg::StateAttribute::ON);
        // Associate this state set
        geodePion->setStateSet(pionSS);
        
        if (i<4) {
            osg::Vec3f pionPosTrans = osg::Vec3f(5.0f+i*965%(965*4)/100,25.0,0.0);
            PATPion->setPosition(pionPosTrans);
            PATPion->addChild(geodePion.get());
            mt->addChild(PATPion.get());
        }
        else if (i>=9){
            osg::Vec3f pionPosTrans = osg::Vec3f(i*965%(965*4)/100,30.0,0.0);
            PATPion->setPosition(pionPosTrans);
            PATPion->addChild(geodePion.get());
            mt->addChild(PATPion.get());
        }
        else{
            osg::Vec3f pionPosTrans = osg::Vec3f(5.0f+i*965%(965*4)/100,35,0.0);
            PATPion->setPosition(pionPosTrans);
            PATPion->addChild(geodePion.get());
            mt->addChild(PATPion.get());
        }
        
        
        
    }
    
    
    //
    //
    //    /*POSITION*/
    //    osg::ref_ptr<osg::PositionAttitudeTransform> objectPAT (new osg::PositionAttitudeTransform);
    //
    //    osg::Vec3f objectPosTrans = osg::Vec3f(2.0,2.0,2.0);
    //    objectPAT->setPosition(objectPosTrans);
    //    objectPAT->addChild(geodePion.get());
    //
    //    objectPAT->setPosition(osg::Vec3f(4.0,4.0,0.0));
    //    objectPAT->addChild(geodePion.get());
    //
    //
    /* IMPORT*/
    //Create transformation node
    osg::ref_ptr<osg::MatrixTransform> terrainScaleMAT (new osg::MatrixTransform);
    
    // Scale matrix
    osg::Matrix terrainScaleMatrix;
    terrainScaleMatrix.makeScale(osg::Vec3f(0.1f,0.1f,0.1f));
    
    
    //Loading the terrain node
    osg::ref_ptr<osg::Node> terrainnode (osgDB::readNodeFile("/Users/willispinaud/Documents/Unzip/273/modell.3DS"));
    
    //Set transformation node parameters
    terrainScaleMAT->addChild(terrainnode);
    terrainScaleMAT->setMatrix(terrainScaleMatrix);
    
    osg::ref_ptr<osg::PositionAttitudeTransform> envPAT (new osg::PositionAttitudeTransform);
    envPAT->addChild(terrainScaleMAT);
    envPAT->setPosition(osg::Vec3(-20,210,-37));
    root->addChild(envPAT);
    
    //    /* Matériaux */
    //    osg::ref_ptr<osg::Material> myMaterial (new osg::Material());
    //    //myMaterial->setEmission(osg::Material::FRONT,osg::Vec4f(0.93f,0.12f,0.031f,1.0f));
    //    //myMaterial->setAmbient(osg::Material::FRONT,osg::Vec4f(0.0f,1.0f,1.0f,1.0f));
    //    //myMaterial->setShininess(osg::Material::FRONT,0.0);
    //    //nodeStateSet->setAttribute(myMaterial);
    //
    
    
    
    //
    /*Materiaux de la table*/
    osg::ref_ptr<osg::Texture2D> table (new osg::Texture2D);
    // load an image by reading a file:
    osg::ref_ptr<osg::Image> img_table (osgDB::readImageFile("/Users/willispinaud/Desktop/damier.jpg"));
    // protect from being optimized away as static state:
    table->setDataVariance(osg::Object::DYNAMIC);
    // Assign the texture to the image we read from file:
    table->setImage(img_table);
    //nodeStateSet->setAttribute(myMaterial);
    // Assign texture unit 0 of our new StateSet to the texture
    //  we just created and enable the texture.
    tableSS->setTextureAttributeAndModes(0, table,osg::StateAttribute::ON);
    // Associate this state set
    geodeTable->setStateSet(tableSS);
    
    
    /*LIGHTING*/
    //Create nodes
    osg::ref_ptr<osg::Group> lightGroup (new osg::Group());
    osg::ref_ptr<osg::StateSet> lightSS (lightGroup->getOrCreateStateSet());
    osg::ref_ptr<osg::LightSource> lightSource1 = new osg::LightSource;
    
    //Create a local light
    osg::Vec4f lightPosition = osg::Vec4f(10.0,1.0,1.0,1.0);
    osg::ref_ptr<osg::Light> myLight = new osg::Light;
    myLight->setLightNum(0);
    myLight->setPosition(lightPosition);
    myLight->setAmbient(osg::Vec4f(0.4f,0.4f,0.4f,0.4f));
    myLight->setDiffuse(osg::Vec4f(1,0.4f,1,1));
    myLight->setConstantAttenuation(0.3);
    
    //Set light source parameters
    lightSource1->setLight(myLight);
    lightSource1->setStateSetModes(*lightSS.get(), osg::StateAttribute::ON);
    
    //Add to light source group
    lightGroup->addChild(lightSource1);
    root->addChild(lightGroup);
    //Light markers: small spheres
    
    
    //
    
    
    /* SCENE GRAPH*/
    //    // Add the shape drawable to the geode
    //geodePion->addDrawable(pionDrawable.get());
    osg::ref_ptr<osg::Geode> animPion (new osg::Geode);
    osg::ref_ptr<osg::ShapeDrawable> pionAnimDrawable (new osg::ShapeDrawable(monPion.get()));
    animPion->addDrawable(pionAnimDrawable.get());
    
    
    // Ajout d'un pion dans un groupe MatrixTransform
    osg::MatrixTransform* pMatTrans = new osg::MatrixTransform;
    pMatTrans->addChild( animPion );
    // Création d'un Animation Path
    osg::ref_ptr<osg::AnimationPath> rPath = new osg::AnimationPath;
    // Définition du mode de boucle
    rPath->setLoopMode( osg::AnimationPath::SWING );
    // Création de point de contrôle
    osg::AnimationPath::ControlPoint c0(osg::Vec3(0,0,0));
    osg::AnimationPath::ControlPoint c1(osg::Vec3( 0,10,0));
    osg::AnimationPath::ControlPoint c2(osg::Vec3( 0,9,4));
    osg::AnimationPath::ControlPoint c3(osg::Vec3( 0,0,4));
    rPath->insert( 0.0f, c0 );
    //rPath->insert( 2.0f, c2 );
    rPath->insert( 1.0f, c1 );
    //    rPath->insert( 6.0f, c3 );
    //    rPath->insert( 8.0f, c0 );
    
    // Mise en place du callback (rappel)
    osg::ref_ptr<osg::AnimationPathCallback> rAniCallback = new osg::AnimationPathCallback( rPath.get() );
    pMatTrans->setUpdateCallback( rAniCallback.get() );
    root->addChild(pMatTrans);
    // Add the geode to the scene graph root (Group)
    //    root->addChild(geodePion.get());
    
    //
    //
    //    // Add the PAT to the scene graph root (Group)
    //    root->addChild(objectPAT.get());
    //    
    //    //root->addChild(terrainScaleMAT.get()); //For the import
    //    root->addChild(lightGroup.get());
    
    InfoVisitor infoVisitor;
    
    //MyKeyboardEventHandler* myFirstEventHandler = new MyKeyboardEventHandler();

    //Creating the viewer
    osgViewer::Viewer viewer;
    
    //La racine
    //osg::ref_ptr<osg::Node> root = creerLaScene();
    root->accept(infoVisitor);
    //patternVistor
    //OSG update traversal
    
    //root->Node::
    
    // Set the scene data
    viewer.setSceneData(root);
    
    
    
    
/* KEYBOARD INPUT */
    //Stats Event Handler s key
    //viewer.addEventHandler(new osgViewer::StatsHandler);
    
    //Windows size handler
    viewer.addEventHandler(new osgViewer::WindowSizeHandler);
    
    // add the state manipulator
    //viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );
    viewer.addEventHandler( ctrler.get() );
    // ajout de la gestion des touches du clavier
//    viewer.addEventHandler(myFirstEventHandler);
    
    //viewer.setThreadingModel(osgViewer::Viewer::SingleThreaded);
    
    

    
    viewer.getCamera()->setViewMatrixAsLookAt(osg::Vec3(100.0f,+50.0f,35.0f), osg::Vec3(), osg::Z_AXIS );
    viewer.getCamera()->setAllowEventFocus( false );
    /* START VIEWER */
    auto monCallback = new monSuperCallback();
    for (int i=0; i<mt->getNumChildren(); i++) {
        mt->getChild(i)->setUpdateCallback(monCallback);
    }
    
    std::cout << &monCallback->position;
    //The viewer.run() method starts the threads and the traversals.
    return (viewer.run());
}
