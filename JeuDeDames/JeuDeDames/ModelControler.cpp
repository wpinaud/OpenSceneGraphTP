//
//  ModelControler.cpp
//  JeuDeDames
//
//  Created by Willis Pinaud on 21/10/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#include "ModelControler.hpp"
bool ModelController::handle( const osgGA::GUIEventAdapter& ea,
                             osgGA::GUIActionAdapter& aa )
{
    if ( !_model ) return false;
    osg::Matrix matrix = _model->getMatrix();
    
    switch ( ea.getEventType() )
    {
        case osgGA::GUIEventAdapter::KEYDOWN:
            switch ( ea.getKey() )
        {
            case 'q': case 'Q':
                matrix *= osg::Matrix::rotate(-0.1f, osg::Z_AXIS);
                break;
            case 'd': case 'D':
                matrix *= osg::Matrix::rotate(0.1f, osg::Z_AXIS);
                break;
            case 'z': case 'Z':
                matrix *= osg::Matrix::rotate(-0.1f, osg::X_AXIS);
                break;
            case 's': case 'S':
                matrix *= osg::Matrix::rotate(0.1f, osg::X_AXIS);
                break;
            default:
                break;
        }
            _model->setMatrix( matrix );
            break;
        default:
            break;
    }
    return false;
}