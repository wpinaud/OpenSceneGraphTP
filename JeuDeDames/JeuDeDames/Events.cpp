//
//  Events.cpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 16/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#include "Events.hpp"

bool MyKeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
    switch(ea.getEventType())
    {
        case(osgGA::GUIEventAdapter::KEYDOWN):
        {
            switch(ea.getKey())
            {
                case 'z':
                    std::cout << " z key pressed" << std::endl;
                    return false;
                    break;
                default:
                    return false;
            }
        }
        default:
            return false;
    }
}