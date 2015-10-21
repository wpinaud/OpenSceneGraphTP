//
//  Events.hpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 16/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef Events_hpp
#define Events_hpp

#include <osgGA/GUIEventHandler>
#include <iostream>

#endif /* Events_hpp */

class MyKeyboardEventHandler : public osgGA::GUIEventHandler
{
public:
    virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&);
    virtual void accept(osgGA::GUIEventHandlerVisitor& v)   { v.visit(*this); };
};