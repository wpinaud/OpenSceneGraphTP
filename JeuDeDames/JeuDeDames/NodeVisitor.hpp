//
//  NodeVisitor.hpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 20/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef NodeVisitor_hpp
#define NodeVisitor_hpp

#include <stdio.h>
#include <osg/NodeVisitor>
#include <osg/Geode>
#include <osg/PositionAttitudeTransform>
#include <iostream>

#endif /* NodeVisitor_hpp */

class InfoVisitor : public osg::NodeVisitor
{
public:
    InfoVisitor() : _level(0)
    { setTraversalMode(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN); }
    
    std::string spaces()
    { return std::string(_level*2, ' '); }
    
    virtual void apply( osg::Node& node );
    virtual void apply( osg::Geode& geode );
    
protected:
    unsigned int _level;
};

