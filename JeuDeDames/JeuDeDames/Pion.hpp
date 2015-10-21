//
//  Pion.hpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 16/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef Pion_hpp
#define Pion_hpp

#include <stdio.h>
#include <osg/Drawable>
#include <osg/ShapeDrawable>


#endif /* Pion_hpp */


class Pion : public osg::Drawable
{
private:
    int couleur;
    osg::Vec3f position;
    osg::ref_ptr<osg::ShapeDrawable> pionDrawable;
    
public:
    Pion(int couleur,osg::Vec3f position);
    Pion(int couleur);
    //void bouger(int direction);
    virtual const int getCouleur(){return couleur;};
};