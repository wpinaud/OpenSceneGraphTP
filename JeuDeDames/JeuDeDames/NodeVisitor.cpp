//
//  NodeVisitor.cpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 20/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#include "NodeVisitor.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
void InfoVisitor::apply( osg::Node& node )
{
    std::cout << spaces() << (std::string) node.libraryName() << "::" << node.className() << std::endl;
    if ((std::string) node.className()=="PositionAttitudeTransform"){
        osg::PositionAttitudeTransform* pat = dynamic_cast<osg::PositionAttitudeTransform*> (&node);
        osg::Vec3d a = pat->getPosition();
    }
    _level++;
    traverse( node );
    _level--;
}

void InfoVisitor::apply( osg::Geode& geode )
{
    std::cout << spaces() << geode.libraryName() << "::" << geode.className() << std::endl;
    
    _level++;
    for ( unsigned int i=0; i<geode.getNumDrawables(); ++i )
    {
        osg::Drawable* drawable = geode.getDrawable(i);
        std::cout << spaces() << drawable->libraryName() << "::" << drawable->className() << std::endl;
    }
    
    traverse( geode );
    _level--;
}
