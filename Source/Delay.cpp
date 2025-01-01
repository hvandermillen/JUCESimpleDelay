//
//  Delay.cpp
//  SimpleDelay - VST3
//
//  Created by Henry Vandermillen on 1/1/25.
//

#include "Delay.hpp"
#include <algorithm>

template <typename Type>

Delay<Type>::Delay(int sr, float delaySeconds) {
    //create buffer of correct length
    bufferSize = sr*delaySeconds;
    delayBuffer = new Type[bufferSize];
    //initialize buffer to all zeros
    for (int i  = 0; i < bufferSize; i++) {
        delayBuffer[i] = 0;
    }
}

template <typename Type>
Type Delay<Type>::Process(Type input, double feedback) {
    Type output = 0;
    
    delayBuffer[0] = input*std::max(feedback,1.0);
    for (int i = 1; i < bufferSize; i++) {
        delayBuffer[i] = delayBuffer[i-1];
    }
    
    output = input + delayBuffer[bufferSize];
    
    return output;
}
