//
//  ModelControler.hpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 21/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef ModelControler_hpp
#define ModelControler_hpp
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <iostream>
#include <osg/MatrixTransform>

#include <osgGA/GUIEventHandler>

#include <osg/ShapeDrawable>
#include <osg/PolygonMode>

#include <osgUtil/LineSegmentIntersector>

class ModelController : public osgGA::GUIEventHandler
{
public:
    ModelController( osg::MatrixTransform* node )
    : _model(node)
    {}
    virtual bool handle( const osgGA::GUIEventAdapter& ea,
                        osgGA::GUIActionAdapter& aa );
    
protected:
    osg::ref_ptr<osg::MatrixTransform> _model;
};


#endif /* ModelControler_hpp */
