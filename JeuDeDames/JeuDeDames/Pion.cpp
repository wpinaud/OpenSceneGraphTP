//
//  Pion.cpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 16/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#include "Pion.hpp"

Pion::Pion(int couleur,osg::Vec3f position){
    //La shape du Pion principal
    osg::ref_ptr<osg::Cylinder> monPion (new osg::Cylinder(position,2,1));
    //La shape drawable du pion
    pionDrawable = new osg::ShapeDrawable(monPion.get());

}

Pion::Pion(int couleur){
    //La shape du Pion principal
    osg::ref_ptr<osg::Cylinder> monPion (new osg::Cylinder(osg::Vec3f(0.0f,0.0f,1.0f),2,1));
    //La shape drawable du pion
    pionDrawable = new osg::ShapeDrawable(monPion.get());

}

