//
//  monSuperCallback.hpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 21/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef monSuperCallback_hpp
#define monSuperCallback_hpp

#include <stdio.h>
#include <osg/NodeCallback>
#include <osg/Vec3d>
#include <osg/Vec4d>
#include <time.h>
#include <osg/PositionAttitudeTransform>
#include <osg/MatrixTransform>
#include <osg/Matrix>

class monSuperCallback : public osg::NodeCallback
{
public:
    void operator()(osg::Node* noeud, osg::NodeVisitor* visiteur){
        //x: pat->getPosition()*Resultant.x;
        osg::ref_ptr<osg::MatrixTransform> mt = dynamic_cast<osg::MatrixTransform*>(noeud->getParent(0));
        osg::Vec4d restest = osg::Vec4d(0,0,0,0);
        
        osg::Vec4d resultante = mt->getMatrix()*restest;
        osg::ref_ptr<osg::PositionAttitudeTransform> pat = dynamic_cast<osg::PositionAttitudeTransform*>(noeud);
        osg::Vec3d posPrev = osg::Vec3d(0,0,0);
        
        if (!pat.valid()) {
            return;
        }
        posPrev = pat->getPosition();
        osg::Vec3d pos = osg::Vec3d(resultante.x(),resultante.y(),resultante.z()) + posPrev;
        pat->setPosition(pos);
        
        
    }
    osg::Matrix position;
};

#endif /* monSuperCallback_hpp */
