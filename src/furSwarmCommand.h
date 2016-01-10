//
//  furSwarmCommand.h
//
//  $Date$
//  $Rev$
//  $Author$
//
//  Copyright (c) 2012, Mauricio Bustos
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, 
//  with or without modification, are permitted provided 
//  that the following conditions are met:
//
//  - Redistributions must not be for profit.  This software in source or binary form, 
//      with or without modification, cannot be included in anyproduct that is then sold.  
//      Please contact Mauricio Bustos m@bustos.org if you are interested in a for-profit license.
//  - Redistributions of source code or in binary form must reproduce the above copyright notice, 
//      this list of conditions and the following disclaimer in the documentation 
//      and/or other materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
//  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#ifndef furSwarm_furSwarmCommand_h
#define furSwarm_furSwarmCommand_h

#include "ofEllipseButton.h"
#include "ofSlider.h"
#include "fsPatternParameters.h"
#include "fsPayload.h"

//! Class describing a network command
/*!
    This includes some visualiation aspects about the command's
    interactions with the display sliders.
 */
class furSwarmCommand {
    
public: 
    furSwarmCommand(int shape, int buttonX, int buttonY, int buttonHeight, int buttonWidth, int buttonColor, 
                    const char *buttonLabel, uint8_t identifier, fsPatternParameters *parameters);
    ~furSwarmCommand();
    
    // Actions
    void draw();
    void press();
    void release();
    void setCanSetColor(bool setting);
    virtual void setColor(int newColor);
    void setCanSetIntensity(bool setting);
    void setActivelySelected(bool setting);
    // Query
    bool pointValid(int pointX, int pointY);
    fsPayload payload(bool force);
    // Attributes
    char* label();
    ofButton *commandButton;    
    uint8_t commandIdentifier;
    bool canSetColor, canSetIntensity;
    bool activelySelected;    
    // Local Attributes
    fsPatternParameters *patternParameters;
    fsPayload lastPayload;
};

#endif
