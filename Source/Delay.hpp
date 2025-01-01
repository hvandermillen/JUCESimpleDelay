//
//  Delay.hpp
//  SimpleDelay - VST3
//
//  Created by Henry Vandermillen on 1/1/25.
//

#ifndef Delay_hpp
#define Delay_hpp

#include <stdio.h>

#endif /* Delay_hpp */

template <typename Type>
class Delay {
public:
    Delay(int, float);
    Type Process(Type,double);
private:
    Type* delayBuffer;
    int bufferSize;
    int delaySamples; //how long, in samples, the delay is
    
};
