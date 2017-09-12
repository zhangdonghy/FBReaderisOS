//
//  ZLTextNGStyle.hpp
//  ZDStudent
//
//  Created by zhangdong on 16/9/18.
//  Copyright © 2016年 Eagley. All rights reserved.
//

#ifndef ZLTextNGStyle_hpp
#define ZLTextNGStyle_hpp

#include <stdio.h>
#include "ZLTextDecoratedStyle.hpp"
#include "ZLTextNGStyleDescription.hpp"


class ZLTextNGStyle: public ZLTextDecoratedStyle
{
private:
    shared_ptr<ZLTextNGStyleDescription> myDescription;
    
public:
    ZLTextNGStyle(shared_ptr<ZLTextStyle> parent, shared_ptr<ZLTextNGStyleDescription> description,
                  shared_ptr<ZLTextHyperlink> hyperlink) ;
    
    
    virtual int getLineSpacePercentInternal();
    virtual bool isItalicInternal();
    virtual bool isBoldInternal();
    virtual bool isUnderlineInternal();
    virtual bool isStrikeThroughInternal();
    virtual std::vector<shared_ptr<ZDFontEntry>> getFontEntriesInternal();
    
    virtual int getFontSizeInternal(shared_ptr<ZLTextMetrics> metrics);
    virtual int getSpaceBeforeInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getSpaceAfterInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getVerticalAlignInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getLeftMarginInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getRightMarginInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getLeftPaddingInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getRightPaddingInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual int getFirstLineIndentInternal(shared_ptr<ZLTextMetrics> metrics, int fontSize);
    virtual bool isVerticallyAlignedInternal();
    
    
    ///////////
    unsigned char getAlignment() {
         unsigned char defined = myDescription->getAlignment();
        if (defined != ALIGN_UNDEFINED) {
            return defined;
        }
        return Parent->getAlignment();
    }
    
    bool allowHyphenations() {
        switch (myDescription->allowHyphenations()) {
            case B3_TRUE:
                return true;
            case B3_FALSE:
                return false;
            default:
                return Parent->allowHyphenations();
        }
    }
    
};
#endif /* ZLTextNGStyle_hpp */
